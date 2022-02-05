#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
// SETTING UP WIFI CONNECTIONS
char auth[] = "71UPmZgb8-cG4a-oUJwF0CigLrsGePNk"; // Auth code sent by Blynk
char ssid[] = "wifie_name"; //WIFI Name
char pass[] = "wifie_password"; //WIFI Password
//DHT 11
#define DHTPIN 2 // (D4) 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
void setup()
{
 dht.begin();
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);
}
void loop()
{
 Blynk.run();
 float h = dht.readHumidity(); //humidity (in %)
 float t = dht.readTemperature(); //temperature (in C)
 float rain=(1-((float)analogRead(A0)/1024))*100; //rain (in %)
 //Sending values to the Blynk app
 Blynk.virtualWrite(V5, h); //V5 is for Humidity
 Blynk.virtualWrite(V6, t); //V6 is for Temperature
 Blynk.virtualWrite(V7, rain); //V7 is for Rain
// Printing out to the serial monitor
 Serial.print("Humidity: ");
 Serial.println(h);
 Serial.print("Temperature (in C) :");
 Serial.println(t);
 Serial.print("Rain (in %) : ");
 Serial.print(rain);
 Serial.println(" %");
 Serial.println("------"); 
 delay(2000); 
}