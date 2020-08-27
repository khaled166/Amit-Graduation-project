/*
 * IncFile2.h
 *
 * Created: 04/07/2020 07:34:02 ص
 *  Author: Ali
 */ 


#ifndef INCFILE2_H_
#define INCFILE2_H_

#include "ATMEGA32_Regs.h"

#define   LCD_8BIT_CMD_PORT     PORTA
#define   LCD_8BIT_DATA_PORT    PORTB


#define   LCD_4BIT_CMD_PORT     DIO_PORTB
#define   LCD_4BIT_DATA_PORT    DIO_PORTA  


#define   LCD_RS_PIN            DIO_PIN1
#define   LCD_RW_PIN            DIO_PIN2
#define   LCD_E_PIN             DIO_PIN3

#define   LCD_D0                DIO_PIN0
#define   LCD_D1                DIO_PIN1
#define   LCD_D2                DIO_PIN2
#define   LCD_D3                DIO_PIN3
#define   LCD_D4                DIO_PIN4
#define   LCD_D5                DIO_PIN5
#define   LCD_D6                DIO_PIN6
#define   LCD_D7                DIO_PIN7



#define  LCD_MODE               4


#endif /* INCFILE2_H_ */