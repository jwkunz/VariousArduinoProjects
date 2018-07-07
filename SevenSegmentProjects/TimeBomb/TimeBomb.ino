


int a = 8;
int b = 12;
int c = 4;
int d = 2;
int e = 1;
int f = 9;
int g = 5;
int dp = 3;

int dig1 = 7;
int dig2 = 10;
int dig3 = A0;
int dig4 = 13;
int dig5 = 11;
int dig6 = A1;
int dig7 = A3;
int dig8 = 6;
int dig9 = A2;

int buzzpin = A5;


void setup() {


  
  //pinMode(0, OUTPUT);
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

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, OUTPUT);

}

void clearall()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dig1, LOW);
  digitalWrite(dig2, LOW);
  analogWrite(dig3, 0);
  digitalWrite(dig4, LOW);
  digitalWrite(dig5, LOW);
  analogWrite(dig6, 0);
  digitalWrite(dig7, LOW);
  digitalWrite(dig8, LOW);
  analogWrite(dig9, 0);
}


void display(char character, char digit, char decimal)
{

  if (decimal == '.')
  {
    digitalWrite(dp, LOW);
  }
  else
  {
    digitalWrite(dp, HIGH);
  }

  if (digit == '1')
  {
    digitalWrite(dig1, HIGH);
    digitalWrite(dig2, LOW);
    analogWrite(dig3, 0);
    digitalWrite(dig4, LOW);
    digitalWrite(dig5, LOW);
    analogWrite(dig6, 0);
    digitalWrite(dig7, LOW);
    digitalWrite(dig8, LOW);
    analogWrite(dig9, 0);

  }
  if (digit == '2')
  {
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, HIGH);
    analogWrite(dig3, 0);
    digitalWrite(dig4, LOW);
    digitalWrite(dig5, LOW);
    analogWrite(dig6, 0);
    digitalWrite(dig7, LOW);
    digitalWrite(dig8, LOW);
    analogWrite(dig9, 0);
  }
  if (digit == '3')
  {
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, LOW);
    analogWrite(dig3, 255);
    digitalWrite(dig4, LOW);
    digitalWrite(dig5, LOW);
    analogWrite(dig6, 0);
    digitalWrite(dig7, LOW);
    digitalWrite(dig8, LOW);
    analogWrite(dig9, 0);
  }
  if (digit == '4')
  {
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, LOW);
    analogWrite(dig3, 0);
    digitalWrite(dig4, HIGH);
    digitalWrite(dig5, LOW);
    analogWrite(dig6, 0);
    digitalWrite(dig7, LOW);
    digitalWrite(dig8, LOW);
    analogWrite(dig9, 0);
  }
  if (digit == '5')
  {
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, LOW);
    analogWrite(dig3, 0);
    digitalWrite(dig4, LOW);
    digitalWrite(dig5, HIGH);
    analogWrite(dig6, 0);
    digitalWrite(dig7, LOW);
    digitalWrite(dig8, LOW);
    analogWrite(dig9, 0);
  }

  if (digit == '6')
  {
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, LOW);
    analogWrite(dig3, 0);
    digitalWrite(dig4, LOW);
    digitalWrite(dig5, LOW);
    analogWrite(dig6, 255);
    digitalWrite(dig7, LOW);
    digitalWrite(dig8, LOW);
    analogWrite(dig9, 0);
  }
  if (digit == '7')
  {
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, LOW);
    analogWrite(dig3, 0);
    digitalWrite(dig4, LOW);
    digitalWrite(dig5, LOW);
    analogWrite(dig6, 0);
    digitalWrite(dig7, HIGH);
    digitalWrite(dig8, LOW);
    analogWrite(dig9, 0);
  }
  if (digit == '8')
  {
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, LOW);
    analogWrite(dig3, 0);
    digitalWrite(dig4, LOW);
    digitalWrite(dig5, LOW);
    analogWrite(dig6, 0);
    digitalWrite(dig7, LOW);
    digitalWrite(dig8, HIGH);
    analogWrite(dig9, 0);
  }
  if (digit == '9')
  {
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, LOW);
    analogWrite(dig3, 0);
    digitalWrite(dig4, LOW);
    digitalWrite(dig5, LOW);
    analogWrite(dig6, 0);
    digitalWrite(dig7, LOW);
    digitalWrite(dig8, LOW);
    analogWrite(dig9, 255);
  }
  if (digit == '0')
  {
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, LOW);
    analogWrite(dig3, 0);
    digitalWrite(dig4, LOW);
    digitalWrite(dig5, LOW);
    analogWrite(dig6, 0);
    digitalWrite(dig7, LOW);
    digitalWrite(dig8, LOW);
    analogWrite(dig9, 0);
  }
  if (character == '0')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (character == '1')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

  }
  if (character == '2')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);

  }
  if (character == '3')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);

  }
  if (character == '4')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

  }
  if (character == '5')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

  }
  if (character == '6')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

  }
  if (character == '7')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);

  }
  if (character == '8')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);

  }
  if (character == '9')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == ' ')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (character == 'A' || character == 'a')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'B')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'b')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'C')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (character == 'c')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (character == 'D')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (character == 'd')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (character == 'E' || character == 'e')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'F' || character == 'f')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'G')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'g')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'H')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'h')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'I' || character == 'i')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (character == 'J' || character == 'j')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (character == 'K' || character == 'k')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'L')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (character == 'l')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (character == 'N' || character == 'M')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (character == 'n' || character == 'm')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (character == 'O')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (character == 'o')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (character == 'P' || character == 'p')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'q' || character == 'Q')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'R')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'r')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (character == 'S' || character == 's')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'T')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (character == 't')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'U')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (character == 'u')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (character == 'V' || character == 'W')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (character == 'v' || character == 'w')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (character == 'X' || character == 'x')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'Y' || character == 'y')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == 'Z' || character == 'z')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (character == '=')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (character == '+')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == '-')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (character == ':')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (character == '/')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (character == '\\')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (character == '{' || character == '[' || character == '(' || character == '<')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (character == '}' || character == ']' || character == ')' || character == '>')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (character == '^')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (character == '\'')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (character == '"')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (character == ',')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (character == '.')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
  }
  if (character == '!')
  {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
  }
  if (character == '?')
  {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(dp, HIGH);
  }

}
void display9(String text)
{
  int l = 1;

  char t1 = text[0];
  char t2 = text[1];
  char t3 = text[2];
  char t4 = text[3];
  char t5 = text[4];
  char t6 = text[5];
  char t7 = text[6];
  char t8 = text[7];
  char t9 = text[8];

  display(t1, '1', '0');
  delay(l);
  clearall();
  display(t2, '2', '0');
  delay(l);
  clearall();
  display(t3, '3', '0');
  delay(l);
  clearall();
  display(t4, '4', '0');
  delay(l);
  clearall();
  display(t5, '5', '0');
  delay(l);
  clearall();
  display(t6, '6', '0');
  delay(l);
  clearall();
  display(t7, '7', '0');
  delay(l);
  clearall();
  display(t8, '8', '0');
  delay(l);
  clearall();
  display(t9, '9', '0');
  delay(l);
  clearall();
}
////////////////////////




