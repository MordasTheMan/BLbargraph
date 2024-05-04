#include "BGanim.h"
#include "BLbargraph.h"
BG bargraph = BG();

void BGanimation::BGinit()
{
  BG.init(0x70);
  delay(1000);
  BG.setBrightness(15);
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
}
