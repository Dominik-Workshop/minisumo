#ifndef SENSORS_H
#define SENSORS_H

//#include "modes_of_operation.h"

typedef enum{
	DETECTED_TOF1,
	DETECTED_TOF2,
	DETECTED_TOF3,
	DETECTED_TOF4,
	DETECTED_TOF5,
	DETECTED_TOF6,
	DETECTED_KTIR1,
	DETECTED_KTIR2,
	DETECTED_KTIR3
}sensors_detected;

typedef enum{
	KTIR_FRONT_LEFT = 1,
	KTIR_FRONT_RIGHT,
	KTIR_BACK
}KTIR_sensors;

#endif
