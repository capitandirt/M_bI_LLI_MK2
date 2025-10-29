#ifndef ARGVIZ_DRIVER_H
#define ARGVIZ_DRIVER_H

#include <Arduino.h>
#include <argviz.h>
#include "Globals.h"

float voltage_input = 0;

SCREEN(screen0,
       {
         ROW("counter [us]: %lu", micros());
         ROW("counter [ms]: %lu", millis());
         CLICK_ROW([](CLICK_STATE state)
                   {
        switch(state)
        {
        case CLICK_LEFT:
            voltage_input += 0.1;
            break;
        case CLICK_RIGHT:
            voltage_input -= 0.1;
            break;
        case CLICK_DOWN:
            voltage_input = 0;
            break;
        default:
            break;
        } }, "vin: %d", int(voltage_input*1000));

         ROW("HINT:")
         ROW("battery: %3d", int(voltage_sensor.get()*1000))
       })


#endif // ARGVIZ_DRIVER_H