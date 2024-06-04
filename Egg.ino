// Mode trứng gà, trứng vịt, trứng chim chỉ
//------------------------------------ Blynk
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6vUynz5WG"
#define BLYNK_TEMPLATE_NAME "SEHI"
#define BLYNK_AUTH_TOKEN "Uee95hgp2Talvo-NdpcgF7eiUFA9EHNt"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "Uee95hgp2Talvo-NdpcgF7eiUFA9EHNt";
char ssid[] = "Egg";
char pass[] = "Egg123456789";
//--------------------------------------- DHT22
#include "DHT.h"
#define DHTPIN 27
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
//--------------------------------------- LCD
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
//------------------------------------ Ngoại vi
#define MODE 13
#define START 4
#define Stop 15

#define Fan1 14
#define Fan2 26 // Relay 2
#define UP_TEMP 19 // Máy sấy Relay 3
#define Light 34
#define Gas 35

#define Buzz 2
//---------------------------------- Varialble
int flag;
int Rb;
unsigned long TIme;
void setup(){
  Serial.begin(115200);  
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  dht.begin();
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  pinMode(Light,INPUT);
  pinMode(MODE,INPUT_PULLUP);
  pinMode(START,INPUT_PULLUP);
  pinMode(Stop,INPUT_PULLUP);
  pinMode(Fan1,OUTPUT);
  pinMode(Fan2,OUTPUT);
  pinMode(UP_TEMP,OUTPUT);

  Start();
  Mode();
}

void loop() { Blynk.run();
  UI();
  Run();
  Push_Data();
}

BLYNK_WRITE(V1){
  String Val = param.asString();
  if(Val == "M_1"){ flag = 1; Rb = 0;}
  if(Val == "M_2"){ flag = 1; Rb = 1;}
  if(Val == "M_3"){ flag = 1; Rb = 2;}
}
