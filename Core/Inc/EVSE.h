/*
 * EVSE.h
 *
 *  Created on: Apr 15, 2022
 *      Author: Martin
 *      Brief:  Simple control of AC EV charger
 *
 */

#ifndef INC_EVSE_H_
#define INC_EVSE_H_

#include "main.h"

#define EVSE_MAX_CURRENT	16

#define EVSE_PWM_TIM_CHANNEL	TIM_CHANNEL_2

#define EVSE_CPV_NOCAR_MV	 		10000   // voltage thresholds on CP pin
#define EVSE_CPV_CAR_DETECT_MV	 	8000   // voltage thresholds on CP pin
#define EVSE_CPV_CAR_READY_MV	 	5000   // voltage thresholds on CP pin
#define EVSE_CPV_CAR_VENT_MV	 	2000   // voltage thresholds on CP pin

typedef enum
{
	evsInit,
	evsNoCarDetected,
	evsCarFull,
	evsCharging,
	evsNoFreePower,
	evsDisabled,
	evsError
}eEvseState;


void EVSE_Init(void);

void EVSE_Update_100ms(void);

uint16_t EVSE_GetActualCurrent(void);
uint16_t EVSE_GetActualPower(void);
eEvseState EVSE_GetStatus(void);
void EVSE_SetCurrentLimit(uint16_t charging_current);
uint16_t EVSE_GetCurrentLimit(void);
uint16_t EVSE_GetThisCons(void);



#endif /* INC_EVSE_H_ */
