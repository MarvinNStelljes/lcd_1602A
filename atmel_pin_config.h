
#ifndef ATMEL_PIN_CONFIG_H

#define ATMEL_PIN_CONFIG_H



#include <stdint.h>

 struct portpin {
	volatile uint8_t *port;
	uint8_t pin;
};

struct portpin LCD_EN_test;

extern void configurate_pins(void);

#endif /* LCD_1602A_H */
