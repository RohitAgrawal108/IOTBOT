#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>


WiFiClient wifiClient;

static const int RXPin = 4, TXPin = 5;
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);
String host = "api.thingspeak.com";
int httpPort = 80;
String url1 = "/update?api_key=JT1S8FCGIDEQBE21&field1=";
String url2 = "/update?api_key=JT1S8FCGIDEQBE21&field2=";

HTTPClient http;

void setup()
{
  Serial.begin(9600);
  WiFi.begin("Rohit", "123zxcvbnm");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  ss.begin(9600);
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
}

void loop()
{
  displayInfo();
}

void displayInfo()
{
//  if (gps.location.isValid() )
//  {
//    float latitude = (gps.location.lat());     //Storing the Lat. and Lon.
//    float longitude = (gps.location.lng());

    float latitude = 73.8713;     //Storing the Lat. and Lon.
    float longitude = 18.4695;
    
    Serial.print("LAT:  ");
    Serial.println(latitude, 6);  // float to x decimal places
    Serial.print("LONG: ");
    Serial.println(longitude, 6);

    //code for sending data to the apis


  Serial.println();
}
