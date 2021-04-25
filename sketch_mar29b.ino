#include <Wire.h>
#include <Adafruit_MLX90614.h>

#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


Adafruit_MLX90614 mlx = Adafruit_MLX90614();

char auth[] = "XzoKnG0VElcxHCBYHev-5bpBd7tCzLyc";
char ssid[] = "JID01 2.4G";
char pass[] = "0881677852";
double temp_amb;
double temp_obj;
double calibration = 2.36;
void setup()
{
  // Debug console
  Serial.begin(9600);
  mlx.begin(); 
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  Serial.println("Temperature Sensor MLX90614");
}

void loop()
{
  Blynk.run();
  temp_amb = mlx.readAmbientTempC();
  temp_obj = mlx.readObjectTempC();
 
  //Serial Monitor
  Serial.print("Room Temp = ");
  Serial.println(temp_amb);
  Serial.print("Object temp = ");
  Serial.println(temp_obj);
  
  Blynk.virtualWrite(V1, temp_amb);
  Blynk.virtualWrite(V2, (temp_obj + calibration));
   delay(1000);
}
