#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t segment_vals[10] = {
	0b10111111, // ZERO
	0b00000110, // ONE
	0b01011011, // TWO
	0b01001111, // THREE
	0b01100110, // FOUR
	0b01101101, // FIVE
	0b11111101, // SIX
	0b00000111, // SEVEN
	0b11111111, // EIGHT
	0b11101111  // NINE
};

int main(void)
{
	DDRB = 0xFF;
	DDRD = 0xFF;
	
	while (1)
	{
		for(uint8_t i = 0; i < 10; i++)
		{
			PORTB = segment_vals[i];
			PORTD = (1 << i) - 1;
			_delay_ms(500);
		}
	}
}
