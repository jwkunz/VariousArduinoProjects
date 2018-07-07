#include <ArduinoStdInt.h>

#include<SevenSegmentDriver.h>


// Baud Rate
#define BAUDRATE 9600

static unsigned long long time_lastTickMS = 0; // Last time the tick was called in milliseconds
static unsigned long long time_currentMS = 0; // Current number of milliseconds since program start

static String displayTime = "00.00.00A"; // Start Time
static String alarmTime = "00.01.23A"; //

static bool alarmOn = false; // Flag to know if the alarm is on

#define TIMERLIMIT 10000
static unsigned long timer = TIMERLIMIT;

// Objects
SevenSegmentDriver SSD; // 7 Segment Display Driver


void setup() {

  Serial.begin(BAUDRATE); // Start Serial Communication
  time_currentMS = millis(); // Record time
  time_lastTickMS = time_currentMS; // Record first bench mark



}


void loop() {

String message = "STARIWARS";

  if (displayTime == alarmTime)
  {
    alarmOn = true; // Raise Alarm
    displayTime = "00.00.00A";

    timer = 0;
  }

  if (alarmOn)
  {
    driveSound();
  }

  if ( timer < TIMERLIMIT)
  {
    
    SSD.display9(&message);
    SSD.displayChar(' ', 4, true);
    timer++;
  }
  else
  {
    driveTime();
  };

}


//////////////////////////////////////////////////////////////////////////
/// Time Manager
/////////////////////////////////////////////////////////////////////////
#define PERIOD_MS (998500) // Period to tick the clock in milliseconds 
unsigned long long totalElapsedTime; // Time since the begining of run
unsigned long long numTicks; // Num of ticks passed

// Controls Time.  If a second has passed, updates the clock.  Always flashes the current time.
void driveTime()
{

  time_currentMS = micros(); // Sample the time

  unsigned long long elapsedTickTime = abs(time_currentMS - time_lastTickMS); //ElapsedTime


  // Determine in the period time has elapsed to call a tick
  if ((elapsedTickTime) >= PERIOD_MS )
  { // Period Time Elapsed, running tick function
    numTicks++;

    // Reset and log the current milliseconds as the lastTick
    time_lastTickMS = time_currentMS;

    // Call the tick function
    tickTime(&displayTime);
    SSD.display9(&displayTime);
  }
  SSD.display9(&displayTime);

}




// Takes in the current time as a string, adds one seconds, and returns a string to new time
void tickTime(String* Time)
{
  if (increment60s(&(*Time)[6], &(*Time)[7]))
  {
    if (increment60s(&(*Time)[3], &(*Time)[4]))
    {
      if (increment12s(&(*Time)[0], &(*Time)[1]))
      {
        toggleAMPM(&(*Time)[8]);
      }
    }
  }
}
// Increment tens and ones by one unit in seconds or minutes (based on 60)
// Returns true if 59 overflows to 00 (Need to update the next level up)
bool increment60s(char* tens, char* ones)
{

  if (*ones == '9')
  {
    *ones = '0';
    if (*tens == '5')
    {
      *tens = '0';
      return true;
    }
    else
    {
      (*tens)++;
      return false;
    }

  } else
  {
    (*ones)++;
    return false;
  }
}

// Increment tens and ones by one unit in hours (based on 12)
// Returns true if 11 goes to 12 (Need to switch AM/PM)
bool increment12s(char* tens, char* ones)
{

  if ((*tens) == '1')
  { // Either 10,11, or 12
    switch ((*ones))
    {
      case '0': // 10
        {
          (*ones)++; // ->11
          return false;
        }
        break;
      case '1': // 11
        {
          (*ones)++; // ->12
          return true;
        }
        break;
      case '2': // 12
        {
          (*ones) = '1'; // ->01
          (*tens) = '0';
          return false;
        }
        break;
    }

  }
  else { // Is less than 10, normal Increment

    if (*ones == '9')
    {
      // 09 -> 10
      (*ones) = '0';
      (*tens)++;
      return false;
    }
    else
    {
      (*ones)++;
      return false;
    }

  }
}

// Toggles the value from A for AM to P for PM or visVersa
void toggleAMPM(char* value)
{
  if (*value == 'A')
  {
    (*value) = 'P';
  } else
  {
    (*value) = 'A';
  }
}
//////////////////////////////////////////////////////////////////////////
/// Tick Sound
/////////////////////////////////////////////////////////////////////////
#define BUZZPIN 3 // + PWM of the buzzer
#define BPM 1000 // Not actually scaled, relative to the song programming
unsigned long MSperBeat = 60000 / BPM; // MSperBeat

static unsigned long sound_lastTickMS = 0; // Last time the tick was called in milliseconds
static unsigned long sound_currentMS = 0; // Current number of milliseconds since program start

unsigned int noteNumber = 0; // Iterator in song array
unsigned int noteBeatsLeft = 0; // Counter of number of beats to hold note.  Counts down to 0.
unsigned int noteFrequency = 0; // Frequency of note to sustain


// Notes
#define C1   261
#define Db1   277
#define D1  294
#define Eb1   311
#define E1   330
#define F1  349
#define Gb1  370
#define G1  392
#define Ab1  415
#define nA1  440
#define Bb1  466
#define nB1   494
#define C2  523
#define D2  587
#define Eb2  622
#define E2   659
#define F2   698
#define Gb2  740
#define G2   784
#define Ab2   831
#define nA2   880
#define Bb2  932
#define nB2   988
#define C3   1047

