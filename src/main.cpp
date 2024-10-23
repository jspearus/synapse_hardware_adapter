#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 2  // On Trinket or Gemma, suggest changing this to 1
#define PIN2 3 // On Trinket or Gemma, suggest changing this to 1
#define PIN3 4 // On Trinket or Gemma, suggest changing this to 1
#define PIN4 5 // On Trinket or Gemma, suggest changing this to 1
#define PIN5 6 // On Trinket or Gemma, suggest changing this to 1

#define OUT1 7 // Assign pin# to Outlets
#define OUT2 8
#define OUT3 9
#define OUT4 16
#define OUT5 10
#define OUT6 14
#define OUT7 15
#define OUT8 18

// How many NeoPixels are attached to the Arduino?
#define NUMPIXEL_CENTER 114 // Popular NeoPixel ring size
#define NUMPIXELS 100       // Popular NeoPixel ring size

Adafruit_NeoPixel pixels1(NUMPIXEL_CENTER, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS, PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels5(NUMPIXELS, PIN5, NEO_GRB + NEO_KHZ800);

String getValue(String data, char separator, int index);

void pixel(int i, int r, int g, int b);
void pixel2(int i, int r, int g, int b);
void pixel3(int i, int r, int g, int b);
void pixel4(int i, int r, int g, int b);
void pixel5(int i, int r, int g, int b);

String DataIn = "";

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);

  pixels1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels2.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels3.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels4.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels5.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(OUT5, OUTPUT);
  pinMode(OUT6, OUTPUT);
  pinMode(OUT7, OUTPUT);
  pinMode(OUT8, OUTPUT);
  digitalWrite(OUT1, HIGH); // sets the digital pin 13 off
  digitalWrite(OUT2, HIGH); // sets the digital pin 13 off
  digitalWrite(OUT3, HIGH); // sets the digital pin 13 off
  digitalWrite(OUT4, HIGH); // sets the digital pin 13 off
  digitalWrite(OUT5, HIGH); // sets the digital pin 13 off
  digitalWrite(OUT6, HIGH); // sets the digital pin 13 off
  digitalWrite(OUT7, HIGH); // sets the digital pin 13 off
  digitalWrite(OUT8, HIGH); // sets the digital pin 13 off
}

