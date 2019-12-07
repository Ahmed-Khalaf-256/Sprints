/*
 * gpio.c
 *
 *  Created on: Dec 3, 2019
 *      Author: Knight
 */

#include "std_types.h"
#include "registers.h"
#include "gpio.h"

/************************************************************************/
/*				 GPIO functions' defines	                            */
/************************************************************************/

/*===========================PORT Control===============================*/
/**
 * Description: set port value (which is DDR register)
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 * @param value: set the port value and takes the following values
 * 				- 0x00 -> Input
 * 				- 0xff -> Output
 */
void gpioPortDirection(uint8 port, uint8 direction) {
	/* Check on the Required PORT Number */
	switch (port) {
	case GPIOA:
		PORTA_DIR = direction;
		break;
	case GPIOB:
		PORTB_DIR = direction;
		break;
	case GPIOC:
		PORTC_DIR = direction;
		break;
	case GPIOD:
		PORTD_DIR = direction;
		break;
	default: /* Wrong Port Number */
		break;
	}
}

/**
 * Description: set the port value (which is PORT register)
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param value: set the port value and takes the following values
 * 				- 0x00 -> Low
 * 				- 0xff -> High
 */
void gpioPortWrite(uint8 port, uint8 value) {
	/* Check on the Required PORT Number */
	switch (port) {
	case GPIOA:
		PORTA_DATA = value;
		break;
	case GPIOB:
		PORTB_DATA = value;
		break;
	case GPIOC:
		PORTC_DATA = value;
		break;
	case GPIOD:
		PORTD_DATA = value;
		break;
	default:
		break;
		/* Wrong Port Number */
	}
}

/**
 * Description: toggle the port value (which is PORT register)
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 */
void gpioPortToggle(uint8 port) {
	/* Check on the Required PORT Number */
	switch (port) {
	case GPIOA:
		PORTA_DATA = ~PORTA_DATA;
		break;
	case GPIOB:
		PORTB_DATA = ~PORTB_DATA;
		break;
	case GPIOC:
		PORTC_DATA = ~PORTC_DATA;
		break;
	case GPIOD:
		PORTD_DATA = ~PORTD_DATA;
		break;
	default:
		break;
		/* Wrong Port Number */
	}
}

/**
 * Description: read the current port value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @return
 */
uint8 gpioPortRead(uint8 port) {
	uint8 PortRead = 0 ;
	switch (port) {
	case GPIOA:
		PortRead = PORTA_PIN;
		break;
	case GPIOB:
		PortRead = PORTB_PIN;
		break;
	case GPIOC:
		PortRead = PORTC_PIN;
		break;
	case GPIOD:
		PortRead = PORTD_PIN;
		break;
	default: /* Wrong Port Number */
		break;
	}
	return PortRead;
}

/*===========================PIN Control===============================*/
/**
 * Description: set selected pins (more than one pin [ORed]) direction
 *
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param pins: the selected pins the user need to set its direction and takes
 * 				any member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 *
 * @param direction: set the pins direction and takes the following values
 * 				- 0x00 -> Input
 * 				- 0xff -> Output
 */
void gpioPinDirection(uint8 port, uint8 pins, uint8 direction) {
	/* Check on the Required PORT Number */
	switch (port) {
	case GPIOA:
		ASSIGN_BIT(PORTA_DIR, pins, direction);
		break;
	case GPIOB:
		ASSIGN_BIT(PORTB_DIR, pins, direction);
		break;
	case GPIOC:
		ASSIGN_BIT(PORTC_DIR, pins, direction);
		break;
	case GPIOD:
		ASSIGN_BIT(PORTD_DIR, pins, direction);
		break;
	default: /* Wrong Port Number */
		break;
	}
}

/**
 * Description: set selected pins (more than one pin [ORed]) values
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param pins: the selected pins the user need to write its values and takes
 * 				any member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 * @param value
 */
