int micpin = A5;
int buzzpin = A4;
int oldvalue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(micpin,INPUT);
  pinMode(buzzpin,OUTPUT);
  Serial.begin(9800);
  
}

void loop() {
int value = analogRead(micpin);

Serial.print(value);
//analogWrite(buzzpin,255);
//delayMicroseconds(value);
//analogWrite(buzzpin,0);
if (value != 613)
{
  tone(buzzpin,1000,40);
}
oldvalue = value;
Serial.print("\n");
//delay(10);
}
  



