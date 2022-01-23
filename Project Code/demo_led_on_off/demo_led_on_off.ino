#include <FirebaseArduino.h>
#include "DHT.h"
#include  <ESP8266WiFi.h>
#define FIREBASE_HOST "licenseauthentication-f7388.firebaseio.com"
#define FIREBASE_AUTH "jSPfnkpjMm1L3oS6or3Lxz6k7F7QwIdCU8OUZyLU"
#define WIFI_SSID "Abc"
#define WIFI_PASSWORD "arshid11"
#define DHTPIN 14    // Data Pin of DHT 11 , for NodeMCU D5 GPIO no. is 14
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
 Serial.begin(9600);
 WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
   dht.begin();
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST);
  
}
void loop() {
 
  float h = dht.readHumidity();
  
  float t = dht.readTemperature();  // Reading temperature as Celsius (the default)
  Firebase.setFloat ("Temp",t);
  Firebase.setFloat ("Humidity",h);
  delay(200);
}
