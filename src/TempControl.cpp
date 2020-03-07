//============================================================================
// Name        : TempControl.ino
// Author      : Romualdo Dasig
// Version     : v1.0.0
// Copyright   : MIT License
// Description : Display temperature and humidity on a Liquid Crystal Display
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
  dht.begin();
  lcd.begin(16, 2);

  lcd.print("Initializing");
  int i = 3;
  while(i > 0) {
    delay(1000);
    lcd.print(".");
    i--;
  }
  delay(1000);
  lcd.clear();
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
    hum = dht.readHumidity();
    temp = dht.readTemperature();
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
  lcd.print(" %");
}
