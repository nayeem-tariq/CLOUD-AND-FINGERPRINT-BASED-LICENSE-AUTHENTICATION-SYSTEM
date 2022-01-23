#include <Adafruit_Fingerprint.h>
#include <ESP8266WiFi.h>
#include<FirebaseArduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
SoftwareSerial mySerial(D7, D8);
LiquidCrystal_I2C lcd(0x27, 20, 4);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

#define FIREBASE_HOST "licenseauthentication-f7388.firebaseio.com"
#define FIREBASE_AUTH "jSPfnkpjMm1L3oS6or3Lxz6k7F7QwIdCU8OUZyLU"
//Change line with your WiFi router name and password
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "1234554321"
void(*resetFunc)(void)=0;
void setup()
{
  Serial.begin(9600);
  finger.begin(57600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  lcd.setBacklight(HIGH);
  //Use predefined PINS consts
  Wire.begin(D4, D3);
  lcd.begin(20, 4);
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
  if (finger.verifyPassword()) {
    lcd.clear(); lcd.setCursor(0, 0); lcd.print("Adafruit Fingerprint"); lcd.setCursor(2, 1); lcd.print("Initializing...."); lcd.setCursor(1, 2); lcd.print("Fingerprint Sensor"); lcd.setCursor(7, 3); lcd.print("Found"); delay(3000);
  }
  else {
    lcd.clear(); lcd.setCursor(0, 0); lcd.print("Adafruit Fingerprint"); lcd.setCursor(2, 1); lcd.print("Initializing...."); lcd.setCursor(1, 2); lcd.print("Fingerprint Sensor"); lcd.setCursor(5, 3); lcd.print("Not Found"); delay(3000);
    while (1) {
      delay(1);
    }
  }
  finger.getTemplateCount();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("connecting to.......");
  lcd.setCursor(2, 1);
  lcd.print("google firebase");
  lcd.setCursor(0, 2);
  lcd.print("Establishing link...");
  delay(1000);
  while (WiFi.status() != WL_CONNECTED) {
    lcd.setCursor(4, 3);
    lcd.print("Waiting.....");
    delay(1000);
  }
  lcd.setCursor(0, 3);
  lcd.print("     connected      ");
  delay(3000);
  lcd.setCursor(3, 3);
  lcd.print(WiFi.localIP());
  delay(2000);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void firebasereconnect()
{
  lcd.setCursor(0, 3);
  lcd.print("Trying to reconnect ");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}




void loop()
{
  if (Firebase.failed())
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Firebase Connection");
    lcd.setCursor(7, 1);
    lcd.print("Failed");
    lcd.setCursor(1, 2);
    lcd.print("Data Fetch Failed");
    delay(2000);
    firebasereconnect();
    return;
  }
  lcd.clear(); lcd.setCursor(1, 0); lcd.print("Fingerprint Sensor"); lcd.setCursor(4, 1); lcd.print("Contains"); lcd.setCursor(15, 1); lcd.print(finger.templateCount); lcd.setCursor(5, 2); lcd.print(" templates"); lcd.setCursor(1, 3); lcd.print("Place Your Finger");; delay(3000);
  getFingerprintIDez();
  delay(500);            //don't ned to run this at full speed.
  switch (finger.fingerID)
  { 
      
    case 1:
      { lcd.clear(); lcd.setCursor(0, 0);  lcd.print("Fetching Details...."); lcd.setCursor(8, 1);  lcd.print("From"); lcd.setCursor(2, 2);  lcd.print("Google Firebase"); lcd.setCursor(3, 3); lcd.print(WiFi.localIP()); delay(2000); lcd.clear(); lcd.setCursor(0, 0);  lcd.print("Fetching Details...."); lcd.setCursor(8, 1);  lcd.print("From"); lcd.setCursor(2, 2);  lcd.print("Google Firebase"); lcd.setCursor(3, 3); lcd.print("Details Found"); delay(3000);
        String Name1 = Firebase.getString("Name1"); String License1 = Firebase.getString("License1"); String Registration1 = Firebase.getString("Registration1"); String Pollution1 = Firebase.getString("Pollution1");
        lcd.clear(); lcd.setCursor(0, 0);  lcd.print(Name1); lcd.setCursor(0, 1);  lcd.print(License1); lcd.setCursor(0, 2);  lcd.print(Registration1); lcd.setCursor(0, 3);  lcd.print(Pollution1); delay(4000);
        finger.fingerID = 0;
        break;
      }
    case 2:
      { lcd.clear(); lcd.setCursor(0, 0);  lcd.print("Fetching Details...."); lcd.setCursor(8, 1);  lcd.print("From"); lcd.setCursor(2, 2);  lcd.print("Google Firebase"); lcd.setCursor(3, 3); lcd.print(WiFi.localIP()); delay(2000); lcd.clear(); lcd.setCursor(0, 0);  lcd.print("Fetching Details...."); lcd.setCursor(8, 1);  lcd.print("From"); lcd.setCursor(2, 2);  lcd.print("Google Firebase"); lcd.setCursor(3, 3); lcd.print("Details Found"); delay(3000);
        String Name2 = Firebase.getString("Name2"); String License2 = Firebase.getString("License2"); String Registration2 = Firebase.getString("Registration2"); String Pollution2 = Firebase.getString("Pollution2");
        lcd.clear(); lcd.setCursor(0, 0);  lcd.print(Name2); lcd.setCursor(0, 1);  lcd.print(License2); lcd.setCursor(0, 2);  lcd.print(Registration2); lcd.setCursor(0, 3);  lcd.print(Pollution2); delay(4000);
        finger.fingerID = 0;
        break;
      }

    case 3:
      { lcd.clear(); lcd.setCursor(0, 0);  lcd.print("Fetching Details...."); lcd.setCursor(8, 1);  lcd.print("From"); lcd.setCursor(2, 2);  lcd.print("Google Firebase"); lcd.setCursor(3, 3); lcd.print(WiFi.localIP()); delay(2000); lcd.clear(); lcd.setCursor(0, 0);  lcd.print("Fetching Details...."); lcd.setCursor(8, 1);  lcd.print("From"); lcd.setCursor(2, 2);  lcd.print("Google Firebase"); lcd.setCursor(3, 3); lcd.print("Details Found"); delay(3000);
        String Name3 = Firebase.getString("Name3"); String License3 = Firebase.getString("License3"); String Registration3 = Firebase.getString("Registration3"); String Pollution3 = Firebase.getString("Pollution3");
        lcd.clear(); lcd.setCursor(0, 0);  lcd.print(Name3); lcd.setCursor(0, 1);  lcd.print(License3); lcd.setCursor(0, 2);  lcd.print(Registration3); lcd.setCursor(0, 3);  lcd.print(Pollution3); delay(4000);
        finger.fingerID = 0;
        break;
      }

    case 4:
      { lcd.clear(); lcd.setCursor(0, 0);  lcd.print("Fetching Details...."); lcd.setCursor(8, 1);  lcd.print("From"); lcd.setCursor(2, 2);  lcd.print("Google Firebase"); lcd.setCursor(3, 3); lcd.print(WiFi.localIP()); delay(2000); lcd.clear(); lcd.setCursor(0, 0);  lcd.print("Fetching Details...."); lcd.setCursor(8, 1);  lcd.print("From"); lcd.setCursor(2, 2);  lcd.print("Google Firebase"); lcd.setCursor(3, 3); lcd.print("Details Found"); delay(3000);
        String Name4 = Firebase.getString("Name4"); String License4 = Firebase.getString("License4"); String Registration4 = Firebase.getString("Registration4"); String Pollution4 = Firebase.getString("Pollution4");
        lcd.clear(); lcd.setCursor(0, 0);  lcd.print(Name4); lcd.setCursor(0, 1);  lcd.print(License4); lcd.setCursor(0, 2);  lcd.print(Registration4); lcd.setCursor(0, 3);  lcd.print(Pollution4); delay(4000);
        finger.fingerID = 0;
        break;
      }


    case 5:
      { lcd.clear(); lcd.setCursor(0, 0);  lcd.print("Fetching Details...."); lcd.setCursor(8, 1);  lcd.print("From"); lcd.setCursor(2, 2);  lcd.print("Google Firebase"); lcd.setCursor(3, 3); lcd.print(WiFi.localIP()); delay(2000); lcd.clear(); lcd.setCursor(0, 0);  lcd.print("Fetching Details...."); lcd.setCursor(8, 1);  lcd.print("From"); lcd.setCursor(2, 2);  lcd.print("Google Firebase"); lcd.setCursor(3, 3); lcd.print("Details Found"); delay(3000);
        String Name5 = Firebase.getString("Name5"); String License5 = Firebase.getString("License5"); String Registration5 = Firebase.getString("Registration5"); String Pollution5 = Firebase.getString("Pollution5");
        lcd.clear(); lcd.setCursor(0, 0);  lcd.print(Name5); lcd.setCursor(0, 1);  lcd.print(License5); lcd.setCursor(0, 2);  lcd.print(Registration5); lcd.setCursor(0, 3);  lcd.print(Pollution5); delay(4000);
        finger.fingerID = 0;
        break;
      }

  default:
      { lcd.clear(); lcd.setCursor(0, 0);  lcd.print("Fetching Details...."); lcd.setCursor(8, 1);  lcd.print("From"); lcd.setCursor(2, 2);  lcd.print("Google Firebase"); lcd.setCursor(3, 3); lcd.print(WiFi.localIP()); delay(2000); lcd.clear(); lcd.setCursor(0, 0);  lcd.print("Fetching Details...."); lcd.setCursor(8, 1);  lcd.print("From"); lcd.setCursor(2, 2);  lcd.print("Google Firebase"); lcd.setCursor(1, 3); lcd.print("Details not Found"); delay(3000);
      lcd.clear(); lcd.setCursor(4, 0);  lcd.print("Reset System");lcd.setCursor(9,1);  lcd.print("To");lcd.setCursor(2, 2);  lcd.print("Normal Settings"); delay(2000);
     // resetFunc();
        break;
      }


  }
}



uint8_t getFingerprintID() {
  
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;
}
