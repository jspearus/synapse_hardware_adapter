#include <Arduino.h>

String DataIn = "";

void setup()
{

  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    DataIn = Serial.readStringUntil('#');
    if (DataIn == "Command")
    {
      // exicute code when cammand is sent
      delay(1000);
    }
  }
}