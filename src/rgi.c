/*
 * rgi.c
 *
 *  Created on: 10 de may de 2016
 *      Author: titi
 */

#include "stm32f30x.h"

#include "rgi.h"
#include "timers.h"

int timer_pressure = 0;

/*
 * in_01	-> PA10
 * in_02	-> PA9
 * in_03	-> PA8
 * in_04	-> PC9
 * in_05	-> PC8
 * in_06	-> PC7
 * in_07	-> PC6
 * in_08	-> PB15
 * in_09	-> PB14
 * in_10	-> PB13
 * in_11	-> PB12
 *
 * out_01 	-> PA3
 * out_02 	-> PF4
 * out_03 	-> PA5
 * out_04 	-> PA6
 * out_05 	-> PA7
 * out_06 	-> PC4
 * out_07 	-> PC5
 * out_08 	-> PB0
 * out_09 	-> PB1
 * out_10	-> PB2
 * out_11 	-> PB10
 * out_12 	-> PB11
 *
 * out_A	-> PA1
 * out_B	-> PA0
 * out_C	-> PC3
 * out_D	-> PC2
 * out_E	-> PC1
 * out_F	-> PC0
 * out_G	-> PF0 ou PC14
 * out_H	-> PC13
 * out_I	-> PB9
 * out_J	-> PB8
 * out_K	-> PB5
 *
 * out_LED1 -> PC10
 * out_LED2 -> PC11
 *
 */

uint8_t RGI_get_In(uint8_t inValue)
{
	uint8_t status;
	switch(inValue)
	{
		case 1:
			status = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10);
			break;

		case 2:
			status = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9);
			break;

		case 3:
			status = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8);
			break;

		case 4:
			status = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9);
			break;

		case 5:
			status = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8);
			break;

		case 6:
			status = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7);
			break;

		case 7:
			status = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6);
			break;

		case 8:
			status = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);
			break;

		case 9:
			status = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14);
			break;

		case 10:
			status = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_13);
			break;

		case 11:
			status = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12);
			break;

		default:
			status = 0;
			break;
	}

	return !status;
}
void RGI_set_Out(unsigned int load, FunctionalState status)
{
	switch (load)
	{
		case 1:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOA, GPIO_Pin_3);
			else
				GPIO_SetBits(GPIOA, GPIO_Pin_3);
			break;

		case 2:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOF, GPIO_Pin_4);
			else
				GPIO_SetBits(GPIOF, GPIO_Pin_4);
			break;

		case 3:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			else
				GPIO_SetBits(GPIOA, GPIO_Pin_5);
			break;

		case 4:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOA, GPIO_Pin_6);
			else
				GPIO_SetBits(GPIOA, GPIO_Pin_6);
			break;

		case 5:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOA, GPIO_Pin_7);
			else
				GPIO_SetBits(GPIOA, GPIO_Pin_7);
			break;

		case 6:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOC, GPIO_Pin_4);
			else
				GPIO_SetBits(GPIOC, GPIO_Pin_4);
			break;

		case 7:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOC, GPIO_Pin_5);
			else
				GPIO_SetBits(GPIOC, GPIO_Pin_5);
			break;

		case 8:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOB, GPIO_Pin_0);
			else
				GPIO_SetBits(GPIOB, GPIO_Pin_0);
			break;

		case 9:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOB, GPIO_Pin_1);
			else
				GPIO_SetBits(GPIOB, GPIO_Pin_1);
			break;

		case 10:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOB, GPIO_Pin_2);
			else
				GPIO_SetBits(GPIOB, GPIO_Pin_2);
			break;

		case 11:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOB, GPIO_Pin_10);
			else
				GPIO_SetBits(GPIOB, GPIO_Pin_10);
			break;

		case 12:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOB, GPIO_Pin_11);
			else
				GPIO_SetBits(GPIOB, GPIO_Pin_11);
			break;

		case 13:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOA, GPIO_Pin_1);
			else
				GPIO_SetBits(GPIOA, GPIO_Pin_1);
			break;

		case 14:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOA, GPIO_Pin_0);
			else
				GPIO_SetBits(GPIOA, GPIO_Pin_0);
			break;

		case 15:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOC, GPIO_Pin_3);
			else
				GPIO_SetBits(GPIOC, GPIO_Pin_3);
			break;

		case 16:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOC, GPIO_Pin_2);
			else
				GPIO_SetBits(GPIOC, GPIO_Pin_2);
			break;

		case 17:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOC, GPIO_Pin_1);
			else
				GPIO_SetBits(GPIOC, GPIO_Pin_1);
			break;

		case 18:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOC, GPIO_Pin_0);
			else
				GPIO_SetBits(GPIOC, GPIO_Pin_0);
			break;

		// PC14 or PF0
		case 19:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOC, GPIO_Pin_14);
