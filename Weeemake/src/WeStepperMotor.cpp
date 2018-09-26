#include "WeStepperMotor.h"

WeStepperMotor::WeStepperMotor(uint8_t port)
{
    _WeStepperMotor.reset(port);	
}
void WeStepperMotor::reset(uint8_t port)
{
	_WeStepperMotor.reset(port);	
}

void WeStepperMotor::setMicroStep(uint8_t value)
{
     if(_WeStepperMotor.reset()!=0)
	   return;
	 _WeStepperMotor.write_byte(0x02);
     if(_WeStepperMotor.reset()!=0)
	   return;
     _WeStepperMotor.write_byte(value);
}
void WeStepperMotor::setSpeed(uint8_t speed)
{
    if(speed>255)  speed=255;
	if(_WeStepperMotor.reset()!=0)
	   return;
	_WeStepperMotor.write_byte(0x03);
	if(_WeStepperMotor.reset()!=0)
	   return;
	_WeStepperMotor.write_byte((uint8_t)speed);
}
void WeStepperMotor::moveTo(int16_t value)
{
    moveto=value-last_move;
	if(moveto>16000)  moveto=16000;
	else if(moveto<-16000)  moveto=-16000;
	if(_WeStepperMotor.reset()!=0)
	   return;
	_WeStepperMotor.write_byte(0x04);
	if(_WeStepperMotor.reset()!=0)
	   return;
	_WeStepperMotor.write_byte((uint8_t)moveto);
	_WeStepperMotor.write_byte((uint8_t)(moveto>>8));
	last_move=value;
}

void WeStepperMotor::move(int16_t value)
{ 
    if(value>16000)  value=16000;
	else if(value<-16000) value=-16000;
	if(_WeStepperMotor.reset()!=0)
	   return;
	_WeStepperMotor.write_byte(0x04);
	if(_WeStepperMotor.reset()!=0)
	   return;
	_WeStepperMotor.write_byte((uint8_t)value);
	_WeStepperMotor.write_byte((uint8_t)(value>>8));
	last_move=last_move+value;
}
void WeStepperMotor::stop()
{  
	if(_WeStepperMotor.reset()!=0)
	   return;
	_WeStepperMotor.write_byte(0x05);	
}





