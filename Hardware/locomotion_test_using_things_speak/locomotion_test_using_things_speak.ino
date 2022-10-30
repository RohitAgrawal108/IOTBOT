#include <ESP8266WiFi.h>

int value = 0;
const char *ssid = "Rohit";
const char *password = "qwertyuiop";

const char *host = "api.thingspeak.com";


int find_text(String needle, String haystack, int form)
{
    //find text function
    int foundpos = -1;
    if (haystack.length() < needle.length())
    {
        return foundpos;
    }
    for (int i = 0; (i < (haystack.length() - needle.length())); i++)
    {
        if (haystack.substring(i, needle.length() + i) == needle)
        {
            foundpos = i;
            return foundpos;
        }
    }
    return foundpos;

}

void setup()
{
    Serial.begin(9600);
    delay(100);

    WiFi.begin("Rohit", "qwertyuiop");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(200);
        Serial.print("..");
    }
    Serial.println();
    Serial.println("NodeMCU is connected!");
    Serial.println(WiFi.localIP());
}

void loop()
{
    Serial.print("connecting to ");
    Serial.println(host);
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort))
    {
        Serial.println("Connection Failed");
    }

    String url = "https://api.thingspeak.com/apps/thinghttp/send_request?api_key=5LBNVFUKP6WV45Y4";

    Serial.print("Requesting URL: ");
    Serial.println(url);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
    delay(500);

    while (client.available())
    {
      Serial.println("**********************IN AVAILABE************************");
      
        String line = client.readStringUntil('\r');
//        Serial.println(line);
          if(line.substring(line.length()-1,line.length())=="S"||line.substring(line.length()-1,line.length())=="F"||line.substring(line.length()-1,line.length())=="B"||line.substring(line.length()-1,line.length())=="L"||line.substring(line.length()-1,line.length())=="R")
            {
                    Serial.println(line.substring(line.length()-1,line.length()));
            }
        // find the static data from the serverwebsite
    }
}
