/*
 * usart.c
 *
 *  Created on: Aug 23, 2022
 *      Author: marei
 */
#include <stdio.h>
#include "usart.h"
#include "registers.h"

static uint16_t uart_baud_rate(uint32_t periphClk, uint32_t baudRate) {
	return (periphClk + (baudRate / 2) / baudRate);
}

void usart2_tx_init(void) {
	/*First configuring alternate functions at PA2*/
	uint32_t APB1_CLK = 16000000;
	uint32_t UART_BAUDRATE = 115200;

	RCC -> RCC_AHBENER = 1 << 17;

	Mode -> GPIOx_MODER &= ~(1U << 4);
	Mode -> GPIOx_MODER |= 2 << 4;

	Mode -> GPIOx_AFRL = 7 << 8;

	/*Now configure the UART module itself */
	RCC -> RCC_APB1ENR = 1 << 17;
	USART2 -> USART_BRR = uart_baud_rate(APB1_CLK, UART_BAUDRATE);
	USART2 -> USART_CR1 = 1 << 3;
	USART2 -> USART_CR1 |= 1 << 0;
}

void usart2_write(int data) {
	while(!(USART2 -> USART_ISR & (1U << 7))){}
	USART -> USART_TDR = data;
}
