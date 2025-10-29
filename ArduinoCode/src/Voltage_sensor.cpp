#include "Voltage_sensor.h"

Voltage_sensor::Voltage_sensor(int pin)
{
    this->_pin = pin;
}

float Voltage_sensor::get()
{
    return analogRead(_pin);
}

void Voltage_sensor::init()
{
    pinMode(_pin, INPUT);
}