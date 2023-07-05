#include <Adafruit_Sensor.h>
#include <DHT.h>  //These libraries provide the necessary functions and definitions to interact with the DHT11 sensor.
#include <DHT_U.h> //These libraries provide the necessary functions and definitions to interact with the DHT11 sensor.
#define DHTTYPE    DHT11     // DHT 11
#define DHTPIN 2  //This line defines the pin to which the DHT11 sensor is connected. In this case, it is connected to pin 2 of the Arduino board. Modify this line if your sensor is connected to a different pin.
DHT_Unified dht(DHTPIN, DHTTYPE); //This line creates a DHT object called dht using the DHT_Unified class. The constructor takes two arguments: the pin number (DHTPIN) and the sensor type (DHTTYPE).


 void setup() {
  Serial.begin(9600); //This line initializes the serial communication with a baud rate of 9600. It allows you to communicate with the Arduino board and send/receive data via the serial monitor in the Arduino IDE.
  dht.begin(); //This line initializes the DHT sensor. It prepares the sensor for communication and configuration.
  sensor_t sensor; //he sensor_t structure is defined in the Adafruit Unified Sensor library and provides information about the sensor's capabilities and properties.
  
}
void loop()
{
  sensors_event_t event; //The sensors_event_t structure is defined in the Adafruit Unified Sensor library and holds the data from the sensor readings.
  dht.temperature().getEvent(&event); //This line retrieves the temperature reading from the DHT sensor using the temperature() function of the DHT_Unified object (dht). It then stores the temperature data in the event variable.
  Serial.print(F("Temperature: "));
  Serial.print(event.temperature);
  Serial.println(F("°C"));
  dht.humidity().getEvent(&event);
  Serial.print(F("Humidity: "));
  Serial.print(event.relative_humidity);
  Serial.println(F("%"));
  delay(1000);
}