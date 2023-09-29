#include <Wire.h>
#include <ryFRAM.h>

ryFRAM fram(0x50); //0x50 is the default Device address

void setup() {
  Serial.begin(115200);
  
  Serial.println("HELLO FRAM");
  Wire.begin();
byte singleByte = 242;
unsigned int singleInt = 42000;
long largeValue = 123456789;


fram.writeByte(0x50, singleByte); // Write a single Byte to the memory location 0x50

fram.writeInt(0x60, singleInt); // Write an unsigned int to the memory locations 0x60 and 0x61

fram.writeLong(0x70, largeValue);  // Write an unsigned long to the  memory locations 0x70 through 0x73

byte dataAt_x50 = fram.readByte(0x50); //Read a single byte from memory location 0x50

unsigned int dataAt_x60_61 = fram.readInt(0x60); //Read an int from the memory locations 0x60 and 0x61

unsigned long dataAt_x70_73 = fram.readLong(0x70); //Read an unsigned long from the memory locations 0x70 through 0x73

Serial.print("Here is the data stored at memory location 0x50: "); Serial.println(dataAt_x50);
Serial.print("Here is the data stored at memory location 0x60: "); Serial.println(dataAt_x60_61);
Serial.print("Here is the data stored at memory location 0x70: "); Serial.println(dataAt_x70_73);

}

void loop() {

}
