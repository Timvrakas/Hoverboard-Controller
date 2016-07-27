//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

#include <Buzzer.h>
#include "stm32f10x_conf.h"
#include "stm32f10x.h"

void enableBuzzer(long freq) {

	//enable timers
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	//disable GPIO
	GPIO_InitTypeDef GPIO_DAC_Struct;
	GPIO_DAC_Struct.GPIO_Pin = GPIO_Pin_4;
	GPIO_DAC_Struct.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_DAC_Struct);

	//enable DAC
	DAC_InitTypeDef DAC_InitStruct;
	DAC_InitStruct.DAC_Trigger = DAC_Trigger_Software;
	DAC_InitStruct.DAC_WaveGeneration = DAC_WaveGeneration_None;
	DAC_InitStruct.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
	DAC_Init(DAC_Channel_1, &DAC_InitStruct);
	DAC_Cmd(DAC_Channel_1, ENABLE);

	//set DAC to 0
	DAC_SetChannel1Data(DAC_Align_8b_R, 0);

	//enable buzzer
	i = 0;
	volume = 255;
	SysTick_Config(SystemCoreClock / (freq * volume));

}

void setTone(long freq, int newVolume) {
	volume = newVolume;
	SysTick_Config(SystemCoreClock / (freq * volume));
}

void endTone(void) {
	SysTick_Config(0);
}

void SysTick_Handler(void) {
	DAC_SetChannel1Data(DAC_Align_8b_R, i);
	DAC_SoftwareTriggerCmd(DAC_Channel_1, ENABLE);
	i++;
	if (i >= volume)
		i = 0;
}

