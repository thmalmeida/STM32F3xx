/*
 * timers.c
 *
 *  Created on: 2 de abr de 2016
 *      Author: titi
 */

#include "timers.h"

void init_SysTick(void)
{
	SysTick->LOAD  = 9;
	NVIC_SetPriority(SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);
	SysTick->CTRL  = SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}
void delay_us(int micro)
{
	time_us = micro;
	while(time_us>0);
}
void delay_ms(int milli)
{
	time_ms = milli*100;
	while(time_ms>0);
}
void init_TIM(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	/* TIM3 clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	/* Enable the TIM3 gloabal Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Initialize Leds mounted on STM32F3-Discovery EVAL board */
	STM_EVAL_LEDInit(LED3);
	STM_EVAL_LEDInit(LED4);
	STM_EVAL_LEDInit(LED5);
	STM_EVAL_LEDInit(LED6);

///*	TIM1_CR1:
//				9:8		CKD[1:0]
//				7		ARPE
//				6:5		CMS[1:0]
//				4		DIR
//				3		OPM
//				2		URS
//				1		UDIS
//				0		CEN
//*/
//	TIM3 -> CR1 |=  TIM_CR1_CEN;		// TIM1 Counter Enable;
	TIM3 -> CR1 &= ~TIM_CR1_DIR;		// Upconting mode DIR = 0;
//	TIM3 -> CR1 |=  TIM_CKD_DIV1;
//
///*	TIM1_SMCR:
//				15		ETP
//				7
//				2:0		SMS[2:0]
//*/
	TIM3 -> SMCR &= ~TIM_SMCR_SMS;		// Internal clock select;
//
///*	TIM1_DIER: DMA/interrupt enable register
//				14		TDE	- Trigger DMA request enable
//				8		UDE
//				6		TIE
//				0		UIE	- Uptade Interrupt enable
//*/
//	TIM1 -> DIER |= TIM_DIER_UIE;
//
	TIM3 -> ARR = 36000;	// Set TIM_Period;

/* Compute the prescaler value */
//	PrescalerValue = (uint16_t) 100*((SystemCoreClock)/72000000);

/* Time base configuration */
//	TIM_TimeBaseStructure.TIM_Period = 65535;
//	TIM_TimeBaseStructure.TIM_Prescaler = 0;
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//
//	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

/* Prescaler configuration */
//	TIM_PrescalerConfig(TIM3, PrescalerValue, TIM_PSCReloadMode_Immediate);
	TIM3->PSC = 2000;							// Set TIM_Prescaler;
	TIM3->EGR = TIM_PSCReloadMode_Immediate;	// Set or reset the UG Bit

/* Output Compare Timing Mode configuration: Channel1 */
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
//	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Disable);

/* Output Compare Timing Mode configuration: Channel2 */
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_Pulse = CCR2_Val;
//	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
//	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Disable);

/* Output Compare Timing Mode configuration: Channel3 */
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_Pulse = CCR3_Val;
//	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
//	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Disable);

	/* Output Compare Timing Mode configuration: Channel 4 */
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_Pulse = CCR4_Val;
//	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
//	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Disable);

/* TIM Interrupts enable */
//	TIM_ITConfig(TIM3, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4, ENABLE);
	TIM3 -> DIER |= TIM_IT_CC4;

	/* TIM3 enable counter */
//	TIM_Cmd(TIM3, ENABLE);
	TIM3 -> CR1 |=  TIM_CR1_CEN;		// TIM1 Counter Enable;

	/* Turn on LED3, LED4, LED5 and LED6 */
//  STM_EVAL_LEDOn(LED3);
//  STM_EVAL_LEDOn(LED4);
//  STM_EVAL_LEDOn(LED5);
//  STM_EVAL_LEDOn(LED6);
}

