
#ifndef WeHumiture_H
#define WeHumiture_H

#include "WePort.h"

class WeHumiture
{
public:

  WeHumiture(uint8_t port=0);
  void reset(uint8_t port=0);

  void startRead(void);
  uint16_t getHumidity(void);
  uint16_t getTemperature(void);


  
private:
	WeOneWire _WeHumiture;
    volatile uint8_t  _humidity,_temperature;
};

#endif

