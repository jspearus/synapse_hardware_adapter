#include <Arduino.h>
#define LIGHT_1 5
#define LIGHT_2 6

String DataIn = "";

void setup()
{
  pinMode(LIGHT_1, OUTPUT);
  pinMode(LIGHT_2, OUTPUT);
  digitalWrite(LIGHT_1, HIGH);
  digitalWrite(LIGHT_2, HIGH);
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    DataIn = Serial.readStringUntil('#');
    if (DataIn == "pOn")
    {
      digitalWrite(LIGHT_1, LOW);
      delay(5000);
      digitalWrite(LIGHT_2, LOW);
    }
    else if (DataIn == "pOnq")
    {
      digitalWrite(LIGHT_1, LOW);
      delay(500);
      digitalWrite(LIGHT_2, LOW);
    }
    else if (DataIn == "pOff")
    {
      digitalWrite(LIGHT_1, HIGH);
      delay(100);
      digitalWrite(LIGHT_2, HIGH);
    }
  }
}