#include "WeELF328P.h"

WeTemperature wetemp(PORT_3);

void setup()
{  
  Serial.begin(9600);
}
void loop() 
{
  Serial.print("Temperature=");
  Serial.println(wetemp.temperature() );
  delay(100);
}
