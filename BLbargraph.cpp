#include <Wire.h>
#include "BLbargraph.h"

void BG::init(uint8_t addr)
{  
  // set the I2C address
  _i2c_addr = addr;
  
  _buffer = (uint16_t*)calloc(8, sizeof(uint16_t));
  
  Wire.begin();
  Wire.beginTransmission(_i2c_addr);
  Wire.write(0x21); 
  Wire.write(BB_CMD_SETUP | BB_DISPLAY_ON); 
  Wire.endTransmission();
  
  setBrightness(15);
  write();
}

void BG::setBrightness(uint8_t brightness)
{
  brightness = brightness & 0x0F;
  
  Wire.beginTransmission(_i2c_addr);
  Wire.write(BB_CMD_DIMMING | brightness);
  Wire.endTransmission();
}

void BG::clear(void)
{  
  for (uint8_t i = 0; i < 8; i++)
  {
    _buffer[i] = 0;
  }  
}

void BG::setPixel(uint8_t col, uint8_t row, uint8_t val)
{
  // bounds checking
  col = col & 0x07;
  row = row & 0x0F;
  val = val & 0x01;
  
  // write the buffer
  if (val == 1)
  {
    _buffer[col] |= 1 << row;
  }
  else
  {
    _buffer[col] &= ~(1 << row);
  }

}

void BG::setRow(uint8_t row, uint16_t value)
{

  row = row & 0x07;
  
  // write it
  _buffer[row] = value;
}

void BG::setColumn(uint8_t col, uint8_t value)
{

  for (uint8_t row = 0; row < 8; row++)
  {
    setPixel(col, row, (value & (1 << row)) > 0);
  }
}

void BG::write(void)
{
  Wire.beginTransmission(_i2c_addr);
  Wire.write(BB_CMD_RAM);
  
  for (uint8_t col = 0; col < 8; col++)
  {
    writeRow(col);
  }
  
  Wire.endTransmission();
}

void BG::setSegment(uint8_t pos, uint8_t val)
{
  uint8_t row, col;
  
  val &= 0x01;	//constrain val to be either 0 or 1
  
  // verify the position isn't greater than the bargraph size
  if(pos > (BG_SIZE - 1) ) pos = BG_SIZE - 1;
  
  row = pos / 4;
  col = pos % 4;
	
  setPixel(col, row, val);
}

uint8_t BG::size(void)
{
  return BG_SIZE;
}

void BG::writeRow(uint8_t row)
{
    uint16_t out = _buffer[row];
    Wire.write(out & 0xFF); // first byte
    Wire.write(out >> 8); // second byte
  }
