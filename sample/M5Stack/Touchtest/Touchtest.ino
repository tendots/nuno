#include <M5Stack.h>
#include "MTCH6102.h"
#define ADDR 0x25
#define ScreenWidth 320
#define ScreenHeight 240

MTCH6102 mtch = MTCH6102();
int len = 8;

void setup() { 

  // Initialize the M5Stack object
  M5.begin();
  //Wire.begin();
  M5.Power.begin();

 
  
  //Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.println("start");
  
  //Wire.begin();
  mtch.begin();
  mtch.writeRegister(MTCH6102_MODE, MTCH6102_MODE_STANDBY);
  mtch.writeRegister(MTCH6102_NUMBEROFXCHANNELS, 0x08);
  mtch.writeRegister(MTCH6102_NUMBEROFYCHANNELS, 0x03);//最低3点必要なため
  mtch.writeRegister(MTCH6102_MODE, MTCH6102_MODE_FULL);
  
  byte data;

  // the operating mode (MODE)
  data = mtch.readRegister(MTCH6102_MODE);
  Serial.print("MODE: ");
  Serial.println(data,BIN);

  data = mtch.readRegister(MTCH6102_NUMBEROFXCHANNELS);
  Serial.print("NUMBEROFXCHANNELS: ");
  Serial.println(data);

  data = mtch.readRegister(MTCH6102_NUMBEROFYCHANNELS);
  Serial.print("NUMBEROFYCHANNELS: ");
  Serial.println(data);
  
  mtch.writeRegister(MTCH6102_CMD, 0x20);
  delay(500);

  
}

void loop() {
  M5.Lcd.setCursor(0, 70);
  
  byte data; 
  float sensVals[10]={0,0,0,0,0,0,0,0,0,0};

  //背景ライン
  for(int i=0; i<len; i++){
    M5.Lcd.drawLine((i+1)*35, ScreenHeight-40, (i+1)*35, 0, 0x0000cc);
  }
  for(int i=1; i<11; i++){
    M5.Lcd.drawLine(0, i*20, ScreenWidth, i*20, 0x0000cc);
  }

  Serial.print("SENSORVALUE_RX <i>: ");
  //for (byte i = MTCH6102_SENSORVALUE_RX0; i < MTCH6102_SENSORVALUE_RX0+10; i++) {
  for (int i = 0; i < len; i++) {
     data = mtch.readRegister(MTCH6102_SENSORVALUE_RX0+(i+2));
     
    Serial.print(data);
    Serial.print(", ");

    sensVals[i] = data;

    M5.Lcd.fillRect(30+(i*35), ScreenHeight-20, 30, 10, TFT_BLACK);
    M5.Lcd.setCursor(30+(i*35), ScreenHeight-20);
    M5.Lcd.print(data);
  }

  //グラフ線の描画
  int leftMargin = 0;
  for (int i = 0; i<len+1; i++){
    float prev;
    float current;
    if(i==0){
       prev = 0;
    }if(i==len+1){
      current = 0;
    }else{
       prev=sensVals[i-1];
       current = sensVals[i];
    }
    
    M5.Lcd.drawLine(leftMargin+(i*35), 200-(prev/255)*200, leftMargin+((i+1)*35), 200-(current/255)*200, TFT_WHITE);
  }
  delay(50);
  

  
  //グラフ線の消去
  for (int i = 0; i<len+1; i++){
    float prev;
    float current;
    if(i==0){
       prev = 0;
    }if(i==len+1){
      current = 0;
    }else{
       prev=sensVals[i-1];
       current = sensVals[i];
    }
    M5.Lcd.drawLine(leftMargin+(i*35), 200-(prev/255)*200, leftMargin+((i+1)*35), 200-(current/255)*200, TFT_BLACK);
  }
   
  Serial.println();
  M5.Lcd.println();
  M5.update();
  
 }
