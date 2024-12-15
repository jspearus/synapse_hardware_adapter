#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 2 // On Trinket or Gemma, suggest changing this to 1

#define OUT1 9 // Assign pin# to Outlets
#define OUT2 8
#define OUT3 7
#define OUT4 10
#define OUT5 16
#define OUT6 14
#define OUT7 15
#define OUT8 18

// How many NeoPixels are attached to the Arduino?
#define NUMPIXEL_CENTER 140 // Popular NeoPixel ring size
#define NUMPIXELS 100       // Popular NeoPixel ring size

Adafruit_NeoPixel pixels1(NUMPIXEL_CENTER, PIN, NEO_GRB + NEO_KHZ800);

String getValue(String data, char separator, int index);

void pixel(int i, int r, int g, int b);

String DataIn = "";

void setup()
{
  Serial1.begin(115200);

  pixels1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop()
{ // pixels.clear(); // Set all pixel colors to 'off'
  if (Serial1.available() > 0)
  {
    DataIn = Serial1.readStringUntil('#');

    if (DataIn == "show1")
    {
      pixels1.show(); // Send the updated pixel colors to the hardware.
    }
    else if (DataIn == "clear1")
    {
      pixels1.clear();
    }
    else
    {
      String string = getValue(DataIn, ',', 0);
      String led = getValue(DataIn, ',', 1);
      String r = getValue(DataIn, ',', 2);
      String g = getValue(DataIn, ',', 3);
      String b = getValue(DataIn, ',', 4);
      pixel(led.toInt(), r.toInt(), g.toInt(), b.toInt());
    }
  }
}

void pixel(int i, int r, int g, int b)
{
  pixels1.setPixelColor(i, pixels1.Color(r, g, b));
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