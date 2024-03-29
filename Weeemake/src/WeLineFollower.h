
#ifndef WeLineFollower_H
#define WeLineFollower_H

#include "WePort.h"

class WeLineFollower
{
public:

  WeLineFollower(uint8_t port=0);
  void reset(uint8_t port=0);

  void startRead(void);
  uint8_t readSensor1(void);
  uint8_t readSensor2(void);


  
private:
	WeOneWire _WeLineFollower;
    volatile uint8_t  _Sensor1;
    volatile uint8_t  _Sensor2;
};

#endif

