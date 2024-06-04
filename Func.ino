void Temp_Sun(int A){ // Nhiệt độ mặt trời
 if(analogRead(Light) < 3000){
  if(dht.readTemperature() > A) {
    digitalWrite(Fan1,1);
  }

  if(dht.readTemperature() < A) {
    digitalWrite(Fan1,0);
  }
 }
}

void Temp_Night(int A){ // Nhiệt độ trời tối
 if(analogRead(Light) > 3000){
  if(dht.readTemperature() > A) {
    digitalWrite(Fan1,0);
    digitalWrite(UP_TEMP, 0);
  }

  if(dht.readTemperature() < A) {
    digitalWrite(Fan1,0);
    digitalWrite(UP_TEMP, 1);
  }
 }
}

void Humi(int A){
  if(dht.readHumidity() < A){
    digitalWrite(Fan2,0);
  }
  if(dht.readHumidity() > A){
    digitalWrite(Fan2,1);
  }
}

void Reset_Device(){
  digitalWrite(Fan1,0);
  digitalWrite(Fan2,0);
  digitalWrite(UP_TEMP,0);
}

void Push_Data(){
  if(millis() - TIme >= 1000){
    String A = String(dht.readTemperature()) + "x" + String(dht.readHumidity()) + "x";
    Blynk.virtualWrite(V0, A);
    TIme = millis();
  }
}
