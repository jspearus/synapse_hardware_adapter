#include <Arduino.h>

#define T_LIGHT_1 21
#define T_LIGHT_2 20
#define T_LIGHT_3 19
#define T_LIGHT_4 18

#define S_LIGHT_1 5
#define S_LIGHT_2 6
#define S_LIGHT_3 7
#define S_LIGHT_4 8

String DataIn = "";

void setup()
{

  pinMode(T_LIGHT_1, OUTPUT);
  pinMode(T_LIGHT_2, OUTPUT);
  pinMode(T_LIGHT_3, OUTPUT);
  pinMode(T_LIGHT_4, OUTPUT);

  pinMode(S_LIGHT_1, OUTPUT);
  pinMode(S_LIGHT_2, OUTPUT);
  pinMode(S_LIGHT_3, OUTPUT);
  pinMode(S_LIGHT_4, OUTPUT);

  digitalWrite(T_LIGHT_1, HIGH);
  digitalWrite(T_LIGHT_2, HIGH);
  digitalWrite(T_LIGHT_3, HIGH);
  digitalWrite(T_LIGHT_4, HIGH);

  digitalWrite(S_LIGHT_1, LOW);
  digitalWrite(S_LIGHT_2, LOW);
  digitalWrite(S_LIGHT_3, LOW);
  digitalWrite(S_LIGHT_4, LOW);

  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    DataIn = Serial.readStringUntil('#');
    if (DataIn == "sOn")
    {
      digitalWrite(S_LIGHT_1, HIGH);
      delay(1000);
      digitalWrite(S_LIGHT_2, HIGH);
      delay(1000);
      digitalWrite(S_LIGHT_3, HIGH);
      delay(1000);
      digitalWrite(S_LIGHT_4, HIGH);
    }
    else if (DataIn == "sOnq")
    {
      digitalWrite(S_LIGHT_1, HIGH);
      delay(250);
      digitalWrite(S_LIGHT_2, HIGH);
      delay(250);
      digitalWrite(S_LIGHT_3, HIGH);
      delay(250);
      digitalWrite(S_LIGHT_4, HIGH);
    }
    else if (DataIn == "sOff")
    {
      digitalWrite(S_LIGHT_1, LOW);
      delay(250);
      digitalWrite(S_LIGHT_2, LOW);
      delay(250);
      digitalWrite(S_LIGHT_3, LOW);
      delay(250);
      digitalWrite(S_LIGHT_4, LOW);
    }

    else if (DataIn == "tOn")
    {
      digitalWrite(T_LIGHT_1, LOW);
      delay(1000);
      digitalWrite(T_LIGHT_2, LOW);
      delay(1000);
      digitalWrite(T_LIGHT_3, LOW);
      delay(1000);
      digitalWrite(T_LIGHT_4, LOW);
    }
    else if (DataIn == "tOnq")
    {
      digitalWrite(T_LIGHT_1, LOW);
      delay(500);
      digitalWrite(T_LIGHT_2, LOW);
      delay(500);
      digitalWrite(T_LIGHT_3, LOW);
      delay(500);
      digitalWrite(T_LIGHT_4, LOW);
    }
    else if (DataIn == "tOff")
    {
      digitalWrite(T_LIGHT_1, HIGH);
      delay(500);
      digitalWrite(T_LIGHT_2, HIGH);
      delay(500);
      digitalWrite(T_LIGHT_3, HIGH);
      delay(500);
      digitalWrite(T_LIGHT_4, HIGH);
    }
  }
}