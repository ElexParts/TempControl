/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
   More info: http://www.ardumotive.com/how-to-use-dht-22-sensor-en.html
   Dev: Michalis Vasilakis // Date: 1/7/2015 // www.ardumotive.com */

// Libraries
#include <DHT.h>

// Constants
#define DHTPIN  2         // Temperature Sense pin
#define DHTTYPE DHT11     // DHT 11
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT Sensor

// Variables
float hum;  // Humidity
float temp; // Temperature

// Turn off temperature indicator by default.
int sensorState = LOW;
int oneState = HIGH;
int tenState = HIGH;

// Variable to store current time.
unsigned long previousMillis = 0;

// Set interval to read temperature.
const long interval = 2000;

// LED pins
const int segmentA = 3;
const int segmentB = 4;
const int segmentE = 5;
const int segmentD = 6;
const int segmentC = 7;
const int segmentG = 8;
const int segmentP = 9;
const int segmentF = 10;
const int displayOnes = 11;
const int displayTens = 12;

void setup()
{
  Serial.begin(9600);
  dht.begin();

  // Set display pins.
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);

  // Set digits.
  pinMode(displayOnes, OUTPUT);
  pinMode(displayTens, OUTPUT);
}

void displayTemp(float temp)
{
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentG, LOW);
  digitalWrite(segmentP, HIGH);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // Save the last time we've read the temperature.
    previousMillis = currentMillis;

    // Turn temperature indicator on and off.
    if (sensorState == LOW) {
      sensorState = HIGH;
      oneState = HIGH;
      tenState = LOW;
    } else {
      sensorState = LOW;
      oneState = LOW;
      tenState = HIGH;
    }

    // Toggle digits.
    digitalWrite(displayOnes, oneState);
    digitalWrite(displayTens, oneState);

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
  displayTemp(temp);
}

