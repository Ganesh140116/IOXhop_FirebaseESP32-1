#ifndef _IOXhop_FirebaseESP32_H_INCLUDED
#define _IOXhop_FirebaseESP32_H_INCLUDED

#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>
#include<HTTPClient.h>

#define FIREBASE_HOST "https://ganeshreddy-62380-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "AIzaSyDDB3kLFzzBCz_lH7ih3rG9PhdhoZ7GPdk"
#define WIFI_SSID "Ganesh"
#define WIFI_PASSWORD "GeePas@#?852"

int led = 2;
int led2 = 15;  // just leave this pin and connect all other remaining to Relays 
int led3 = 4;
int led4 = 13;
int led5 = 21;
int led6 = 19;
int led7 = 18;
int led8 = 5;

void setup() {
  Serial.begin(9600);
  delay(1000);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);

  delay(1000);


  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);

  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  // for (int i = 1; i <= 8; i++) {
  //   Firebase.setString("LED_STATUS" + String(i), "OFF");
  // }
}

void loop() {
 
  String pstatus = Firebase.getString("P1");
  String relay1 = Firebase.getString("L1");
  String relay2 = Firebase.getString("L2");
  String relay3 = Firebase.getString("L3");
  String relay4 = Firebase.getString("L4");
  String relay5 = Firebase.getString("L5");
  String relay6 = Firebase.getString("L6");
  String relay7 = Firebase.getString("L7");
  
  if(pstatus == "1")
    {
      digitalwrite(led,HIGH);
      digitalwrite(led3,HIGH);
      digitalwrite(led4,HIGH);
      digitalwrite(led5,HIGH);
      digitalwrite(led6,HIGH);
      digitalwrite(led7,HIGH);
      digitalwrite(led8,HIGH);
      
    }
    else if(pstatus =="0"){
      digitalwrite(led,LOW);
      digitalwrite(led3,LOW);
      digitalwrite(led4,LOW);
      digitalwrite(led5,LOW);
      digitalwrite(led6,LOW);
      digitalwrite(led7,LOW);
      digitalwrite(led8,LOW);
    }
    
    if(relay1 == "1")
    {
      digitalWrite(led,HIGH);
    }
    else if(relay1=="0")
    {
      digitalWrite(led,LOW);
    }

    if(relay2 == "1")
    {
      digitalWrite(led3,HIGH);
    }
    else if(relay2=="0")
    {
      digitalWrite(led3,LOW);
    }
    if(relay3 == "1")
    {
      digitalWrite(led4,HIGH);
    }
    else if(relay3=="0")
    {
      digitalWrite(led4,LOW);
    }
    if(relay4 == "1")
    {
      digitalWrite(led5,HIGH);
    }
    else if(relay4=="0")
    {
      digitalWrite(led5,LOW);
    }
    if(relay5 == "1")
    {
      digitalWrite(led6,HIGH);
    }
    else if(relay5=="0")
    {
      digitalWrite(led6,LOW);
    }
    if(relay6 == "1")
    {
      digitalWrite(led7,HIGH);
    }
    else if(relay6=="0")
    {
      digitalWrite(led7,LOW);
    }
    if(relay7 == "1")
    {
      digitalWrite(led8,HIGH);
    }
    else if(relay7=="0")
    {
      digitalWrite(led8,LOW);
    }
    
 delay(100);
}
