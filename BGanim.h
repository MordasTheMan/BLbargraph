#ifndef BGanim
#define BGanim

#if (ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

const uint8_t barGraph[28][2]  = {
  {0, 0},
  {0, 1},
  {0, 2},
  {0, 3},
  {1, 0},
  {1, 1},
  {1, 2},
  {1, 3},
  {2, 0},
  {2, 1},
  {2, 2},
  {2, 3},
  {3, 0},
  {3, 1},
  {3, 2},
  {3, 3},
  {4, 0},
  {4, 1},
  {4, 2},
  {4, 3},
  {5, 0},
  {5, 1},
  {5, 2},
  {5, 3},
  {6, 0},
  {6, 1},
  {6, 2},
  {6, 3},
};

class BGanimation  {
  public:

    void BGanime();
        enum  direction { FORWARD, REVERSE };
        direction DirectionBG ;

    void BGanimate();

    void initiate(uint8_t BGMODE);
    void changeInterval(uint8_t NewInterval);
    void seqBGFireFan(unsigned long currentMillis);
    void seqBGFireVent(unsigned long currentMillis);
    void seqBGFireTVG(unsigned long currentMillis);
    void seqBGVentTVG(unsigned long currentMillis);
    void seqIdle1(unsigned long currentMillis);
    void seqIdleAL(unsigned long currentMillis);
    void seqVent(unsigned long currentMillis);
    void clearLEDs();
    void seqShutdown(unsigned long currentMillis);
    void drawBarGraph( uint8_t row, uint8_t col, uint8_t val );

    int IndexSegment;
    unsigned long  IntervalBG = 50;
    unsigned long  IntervalVENT = 2500;
    bool startVent = true;
    unsigned long  lastUpdateBG; //= 0; // last update of position
    unsigned long  lastUpdateVENT;

  private:
    bool _DirectionChange = false;
};
#endif
