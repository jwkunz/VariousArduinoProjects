#define PERIOD_MS 50 // State Machine Period

// Series of state names and corresponding numbers
#define INIT_ST 0
#define FINAL_ST 1

// Baud Rate
#define BAUDRATE 9600

static unsigned short currentState = INIT_ST; // Current State of Machine
static unsigned short lastState = INIT_ST; // Keeps track of the last state

static unsigned long lastTickMS = 0; // Last time the tick was called in milliseconds
static unsigned long currentMS = 0; // Current number of milliseconds since program start




void setup() {

  Serial.begin(BAUDRATE); // Start Serial Communication
  currentMS = millis(); // Record time
  lastTickMS = currentMS; // Record first bench mark

}

void loop() {

  currentMS = millis(); // Sample the time

  // Determine in the period time has elapsed to call a tick
  if ((currentMS - lastTickMS) >= PERIOD_MS )
  { // Period Time Elapsed, running tick function

    // Reset and log the current milliseconds as the lastTick
    lastTickMS = currentMS;

    // Call the tick function
    tickFunction();
  }
  // Else, keep running

}


// Serial Prints the current state when a change is detected for debugging.
void printState()
{
  // Does this check to only print when transition occurs
  if (currentState != lastState)
  {
    // Update
    lastState = currentState;

    // Depending on the currentState, print the currentState
    switch (currentState)
    {
      case INIT_ST:
        Serial.print("INIT_ST\n\r");
        break;
      case FINAL_ST:
        Serial.print("FINAL_ST\n\r");
        break;
      default:
        Serial.print("Error State Not Identified\n\r");
        break;

    }
  }
}



// Runs every PERIOD_MS.  Used to operate state machine
void tickFunction()
{
  printState(); // Print the current state to Serail

  // State Actions
  switch (currentState) {
    case INIT_ST:
      {
        // Insert
      }
      break;
    case FINAL_ST:
      {
        // Insert
      }
      break;

    default:
      {
        // Error
        Serial.print("Error State Not Identified\n\r");
      }
      break;
  }


  // State Transitions
  switch (currentState) {
    case INIT_ST:
      {
        currentState = FINAL_ST; // Advance
      }
      break;
    case FINAL_ST:
      {
        currentState = FINAL_ST; // Stay
      }
      break;

    default:
      {
        // Error, reset
        currentState = INIT_ST; // Advance
      }
      break;

  }
}
