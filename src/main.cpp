#include <Arduino.h>
#include "hardware.h"
#include "irsensor.h"

void setup() 
{
  Serial.begin(115200);
  IR_sensor.init();
  strip.init();
}

void loop() 
{
  if(IR_sensor.isTrigd())
  {
    if(strip.on)
    {
      strip.dim(DOWN, strip.warm_white);
    }
    else
    {
      strip.dim(UP, strip.warm_white);
    }
    IR_sensor.trig(false);
  }
}