//lcd_1602A.c





#include "main.h"
#include "lcd_1602A.h"
#include <avr/io.h> 
#include <util/delay.h>



int get_lcd_busy_flag(void)
{
	// TODO: add address counter

	uint8_t input_buffer = 0;
	
	DDRD &= ~( (1 << LCD_D7) | (1 << LCD_D6) | (1 << LCD_D5) | (1 << LCD_D4));	// Set LCD Port Pins as Input
		
	clear_bits(&RS_PORT, 1, RS_PIN);
	set_bits(&RW_PORT, 1, RW_PIN); 
	_delay_ms (1);
	set_bits(&PORTB, 1, LCD_EN);
	_delay_ms (1);
		
	if ((LCD_DATA_IN & (1 << LCD_D7)) != 0)
		input_buffer |= (1 << 7);
	if ((LCD_DATA_IN & (1 << LCD_D6)) != 0)
		input_buffer |= (1 << 6);
	if ((LCD_DATA_IN & (1 << LCD_D5)) != 0)
		input_buffer |= (1 << 5);
	if ((LCD_DATA_IN & (1 << LCD_D4)) != 0)
		input_buffer |= (1 << 4);
		
		_delay_ms (1);
	clear_bits(&PORTB, 1, LCD_EN);
   _delay_ms (1);
	set_bits(&PORTB, 1, LCD_EN);
	_delay_ms (1);
	
	if ((LCD_DATA_IN & (1 << LCD_D7)) != 0)
		input_buffer |= (1 << 3);
	if ((LCD_DATA_IN & (1 << LCD_D6)) != 0)
		input_buffer |= (1 << 2);
	if ((LCD_DATA_IN & (1 << LCD_D5)) != 0)
		input_buffer |= (1 << 1);
	if ((LCD_DATA_IN & (1 << LCD_D4)) != 0)
		input_buffer |= (1 << 0);
	
	clear_bits(&PORTB, 1, LCD_EN);
	
	clear_bits(&RW_PORT, 1, RW_PIN);
	
	DDRD |= ((1 << LCD_D7) | (1 << LCD_D6) | (1 << LCD_D5) | (1 << LCD_D4));	// Set LCD Port Pins as Output


	return ( input_buffer & 0b10000000);
}


/////-----void toggle_LCD_EN(void)-----/////
/*Toggle the LCD enable pin to transmit or receive data. The data to tranceive have to be set on output before toggle the LCD enable pin. */

void toggle_LCD_EN(void)
{
	set_bits(&LCD_EN_PORT, 1, LCD_EN);
	_delay_ms (1);
	clear_bits(&LCD_EN_PORT, 1, LCD_EN);
}
