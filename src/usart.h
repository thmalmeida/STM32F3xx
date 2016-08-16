/*
 * usart.h
 *
 *  Created on: 11 de jun de 2016
 *      Author: titi
 */

#ifndef USART_H
#define USART_H

#include "stm32f30x.h"
#include "stm32f3_discovery.h"
#include <string.h>

#define RINGBUF_SIZE_BITS 5

void USART1_Init(void);
void USART1_IRQHandler(void);
void USART1_putc(char ch);
void USART1_write(const char *str, int len);
void USART1_print(const char *str);
void USART1_directputc(const char ch);
void USART1_directprint(const char *str);
void USART1_flush(void);
void USART1_B_Init();
void USART1_puts0(USART_TypeDef* USARTx, volatile char *s);

#endif
