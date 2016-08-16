/*
 * usart.c
 *
 *  Created on: 11 de jun de 2016
 *      Author: titi
 */

#include "usart.h"

#define RINGBUF_SIZE (1<<RINGBUF_SIZE_BITS)
volatile uint8_t USART1_ringbuf[RINGBUF_SIZE];
volatile uint32_t USART1_readidx = 0;
volatile uint32_t USART1_writeidx = 0;

void USART1_B_Init()
{
	/* Enable GPIOB clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

	/* Enable USART clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/* GPIO Configuration */
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Connect PB6 to USART1_Tx */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_7);

	/* Connect PB7 to USART1_Rx */
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_7);

	/* Configure USART Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* Configure USART Rx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOB, &GPIO_InitStructure);


	/* USART1 Configuration */
	USART_InitTypeDef USART_InitStructure;

	/* USART resources configuration (Clock, GPIO pins and USART registers) ----*/
	/* USART configured as follow:
	        - BaudRate = 115200 baud
	        - Word Length = 8 Bits
	        - One Stop Bit
	        - No parity
	        - Hardware flow control disabled (RTS and CTS signals)
	        - Receive and transmit enabled
	 */
	USART_InitStructure.USART_BaudRate = 9600; //115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	/* USART configuration set */
	USART_Init(USART1, &USART_InitStructure);

	/* Enable USART */
	USART_Cmd(USART1, ENABLE);

	NVIC_EnableIRQ(USART1_IRQn);
}

void USART1_Init(void)
{
	/* Enable GPIO clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	/* Enable USART clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/* GPIO Configuration */
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Connect PA9 to USART1_Tx */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_7);

	/* Connect PA10 to USART1_Rx */
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_7);

	/* Configure USART Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure USART Rx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &GPIO_InitStructure);


	/* USART1 Configuration */
	USART_InitTypeDef USART_InitStructure;

	/* USART resources configuration (Clock, GPIO pins and USART registers) ----*/
	/* USART configured as follow:
	        - BaudRate = 115200 baud
	        - Word Length = 8 Bits
	        - One Stop Bit
	        - No parity
	        - Hardware flow control disabled (RTS and CTS signals)
	        - Receive and transmit enabled
	 */
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	/* USART configuration set */
	USART_Init(USART1, &USART_InitStructure);

	/* Enable USART */
	USART_Cmd(USART1, ENABLE);

	NVIC_EnableIRQ(USART1_IRQn);

//    GPIO_InitTypeDef GPIO_InitStructure;
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//
//    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_7);
//    GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_7);
////    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_7);
//
//    USART_InitTypeDef USART_InitStructure;
//    USART_StructInit(&USART_InitStructure);
//    USART_InitStructure.USART_BaudRate = 9600;
//    USART_Init(USART1, &USART_InitStructure);
//
//    USART_Cmd(USART1, ENABLE);
//
}
//void USART1_IRQHandler(void)
//{
//    if (USART1_writeidx - USART1_readidx == 0) {
//        USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
//        return;
//    }
//    USART_SendData(USART1, USART1_ringbuf[(USART1_readidx++) & (RINGBUF_SIZE-1)]);
//}

#define MIN(a, b) ((a)<(b)?(a):(b))

//void USART1_write(const char *str, int len)
//{
//    uint32_t i = 0;
//    while (i < len) {
//        uint32_t writeidx = USART1_writeidx & (RINGBUF_SIZE-1);
//        uint32_t len_to_end = RINGBUF_SIZE - writeidx;
//        uint32_t capacity = RINGBUF_SIZE - (USART1_writeidx - USART1_readidx);
//        uint32_t max_len = MIN(len_to_end, capacity);
//        if (max_len == 0) continue;
//
//        uint32_t this_len = MIN(max_len, len - i);
//
//        int j;
//        for (j = 0; j < this_len; ++j) {
//            USART1_ringbuf[writeidx++] = str[i++];
//        }
//        USART1_writeidx += this_len;
//
//        USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
//    }
//}
void USART1_print(const char *str)
{
    uint32_t len = strlen(str);
    USART1_write(str, len);
}
void USART1_directputc(const char ch)
{
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    USART_SendData(USART1, ch);
}
void USART1_directprint(const char *str)
{
    uint32_t i = 0;
    uint32_t len = strlen(str);
    while (i < len) {
        USART1_directputc(str[i++]);
    }
}
void USART1_flush(void)
{
    while (USART1_readidx != USART1_writeidx);
}
void USART1_puts0(USART_TypeDef* USARTx, volatile char *s)
{
	while(*s)
	{
		// wait until data register is empty. Transmission complete (TC) bit
		while( !(USARTx->ISR & 0x00000040) );
		USART_SendData(USARTx, *s);
		s++;
	}
}
//void USART1_putc(char ch)
//{
//    while (1) {
//        uint32_t capacity = RINGBUF_SIZE - (USART1_writeidx - USART1_readidx);
//        if (capacity > 0) break;
//    }
//    USART1_ringbuf[(USART1_writeidx++) & (RINGBUF_SIZE-1)] = ch;
//}

