//============================================================================
// Name        : TempControl.ino
// Author      : Romualdo Dasig
// Version     : v0.1
// Copyright   : MIT License
// Description : Display temperature to a Seven Segment LED Display
//============================================================================

// Libraries
#include <DHT.h>
#include <LiquidCrystal.h>

// Setup Liquid Crystal Display.
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Setup Sensor.
#define DHTPIN  A0        // Temperature Sense pin
#define DHTTYPE DHT11     // DHT 11
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT Sensor

// Variables
float hum;  // Humidity
float temp; // Temperature

// Variable to store current time.
unsigned long previousMillis = 0;

// Set interval to read temperature.
const long interval = 2000;

void setup()
{
  // Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
}

void loop()
{
  // Get current time in milliseconds.
  unsigned long currentMillis = millis();

  // Read temperature every 2 seconds.
  if (currentMillis - previousMillis >= interval) {
    // Clear screen.
    // lcd.clear();

    // Save the last time we've read the temperature.
    previousMillis = currentMillis;

    // Read data and store it to variables hum and temp.
    hum = dht.readHumidity();
    temp = dht.readTemperature();

    // Serial.print("Temperature: ");
    // Serial.println(temp);
    // Serial.print("Humidity: ");
    // Serial.println(hum);
  }

  // Display temperature.
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" deg");

  // Display humidity.
  lcd.setCursor(0, 1);
  lcd.print(" Hum: ");
  lcd.print(hum);
  lcd.print("%");
}
