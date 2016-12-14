//============================================================================
// Name        : TempControl.ino
// Author      : Romualdo Dasig
// Version     : v0.1
// Copyright   : MIT License
// Description : Display temperature to a Seven Segment LED Display
//============================================================================

// Libraries
#include <DHT.h>
#include <SevenSegmentDisplay.h>

// Setup Sensor.
#define DHTPIN  2         // Temperature Sense pin
#define DHTTYPE DHT11     // DHT 11
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT Sensor

// Variables
float hum;  // Humidity
float temp; // Temperature

// Variable to store current time.
unsigned long previousMillis = 0;

// Set interval to read temperature.
const long interval = 2000;

// Configure a 2-Digit 7-Segment Display.
int segments[7] = {3, 4, 7, 6, 5, 10, 8}; // Display segments (a,b,c,d,e,f,g)
int displays[2] = {12, 11}; // Display digits (00 - 99)
int type = COMMON_ANODE; // Type

SevenSegmentDisplay sevenSegmentDisplay(
  segments[0],
  segments[1],
  segments[2],
  segments[3],
  segments[4],
  segments[5],
  segments[6],
  displays[0],
  displays[1],
  type
);

void setup()
{
  Serial.begin(9600);
  dht.begin();
  sevenSegmentDisplay.begin();
}

void loop()
{
  // Get current time in milliseconds.
  unsigned long currentMillis = millis();

  // Read temperature every 2 seconds.
  if (currentMillis - previousMillis >= interval) {
    // Save the last time we've read the temperature.
    previousMillis = currentMillis;

    // Read data and store it to variables hum and temp.
    // hum = dht.readHumidity();
    temp= dht.readTemperature();
  }

  // Display temperature.
  sevenSegmentDisplay.display(temp);
}
