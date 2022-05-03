// Digital inputs 
// Author : Martin Kresta, credits
// Date   : 14.10.2019


#include "di.h"
#include "APP.h"

static sDI DI[NUM_OF_INPUTS];

/* Private functions prototypes */
static void 		DI_Struct_Initialisation (sDI init_struct, uint8_t input);

static void 	OnChange(sDI *di_input);

/* Public functions definitions */

void DI_Init(void)
{
	
	sDI init_struct;
	
	init_struct.Main_Status				= eDI_HI;
	init_struct.Actual_Status			= eDI_HI;
	init_struct.Last_Status				= eDI_HI;
	init_struct.Cnt_DI						= 0;
	init_struct.Cnt_Filter				= 0;
	init_struct.Filter_Value			= 50;
	
	//----------------------------------------------------------------------------------------
	init_struct.Port							= BTN_ENTER_GPIO_Port;
	init_struct.Pin								= BTN_ENTER_Pin;
	DI_Struct_Initialisation(init_struct,ENTER);
	//----------------------------------------------------------------------------------------
	init_struct.Port							= BTN_UP_GPIO_Port;
	init_struct.Pin								= BTN_UP_Pin;
	DI_Struct_Initialisation(init_struct,UP);
	//----------------------------------------------------------------------------------------
	init_struct.Port							= BTN_DOWN_GPIO_Port;
	init_struct.Pin								= BTN_DOWN_Pin;
	DI_Struct_Initialisation(init_struct,DOWN);
	//----------------------------------------------------------------------------------------

	
}


/**
* @brief  Reading of actual states on defined Digital input
* @param	*di_input	Pointer to Digital input
*/
static void DI_Struct_Initialisation (sDI init_struct, uint8_t input)
{
	init_struct.DiId = input;
	DI[input] = init_struct;
	DI_Read(&(DI[input]));
}

/**
* @brief  Reading of actual states on defined Digital input
* @param	*di_input	Pointer to Digital input
*/
void DI_Read (sDI *di_input)
{	
	di_input->Actual_Status = (eDI)HAL_GPIO_ReadPin(di_input->Port,di_input->Pin);
	if(di_input->Actual_Status != di_input->Main_Status)
	{
		di_input->Cnt_Filter++;
		if(di_input->Cnt_Filter > di_input->Filter_Value)
		{
			di_input->Main_Status = di_input->Actual_Status;							
			di_input->Cnt_Filter = 0;
			di_input->Cnt_DI = 0;
			if (di_input->Main_Status != di_input->Last_Status)
			{
				di_input->Last_Status = di_input->Main_Status;
				OnChange(di_input);
			}
		}
	}
	else
	{
		if(di_input->Cnt_DI!=0xFFFF)
		{
			di_input->Cnt_DI++;				
		}
	}
}


// return s status of one specified digital input
eDI DI_Get(uint8_t input)
{
	if (input < NUM_OF_INPUTS)
	{
		return DI[input].Main_Status;
	}
	return eDI_LO;
}



// sequentialy reads all digital inputs 
void DI_Read_All(void)
{
	uint8_t i;
	for (i = 0; i < NUM_OF_INPUTS; i++)
	{
		DI_Read(&DI[i]);
	}
}


// notify about input change
static void OnChange(sDI *di)
{
	//APP_DiInputChanged(di->DiId,di->Main_Status);
	//GEST_DiInputChanged(di->DiId,di->Main_Status);
}
