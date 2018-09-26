#ifndef _WeStepperMotor_H
#define _WeStepperMotor_H

#include "WePort.h"

class WeStepperMotor
{
public:

  WeStepperMotor(uint8_t port=0); 
  void reset(uint8_t port=0);
  void setMicroStep(uint8_t value);
  void setSpeed(uint8_t speed);
  void moveTo(int16_t value);
  void move(int16_t value);
  void stop();
private:
	WeOneWire _WeStepperMotor;
	int16_t  last_move=0;
	int16_t  moveto=0;
};

#endif

