#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <Arduino.h>

/*==GLOBAL SERIAL SHUT DEFINE BEGIN==*/
#define GLOBAL_OUTPUT 0
#if GLOBAL_OUTPUT

#define PRINT(x) Serial.print(x)
#define PRINTLN(x) Serial.println(x)

#else

#define PRINT(x)
#define PRINTLN(x)

#endif
/*==GLOBAL SERIAL SHUT DEFINE END==*/

/*==UTILITY DEFINES BEGIN==*/
#define MAX_ANALOG_VALUE static_cast<int32_t>(1023)
#define HALF(x)  ((x) / 2)
/*==UITILITY DEFINES END==*/

/*==FREQUENCY DISCRETIZATION BEGIN==*/
#define Ts_us 10000 // 0 < Ts_us <= 10000
#define Ts_s (Ts_us / 1000000.0)
/*==FREQUENCY DISCRETIZATION END==*/

/*==ENCODER CONNECTION PINS BEGIN==*/
#define LEFT_CLK_A_PIN 2
#define LEFT_B_PIN 4
#define LEFT_ENC_DIR -1

#define RIGHT_CLK_A_PIN 3
#define RIGHT_B_PIN 5
#define RIGHT_ENC_DIR 1
/*==ENCODER CONNECTION PINS END==*/

/*==ROBOT PARAMS BEGIN==*/
#define ROBOT_WIDTH 0.077f
#define WHEEL_RADIUS 0.0173f
/*==ROBOT PARAMS END*/

/*==WHEELS PARAMS BEGIN==*/
#define ENC_PPR 48
#define GEAR_RATIO 30
#define TICK2RAD (2.f * M_PI / (ENC_PPR * GEAR_RATIO))
/*==WHEELS PARAMS END==*/

/*==MOTOR PINS BEGIN==*/
#define LEFT_MOTOR_DIR 7
#define LEFT_MOTOR_PWM (PIN_A1)
#define LEFT_MOTOR_POLARITY 1

#define RIGHT_MOTOR_DIR 8
#define RIGHT_MOTOR_PWM (PIN_A0)
#define RIGHT_MOTOR_POLARITY 0
/*==MOTOR PINS END==*/

/*==FUNCTIONAL SELECTOR BEGIN==*/
#define INDICATOR_LED_PIN (6)
#define FUNCTION_PIN A6
/*==FUNCTIONAL SELECTOR END==*/

/*==BUTTONS PIN BEGIN==*/
#define BUTTON_1_PIN (28)
#define BUTTON_2_PIN (27)
#define BUTTON_3_PIN (26)
#define BUTTON_4_PIN (25)
/*==BUTTONS PIN END==*/

/*==W MOTOT PIREG BEGIN==*/
#define W_K_MOTOR (6 / 1.5) //он выдаёт примерно 6.5 рад/с на 1.5 Волта
#define W_T_MOTOR 0.15
#define W_T_u (2 * Ts_s)

#define W_KP (0.4f) // Kp = K
#define W_KI (W_KP / 0.05f) // Ki = K / T
/*==W MOTOT PIREG END==*/

/*==MAZE BEGIN==*/
// MY MAZE STRUCT
// for exapmle, let's take maze 3x3:
//        X - a x i s 
//      Y      === === ===
//      |     | 0 | 1 | 2 |
//      a  === === === ===
//      x | 3 | 4 | 5 | 6 |
//      i  === === === ===
//      s | 7 | 8 | 9 | 10|
//         === === === ===
//        | 11| 12| 13| 14|
//         === === === ===
// here 0, 1, 2, 3, 7, 11 cells are utility. important for west and north fronts of maze
// total number of cells are 15, but informal numbers of cells are 9 (3x3)

#define MAZE_SIDE_LENGTH 11

#define MAZE_SIDE_LENGTH_ADD_ONE (MAZE_SIDE_LENGTH + 1)
#define MAZE_TOTAL_SIZE (MAZE_SIDE_LENGTH * 2 + MAZE_SIDE_LENGTH * MAZE_SIDE_LENGTH)
#define MAZE_MEM_SIZE (((MAZE_SIDE_LENGTH + MAZE_SIDE_LENGTH) + MAZE_SIDE_LENGTH * MAZE_SIDE_LENGTH))

#define MAZE_PATH_SIZE ((MAZE_TOTAL_SIZE - (MAZE_TOTAL_SIZE % 2)))
/*==MAZE END==*/

/*==QUEUE BEGIN==*/
#define MAX_SIZE_QUEUE (MAZE_SIDE_LENGTH * 4)
/*==QUEUE END*/


/*==ROBOT START PLACE BEGIN==*/
#define START_ROBOT_COORDS {0, 0}
/*==ROBOT START PLACE END==*/


/*==ROBOT FINISH PLACE BEGIN==*/
#define FINISH_ROBOT_COORDS_X (2)
#define FINISH_ROBOT_COORDS_Y (2)

#define FINISH_ROBOT_COORDS {FINISH_ROBOT_COORDS_X, FINISH_ROBOT_COORDS_Y}
/*==ROBOT FINISH PLACE END==*/

/*==CHECK TEST'S CORRECT OUTPUT BEGIN==*/
/*
---[ IN TEST CYCLOGRAMS: 
    \--Primitive:
        | BLANK FORWARD LEFT RIGHT STOP 
    \--Smarts: 
        | IDLE FWD1 SS90SL SS90SR STOP
    ]
---[ IN TEST BFS PATH EQUAL:
    \--| S E N E E E E S S W W S E S E S
    ]
---[ IN TEST CONVERT_PATH_TO_CYCLOGRAM:
    \--|
    IP180 FWD_HALF SS90EL SS90EL SS90ER FWD1 FWD1 FWD1 SS90ER FWD1 SS90ER FWD1 SS90EL SS90EL SS90ER SS90EL SS90ER FWD_HALF STOP
    ]
*/
/*==CHECK TEST'S CORRECT OUTPUT END==*/

/*==OPTOCOUPLER BEGIN==*/
#define OPTOCOUPLER_PIN_DIAG_RIGHT (A10) // выбор пинов связан с удобством разводки
#define OPTOCOUPLER_PIN_FWD_RIGHT (A11)
#define OPTOCOUPLER_PIN_FWD_LEFT (A12)
#define OPTOCOUPLER_PIN_DIAG_LEFT (A13)

#define OPTOCOUPLER_EMITERS_A (A14) // Emitters_back
#define OPTOCOUPLER_EMITERS_B (A15) // Emitters_fwd
/*==OPTOCOUPLER END==*/

/*==BATTERY BEGIN==*/
#define BATTERY_PIN (A7)
/*==BATTERY END==*/

/*==GYRO BEGIN==*/
#define USE_GYRO true // выбор ехать по жнкодерам или гироскопу
/*==GYRO END==*/

#endif // !_CONFIG_H_