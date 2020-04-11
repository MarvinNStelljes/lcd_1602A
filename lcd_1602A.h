//lcd_1602A.h

#ifndef LCD_1602A_H

#define LCD_1602A_H
#endif /* LCD_1602A_H */


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


int get_lcd_busy_flag(void);
