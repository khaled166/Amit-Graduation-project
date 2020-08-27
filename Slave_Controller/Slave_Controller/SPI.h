/*
 * SPI.h
 *
 * Created: 8/20/2020 10:56:51 PM
 *  Author: Khaledseif166
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "DIO.h"

/*
	Function Name        : Slave_spi_init
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize SPI Slave Device.
*/
void Slave_spi_init(void);

/*
	Function Name        : Send_data_via_SPI
	Function Returns     : void
	Function Arguments   : uint8
	Function Description : Send Respond to the master according to the device status.
*/

void Send_data_via_SPI(uint8 trans_Data);

#endif /* SPI_H_ */