/*
 * SPI.h
 *
 * Created: 8/20/2020 10:56:51 PM
 *  Author: Khaledseif166
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "DIO.h"
//****************************************************************************************
/*
	Function Name        : Master_spi_init
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize SPI master device.
*/
void Master_spi_init(void);
//****************************************************************************************
/*
	Function Name        : spi_trans_init
	Function Returns     : void
	Function Arguments   : void
	Function Description : Allow the clk to start transmission and receiving between master and slave.
*/
void spi_trans_init(void);
//****************************************************************************************
/*
	Function Name        : Send_data_via_SPI
	Function Returns     : void
	Function Arguments   : uint8
	Function Description : Send data that targeted from bluetooth module to the slave device.
*/
void Send_data_via_SPI(uint8);


#endif /* SPI_H_ */