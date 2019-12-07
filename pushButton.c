/*
 * pushButton.c
 *
 *  Created on: Dec 5, 2019
 *      Author: Knight
 */

#include "pushButton.h"

static uint8 BTNstatus[4];

/**
 * Description: Initialize the BTN_x Pin state (where x 0, 1, 2, 3) to Input
 * @param btn_id: The btn to be initialized and it takes
 * 				  one of the enum (En_buttonId) parameters
 *
 */
void pushButton_Init(En_buttonId btn_id) {
	switch (btn_id) {
	case BTN_0:
		gpioPinDirection(BTN_0_GPIO, BTN_0_BIT, INPUT);
		break;
	case BTN_1:
		gpioPinDirection(BTN_1_GPIO, BTN_1_BIT, INPUT);
		break;
	case BTN_2:
		gpioPinDirection(BTN_2_GPIO, BTN_2_BIT, INPUT);
		break;
	case BTN_3:
		gpioPinDirection(BTN_3_GPIO, BTN_3_BIT, INPUT);
		break;
	default:
		break;
	}
}
/**
 * Description: read all BTN_x (where x 0, 1, 2, 3) states and store it in the program
 *
 * @note : this function must be called in the system tick hundler or in the super loop hundler
 */
void pushButton_Update(void) {
	uint8 BTN[4];

	/*
	 * Push Button 0 status update
	 */
	BTNstatus[0] = gpioPinRead(BTN_0_GPIO, BTN_0_BIT);
	timer0Delay_ms(30);
	BTN[0] = gpioPinRead(BTN_0_GPIO, BTN_0_BIT);
	if (BTNstatus[0] == HIGH && BTN[0] == HIGH) {
		BTNstatus[0] = Pressed;
	} else if (BTNstatus[0] == LOW && BTN[0] == LOW) {
		BTNstatus[0] = Released;
	} else if (BTNstatus[0] == LOW && BTN[0] == HIGH) {
		BTNstatus[0] = Prepressed;
	} else if (BTNstatus[0] == HIGH && BTN[0] == LOW) {
		BTNstatus[0] = Prereleased;
	} else {
		/* error */
	}

	/*
	 * Push Button 1 status update
	 */
	BTNstatus[1] = gpioPinRead(BTN_1_GPIO, BTN_1_BIT);
	timer0Delay_ms(30);
	BTN[1] = gpioPinRead(BTN_1_GPIO, BTN_1_BIT);
	if (BTNstatus[1] == HIGH && BTN[1] == HIGH) {
		BTNstatus[1] = Pressed;
	} else if (BTNstatus[1] == LOW && BTN[1] == LOW) {
		BTNstatus[1] = Released;
	} else if (BTNstatus[1] == LOW && BTN[1] == HIGH) {
		BTNstatus[1] = Prepressed;
	} else if (BTNstatus[1] == HIGH && BTN[1] == LOW) {
		BTNstatus[1] = Prereleased;
	} else {
		/* error */
	}

	/*
	 * Push Button 2 status update
	 */
	BTNstatus[2] = gpioPinRead(BTN_2_GPIO, BTN_2_BIT);
	timer0Delay_ms(30);
	BTN[2] = gpioPinRead(BTN_2_GPIO, BTN_2_BIT);
	if (BTNstatus[2] == HIGH && BTN[2] == HIGH) {
		BTNstatus[2] = Pressed;
	} else if (BTNstatus[2] == LOW && BTN[2] == LOW) {
		BTNstatus[2] = Released;
	} else if (BTNstatus[2] == LOW && BTN[2] == HIGH) {
		BTNstatus[2] = Prepressed;
	} else if (BTNstatus[2] == HIGH && BTN[2] == LOW) {
		BTNstatus[2] = Prereleased;
	} else {
		/* error */
	}

	/*
	 * Push Button 3 status update
	 */
	BTNstatus[3] = gpioPinRead(BTN_3_GPIO, BTN_3_BIT);
	timer0Delay_ms(50);
	BTN[3] = gpioPinRead(BTN_3_GPIO, BTN_3_BIT);
	if (BTNstatus[3] == HIGH && BTN[3] == HIGH) {
		BTNstatus[3] = Pressed;
	} else if (BTNstatus[3] == LOW && BTN[3] == LOW) {
		BTNstatus[3] = Released;
	} else if (BTNstatus[3] == LOW && BTN[3] == HIGH) {
		BTNstatus[3] = Prepressed;
	} else if (BTNstatus[3] == HIGH && BTN[3] == LOW) {
		BTNstatus[3] = Prereleased;
	} else {
		/* error */
	}

}
/**
 * Description: read BTN_x (where x 0, 1, 2, 3) state which is stored in the program
 * 				in the update function
 *
 */
En_buttonStatus_t pushButton_GetStatus(En_buttonId btn_id) {
	pushButton_Update(); 			// untill we use it in OS
	uint8 btnStatus = BTN_MAX_NUM; // check if it's updated or not
	switch (btn_id) {
	case BTN_0:
		btnStatus = BTNstatus[0];
		break;
	case BTN_1:
		btnStatus = BTNstatus[1];
		break;
	case BTN_2:
		btnStatus = BTNstatus[2];
		break;
	case BTN_3:
		btnStatus = BTNstatus[3];
		break;
	default:
		/* error */
		break;
	}
	return btnStatus ;
}

