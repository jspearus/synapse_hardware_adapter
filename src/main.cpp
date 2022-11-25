#include <Arduino.h>
#include <Servo.h>

Servo monServo; // create servo object to control a servo
#define servoPin 5
#define servoDown 80
#define servoUp 90

String DataIn = "";

void setup()
{

  monServo.attach(servoPin);
  monServo.write(servoUp);
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    DataIn = Serial.readStringUntil('#');
    if (DataIn == "mon")
    {
      // Power On Projector
      monServo.write(servoUp);
      delay(100);
      monServo.write(servoDown);
      delay(300);
      monServo.write(servoUp);
      delay(1000);
    }
    else if (DataIn == "moff")
    {
      // Power Off Projector
      monServo.write(servoUp);
      delay(100);
      monServo.write(servoDown);
      delay(200);
      monServo.write(servoUp);
      delay(200);
      monServo.write(servoDown);
      delay(400);
      monServo.write(servoUp);
      delay(1000);
    }
  }
}