

#ifndef DIO_H_
#define DIO_H_


#include "ATMEGA32_Regs.h"
#include "Bit_Math.h"





#define  DIO_PORTA      0
#define  DIO_PORTB      1
#define  DIO_PORTC      2
#define  DIO_PORTD      3




#define  DIO_PIN0       0
#define  DIO_PIN1       1
#define  DIO_PIN2       2
#define  DIO_PIN3       3
#define  DIO_PIN4       4
#define  DIO_PIN5       5
#define  DIO_PIN6       6
#define  DIO_PIN7       7



#define DIO_PIN_HIGH            1
#define DIO_PIN_LOW             0
#define DIO_PIN_PULL_UP         1

#define DIO_PORT_HIGH           0xFF
#define DIO_PORT_LOW            0
#define DIO_PORT_PULL_UP        0xFF


#define DIO_PIN_OUTPUT          1
#define DIO_PIN_INPUT           0

#define DIO_PORT_OUTPUT         0xFF
#define DIO_PORT_INPUT          0






void DIO_SetPortDir(uint8 Port , uint8 Dir);
void DIO_SetPinDir(uint8 Port ,uint8 Pin , uint8 Dir);

void DIO_WritePort(uint8 Port , uint8 Val);
void DIO_WritePin(uint8 Port ,uint8 Pin, uint8 Val);

void DIO_ReadPort(uint8 Port , uint8* Val);
void DIO_ReadPin (uint8 Port ,uint8 Pin, uint8* Val);








#endif





