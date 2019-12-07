/*
 * main.c
 *
 *  Created on: Dec 3, 2019
 *      Author: Knight
 */
#include "std_types.h"
#include "gpio.h"
//#include "softwareDelay.h"
#include "timers.h"
#include "pushButton.h"
#include "led.h"

#define REQ6	6
#define REQ7	7
#define REQ9	9
#define REQ		REQ6	/* choose a req then compile */

int main(void) {

	uint8 PBstatus, led = 0, counter = 0;
	//gpioPortDirection(GPIOB, OUTPUT);
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);
	pushButton_Init(BTN_1);
//	timer0Init(T0_NORMAL_MODE, T0_OC0_DIS, T0_PRESCALER_64, FALSE, FALSE,
//			T0_POLLING);
	while (TRUE) {

		// REQ6
#if (REQ==REQ6)

		PBstatus = pushButton_GetStatus(BTN_1); // delay 50ms
		while (PBstatus != Pressed) {
			Led_Off(LED_1);
			PBstatus = pushButton_GetStatus(BTN_1); // delay 50ms
		}
		Led_On(LED_1);
		for (counter = 10; counter > 0; counter--) {
			timer0Delay_ms(50);
			PBstatus = pushButton_GetStatus(BTN_1); // delay 50ms
			if (PBstatus == Pressed) {
				counter += 10;
			}
		}

		// REQ7
#elif (REQ==REQ7)

		switch (led) {
			case 0:
			Led_Off(LED_3);
			Led_On(LED_1);
			led = 1;
			break;
			case 1:
			Led_Off(LED_1);
			Led_On(LED_2);
			led = 2;
			break;
			case 2:
			Led_Off(LED_2);
			Led_On(LED_3);
			led = 0;
			break;
			default: /* error */
			break;
		}
		timer0Delay_ms(1000);

#elif (REQ==REQ9)

		switch (led) {
		case 0:				//STOP
			Led_Off(LED_3);
			Led_On(LED_1);
			led = 1;
			break;
		case 1:				//GET READY
			Led_Off(LED_1);
			Led_On(LED_2);
			led = 2;
			break;
		case 2:				//GO
			Led_Off(LED_2);
			Led_On(LED_3);
			led = 0;
			break;
		default: /* error */
			break;
		}
		for (counter = 10; counter > 0; counter--) {
			timer0Delay_ms(50);
			PBstatus = pushButton_GetStatus(BTN_1); // delay 50ms
			if (PBstatus == Pressed) {
				led = 0;
			}
		}
#endif
	}

	return 0;
}

/*
 ISR();
 void __vector_6(void) __attribute__ ((signal, INTR_ATTRS)); //or((signal, INTR_ATTRS))
 void __vector_6(void) {
 */
