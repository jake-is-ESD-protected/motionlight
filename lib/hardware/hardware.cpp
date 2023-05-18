#include "hardware.h"

c_strip strip;

c_led::c_led()
{

}

void c_led::init(uint8_t _pin)
{
    pinMode(_pin, OUTPUT);
    analogWrite(_pin, 0);
    pin = _pin;
}

void c_led::level(uint8_t level)
{
    analogWrite(pin, level);
}


c_color::c_color(uint8_t _red, uint8_t _green, uint8_t _blue)
{
    red = _red;
    green = _green;
    blue = _blue;
}


void c_strip::init()
{
    r.init(PIN_R);
    g.init(PIN_G);
    b.init(PIN_B);
}

void c_strip::light(c_color color)
{
    on = true;
    r.level(color.red);
    g.level(color.green);
    b.level(color.blue);
}

void c_strip::off()
{
    on = false;
    r.level(0);
    g.level(0);
    b.level(0);
}

void c_strip::dim(uint8_t direction, c_color color)
{
    uint8_t r_step_size;
    uint8_t g_step_size;
    uint8_t b_step_size;

    if(color.red == 0)
    {
        r_step_size = 0;
    }
    else
    {
        r_step_size = (uint8_t)(1 / (((float)color.red) / MAX_PWM));
    }

    if(color.green == 0)
    {
        g_step_size = 0;
    }
    else
    {
        g_step_size = (uint8_t)(1 / (((float)color.green) / MAX_PWM));
    }

    if(color.blue == 0)
    {
        b_step_size = 0;
    }
    else
    {
        b_step_size = (uint8_t)(1 / (((float)color.blue) / MAX_PWM));
    }

    if(direction == UP)
    {
        strip.off();
        for(uint8_t i = 0; i < MAX_PWM; i++)
        {
            if(r_step_size != 0) r.level((uint8_t)(((float)i) / r_step_size));
            if(g_step_size != 0) g.level((uint8_t)(((float)i) / g_step_size));
            if(b_step_size != 0) b.level((uint8_t)(((float)i) / b_step_size));
            delay(_DIM_TIME);
        }
        strip.light(color);
    }
    else
    {
        strip.light(color);
        for(uint8_t i = MAX_PWM; i > 0; i--)
        {
            if(r_step_size != 0) r.level((uint8_t)(((float)i) / r_step_size));
            if(g_step_size != 0) g.level((uint8_t)(((float)i) / g_step_size));
            if(b_step_size != 0) b.level((uint8_t)(((float)i) / b_step_size));
            delay(_DIM_TIME);
        }
        strip.off();
    }
    
}
