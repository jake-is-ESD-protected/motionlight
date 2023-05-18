#include "hardware.h"
#include "STM32FreeRTOS.h"

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

void c_strip::init()
{
    led.init(PIN_LED);
}

void c_strip::light()
{
    on = true;
    led.level(MAX_PWM);
}

void c_strip::off()
{
    on = false;
    led.level(0);
}

void c_strip::dim(uint8_t direction)
{
    if(direction == UP){
        for(uint8_t i = 0; i < MAX_PWM; i++){
            led.level(i);
            vTaskDelay(_DIM_TIME / portTICK_PERIOD_MS);
        }
    }
    else{
        for(uint8_t i = MAX_PWM; i > 0; i--){
            led.level(i);
            vTaskDelay(_DIM_TIME / portTICK_PERIOD_MS);
        }
    }
}
