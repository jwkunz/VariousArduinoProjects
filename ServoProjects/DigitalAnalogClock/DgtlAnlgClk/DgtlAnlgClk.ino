#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int sw = LOW;
int swpin = 4;

int debounce()
{
  while (true)
  {
    int old1 = sw;
    sw = digitalRead(swpin);
    if (old1 == sw)
    {
      delay(10);
      int old2 = digitalRead(swpin);
      if (old2 == old1)
      {
        return old2;
      }
    }
  }
}

void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
  pinMode(swpin,INPUT);
}

void loop() {


  for (int i = 0; i < 180; i++)
  {
    myservo.write(i);
   if(i == 0)
   {
    delay(50);
   }
     
    int flag = debounce();
    
    if (flag==HIGH)
    {
      myservo.write(0);
      delay(100);
    }
    delay(100);
  }
} 
  








