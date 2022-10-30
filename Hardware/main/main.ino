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

#define frunt_dir = HIGH
#define back_dir = LOW



void setup() {
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
}

void loop() {
  
}

void forward(){
  analogWrite(D1,150);
  analogWrite(D2,150);
  digitalWrite(D5,HIGH);
  digitalWrite(D4,HIGH);
  digitalWrite(D6,LOW);
  digitalWrite(D3,LOW);
}
void backward(){
  analogWrite(D1,150);
  analogWrite(D2,150);
  digitalWrite(D6,HIGH);
  digitalWrite(D3,HIGH);
  digitalWrite(D5,LOW);
  digitalWrite(D4,LOW);
}
void left(){
  analogWrite(D1,150);
  analogWrite(D2,150);
  digitalWrite(D6,LOW);
  digitalWrite(D3,HIGH);
  digitalWrite(D5,HIGH);
  digitalWrite(D4,LOW);
}
void right(){
  analogWrite(D1,150);
  analogWrite(D2,150);
  digitalWrite(D6,HIGH);
  digitalWrite(D3,LOW);
  digitalWrite(D5,LOW);
  digitalWrite(D4,HIGH);
}
