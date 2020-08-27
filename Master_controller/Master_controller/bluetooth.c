/*
 * bluetooth.c
 *
 * Created: 8/19/2020 2:34:12 PM
 *  Author: Khaledseif166
 */ 

#include "bluetooth.h"


//*************************************************************************************
void Bluetooth_init(void){
	UART_INIT();  //configuration of uart communication protocol.
}

//************************************************************************************
uint8 Bluetooth_send_data(void){
	uint8 Data=0;  //Empty buffer to accept the received data form mobile app.
	Data=UART_Receive_Data(); //check the received data according to uart communication protocol. 
	return Data;  //return the received value after the transmission is done.
}