void loop()
{

  // pixels.clear(); // Set all pixel colors to 'off'
  if (Serial1.available() > 0)
  {
    DataIn = Serial1.readStringUntil('#');
    if (DataIn == "show")
    {
      pixels1.show(); // Send the updated pixel colors to the hardware.
      pixels2.show();
      pixels3.show();
      pixels4.show();
      pixels5.show();
    }
    else if (DataIn == "clear")
    {
      pixels1.clear();
      pixels2.clear();
      pixels3.clear();
      pixels4.clear();
      pixels5.clear();
    }
    else if (DataIn == "show1")
    {
      pixels1.show(); // Send the updated pixel colors to the hardware.
    }
    else if (DataIn == "clear1")
    {
      pixels1.clear();
    }
    else if (DataIn == "show2")
    {
      pixels2.show(); // Send the updated pixel colors to the hardware.
    }
    else if (DataIn == "clear2")
    {
      pixels2.clear();
    }
    else if (DataIn == "show3")
    {
      pixels3.show(); // Send the updated pixel colors to the hardware.
    }
    else if (DataIn == "clear3")
    {
      pixels3.clear();
    }
    else if (DataIn == "show4")
    {
      pixels4.show(); // Send the updated pixel colors to the hardware.
    }
    else if (DataIn == "clear4")
    {
      pixels4.clear();
    }
    else if (DataIn == "show5")
    {
      pixels5.show(); // Send the updated pixel colors to the hardware.
    }
    else if (DataIn == "clear5")
    {
      pixels5.clear();
    }
    else if (DataIn == "out1on")
    {
      digitalWrite(OUT1, LOW); // sets the digital pin 13 on
    }
    else if (DataIn == "out1off")
    {
      digitalWrite(OUT1, HIGH); // sets the digital pin 13 on
    }
    else if (DataIn == "out2on")
    {
      digitalWrite(OUT2, LOW); // sets the digital pin 13 on
    }
    else if (DataIn == "out2off")
    {
      digitalWrite(OUT2, HIGH); // sets the digital pin 13 on
    }
    else if (DataIn == "out3on")
    {
      digitalWrite(OUT3, LOW); // sets the digital pin 13 on
    }
    else if (DataIn == "out3off")
    {
      digitalWrite(OUT3, HIGH); // sets the digital pin 13 on
    }
    else if (DataIn == "out4on")
    {
      digitalWrite(OUT4, LOW); // sets the digital pin 13 on
    }
    else if (DataIn == "out4off")
    {
      digitalWrite(OUT4, HIGH); // sets the digital pin 13 on
    }
    else if (DataIn == "out5on")
    {
      digitalWrite(OUT5, LOW); // sets the digital pin 13 on
    }
    else if (DataIn == "out5off")
    {
      digitalWrite(OUT5, HIGH); // sets the digital pin 13 on
    }
    else if (DataIn == "out6on")
    {
      digitalWrite(OUT6, LOW); // sets the digital pin 13 on
    }
    else if (DataIn == "out6off")
    {
      digitalWrite(OUT6, HIGH); // sets the digital pin 13 on
    }
    else if (DataIn == "out7on")
    {
      digitalWrite(OUT7, LOW); // sets the digital pin 13 on
    }
    else if (DataIn == "out7off")
    {
      digitalWrite(OUT7, HIGH); // sets the digital pin 13 on
    }
    else if (DataIn == "out8on")
    {
      digitalWrite(OUT8, LOW); // sets the digital pin 13 on
    }
    else if (DataIn == "out8off")
    {
      digitalWrite(OUT8, HIGH); // sets the digital pin 13 on
    }
    else
    {
      String string = getValue(DataIn, ',', 0);
      String led = getValue(DataIn, ',', 1);
      String r = getValue(DataIn, ',', 3);
      String g = getValue(DataIn, ',', 2);
      String b = getValue(DataIn, ',', 4);
      if (string == "0")
      {
        pixel2(led.toInt(), r.toInt(), g.toInt(), b.toInt());
        pixel3(led.toInt(), r.toInt(), g.toInt(), b.toInt());
        pixel4(led.toInt(), r.toInt(), g.toInt(), b.toInt());
        pixel5(led.toInt(), r.toInt(), g.toInt(), b.toInt());
      }
      else if (string == "1")
      {
        if (led.toInt() >= 50)
        {
          pixel(led.toInt(), r.toInt(), g.toInt(), b.toInt());
        }
        else
        {
          pixel(led.toInt(), g.toInt(), r.toInt(), b.toInt());
        }
      }
      else if (string == "2")
      {
        pixel2(led.toInt(), r.toInt(), g.toInt(), b.toInt());
      }
      else if (string == "3")
      {
        pixel3(led.toInt(), r.toInt(), g.toInt(), b.toInt());
      }
      else if (string == "4")
      {
        pixel4(led.toInt(), r.toInt(), g.toInt(), b.toInt());
      }
      else if (string == "5")
      {
        pixel5(led.toInt(), r.toInt(), g.toInt(), b.toInt());
      }
    }
  }
}

void pixel(int i, int g, int r, int b)
{
  pixels1.setPixelColor(i, pixels1.Color(r, g, b));
}

void pixel2(int i, int r, int g, int b)
{
  pixels2.setPixelColor(i, pixels2.Color(r, g, b));
}
void pixel3(int i, int r, int g, int b)
{
  pixels3.setPixelColor(i, pixels1.Color(r, g, b));
}

void pixel4(int i, int r, int g, int b)
{
  pixels4.setPixelColor(i, pixels2.Color(r, g, b));
}
void pixel5(int i, int r, int g, int b)
{
  pixels5.setPixelColor(i, pixels1.Color(r, g, b));
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++)
  {
    if (data.charAt(i) == separator || i == maxIndex)
    {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}