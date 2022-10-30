#include <ESP8266WiFi.h>

#define A0 A0
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
#define SD2 9
#define SD3 10
#define RX 3
#define TX 1

WiFiClient client;
WiFiServer server(80);

void setup() 
{
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("Rohit", "123zxcvbnm");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  client = server.available();  //Gets a client that is connected to the server and has data available for reading.    
  if (client == 1)
  {  
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /f HTTP/1.1")
    {
      forward();
    }
    if(request == "GET /b HTTP/1.1")
    {
      backward();
    }
    if(request == "GET /r HTTP/1.1")
    {
      right();
    }
    if(request == "GET /l HTTP/1.1")
    {
      left();
    }
    if(request == "GET /s HTTP/1.1")
    {
      stoped();
    }
  }
}

void forward(){
  analogWrite(D1,250);
  analogWrite(D2,250);
  digitalWrite(D5,HIGH);
  digitalWrite(D4,HIGH);
  digitalWrite(D6,LOW);
  digitalWrite(D3,LOW);
  Serial.println("forward");
  
}
void backward(){
  analogWrite(D1,250);
  analogWrite(D2,250);
  digitalWrite(D6,HIGH);
  digitalWrite(D3,HIGH);
  digitalWrite(D5,LOW);
  digitalWrite(D4,LOW);
  Serial.println("backward");

}
void left(){
  analogWrite(D1,250);
  analogWrite(D2,250);
  digitalWrite(D6,LOW);
  digitalWrite(D3,HIGH);
  digitalWrite(D5,HIGH);
  digitalWrite(D4,LOW);
  Serial.println("left");
}
void right(){
  analogWrite(D1,250);
  analogWrite(D2,250);
  digitalWrite(D6,HIGH);
  digitalWrite(D3,LOW);
  digitalWrite(D5,LOW);
  digitalWrite(D4,HIGH);
  Serial.println("right");
}
void stoped(){
  analogWrite(D1,0);
  analogWrite(D2,0);
  digitalWrite(D6,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D5,LOW);
  digitalWrite(D4,LOW);
  Serial.println("stop");
}