/*
  void clock12(int hours,int minutes,int seconds,char AMPM)
  {
  int calibration = 48;
  //48 is fast
  //49 is slow
  int secondcalibration = 2;
  //10 is slow
  //5 is slow
  //1 is fast
  //3 is slow
  //2 is slow
  // 1 is final

  int minutecalibration = 2;
  //1 is fast
  //3 is slow 40 second over 12 hours ,
  //2 is fast
  int hourcalibration = 56;
  //56 is
  int halfdaycalibration = 0;

  int apchange = 0;
  String s,m,h;

  int j = 0;
  while (true)
  {
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
    String disptime = String(h + " " + m + " " + s + AMPM);
    display9(disptime);
    j++;

    if (j == calibration)
    {
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
      if (hours == 11)
      {
        apchange = 1;
      }
      }
      if (hours == 12)
      {
        if (AMPM == 'A' && apchange == 1)
         { AMPM = 'P';
            apchange = 0;
         }
        if (AMPM == 'P' && apchange == 1)
         { AMPM = 'A';
            apchange = 0;
         }

      }
         if (hours == 13 )
      {
        delay(halfdaycalibration);
        hours = 1;

      }

    }
  }


  void scroll(String text, double scrollspeed, char repeat)
  {

  int counter = 1;
  while (true)
  {

  for (int i = 0; i < (1/scrollspeed)*1000; i++)
   {
   display9(text.substring(0,9));
   delay(1);
   }

  int tsize = text.length();

  char temp = text[0];

  for (int i = 0; i < tsize; i++)
  {
    text[i] = text[i+1];
  }

  counter++;
  if (repeat == 'r')
  {text[tsize-1] = temp;}
  else
  {
    text[tsize-1] = ' ';
    if (counter == tsize)
    return;
  }


  }
  }
*/


