/// atmel_io_control.h /// Author: MarvinNStelljes ///
/* Helper functions to manipulate input and output pins.
 * Supported microcontrollers:	atmega328p
 */

#include <stdint.h>

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
extern void set_bits(volatile uint8_t *reg, uint8_t num, int first_bit, ...);

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
extern void clear_bits(volatile uint8_t *reg, uint8_t num, int first_bit, ...);
