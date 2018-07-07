#include <Servo.h>

int laserpin = 7;
int azmpin = 6;
int zenpin = 5;

int Apin = A0;
int Bpin = A1;
int jXpin = A2;


Servo AZM;
Servo ZEN;


void setup() {

 pinMode(laserpin,OUTPUT);
 AZM.attach(azmpin);
 ZEN.attach(zenpin);

 pinMode(Apin,INPUT);
  pinMode(Bpin,INPUT);
   pinMode(jXpin,INPUT);
    

    Serial.begin(9600);



}

void flash(int dtime)
{
  digitalWrite(laserpin,HIGH);
delay(dtime);
digitalWrite(laserpin,LOW);
delay(dtime);
}

void zipto(int a,int z)
{
  AZM.write(a);
  ZEN.write(z);
}

void circle(double ca, double cz, double r)
{
  
  digitalWrite(laserpin,HIGH);
int dtime = r / 10;

if (r < 10)
{
  dtime = 1;
}


for (double i = 0; i < 2*3.14; i = i + .1)
{
  double a = sin(i)*r + ca;
  double z = cos(i)*r + cz;
  zipto(a,z);
  delay(dtime);
}

}

void fullsweep(int dtime)
{
  
  digitalWrite(laserpin,HIGH);

   
  for(int i = 45; i < 180; i++)
  {
    for (int j = 0; j < 180; j++)
    {
     
      zipto(j,i);
       if(j == 0)
      {
         delay(500);
      }
      delay(dtime);
    }
   
    }
  }


void target(int ca, int cz)
{
  for (int i = 15; i > 0; i=i-3)
  {
    circle(ca,cz,i);
  }
}

void randomshot(int dtime,int LA, int HA, int LZ, int HZ)
{
   
  digitalWrite(laserpin,HIGH);
  int ra = random(LA,HA);
  int rz = random(LZ,HZ);
  zipto(ra,rz);
  digitalWrite(laserpin,LOW);
  delay(dtime);
}

void raster(int dtime, int LA, int HA, int LZ, int HZ)
{
  
  for (int i = LA; i < HA; i = i+2)
  {
    
    for (int j = LZ; j < HZ; j++)
    {
      digitalWrite(laserpin,HIGH);
      zipto(i,j);
       digitalWrite(laserpin,LOW);
       delay(dtime);
    }
    for (int j = HZ; j > LZ; j--)
    {
      digitalWrite(laserpin,HIGH);
      zipto(i+1,j);
       digitalWrite(laserpin,LOW);
       delay(dtime);
    }
  }
}

struct buttons
{
  int A;
  int B;
  int jX;
    
};

struct buttons readButtons()
{
  buttons Blist;
  Blist.A = 0;
  Blist.B = 0;
  Blist.jX = 0;
 
  int dA =  analogRead(Apin);
  int dB = analogRead(Bpin);
  int dX = analogRead(jXpin);
 
 

 Serial.println(dA);
 Serial.println(dB);
 Serial.println(dX);
 
 


if (dX > 100)
{
  Blist.jX = -1;
}
else if ( dX < 60)
{
  Blist.jX = 1;
}
else
{
  Blist.jX = 0;
}

if (dA > 100)
{
  Blist.A = 1;
  Blist.jX = 0;
}
if (dB > 100)
{
  Blist.B = -1;
  Blist.jX = 0;
}

Serial.println(String("X: " + String(Blist.jX) + "A: " + String(Blist.A) + "B: " + String(Blist.B)));

  return Blist;
}






void loop()
{
digitalWrite(laserpin,HIGH);

while(true)
{
  randomshot(50,20,160,100,180);
}

String mode = "dot";

bool laser = true;
int spd = 1;

int Sa = 100;
int Sz = 100;
zipto(Sa,Sz);

while (true)
{
buttons Blist = readButtons();


  Sa = Sa + Blist.jX*spd;
  if (Sa >= 180)
  {
    Sa = 180;
  }
 if (Sa <= 0)
  {
    Sa = 0;
  }

  Sz = Sz + Blist.A*spd + Blist.B*spd;
  if (Sz >= 180)
  {
    Sa = 180;
  }
 if (Sz <= 70)
  {
    Sz = 70;
  }


if (Blist.A == 1 && Blist.B == -1 &&  mode == "circle")
  {
    /*
    digitalWrite(laserpin,LOW);
    laser = false;
    delay(500);
    */
    mode = "dot";
  }
  else if (Blist.A == 1 && Blist.B == -1 && mode == "dot")
  {
    /*
    digitalWrite(laserpin,HIGH);
    laser = true;
    delay(500);
    */

    mode = "circle";
  }
if (mode == "target")
{
  target(Sa,Sz);
  delay(1);
}
if (mode == "circle")
{
circle(Sa,Sz,5);
delay(1);
}
else if (mode == "dot");
{
  zipto(Sa,Sz);
  delay(50);
}
}



}







