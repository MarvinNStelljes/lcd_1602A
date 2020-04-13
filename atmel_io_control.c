/// atmel_io_control.c /// Author: MarvinNStelljes ///
/* Helper functions to manipulate input and output pins.
 * Supported microcontrollers:	atmega328p
 */


#include <stdarg.h>

#include "atmel_io_control.h"
/* Set a variable amount of bits.
 * 	
 * *reg			-	The address of Port which includes the pins to set
 *  num			- 	Number of pins which has to be set
 *  first_bit	- 	Pins to set as numbers from 0 - 7 
 *  				It has to be set at least one pin
 *
 * Example: set_bits(&PORT_A, 2, PIN5, PIN6);  
 *
 */  
void set_bits(volatile uint8_t *reg, uint8_t num, int first_bit, ...) 
{
	va_list pointer;	
	 
	*reg |= (1 << first_bit);	// Set the first pin
	
	// If there are more then one argument, the remaining pins must be 
	// set
	if (num >1) {
	
		va_start(pointer, first_bit);	// Initalize the arg pointer
		
		while((num-1) > 0)  {
			*reg |= (1 << va_arg(pointer, int));	// Set next pin
			num--;
		}
		va_end(pointer);
	}
}

/* Clear a variable amount of bits.
 * 	
 * *reg			-	The address of Port which includes the pins to clear
 *  num			- 	Number of pins which has to be clear
 *  first_bit	- 	Pins to clear as numbers from 0 - 7 
 *  				It has to be set at least one pin
 *
 * Example: clear_bits(&PORT_A, 1, PIN6);  
 *
 */  	
void clear_bits(volatile uint8_t *reg, uint8_t num, int first_bit, ...) 
{
	va_list pointer;
	
	*reg &= ~(1 << first_bit);	// Clear the first pin
	 
	// If there are more then one argument, the remaining pins must be
	// cleared 
	if (num >1) {
		
		va_start(pointer, first_bit);	
		
		while(num > 0)  {
			*reg &= ~(1 << va_arg(pointer, int));	// Clear next pin
			num--;
		}
		va_end(pointer);
	}
}
