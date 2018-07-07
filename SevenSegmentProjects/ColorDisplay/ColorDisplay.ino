#include <ArduinoStdInt.h>
#include <SevenSegmentDriver.h>


SevenSegmentDriver SSD;

#define BAUDRATE 9600
#define TIMEOUT 3

String Red = "";
String Green = "";
String Blue = "";
String Display = "";
String RxString = "";

#define SCROLL_DELAY_MS 500 // Delay on scroll in milliseconds

void setup() {
  
  // Open Serial
  Serial.begin(BAUDRATE);
  // Set the timeout
  Serial.setTimeout(TIMEOUT);
  // Set scroll speed
  SSD.setScrollDelay(SCROLL_DELAY_MS);

}

void loop() {
  
  
  // Read the Serial string
  while(Serial.available() > 0)
  {

    RxString = Serial.readString();
    
  }
     
  // Find the location of the decimal dividers  
  uint8_t firstDec = RxString.indexOf('.',0);
  uint8_t secondDec = RxString.indexOf('.',firstDec+1);
  uint8_t thirdDec = RxString.indexOf('.',secondDec+1);
  
  // Break apart the RxString into it's pieces
  Red = RxString.substring(0,firstDec);
  Green = RxString.substring(firstDec+1,secondDec);
  Blue = RxString.substring(secondDec+1,thirdDec);
  
  // Format each String
  formatColorStrings(Red, Green,Blue);
   
  // Now Display all the String pieces
  displayColorValues(Red, Green, Blue);


  }
  


void formatColorStrings(String &Red, String &Green, String &Blue)
{
     // For each color, determine if the number has smaller than 3 digits 
   // and if necessary, add extra zeros to fill it up to 3 digits.
    
    if (Red.length() == 2)
    Red = String ("0" + Red);
    else if (Red.length() == 1)
    Red = String ("00" + Red);
    
    if (Green.length() == 2)
    Green = String ("0" + Green);
    else if (Green.length() == 1)
    Green = String ("00" + Green);
    
    if (Blue.length() == 2)
    Blue = String ("0" + Blue);
    else if (Green.length() == 1)
    Blue = String ("00" + Blue);
}

void displayColorValues(String &Red, String &Green, String &Blue)
{
    if (Red != "")
  {
  // Display each character of Red
  // Remember to clear the screen between chars
  SSD.displayChar(Red[0],0,false);
  SSD.clearAll();
  SSD.displayChar(Red[1],1,false);
  SSD.clearAll();
  SSD.displayChar(Red[2],2,true);
  SSD.clearAll();
  }

  if (Green != "")
  {
  // Display each character of Green
  // Remember to clear the screen between chars
  SSD.displayChar(Green[0],3,false);
  SSD.clearAll();
  SSD.displayChar(Green[1],4,false);
  SSD.clearAll();
  SSD.displayChar(Green[2],5,true);
  SSD.clearAll();
  }
  
    if (Blue != "")
  {
  // Display each character of Blue
  // Remember to clear the screen between chars
  SSD.displayChar(Blue[0],6,false);
  SSD.clearAll();
  SSD.displayChar(Blue[1],7,false);
  SSD.clearAll();
  SSD.displayChar(Blue[2],8,true);
  SSD.clearAll();
  }
}

