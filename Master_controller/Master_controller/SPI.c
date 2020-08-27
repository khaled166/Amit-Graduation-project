/*
 * SPI.c
 *
 * Created: 8/20/2020 10:57:10 PM
 *  Author: Khaledseif166
 */ 


#include "SPI.h"
//*****************************************************************************************************
void Master_spi_init(void){
	DIO_SetPinDir(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);   //master SS(slave select) PA0 output. 
	DIO_SetPinDir(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT);   //set PortB PA5 mosi(master output slave input).
	DIO_SetPinDir(DIO_PORTB,DIO_PIN6,DIO_PIN_INPUT);    //set portB PB6 miso(master input slave output).
	DIO_SetPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);   //enable sck(spi clock).
	SET_BIT(SPCR,6);  //enable spi protocol.
	SET_BIT(SPCR,4);  //enable spi master control.
	//SET_BIT(SPCR,0);  //set clk speed according to F/4.
	//SET_BIT(SPCR,1);  //set clk speed according to F/4.
	//SET_BIT(SPSR,0);
	SET_BIT(SREG,7);   //Enable global interrupt.
	SET_BIT(SPCR,7);   //Enable peripheral interrupt.
}
//******************************************************************************************************
void spi_trans_init(void){
	DIO_WritePin(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);       //transmission start while	PA0 is low.
}
//******************************************************************************************************
void Send_data_via_SPI(uint8 trans_Data){
	SPDR=trans_Data;  //move the given data to SPI Data register SPDR.
}
