/**
 * @file vl53l0_init.h
 * @author Dominik
 * @brief
 * @version 0.1
 * @date 2023-05-3
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef VL53L0_HH
#define VL53L0_HH

#include "vl53l0x_api.h"
#include "main.h"

typedef struct{
	VL53L0X_RangingMeasurementData_t RangingData;
	VL53L0X_Dev_t  vl53l0x_c; // center module
	//VL53L0X_DEV    Dev;
}TOF_VL53L0X;

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

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;
extern I2C_HandleTypeDef hi2c3;

void TOF_VL53L0X_init_all();
void TOF_VL53L0X_measurement_setup(VL53L0X_DEV Dev, uint8_t *pVhvSettings, uint8_t *pPhaseCal, uint32_t *refSpadCount, uint8_t *isApertureSpads);

#endif
