/*
 * timers.c
 *
 *  Created on: Dec 7, 2019
 *      Author: Knight
 */
#include "std_types.h"
#include "timers.h"

static uint8 gu8_Prescaler;

/*===========================Timer0 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer0Init(En_timer0Mode_t mode, En_timer0OC_t OC0,
		En_timer0perscaler_t prescal, uint8 initialValue, uint8 outputCompare,
		uint8 interruptMask) {

	/* set T0 mode */
	if (mode == T0_NORMAL_MODE || mode == T0_COMP_MODE) {
		TCCR0 |= mode;
	} else {
		/* error */
	}
	if (mode == T0_COMP_MODE) {
		/* set T0 compare mode */
		if (OC0 == T0_OC0_DIS || OC0 == T0_OC0_TOGGLE || OC0 == T0_OC0_CLEAR
				|| OC0 == T0_OC0_SET) {
			TCCR0 |= OC0;
		} else {
			/* error */
		}
	} else {
		/* error */
	}
	/* set T0 prescaler */
	if (prescal >= 0 && prescal <= 0x05) {
		gu8_Prescaler = prescal;
	} else {
		/* error */
	}
	/* set T0 initial Value */
	if (initialValue >= 0 && initialValue <= 0xFF) {
		TCNT0 |= initialValue;
	} else {
		/* error */
	}
	/* set T0 output Compare */
	if (outputCompare >= 0 && outputCompare <= 0xFF) {
		OCR0 |= outputCompare;
	} else {
		/* error */
	}
	/* set T0 mode */
	if (interruptMask == T0_POLLING || interruptMask == T0_INTERRUPT_NORMAL
			|| interruptMask == T0_INTERRUPT_CMP) {
		TIMSK |= mode;
	} else {
		/* error */
	}

}

/**
 * Description:
 * @param value
 */
void timer0Set(uint8 value) {
	/* set T0 initial Value */
	if (value >= 0 && value <= 0xFF) {
		TCNT0 |= value;
	} else {
		/* error */
	}
}

/**
 * Description:
 * @return
 */
uint8 timer0Read(void) {
	//uint8 value;
	/* read T0 initial Value */
	return TCNT0;
}

/**
 * Description:
 */
void timer0Start(void) {
	/* start T0 with prescaler */
	TCNT0 |= gu8_Prescaler;
}

/**
 * Description:
 */
void timer0Stop(void) {
	/* stop T0 by removing prescaler */
	TCNT0 |= T0_NO_CLOCK;
}

/**
 * Description:
 * @param delay
 */
void timer0Delay_ms(uint16 delay) {
	uint16 u16_counter;
	/* osc 8MHz and 46 prescaler >> (1/125)us for 1 tick time */
	//timer0Init(T0_NORMAL_MODE, T0_OC0_DIS, T0_PRESCALER_64, 0, 0, T0_POLLING);
		TCCR0 |= T0_NORMAL_MODE|T0_OC0_DIS|T0_PRESCALER_64;
	for (u16_counter = 0; u16_counter < delay; u16_counter++) {
		timer0Set(5); //255-125
		timer0Start();
//		while (!GET_BIT(TIFR, BIT0));	//	read OV flag
//		SET_BIT(TIFR, BIT0);		//	clear OV flag
	while(!(TIFR & (BIT0)));
	TIFR |= BIT0;
	}
	timer0Stop();
}

/**
 * Description:
 * @param dutyCycle
 */
void timer0SwPWM(uint8 dutyCycle, uint8 freq) {

}

