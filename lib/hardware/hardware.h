#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include <Arduino.h>

#define PIN_R           5
#define PIN_G           9
#define PIN_B           6

#define WARM_WHITE      255, 120, 20

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


class c_color
{
public:
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = 0;
    c_color(uint8_t _red=0, uint8_t _green=0, uint8_t _blue=0);
private:
};


class c_strip
{
public:
    c_strip() : warm_white(WARM_WHITE) {}
    void init();
    void light(c_color color);
    void off();
    void dim(uint8_t direction, c_color color);

    const c_color warm_white{WARM_WHITE};

    bool on = false;

private:
    c_led r;
    c_led g;
    c_led b;

};

extern c_strip strip;

#endif