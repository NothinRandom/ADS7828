#ifndef ADS7828_h
#define ADS7828_h

#if (ARDUINO >= 100)
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Wire.h"

#define ADS_DEBUG 1 	

class ADS7828
{
	public:
		ADS7828(byte address);
		int read(byte channel);
	private:
		int _address;
		int _value;
		byte _channel [8];
};

#endif