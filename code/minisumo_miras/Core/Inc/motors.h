/**
 * @file motors.h
 * @author Dominik
 * @brief
 * @version 0.1
 * @date 2023-05-6
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MOTORS_H
#define MOTORS_H

#include "stdint.h"
#include "main.h"

#define MIN_PULSE_SERVO 560		//μs, 0 degree
#define MAX_PULSE_SERVO 2540	//μs, 180 degree
#define STEP (1000 * (MAX_PULSE_SERVO - MIN_PULSE_SERVO) / 180)

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

typedef enum{
	FORWARD,
	BACKWARD
}motor_direction;

void motor_L_set_speed(uint8_t speed);
void motor_R_set_speed(uint8_t speed);
void motor_L_set_direction(motor_direction direction);
void motor_R_set_direction(motor_direction direction);
void servo_set_eangle(uint8_t eangle);

#endif
