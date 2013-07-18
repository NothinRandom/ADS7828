#include "ADS7828.h"

ADS7828::ADS7828(byte address)
{
	_address = 0x48 | address; //0x48|0 = 0x48; 
							   //0x48|1 = 0x49; 
							   //0x48|2 = 0x4A; 
							   //0x48|3 = 0x4B;
	_channel[0] = 0x8C;
	_channel[1] = 0xCC;
	_channel[2] = 0x9C;
	_channel[3] = 0xDC;
	_channel[4] = 0xAC;
	_channel[5] = 0xEC;
	_channel[6] = 0xBC;
	_channel[7] = 0xFC;
	Wire.begin();
};

int ADS7828::read(byte channel)
{
	if(channel > 7 || channel < 0) 
		return -3; //out of range

  	//Send command byte
  	Wire.beginTransmission(_address);
  	Wire.write(_channel[channel]);
  	Wire.endTransmission();
  
  	// Receive ADC value
  	Wire.requestFrom(_address, 2);
  	
  	//Convert byte pair to int
  	if (Wire.available())
  	{
  		_value = 0; //reset value back to 0
    		_value += Wire.read() << 8; //grab high byte
    		if (Wire.available())
      			_value += Wire.read(); //grab low byte
   		else
      			return -1; //low byte not available
  	}
  	else
    	return -2; //IC not detected
  	return _value;
};
