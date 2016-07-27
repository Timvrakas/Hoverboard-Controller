#include <stdio.h>
#include <stdlib.h>
#include "stm32f10x_conf.h"
//#include "stm32f10x.h"

DAC_InitTypeDef DAC_InitStructure;

int main() {

	GPIO_InitTypeDef GPIO_Blink_InitStructure;
	GPIO_Blink_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_Blink_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Blink_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Blink_InitStructure);

	enableBuzzer(1000);

	while (1) {

		setTone(2000, 255);

		setTone(3000, 255);

		setTone(4000, 255);

		setTone(5000, 255);

	}
}

