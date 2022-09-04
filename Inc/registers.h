/*
 * registers.h
 *
 *  Created on: Aug 23, 2022
 *      Author: mars
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

typedef struct _RCC {
	uint32_t RCC_CR;
	uint32_t RCC_CFGR;
	uint32_t RCC_CIR;
	uint32_t RCC_APB2RSTR;
	uint32_t RCC_APB1RSTR;
	uint32_t RCC_AHBENER;
	uint32_t RCC_APB2ENR;
	uint32_t RCC_APB1ENR;
	uint32_t RCC_BDCR;
	uint32_t RCC_CSR;
	uint32_t RCC_AHBRSTR;
	uint32_t RCC_CFGR2;
	uint32_t RCC_CFGR3;
}RCCRegs;

typedef struct _Mode {
	uint32_t GPIOx_MODER;
	uint32_t GPIOx_OTYPER;
	uint32_t GPIOx_OSPEEDR;
	uint32_t GPIOx_PUPDR;
	uint32_t GPIOx_IDR;
	uint32_t GPIOx_ODR;
	uint32_t GPIOx_BSRR;
	uint32_t GPIOx_LCKR;
	uint32_t GPIOx_AFRL;
	uint32_t GPIOx_AFRH;
	uint32_t GPIOx_BRR;
}ModeRegs;

#define RCC1		((RCCRegs*) 0x40021000)
#define Mode1		((ModeRegs*) 0x48000000)
#define USART		((USARTReg*) 0x40004400)


#endif /* REGISTERS_H_ */
