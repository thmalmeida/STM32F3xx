/*
 * pcd8544.h
 *
 *  Created on: 30 de mar de 2016
 *      Author: titi
 */

#ifndef PCD8544_H_
#define PCD8544_H_

#include "stm32f30x.h"
#include "stdio.h"
#include "stdlib.h"

static const uint8_t FontNew[] = {
	0x00, 0x00, 0x00, 0x00, 0x00,// (space)
	0x00, 0x00, 0x5F, 0x00, 0x00,// !
	0x00, 0x07, 0x00, 0x07, 0x00,// "
	0x14, 0x7F, 0x14, 0x7F, 0x14,// #
	0x24, 0x2A, 0x7F, 0x2A, 0x12,// $
	0x23, 0x13, 0x08, 0x64, 0x62,// %
	0x36, 0x49, 0x55, 0x22, 0x50,// &
	0x00, 0x05, 0x03, 0x00, 0x00,// '
	0x00, 0x1C, 0x22, 0x41, 0x00,// (
	0x00, 0x41, 0x22, 0x1C, 0x00,// )
	0x08, 0x2A, 0x1C, 0x2A, 0x08,// *
	0x08, 0x08, 0x3E, 0x08, 0x08,// +
	0x00, 0x50, 0x30, 0x00, 0x00,// ,
	0x08, 0x08, 0x08, 0x08, 0x08,// -
	0x00, 0x60, 0x60, 0x00, 0x00,// .
	0x20, 0x10, 0x08, 0x04, 0x02,// /
	0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
	0x00, 0x42, 0x7F, 0x40, 0x00,// 1
	0x42, 0x61, 0x51, 0x49, 0x46,// 2
	0x21, 0x41, 0x45, 0x4B, 0x31,// 3
	0x18, 0x14, 0x12, 0x7F, 0x10,// 4
	0x27, 0x45, 0x45, 0x45, 0x39,// 5
	0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
	0x01, 0x71, 0x09, 0x05, 0x03,// 7
	0x36, 0x49, 0x49, 0x49, 0x36,// 8
	0x06, 0x49, 0x49, 0x29, 0x1E,// 9
	0x00, 0x36, 0x36, 0x00, 0x00,// :
	0x00, 0x56, 0x36, 0x00, 0x00,// ;
	0x00, 0x08, 0x14, 0x22, 0x41,// <
	0x14, 0x14, 0x14, 0x14, 0x14,// =
	0x41, 0x22, 0x14, 0x08, 0x00,// >
	0x02, 0x01, 0x51, 0x09, 0x06,// ?
	0x32, 0x49, 0x79, 0x41, 0x3E,// @
	0x7E, 0x11, 0x11, 0x11, 0x7E,// A
	0x7F, 0x49, 0x49, 0x49, 0x36,// B
	0x3E, 0x41, 0x41, 0x41, 0x22,// C
	0x7F, 0x41, 0x41, 0x22, 0x1C,// D
	0x7F, 0x49, 0x49, 0x49, 0x41,// E
	0x7F, 0x09, 0x09, 0x01, 0x01,// F
	0x3E, 0x41, 0x41, 0x51, 0x32,// G
	0x7F, 0x08, 0x08, 0x08, 0x7F,// H
	0x00, 0x41, 0x7F, 0x41, 0x00,// I
	0x20, 0x40, 0x41, 0x3F, 0x01,// J
	0x7F, 0x08, 0x14, 0x22, 0x41,// K
	0x7F, 0x40, 0x40, 0x40, 0x40,// L
	0x7F, 0x02, 0x04, 0x02, 0x7F,// M
	0x7F, 0x04, 0x08, 0x10, 0x7F,// N
	0x3E, 0x41, 0x41, 0x41, 0x3E,// O
	0x7F, 0x09, 0x09, 0x09, 0x06,// P
	0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
	0x7F, 0x09, 0x19, 0x29, 0x46,// R
	0x46, 0x49, 0x49, 0x49, 0x31,// S
	0x01, 0x01, 0x7F, 0x01, 0x01,// T
	0x3F, 0x40, 0x40, 0x40, 0x3F,// U
	0x1F, 0x20, 0x40, 0x20, 0x1F,// V
	0x7F, 0x20, 0x18, 0x20, 0x7F,// W
	0x63, 0x14, 0x08, 0x14, 0x63,// X
	0x03, 0x04, 0x78, 0x04, 0x03,// Y
	0x61, 0x51, 0x49, 0x45, 0x43,// Z
	0x00, 0x00, 0x7F, 0x41, 0x41,// [
	0x02, 0x04, 0x08, 0x10, 0x20,// "\"
	0x41, 0x41, 0x7F, 0x00, 0x00,// ]
	0x04, 0x02, 0x01, 0x02, 0x04,// ^
	0x40, 0x40, 0x40, 0x40, 0x40,// _
	0x00, 0x01, 0x02, 0x04, 0x00,// `
	0x20, 0x54, 0x54, 0x54, 0x78,// a
	0x7F, 0x48, 0x44, 0x44, 0x38,// b
	0x38, 0x44, 0x44, 0x44, 0x20,// c
	0x38, 0x44, 0x44, 0x48, 0x7F,// d
	0x38, 0x54, 0x54, 0x54, 0x18,// e
	0x08, 0x7E, 0x09, 0x01, 0x02,// f
	0x08, 0x14, 0x54, 0x54, 0x3C,// g
	0x7F, 0x08, 0x04, 0x04, 0x78,// h
	0x00, 0x44, 0x7D, 0x40, 0x00,// i
	0x20, 0x40, 0x44, 0x3D, 0x00,// j
	0x00, 0x7F, 0x10, 0x28, 0x44,// k
	0x00, 0x41, 0x7F, 0x40, 0x00,// l
	0x7C, 0x04, 0x18, 0x04, 0x78,// m
	0x7C, 0x08, 0x04, 0x04, 0x78,// n
	0x38, 0x44, 0x44, 0x44, 0x38,// o
	0x7C, 0x14, 0x14, 0x14, 0x08,// p
	0x08, 0x14, 0x14, 0x18, 0x7C,// q
	0x7C, 0x08, 0x04, 0x04, 0x08,// r
	0x48, 0x54, 0x54, 0x54, 0x20,// s
	0x04, 0x3F, 0x44, 0x40, 0x20,// t
	0x3C, 0x40, 0x40, 0x20, 0x7C,// u
	0x1C, 0x20, 0x40, 0x20, 0x1C,// v
	0x3C, 0x40, 0x30, 0x40, 0x3C,// w
	0x44, 0x28, 0x10, 0x28, 0x44,// x
	0x0C, 0x50, 0x50, 0x50, 0x3C,// y
	0x44, 0x64, 0x54, 0x4C, 0x44,// z
	0x00, 0x08, 0x36, 0x41, 0x00,// {
	0x00, 0x00, 0x7F, 0x00, 0x00,// |
	0x00, 0x41, 0x36, 0x08, 0x00,// }
	0x08, 0x08, 0x2A, 0x1C, 0x08,// ->
	0x08, 0x1C, 0x2A, 0x08, 0x08 // <-
};

