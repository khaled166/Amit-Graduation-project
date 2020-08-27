/*
 * UART.c
 *
 * Created: 8/19/2020 2:33:26 PM
 *  Author: Khaledseif166
 */ 

#include "UART.h"

//*************************************************************************************************
void UART_INIT(void){
	DIO_SetPinDir(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);       // DIO RXD initialized as input pin. 
	DIO_SetPinDir(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);      // DIO_TXD initialized as output pin.
	SET_BIT(UCSRB,3);     //Enable uart receiver bit.
 	SET_BIT(UCSRB,4);     //Enable uart transmitter bit. 
	SET_BIT(UCSRC,1);     //select 8-bit character size.
	SET_BIT(UCSRC,2);     //select 8_bit character size. 
	SET_BIT(UCSRC,7);     //allow accessing on UCSRC register.
	SET_BIT(UCSRA,1);     //Double the USART Transmission Speed.
	UBRRL=103;            //baud rate 9600 F_CPU 8MHZ. 
	
}
//*************************************************************************************************
uint8 UART_Receive_Data(void){
	uint8 Data=0;                //Data send to the receiver device.
	while(GET_BIT(UCSRA,7)==0);  //check if there is a new data received or not. 
	Data= UDR;                   //new data sent to the UDR register
	return Data;                 //Return the value of uart data register (UDR) while the transmission is complete.    
}