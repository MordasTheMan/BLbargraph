#include "BGanim.h"
#include "BLbargraph.h"
BG bargraph = BG();

void BGanim::BBinit()
{
  BG.init(0x70);
  delay(1000);
  BG.setBrightness(15);
}

void BGanim::changeInterval(uint8_t NewInterval)
{
  IntervalBG = NewInterval;
}

void BGanim::seqIdle1(unsigned long currentMillis)
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
