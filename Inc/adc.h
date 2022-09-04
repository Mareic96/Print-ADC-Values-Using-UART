/*
 * adc.h
 *
 *  Created on: 27 Aug 2022
 *      Author: mars
 */

#ifndef ADC_H_
#define ADC_H_

#include <stdio.h>
#include <stdint.h>

typedef struct _ADCCR {
	uint32_t volatile ADEN		: 1;
	uint32_t volatile ADDIS		: 1;
	uint32_t volatile ADSTART	: 1;
	uint32_t volatile JADSTART	: 1;
	uint32_t volatile ADSTP		: 1;
	uint32_t volatile JADSTP	: 1;
	uint32_t volatile Res		: 22;
	uint32_t volatile ADVREGEN	: 2;
	uint32_t volatile ADCALDIF	: 1;
	uint32_t volatile ADCAL		: 1;
}ADCx_CR;

typedef struct _ADCCFGR {
	uint32_t volatile DMAEN		: 1;
	uint32_t volatile DMACFG	: 1;
	uint32_t volatile Res1		: 1;
	uint32_t volatile RES		: 2;
	uint32_t volatile ALIGN		: 1;
	uint32_t volatile EXTSEL	: 4;
	uint32_t volatile EXTEN		: 2;
	uint32_t volatile OVRMOD	: 1;
	uint32_t volatile CONT		: 1;
	uint32_t volatile AUTDLY	: 1;
	uint32_t volatile Res2		: 1;
	uint32_t volatile DISCEN	: 1;
	uint32_t volatile DISCNUM	: 3;
	uint32_t volatile JDISCEN	: 1;
	uint32_t volatile JQM		: 1;
	uint32_t volatile AWD1SGL	: 1;
	uint32_t volatile AWD1EN	: 1;
	uint32_t volatile JAUTO		: 1;
	uint32_t volatile AWD1CH	: 5;
	uint32_t volatile Res3		: 1;
}ADCx_CFGR;

typedef struct _ADCSQR1 {
	uint32_t volatile L		: 4;
	uint32_t volatile Res1	: 2;
	uint32_t volatile SQ1	: 5;
	uint32_t volatile Res2	: 1;
	uint32_t volatile SQ2	: 5;
	uint32_t volatile Res3	: 1;
	uint32_t volatile SQ3	: 5;
	uint32_t volatile Res4	: 1;
	uint32_t volatile SQ4	: 5;
	uint32_t volatile Res5	: 3;
}ADCx_SQR1;

typedef struct _ADCDR {
	uint32_t volatile RDATA	: 16;
	uint32_t volatile Res	: 16;
}ADCx_DR;

typedef struct _ADC_Common {
	uint32_t volatile ADCx_CSR;
	uint32_t volatile RESERVED;
	uint32_t volatile ADCx_CCR;
	uint32_t volatile ADCx_CDR;
}ADCCommonReg;

#define ADC12_common	((ADCCommonReg*) 0x50000300)
#define ADC1_CFGR		((ADCx_CFGR*) 0x5000000C)
#define ADC1_SQR1		((ADCx_SQR1*) 0x50000030)
#define ADC1_CR			((ADCx_CR*) 0x50000008)
#define ADC1_DR			((ADCx_DR*) 0x50000040)

void adc_init(void);
void activate_adc(void);
void start_conversion(void);
uint32_t adc_read(void);



#endif /* ADC_H_ */
