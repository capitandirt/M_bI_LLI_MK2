#include <Arduino.h>
#include <argviz.h>

/**
Set

```
monitor_raw = true
monitor_speed = 115200
```

in platformio.ini to get proper output
 */

uint8_t counter = 0;

SCREEN(screen0,
       {
         ROW("counter [us]: %lu", micros());
         ROW("counter [ms]: %lu", millis());
         CLICK_ROW([](CLICK_STATE state)
                   {
        switch(state)
        {
        case CLICK_LEFT:
            counter--;
            break;
        case CLICK_RIGHT:
            counter++;
            break;
        case CLICK_DOWN:
            counter = 0;
            break;
        default:
            break;
        } }, "click me (h|l|space): %3u", counter);

         ROW("HINT:")
         ROW("control with hjkl+space")
       })

SCREEN(screen1,
       ROW("This is screen 1");)

SCREEN(screen2,
       {
         ROW("This is screen 2");
       })

SCREEN(screen3,
       {
         static int zero_idx = 0;
         CLICK_ROW([](CLICK_STATE state)
                   {
    switch(state)
    {
    case CLICK_LEFT:
      zero_idx = (zero_idx + 5 - 1) % 5;
      break;
    case CLICK_RIGHT:
      zero_idx = (zero_idx + 1) % 5;
      break;
    case CLICK_DOWN:
      zero_idx = 0;
      break;
    default:
      break;
    } }, "screens[%d:%d]", zero_idx, zero_idx + 5);

         for (int i = zero_idx; i < zero_idx + 5; i++)
           ROW("screens[%d] = %p", i, __screens[i]);
       })

void setup()
{
  Serial.begin(115200);

  argviz_init(Serial);
  argviz_registerScreen(0, screen0);
  argviz_registerScreen(1, screen1);
  argviz_registerScreen(2, screen2);
  argviz_registerScreen(3, screen3);
  argviz_start();
}

void loop()
{
  static uint32_t timer = 0;
  while (micros() - timer < 500)
    ;
  timer = micros();
}
