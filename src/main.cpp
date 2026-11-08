#include <Arduino.h>
#include <Servo.h>

Servo monServo; // create servo object to control a servo
#define servoPin 3
#define servoDown 65
#define servoUp 100
 
String DataIn = "";

void setup()
{

  monServo.attach(servoPin);
  monServo.write(servoUp);
  Serial.begin(115200);
  // Serial.println("Projector Control Ready");
}

void loop()
{
  delay(100);
  if (Serial.available() > 0)
  {
    DataIn = Serial.readStringUntil('#');
    if (DataIn == "pOn")
    {
      // Serial.println("Projector ON");
      // Power On Projector
      monServo.write(servoUp);
      delay(100);
      monServo.write(servoDown);
      delay(300);
      monServo.write(servoUp);
      delay(1000);
      // Serial.println("ON");
    }
    else if (DataIn == "pOff")
    {
      // Serial.println("Projector OFF");
      // Power Off Projector
      monServo.write(servoUp);
      delay(100);
      monServo.write(servoDown);
      delay(200);
      monServo.write(servoUp);
      delay(400);
      monServo.write(servoDown);
      delay(400);
      monServo.write(servoUp);
      delay(1000);
      // Serial.println("OFF");
    }
  }
}