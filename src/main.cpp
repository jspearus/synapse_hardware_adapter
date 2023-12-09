#include <Arduino.h>

#define T_LIGHT_1 21
#define T_LIGHT_2 20
#define T_LIGHT_3 19
#define T_LIGHT_4 18

#define S_LIGHT_1 5 // PWM Ctrl
#define S_LIGHT_2 6 // PWM Ctrl
#define S_LIGHT_3 3
#define S_LIGHT_4 9

// FUNCTION Declarations
void treeLights(int state, int delayTime);

String DataIn = "";
boolean flicker = false; // enable street light fflicker mode

unsigned long preTime; // time in milliseconds since system startup

unsigned char treeState; // state of tree activation
enum
{
  treeStart,
  tree1on,
  tree2on,
  tree3on,
  tree4on,
  tree1off,
  tree2off,
  tree3off,
  tree4off,
  treeDone
};

unsigned char lightState; // state of light activation
enum
{
  lightStart,
  light1on,
  light2on,
  light3on,
  light4on,
  light1off,
  light2off,
  light3off,
  light4off,
  lightDone
};

const unsigned long shortDelay = 500; // short delay between light / tree events
const unsigned long longDelay = 1500; // long delay between light / tree events
unsigned long preMillis = 0;

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

  treeState = treeDone;

  Serial.begin(115200);
}

void loop()
{
  if (Serial.available() > 0)
  {
    DataIn = Serial.readStringUntil('#');
  }
  if (DataIn == "sOnf")
  {
    flicker = true;
  }
  else if (DataIn == "sOfff")
  {
    flicker = false;
    digitalWrite(S_LIGHT_1, LOW);
    digitalWrite(S_LIGHT_2, LOW);
    digitalWrite(S_LIGHT_3, LOW);
    digitalWrite(S_LIGHT_4, LOW);
  }
  else if (DataIn == "sOff")
  {
    digitalWrite(S_LIGHT_1, LOW);
    delay(500);
    digitalWrite(S_LIGHT_2, LOW);
    delay(500);
    digitalWrite(S_LIGHT_3, LOW);
    delay(500);
    digitalWrite(S_LIGHT_4, LOW);
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
    // treeState = tree1on;
    // treeLights(0, shortDelay);
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

  if (flicker == true)
  {
    analogWrite(S_LIGHT_1, random(120) + 135);
    analogWrite(S_LIGHT_2, random(120) + 135);
    analogWrite(S_LIGHT_3, random(120) + 135);
    analogWrite(S_LIGHT_4, random(120) + 135);
    delay(random(100));
  }
}

void treeLights(int state, int delayTime)
{
  switch (treeState)
  {
  case tree1on:
    preMillis = millis();
    digitalWrite(T_LIGHT_1, state);
    treeState = tree2on;
    // Serial.println(preMillis);
    // Serial.println(treeState);

  case tree2on:
    // Serial.println(treeState);
    if (millis() - delayTime > preMillis)
    {
      preMillis = millis();
      treeState = tree3on;
      digitalWrite(T_LIGHT_2, state);
      // Serial.println(preMillis);
      // Serial.println(treeState);
    }

  case tree3on:
    if (millis() - delayTime > preMillis)
    {
      preMillis = millis();
      digitalWrite(T_LIGHT_3, state);
      treeState = tree4on;
      // Serial.println(preMillis);
      // Serial.println(treeState);
    }

  case tree4on:
    if (millis() - delayTime > preMillis)
    {
      digitalWrite(T_LIGHT_4, state);
      treeState = treeDone;
      DataIn = "";
      preMillis = millis();
      // Serial.println(preMillis);
      // Serial.println(treeState);
    }
  }
}