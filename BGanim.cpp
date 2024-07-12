#include "BGanim.h"
#include "BLbargraph.h"
BG bargraph = BG();

void BGanimation::initiate(uint8_t BGMODE)
{
  switch (BGMODE)
    {
      case 0:  //movie idle
      IndexSegment = 0;
      lastUpdateBG = 0;
      IntervalBG = 60;
      DirectionBG = FORWARD;
      break;
    case 1:    //fan idle
      IndexSegment = 0;
      lastUpdateBG = 0;
      IntervalBG = 60;
      DirectionBG = FORWARD;
      break;
    case 2:     //fan fire
      IndexSegment = 0;
      lastUpdateBG = 0;
      IntervalBG = 50;
      DirectionBG = FORWARD;
      break;
    case 3:      //TVG fire
      IndexSegment = 0;
      lastUpdateBG = 0;
      IntervalBG = 50;
      DirectionBG = FORWARD;
      break;
    case 4:       //Vent
      IndexSegment = 0;
      lastUpdateBG = 0;
      IntervalBG = 100;
      DirectionBG = FORWARD;
      break;
    }
}

void BGanimation::BGanimate()
{
  bargraph.init(0x70);
  delay(1000);
  bargraph.setBrightness(10);
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
    if (DirectionBG == FORWARD)
    {
      for (int i = 0; i <= 27; i++)
      {
        if (i == IndexSegment )
        {
          drawBarGraph(barGraph[i][0], barGraph[i][1], 1);
        }
      }
    }
    else
    {
      for (int i = 0; i <= 27; i++)
      {
        if (i == IndexSegment )
        {
          drawBarGraph(barGraph[i + 1][0], barGraph[i + 1][1], 0);
        }
      }
    }
    if (IndexSegment == 27)
    {
      DirectionBG = REVERSE;
    }
    if (IndexSegment == 0)
    {
      DirectionBG = FORWARD;
    }
    if (DirectionBG == FORWARD)
    {
      IndexSegment++;
    }
    else
    {
      IndexSegment--;
    }
  }
 bargraph.write();
}

void BGanimation::drawBarGraph( uint8_t row, uint8_t col, uint8_t val )
{
  bargraph.setPixel(row, col, val);
  bargraph.write();
}
