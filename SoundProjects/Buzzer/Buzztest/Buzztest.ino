int buzzpin = 3;

int C1 =  261; 
int Db1 =  277;
int D1 = 294; 
int Eb1 =  311;
int E1 =  330;
int F1 = 349;
int Gb1 = 370;
int G1 = 392;
int Ab1 = 415;
int nA1 = 440;
int Bb1 = 466;
int nB1 =  494;
int C2 = 523;
int D2 = 587;
int Eb2 = 622;
int E2 =  659;
int F2 =  698;
int Gb2 = 740;
int G2 =  784; 
int Ab2 =  831;
int nA2 =  880;
int Bb2 = 932;
int nB2 =  988;
int C3 =  1047;

void setup() {
  pinMode(buzzpin,OUTPUT);

}

void tickboom()
{
  int freq = 5000;
  for (int i = 1000; i > 0; i=i*.75)
{
tone(buzzpin,freq,100);

delay(i);
if (i < 200)
{
 for (int j = 1; j < 10; j++)
 {
  tone(buzzpin,freq,i/2);
  delay(i);
 }
 tone(buzzpin,50,5000);
 delay(5000);
 return;
}
}
}


void scale()
{
  tone(buzzpin,C1,500);
  delay(500);
 // tone(buzzpin,Db1,500);
 //delay(500);
  tone(buzzpin,D1,500);
  delay(500);
 // tone(buzzpin,Eb1,500);
  //delay(500);
  tone(buzzpin,E1,500);
  delay(500);
  tone(buzzpin,F1,500);
  delay(500);
  //tone(buzzpin,Gb1,500);
  //delay(500);
  tone(buzzpin,G1,500);
  delay(500);
  //tone(buzzpin,Ab1,500);
  //delay(500);
  tone(buzzpin,nA1,500);
  delay(500);
  //tone(buzzpin,Bb1,500);
  //delay(500);
  tone(buzzpin,nB1,500);
  delay(500);
  tone(buzzpin,C2,500);
  delay(500);
}

void playsong()
{
  int StarWars[] = {
    D1,1,
    0,1,
    D1,1,
    0,1,
    D1,1,
    G1,8,
    D2,8,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    nA1,1,
    G2,8,
    D2,8,
    0,1,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    nA1,1,
    G2,8,
    D2,8,
    0,1,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    C2,1,
    nA1,8,
    0,1,
    D1,1,
    0,1,
    D1,1,
    0,1,
    D1,1,
    G1,8,
    D2,8,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    nA1,1,
    G2,8,
    D2,8,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    nA1,1,
    G2,8,
    D2,8,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    C2,1,
    nA1,8,
    //
    D1,4,
    0,1,
    D1,3,
    E1,7,
    0,1,
    E1,2,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    nA1,1,
    0,1,
    G1,2,
    0,1,
    G1,2,
    nA1,2,
    nB1,2,
    nA1,2,
    E1,2,
    Gb1,4,
    //
    D1,4,
    0,1,
    D1,3,
    E1,7,
    0,1,
    E1,2,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    nA1,1,
    0,1,
    G1,2,
    D2,6,
    nA1,6,
    //
    D1,4,
    0,1,
    D1,3,
    E1,7,
    0,1,
    E1,2,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    nA1,1,
    0,1,
    G1,2,
    0,1,
    G1,2,
    nA1,2,
    nB1,2,
    nA1,2,
    E1,2,
    Gb1,4,
    //113
    D1,4,
    0,1,
    D1,2,
    0,1,
    G2,1,
    0,1,
    F2,1,
    0,1,
    Eb2,1,
    0,1,
    D2,1,
    0,1,
    C2,1,
    0,1,
    Bb1,1,
    0,1,
    nA1,1,
    0,1,
    G1,1,
    D2,8,
    0,4,   
    //134
    D1,1,
    0,1,
    D1,1,
    0,1,
    D1,1,
    G1,8,
    D2,8,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    nA1,1,
    G2,8,
    D2,8,
    0,1,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    nA1,1,
    G2,8,
    D2,8,
    0,1,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    C2,1,
    nA1,8,
    D1,1,
    0,1,
    D1,1,
    0,1,
    D1,1,
    G1,8,
    D2,8,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    nA1,1,
    G2,8,
    D2,8,
    0,1,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    nA1,1,
    G2,8,
    D2,8,
    0,1,
    C2,1,
    0,1,
    nB1,1,
    0,1,
    C2,1,
    nA1,8,
    //192
    D1,4,
    0,1,
    D1,2,
    0,1,
    G2,1,
    0,1,
    F2,1,
    0,1,
    Eb2,1,
    0,1,
    D2,1,
    0,1,
    C2,1,
    0,1,
    Bb1,1,
    0,1,
    nA1,1,
    0,1,
    G1,1,
    D2,4,
    0,1,
    G1,2,
    0,1,
    G1,2,
    0,1,
    G1,2,
    0,1,
    G1,4   
    
    };
  int msize = 219*2;
  double bpm = 45;
  double beatlength = (((1/bpm)/16)*60)*1000;

  for (int i = 0; i < msize; i = i+2)
  {
    int freq = StarWars[i];
    int beats = StarWars[i+1];     
    int blength = beats*beatlength;
    if(freq == 0)
    {
 
      noTone(buzzpin);
      delay(blength);
    }
    else
    {
    tone(buzzpin,freq);
    delay(blength);
    }
  }
  }

void loop() {

playsong();

}