void couptime()
{
  // takes 22 seconds
  int nC5 = 523;
  int nE5 = 659;
  int nG5 = 784;
  int nC6 = 1047;

  int beat = 128;

  for (int i = 0; i < 4; i++)
  {
    tone(buzzpin, nC5, beat);
    delay(beat);
    noTone(buzzpin);
    delay(beat / 4);
    tone(buzzpin, nE5, beat);
    delay(beat);
    noTone(buzzpin);
    delay(beat / 4);
    tone(buzzpin, nG5, beat);
    delay(beat);
    noTone(buzzpin);
    delay(beat / 4);
    tone(buzzpin, nC6, beat);
    delay(beat);
    noTone(buzzpin);
    delay(beat / 4);

    scroll("  HEY GUYS IT'S LUNCH     LET'S PLAY COUP!!! ", 200, 'N');

    noTone(buzzpin);
  }
  tone(buzzpin, 1000, 1000);
  delay(1000);
}

/*
  void alarmclock12(int hours,int minutes,int seconds,char AMPM,int alarmhours,int alarmminutes,int alarmseconds,char alarmAMPM)
  {
  int calibration = 48;
  int secondcalibration = 2;
  int minutecalibration = 2;
  //3 is slow
  int hourcalibration = 0;

  int halfdaycalibration = 0;

  int apchange = 0;
  String s,m,h;
  String as,am,ah;

  as = String(alarmseconds);
  am = String(alarmminutes);
  ah = String(alarmhours);

  int j = 0;
  int alarmcounter = 0;
  int alarmlength = 1;
  bool alarmflag = false;

  while (true)
  {
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
    String disptime = String(h + " " + m + " " + s + AMPM);
    display9(disptime);
    j++;

    if (j == calibration)
    {

      if((seconds == alarmseconds) && (minutes == alarmminutes) && (hours == alarmhours) && (AMPM == alarmAMPM))
      {
        alarmflag = true;
      }
      if(alarmflag)
      {
        alarmcounter++;


        //Insert Alarm Function HERE
        tickboom();


        int alarmLengthSeconds = 22;
        int alarmLengthMinutes = 0;
        seconds = seconds + alarmLengthSeconds;
        minutes = minutes + alarmLengthMinutes;

        if (seconds >= 60)
        {
          seconds = seconds - 60;
          minutes++;
        }
         if (minutes >= 60)
        {
          minutes = minutes - 60;
          hours++;
        }
      }
      if(alarmcounter == alarmlength)
      {
        alarmcounter =0;
        alarmflag = false;
      }

       delay(secondcalibration);
      seconds++;
      j = 0;


      if (seconds >= 60 )
      {
        seconds = 0;
        delay(minutecalibration);
        minutes++;
       }
         if (minutes >= 60 )
      {
        delay(hourcalibration);
        minutes = 0;
        hours++;
      }
      if (hours == 11)
      {
        apchange = 1;
      }
      }
      if (hours == 12)
      {
        if (AMPM == 'A' && apchange == 1)
         { AMPM = 'P';
            apchange = 0;
         }
        if (AMPM == 'P' && apchange == 1)
         { AMPM = 'A';
            apchange = 0;
         }

      }
         if (hours == 13 )
      {
        delay(halfdaycalibration);
        hours = 1;

      }

    }
  }
*/

