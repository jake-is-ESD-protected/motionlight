#include "irsensor.h"

c_IR_sensor IR_sensor;

static uint32_t last_isr = 0;

void IR_ISR()
{
    uint32_t irt = millis();
    if(irt - last_isr > ISR_DEBOUNCE)
    {
        IR_sensor.now();
        IR_sensor.trig(true);
    }
    last_isr = irt;
}

c_IR_sensor::c_IR_sensor()
{

}

void c_IR_sensor::init()
{
    pinMode(PIN_SENSE, INPUT);
    attachInterrupt(digitalPinToInterrupt(PIN_SENSE), IR_ISR, RISING);
}

bool c_IR_sensor::isTrigd()
{
    return trigd;
}

void c_IR_sensor::trig(bool state)
{
    trigd = state;
}

uint32_t c_IR_sensor::getLast()
{
    return last_interrupt;
}

void c_IR_sensor::now()
{
    last_interrupt = millis();
}