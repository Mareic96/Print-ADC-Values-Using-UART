/*
 * adc.c
 *
 *  Created on: 27 Aug 2022
 *      Author: mars
 *
 * Activating the analog to digital converter channel 4 (ADC_IN4) on PA3 and return the value
 */
#include <stdio.h>
#include "adc.h"
#include "registers.h"

/* Initialise the ADC module */
void adc_init(void) {
	/* First activate clock control for GPIOA, ADC_IN4 is an additional function of PA3 */
	RCC1 -> RCC_AHBENER |= (1U << 17); // GPIOA sits on the AHB (Advance High Performance Bus)
	Mode1 -> GPIOx_MODER |= (3U << 6); // Configuring pin3 to be analog mode

	/* Now the ADC can be configured */
	RCC1 -> RCC_AHBENER |= (1U << 28); // Enable reset clock control for ADC12EN

	/* Need to specify the clock speed, this will be half the main CPU clock */
	ADC12_common -> ADCx_CCR &= ~(3U << 16);
	ADC12_common -> ADCx_CCR |= (2U << 16);

	ADC1_CFGR -> EXTEN = 0; // Using software trigger - Meaning the conversion will start when we specify
	ADC1_CFGR -> CONT = 1; // Conversion mode - 1 for continuous and 0 for single conversion
	ADC1_SQR1 -> L = 0; // Number of channels - In this case, we are using only using a single channel
	ADC1_SQR1 -> SQ1 = 4; // Channel number and order - Using ADC1_IN4 and should be the first channel to return a value
}

/* Enable the ADC voltage regulator, by setting ADVREGEN to 0 then 01 and enable the ADC */
void activate_adc(void) {
	ADC1_CR -> ADVREGEN = 0;
	ADC1_CR -> ADVREGEN = 1;

	ADC1_CR -> ADEN = 1;

}

/* Start conversion */
void start_conversion(void) {
	ADC1_CR -> ADSTART = 1;
}

/* Read the ADC data register */
uint32_t adc_read(void) {
	return (ADC1_DR -> RDATA);
}


