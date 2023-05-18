#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include <Arduino.h>

#define PIN_LED         PA12

#define DOWN            0
#define UP              1

#define MAX_PWM         255
#define DIM_TIME        2
#define _DIM_TIME       (uint16_t)((1000 * (float)DIM_TIME) / (MAX_PWM))


class c_led
{
public:
    c_led();
    void init(uint8_t _pin);
    void level(uint8_t level);

    uint8_t pin = 0;
    
private:
    
};


class c_strip
{
public:
    c_strip();
    void init();
    void light();
    void off();
    void dim(uint8_t direction);

    bool on = false;

private:
    c_led led;
};

extern c_strip strip;

#endif