//				GPIO_ResetBits(GPIOF, GPIO_Pin_0);
			else
				GPIO_SetBits(GPIOC, GPIO_Pin_14);
//				GPIO_SetBits(GPIOF, GPIO_Pin_0);
			break;

		case 20:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOC, GPIO_Pin_13);
			else
				GPIO_SetBits(GPIOC, GPIO_Pin_13);
			break;

		case 21:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOB, GPIO_Pin_9);
			else
				GPIO_SetBits(GPIOB, GPIO_Pin_9);
			break;

		case 22:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOB, GPIO_Pin_8);
			else
				GPIO_SetBits(GPIOB, GPIO_Pin_8);
			break;

		case 23:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOB, GPIO_Pin_5);
			else
				GPIO_SetBits(GPIOB, GPIO_Pin_5);
			break;
	}
}
void RGI_set_LED(unsigned int load, FunctionalState status)
{
	switch (load)
	{
		case 1:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOC, GPIO_Pin_10);
			else
				GPIO_SetBits(GPIOC, GPIO_Pin_10);
			break;

		case 2:
			if(status != ENABLE)
				GPIO_ResetBits(GPIOC, GPIO_Pin_11);
			else
				GPIO_SetBits(GPIOC, GPIO_Pin_11);
			break;

		default:
			break;
	}
}
void valve_1(uint8_t solenoid, FunctionalState status)
{
	switch(solenoid)
	{
		case 1:
			RGI_set_Out(1, status);
			break;

		case 2:
			RGI_set_Out(2, status);
			break;
	}
}
void valve_2(uint8_t solenoid, FunctionalState status)
{
	switch(solenoid)
	{
		case 1:
			RGI_set_Out(3, status);
			break;

		case 2:
			RGI_set_Out(4, status);
			break;
	}
}
void valve_3(uint8_t solenoid, FunctionalState status)
{
	switch(solenoid)
	{
		case 1:
			RGI_set_Out(5, status);
			break;

		case 2:
			RGI_set_Out(6, status);
			break;
	}
}
void valve_4(FunctionalState status)
{
	RGI_set_Out(7, status);
}
void oilPump(FunctionalState status)
{
	RGI_set_Out(8, status);
}

uint8_t buttonUP()
{
	return RGI_get_In(1);
}
uint8_t buttonDOWN()
{
	return RGI_get_In(2);
}
uint8_t buttonLEFT()
{
	return RGI_get_In(3);
}
uint8_t buttonRIGHT()
{
	return RGI_get_In(4);
}
uint8_t buttonEAST()
{
	return RGI_get_In(5);
}
uint8_t buttonWEST()
{
	return RGI_get_In(6);
}
uint8_t button1()
{
	return RGI_get_In(7);
}
uint8_t button2()
{
	return RGI_get_In(8);
}

// Abertura do Cilindro de tração. Solenoide 3 e 7.

