#include <ArduinoStdInt.h> // Standard int types
#include <RGBLedDriver.h>  // Driver

RGBLedDriver RGB_DR; // Define Object


#define INTENSITY_MAX 100 // Max intensity (255 MAX)
#define INTENSITY_MIN 0 // Min intensity (0 MIN)

#define DELAY_RAINBOW_MS 20 // Number of milliseconds to delay between colors

uint8_t delta = (INTENSITY_MAX/10); // Amount to change color by

void setup() {

}

void loop() {

// Start with random values
uint8_t red = random(INTENSITY_MIN,INTENSITY_MAX);
uint8_t green = random(INTENSITY_MIN,INTENSITY_MAX);
uint8_t blue = random(INTENSITY_MIN,INTENSITY_MAX);


while (true){

// Transition to random color
rainbowTransition(&red,&green,&blue);
// Display color
RGB_DR.driveColor(red,green,blue);
// Delay
delay(DELAY_RAINBOW_MS);
}
}


// Will do a random discrete color change by parameter delta.
void rainbowTransition(uint8_t* red,uint8_t* green,uint8_t* blue)
{


// Decide a random transition case for inc/dec a single color component
switch(random(1,6))
{
  
  // Each case will check if the transition will exceed the intensity limits
  // If so, the transition will reverse the opposite direction
  // This guarentees smooth rainbow like transitions without sharp jumps
  
  // Red++
  case 1:
  {
    if((*red + delta) < INTENSITY_MAX)
    {
    *red += delta;
    }
    else
    {
      *red -= delta;
    }
  }
  break;
  // Red--
      case 2:
  {
     if((*red - delta) > INTENSITY_MIN)
    {
    *red -= delta;
    }
    else
    {
      *red += delta;
    }
  }
  break;
  // Green++
 case 3:
  {
    if((*green + delta) < INTENSITY_MAX)
    {
    *green += delta;
    }
    else
    {
      *green -= delta;
    }
  }
  break;
  // Green--
    case 4:
  {
     if((*green - delta) > INTENSITY_MIN)
    {
    *green -= delta;
    }
    else
    {
      *green += delta;
    }
  }
  break;
  // Blue++
  case 5:
  {
    if((*blue + delta) < INTENSITY_MAX)
    {
    *blue += delta;
    }
    else
    {
      *blue -= delta;
    }
  }
  break;
  // Blue--
    case 6:
  {
     if((*blue - delta) > INTENSITY_MIN)
    {
    *blue -= delta;
    }
    else
    {
      *blue += delta;
    }
  }
  break;
}
}


