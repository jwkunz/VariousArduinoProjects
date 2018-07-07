#include <Servo.h>

int laserpin = 7;
int azmpin = 6;
int zenpin = 5;

Servo AZM;
Servo ZEN;

void setup() {

 pinMode(laserpin,OUTPUT);
 AZM.attach(azmpin);
 ZEN.attach(zenpin);

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

void circle(double ca, double cz, double r,int dtime)
{
  
  digitalWrite(laserpin,HIGH);

for (double i = 0; i < 2*3.14; i = i + .1)
{
  double a = sin(i)*r + ca;
  double z = cos(i)*r + cz;
  zipto(a,z);
  delay(dtime);
}
  digitalWrite(laserpin,LOW);
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
    circle(ca,cz,i,2);
  }
}

void randomshot(int HA, int LA, int HZ, int LZ, int dtime)
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

void loop()
{
raster(2,25,115,65,130);
}



