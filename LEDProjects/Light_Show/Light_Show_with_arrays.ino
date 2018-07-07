int p[] = {0,1,2,3,4,5,6,7,8,9};


void setup() {
  for(int i = 0; i<=9; i++)
  {
    pinMode(p[i],OUTPUT);
  }
}

void all_off()
{
  for (int i = 0; i <=9; i++)
 {
  digitalWrite(p[i], LOW);
 }
 
}

void all_on()
{
   for (int i = 0; i <=9; i++)
 {
  digitalWrite(p[i], HIGH);
 }
}

void line()
{
  for (int i = 0; i <= 9; i++)
  {
    if (i == 0)  digitalWrite(p[0], HIGH);
    if (i == 1)  digitalWrite(p[1], HIGH);
    if (i == 2)  digitalWrite(p[2], HIGH);
    if (i == 3)  digitalWrite(p[3], HIGH);
    if (i == 4)  digitalWrite(p[4], HIGH);
    if (i == 5)  digitalWrite(p[5], HIGH);
    if (i == 6)  digitalWrite(p[6], HIGH);
    if (i == 7)  digitalWrite(p[7], HIGH);
    if (i == 8)  digitalWrite(p[8], HIGH);
    if (i == 9)  digitalWrite(p[9], HIGH);
    delay(50);
  }
}

void rline()
{

  for (int i = 9; i >= 0; i--)
  {
    if (i == 0)  digitalWrite(p[0], HIGH);
    if (i == 1)  digitalWrite(p[1], HIGH);
    if (i == 2)  digitalWrite(p[2], HIGH);
    if (i == 3)  digitalWrite(p[3], HIGH);
    if (i == 4)  digitalWrite(p[4], HIGH);
    if (i == 5)  digitalWrite(p[5], HIGH);
    if (i == 6)  digitalWrite(p[6], HIGH);
    if (i == 7)  digitalWrite(p[7], HIGH);
    if (i == 8)  digitalWrite(p[8], HIGH);
    if (i == 9)  digitalWrite(p[9], HIGH);
    delay(50);
  }
}


void inside_out()
{
  for (int i = 0;i <= 5; i++)
  {
    if (i == 5)  digitalWrite(p[0], HIGH);
    if (i == 4)  digitalWrite(p[1], HIGH);
    if (i == 3)  digitalWrite(p[2], HIGH);
    if (i == 2)  digitalWrite(p[3], HIGH);
    if (i == 1)  digitalWrite(p[4], HIGH);
    if (i == 1)  digitalWrite(p[5], HIGH);
    if (i == 2)  digitalWrite(p[6], HIGH);
    if (i == 3)  digitalWrite(p[7], HIGH);
    if (i == 4)  digitalWrite(p[8], HIGH);
    if (i == 5)  digitalWrite(p[9], HIGH);
    delay(1000);
  }
  all_on();
  delay(1000);
  all_off();
  delay(1000);
}

void run_up_down()
{
  line();
  delay(100);
  all_off();
  rline();
  delay(100);
  all_off();
}

void warning()
{
  all_on();
  delay(20);
  all_off();
  delay(20);
}

void heart_beat()
{
  all_on();
  delay(150);
  all_off();
  delay(250);
   all_on();
  delay(150);
  all_off();
  

  delay(1000);
}
void loop()
{

 line();
 delay(100);
 all_off();
 rline();
 all_off();
 inside_out();
 run_up_down();
 warning();
 heart_beat();
}

