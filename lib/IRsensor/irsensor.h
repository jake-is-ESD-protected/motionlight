#ifndef _IRSENSOR_H_
#define _IRSENSOR_H_

#include <Arduino.h>
#include "STM32FreeRTOS.h"

#define PIN_SENSE       PA8
#define ISR_DEBOUNCE    100  

class c_IR_sensor
{
public:
    c_IR_sensor();
    void init();
    uint32_t getLast();
    void now();

private:
    uint32_t last_interrupt = 0;
};

void irISR();

extern c_IR_sensor IR_sensor;
extern TaskHandle_t h_mainLoop;

#endif