// TAP UI //

void Start(){
  for(int i = 1; i < 14; i++)
    {
     digitalWrite(Buzz,millis()/(i*50)%2);
     lcd.clear();
     lcd.setCursor(4+i,0); lcd.print("Wellcome");
     lcd.setCursor(3+i,1); lcd.print("SEHI"); delay(300);
    }
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("SEHI");
  delay(1500);
}
void UI(){ // Giao diện của Hệ thống
  if(flag == 0 and digitalRead(MODE) == 0){
    if(Rb >= 2){lcd.clear(); Rb = 0; Mode();}
    else
    {
      lcd.clear(); Rb++; Mode();
    }
    delay(250);
  }
    
  if(digitalRead(START) == 0) {flag = 1; delay(250); lcd.clear();}
}

void Mode(){ // Hiển thị giao diện mode
  if(Rb == 0){
    lcd.setCursor(6,0);
    lcd.print("MODE");
    lcd.setCursor(0,1);
    lcd.print(">Chicken Egg");
  }
  if(Rb == 1){
    lcd.setCursor(0,0);
    lcd.print(">Duck Egg");
    lcd.setCursor(0,1);
    lcd.print(" Pheasant Egg");
  }
 if(Rb == 2){
    lcd.setCursor(0,0);
    lcd.print(" Duck Egg");
    lcd.setCursor(0,1);
    lcd.print(">Pheasant Egg");
    }
}

void Run(){
  while(flag == 1 and Rb == 0){ // Chicken
    Blynk.run();
    lcd.setCursor(3,0);
    lcd.print("Chicken Egg");
    lcd.setCursor(0,1);
    lcd.print("T:");
    lcd.print(dht.readTemperature());
    lcd.print("  H:");
    lcd.print(dht.readHumidity());
    Temp_Sun(37);
    Temp_Night(36);
    Humi(75);
    if(digitalRead(Stop)  == 0) {Reset_Device(); flag = 0; Rb = 0; delay(250); lcd.clear(); Mode(); return loop();}
  }
 while(flag == 1 and Rb == 1){ // Duck
    Blynk.run();
    lcd.setCursor(4,0);
    lcd.print("Duck Egg");
    lcd.setCursor(0,1);
    lcd.print("T:");
    lcd.print(dht.readTemperature());
    lcd.print("  H:");
    lcd.print(dht.readHumidity());
    Temp_Sun(37);
    Temp_Night(37);
    Humi(65);
    if(digitalRead(Stop)  == 0) {Reset_Device(); flag = 0; Rb = 0; delay(250); lcd.clear(); Mode(); return loop();}
  }
 while(flag == 1 and Rb == 2){ // Pheasant
    Blynk.run();
    lcd.setCursor(2,0);
    lcd.print("Pheasant Egg");
    lcd.setCursor(0,1);
    lcd.print("T:");
    lcd.print(dht.readTemperature());
    lcd.print("  H:");
    lcd.print(dht.readHumidity());
    Temp_Sun(36);
    Temp_Night(36);
    Humi(65);
    if(digitalRead(Stop)  == 0) {Reset_Device(); flag = 0; Rb = 0; delay(250); lcd.clear(); Mode(); return loop();}
  }
}
