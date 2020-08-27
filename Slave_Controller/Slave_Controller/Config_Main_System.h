/*
 * Config_Main_System.h
 *
 * Created: 8/24/2020 8:22:54 AM
 *  Author: Khaledseif166
 */ 


#ifndef CONFIG_MAIN_SYSTEM_H_
#define CONFIG_MAIN_SYSTEM_H_
#include "DIO.h"

#define First_Device_Active_Mode       '1'  //Send this data from mobile app via bluetooth to turn on this device.
#define Second_Device_Active_Mode      '2'  //send this data from mobile app via bluetooth to turn on this device.
#define First_Device_Sleep_Mode        '3'  //send this data from mobile app via bluetooth to turn off this device.
#define Second_Device_Sleep_Mode       '4'  //send this data from mobile app via bluetooth to turn off this device.
#define All_Home_devices_Sleep_Mode    '5'  //Send this data from mobile app via bluetooth to turn off all devices.
#define First_device_turned_on     DIO_WritePin(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);  
#define Second_device_turned_on    DIO_WritePin(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
#define First_device_turned_off    DIO_WritePin(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
#define Second_device_turned_off   DIO_WritePin(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
#define All_devices_turned_off     DIO_WritePin(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);\
                                   DIO_WritePin(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
								 
					
								 			 
#define send_respond_device1_on         1   //data that sent to the master to confirm the device status.
#define send_respond_device2_on         2   //data that sent to the master to confirm the device status.
#define send_respond_device1_off        3   //data that sent to the master to confirm the device status.
#define send_respond_device2_off        4   //data that sent to the master to confirm the device status.
#define send_respond_all_devices_off    5   //data that sent to the master to confirm the device status.							   
						
						
						
								   
								   
                                        
										
#endif /* CONFIG_MAIN_SYSTEM_H_ */