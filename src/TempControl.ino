//============================================================================
// Name        : TempControl.ino
// Author      : Romualdo Dasig
// Version     : v0.1
// Copyright   : MIT License
// Description : Display temperature to a Seven Segment LED Display
//============================================================================

// Libraries
#include <Arduino.h>
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

// Setup 7-Segment Display.
// Display segments (a,b,c,d,e,f,g)
int segment_a = 3;
int segment_b = 4;
int segment_c = 7;
int segment_d = 6;
int segment_e = 5;
int segment_f = 10;
int segment_g = 8;

// Display digits (00 - 99)
int display_0 = 12;
int display_1 = 11;

// Type
int type = COMMON_ANODE;

SevenSegmentDisplay sevenSegmentDisplay(
  segment_a,
  segment_b,
  segment_c,
  segment_d,
  segment_e,
  segment_f,
  segment_g,
  display_0,
  display_1,
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
  unsigned long currentMillis = millis();

  // Read temperature every 2 seconds.
  if (currentMillis - previousMillis >= interval) {
    // Save the last time we've read the temperature.
    previousMillis = currentMillis;

    // Read data and store it to variables hum and temp.
    // hum = dht.readHumidity();
    temp= dht.readTemperature();

    // Print temp and humidity values to serial monitor.
    // Serial.print("Humidity: ");
    // Serial.print(hum);
    // Serial.print(" %, Temp: ");
    // Serial.print(temp);
    // Serial.print(" *C\n");
  }

  // Display temperature.
  sevenSegmentDisplay.display(temp);
}
