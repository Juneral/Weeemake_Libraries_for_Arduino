#include "WeELF328P.h"

WeMP3 mp3(PORT_A);

void setup()
{  
  mp3.appointVolume(18);  //Volume 0~30 
  mp3.appointDevice(4);   //2-TF; 4-FLASH
  mp3.appointMusic(2);   //0~3000
}
void loop() 
{
	mp3.appointVolume(18);  //Volume 0~30 
  if(mp3.isOver()==1)
  {
     mp3.nextMusic();
  }
  //mp3.pause(); 
  //delay(2000);
  //mp3.play();
}
