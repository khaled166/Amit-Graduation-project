


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_
#include "STD.h"
/******************************************* External Interrupt Memory Addresses **************************************************************************************************************/
#define SREG   (*(volatile uint8*)(0x5F))           //Status Register Memory Address(ATMEGA32 MICROCHIP)
#define GICR   (*(volatile uint8*)(0x5B))           //General Interrupt Control Register Memory Address(ATMEGA32 MICROCHIP) 
#define GIFR   (*(volatile uint8*)(0x5A))           //General Interrupt Flag Register Memory Address(ATMEGA32 MICROCHIP)
#define MCUCR  (*(volatile uint8*)(0x55))           //MicroController Control Register Memory Address(ATMEGA32 MICROCHIP)
#define MCUCSR (*(volatile uint8*)(0x54))           //MicroController Control&Status Register Memory Address(ATMEGA32 MICROCHIP)  
/******************************************* DIO Memory Addresses **************************************************************************************************************************/
#define PORTA (*(volatile uint8*)(0x3B))            //Atmega32 Accessing DIO registers.
#define PINA  (*(volatile uint8*)(0x39))            //Atmega32 Accessing DIO registers.
#define DDRA  (*(volatile uint8*)(0x3A))            //Atmega32 Accessing DIO registers.
#define PORTB (*(volatile uint8*)(0x38))            //Atmega32 Accessing DIO registers.
#define PINB  (*(volatile uint8*)(0x36))            //Atmega32 Accessing DIO registers.  
#define DDRB  (*(volatile uint8*)(0x37))            //Atmega32 Accessing DIO registers.
#define PORTC (*((volatile uint8*)(0x35)))          //Atmega32 Accessing DIO registers.
#define PINC  (*((volatile uint8*)(0x33)))          //Atmega32 Accessing DIO registers.
#define DDRC  (*((volatile uint8*)(0x34)))          //Atmega32 Accessing DIO registers.
#define PORTD (*(volatile uint8*)(0x32))            //Atmega32 Accessing DIO registers.   
#define PIND  (*(volatile uint8*)(0x30))            //Atmega32 Accessing DIO registers. 
#define DDRD  (*(volatile uint8*)(0x31))            //Atmega32 Accessing DIO registers.
/****************************************************                 ADC Memory Addresses                ***************************************************/
#define ADMUX           (*(volatile uint8 *)(0x27))           //Analog To Digital Converter Multiplexer Selection Register
#define ADCSRA          (*(volatile uint8 *)(0x26))           //Analog To Digital Converter Control&Status Register A
#define ADCH            (*(volatile uint8 *)(0x25))           //Analog To Digital Converter Highest Register
#define ADCL            (*(volatile uint8 *)(0x24))           //Analog To Digital Converter Lowest Register
#define ADC_Adjust      (*(volatile uint16*)(0x24))           //Analog To Digital Converter ADCH+ADCL Register
#define SFIOR           (*(volatile uint8 *)(0x50))            //Special FunctionIO Register
/****************************************************               Timer Memory Addresses               *************************************************/
//Timer0 Registers Memory Addresses 
#define TCNT0  (*(volatile uint8*)(0x52))
#define TCCR0  (*(volatile uint8*)(0x53))
#define OCR0   (*(volatile uint8*)(0x5C))
#define TIMSK  (*(volatile uint8*)(0x59))             //Timers(timer0-timer1-timer2) Accessing on this Register to Active Interrupt Status
#define TIFR   (*(volatile uint8*)(0x58))
//Timer1 Registers Memory Addresses
#define TCCR1A  (*(volatile uint8*)(0x4F))
#define TCCR1B  (*(volatile uint8*)(0x4E))
#define TCNT1   (*(volatile uint16*)(0x4C))           //Timer1 Counter Register Accessing Both (TCNT1L+TCNT1H)
#define OCR1A   (*(volatile uint16*)(0x4A))           //Timer1 Output Compare Match RegistersA (OCR1AL+OCR1AH)
#define OCR1B   (*(volatile uint16*)(0x48))           //Timer1 Output Compare Match RegistersB (OCR1BL+OCR1BH)
#define ICR1    (*(volatile uint16*)(0x46))           //Timer1 Input Capture Registers (ICR1L+ICR1H)
//Timer2 Register Memory Addresses
#define TCCR2   (*(volatile uint8*)(0x45))
#define TCNT2   (*(volatile uint8*)(0x44))
#define OCR2    (*(volatile uint8*)(0x43))
/*******************************************************           USART Memory Addressess        *****************************************************************************/
#define UDR (*(volatile uint8*)(0x2C))                           //Atmega32 Accessing UART registers.
#define UCSRA (*(volatile uint8*)(0x2B))                         //Atmega32 Accessing UART registers.
#define UCSRB (*(volatile uint8*)(0x2A))                         //Atmega32 Accessing UART registers.
#define UBRRL (*(volatile uint8*)(0x29))                         //Atmega32 Accessing UART registers. 
#define UBRRH (*(volatile uint8*)(0x40))                         //Atmega32 Accessing UART registers. 
#define UCSRC (*(volatile uint8*)(0x40))                         //Atmega32 Accessing UART registers.
#define UDR (*(volatile uint8*)(0x2C))                           //Atmega32 Accessing UART registers.         
/***************************************************       SPI Memory Addressess      **********************************************************************/
#define SPDR (*(volatile uint8*)(0x2F))                          //Atmega32 Accessing SPI registers 
#define SPSR (*(volatile uint8*)(0x2E))                          //Atmega32 Accessing SPI registers                          
#define SPCR (*(volatile uint8*)(0x2D))                          //Atmega32 Accessing SPI registers
/*
typedef struct{
	
	 uint8  SPDR
	 uint8  SPSR
	 uint8  SPCR
	}SPI_Reg;
	
#define SPI ((volatile SPI_Reg*)(0x2D))	
*/
#endif /* ATMEGA32_REG_H_ */