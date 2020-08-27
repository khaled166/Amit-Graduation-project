/*
 * UART.h
 *
 * Created: 8/19/2020 2:33:12 PM
 *  Author: Khaledseif166
 */ 


#ifndef UART_H_
#define UART_H_
#include "DIO.h"

//**********************************************************************************
/*
	Function Name        : UART_INIT
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize universal asynchronous receiver transmitter.
*/
void UART_INIT(void);
//***********************************************************************************
/*
	Function Name        : UART_Receive_Data
	Function Returns     : uint8
	Function Arguments   : void
	Function Description : return received data from any master application.
*/
uint8 UART_Receive_Data(void);



#endif /* UART_H_ */