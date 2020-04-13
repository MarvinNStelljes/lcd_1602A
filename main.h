//main.h

#include <stdint.h>




//lcd_1602A.h

#ifndef LCD_1602A_H

#define LCD_1602A_H
#endif /* LCD_1602A_H */

#define F_CPU 16000000UL


#define LCD_D4	PORTD4
#define LCD_D5	PORTD5
#define LCD_D6	PORTD6
#define LCD_D7	PORTD7

#define LOW_NIBBLE	0x0F
#define HIGH_NIBBLE	0xF0

#define LCD_DATA PORTD
#define LCD_DATA_IN PIND

#define RW_PIN	PORTD3
#define RW_PORT	PORTD

#define RS_PIN	PORTD2
#define RS_PORT	PORTD



#define LCD_EN	PORTB4
#define LCD_EN_PORT	PORTB


	




#define SENSOR		PORTB2
#define SENSOR_PORT	PINB2

#define BIT0 0b00000001
#define BIT1 0b00000010
#define BIT2 0b00000100
#define BIT3 0b00001000
#define BIT4 0b00010000
#define BIT5 0b00100000
#define BIT6 0b01000000
#define BIT7 0b10000000

#define LCD_ENTRY_MODE			0x04
#define LCD_CURSOR_INC_DIR_LEFT		(0 << 1)
#define LCD_CURSOR_INC_DIR_RIGHT	(1 << 1)
#define LCD_SHIFT_ON			(1 << 0)
#define LCD_SHIFT_OFF			(0 << 0)

//LCD Display ON/OFF
#define LCD_DISPLAY_ON			0x0C
#define LCD_DISPLAY_OFF			0x08
#define LCD_CURSOR_ON			(1 << 1)
#define LCD_CURSOR_OFF			(0 << 1)
#define LCD_CURSOR_BLINK_ON		(1 << 0)
#define LCD_CURSOR_BLINK_OFF	(0 << 0)

//LCD Function Set
#define LCD_FUNCTION_SET		0x20
#define LCD_SET_8BIT_MODE		(1 << 4)
#define LCD_SET_4BIT_MODE		(0 << 4)
#define LCD_SET_1LINE_MODE		(0 << 3)
#define LCD_SET_2LINE_MODE		(1 << 3)
#define LCD_FONT_5X8_MODE		(0 << 2)
#define LCD_FONT_5X11_MODE		(1 << 2)

#define LCD_CLEAR_DISPLAY		0x01	

#define LCD_RETURN_HOME			0x02
#define LCD_CARRIAGE_RETURN		0xC0


#define LCD_SHIFT_CONTROL		0x10
#define LCD_MOVE_LEFT	(0 << 2)
#define LCD_MOVE_RIGHT	(1 << 2)
#define LCD_SHIFT_MOVE	(1 << 3)
#define LCD_CURSOR_MOVE	(0 << 3)


#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include "atmel_io_control.h"


extern int get_lcd_busy_flag(void);





