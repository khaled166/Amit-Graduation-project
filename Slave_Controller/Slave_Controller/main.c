/*
 * Slave_Controller.c
 *
 * Created: 8/21/2020 4:53:33 PM
 * Author : Khaledseif166
 */ 
// 0.Documentation Section
// main.c
// Runs on Atmega32

/*  Project Description

-This project is Smart Home based Bluetooth where we want to
control home appliance wirelessly using Mobile App via Bluetooth.

-It is a Slave software that receiving the data from mobile application
 via spi communication protocol and apply the action on the home appliance
 according to that data received from the mobile application. 
  
*/
//*************************************************************************************
// 1. Pre-processor Directives Section
#include "SPI.h"
#include "Config_Main_System.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
//*************************************************************************************
// 2. Declarations Section
//   Global Variables
uint8 Received_Data=0;             //empty buffer to hold the transmitted data from the master controller.
uint8 Slave_controller_responde=0; //empty buffer to hold the devices status to display on screen.
//****************************************************************************************
// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void)
{
	LCD_Init();     
	Slave_spi_init();  //initialized as a slave device that receive the data from the master device.
	DIO_SetPinDir(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);    //set PD3 as an output pin.
	DIO_SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);    //set PC2 as an output pin.
    while (1) 
    {
		
	/************************************ Home Devices Action According to Data received****************************/
		
		if(Received_Data==First_Device_Active_Mode){                //check the data received from the master controller.
	        First_device_turned_on                                  //Apply the action according the data received
		    Received_Data=0;                                        //clear the data received
		    Send_data_via_SPI(send_respond_device1_on);             //Send confirmation to the screen of the device status.
	}
		if(Received_Data==Second_Device_Active_Mode){	            //check the data received from the master controller.
			Second_device_turned_on	                                //Apply the action according the data received
            Received_Data=0;                                        //clear the data received 
			Send_data_via_SPI(send_respond_device2_on);             //Send confirmation to the screen of the device status.
    }
	    if(Received_Data==First_Device_Sleep_Mode){                 //check the data received from the master controller.
		    First_device_turned_off                                 //Apply the action according the data received
		    Received_Data=0;                                        //clear the data received 
		    Send_data_via_SPI(send_respond_device1_off);            //Send confirmation to the screen of the device status.
    }
	    if(Received_Data==Second_Device_Sleep_Mode){                //check the data received from the master controller. 
		    Second_device_turned_off                                //Apply the action according the data received
		    Received_Data=0;                                        //clear the data received 
		    Send_data_via_SPI(send_respond_device2_off);            //Send confirmation to the screen of the device status.
    }
		if(Received_Data==All_Home_devices_Sleep_Mode){             //check the data received from the master controller.
		    All_devices_turned_off                                  //Apply the action according the data received
		    Received_Data=0;                                        //clear the data received 
		    Send_data_via_SPI(send_respond_all_devices_off);        //Send confirmation to the screen of the device status.
	}
	_delay_ms(100);	
  }
}







ISR(SPI_STC_vect){
	if(GET_BIT(SPSR,7)==1){
		Received_Data=SPDR;
		CLR_BIT(SPSR,7);
	}
}
