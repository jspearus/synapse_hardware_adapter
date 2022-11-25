#include <Arduino.h>
#define LIGHT_1 5
#define LIGHT_2 6

String DataIn = "";

void setup()
{
  pinMode(LIGHT_1, OUTPUT);
  pinMode(LIGHT_2, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    DataIn = Serial.readStringUntil('#');
  }
}