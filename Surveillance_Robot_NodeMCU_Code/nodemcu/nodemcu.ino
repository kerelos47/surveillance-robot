#include <SoftwareSerial.h>
SoftwareSerial mySerial(4,5);

#include "Serial_Get_Data.h"
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

#define FIREBASE_HOST "bebo-26371-default-rtdb.firebaseio.com" //--> URL address of your Firebase Realtime Database.
#define FIREBASE_AUTH "vJ9b8HV5opCB0BA4xuXWX4vsz0Tz9L3pzy4xZ9uk" //--> Your firebase database secret code.

#define ON_Board_LED 2  //--> Defining an On Board LED, used for indicators when the process of connecting to a wifi router

//----------------------------------------SSID and Password of your WiFi router.
const char* ssid = "Pola"; //--> Your wifi name or SSID.
const char* password = "pola14112003"; //--> Your wifi password.
//----------------------------------------

long randNumber;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(500);
  pinMode(D3,OUTPUT);
  digitalWrite(D3, LOW);
  WiFi.begin(ssid, password); //--> Connect to your WiFi router
  Serial.println("");
    
  pinMode(ON_Board_LED,OUTPUT); //--> On Board LED port Direction output
  digitalWrite(ON_Board_LED, HIGH); //--> Turn off Led On Board

  //----------------------------------------Wait for connection
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    //----------------------------------------Make the On Board Flashing LED on the process of connecting to the wifi router.
    digitalWrite(ON_Board_LED, LOW);
    delay(250);
    digitalWrite(ON_Board_LED, HIGH);
    delay(250);
    //----------------------------------------
  }
  //----------------------------------------
  digitalWrite(ON_Board_LED, HIGH); //--> Turn off the On Board LED when it is connected to the wifi router.
  //----------------------------------------If successfully connected to the wifi router, the IP Address that will be visited is displayed in the serial monitor.
  
  //----------------------------------------

  //----------------------------------------Firebase Realtime Database Configuration.
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //----------------------------------------
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D3, HIGH);digitalWrite(ON_Board_LED, LOW);
  Get_Serial_Data('@',',','*');
  var_send_int[1]=var_res_int[1];
  var_send_int[2]=var_res_int[2];
  var_send_int[3]=var_res_int[3];
  var_send_int[4]=var_res_int[4];
  var_send_int[5]=(millis()/1000)%10;
  Put_Serial_Data('@',',','*');
  //----------------------------------------Send data in the form of random value data to the Firebase Realtime Database.
   Firebase.setString("send",datos); //--> Command or code to send data or update data (String data type) to the Firebase Realtime Database.
  datos="";
  // Conditions for handling errors.
  if (Firebase.failed()) { 
      
      Serial.println(Firebase.error());  
      delay(500);
      return;
  }

  
  //----------------------------------------

  //----------------------------------------Command or code to get data from Firebase Realtime Database.
 
  Serial.println(Firebase.getString("recieve")); //--> Command or code to get data (String data type) from Firebase Realtime Database.

  // Conditions for handling errors.
  if (Firebase.failed()) { 
      Serial.println(Firebase.error());
      digitalWrite(D3, LOW);digitalWrite(ON_Board_LED, HIGH);
      delay(500); 
      return;
  }
}
  
 
