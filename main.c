#include <stdint.h>
#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>

#include "LEDs.h"
#include "delayTimer.h"
#include "ultrasonic.h"
#include "UART.h"
#include "pushButton.h"



TaskHandle_t taskHandle = NULL;


void task(void *params);


int main1()
{

	
	xTaskCreate(task, "task", 1000, NULL, 1, &taskHandle);
 	
	
	vTaskStartScheduler();	
	
	
	for (;;);
	
}

void task(void *params)
{
	while(1);
}