void gpioPinWrite(uint8 port, uint8 pins, uint8 value) {
	/* Check on the Required PORT Number */
	switch (port) {
	case GPIOA:
		ASSIGN_BIT(PORTA_DATA, pins, value);
		break;
	case GPIOB:
		ASSIGN_BIT(PORTB_DATA, pins, value);
		break;
	case GPIOC:
		ASSIGN_BIT(PORTC_DATA, pins, value);
		break;
	case GPIOD:
		ASSIGN_BIT(PORTD_DATA, pins, value);
		break;
	default: /* Wrong Port Number */
		break;
	}
}

/**
 * Description: toggle selected pin (only one pin) direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param pins: the selected pin the user need to toggle it's value and takes
 * 				only one member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 */
void gpioPinToggle(uint8 port, uint8 pins){
	/* Check on the Required PORT Number */
		switch (port) {
		case GPIOA:
			TOGGLE_BIT(PORTA_DATA,pins);
			break;
		case GPIOB:
			TOGGLE_BIT(PORTB_DATA,pins);
			break;
		case GPIOC:
			TOGGLE_BIT(PORTC_DATA,pins);
			break;
		case GPIOD:
			TOGGLE_BIT(PORTD_DATA,pins);
			break;
		default: /* Wrong Port Number */
			break;
		}
}


/**
 * Description: read selected pin (only one pin) direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 * @param pin: the selected pin the user need to read it's value and takes
 * 				only one member from the enum EN_bits:
 * 				- BIT0
 * 				- BIT1
 * 				- BIT2
 * 				- BIT3
 * 				- BIT4
 * 				- BIT5
 * 				- BIT6
 * 				- BIT7
 * @return
 */
uint8 gpioPinRead(uint8 port, uint8 pin) {
	uint8 u8PinValue = 0 ;
	/* Check on the Required PORT Number */
	switch (port) {
	case GPIOA:
		u8PinValue = GET_BIT(PORTA_PIN, pin);
		break;
	case GPIOB:
		u8PinValue = GET_BIT(PORTB_PIN, pin);
		break;
	case GPIOC:
		u8PinValue = GET_BIT(PORTC_PIN, pin);
		break;
	case GPIOD:
		u8PinValue = GET_BIT(PORTD_PIN, pin);
		break;
	default: /* Wrong Port Number */
		break;
	}
	return u8PinValue;
}

/*===========================Upper Nibble Control===============================*/
/**
 * Description: set the upper nibble direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param direction
 */
void gpioUpperNibbleDirection(uint8 port, uint8 direction) {
	uint8 Mask = 0xF0;
	direction &= Mask;
	/* Check on the Required PORT Number */
	switch (port) {
	case GPIOA:
		PORTA_DIR &= ~Mask;
		PORTA_DIR |= direction;
		break;
	case GPIOB:
		PORTB_DIR &= ~Mask;
		PORTB_DIR |= direction;
		break;
	case GPIOC:
		PORTC_DIR &= ~Mask;
		PORTC_DIR |= direction;
		break;
	case GPIOD:
		PORTD_DIR &= ~Mask;
		PORTD_DIR |= direction;
		break;
	default: /* Wrong Port Number */
		break;
	}
}

/**
 * Description: write the upper nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param value
 */
void gpioUpperNibbleWrite(uint8 port, uint8 value) {
	uint8 Mask = 0xF0;
	value &= Mask;
	/* Check on the Required PORT Number */
	switch (port) {
	case GPIOA:
		PORTA_DATA &= ~Mask;
		PORTA_DATA |= value;
		break;
	case GPIOB:
		PORTB_DATA &= ~Mask;
		PORTB_DATA |= value;
		break;
	case GPIOC:
		PORTC_DATA &= ~Mask;
		PORTC_DATA |= value;
		break;
	case GPIOD:
		PORTD_DATA &= ~Mask;
		PORTD_DATA |= value;
		break;
	default: /* Wrong Port Number */
		break;
	}
}

/**
 * Description: toggle the upper nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 */
