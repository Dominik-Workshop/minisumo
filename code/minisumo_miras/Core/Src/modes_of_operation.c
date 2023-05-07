/**
 * @file modes_of_operation.c
 * @author Dominik
 * @brief
 * @version 0.1
 * @date 2023-05-7
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "modes_of_operation.h"

void debug_screen(){
	while(HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin) == 0){
		if(HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin)){
			  servo_set_eangle(0);
			  HAL_GPIO_WritePin(user_LED_GPIO_Port, user_LED_Pin, GPIO_PIN_SET);
		}
		else{
		  servo_set_eangle(180);
		  HAL_GPIO_WritePin(user_LED_GPIO_Port, user_LED_Pin, GPIO_PIN_RESET);
		}

		if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin))
			HAL_GPIO_WritePin(LS_ON_GPIO_Port, LS_ON_Pin, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(LS_ON_GPIO_Port, LS_ON_Pin, GPIO_PIN_RESET);

		battery.adc_reading = values_adc[0];
		display_fill(DISPLAY_COLOR_BLACK);
		display_printf(50, 0, DISPLAY_COLOR_WHITE, display_font_6x8, "%.2fV", calculateBatteryVoltage(& battery));
		display_printf(0, 0, DISPLAY_COLOR_WHITE, display_font_6x8, "%d", (int) values_adc[1]);
		display_printf(104, 00, DISPLAY_COLOR_WHITE, display_font_6x8, "%d", (int) values_adc[2]);
		display_printf(54, 56, DISPLAY_COLOR_WHITE, display_font_6x8, "%d", (int) values_adc[3]);

		VL53L0X_PerformSingleRangingMeasurement(&(TOF3.vl53l0x_c), &(TOF3.RangingData));
		if(TOF3.RangingData.RangeStatus == 0){
			display_printf(32, 20, DISPLAY_COLOR_WHITE, display_font_6x8, "%i", TOF3.RangingData.RangeMilliMeter);
		}

		VL53L0X_PerformSingleRangingMeasurement(&(TOF4.vl53l0x_c), &(TOF4.RangingData));
		if(TOF4.RangingData.RangeStatus == 0){
				display_printf(72, 20, DISPLAY_COLOR_WHITE, display_font_6x8, "%i", TOF4.RangingData.RangeMilliMeter);
		}

		display_render();
	}
}

void fight(){
	display_fill(DISPLAY_COLOR_BLACK);
	display_bitmap(0, 0, DISPLAY_COLOR_WHITE, bitmap_konar_vertical_128_64, 128, 64);
	display_render();
	while(HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin) == 1){
		motor_L_set_direction(FORWARD);
		motor_R_set_direction(FORWARD);
		motor_L_set_speed(50);
		motor_R_set_speed(50);

		VL53L0X_PerformSingleRangingMeasurement(&(TOF3.vl53l0x_c), &(TOF3.RangingData));
		if(TOF3.RangingData.RangeStatus == 0){
			if(TOF3.RangingData.RangeMilliMeter < 200)
				HAL_GPIO_WritePin(user_LED_GPIO_Port, user_LED_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(user_LED_GPIO_Port, user_LED_Pin, GPIO_PIN_RESET);
		}

	}
}
