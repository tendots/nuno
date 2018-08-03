#include <M5Stack.h>


#include <Arduino.h>
#include <Wire.h>
#include "MTCH6102.h"

#define ADDR 0x25

MTCH6102 mtch = MTCH6102();
int len = 8;

void setup() {
 delay(1000);
 
 byte data;

  // Initialize the M5Stack object
  M5.begin();
  M5.Lcd.fillScreen(TFT_BLACK);

   //I2c.begin();
  
  Serial.begin(115200);
  
  //Wire.begin();
  mtch.begin();
  mtch.writeRegister(MTCH6102_MODE, MTCH6102_MODE_STANDBY);
  mtch.writeRegister(MTCH6102_NUMBEROFXCHANNELS, 0x10 );
  mtch.writeRegister(MTCH6102_NUMBEROFYCHANNELS, 0x03);//最低3点必要なため
  mtch.writeRegister(MTCH6102_MODE, MTCH6102_MODE_FULL);
  
  mtch.writeRegister(MTCH6102_CMD, 0x20);
  delay(500);
  
  // the operating mode (MODE)
  data = mtch.readRegister(MTCH6102_MODE);
  Serial.print("MODE: ");
  Serial.println(data,BIN);

  // Set mode to Touch only
  //mtch.writeRegister(MTCH6102_MODE, 0x02);


  data = mtch.readRegister(MTCH6102_MODE);
  Serial.print("MODE: ");
  Serial.println(data,BIN);

  data = mtch.readRegister(MTCH6102_NUMBEROFXCHANNELS);
  Serial.print("NUMBEROFXCHANNELS: ");
  Serial.println(data);

  data = mtch.readRegister(MTCH6102_NUMBEROFYCHANNELS);
  Serial.print("NUMBEROFYCHANNELS: ");
  Serial.println(data);


  data = mtch.readRegister(MTCH6102_NUMBEROFXCHANNELS);
  Serial.print("NUMBEROFXCHANNELS: ");
  Serial.println(data);

 data = mtch.readRegister(MTCH6102_NUMBEROFYCHANNELS);
  Serial.print("NUMBEROFYCHANNELS: ");
  Serial.println(data);
  
}

void loop() {
//M5.lcd.clear();
M5.Lcd.setCursor(0, 70);
  
  byte data; 
  float sensVals[10]={0,0,0,0,0,0,0,0,0,0};

  Serial.print("SENSORVALUE_RX <i>: ");
  //for (byte i = MTCH6102_SENSORVALUE_RX0; i < MTCH6102_SENSORVALUE_RX0+10; i++) {
  for (int i = 0; i < len; i++) {
     data = mtch.readRegister(MTCH6102_SENSORVALUE_RX0+i);
     
    //Serial.print(data);
    //Serial.print(", ");

    sensVals[i] = data;
    M5.Lcd.print(data);
    M5.Lcd.print(", ");
  }
  
  for (int i = 0; i<len; i++){
    float prev;
    if(i==0){
       prev = 0;
    }else{
       prev=sensVals[i-1];
    }
    M5.Lcd.drawLine(i*30, 240-(prev/255)*240, (i+1)*30, 240-(sensVals[i]/255)*240, TFT_WHITE);
  }
  delay(100);
  
  for (int i = 0; i<len; i++){
    float prev;
    if(i==0){
       prev = 0;
    }else{
       prev=sensVals[i-1];
    }
    M5.Lcd.drawLine(i*30, 240-(prev/255)*240, (i+1)*30, 240-(sensVals[i]/255)*240, TFT_BLACK);
  }

   
  Serial.println();
  M5.Lcd.println();
  
  //delay(100);
  }
  