void gpioUpperNibbleToggle(uint8 port) {
	uint8 Mask = 0xF0;
	/* Check on the Required PORT Number */
	switch (port) {
	case GPIOA:
		PORTA_DATA ^= Mask;
		break;
	case GPIOB:
		PORTB_DATA ^= Mask;
		break;
	case GPIOC:
		PORTC_DATA ^= Mask;
		break;
	case GPIOD:
		PORTD_DATA ^= Mask;
		break;
	default: /* Wrong Port Number */
		break;
	}
}

/**
 * Description: read the upper nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @return
 */
uint8 gpioUpperNibbleRead(uint8 port) {
	uint8 Mask = 0xF0, NibbleValue = 0;
	/* Check on the Required PORT Number */
	switch (port) {
	case GPIOA:
		NibbleValue = (PORTA_PIN & Mask);
		break;
	case GPIOB:
		NibbleValue = (PORTB_PIN & Mask);
		break;
	case GPIOC:
		NibbleValue = (PORTC_PIN & Mask);
		break;
	case GPIOD:
		NibbleValue = (PORTD_PIN & Mask);
		break;
	default: /* Wrong Port Number */
		break;
	}
	return NibbleValue;
}

/*===========================Lower Nibble Control===============================*/
/**
 * Description: set the lower nibble direction
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 * @param direction
 */
void gpioLowerNibbleDirection(uint8 port, uint8 direction){
	uint8 Mask = 0x0F;
		direction &= Mask;
		/* Check on the Required PORT Number */
		switch (port) {
		case GPIOA:
			PORTA_DIR &= ~Mask;
			PORTA_DIR |= direction;
			break;
		case GPIOB:
			PORTB_DIR &= ~Mask;
			PORTB_DIR |= direction;
			break;
		case GPIOC:
			PORTC_DIR &= ~Mask;
			PORTC_DIR |= direction;
			break;
		case GPIOD:
			PORTD_DIR &= ~Mask;
			PORTD_DIR |= direction;
			break;
		default: /* Wrong Port Number */
			break;
		}
}

/**
 * Description: write the lower nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @param value
 */
void gpioLowerNibbleWrite(uint8 port, uint8 value){
	uint8 Mask = 0x0F;
	value &= Mask;
	/* Check on the Required PORT Number */
	switch (port) {
	case GPIOA:
		PORTA_DATA &= ~Mask;
		PORTA_DATA |= value;
		break;
	case GPIOB:
		PORTB_DATA &= ~Mask;
		PORTB_DATA |= value;
		break;
	case GPIOC:
		PORTC_DATA &= ~Mask;
		PORTC_DATA |= value;
		break;
	case GPIOD:
		PORTD_DATA &= ~Mask;
		PORTD_DATA |= value;
		break;
	default: /* Wrong Port Number */
		break;
	}
}

/**
 * Description: toggle the lower nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 *
 */
void gpioLowerNibbleToggle(uint8 port){
	uint8 Mask = 0x0F;
		/* Check on the Required PORT Number */
		switch (port) {
		case GPIOA:
			PORTA_DATA ^= Mask;
			break;
		case GPIOB:
			PORTB_DATA ^= Mask;
			break;
		case GPIOC:
			PORTC_DATA ^= Mask;
			break;
		case GPIOD:
			PORTD_DATA ^= Mask;
			break;
		default: /* Wrong Port Number */
			break;
		}
}

/**
 * Description: read the lower nibble value
 * @param port: portID and takes the following values
 * 				- 0 -> GPIOA
 * 				- 1 -> GPIOB
 * 				- 2 -> GPIOC
 * 				- 3 -> GPIOD
 * @return
 */
uint8 gpioLowerNibbleRead(uint8 port){
	uint8 Mask = 0x0F, NibbleValue = 0;
		/* Check on the Required PORT Number */
		switch (port) {
		case GPIOA:
			NibbleValue = (PORTA_PIN & Mask);
			break;
		case GPIOB:
			NibbleValue = (PORTB_PIN & Mask);
			break;
		case GPIOC:
			NibbleValue = (PORTC_PIN & Mask);
			break;
		case GPIOD:
			NibbleValue = (PORTD_PIN & Mask);
			break;
		default: /* Wrong Port Number */
			break;
		}
		return NibbleValue;
}
