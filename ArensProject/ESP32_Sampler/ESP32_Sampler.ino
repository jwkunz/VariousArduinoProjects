#include <DSP.h>
#include <ArduinoStdInt.h>

// Parameters
#define BAUDRATE 115200
#define ADC_PIN 
#define TONE_PIN 5
#define SAMPLE_RATE_HZ 1E3
#define TARGET_FREQ_HZ 300
#define TARGET_BW_HZ 50
#define WINDOW_LEN 48
#define FILT_LEN 100
#define AMP_MIXER 1
#define AMP_FILT 1
#define DETECT_THRESHOLD_DB -40
#define OPTIMAL_DEC_FACTOR ((length_t)floor(SAMPLE_RATE_HZ / (TARGET_BW_HZ * 1.05)))
#define DECIMATION_FACTOR OPTIMAL_DEC_FACTOR
#define TONE_FREQ 400

// Derived Values
#define SAMPLE_DURATION_US ((1/SAMPLE_RATE_HZ)*1E6)
#define TARGET_OMEGA (2*vPI*TARGET_FREQ_HZ/SAMPLE_RATE_HZ)
#define BPF_CUTOFF_NORM (1/(double)(DECIMATION_FACTOR+1))
#define DEC_SIG_LENGTH ((length_t)ceil(WINDOW_LEN / DECIMATION_FACTOR))

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

  
}

void loop() {
  detectSignal();
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
  
  // Down Mix
  dsp_realDownMix_window(sampleData, WINDOW_LEN, mixerI, downMixed);

  // Decimate and BandPass Filter
  dsp_polyphaseDecimate(downMixed, WINDOW_LEN, LPF_taps, FILT_LEN, DECIMATION_FACTOR, signal_dec, DEC_SIG_LENGTH); 

  // Integrate Power
  double sum = 0;
  for (length_t m = 0; m < DEC_SIG_LENGTH; m++)
  {
    sum = sum + abs(signal_dec[m])*abs(signal_dec[m]);
  }

  double totalPower_dB = dsp_convert_dB((sum));
  Serial.print("Total Power In dB: ");
  Serial.println(totalPower_dB); 
  
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



