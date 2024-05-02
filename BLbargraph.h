#ifndef BLbargraph_h
  #define BLbargraph_h

  #if (ARDUINO >= 100)
    #include "Arduino.h"
  #else
    #include "WProgram.h"
  #endif

#include <Wire.h>

#define BB_DISPLAY_OFF 0x00

#define BB_DISPLAY_ON  0x01

#define BG_SIZE       28

class BargraphLED
  {
    public:
      void init(uint8_t addr);
      
      void setBrightness(uint8_t brightness);
       
      void setPixel(uint8_t row, uint8_t col, uint8_t onff);
      
      void clear(void);

      void write(void);
	  

      void setSegment(uint8_t pos, uint8_t value);
      
      uint8_t size(void);
	        
    private:
      uint16_t *_buffer;
      uint8_t  _i2c_addr;
      
      void writeRow(uint8_t col);
  };

#endif
