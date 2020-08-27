/*
 * SPI.c
 *
 * Created: 8/20/2020 10:57:10 PM
 *  Author: Khaledseif166
 */ 

#include "SPI.h"

void Slave_spi_init(void){
	DIO_SetPinDir(DIO_PORTB,DIO_PIN4,DIO_PIN_INPUT);     //Slave destination SS(slave select) PB4 input. 
	DIO_SetPinDir(DIO_PORTB,DIO_PIN5,DIO_PIN_INPUT);     //Clear PortB PA5 mosi(master output slave input).
	DIO_SetPinDir(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT);    //set portB PB6 miso(master input slave output).
	DIO_SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_INPUT);     //take the clk pulse from the master controller.
	SET_BIT(SPCR,6);   //Enable spi communication.
	SET_BIT(SREG,7);   //enable global interrupt.
	SET_BIT(SPCR,7);   //enable spi interrupt.
	//SET_BIT(SPCR,0);  //set clk speed according to F/4.
	//SET_BIT(SPCR,1);  //set clk speed according to F/4.
}


void Send_data_via_SPI(uint8 trans_Data){
	SPDR=trans_Data;  //move the given data to SPI Data register SPDR.
}
