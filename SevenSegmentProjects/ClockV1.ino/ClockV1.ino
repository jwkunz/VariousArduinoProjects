/*
 Developed by Jakob Kunzler
 May 21 2016
 jake.kunzler@gmail.com
  
This code programs an Arudino UNO that control 6 digits of a common cathode 7 segment display.  It generates it's timing by a series of calibration delays.  
Currently it is accurate to lose less than 1 second every 4 days.

The locations of each digit must be wired by the user to form the clock.
Location 1 is the most left (usually the first digit of the hours)
Location 6 is the most right (usually the second digit of the seconds)
There is no colon, so use spacing to seperate the digits

Driving a location high enables that location.
Driving a segment low will cause it light up if it's location is high.

*/

// Pin Definitions

//Segments on each digit
int a = 8;
int b = 12;
int c = 4;
int d = 2;
int e = 1;
int f = 9;
int g = 5;
int dp = 3; // The decimal point is used for loc6 instead because of pin limitations

//Digit location enables
int loc1 = 7;
int loc2 = 10;
int loc3 = 11;
int loc4 = 13;
int loc5 = 6;
int loc6 = dp;


void setup() {

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);


}

//This function makes all digits go blank
void clearall()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(loc1, LOW);
  digitalWrite(loc2, LOW);
  digitalWrite(loc3, LOW);
  digitalWrite(loc4, LOW);
  digitalWrite(loc5, LOW);
  digitalWrite(loc6, LOW);
}

//This function will take in chars representing natural numbers 0-9.  "number" is the number to be diplayed on a particular digit location indicated by "location".  
//The number will remain displayed until it is cleared.

void display(char number, char location)
{
  if (location == '1')
  {
    digitalWrite(loc1, HIGH);
    digitalWrite(loc2, LOW);
    digitalWrite(loc3, LOW);
    digitalWrite(loc4, LOW);
    digitalWrite(loc5, LOW);
    digitalWrite(loc6, LOW);

  }
  if (location == '2')
  {
    digitalWrite(loc1, LOW);
    digitalWrite(loc2, HIGH);
    digitalWrite(loc3, LOW);
    digitalWrite(loc4, LOW);
    digitalWrite(loc5, LOW);
    digitalWrite(loc6, LOW);
  }
  if (location == '3')
  {
    digitalWrite(loc1, LOW);
    digitalWrite(loc2, LOW);
    digitalWrite(loc3, HIGH);
    digitalWrite(loc4, LOW);
    digitalWrite(loc5, LOW);
    digitalWrite(loc6, LOW);
  }
  if (location == '4')
  {
    digitalWrite(loc1, LOW);
    digitalWrite(loc2, LOW);
    digitalWrite(loc3, LOW);
    digitalWrite(loc4, HIGH);
    digitalWrite(loc5, LOW);
    digitalWrite(loc6, LOW);
  }
   if (location == '5')
  {
    digitalWrite(loc1, LOW);
    digitalWrite(loc2, LOW);
    digitalWrite(loc3, LOW);
    digitalWrite(loc4, LOW);
    digitalWrite(loc5, HIGH);
    digitalWrite(loc6, LOW);
  }
  
   if (location == '6')
  {
    digitalWrite(loc1, LOW);
    digitalWrite(loc2, LOW);
    digitalWrite(loc3, LOW);
    digitalWrite(loc4, LOW);
    digitalWrite(loc5, LOW);
    digitalWrite(loc6, HIGH);
  }
  
  if (number == '1')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

  }
  if (number == '2')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);

  }
  if (number == '3')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);

  }
  if (number == '4')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

  }
  if (number == '5')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

  }
  if (number == '6')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

  }
  if (number == '7')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

  }
  if (number == '8')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

  }
  if (number == '9')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

  }
  if (number == '0')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);

  }

}
//This function displays a 6 digit number passed as a string.  All locations share wires as a bus, so it enables each digit for a short time so fast that it appears all locations display at once.
//This function does not have any loops and will only display the number for 1 cycle and will finish with cleared locations.

void display6(String number)
{
 int l = 3;
 char hundredthousands = number[0];
 char tenthousands = number[1];
 char thousands = number[2];
 char hundreds = number[3];
 char tens = number[4];
 char ones = number[5];

  display(ones, '6');
  delay(l);
  clearall();
  display(tens, '5');
  delay(l);
  clearall();
  display(hundreds, '4');
  delay(l);
  clearall();
  display(thousands, '3');
  delay(l);
  clearall();
  display(tenthousands, '2');
  delay(l);
  clearall();
  display(hundredthousands, '1');
  delay(l);
}

//This is a 12 hour clock calibrated for the Arduino UNO.  The clock is set from the start time passed as input as integers representing the hours, minutes, and seconds.
// Example Start at 8:30 -> clock12(8,30,0)
// Do not represent an int with one digit as two digits.  Ex) "1" not "01"
// The clock is an infinite loop that will only end when the power is turned off.
// Current accuacy, lose less than 1 second every 4 days.  
// NOTE:  The nature of using loops for timing is less accurate, so the clock will fluctuate between + or - 10 seconds of actual time throughout the day, but on the 12 hour cycle it will be accurate.

void clock12(int hours,int minutes,int seconds)
{

//Calibration delays
int calibration = 51;
int secondcalibration = 11;
int minutecalibration = 27;
int hourcalibration = 5;
int halfdaycalibration = 23;

//Intializing values
String s,m,h;
int j = 0;

  while (true)
  {
    // The < 10 statement account for single digit ints. 
    // ints are converted to Strings for displaying.
    
     if (seconds < 10)
    {
      s = String("0" + String(seconds));
    }
    else
    {
      s = String(seconds);
    }
    
    if (minutes < 10)
    {
      m = String("0" + String(minutes));
    }
    else
    {
      m = String(minutes);
    }
    
    if (hours < 10)
    {
      h = String("0" + String(hours));
    }
    else
    {
      h = String(hours);
    }

    //This is the final string passed into display6
    String disptime = String(h + m + s);
    
    display6(disptime);
    
    j++;
    //This j counter acts as the intial calibration for counting the second
    if (j == calibration)
    {  

      //Inside this statement all time advancements and calibration delays are handled
      delay(secondcalibration);
      seconds++;
      j = 0;

      if (seconds == 60 )
      {
        seconds = 0;
        delay(minutecalibration);
        minutes++;
       }
         if (minutes == 60 )
      {
        delay(hourcalibration);
        minutes = 0;
        hours++;
      }
         if (hours == 13 )
      {
        delay(halfdaycalibration);
        hours = 1;
      }
       
    }
  }
}


void loop() {
//Setting the clock
clock12(8,25,0);
}




