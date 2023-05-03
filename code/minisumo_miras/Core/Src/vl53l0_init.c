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
 * @brief
 *
 * @param Dev
 * @param pVhvSettings
 * @param pPhaseCal
 * @param refSpadCount
 * @param isApertureSpads
 */
void tof_vl53l0_init(VL53L0X_Dev_t * Dev, uint8_t *pVhvSettings, uint8_t *pPhaseCal, uint32_t *refSpadCount, uint8_t *isApertureSpads){
  //
  // VL53L0X init for Single Measurement
  //
  VL53L0X_WaitDeviceBooted(Dev);
  VL53L0X_DataInit(Dev);
  VL53L0X_StaticInit(Dev);
  VL53L0X_PerformRefCalibration(Dev, pVhvSettings, pPhaseCal);
  VL53L0X_PerformRefSpadManagement(Dev, refSpadCount, isApertureSpads);
  VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_SINGLE_RANGING);
  //
  // Enable/Disable Sigma and Signal check
  //
  VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1);
  VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1);
  VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, (FixPoint1616_t)(0.1*65536));
  VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, (FixPoint1616_t)(60*65536));
  VL53L0X_SetMeasurementTimingBudgetMicroSeconds(Dev, 33000);
  VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_PRE_RANGE, 18);
  VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_FINAL_RANGE, 14);

}
