
#include <stdint.h>
#include "atmel_io_control.h"
#include "atmel_pin_config.h"

extern void toggle_LCD_EN(volatile uint8_t *port, int lcd_enable_pin);
extern void toggle_LCD_EN_test(struct portpin *test); 
