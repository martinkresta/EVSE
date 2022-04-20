/*
 * APP.c
 *
 *  Created on: Aug 14, 2021
 *      Author: Martin
 *      Brief:  Main application and compile time configuration
 *
 */

#include "RTC.h"
#include "UI.h"
#include "main.h"
#include "APP.h"
#include "scheduler.h"
#include "COM.h"
#include "ELM.h"
#include "ADC.h"
#include "watchdog.h"
#include "ST7066U.h"
#include "VARS.h"
#include "EVSE.h"



static void ProcessMessage(s_CanRxMsg* msg);


// public methods
void APP_Init(void)
{

	sUIHwInit uihw;

	Scheduler_Init();

	VAR_Init();
	MCAN_Init(&hcan1, THIS_NODE);
    COM_Init(THIS_NODE);
  	WDG_Init(3000);
  	ELM_Init(NUM_OF_ELEMTERS);
  	ADC_Init(&hadc1, &hdma_adc1, 1);



	/*Assign pins for onboard UI  */
	uihw.Led_Life.Pin = LED_Life_Pin;
	uihw.Led_Life.Port = LED_Life_GPIO_Port;
	uihw.Led_Life.Logic = eUIL_POSITIVE;

	uihw.Led_R.Pin = LED_Error_Pin;
	uihw.Led_R.Port = LED_Error_GPIO_Port;
	uihw.Led_R.Logic = eUIL_NEGATIVE;

	/*uihw.Led_R.Pin = LED_Error_Pin;
	uihw.Led_R.Port = LED_Error_GPIO_Port;
	uihw.Led_R.Logic = eUIL_NEGATIVE;

	uihw.Led_G.Pin = LED_Error_Pin;
	uihw.Led_G.Port = LED_Error_GPIO_Port;
	uihw.Led_G.Logic = eUIL_NEGATIVE;

	uihw.Led_B.Pin = LED_Error_Pin;
	uihw.Led_B.Port = LED_Error_GPIO_Port;
	uihw.Led_B.Logic = eUIL_NEGATIVE;

	uihw.Buzzer.Pin = LED_Error_Pin;
	uihw.Buzzer.Port = LED_Error_GPIO_Port;
	uihw.Buzzer.Logic = eUIL_NEGATIVE;*/


	UI_Init(&uihw);
	UI_LED_Life_SetMode(eUI_BLINKING_SLOW);



	/* Configure CAN streamed variables */


	/*configure elmeters*/

	ELM_AddMeter(ELM_EVSE, ELM1_Pin, VAR_CONS_EVSE_WH);

}

void APP_Start(void)
{

	UI_LED_R_SetMode(eUI_OFF);

	MCAN_Start();

	LCD_Init();
	LCD_Show_String("  UHA-EVSE 1.0  ", 0);
	LCD_Show_String("****************", 1);

	EVSE_Init();

	while (1)   // endless loop
	{
		Scheduler_Check_Flag();

		// Process received COM messages

		s_CanRxMsg rmsg;
		while(1 == COM_GetRxMessage(&rmsg))  // process all messages in buffer
		{
				ProcessMessage(&rmsg);
		}

	}

}

void APP_Update_1s(void)
{
	// check midnight
	char row[16];
	static uint8_t dayNumber = 0;
	uint8_t newDayNumber = 0;
	newDayNumber = RTC_GetTime().Day;
	if (dayNumber != newDayNumber)
	{
		dayNumber = newDayNumber;

		// TBD
	}



	switch(EVSE_GetStatus())
	{
	case evsInit:
		LCD_Show_String("  UHA-EVSE 1.0  ", 0);
		LCD_Show_String("****************", 1);
		break;
	case evsNoCarDetected:
		LCD_Show_String("No Vehicle	     ", 0);
		sprintf(row,"Limit: %dA ",EVSE_GetCurrentLimit());
		LCD_Show_String(row, 1);
		break;
	case evsCarFull:
		LCD_Show_String("Vehicle charged ", 0);
		sprintf(row,"Limit: %dA ",EVSE_GetCurrentLimit());
		LCD_Show_String(row, 1);
		break;
	case evsCharging:
		sprintf(row,"Charging: %dW",EVSE_GetCurrentLimit());
		LCD_Show_String(row, 0);
		sprintf(row,"Consumed: %dWh ",EVSE_GetThisCons());
		LCD_Show_String(row, 1);
		break;
	case evsNoFreePower:
		LCD_Show_String("No free power", 0);
		sprintf(row,"Limit: %dA ",EVSE_GetCurrentLimit());
		LCD_Show_String(row, 1);
		break;
	case evsError:
		LCD_Show_String("EVSE ERROR! ", 0);
		sprintf(row,"Limit: %dA ",EVSE_GetCurrentLimit());
		LCD_Show_String(row, 1);
		break;
	}



}




/*Private methods*/

static void ProcessMessage(s_CanRxMsg* msg)
{
	uint16_t cmd = msg->header.StdId & 0xFF0;  // maskout nodeid
//	uint8_t producer = msg->header.StdId & 0x00F;  // maskout cmd
	int16_t par1,par2,par3; //,par4;
	uint32_t unixtime = 0;
	par1 = (msg->data[0] << 8) | msg->data[1];
	par2 = (msg->data[2] << 8) | msg->data[3];
	par3 = (msg->data[4] << 8) | msg->data[5];
	// par4 = (msg->data[6] << 8) | msg->data[7];

	switch (cmd)
	{
		case CMD_BUTTON_STATE:
			break;
		case  CMD_VAR_VALUE:
			VAR_SetVariable(par1, par2, par3);  // tbd check valid flag
			break;
		case CMD_GESTURE:
			break;
		case CMD_RTC_SYNC: // set RTC time
			unixtime |= msg->data[0] << 24;
			unixtime |= msg->data[1] << 16;
			unixtime |= msg->data[2] << 8;
			unixtime |= msg->data[3];
			RTC_SetUnixTime(unixtime);
			break;
	}
	return;
}




void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	ELM_ExtiCallback(GPIO_Pin);
}





