/*
 * usart.h
 *
 *  Created on: Aug 23, 2022
 *      Author: marei
 */
#include "registers.h"

#ifndef USART_H_
#define USART_H_

typedef struct _USART {
	uint32_t USART_CR1;
	uint32_t USART_CR2;
	uint32_t USART_CR3;
	uint32_t USART_BRR;
	uint32_t USART_GTPR;
	uint32_t USART_RTOR;
	uint32_t USART_RQR;
	uint32_t USART_ISR;
	uint32_t USART_ICR;
	uint32_t USART_RDR;
	uint32_t USART_TDR;
}USARTReg;

#define RCC			((RCCRegs*) 0x40021000)
#define Mode		((ModeRegs*) 0x48000000)
#define USART2		((USARTReg*) 0x40004400)

void usart2_tx_init(void);
void usart2_write(int data);


#endif /* USART_H_ */
