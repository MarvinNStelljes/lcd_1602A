


#include "atmel_pin_config.h"
#include <avr/io.h> 

void configurate_pins(void)
{
	LCD_EN_test.port = &PORTB;
	LCD_EN_test.pin = PORTB4;
}
