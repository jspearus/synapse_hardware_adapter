#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define BUFFER_SIZE 32 // Adjust based on expected message size

// Which pin on the Arduino is connected to the NeoPixels?
#define PIXEL1 17 // 17
#define PIXEL2 16 // 16
#define PIXEL3 10 // 10
#define PIXEL4 14 // 14
#define PIXEL5 15 // 15

#define OUT1 9 // Assign pin# to Outlets
#define OUT2 8
#define OUT3 7
#define OUT4 6
#define OUT5 5
#define OUT6 4
#define OUT7 3
#define OUT8 2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 150 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels1(NUMPIXELS, PIXEL1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, PIXEL2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS, PIXEL3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS, PIXEL4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels5(NUMPIXELS, PIXEL5, NEO_GRB + NEO_KHZ800);

String getValue(String data, char separator, int index);

void receiveEvent(int howMany);

void pixel1(int i, int r, int g, int b);
void pixel2(int i, int r, int g, int b);
void pixel3(int i, int r, int g, int b);
void pixel4(int i, int r, int g, int b);
void pixel5(int i, int r, int g, int b);

String DataIn = "";
char receivedText[BUFFER_SIZE];
int index = 0;

void setup()
{
  // Join I2C bus as slave with address 8
  Wire.begin(0x8);

  // Call receiveEvent when data received
  Wire.onReceive(receiveEvent);

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
  // if (Serial.available() > 0)
  // {
  //   DataIn = Serial.readStringUntil('#');
}
void receiveEvent(int numBytes)
{
  while (Wire.available())
  {
    char c = Wire.read();
    // Check for buffer overflow
    if (index < BUFFER_SIZE - 1)
    {
      receivedText[index++] = c;
    }
  }
  receivedText[index] = '\0'; // Null-terminate the string
  index = 0;                  // Reset index for the next message

  // Print the received text to the Serial Monitor
  Serial.println(receivedText);
  DataIn = receivedText;
  // /////////////////////////////////////////////////////////////////////
  if (DataIn == "\nshow")
  {
    pixels1.show(); // Send the updated pixel colors to the hardware.
    pixels2.show();
    pixels3.show();
    pixels4.show();
    pixels5.show();
  }
  else if (DataIn == "\nclear")
  {
    pixels1.clear();
    pixels2.clear();
    pixels3.clear();
    pixels4.clear();
    pixels5.clear();
  }
  else if (DataIn == "\nshow1")
  {
    pixels1.show(); // Send the updated pixel colors to the hardware.
  }
  else if (DataIn == "\nclear1")
  {
    pixels1.clear();
  }
  else if (DataIn == "\nshow2")
  {
    pixels2.show(); // Send the updated pixel colors to the hardware.
  }
  else if (DataIn == "\nclear3")
  {
    pixels2.clear();
  }
  else if (DataIn == "\nshow3")
  {
    pixels1.show(); // Send the updated pixel colors to the hardware.
  }
  else if (DataIn == "\nclear3")
  {
    pixels3.clear();
  }
  else if (DataIn == "\nshow4")
  {
    pixels4.show(); // Send the updated pixel colors to the hardware.
  }
  else if (DataIn == "\nclear4")
  {
    pixels4.clear();
  }
  else if (DataIn == "\nshow5")
  {
    pixels5.show(); // Send the updated pixel colors to the hardware.
  }
  else if (DataIn == "\nclear5")
  {
    pixels5.clear();
  }
  else if (DataIn == "\nout1on")
  {

    digitalWrite(OUT1, LOW); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout1off")
  {
    digitalWrite(OUT1, HIGH); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout2on")
  {
    digitalWrite(OUT2, LOW); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout2off")
  {
    digitalWrite(OUT2, HIGH); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout3on")
  {
    digitalWrite(OUT3, LOW); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout3off")
  {
    digitalWrite(OUT3, HIGH); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout4on")
  {
    digitalWrite(OUT4, LOW); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout4off")
  {
    digitalWrite(OUT4, HIGH); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout5on")
  {
    digitalWrite(OUT5, LOW); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout5off")
  {
    digitalWrite(OUT5, HIGH); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout6on")
  {
    digitalWrite(OUT6, LOW); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout6off")
  {
    digitalWrite(OUT6, HIGH); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout7on")
  {
    digitalWrite(OUT7, LOW); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout7off")
  {
    digitalWrite(OUT7, HIGH); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout8on")
  {
    digitalWrite(OUT8, LOW); // sets the digital pin 13 on
  }
  else if (DataIn == "\nout8off")
  {
    digitalWrite(OUT8, HIGH); // sets the digital pin 13 on
  }
  else
  {
    String string = getValue(DataIn, ',', 1);
    String led = getValue(DataIn, ',', 2);
    String r = getValue(DataIn, ',', 3);
    String g = getValue(DataIn, ',', 4);
    String b = getValue(DataIn, ',', 5);
    // Serial.print(string);
    if (string == "0")
    {
      pixel1(led.toInt(), r.toInt(), g.toInt(), b.toInt());
      pixel2(led.toInt(), r.toInt(), g.toInt(), b.toInt());
      pixel3(led.toInt(), r.toInt(), g.toInt(), b.toInt());
      pixel4(led.toInt(), r.toInt(), g.toInt(), b.toInt());
    }
    else if (string == "1")
    {
      pixel1(led.toInt(), r.toInt(), g.toInt(), b.toInt());
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
  // }
  DataIn = "";
  // ///////////////////////////////////////////////////////////////////
}

// void pixel(int i, int g, int r, int b)
// {
//   pixels1.setPixelColor(i, pixels1.Color(r, g, b));
// }
void pixel1(int i, int r, int g, int b)
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
  pixels4.setPixelColor(i, pixels4.Color(r, g, b));
}

void pixel5(int i, int r, int g, int b)
{
  pixels5.setPixelColor(i, pixels5.Color(r, g, b));
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