

#include "MTCH6102.h"

MTCH6102::MTCH6102() {}

boolean MTCH6102::begin(uint8_t i2caddr) {
  Wire.begin();

  _i2caddr = i2caddr;

  return true;
}

uint8_t MTCH6102::readRegister(uint8_t reg) {
  Wire.beginTransmission(_i2caddr);
  Wire.write(reg); // register to read
  Wire.endTransmission(false);
  // read a byte
  //delayMicroseconds(10);
  //delayいれたがendTransmission()にfalse入れたほうが応答いい
  while (Wire.requestFrom(_i2caddr, 1) != 1);
  return ( Wire.read());
}

void MTCH6102::writeRegister(uint8_t reg, uint8_t value) {
  Wire.beginTransmission(_i2caddr);
  Wire.write((uint8_t)reg); // register to read
  Wire.write((uint8_t)(value));
  Wire.endTransmission();
}
