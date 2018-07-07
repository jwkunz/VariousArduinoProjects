#include <Servo.h>

int FL_pin =10;
int FR_pin =11;
int BL_pin =6;
int BR_pin =9;

Servo FL;
Servo FR;
Servo BL;
Servo BR;




void setup() {
  // put your setup code here, to run once:

FL.attach(FL_pin);
//0 Extended 180 Closed
FR.attach(FR_pin);
//0 Closed 180 Extended
BL.attach(BL_pin);
//0 Extended 180 Closed
BR.attach(BR_pin);
//0 Closed 180 Extended


}


void moveFL(int angle)
{
  
  FL.write(angle);
}
void moveFR(int angle)
{
   int a = abs(180 - angle);
  FR.write(a);
}
void moveBL(int angle)
{
  int a = abs(180 - angle);
  BL.write(a);
}
void moveBR(int angle)
{
  BR.write(angle);
}


void zeroposition()
{
  moveBR(100);
  moveBL(100);
  moveFR(45);
  moveFL(45);
}


void extendR()
{
  moveFR(140);
  moveBR(100);
}

void extendL()
{
  moveFL(140);
  moveBL(100);
}

void contractR()
{
  
  moveFR(0);
  moveBR(180);
}
void contractL()
{
 
  moveFL(0);
   moveBL(180);
}

void doublestep()
{
  
   
  zeroposition();
  moveBR(180);
  moveBL(180);
  delay(1000);
   moveFR(100);
  moveFL(100);
  delay(1000);
   moveBR(100);
  moveBL(100);
  delay(1000);
   moveFR(45);
  moveFL(45);
  delay(1000);
}

void loop() {



doublestep();
delay(500);


/*
moveFR(0);
moveFL(0);
delay(2000);
moveFR(180);
moveFL(180);
delay(2000);
moveFR(0);
moveFL(0);
delay(2000);
*/
}
