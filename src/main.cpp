#include <Arduino.h>

#define T_LIGHT_1 21
#define T_LIGHT_2 20
#define T_LIGHT_3 19
#define T_LIGHT_4 18

#define S_LIGHT_1 5 // PWM Ctrl
#define S_LIGHT_2 6 // PWM Ctrl
#define S_LIGHT_3 3 // PWM Ctrl
#define S_LIGHT_4 9 // PWM Ctrl

// FUNCTION Declarations
void treeLights(int state, int delayTime);
void streetLights(int delayTime);

String DataIn = "";
boolean s_LIGHT_1 = false;
boolean s_LIGHT_2 = false;
boolean s_LIGHT_3 = false;
boolean s_LIGHT_4 = false;

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
unsigned long lpreMillis = 0;
enum
{
  on,
  off
};
int mode = 0;

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
  lightState = lightDone;

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
    Serial.println("street lights on");
    // lightState = light1on;
    s_LIGHT_1 = true;
    s_LIGHT_2 = true;
    s_LIGHT_3 = true;
    s_LIGHT_4 = true;
  }
  else if (DataIn == "sOfff")
  {
    Serial.println("street lights off");
    lightState = light1off;
    s_LIGHT_1 = false;
    s_LIGHT_2 = false;
    s_LIGHT_3 = false;
    s_LIGHT_4 = false;
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
    treeState = tree1on;
    mode = on;
  }
  else if (DataIn == "tOff")
  {
    treeState = tree1off;
    mode = off;
  }

  if (s_LIGHT_1 == true)
  {
    analogWrite(S_LIGHT_1, random(120) + 135);
  }
  if (s_LIGHT_2 == true)
  {
    analogWrite(S_LIGHT_2, random(120) + 135);
  }
  if (s_LIGHT_3 == true)
  {
    analogWrite(S_LIGHT_3, random(120) + 135);
  }
  if (s_LIGHT_4 == true)
  {
    analogWrite(S_LIGHT_4, random(120) + 135);
  }
  delay(random(100));
  if (s_LIGHT_1 == false)
  {
    analogWrite(S_LIGHT_1, 0);
  }
  if (s_LIGHT_2 == false)
  {
    analogWrite(S_LIGHT_2, 0);
  }
  if (s_LIGHT_3 == false)
  {
    analogWrite(S_LIGHT_3, 0);
  }
  if (s_LIGHT_4 == false)
  {
    analogWrite(S_LIGHT_4, 0);
  }

  if (treeState != treeDone)
  {
    treeLights(mode, shortDelay);
  }
  if (lightState != lightDone)
  {
    streetLights(shortDelay);
  }
  DataIn = "";
}

void treeLights(int state, int delayTime)
{
  Serial.print("Tree State: ");
  Serial.println(treeState);
  switch (treeState)
  {
  case tree1on:
    preMillis = millis();
    digitalWrite(T_LIGHT_1, state);
    treeState = tree2on;

  case tree2on:
    if (millis() - delayTime > preMillis)
    {
      preMillis = millis();
      treeState = tree3on;
      digitalWrite(T_LIGHT_2, state);
    }

  case tree3on:
    if (millis() - delayTime > preMillis)
    {
      preMillis = millis();
      digitalWrite(T_LIGHT_3, state);
      treeState = tree4on;
    }

  case tree4on:
    if (millis() - delayTime > preMillis)
    {
      digitalWrite(T_LIGHT_4, state);
      treeState = treeDone;
      DataIn = "";
      preMillis = millis();
    }
  case tree1off:
    preMillis = millis();
    digitalWrite(T_LIGHT_1, state);
    treeState = tree2off;

  case tree2off:
    if (millis() - delayTime > preMillis)
    {
      preMillis = millis();
      treeState = tree3off;
      digitalWrite(T_LIGHT_2, state);
    }

  case tree3off:
    if (millis() - delayTime > preMillis)
    {
      preMillis = millis();
      digitalWrite(T_LIGHT_3, state);
      treeState = tree4off;
    }

  case tree4off:
    if (millis() - delayTime > preMillis)
    {
      digitalWrite(T_LIGHT_4, state);
      treeState = treeDone;
      preMillis = millis();
    }
  }
}
void streetLights(int delayTime)
{
  Serial.print("light State: ");
  Serial.println(lightState);
  switch (lightState)
  {
  case light1on:
    lpreMillis = millis();
    s_LIGHT_1 = true;
    lightState = light2on;

  case light2on:
    if (millis() - delayTime > lpreMillis)
    {
      lpreMillis = millis();
      s_LIGHT_2 = true;
      lightState = light3on;
    }
  case light3on:
    if (millis() - delayTime > lpreMillis)
    {
      lpreMillis = millis();
      s_LIGHT_3 = true;
      lightState = light4on;
    }
  case light4on:
    if (millis() - delayTime > lpreMillis)
    {
      lpreMillis = millis();
      s_LIGHT_4 = true;
      lightState = lightDone;
    }

  case light1off:
    lpreMillis = millis();
    s_LIGHT_1 = false;
    lightState = light2off;

  case light2off:
    if (millis() - delayTime > lpreMillis)
    {
      lpreMillis = millis();
      s_LIGHT_2 = false;
      lightState = light3off;
    }
  case light3off:
    if (millis() - delayTime > lpreMillis)
    {
      lpreMillis = millis();
      s_LIGHT_3 = false;
      lightState = light4off;
    }
  case light4off:
    if (millis() - delayTime > lpreMillis)
    {
      lpreMillis = millis();
      s_LIGHT_4 = false;
      lightState = lightDone;
    }
  }
}