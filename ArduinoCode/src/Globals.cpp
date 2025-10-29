#include "Globals.h"

Voltage_sensor voltage_sensor(BATTERY_PIN);

Motor Left_motor(LEFT_MOTOR_DIR, LEFT_MOTOR_PWM, LEFT_MOTOR_POLARITY, &voltage_sensor);
Motor Right_motor(RIGHT_MOTOR_DIR, RIGHT_MOTOR_PWM, RIGHT_MOTOR_POLARITY, &voltage_sensor);

void motorsInit()
{
    pinMode(LEFT_MOTOR_DIR, OUTPUT);
    pinMode(RIGHT_MOTOR_DIR, OUTPUT);
    pinMode(LEFT_MOTOR_PWM, OUTPUT);
    pinMode(RIGHT_MOTOR_PWM, OUTPUT);
}