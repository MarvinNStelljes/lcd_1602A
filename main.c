/* Alle Zeichen zwischen Schrägstrich-Stern 
   und Stern-Schrägstrich sind Kommentare */

// Zeilenkommentare sind ebenfalls möglich
// alle auf die beiden Schrägstriche folgenden
// Zeichen einer Zeile sind Kommentar



#include "lcd_1602A.h"
#include "main.h"
#include <avr/io.h> 
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
//#include <avr/io.h>          // (1)
//#include <util/delay.h>


//#include "lcd_1602A.h"




/*
void set_bits(unsigned char *reg, unsigned char num, int first_bit, ...);
void clear_bits(unsigned char *reg, unsigned char num, int first_bit, ...);
void lcd_write(unsigned char character);
void lcd_write_string(unsigned char *string);
void put_lcd_data(uint8_t data);
void put_lcd_nibble(uint8_t data);

*/


int main (void) {   
	
	_delay_ms (20);
		DDRB = 0xFF;             // (3)
            
	DDRD = 0xFF;         // (2)

  
 
    clear_bits(&PORTD, 2, RS_PIN, RW_PIN);
   _delay_ms (10); 
   
put_lcd_nibble(0x03);
_delay_ms (4.1);

put_lcd_nibble(0x03);
_delay_us (100);

              



put_lcd_nibble(0x03);
_delay_ms (4.1);
put_lcd_nibble(0x02);
_delay_ms (4.1);

put_lcd_data(LCD_FUNCTION_SET | LCD_SET_4BIT_MODE | LCD_SET_2LINE_MODE | LCD_FONT_5X8_MODE);	

put_lcd_data(LCD_DISPLAY_OFF);

put_lcd_data(LCD_CLEAR_DISPLAY);	

//Entry Mode

put_lcd_data(LCD_ENTRY_MODE | LCD_CURSOR_INC_DIR_RIGHT| LCD_SHIFT_OFF);


put_lcd_data(LCD_DISPLAY_ON | LCD_CURSOR_ON | LCD_CURSOR_BLINK_ON);

//----------------------------------------------------------------------
	uint8_t formatted_string[40];

int zahl = 0x55;




   	lcd_write_string("Na das war aber eine schwere Geburt");
   	 _delay_ms (2000);
         
   	put_lcd_data(LCD_CLEAR_DISPLAY);
  
   	
	lcd_write_string("Und das alles wegen einem schlechten Datenblatt...");
	_delay_ms (2000);
	put_lcd_data(LCD_CLEAR_DISPLAY);
	
	
	sprintf(formatted_string, "DMSG: PORTB:%x",PORTB);
	lcd_write_string(formatted_string);
	_delay_ms (2000);
	
		
	DDRB &=	~(1 << SENSOR);
	_delay_ms (20);
	
		
	put_lcd_data(LCD_CLEAR_DISPLAY);	
		
		
	while(1) {                
     
        debug_pin(PORTB0);
        
	sprintf(formatted_string, "SENSOR: %x",(PINB & (1 << PINB2)));
	lcd_write_string(formatted_string);
	
	put_lcd_data(LCD_CARRIAGE_RETURN);
	//while(get_lcd_busy_flag() > 0);
	
	_delay_ms (1000);	
        
        
   }        
		
		
	
	
   while(1) {                
     
        debug_pin(PORTB0);
   }                        

   /* wird nie erreicht */
   return 0;                 
}






