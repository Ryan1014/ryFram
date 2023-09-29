#include "Arduino.h"
#include "ryFRAM.h"
#include <Wire.h>

void i2cStart(){
    Wire.begin();
    //SWire.begin(); //use for software I2C
}

ryFRAM::ryFRAM(byte address){
_address = address;

}

/*****FRAM Functions*****/
void ryFRAM::writeByte(int location, byte data){
  //Serial.println("Writing byte");
  Wire.beginTransmission(_address);
  Wire.write(highByte (location));   // mem location highByte
  Wire.write(lowByte (location));    // mem location lowbyte
  Wire.write(data);                 // write 1 byte of data
  Wire.endTransmission();
}

void ryFRAM::writeInt(int location, int data){
  //Serial.println("Writing int");
  Wire.beginTransmission(_address);
  Wire.write(highByte (location));   // mem location highByte
  Wire.write(lowByte (location));    // mem location lowbyte
  Wire.write(highByte (data));      // write high byte of data
  Wire.write(lowByte (data));       // write low byte of data
  Wire.endTransmission();
}

void ryFRAM::writeLong(int location, unsigned long input){
  //Serial.println("Writing long");
  byte bytes[4];
  
  for (int i = 0; i < 4; i++) {     // Extract the individual bytes
    bytes[i] = (input >> (i * 8)) & 0xFF;
  }

  Wire.beginTransmission(_address);
  Wire.write(highByte (location));   // mem location highByte
  Wire.write(lowByte (location));    // mem location lowbyte

  for (int i = 0; i < 4; i++) {     // write the 4 extraced bytes of data
    Wire.write(bytes[i]);
  }
  Wire.endTransmission();
}

byte ryFRAM::readByte(int location) {
  //Serial.println("Reading 1 byte ");
  byte data = 0;
  // send memory location we want to read from
  Wire.beginTransmission(_address);      
  Wire.write(highByte (location));   // mem location highByte
  Wire.write(lowByte (location));    // mem location lowbyte
  Wire.endTransmission();
  // Read the data
  Wire.beginTransmission(_address);
  Wire.requestFrom(_address, 1, true);
  Wire.endTransmission();

  while (Wire.available()) {
    data = Wire.read();  // Receive a byte
  }
  return data;
}


int ryFRAM::readInt(int location) {
  //Serial.println("Reading 2 bytes ");
  int result = 0;
  byte byte0, byte1;
  // send memory location we want to start reading from
  Wire.beginTransmission(_address);     
  Wire.write(highByte (location));   // mem location highByte
  Wire.write(lowByte (location));    // mem location lowbyte
  Wire.endTransmission();

  Wire.beginTransmission(_address);     // Request the data
  Wire.requestFrom(_address, 2);
  Wire.endTransmission();

  while (Wire.available()) {
    byte1 = Wire.read();
    byte0 = Wire.read();
  }

  result |= (int)byte0 << 0;
  result |= (int)byte1 << 8;

  return result;
}


unsigned long ryFRAM::readLong(int location) {
  //Serial.println("Reading 4 bytes ");
unsigned long result = 0;
  int i = 0;
  //uint8_t byte0, byte1, byte2, byte3;
  byte bytes[4];
  // send memory location we want to start reading from
  Wire.beginTransmission(_address);     
  Wire.write(highByte (location));   // mem location highByte
  Wire.write(lowByte (location));    // mem location lowbyte
  Wire.endTransmission();
  // Read the data
  Wire.beginTransmission(_address);
  Wire.requestFrom(_address, 4);
  Wire.endTransmission();

  while (Wire.available()) {
    bytes[i] = Wire.read();
    i++;
  }
  result |= (unsigned long)bytes[0] << 0;
  result |= (unsigned long)bytes[1] << 8;
  result |= (unsigned long)bytes[2] << 16;
  result |= (unsigned long)bytes[3] << 24;

  return result;
}