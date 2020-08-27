/*
 * Master_controller.c
 *
 * Created: 8/19/2020 2:31:05 PM
 * Author : Khaledseif166
 */ 

// 0.Documentation Section
// main.c
// Runs on Atmega32

/*  Project Description

-This project is Smart Home based Bluetooth where we want to
control home appliance wirelessly using Mobile App via Bluetooth.

-It is a master software that receiving the data from mobile application via bluetooth 
 and re-transmit this received data to the slave device via SPI communication protocol 
 to control the home appliance according to that received data.
   
*/
//*************************************************************************************
// 1. Pre-processor Directives Section
#include "bluetooth.h"
#include "SPI.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#define First_Device_Active_Mode       '1'  //Send this data from mobile app via bluetooth to turn on this device.
#define Second_Device_Active_Mode      '2'  //send this data from mobile app via bluetooth to turn on this device.
#define First_Device_Sleep_Mode        '3'  //send this data from mobile app via bluetooth to turn off this device. 
#define Second_Device_Sleep_Mode       '4'  //send this data from mobile app via bluetooth to turn off this device.
#define All_Home_devices_Sleep_Mode    '5'  //Send this data from mobile app via bluetooth to turn off all devices.
#define Receive_Respond_1               1   //Received confirmation according to the the devices states.
#define Receive_Respond_2               2   //Received confirmation according to the the devices states.
#define Receive_Respond_3               3   //Received confirmation according to the the devices states.
#define Receive_Respond_4               4   //Received confirmation according to the the devices states.
#define Receive_Respond_5               5   //Received confirmation according to the the devices states.
//*************************************************************************************
// 2. Declarations Section
//   Global Variables
uint8  Home_appliance_Status=0;     //Empty buffer hold the data that sent from the master bluetooth(mobile app) . 
uint8  Respond=0;                   //Empty buffer hold the data that received from the slave controller(screen device status).

//*************************************************************************************
// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void)
{      
	  Bluetooth_init();   //initialized according to the uart communication protocol standards.
	  Master_spi_init();  //initialized as a master device that send the data from mobile to slave device.
	  spi_trans_init();   //start the data transmission between master and slave devices.
	  LCD_Init();        //LCD initialized according 4-bit mode configuration(Data:PA4-PA7)(RS,RW,E:PB1-PB3).
	  _delay_ms(1000);    //delay a 1sec According to the SPI Communication protocol functionality.
    while (1) 
    {
	/*********************************** Data send to the slave controller**********************************/	
		Home_appliance_Status=Bluetooth_send_data();              //Receive the data sent from mobile app via bluetooth. 
	    if(Home_appliance_Status==First_Device_Active_Mode){      //check the data sent to the slave destination.
	        Send_data_via_SPI(Bluetooth_send_data());  //send this data to the slave controller via spi communication protocol.
		}
		if(Home_appliance_Status==Second_Device_Active_Mode){     //check the data sent to the slave destination.
			Send_data_via_SPI(Bluetooth_send_data());   //send this data to the slave controller via spi communication protocol.
		}
		if(Home_appliance_Status==First_Device_Sleep_Mode){        //check the data sent to the slave destination.
			Send_data_via_SPI(Bluetooth_send_data());    //send this data to the slave controller via spi communication protocol.
		}
		if(Home_appliance_Status==Second_Device_Sleep_Mode){       //check the data sent to the slave destination.
			Send_data_via_SPI(Bluetooth_send_data());   //send this data to the slave controller via spi communication protocol.
		}
		if(Home_appliance_Status==All_Home_devices_Sleep_Mode){   //check the data sent to the slave destination.
            Send_data_via_SPI(Bluetooth_send_data());	//send this data to the slave controller via spi communication protocol.	
	    }
	/******************************************* Slave controller Send respond *********************************/
	if(Respond==Receive_Respond_1){
		LCD_Clear();                                   //Clear the data on the LCD screen.     
		LCD_WriteString("Device1:ON");                 //Display the home devices status.
		Respond=0;
	}
	if(Respond==Receive_Respond_2){
		LCD_Clear();                                   //Clear the data on the LCD screen.
		LCD_WriteString("Device2: ON");                //Display the home devices status.
	}
	if(Respond==Receive_Respond_3){
		LCD_Clear();                                   //Clear the data on the LCD screen.
		LCD_WriteString("Device1:OFF");                //Display the home devices status.
	}
	if(Respond==Receive_Respond_4){
		LCD_Clear();                                  //Clear the data on the LCD screen.
	  LCD_WriteString("Device2:OFF");                 //Display the home devices status.
	}
	if(Respond==Receive_Respond_5){
		LCD_Clear();                                 //Clear the data on the LCD screen.
		LCD_WriteString("All devices OFF");          //Display the home devices status.
	}	
   _delay_ms(100);
  }
}




ISR(SPI_STC_vect){
	if(GET_BIT(SPSR,7)==1){
		Respond=SPDR;
		CLR_BIT(SPSR,7);
	}
}
