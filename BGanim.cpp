#include "BGanim.h"
#include "BLbargraph.h"
BG bargraph = BG();

void BGanimation::BGanimate()
{
  bargraph.init(0x70);
  delay(1000);
  bargraph.setBrightness(15);
}

void BGanimation::changeInterval(uint8_t NewInterval)
{
  IntervalBG = NewInterval;
}

void BGanimation::seqIdle1(unsigned long currentMillis)
{
  if ((currentMillis - lastUpdateBG) > IntervalBG)
  {
    lastUpdateBG = currentMillis;
    for (int i = 0; i <= 27; i++)
    {
      if (i == IndexSegment )
        {
          drawBarGraph(barGraph[i][0], barGraph[i][1], 1);
        }
    }
  }
  BG.write
}

void BGanimation::drawBarGraph( uint8_t row, uint8_t col, uint8_t val )
{
  bargraph.setPixel(row, col, val);
}
