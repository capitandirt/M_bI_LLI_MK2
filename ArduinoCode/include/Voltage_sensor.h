#ifndef VOLTAGE_SENSOR_H_
#define VOLTAGE_SENSOR_H_

#include <Arduino.h>

class Voltage_sensor
{
    private:
        int _pin;
        
    public:
        Voltage_sensor(int pin);
        float get();
        void init();
};

#endif // VOLTAGE_SENSOR_H_