#define LCD_PORT 						GPIOA

#define	LCD_PIN_LED						GPIO_Pin_3
#define LCD_PIN_SCE						GPIO_Pin_0
#define LCD_PIN_RESET					GPIO_Pin_1
#define LCD_PIN_COMMAND					GPIO_Pin_2
#define LCD_PIN_CLOCK					GPIO_Pin_5
#define LCD_PIN_DATA					GPIO_Pin_7

#define PCD8544_TIME_DELAY				20

#define BLACK 							1
#define WHITE 							0

#define LCDWIDTH						84
#define LCDHEIGHT						48

#define PCD8544_POWERDOWN				0x04
//#define PCD8544_POWER_DOWN            (1<<2)
#define PCD8544_ENTRYMODE				0x02
#define PCD8544_EXTENDEDINSTRUCTION		0x01

#define PCD8544_DISPLAYBLANK			0x0
#define PCD8544_DISPLAYNORMAL			0x4
#define PCD8544_DISPLAYALLON			0x1
#define PCD8544_DISPLAYINVERTED			0x5

// H = 0
#define PCD8544_FUNCTION_SET			0x20
#define PCD8544_POWER_DOWN				(1<<2)
//#define PCD8544_FUNCTION_SET			(1<<5)
#define PCD8544_DISPLAYCONTROL			0x08
#define PCD8544_SET_YADDR				0x40
#define PCD8544_SET_XADDR				0x80

// H = 1
#define PCD8544_SET_TEMP				0x04
#define PCD8544_SET_BIAS				0x10
#define PCD8544_SET_VOP					0x80

#define PCD8544_NOP						0

#define PCD8544_HORIZONTAL_ADDRESSING	0
#define PCD8544_VERTICAL_ADDRESSING  	(1<<1)
#define PCD8544_EXTENDED_INSTRUCTION	(1<<0)

#define PCD8544_SET_Y_ADDRESS			0x40
#define PCD8544_SET_X_ADDRESS			0x80

#define PCD8544_MAX_BANKS				6
#define PCD8544_MAX_COLS				84

// name Basic instruction set (H=0)
#define PCD8544_DISPLAY_CONTROL			(1<<3)
#define PCD8544_DISPLAY_BLANK			0x0
#define PCD8544_DISPLAY_NORMAL			(1<<2)
#define PCD8544_DISPLAY_ALL_ON			(1<<0)
#define PCD8544_DISPLAY_INVERTED		(1<<2|1<<0)
// name Extended instruction set (H=1)

//#define PCD8544_SET_TEMP (1<<2)
#define PCD8544_TEMPCO_0				0b00
#define PCD8544_TEMPCO_1				0b01
#define PCD8544_TEMPCO_2				0b10
#define PCD8544_TEMPCO_3				0b11

//#define PCD8544_SET_BIAS (1<<4)
//#define PCD8544_SET_VOP  (1<<7)



#define SPIy                   SPI1
#define SPIy_CLK               RCC_APB2Periph_SPI1
#define SPIy_GPIO              GPIOA
//#define SPIy_GPIO_CLK          RCC_APB2Periph_GPIOA
#define SPIy_PIN_SCK           GPIO_Pin_5
#define SPIy_PIN_MISO          GPIO_Pin_6
#define SPIy_PIN_MOSI          GPIO_Pin_7

/* Private define ------------------------------------------------------------*/
#define BufferSize 32
#define SEND_LIMIT 3

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

//uint8_t SPIy_Buffer_Tx[BufferSize] = {0x1, 0x2, 0x4, 0x54, 0x55, 0x56, 0x57,
//                                      0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E,
//                                      0x5F, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65,
//                                      0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C,
//                                      0x6D, 0x6E, 0x6F, 0x70};
//
//__IO uint8_t TxIdx = 0, RxIdx = 0, k = 0;

/* Private functions ---------------------------------------------------------*/
void RCC_Configuration();
void GPIO_Configuration();
void SPI1_Configuration();

void glcd_init();
void glcd_init_pins();
void glcd_data(uint8_t c);
void glcd_write();
void glcd_clear2();
void glcd_set_x_address(uint8_t x);
void glcd_set_y_address(uint8_t y);

void glcd_command(uint8_t c);

void glcd_put_char(char c);
void glcd_put_string(uint8_t x, uint8_t y, char *str);


#endif /* PCD8544_H_ */