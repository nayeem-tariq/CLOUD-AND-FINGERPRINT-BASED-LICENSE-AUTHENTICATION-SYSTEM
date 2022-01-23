#include <ESP8266WiFi.h>
#include<FirebaseArduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#define FIREBASE_HOST "licenseauthentication-f7388.firebaseio.com"
#define FIREBASE_AUTH "jSPfnkpjMm1L3oS6or3Lxz6k7F7QwIdCU8OUZyLU"
//Change line with your WiFi router name and password
#define WIFI_SSID "Redmi"  
#define WIFI_PASSWORD "1234554321"  

void setup()
{
   WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  lcd.setBacklight(HIGH);
  //Use predefined PINS consts
  Wire.begin(D4, D3);
  lcd.begin(20,4);
   lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("WELCOME TO CLOUD");
  lcd.setCursor(0, 1);
  lcd.print("BASED LICENSE CHECK,");
    lcd.setCursor(3, 2);
  lcd.print("VALIDATION AND");
  lcd.setCursor(3, 3);
  lcd.print("AUTHENTICATION");
  delay(4000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("connecting to.......");
lcd.setCursor(2,1);
lcd.print("google firebase");
lcd.setCursor(0,2);
lcd.print("Establishing link...");
delay(1000);
  while (WiFi.status()!=WL_CONNECTED){
    lcd.setCursor(4,3);
    lcd.print("Waiting.....");
    delay(1000);
  }
  lcd.setCursor(0,3);
  lcd.print("     connected      ");
  delay(2000);
  lcd.setCursor(3,3);
  lcd.print(WiFi.localIP());
  delay(2000);
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
}

  void firebasereconnect()
{
  lcd.setCursor(0,3);
  lcd.print("Trying to reconnect ");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  }




  void loop()
  {
     if (Firebase.failed())
      {
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Firebase Connection");
        lcd.setCursor(7,1);
        lcd.print("Failed");
        lcd.setCursor(1,2);
        lcd.print("Data Fetch Failed");
        delay(2000);
      firebasereconnect();
      return;
      }
String Name1=Firebase.getString("Name1"); String License1=Firebase.getString("License1");String Registration1=Firebase.getString("Registration1");String Pollution1=Firebase.getString("Pollution1");

lcd.clear(); lcd.setCursor(0,0);  lcd.print(Name1); lcd.setCursor(0,1);  lcd.print(License1); lcd.setCursor(0,2);  lcd.print(Registration1); lcd.setCursor(0,3);  lcd.print(Pollution1); delay(4000);




    
    }
