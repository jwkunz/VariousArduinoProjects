
void setup() {
  // put your setup code here, to run once:
pinMode(A0,OUTPUT);
pinMode(8,OUTPUT);
}

void sendpacket(int data[])
{
int  rate = 1;
rate = rate + 18;
  digitalWrite(8,LOW);
  delay(rate/2);
  for (int i = 0; i < 9; i++)
  {
    if (data[i] == 1)
    {
      digitalWrite(8,HIGH);
      delay(rate);
    }
    else
    {
      digitalWrite(8,LOW);
      delay(rate);
    }
  }
  
}



void loop() {

digitalWrite(8,HIGH);
delay(8000);
int d[] = { 0,1,0,0,1,0,1,0,1};
sendpacket(d);





}
