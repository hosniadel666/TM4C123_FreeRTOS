/**************************************************
*		Test led task and ultrasonic task
*************************************************/
#include <stdint.h>
#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>

#include "LEDs.h"
#include "delayTimer.h"
#include "ultrasonic.h"
#include "UART.h"


TaskHandle_t ledTaskHandle = NULL;
TaskHandle_t ultrasoniTaskHandle = NULL;
char str[30];




void ledTask(void *params);
void ultrasoniTask(void *params);

int main()
{

	
	xTaskCreate(ultrasoniTask, "ultrasoniTask", 1000, NULL, 1, &ultrasoniTaskHandle);
 	xTaskCreate(ledTask, "ledTask", configMINIMAL_STACK_SIZE, NULL, 1, &ledTaskHandle);
 	
	
	vTaskStartScheduler();	
	
	
	for (;;);
	
}

void ultrasoniTask(void *params)
{

	float distance;
	ultrasonicPFConfig x;
	
	x.ECHO = 0x40;			// pin PF6
	x.TRIG = 0x80;			// pin PF7
	
	ultrasonic_init(x);

	while(1)
	{	
		distance = ultrasonic_measure();

		sprintf(str,"distance: %f cm \n\r", distance);
		printMsg(str);
	}

}

void ledTask(void *params)
{
	LEDs ledR;
	
	ledR = RED;
	
	LEDs_init(ledR);

	while(1)
	{
		LED_ON(ledR);
		vTaskDelay(500);
		LED_OFF(ledR);
		vTaskDelay(500);
	}

}
