/*
 * delay.c
 *
 * Created: 11/28/2023 12:57:30 PM
 * Author : Dell
 */ 

#include <avr/io.h>

// Custom delay function
void delay_ms(uint32_t milliseconds) {
	

	// Nested loop for delay
	for (uint32_t i = 0; i < milliseconds; i++) {
		for (uint32_t j = 0; j < 250; j++) {
			// Do nothing, just waste some time
		}
	}
}

int main() {
	// Configure a GPIO pin as an output
	DDRB |= (1 << PB0);

	while (1) {
		// Toggle the GPIO pin
		PORTB |= (1 << PB0);

		// Delay for 1000 milliseconds
		delay_ms(1000);
		PORTB &= ~(1<< PB0);
		delay_ms(1000);
	}

	return 0;
}