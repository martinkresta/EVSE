#include "ST7066U.h"
#include "string.h"

typedef struct 
{
	GPIO_TypeDef*	gate;
	uint16_t		pin; 		
}sPinCfg;

#define RS_Enable HAL_GPIO_WritePin(RS_GPIO_Port,RS_Pin,GPIO_PIN_SET);
#define RW_Enable HAL_GPIO_WritePin(R_W_GPIO_Port, R_W_Pin, GPIO_PIN_SET);
#define E_Enable HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);

#define RS_Disable HAL_GPIO_WritePin(RS_GPIO_Port,RS_Pin,GPIO_PIN_RESET);
#define RW_Disable HAL_GPIO_WritePin(R_W_GPIO_Port, R_W_Pin, GPIO_PIN_RESET);
#define E_Disable HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);

#define LED_IC_FUNCTION_SET						0x20
#define LED_ICFS_8BIT									0x10
#define LED_ICFS_4BIT									0x00
#define LED_ICFS_2LINES								0x08
#define LED_ICFS_1LINES								0x00
#define LED_ICFS_DOUBLE_HEIGHT				0x04
#define LED_ICFS_INS_TABLE0						0x00
#define LED_ICFS_INS_TABLE1						0x01
#define LED_ICFS_INS_TABLE2						0x03

#define LED_IC_DISPLAY_ON_OFF					0x08
#define LED_IC_DIS_ON									0x04
#define LED_IC_DIS_OFF								0x00
#define LED_IC_DIS_CURSOR_ON					0x02
#define LED_IC_DIS_CURSOR_OFF					0x00
#define LED_IC_DIS_CURSOR_ON_POSITON	0x01

#define LED_IC_CLEAR_DISPLAY					0x01

#define LED_IC_CURSOR									0x04
#define LED_IC_CURSOR_INCREMENT_ON		0x02
#define LED_IC_CURSOR_INCREMENT_OFF 	0x00
#define LED_IC_CURSOR_SHIFT_ON				0x01
#define LED_IC_CURSOR_SHIFT_OFF				0x00

#define LED_SET_POSSITION							0x80
#define LED_SP_1ROW										0x00
#define LED_SP_2ROW										0x40


uint8_t	Led_First_Row_Mem					[0xFF] = "Hovno!";
uint8_t	Led_First_Row_MemOffset		= 0x00;
uint8_t	Led_Second_Row_Mem				[0xFF];
uint8_t	Led_Second_Row_MemOffset	= 0x00;
uint8_t	Led_First_Row							[0x10];
uint8_t	Led_Second_Row						[0x10];

uint8_t	Led_Redraw = 0x00;


void LCD_SendCmd(uint8_t cmd);
void LCD_SendData(uint8_t data);
void LCD_Send_Text(uint8_t *data);

void WriteDataToBus(uint8_t cmd)
{
	uint32_t bssr = 0x00000000;
	bssr |= cmd;  // setting bits
	bssr |= (((~cmd)<<16) & 0x00FF0000); // resetting bits

	D0_GPIO_Port->BSRR = bssr;

}



void LCD_Init (void)
{
	HAL_Delay(50);
	LCD_SendCmd(LED_IC_FUNCTION_SET | LED_ICFS_8BIT | LED_ICFS_2LINES | LED_ICFS_INS_TABLE0);
	HAL_Delay(10);
	LCD_SendCmd(LED_IC_FUNCTION_SET | LED_ICFS_8BIT | LED_ICFS_2LINES | LED_ICFS_INS_TABLE0);
	HAL_Delay(200);
	LCD_SendCmd(LED_IC_FUNCTION_SET | LED_ICFS_8BIT | LED_ICFS_2LINES | LED_ICFS_INS_TABLE0);
	
	LCD_SendCmd(LED_IC_FUNCTION_SET | LED_ICFS_8BIT | LED_ICFS_2LINES | LED_ICFS_INS_TABLE0);
		
	//Configurace - LED DISPLAY OFF
	LCD_SendCmd(LED_IC_DISPLAY_ON_OFF | LED_IC_DIS_OFF);	
	
	//Configurace - LED DISPLAY CLEAR
	LCD_SendCmd(LED_IC_CLEAR_DISPLAY);		
	
	//Configurace - LED DISPLAY CLEAR
	LCD_SendCmd(LED_IC_CURSOR | LED_IC_CURSOR_INCREMENT_ON | LED_IC_CURSOR_SHIFT_OFF);	
	
	LCD_SendCmd(LED_IC_DISPLAY_ON_OFF | LED_IC_DIS_ON | LED_IC_DIS_CURSOR_OFF);
	
}

