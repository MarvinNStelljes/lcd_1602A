//lcd_1602A.c





#include <util/delay.h>
#include "lcd_1602A.h"




/////-----void toggle_LCD_EN(void)-----/////
/*Toggle the LCD enable pin to transmit or receive data. The data to tranceive have to be set on output before toggle the LCD enable pin. */

void toggle_LCD_EN(volatile uint8_t *port, int lcd_enable_pin)

{
	clear_bits(port, 1, lcd_enable_pin);
	_delay_us (1);
	set_bits(port, 1, lcd_enable_pin);
	_delay_us (1);
	clear_bits(port, 1, lcd_enable_pin);
}

extern void toggle_LCD_EN_test(struct portpin *test) 

{
	//clear_bits(test.port, 1, test->pin);
	_delay_us (1);
	set_bits(test->port, 1, test->pin);
	_delay_us (1);
	clear_bits(test->port, 1, test->pin);

}
