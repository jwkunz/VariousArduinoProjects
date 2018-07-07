#include <DSP.h>
#include <ArduinoStdInt.h>

// Parameters
#define BAUDRATE 9600
#define ADC_PIN A0
#define TONE_PIN 5
#define SAMPLE_RATE_HZ 3E3
#define TARGET_FREQ_HZ 1E3
#define TARGET_BW_HZ 500
#define WINDOW_LEN 90
#define FILT_LEN 90
#define AMP_MIXER 1
#define AMP_FILT 1
#define DETECT_THRESHOLD_DB 13
#define OPTIMAL_DEC_FACTOR ((length_t)floor(SAMPLE_RATE_HZ / (TARGET_BW_HZ * 1.05)))
#define DECIMATION_FACTOR 10
#define TONE_FREQ 200

// Derived Values
#define SAMPLE_DURATION_US ((1E6/SAMPLE_RATE_HZ))
#define TARGET_OMEGA (2*vPI*TARGET_FREQ_HZ/SAMPLE_RATE_HZ)
#define BPF_CUTOFF_NORM ((TARGET_BW_HZ*1.1)/SAMPLE_RATE_HZ)
#define DEC_SIG_LENGTH ((length_t)ceil(WINDOW_LEN / DECIMATION_FACTOR))
#define FILTER_PART_LENGTH ((length_t)ceil(FILT_LEN / DECIMATION_FACTOR))
#define SIGNAL_PART_LENGTH DEC_SIG_LENGTH

// Data containers
tap_t LPF_taps[FILT_LEN];
mixer_t mixerI[WINDOW_LEN];

void setup()
{
  Serial.begin(BAUDRATE);
  pinMode(ADC_PIN, INPUT);
  pinMode(TONE_PIN, OUTPUT);
  // Init the bandPass filter
  dsp_init_LPF_sinc(LPF_taps, FILT_LEN, BPF_CUTOFF_NORM, AMP_FILT);
  // Init the mixer
  dsp_init_mixerI(TARGET_OMEGA, mixerI, WINDOW_LEN, AMP_MIXER);


  Serial.print("Decimation Factor: ");
  Serial.println(DECIMATION_FACTOR);
  Serial.print("Decimated Signal Length: ");
  Serial.println(DEC_SIG_LENGTH);
  Serial.print("Cut Off Norm: ");
  Serial.println(BPF_CUTOFF_NORM);  
  //Serial.print("Filter Taps: ");
  //printDataArray(LPF_taps,FILT_LEN);
  delay(1000);

  
}

void loop() {
  /*
  Serial.println("Out of Band");
  tone(TONE_PIN,TONE_FREQ);
  detectSignal();
  noTone(TONE_PIN);
  delay(1000);
  Serial.println("In Band");
  tone(TONE_PIN,TARGET_FREQ_HZ);
  detectSignal();
  noTone(TONE_PIN);
  delay(1000);
  */
  Serial.println(detectSignal());
  delay(250);  
}


void printDataArray(sample_t* data,length_t dataLength)
{
  Serial.println("Printing...");
  for(length_t m = 0; m < dataLength; m++)
  {
    Serial.println(data[m],8);
  }
  Serial.println("Finished");
  delay(1000);
}

// Finds the power at TARGET_FREQ by real baseband mix down
// The decimating polyphase filter also perform bandpass filtering
// Returns 1 if detected, Returns 0 if not detected

bool detectSignal()
{

  // Data Arrays
  sample_t sampleData[WINDOW_LEN] = {0};
  sample_t downMixed[WINDOW_LEN] = {0};
  sample_t signal_dec[DEC_SIG_LENGTH] = {0};
  
  // Grab a sample
  sample_window(sampleData, WINDOW_LEN, SAMPLE_DURATION_US);

  //printDataArray(sampleData,WINDOW_LEN);
  
  // Down Mix
  dsp_realDownMix_window(sampleData, WINDOW_LEN, mixerI, downMixed);

  // Decimate and BandPass Filter
  cust_polyphaseDecimate(downMixed, WINDOW_LEN, LPF_taps, FILT_LEN, DECIMATION_FACTOR, signal_dec, DEC_SIG_LENGTH); 

  // Integrate Power
  double sum = 0;
  for (length_t m = 0; m < DEC_SIG_LENGTH; m++)
  {
    sum = sum + abs(signal_dec[m])*abs(signal_dec[m]);
  }

  double totalPower_dB = dsp_convert_dB((sum));
  //Serial.print("Total Power In dB: ");
  //Serial.println(totalPower_dB); 
  
  // Power Detection
  if (totalPower_dB > DETECT_THRESHOLD_DB)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Fills the dataWindow with samples at a fixed rate

void sample_window(sample_t* dataWindow, length_t windowLength, uint32_t sampleInterval_us)
{
  uint32_t timeMark = micros();
  for (length_t m = 0; m < windowLength; m++)
  {
    // Wait for sample time
    while ((micros() - timeMark) < sampleInterval_us);
    // mark time
    timeMark = micros();
    // sample
    dataWindow[m] = analogRead(ADC_PIN);
  }
}


///////////////////////// 

////////////////////////

// Peforms a polyphase based decimation with the given anti-aliasing filter


void cust_polyphaseDecimate(sample_t* signal_OG, length_t signal_OG_length, tap_t* filterTaps, length_t filterTaps_length, uint8_t decimationFactor, sample_t* signal_dec, length_t signal_dec_length)
{
  ///////////
  // Poly Phase Decimate
  for (length_t d = 0; d < decimationFactor; d++)
  {
    // Get the signal part
    sample_t signalPart[SIGNAL_PART_LENGTH] = {0};
    for (length_t s = 0; s < SIGNAL_PART_LENGTH; s++)
    {
      length_t index = d + s * decimationFactor;
      // Check if needs to zero pad
      if (index < signal_OG_length)
      {
        signalPart[s] = signal_OG[index];
      }
      else // Effective zero padding
      {
        signalPart[s] = 0;
      }
    }
    // Get the filter part
    tap_t filterPart[FILTER_PART_LENGTH] = {0};
    for (length_t f = 0; f < FILTER_PART_LENGTH; f++)
    {
      length_t index = d + f * decimationFactor;
      // Check if needs to zero pad
      if (index < filterTaps_length)
      {
        filterPart[f] = filterTaps[index];
      }
      else // Effective zero padding
      {
        filterPart[f] = 0;
      }
    }
    // Filter
    sample_t filterResult[SIGNAL_PART_LENGTH] = {0};
    tap_t* B = filterPart;
    tap_t A[1] = {1};
    // IIR filter acting as FIR
    dsp_filterIIR(B, A, signalPart, 1, FILTER_PART_LENGTH, SIGNAL_PART_LENGTH, filterResult);

    // Running Sum
    for (length_t s = 0; s < SIGNAL_PART_LENGTH; s++)
    {
      signal_dec[s] = signal_dec[s] + filterResult[s];
    }
  }
}