//StarWars Song
unsigned int SONG[] = {
  0, 0, // Skip First Note
  D1, 1,
  0, 1,
  D1, 1,
  0, 1,
  D1, 1,
  G1, 8,
  D2, 8,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  nA1, 1,
  G2, 8,
  D2, 8,
  0, 1,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  nA1, 1,
  G2, 8,
  D2, 8,
  0, 1,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  C2, 1,
  nA1, 8,
  0, 1,
  D1, 1,
  0, 1,
  D1, 1,
  0, 1,
  D1, 1,
  G1, 8,
  D2, 8,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  nA1, 1,
  G2, 8,
  D2, 8,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  nA1, 1,
  G2, 8,
  D2, 8,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  C2, 1,
  nA1, 8,
  //
  D1, 4,
  0, 1,
  D1, 3,
  E1, 7,
  0, 1,
  E1, 2,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  nA1, 1,
  0, 1,
  G1, 2,
  0, 1,
  G1, 2,
  nA1, 2,
  nB1, 2,
  nA1, 2,
  E1, 2,
  Gb1, 4,
  //
  D1, 4,
  0, 1,
  D1, 3,
  E1, 7,
  0, 1,
  E1, 2,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  nA1, 1,
  0, 1,
  G1, 2,
  D2, 6,
  nA1, 6,
  //
  D1, 4,
  0, 1,
  D1, 3,
  E1, 7,
  0, 1,
  E1, 2,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  nA1, 1,
  0, 1,
  G1, 2,
  0, 1,
  G1, 2,
  nA1, 2,
  nB1, 2,
  nA1, 2,
  E1, 2,
  Gb1, 4,
  //
  D1, 4,
  0, 1,
  D1, 2,
  0, 1,
  G2, 1,
  0, 1,
  F2, 1,
  0, 1,
  Eb2, 1,
  0, 1,
  D2, 1,
  0, 1,
  C2, 1,
  0, 1,
  Bb1, 1,
  0, 1,
  nA1, 1,
  0, 1,
  G1, 1,
  D2, 8,
  0, 4,
  //
  D1, 1,
  0, 1,
  D1, 1,
  0, 1,
  D1, 1,
  G1, 8,
  D2, 8,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  nA1, 1,
  G2, 8,
  D2, 8,
  0, 1,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  nA1, 1,
  G2, 8,
  D2, 8,
  0, 1,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  C2, 1,
  nA1, 8,
  D1, 1,
  0, 1,
  D1, 1,
  0, 1,
  D1, 1,
  G1, 8,
  D2, 8,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  nA1, 1,
  G2, 8,
  D2, 8,
  0, 1,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  nA1, 1,
  G2, 8,
  D2, 8,
  0, 1,
  C2, 1,
  0, 1,
  nB1, 1,
  0, 1,
  C2, 1,
  nA1, 8,
  //192
  D1, 4,
  0, 1,
  D1, 2,
  0, 1,
  G2, 1,
  0, 1,
  F2, 1,
  0, 1,
  Eb2, 1,
  0, 1,
  D2, 1,
  0, 1,
  C2, 1,
  0, 1,
  Bb1, 1,
  0, 1,
  nA1, 1,
  0, 1,
  G1, 1,
  D2, 4,
  0, 1,
  G1, 2,
  0, 1,
  G1, 2,
  0, 1,
  G1, 2,
  0, 1,
  G1, 4
};
//
//
// End Song

unsigned int songBytes = sizeof(SONG);
unsigned int songSize = songBytes / (sizeof(unsigned int)); // The length of the song array


// Every time this function is called, it decides if enough time for a beat
// and if so, calls the tickSound function to change notes
// Controls Time.  If a second has passed, updates the clock.  Always flashes the current time.
void driveSound()
{

  sound_currentMS = millis(); // Sample the time

  // Determine in the period time has elapsed to call the next sound using tick
  if ((sound_currentMS - sound_lastTickMS) >= MSperBeat )
  { // Period Time Elapsed, running tick function

    // Reset and log the current milliseconds as the lastTick
    sound_lastTickMS = sound_currentMS;
    // Call the tickSound function
    if (tickSong(SONG)) // returns true when song is over
    {
      alarmOn = false; // Stop Alarm
      // Reset
      noteNumber = 0;
      noteBeatsLeft = 0;
      noteFrequency = 0;
    }

  }


}


// This function sustains the next note of the song until the amound of beats left for that note is zero.
// Each time tickSong is called (every beat) the beat count goes down by 1.
// After finishing a note, it advances to the next note.  It does nothing if the song is finished
// When song is complete, return true

bool tickSong(unsigned int* song)
{

  if (noteNumber == 0) // Check for Initial State
  {
    // Advance in Array
    noteNumber = noteNumber + 2;
    // Find the intial frequency
    noteFrequency = (song)[noteNumber];
    // Get the initial number of beats
    noteBeatsLeft = (song)[noteNumber + 1];
    return false; // Not Over
  }
  else if (noteNumber >= songSize) // SongOver
  {
    noTone(BUZZPIN); // Silence
    return true; // Do nothing
  }
  else // Play Note
  {
    // Decrement the number of beats left
    noteBeatsLeft--;

    if (noteFrequency == 0)
    {
      // Rest Note
      noTone(BUZZPIN);

    }
    else
    { // Drive the note
      tone(BUZZPIN, noteFrequency);
    }

    // Check to advance
    if (noteBeatsLeft == 0)
    {
      // Advance in Array
      noteNumber = noteNumber + 2;
      // Find the new frequency
      noteFrequency = (song)[noteNumber];
      // Get the new number of beats
      noteBeatsLeft = (song)[(noteNumber + 1)];
    }

    return false; // Not Over
  }

}




