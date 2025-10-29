#include "Motor.h"


Motor::Motor(int DIR_pin, int8_t PWM_pin, int polarity, Voltage_sensor* voltage_sensor)
{
    this->DIR_pin = DIR_pin;
    this->PWM_pin = PWM_pin;
    this->_polarity = polarity;
    this->_voltage_sensor = voltage_sensor;
}

void Motor::drive(float voltage)
{
    int analog_value = (voltage / _voltage_sensor->get()) * MAX_ANALOG_WRITE_VALUE * _polarity;
    if (analog_value)
    {
        digitalWrite(DIR_pin, LOW);
        analogWrite(PWM_pin, analog_value);
    }
    else
    {
        digitalWrite(DIR_pin, HIGH);
        analogWrite(PWM_pin, MAX_ANALOG_WRITE_VALUE - abs(analog_value));
    }
}