void set_bits(unsigned char *reg, unsigned char num, int first_bit, ...) 
{
	va_list pointer;
	 
	*reg |= (1 << first_bit);
	
	if (num >1) {
	
		va_start(pointer, first_bit);
		
		while((num-1) > 0)  {
			*reg |= (1 << va_arg(pointer, int));
			num--;
		}
		va_end(pointer);
	}
}
	
	void clear_bits(unsigned char *reg, unsigned char num, int first_bit, ...) 
{
	va_list pointer;
	
	*reg &= ~(1 << first_bit);
	 
	if (num >1) {
		
		va_start(pointer, first_bit);
		
		while(num > 0)  {
			*reg &= ~(1 << va_arg(pointer, int));
			num--;
		}
		va_end(pointer);
	}
}
	
	void lcd_write(unsigned char character)
	{
		
		
			 set_bits(&RS_PORT, 1, RS_PIN); 
	
   _delay_ms (1); 
	
	 put_lcd_data(character);
	//while(get_lcd_busy_flag() > 0);

	
		
	
		
	clear_bits(&RS_PORT, 1, RS_PIN);
	

	//while(get_lcd_busy_flag() > 0);
}
	

void lcd_write_string(unsigned char *string)
{
	int cnt = 0; 
	
	while(*string != 0) {
			
		set_bits(&RS_PORT, 1, RS_PIN); 
		
		_delay_ms (1);
		
		put_lcd_data(*string);
		//while(get_lcd_busy_flag() > 0);	
					
		clear_bits(&RS_PORT, 1, RS_PIN);
			
		if (cnt == 15)
		{
			//carriage return
		
		put_lcd_data(LCD_CARRIAGE_RETURN);
		//while(get_lcd_busy_flag() > 0);
		}
	//_delay_ms (150);
		string++;
		cnt++;
		
		
		}
	}
	
	
	
void put_lcd_data(uint8_t data)	
{
	LCD_DATA &= ~((1 << LCD_D7) | (1 << LCD_D6) | (1 << LCD_D5) | (1 << LCD_D4));
	
	set_bits(&PORTB, 1, LCD_EN); 

	if ((data & BIT7) != 0)
		LCD_DATA |= (1 << LCD_D7);
	if ((data & BIT6) != 0)
		LCD_DATA |= (1 << LCD_D6);
	if ((data & BIT5) != 0)
		LCD_DATA |= (1 << LCD_D5);
	if ((data & BIT4) != 0)
		LCD_DATA |= (1 << LCD_D4);

	clear_bits(&PORTB, 1, LCD_EN);

	LCD_DATA &= ~((1 << LCD_D4) | (1 << LCD_D5) | (1 << LCD_D6) | (1 << LCD_D7));

	set_bits(&PORTB, 1, LCD_EN);     

	if ((data & BIT3) != 0)
		LCD_DATA |= (1 << LCD_D7);
	if ((data & BIT2) != 0)
		LCD_DATA |= (1 << LCD_D6);
	if ((data & BIT1) != 0)
		LCD_DATA |= (1 << LCD_D5);
	if ((data & BIT0) != 0)
		LCD_DATA |= (1 << LCD_D4);

	clear_bits(&PORTB, 1, LCD_EN);
	
	
	
	
	while(get_lcd_busy_flag() > 0);  //Der ist wichtig!!!
	
	
		
}

void put_lcd_nibble(uint8_t data)	
{
	set_bits(&PORTB, 1, LCD_EN); 
   _delay_ms (100);
	LCD_DATA &= ~((1 << LCD_D7) | (1 << LCD_D6) | (1 << LCD_D5) | (1 << LCD_D4));
	
	if ((data & BIT3) != 0)
		LCD_DATA |= (1 << LCD_D7);
	if ((data & BIT2) != 0)
		LCD_DATA |= (1 << LCD_D6);
	if ((data & BIT1) != 0)
		LCD_DATA |= (1 << LCD_D5);
	if ((data & BIT0) != 0)
		LCD_DATA |= (1 << LCD_D4);
	_delay_ms (100);
	clear_bits(&PORTB, 1, LCD_EN);
}	



void   debug_pin(uint8_t bit)                                                                        
{
		PORTB |= (1 << bit);
		_delay_ms (1000);
		PORTB &= ~(1 << bit);
		_delay_ms (1000);
}
	
	/*
	put_lcd_conf
	
	get_lcd_data

	
	
*/










/*

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
*/
