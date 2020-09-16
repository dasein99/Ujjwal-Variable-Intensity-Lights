#include <WiFi.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

#define relay 10
int LED = 9;
int LED2 = 10;
int LDR = A0;

const char *ssid =  "Your wifi Network name";
const char *pass =  "Network password";

WiFiClient client;
 
void setup() 
{
       Serial.begin(9600);
       delay(10);
               
       Serial.println("Connecting to ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 

      pinMode(LED, OUTPUT);
      pinMode(LED2, OUTPUT);
      pinMode(relay, OUTPUT);
      pinMode(LDR, INPUT);
}
 
void loop() 
{
    int LDRValue = analogRead(LDR);
    Serial.print("sensor = ");
    Serial.print(LDRValue);

      if (LDRValue <=700) 
        {
           digitalWrite(LED, HIGH);
           digitalWrite(LED2, HIGH);
           digitalWrite(relay, HIGH);
           Serial.println("It's Dark Outside; Lights status: ON");
        }
      
      else 
        {
           digitalWrite(LED, LOW);
           digitalWrite(LED2, LOW);
           digitalWrite(relay, LOW);
           Serial.println("It's Bright Outside; Lights status: OFF");
        }
}
