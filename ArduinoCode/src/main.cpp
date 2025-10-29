#include <Arduino.h>
#include "argviz_driver.h"
#include "Config.h"
#include "Globals.h"


void setup() {
  Serial.begin(115200);
  motorsInit();
  voltage_sensor.init();

  argviz_init(Serial);
  argviz_registerScreen(0, screen0);
  argviz_start();
}

void loop() {
  static uint32_t timer = micros();
  while(micros() - timer < Ts_us);
  timer = micros();

  Left_motor.drive(voltage_input);
  Right_motor.drive(voltage_input);
}
