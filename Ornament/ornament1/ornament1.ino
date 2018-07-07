#include <Adafruit_NeoPixel.h>

#define NUM_PIXELS 16
int D2 = 8; 
Adafruit_NeoPixel pixels(NUM_PIXELS, D2, NEO_GRB | NEO_KHZ800);

const int numColors = 12;
int R[numColors] = {255,255,227,255,255,128,075,000,127,000,127,255};
int G[numColors] = {194,165,066,000,000,000,000,000,255,255,255,255};
int B[numColors] = {000,000,052,000,255,128,130,255,212,000,000,000};

void setColor(int R, int G, int B) 
{
   for (int i = 0; i < NUM_PIXELS; i++) 
   {
      pixels.setPixelColor (i, R, G, B);
   }
   pixels.show();
}

void setup() 
{
   pixels.begin();
   pixels.show();
}

void loop() 
{
   for (int j = 0; j < numColors; j++) 
   {
      setColor (R[j], G[j], B[j]);
      delay (1000);
   }
}
