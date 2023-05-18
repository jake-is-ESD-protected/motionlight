#include <Arduino.h>
#include "hardware.h"
#include "irsensor.h"
#include "STM32FreeRTOS.h"

TaskHandle_t h_mainLoop = NULL;

void mainLoop(void* p){

}

void setup() 
{
  IR_sensor.init();
  strip.init();
  xTaskCreate(mainLoop, "main loop", 256, NULL, 1, &h_mainLoop);
}

void loop() 
{
  ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

}