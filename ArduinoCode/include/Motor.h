#ifndef MOTOR_H_
#define MOTOR_H_

#include <Arduino.h>
#include "Config.h"
#include "Voltage_sensor.h"

class Motor
{
    private:
        uint8_t DIR_pin, PWM_pin;
        Voltage_sensor* _voltage_sensor;
        int _polarity   ;
        
    public:
        Motor(int DIR_pin, int8_t PWM_pin, int polarity, Voltage_sensor* voltage_sensor);
        void drive(float voltage);
};

#endif // MOTOR_H_