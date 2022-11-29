#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define T_LIGHT_1 21
#define T_LIGHT_2 20
#define T_LIGHT_3 19
#define T_LIGHT_4 18

#define PWM_FREQ 50

String DataIn = "";

Adafruit_PWMServoDriver street_lights = Adafruit_PWMServoDriver(0x40);

void setup()
{

  street_lights.begin();
  street_lights.setPWMFreq(PWM_FREQ);

  pinMode(T_LIGHT_1, OUTPUT);
  pinMode(T_LIGHT_2, OUTPUT);
  pinMode(T_LIGHT_3, OUTPUT);
  pinMode(T_LIGHT_4, OUTPUT);

  digitalWrite(T_LIGHT_1, HIGH);
  digitalWrite(T_LIGHT_2, HIGH);
  digitalWrite(T_LIGHT_3, HIGH);
  digitalWrite(T_LIGHT_4, HIGH);

  Serial.begin(115200);
  street_lights.setPWM(0, 4096, 0);
  delay(500);
  street_lights.setPWM(1, 4096, 0);
  delay(500);
  street_lights.setPWM(2, 4096, 0);
  delay(500);
  street_lights.setPWM(3, 4096, 0);
  delay(500);
  street_lights.setPin(0, 0);
  street_lights.setPin(1, 0);
  street_lights.setPin(2, 0);
  street_lights.setPin(3, 0);
}

void loop()
{
  if (Serial.available() > 0)
  {
    DataIn = Serial.readStringUntil('#');
    if (DataIn == "sOn")
    {
      street_lights.setPWM(0, 4096, 0);
      delay(500);
      street_lights.setPWM(1, 4096, 0);
      delay(500);
      street_lights.setPWM(2, 4096, 0);
      delay(500);
      street_lights.setPWM(3, 4096, 0);
    }
    else if (DataIn == "sOnq")
    {
      street_lights.setPin(0, 3000);
      delay(100);
      street_lights.setPin(1, 3500);
      delay(100);
      street_lights.setPin(2, 3750);
      delay(100);
      street_lights.setPin(3, 4096);
    }
    else if (DataIn == "sOff")
    {
      street_lights.setPin(0, 0);
      delay(100);
      street_lights.setPin(1, 0);
      delay(100);
      street_lights.setPin(2, 0);
      delay(100);
      street_lights.setPin(3, 0);
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