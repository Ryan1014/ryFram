# ryFram
FRAM library for the fujtisu MB85RC64

There are many FRAM Arduino libraries out there, but for some reason the board I was trying to program kept freezing up when I was using them. I tried 3 different libraries including the adafruit library and then finally gave up and wrote my own. Not sure if it will help anyone else, but I figured I would make it public just in case. 

It's quite simple and has only basic functionality.
writeByte(int location, byte data); // Writes a single byte to the specified memory location

writeInt(int location, int data); // Writes an unsigned int to the specified memory location

writeLong(int location, unsigned long data); // Writes an unsigned long to the specified memory location

readByte(int location); //reads a single byte from the specified memory location

readInt(int location); //reads an unsigned int from the specified memory location

readLong(int location); //reads an unsigned long from the specified memory location

When creating an instance of the ryFram Class you should include the device address like so.

ryFRAM fram(0x50); //0x50 is the default Device address
