#include <Arduino.h>

//============================================================================
// Name        : TempControl.ino
// Author      : Romualdo Dasig
// Version     : v0.1
// Copyright   : MIT License
// Description : Display temperature to a Seven Segment LED Display
//============================================================================

// Libraries
#include <DHT.h>
// #include "lib/SevenSegmentDisplay/SevenSegmentDisplay.h"

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

// Setup 7-Segment Display.
// #define SEGMENTS[7] = {3,4,5,6,7,8,9}; // Display segments (a,b,c,d,e,f,g)
// #define DIGITS[2] = {12,11};           // Display digits (00 - 99)
// SevenSegmentDisplay sevenSegmentDisplay(SEGMENTS, DIGITS, COMMON_ANODE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
  // sevenSegmentDisplay.begin();
}

void loop()
{
  unsigned long currentMillis = millis();

  // Read temperature every 2 seconds.
  if (currentMillis - previousMillis >= interval) {
    // Save the last time we've read the temperature.
    previousMillis = currentMillis;

    // Read data and store it to variables hum and temp.
    hum = dht.readHumidity();
    temp= dht.readTemperature();

    // Print temp and humidity values to serial monitor.
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.print(" *C\n");
  }

  // Display temperature.
  // sevenSegmentDisplay.display(temp);
}