void alarmclock12(int hours, int minutes, int seconds, char AMPM, int alarmhours, int alarmminutes, int alarmseconds, char alarmAMPM)
{
  unsigned long tic = millis();
  unsigned long toc = millis();

  int calibration = 989;
  int secondcalibration = 0;
  int minutecalibration = 0;
  int hourcalibration = 0;

  int halfdaycalibration = 0;

  int apchange = 0;
  String s, m, h;
  String as, am, ah;

  as = String(alarmseconds);
  am = String(alarmminutes);
  ah = String(alarmhours);

  int j = 0;
  int alarmcounter = 0;
  int alarmlength = 1;
  bool alarmflag = false;

  while (true)
  {


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
    String disptime = String(h + " " + m + " " + s + AMPM);
    
    
    
 int difference = 0;
 
    do
    {
    display9(disptime);
    toc = millis();
    difference = abs(toc - tic);
    }while(difference <= calibration);
    delay(secondcalibration);
   
   
      tic = millis();
      if ((seconds == alarmseconds) && (minutes == alarmminutes) && (hours == alarmhours) && (AMPM == alarmAMPM))
      {
        alarmflag = true;
      }
      if (alarmflag)
      {
        alarmcounter++;


        //Insert Alarm Function HERE
        tickboom();


        int alarmLengthSeconds = 13;
        int alarmLengthMinutes = 0;
        seconds = seconds + alarmLengthSeconds;
        minutes = minutes + alarmLengthMinutes;

        if (seconds >= 60)
        {
          seconds = seconds - 60;
          minutes++;
        }
        if (minutes >= 60)
        {
          minutes = minutes - 60;
          hours++;
        }
      }
      if (alarmcounter == alarmlength)
      {
        alarmcounter = 0;
        alarmflag = false;
      }

      
      seconds++;
      j = 0;


      if (seconds >= 60 )
      {
        seconds = 0;
        delay(minutecalibration);
        minutes++;
      }
      if (minutes >= 60 )
      {
        delay(hourcalibration);
        minutes = 0;
        hours++;
      }
      if (hours == 11)
      {
        apchange = 1;
      }
    
    if (hours == 12)
    {
      if (AMPM == 'A' && apchange == 1)
      { AMPM = 'P';
        apchange = 0;
      }
      if (AMPM == 'P' && apchange == 1)
      { AMPM = 'A';
        apchange = 0;
      }

    }
    if (hours == 13 )
    {
      delay(halfdaycalibration);
      hours = 1;

    }
  }
   }
 
void scroll(String text, double scrollspeed, char repeat)
{

  int counter = 1;
  while (true)
  {

    for (int i = 0; i < (1 / scrollspeed) * 1000; i++)
    {
      display9(text.substring(0, 9));
      delay(1);
    }

    int tsize = text.length();

    char temp = text[0];

    for (int i = 0; i < tsize; i++)
    {
      text[i] = text[i + 1];
    }

    counter++;
    if (repeat == 'r')
    {
      text[tsize - 1] = temp;
    }
    else
    {
      text[tsize - 1] = ' ';
      if (counter == tsize)
        return;
    }


  }
}


void tickboom()
{
  //Take 23 seconds
  int freq = 3000;

  for (int i = 9; i > 0; i--)
  {
    tone(buzzpin, freq, 200);

    for (int j = 0; j < 15 * i; j++)
    {

      String t = String("--- " + String(i) + " ---");
      display9(t);
    }
  }
  for (int k = 0; k < 8; k++)
  {
    tone(buzzpin, freq, 100);
    delay(100);
  }


  tone(buzzpin, 100, 5000);

  scroll(" BANG YOU'RE DEAD SUCKER!! ", 90, 'n');

  delay(1500);

}


int debounce()
{
int counter = 0;
int counter2 = 0;
int cutoff = 4;
int transition = 500;
  while(true)
  {
    if (analogRead(A4) > transition)
    {
      if (analogRead(A4) > transition)
      {
        counter++;
        delay(1);
      }
      else
      {
        counter = 0;
      }
      if (counter == cutoff)
      {
        return 1;
      }
    }

    if (analogRead(A4) < transition)
    {
      if (analogRead(A4) < transition)
      {
        counter2++;
        delay(1);
      }
      else
      {
        counter2 = 0;
      }
      if (counter2 == cutoff)
      {
        return 0;
      }
    }
 
}
}


int* UARTrx(int* packet)
{
  bool wait = true;
int rate = 1;
  
  while(wait)
  { 
    display9("  HI  ");
      
    if (debounce() == 0)
    {
      wait = false;
    }
    
  }
  for(int i = 0; i<10; i++)
  {
    display9("DATA IN ");
    delay(rate);
    packet[i] = debounce();
 
  }


  return packet;
}

String packet2String(int* packet)
{
  String s = "";
   for(int i = 0; i<10; i++)
   {
    s = String(s + String(packet[i]));
   }
   return s;
}



void loop() {



//alarmclock12(2, 33, 0, 'P', 8, 0,0, 'A');



int packet[] = {0,0,0,0,0,0,0,0,0,0};
String value = packet2String(UARTrx(packet));


 for(int i = 0; i < 500; i++)
{
display9(value);
}

}



