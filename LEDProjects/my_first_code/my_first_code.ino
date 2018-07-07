
int p0 = 0;
int p1 = 1;
int p2 = 2;
int p3 = 3;
int p4 = 4;
int p5 = 5;
int p6 = 6;
int p7 = 7;
int p8 = 8;
int p9 = 9;


void setup() {
  pinMode(p0, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(p5, OUTPUT);
  pinMode(p6, OUTPUT);
  pinMode(p7, OUTPUT);
  pinMode(p8, OUTPUT);
  pinMode(p9, OUTPUT);
}

void all_off()
{
  digitalWrite(p0, LOW);
  digitalWrite(p1, LOW);
  digitalWrite(p2, LOW);
  digitalWrite(p3, LOW);
  digitalWrite(p4, LOW);
  digitalWrite(p5, LOW);
  digitalWrite(p6, LOW);
  digitalWrite(p7, LOW);
  digitalWrite(p8, LOW);
  digitalWrite(p9, LOW);
}

void line()
{
  for (int i = 0; i <= 9; i++)
  {
    if (i == 0)  digitalWrite(p0, HIGH);
    if (i == 1)  digitalWrite(p1, HIGH);
    if (i == 2)  digitalWrite(p2, HIGH);
    if (i == 3)  digitalWrite(p3, HIGH);
    if (i == 4)  digitalWrite(p4, HIGH);
    if (i == 5)  digitalWrite(p5, HIGH);
    if (i == 6)  digitalWrite(p6, HIGH);
    if (i == 7)  digitalWrite(p7, HIGH);
    if (i == 8)  digitalWrite(p8, HIGH);
    if (i == 9)  digitalWrite(p9, HIGH);
    delay(50);
  }
}

void rline()
{

  for (int i = 9; i >= 0; i--)
  {
    if (i == 0)  digitalWrite(p0, HIGH);
    if (i == 1)  digitalWrite(p1, HIGH);
    if (i == 2)  digitalWrite(p2, HIGH);
    if (i == 3)  digitalWrite(p3, HIGH);
    if (i == 4)  digitalWrite(p4, HIGH);
    if (i == 5)  digitalWrite(p5, HIGH);
    if (i == 6)  digitalWrite(p6, HIGH);
    if (i == 7)  digitalWrite(p7, HIGH);
    if (i == 8)  digitalWrite(p8, HIGH);
    if (i == 9)  digitalWrite(p9, HIGH);
    delay(50);
  }
}

void all_on()
{
  digitalWrite(p0, HIGH);
  digitalWrite(p1, HIGH);
  digitalWrite(p2, HIGH);
  digitalWrite(p3, HIGH);
  digitalWrite(p4, HIGH);
  digitalWrite(p5, HIGH);
  digitalWrite(p6, HIGH);
  digitalWrite(p7, HIGH);
  digitalWrite(p8, HIGH);
  digitalWrite(p9, HIGH);
}

void inside_out()
{
  for (int i = 0;i <= 5; i++)
  {
    if (i == 5)  digitalWrite(p0, HIGH);
    if (i == 4)  digitalWrite(p1, HIGH);
    if (i == 3)  digitalWrite(p2, HIGH);
    if (i == 2)  digitalWrite(p3, HIGH);
    if (i == 1)  digitalWrite(p4, HIGH);
    if (i == 1)  digitalWrite(p5, HIGH);
    if (i == 2)  digitalWrite(p6, HIGH);
    if (i == 3)  digitalWrite(p7, HIGH);
    if (i == 4)  digitalWrite(p8, HIGH);
    if (i == 5)  digitalWrite(p9, HIGH);
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

