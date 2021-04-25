#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int LEDD0 = D5; // ขา D0
int LEDD1 = D6; // ขา D1
int LEDD2 = D7; // ขา D2
int LEDD3 = D8; // ขา D3

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "XzoKnG0VElcxHCBYHev-5bpBd7tCzLyc";
char ssid[] = "iot";
char pass[] = "C0mputinG";
int go =255;
int st =0;
int WS,LR;
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1
BLYNK_WRITE(V1)
{
   WS = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.print("WS Slider value is: ");
  Serial.println(WS);
}
BLYNK_WRITE(V2)
{
  LR = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.print("LR Slider value is: ");
  Serial.println(LR);
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(LEDD0, OUTPUT); // กำหนดการทำงานของขา D0 ให้เป็น Output
  pinMode(LEDD1, OUTPUT);
  pinMode(LEDD2, OUTPUT);
  pinMode(LEDD3, OUTPUT);
  digitalWrite(LEDD0, LOW);
  digitalWrite(LEDD1, LOW);
  digitalWrite(LEDD2, LOW);
  digitalWrite(LEDD3, LOW);
  //Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  if(LR == 1 && WS == 1){ // 0
    Blynk.virtualWrite(V3,st);
    Blynk.virtualWrite(V4,go);
    Blynk.virtualWrite(V5,st);
    Blynk.virtualWrite(V6,st);
    Blynk.virtualWrite(V7,st);
    digitalWrite(LEDD0, LOW);
  digitalWrite(LEDD1, LOW);
  digitalWrite(LEDD2, LOW);
  digitalWrite(LEDD3, LOW);
  }
  else if(WS == 0 && LR == 1){ //S
    Blynk.virtualWrite(V3,st);
    Blynk.virtualWrite(V4,st);
    Blynk.virtualWrite(V5,go);
    Blynk.virtualWrite(V6,st);
    Blynk.virtualWrite(V7,st);
    digitalWrite(LEDD0, LOW);
    digitalWrite(LEDD1, HIGH);
    digitalWrite(LEDD2, HIGH); 
    digitalWrite(LEDD3, HIGH);
    
  }
  else if(WS == 2 && LR == 1){ //W
    Blynk.virtualWrite(V3,go);
    Blynk.virtualWrite(V4,st);
    Blynk.virtualWrite(V5,st);
    Blynk.virtualWrite(V6,st);
    Blynk.virtualWrite(V7,st);
    digitalWrite(LEDD0, HIGH);
    digitalWrite(LEDD1, HIGH);
    digitalWrite(LEDD2, LOW); 
    digitalWrite(LEDD3, HIGH);
  }
  else if(WS == 1 && LR == 0){// A
    Blynk.virtualWrite(V3,st);
    Blynk.virtualWrite(V4,st);
    Blynk.virtualWrite(V5,st);
    Blynk.virtualWrite(V6,go);
    Blynk.virtualWrite(V7,st);
    digitalWrite(LEDD0, HIGH);
    digitalWrite(LEDD1, HIGH);
    digitalWrite(LEDD2, LOW); 
    digitalWrite(LEDD3, LOW);
  }
  else if(WS == 1 && LR == 2){//D
    Blynk.virtualWrite(V3,st);
    Blynk.virtualWrite(V4,st);
    Blynk.virtualWrite(V5,st);
    Blynk.virtualWrite(V6,st);
    Blynk.virtualWrite(V7,go);
    digitalWrite(LEDD0, LOW);
    digitalWrite(LEDD1, LOW);
    digitalWrite(LEDD2, LOW); 
    digitalWrite(LEDD3, HIGH);
  }
    
  Blynk.run();
}