void LCD_Set_Position (uint8_t row, uint8_t column)
{
	if(row == 0x00)
	{
		LCD_SendCmd(LED_SET_POSSITION | LED_SP_1ROW + column);
	}
	else
	{
		LCD_SendCmd(LED_SET_POSSITION | LED_SP_2ROW + column);
	}
}

void LCD_SendCmd(uint8_t cmd)
{		
	RS_Disable;		
	RW_Disable;	
	E_Enable;
	WriteDataToBus(cmd);
	//LL_GPIO_WriteOutputPort(D0_GPIO_Port, cmd & 0xFF);
	HAL_Delay(1);	
	E_Disable;	
	HAL_Delay(1);	
}

void LCD_SendData(uint8_t data)
{
	RS_Enable;	
	RW_Disable;
	E_Enable;
	WriteDataToBus(data);
	//LL_GPIO_WriteOutputPort(D0_GPIO_Port, data & 0xFF);
	E_Disable;
	HAL_Delay(1);	
}

void LCD_Send_Text(uint8_t *data)
{	
	uint8_t i;
	for(i=0;i<0x10;i++)
	{	
		LCD_SendData(*data);
		data++;
	}
}

void LCD_Refresf_Display(void)
{
	uint8_t	length;
	int16_t	help_diff = 0;
	memset(Led_First_Row,0x20,0x10);
	memset(Led_Second_Row,0x20,0x10);
	
	length = strlen((char*)Led_First_Row_Mem);
	if(length > 0x10)
	{
		if(length > Led_First_Row_MemOffset + 0x10)
		{			
			memcpy(Led_First_Row, &Led_First_Row_Mem[Led_First_Row_MemOffset], 0x10);
		}
		else
		{
			help_diff = length - Led_First_Row_MemOffset;			
			if(help_diff >= 0)
			{
				memcpy(Led_First_Row, &Led_First_Row_Mem[Led_First_Row_MemOffset], help_diff);
			}
			
			if(help_diff <13)
			{
				memcpy(&Led_First_Row[help_diff+4], Led_First_Row_Mem, 0x10 - help_diff - 4);
				if(help_diff == -4)
				{
					Led_First_Row_MemOffset = 0;
				}
			}
		}		
		Led_First_Row_MemOffset++;
	}
	else
	{
		memcpy(Led_First_Row,Led_First_Row_Mem, length);
	}	
	LCD_Set_Position(0,0);
	LCD_Send_Text(Led_First_Row);
	
	length = strlen((char*)Led_Second_Row_Mem);
	if(strlen((char*)Led_Second_Row_Mem) > 0x10)
	{
		if(length > Led_Second_Row_MemOffset + 0x10)
		{			
			memcpy(Led_Second_Row, &Led_Second_Row_Mem[Led_Second_Row_MemOffset], 0x10);
		}
		else
		{
			help_diff = length - Led_Second_Row_MemOffset;			
			if(help_diff >= 0)
			{
				memcpy(Led_Second_Row, &Led_Second_Row_Mem[Led_Second_Row_MemOffset], help_diff);
			}
			
			if(help_diff <13)
			{
				memcpy(&Led_Second_Row[help_diff+4], Led_Second_Row_Mem, 0x10 - help_diff - 4);
				if(help_diff == -4)
				{
					Led_Second_Row_MemOffset = 0;
				}
			}
		}		
		Led_Second_Row_MemOffset++;
	}
	else
	{
		memcpy(Led_Second_Row,Led_Second_Row_Mem,length);
	}	
	LCD_Set_Position(1,0);
	LCD_Send_Text(Led_Second_Row);
}

void LCD_Insert_New_Text(uint8_t *data, uint8_t row)
{
	uint8_t* p_data; 
	uint16_t data_length;
	
	if(row == 0)
	{
		p_data = Led_First_Row_Mem;
		Led_First_Row_MemOffset = 0;
	}
	else
	{
		p_data = Led_Second_Row_Mem;
		Led_Second_Row_MemOffset = 0;
	}

	data_length = strlen((char*)data);
	if(data_length > 0xFF)
	{
		data_length = 0xFE;
	}
	memset(p_data, 0x00, 0xFF);	
	memcpy(p_data,data,data_length);
}


