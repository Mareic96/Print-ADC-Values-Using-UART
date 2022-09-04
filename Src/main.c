#include <stdio.h>
#include <stdint.h>
#include "usart.h"
#include "adc.h"

int __io_putchar(int ch) {
	usart2_write(ch);
	return ch;
}

void pseudo_delay(void) {
	int x = 0;
	for(int i = 0; i < 90000; ++i) {
		x++;
	}
}

uint32_t sensor_value1;
int main(void)
{
	usart2_tx_init();

	adc_init();
	activate_adc();

	pseudo_delay();

	start_conversion();
	while(1) {
		//usart2_write('A');
		printf("The number is %lu\n\r", adc_read());
		//sensor_value1 = adc_read();
	}
	return 0;
}
