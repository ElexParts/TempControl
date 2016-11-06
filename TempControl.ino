/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
   More info: http://www.ardumotive.com/how-to-use-dht-22-sensor-en.html
   Dev: Michalis Vasilakis // Date: 1/7/2015 // www.ardumotive.com */

// Libraries
#include <DHT.h>

// Constants
#define DHTPIN  7         // Temperature Sense pin
#define DHTTYPE DHT11     // DHT 11
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT Sensor

// Variables
float hum;  // Humidity
float temp; // Temperature

void setup()
{
    Serial.begin(9600);
    dht.begin();
}

void loop()
{
    // Wait a few seconds between measurements.
    delay(2000);
    
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

