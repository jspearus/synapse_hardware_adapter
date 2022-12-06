#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 3   // On Trinket or Gemma, suggest changing this to 1
#define PIN2 5  // On Trinket or Gemma, suggest changing this to 1
#define PIN3 6  // On Trinket or Gemma, suggest changing this to 1
#define PIN4 9  // On Trinket or Gemma, suggest changing this to 1
#define PIN5 10 // On Trinket or Gemma, suggest changing this to 1

#define OUT1 18 // Assign pin# to Outlets
#define OUT2 15
#define OUT3 14
#define OUT4 16
#define OUT5 8
#define OUT6 7
#define OUT7 4
#define OUT8 2

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
  if (Serial.available() > 0)
  {
    DataIn = Serial.readStringUntil('#');
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
    else
    {
      delay(10);
    }
  }
}