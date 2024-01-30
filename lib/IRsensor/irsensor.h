#ifndef _IRSENSOR_H_
#define _IRSENSOR_H_

#include <Arduino.h>

#define PIN_SENSE       2
#define ISR_DEBOUNCE    100  

class c_IR_sensor
{
public:
    c_IR_sensor();
    void init();

    bool isTrigd();
    void trig(bool state);

    uint32_t getLast();
    void now();

private:
    uint32_t last_interrupt = 0;
    bool trigd = false;
};

void IR_ISR();

extern c_IR_sensor IR_sensor;

#endif