#ifndef ryFRAM_h
#define ryFRAM_h
#include "Arduino.h" 
class ryFRAM {
public:
  ryFRAM(byte address);
  /*****FRAM prototypes*****/

void writeByte(int location, byte data);            // Writes a single Byte to the specified memory location

void writeInt(int location, int data);              // Writes an unsigned int to the specified memory location

void writeLong(int location, unsigned long input);  // Writes an unsigned long to the specified memory location

byte readByte(int location);                        //Reads a single byte from the specified memory location

int readInt(int location);                          //Reads an unsigned int from the specified memory location

unsigned long readLong(int location);               //Reads an unsigned long from the specified memory location

private:
 byte _address;

};


#endif



