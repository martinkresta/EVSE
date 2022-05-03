/*
 * EVSE.c
 *
 *  Created on: Apr 15, 2022
 *      Author: Martin
 *      Brief:  Simple control of AC EV charger
 *
 */
#include "EVSE.h"
#include "ADC.h"
#include "main.h"
#include "APP.h"
#include "di.h"

uint16_t mLimitCurrent_A;
uint16_t mThisCharge_Wh;
uint16_t mActualCurrent_A;
uint16_t mActualPower_W;
eEvseState mState;
uint8_t mRelayState;

static void SetCurrent(uint16_t amps);


static TIM_OC_InitTypeDef sConfigOC;

void EVSE_Init(void)
{
	mState = evsInit;
	mLimitCurrent_A = 10;
	mActualCurrent_A = 0;

	// prepare structure for configuring OC channels
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;



	ADC_StartConversion();

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

	EVSE_SetCurrentLimit(mLimitCurrent_A);  // 10Amp default
	mRelayState = 0;
}

void EVSE_Update_100ms(void)
{
	uint16_t adc_raw;
	double adcpin_mV;
	double pilotVoltage_mV;
	// detect car on control pilot pin

	adc_raw = ADC_GetValue(0);
	adcpin_mV = (ADC_VREF_MV/4096.0 * adc_raw);  // convert to milivolts
	pilotVoltage_mV = adcpin_mV * 6.05;  // voltage divider 12k + 56k
	ADC_StartConversion();

	if (mState == evsDisabled)
	{
		mRelayState = 0;
	}
	else
	{
		if(pilotVoltage_mV > EVSE_CPV_NOCAR_MV)
		{
			mState = evsNoCarDetected;
			mRelayState = 0;
		}
		else if (pilotVoltage_mV > EVSE_CPV_CAR_DETECT_MV)
		{
			mState = evsCarFull;
			mRelayState = 0;
		}
		else if (pilotVoltage_mV > EVSE_CPV_CAR_READY_MV)
		{
			mState = evsCharging;
			if (mRelayState == 0)
			{
				mRelayState = 1;
				mThisCharge_Wh = 0;
				ELM_ResetConsumption(ELM_EVSE);
			}

		}
		else if (pilotVoltage_mV > EVSE_CPV_CAR_VENT_MV)
		{
			mState = evsCharging;
			if (mRelayState == 0)
			{
				mRelayState = 1;
				mThisCharge_Wh = 0;
				ELM_ResetConsumption(ELM_EVSE);
			}
		}
		else
		{
			mState = evsError;
			mRelayState = 0;
		}
	}



	// control relay

	if (mRelayState)
	{
		HAL_GPIO_WritePin(AC_RELAY_GPIO_Port, AC_RELAY_Pin, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(AC_RELAY_GPIO_Port, AC_RELAY_Pin, GPIO_PIN_RESET);
	}

	// control the PWM output

	// measure actual charging current using standard elmeter
	mThisCharge_Wh = ELM_GetConsumptionWh(ELM_EVSE);
	mActualPower_W = ELM_GetPowerW(ELM_EVSE);

	// process buttons

	if (DI_Get(UP) == eDI_LO)
	{
		EVSE_SetCurrentLimit(EVSE_GetCurrentLimit() + 1);
	}
	if (DI_Get(DOWN) == eDI_LO)
	{
		EVSE_SetCurrentLimit(EVSE_GetCurrentLimit() - 1);
	}

	if (DI_Get(ENTER) == eDI_LO)
	{
		if (mState != evsDisabled)
		{
			mState = evsDisabled;
		}
		else
		{
			mState = evsInit;
		}
	}


}



uint16_t EVSE_GetActualCurrent(void)
{
	return mActualCurrent_A;
}

eEvseState EVSE_GetStatus(void)
{
	return mState;
}

void EVSE_SetCurrentLimit(uint16_t chargingCurrent)
{
	if (chargingCurrent <= EVSE_MAX_CURRENT)
	{
		mLimitCurrent_A = chargingCurrent;
	}
	else
	{
		mLimitCurrent_A = EVSE_MAX_CURRENT;
	}
	if (chargingCurrent < 6)
	{
		mLimitCurrent_A = 6;
	}
	SetCurrent(mLimitCurrent_A);
}

uint16_t EVSE_GetActualPower(void)
{
	return mActualPower_W;
}

uint16_t EVSE_GetCurrentLimit(void)
{
	return mLimitCurrent_A;
}

uint16_t EVSE_GetThisCons(void)
{
	return mThisCharge_Wh;
}


static void SetCurrent(uint16_t amps)
{
	// safety range check
	if (amps < 6)
	{
		amps = 6;
	}
	if (amps > EVSE_MAX_CURRENT)
	{
		amps = EVSE_MAX_CURRENT;
	}
	// calculate pulse lengt in us
	uint16_t pulse = (amps * 100) / 6;

	sConfigOC.Pulse = pulse;

	HAL_TIM_PWM_Stop(&htim1, EVSE_PWM_TIM_CHANNEL); // we have to stop here

	if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, EVSE_PWM_TIM_CHANNEL) != HAL_OK)  // because this fcn will stop it in register CCER - CCxE
	{
		Error_Handler();
	}
	HAL_TIM_PWM_Start(&htim1, EVSE_PWM_TIM_CHANNEL);  // and this fcn is then not able to start  (HAL HELL ! )


}
