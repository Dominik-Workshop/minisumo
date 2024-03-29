/**
 * @file modes_of_operation.h
 * @author Dominik
 * @brief
 * @version 0.1
 * @date 2023-05-7
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MODES_OF_OPERATION_H
#define MODES_OF_OPERATION_H

#include "display.h"
#include "sprites.h"
#include "battery.h"
#include "motors.h"
#include "vl53l0_init.h"
#include "sensors.h"

extern Battery battery;
extern uint32_t values_adc[4];

extern TOF_VL53L0X TOF1;
extern TOF_VL53L0X TOF2;
extern TOF_VL53L0X TOF3;
extern TOF_VL53L0X TOF4;
extern TOF_VL53L0X TOF5;
extern TOF_VL53L0X TOF6;

extern uint32_t refSpadCount;
extern uint8_t isApertureSpads;
extern uint8_t VhvSettings;
extern uint8_t PhaseCal;

void wait_for_fight_start();
void fight();
void debug_screen();
void check_line();

#endif
