

void setup() {
 pinMode(A0,INPUT);
 pinMode(13,OUTPUT);
  Serial.begin(9600);

}


void loop() {
int value = 0;

digitalWrite(13,HIGH);
delay(500);
digitalWrite(13,LOW);
delay(500);
value = analogRead(A0);
Serial.print("\n");
Serial.print(value);
}
