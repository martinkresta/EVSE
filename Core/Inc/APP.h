/*
 * APP.h
 *
 *  Created on: Aug 14, 2021
 *      Author: Martin
*				Brief:  Main application and compile time configuration
 */

#ifndef INC_APP_H_
#define INC_APP_H_

#include "main.h"
#include "MCAN.h"

#define LIMITED_UI

// CAN node ID
#define THIS_NODE				NODEID_EVSE


#define NUM_OF_ELEMTERS				1
#define ELM_EVSE					0



void APP_Init(void);
void APP_Start(void);
void APP_ProcessMessages(void);
void APP_Update_100ms(void);


#endif /* INC_APP_H_ */
