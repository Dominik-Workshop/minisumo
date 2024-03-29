/**
 * @file vl53l0_init.c
 * @author Dominik
 * @brief
 * @version 0.1
 * @date 2023-05-3
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "vl53l0_init.h"

/**
 * @brief Initializes all six TOF VL53L0X distance sensors
 *
 */
void TOF_VL53L0X_init_all(){
  TOF1.vl53l0x_c.I2cHandle = &hi2c1;
  TOF2.vl53l0x_c.I2cHandle = &hi2c1;
  TOF3.vl53l0x_c.I2cHandle = &hi2c1;
  TOF4.vl53l0x_c.I2cHandle = &hi2c3;
  TOF5.vl53l0x_c.I2cHandle = &hi2c3;
  TOF6.vl53l0x_c.I2cHandle = &hi2c3;

  TOF1.vl53l0x_c.I2cDevAddr = 0x52;
  TOF2.vl53l0x_c.I2cDevAddr = 0x52;
  TOF3.vl53l0x_c.I2cDevAddr = 0x52;
  TOF4.vl53l0x_c.I2cDevAddr = 0x52;
  TOF5.vl53l0x_c.I2cDevAddr = 0x52;
  TOF6.vl53l0x_c.I2cDevAddr = 0x52;

  HAL_GPIO_WritePin(TOF_X1_GPIO_Port, TOF_X1_Pin, GPIO_PIN_RESET); // Disable XSHUT
  HAL_GPIO_WritePin(TOF_X2_GPIO_Port, TOF_X2_Pin, GPIO_PIN_RESET); // Disable XSHUT
  HAL_GPIO_WritePin(TOF_X3_GPIO_Port, TOF_X3_Pin, GPIO_PIN_RESET); // Disable XSHUT
  HAL_GPIO_WritePin(TOF_X4_GPIO_Port, TOF_X4_Pin, GPIO_PIN_RESET); // Disable XSHUT
  HAL_GPIO_WritePin(TOF_X5_GPIO_Port, TOF_X5_Pin, GPIO_PIN_RESET); // Disable XSHUT
  HAL_GPIO_WritePin(TOF_X6_GPIO_Port, TOF_X6_Pin, GPIO_PIN_RESET); // Disable XSHUT
  HAL_Delay(20);

  /*
  HAL_GPIO_WritePin(TOF_X1_GPIO_Port, TOF_X1_Pin, GPIO_PIN_SET); // Enable XSHUT
  TOF_VL53L0X_measurement_setup(&TOF1.vl53l0x_c, &VhvSettings , &PhaseCal, &refSpadCount, &isApertureSpads);
  VL53L0X_SetDeviceAddress(&(TOF1.vl53l0x_c), 0x72);
  TOF1.vl53l0x_c.I2cDevAddr = 0x72;
  HAL_Delay(20);
  */
  HAL_GPIO_WritePin(TOF_X2_GPIO_Port, TOF_X2_Pin, GPIO_PIN_SET); // Enable XSHUT
  TOF_VL53L0X_measurement_setup(&TOF2.vl53l0x_c, &VhvSettings , &PhaseCal, &refSpadCount, &isApertureSpads);
  VL53L0X_SetDeviceAddress(&(TOF2.vl53l0x_c), 0x62);
  TOF2.vl53l0x_c.I2cDevAddr = 0x62;
  HAL_Delay(20);

  HAL_GPIO_WritePin(TOF_X3_GPIO_Port, TOF_X3_Pin, GPIO_PIN_SET); // Enable XSHUT
  TOF_VL53L0X_measurement_setup(&TOF3.vl53l0x_c, &VhvSettings , &PhaseCal, &refSpadCount, &isApertureSpads);

  HAL_GPIO_WritePin(TOF_X4_GPIO_Port, TOF_X4_Pin, GPIO_PIN_SET); // Enable XSHUT
  TOF_VL53L0X_measurement_setup(&TOF4.vl53l0x_c, &VhvSettings , &PhaseCal, &refSpadCount, &isApertureSpads);
  VL53L0X_SetDeviceAddress(&(TOF4.vl53l0x_c), 0x72);
  TOF4.vl53l0x_c.I2cDevAddr = 0x72;
  HAL_Delay(20);

  HAL_GPIO_WritePin(TOF_X5_GPIO_Port, TOF_X5_Pin, GPIO_PIN_SET); // Enable XSHUT
  TOF_VL53L0X_measurement_setup(&TOF5.vl53l0x_c, &VhvSettings , &PhaseCal, &refSpadCount, &isApertureSpads);
  VL53L0X_SetDeviceAddress(&(TOF5.vl53l0x_c), 0x62);
  TOF5.vl53l0x_c.I2cDevAddr = 0x62;
  HAL_Delay(20);

  /*
  HAL_GPIO_WritePin(TOF_X6_GPIO_Port, TOF_X6_Pin, GPIO_PIN_SET); // Enable XSHUT
  TOF_VL53L0X_measurement_setup(&TOF6.vl53l0x_c, &VhvSettings , &PhaseCal, &refSpadCount, &isApertureSpads);
  */
}

/**
 * @brief
 *
 * @param Dev
 * @param pVhvSettings
 * @param pPhaseCal
 * @param refSpadCount
 * @param isApertureSpads
 */
void TOF_VL53L0X_measurement_setup(VL53L0X_Dev_t * Dev, uint8_t *pVhvSettings, uint8_t *pPhaseCal, uint32_t *refSpadCount, uint8_t *isApertureSpads){
  //
  // VL53L0X init for Single Measurement
  //
  VL53L0X_WaitDeviceBooted(Dev);
  VL53L0X_DataInit(Dev);
  VL53L0X_StaticInit(Dev);
  VL53L0X_PerformRefCalibration(Dev, pVhvSettings, pPhaseCal);
  VL53L0X_PerformRefSpadManagement(Dev, refSpadCount, isApertureSpads);
  VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING);

  //
  // Enable/Disable Sigma and Signal check
  //
  //VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1);
  //VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1);
  //VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, (FixPoint1616_t)(0.1*65536));
  //VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, (FixPoint1616_t)(60*65536));
  VL53L0X_SetMeasurementTimingBudgetMicroSeconds(Dev, 20000);
  //VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_PRE_RANGE, 18);
  //VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_FINAL_RANGE, 14);

  VL53L0X_StartMeasurement(Dev);
 }
