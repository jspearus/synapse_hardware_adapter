#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define T_LIGHT_1 21
#define T_LIGHT_2 20
#define T_LIGHT_3 19
#define T_LIGHT_4 18

String DataIn = "";

Adafruit_PWMServoDriver street_lights = Adafruit_PWMServoDriver(0x40);

void setup()
{
  pinMode(T_LIGHT_1, OUTPUT);
  pinMode(T_LIGHT_2, OUTPUT);
  pinMode(T_LIGHT_3, OUTPUT);
  pinMode(T_LIGHT_4, OUTPUT);

  digitalWrite(T_LIGHT_1, HIGH);
  digitalWrite(T_LIGHT_2, HIGH);
  digitalWrite(T_LIGHT_3, HIGH);
  digitalWrite(T_LIGHT_4, HIGH);

  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    DataIn = Serial.readStringUntil('#');
    if (DataIn == "sOn")
    {
      street_lights.setPWM(0, 2048, 0);
      delay(500);
      street_lights.setPWM(1, 2048, 0);
      delay(500);
      street_lights.setPWM(2, 2048, 0);
      delay(500);
      street_lights.setPWM(3, 2048, 0);
    }
    else if (DataIn == "sOnq")
    {
      street_lights.setPWM(0, 2048, 0);
      delay(100);
      street_lights.setPWM(1, 2048, 0);
      delay(100);
      street_lights.setPWM(2, 2048, 0);
      delay(100);
      street_lights.setPWM(3, 2048, 0);
    }
    else if (DataIn == "sOff")
    {
      street_lights.setPWM(0, 0, 2048);
      delay(100);
      street_lights.setPWM(1, 0, 2048);
      delay(100);
      street_lights.setPWM(2, 0, 2048);
      delay(100);
      street_lights.setPWM(3, 0, 2048);
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