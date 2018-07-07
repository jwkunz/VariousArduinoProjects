#include <ArduinoStdInt.h>
#include <SevenSegmentDriver.h>


SevenSegmentDriver SSD;

#define BAUDRATE 9600

#define SCROLL_DELAY_MS 500 // Delay on scroll in milliseconds

#define NUMDIGITS 9 // Number of digits on Seven Seg

String text = ""; // Text to display

void setup() {
  
  // Open Serial
  Serial.begin(BAUDRATE);
  // Set scroll speed
  SSD.setScrollDelay(SCROLL_DELAY_MS);
  

}

void loop() {
  
  
  while(Serial.available() > 0)
  {
   text = Serial.readString();   // Get the text
  }

if(text.length() > NUMDIGITS)
{
  // too big, scroll the text
  SSD.scroll(&text); 
}else
{
  // will fit, display it
  SSD.display9(&text);
}


  
}
