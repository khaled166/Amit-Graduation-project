/*
 * bluetooth.h
 *
 * Created: 8/19/2020 2:33:51 PM
 *  Author: Khaledseif166
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_
#include "UART.h"

//***************************************************************************************
/*
	Function Name        : Bluetooth_init
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize bluetooth according to uart communication protocol.
*/
void Bluetooth_init(void);
//***************************************************************************************
/*
	Function Name        : Bluetooth_send_data
	Function Returns     : uint8
	Function Arguments   : void
	Function Description : Receive data form connected mobile  app.
*/
uint8 Bluetooth_send_data(void);

#endif /* BLUETOOTH_H_ */