void RGI_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOF, ENABLE);

	 /*
	 * out_01 	-> PA3
	 * out_02 	-> PF4
	 * out_03 	-> PA5
	 * out_04 	-> PA6
	 * out_05 	-> PA7
	 * out_06 	-> PC4
	 * out_07 	-> PC5
	 * out_08 	-> PB0
	 * out_09 	-> PB1
	 * out_10	-> PB2
	 * out_11 	-> PB10
	 * out_12 	-> PB11
	 *
	 * out_A	-> PA1
	 * out_B	-> PA0
	 * out_C	-> PC3
	 * out_D	-> PC2
	 * out_E	-> PC1
	 * out_F	-> PC0
	 * out_G	-> PF0 ou PC14
	 * out_H	-> PC13
	 * out_I	-> PB9
	 * out_J	-> PB8
	 * out_K	-> PB5
	 */

	/*Configure GPIO pins : PA3 PA5 PA6 PA7 PA1 PA0  */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_1 | GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*Configure GPIO pins : PB0, PB1, PB2, PB10, PB11; PB9 PB8 PB5*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_9 | GPIO_Pin_8 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/*Configure GPIO pins : PC4 PC5 PC3 PC2 PC1 PC0 PC13 PC14*/
	/*Configure GPIO pins : PC10 PC11 For the LED red and green*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/*Configure GPIO pins : PF4 and PF0 if jump selected*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);


//	------------------------ INPUT PINS! ----------------------------------------
	/*Configure GPIO pins : PA8 PA9 PA10 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 |  GPIO_Pin_9 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*Configure GPIO pins : PC9 PC8 PC7 PC6 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 |  GPIO_Pin_8 | GPIO_Pin_7 | GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/*Configure GPIO pins : PB15, PB14, PB13, PB12 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 |  GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void RGI_Process()
{
	if(buttonUP())
	{
		RGI_set_Out(11, ENABLE);

		RGI_set_LED(1, ENABLE);
		RGI_set_LED(2, DISABLE);
	}
	else if(buttonDOWN())
	{
		RGI_set_Out(12, ENABLE);

		RGI_set_LED(1, ENABLE);
		RGI_set_LED(2, DISABLE);
	}
	else if(buttonLEFT())
	{
		valve_2(1, ENABLE);
		valve_4(ENABLE);
		oilPump(ENABLE);

		RGI_set_LED(1, ENABLE);
		RGI_set_LED(2, DISABLE);
	}
	else if(buttonRIGHT())
	{
		valve_2(2, ENABLE);
		valve_4(ENABLE);
		oilPump(ENABLE);

		RGI_set_LED(1, ENABLE);
		RGI_set_LED(2, DISABLE);
	}
	else if(buttonEAST())
	{
		valve_3(1, ENABLE);
		valve_4(ENABLE);
		oilPump(ENABLE);

		RGI_set_LED(1, ENABLE);
		RGI_set_LED(2, DISABLE);
	}
	else if(buttonWEST())
	{
		valve_3(2, ENABLE);
		valve_4(ENABLE);
		oilPump(ENABLE);

		RGI_set_LED(1, ENABLE);
		RGI_set_LED(2, DISABLE);
	}
	else if(button1())
	{
		valve_1(1, ENABLE);
		valve_4(ENABLE);
		oilPump(ENABLE);

		RGI_set_LED(1, ENABLE);
		RGI_set_LED(2, DISABLE);
	}
	else if(button2())
	{
		valve_1(2, ENABLE);
		valve_4(ENABLE);
		oilPump(ENABLE);


		RGI_set_LED(1, ENABLE);
		RGI_set_LED(2, DISABLE);
	}
	else
	{
		RGI_set_Out(11, DISABLE);
		RGI_set_Out(12, DISABLE);

		valve_1(1, DISABLE);
		valve_1(2, DISABLE);

		valve_2(1, DISABLE);
		valve_2(2, DISABLE);

		valve_3(1, DISABLE);
		valve_3(2, DISABLE);

		valve_4(DISABLE);

		oilPump(DISABLE);

		RGI_set_LED(1, DISABLE);
		RGI_set_LED(2, ENABLE);
	}
}
void RGI_Demo()
{
	int i=0, n = 23;
	int t1 = 4, t2 = 2;
	/* Read the value on input pin PB12 */
	// inval = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12);

	RGI_set_LED(1,0);
	RGI_set_LED(2,1);
	for(i=1;i<=11;i+=2)
	{
		RGI_set_Out(i,1);
		delay_ms(t1);
	}
	for(i=12;i>=2;i-=2)
	{
		RGI_set_Out(i,1);
		delay_ms(t1);
	}
	for(i=13;i<=n;i++)
	{
		RGI_set_Out(i,1);
		delay_ms(t2);
	}

	RGI_set_LED(1,1);
	RGI_set_LED(2,0);
	for(i=n;i>=13;i--)
	{
		RGI_set_Out(i,0);
		delay_ms(t2);
	}
	for(i=2;i<=12;i+=2)
	{
		RGI_set_Out(i,0);
		delay_ms(t1);
	}
	for(i=11;i>=1;i-=2)
	{
		RGI_set_Out(i,0);
		delay_ms(t1);
	}
	delay_ms(10);
}
void RGI_UART1_Init()
{

}
