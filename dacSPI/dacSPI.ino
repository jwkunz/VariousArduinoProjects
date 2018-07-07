#include <softwareSPItx.h>
#include <ArduinoStdInt.h>


uint8_t serialOutPin = 13;
uint8_t lineEnablePin = 12;
uint8_t spiClockPin = 11;
uint32_t baudRate = 40000;
bool shiftLeft2Right = true;
bool risingEdge = false;
bool leHigh = false; 
bool dataHigh = true;



void setup() {

  Serial.begin(9600);
}

void loop() {

  softwareSPItx S(serialOutPin,lineEnablePin,spiClockPin,baudRate,shiftLeft2Right,risingEdge,leHigh,dataHigh);

  for (uint8_t j = 0; j < 255; j++)
  {
    delay(1000);
    String data = generatePacket(true, j);
    Serial.println(data);
    S.sendSPIpacket(&data);
    Serial.println(j);
  }


}

// Generates the appropriate packet.
String generatePacket(bool DACon, uint8_t voltageCode)
{
#define DAC_ON "00"
#define HIGH_Z_OFF "11"

  // Init memmory
  String packet = "";
  String onCommand = "00";
  String vCode = "00000000";
  String extra = "000000";

  // On or Off Select
  if (DACon == true)
  {
    onCommand = DAC_ON;
  } else
  {
    onCommand = HIGH_Z_OFF;
  }

  // Convert to binary string

#define MAXBITLOC 7
  int8_t   i = MAXBITLOC; // Counter init

  while (i >= 0) { // Counting down to 0

    if ((voltageCode >> i) & 1) // Bit shift see if one
    {
      vCode.setCharAt(MAXBITLOC - i, '1'); // Append 1 to string
    }
    else
    {
      vCode.setCharAt(MAXBITLOC - i, '0'); // Append 0 to string
    }
    --i;


  }
  // Finished

  // Create the packet
  packet.concat(onCommand);
  packet.concat(vCode);
  packet.concat(extra);

  // Return the packet
  return packet;
}




