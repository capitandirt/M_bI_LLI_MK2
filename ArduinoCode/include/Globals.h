#ifndef GLOBALS_H_
#define GLOBALS_H_

#include "Config.h"
#include "Voltage_sensor.h"
#include "Motor.h"

extern Voltage_sensor voltage_sensor;

extern Motor Left_motor;
extern Motor Right_motor;
void motorsInit();

#endif // GLOBALS_H_