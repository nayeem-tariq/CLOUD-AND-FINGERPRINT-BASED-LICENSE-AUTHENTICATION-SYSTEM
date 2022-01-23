#include <ESP8266WiFi.h>
#include<FirebaseArduino.h>

#define FIREBASE_HOST "licenseauthentication-f7388.firebaseio.com"
#define FIREBASE_AUTH "jSPfnkpjMm1L3oS6or3Lxz6k7F7QwIdCU8OUZyLU"
//Change line with your WiFi router name and password
#define WIFI_SSID "Redmi"  
#define WIFI_PASSWORD "1234554321"                                   //Password of your wifi network 

#define Relay1 14  //D5
#define Relay2 12  //D6
#define Relay3 13  //D7
#define Relay4 15  //D8
int rel1,rel2,rel3,rel4;

void setup() 
{
  Serial.begin(9600);                                                   // Select the same baud rate if you want to see the datas on Serial Monitor
  pinMode(Relay1,OUTPUT);
  pinMode(Relay2,OUTPUT);
  pinMode(Relay3,OUTPUT);
  pinMode(Relay4,OUTPUT);
  digitalWrite(Relay1,HIGH);
  digitalWrite(Relay2,HIGH);
  digitalWrite(Relay3,HIGH);
  digitalWrite(Relay4,HIGH);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.setString("FB1",0);                     //Here the varialbe"FB1","FB2","FB3" and "FB4" needs to be the one which is used in our Firebase and MIT App Inventor
  Firebase.setString("FB2",0); 
  Firebase.setString("FB3",0); 
  Firebase.setString("FB4",0); 
  
}
void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  }

void loop() 
{
  if (Firebase.failed())
      {
      Serial.print("setting number failed:");
      Serial.println(Firebase.error());
      firebasereconnect();
      return;
      }
      
 String rel1=Firebase.getString("FB1");.toInt();  //Reading the value of the varialble Status from the firebase
  String rel2=Firebase.getString("FB2");.toInt();  //Reading the value of the varialble Status from the firebase
  String rel3=Firebase.getString("FB3");.toInt();  //Reading the value of the varialble Status from the firebase
 String  rel4=Firebase.getString("FB4");.toInt();  //Reading the value of the varialble Status from the firebase
  Serial.println(rel1);
  
  if(rel1==1)                                                             // If, the Status is 1, turn on the Relay1
     {
      digitalWrite(Relay1,LOW);
      Serial.println("Relay 1 ON");
    }
 if(rel1==0)                                                      // If, the Status is 0, turn Off the Relay1
    {                                      
      digitalWrite(Relay1,HIGH);
      Serial.println("Relay 1 OFF");
    }
if(rel2==1)                                                             // If, the Status is 1, turn on the Relay2
     {
      digitalWrite(Relay2,LOW);
      Serial.println("Relay 2 ON");
    }
 if(rel2==0)                                                      // If, the Status is 0, turn Off the Relay2
    {                                      
      digitalWrite(Relay2,HIGH);
      Serial.println("Relay 2 OFF");
    }
if(rel3==1)                                                             // If, the Status is 1, turn on the Relay3
     {
      digitalWrite(Relay3,LOW);
      Serial.println("Relay 3 ON");
    }
if(rel3==0)                                                      // If, the Status is 0, turn Off the Relay3
    {                                      
      digitalWrite(Relay3,HIGH);
      Serial.println("Relay 3 OFF");
    }
 if(rel4==1)                                                             // If, the Status is 1, turn on the Relay4
     {
      digitalWrite(Relay4,LOW);
      Serial.println("Relay 4 ON");
    }
if(rel4==0)                                                      // If, the Status is 0, turn Off the Relay4
    {                                      
      digitalWrite(Relay4,HIGH);
      Serial.println("Relay 4 OFF");
    }    
}
