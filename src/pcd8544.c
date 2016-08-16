/*
 * pcd8544.c
 *
 *  Created on: 30 de mar de 2016
 *      Author: titi
 */

#include <string.h>

#include "pcd8544.h"
#include "glcd.h"
#include "timers.h"

void LCD_ENABLE()
{
	GPIO_ResetBits(LCD_PORT, LCD_PIN_SCE);
}
void LCD_DISABLE()
{
	GPIO_SetBits(LCD_PORT, LCD_PIN_SCE);
}
void LCD_RESET_ON()
{
	GPIO_ResetBits(LCD_PORT, LCD_PIN_RESET);
}
void LCD_RESET_OFF()
{
	GPIO_SetBits(LCD_PORT, LCD_PIN_RESET);
}
void LCD_DC_COMMAND()
{
	GPIO_ResetBits(LCD_PORT, LCD_PIN_COMMAND);
}
void LCD_DC_DATA()
{
	GPIO_SetBits(LCD_PORT, LCD_PIN_COMMAND);
}
void LCD_LED_OFF()
{
	GPIO_ResetBits(LCD_PORT, LCD_PIN_LED);
}
void LCD_LED_ON()
{
	GPIO_SetBits(LCD_PORT, LCD_PIN_LED);
}
//void SPI1_Init()
//{
//	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
//
////	SPI_InitTypeDef SPI1_Setup;
////	SPI1_Setup.SPI_DataSize 			= SPI_DataSize_8b;
////	SPI1_Setup.SPI_Direction 			= SPI_Direction_1Line_Tx;
////	SPI1_Setup.SPI_Mode 				= SPI_Mode_Master;
////	SPI1_Setup.SPI_FirstBit				= SPI_FirstBit_MSB;
////	SPI1_Setup.SPI_BaudRatePrescaler	= SPI_BaudRatePrescaler_128;
////	SPI1_Setup.SPI_NSS					= SPI_NSS_Soft;
////	SPI1_Setup.SPI_CPHA					= SPI_CPHA_2Edge;
////	SPI1_Setup.SPI_CPOL					= SPI_CPOL_High;
//////	SPI1_Setup.SPI_CRCPolynomial 		= SPI_CR1_CRCNEXT;
////
////	SPI_Init(SPI1, &SPI1_Setup);
////	SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Set);
////	SPI_Cmd(SPI1, ENABLE);
//
////	SPI1 -> CR1 |= SPI_CR1_BIDIMODE;	// 1-line bidirectional data mode selected
//	SPI1 -> CR1 |=  SPI_CR1_BIDIOE;		// transmit-only mode;
//	SPI1 -> CR1 |=  SPI_CR1_SSM;		// NSS software mode;
//	SPI1 -> CR1 &= ~SPI_CR1_SSI;
//	SPI1 -> CR1 |=  SPI_CR1_BR;			// Clock divided by 256;
//	SPI1 -> CR1 &= ~SPI_CR1_LSBFIRST;
//	SPI1 -> CR1 |=  SPI_CR1_MSTR | SPI_CR1_CPOL;
//	SPI1 -> CR1 |=  SPI_CR1_SPE;		// SP11 Enable bit;
//
//	SPI1 -> CR2 |= SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0;	// 8 bit frame
//
//	LCD_PORT -> MODER 	= 0x00008800;
//	LCD_PORT -> OSPEEDR = 0x0000CC00;
//	LCD_PORT -> PUPDR 	= 0x00004400;
////	LCD_PORT -> MODER |= (GPIO_Mode_AF << 5*2) | (GPIO_Mode_AF << 7*2);
////	LCD_PORT -> MODER |= (GPIO_Mode_AF << 5*2) | (GPIO_Mode_AF << 7*2);
////	LCD_PORT -> MODER |= (GPIO_Mode_AF << 5*2) | (GPIO_Mode_AF << 7*2);
////	LCD_PORT -> MODER |= (GPIO_Mode_AF << 5*2) | (GPIO_Mode_AF << 7*2);
//
//
//	/* Activate the SPI mode (Reset I2SMOD bit in I2SCFGR register) */
////	SPIx->I2SCFGR &= (uint16_t)~((uint16_t)SPI_I2SCFGR_I2SMOD);
////	SPIx->CRCPR = SPI_InitStruct->SPI_CRCPolynomial;
////	SPIx->CR1 = tmpreg;
////	SPIx->CR2 = tmpreg;
//
//
//
////	hspi1.Init.Mode = SPI_MODE_MASTER;
////	hspi1.Init.Direction = SPI_DIRECTION_2LINES;
////	hspi1.Init.DataSize = SPI_DATASIZE_4BIT;
////	hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
////	hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
////	hspi1.Init.NSS = SPI_NSS_SOFT;
////	hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
////	hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
////	hspi1.Init.TIMode = SPI_TIMODE_DISABLED;
////	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
////	hspi1.Init.CRCPolynomial = 7;
////	hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
////	hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLED;
////	HAL_SPI_Init(&hspi1);
//}
void RCC_Configuration(void)
{
	/* PCLK2 = HCLK/2 */
	RCC_PCLK2Config(RCC_HCLK_Div2);

  /* Enable GPIO clock for SPIy */
//  RCC_APB2PeriphClockCmd(SPIy_GPIO_CLK | RCC_APB2Periph_AFIO, ENABLE);
//  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);


  /* Enable SPIy Periph clock */
//  RCC_APB1PeriphClockCmd(SPIy_CLK, ENABLE);
}
void SPI1_Configuration()
{
	SPI_InitTypeDef   SPI_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	/* SPIy Config -------------------------------------------------------------*/
	SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;// | SPI_NSSInternalSoft_Set;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPIy, &SPI_InitStructure);

	SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Set);
//	SPI_RxFIFOThresholdConfig(SPI1, SPI_RxFIFOThreshold_QF);
	SPI_Cmd(SPI1, ENABLE);
}
void GPIO_Configuration()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	/* Configure SPIy pins: SCK, MISO and MOSI ---------------------------------*/
	GPIO_InitStructure.GPIO_Pin = SPIy_PIN_SCK | SPIy_PIN_MOSI | SPIy_PIN_MISO;
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_5;
	/* Configure SCK and MOSI pins as Alternate Function Push Pull */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(LCD_PORT, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_5); //SCK
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_5); //MISO
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_5); //MOSI

	/*Configure GPIO pins*/
	GPIO_InitStructure.GPIO_Pin = LCD_PIN_SCE | LCD_PIN_RESET | LCD_PIN_COMMAND | LCD_PIN_LED;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(LCD_PORT, &GPIO_InitStructure);


//	GPIOA ->
}
void SPI_write(uint8_t B)
{
	SPI_SendData8(SPI1, B);
}
void glcd_reset()
{
//	LCD_DISABLE();
	LCD_RESET_ON();
	delay_us(PCD8544_TIME_DELAY);
	LCD_RESET_OFF();
	delay_us(PCD8544_TIME_DELAY);
	LCD_ENABLE();
	delay_us(PCD8544_TIME_DELAY);
}
void glcd_command(uint8_t c)
{
	LCD_RESET_OFF();
	LCD_ENABLE();
	LCD_DC_COMMAND();
	SPI_write(c);
	delay_us(PCD8544_TIME_DELAY);
}
void glcd_data(uint8_t c)
{
	LCD_RESET_OFF();
	LCD_ENABLE();
	LCD_DC_DATA();
	delay_us(PCD8544_TIME_DELAY);
	SPI_write(c);
	delay_us(PCD8544_TIME_DELAY);
}
void glcd_init()
{
	SPI1_Configuration();
	GPIO_Configuration();

	// --- Reset and Enable
	glcd_reset();
	LCD_LED_ON();

	// --- glcd intialization
	// get into the EXTENDED mode!
	glcd_command(PCD8544_FUNCTION_SET | PCD8544_EXTENDEDINSTRUCTION);

	// LCD bias select (4 is optimal?)
	glcd_command(PCD8544_SET_BIAS | 0x04);

	// set VOP
//	if (contrast > 0x7f)
//	contrast = 0x7f;

	glcd_command(PCD8544_SET_VOP | 40); // Experimentally determined

	// normal mode
	glcd_command(PCD8544_FUNCTION_SET);

	// Set display to Normal
	glcd_command(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);

//	/* Initialization sequence of controller */
//	glcd_reset();
//
//	/* Get into the EXTENDED mode! */
//	glcd_command(PCD8544_FUNCTION_SET | PCD8544_EXTENDED_INSTRUCTION);
//
//	/* LCD bias select (4 is optimal?) */
//	glcd_command(PCD8544_SET_BIAS | 0x2);
//
//	/* Set VOP */
//	glcd_command(PCD8544_SET_VOP | 50); // Experimentally determined
//
//	/* Back to standard instructions */
//	glcd_command(PCD8544_FUNCTION_SET);
//
//	/* Normal mode */
//	glcd_command(PCD8544_DISPLAY_CONTROL | PCD8544_DISPLAY_NORMAL);
//
////	glcd_select_screen((uint8_t *)&glcd_buffer,&glcd_bbox);
//
////	glcd_set_contrast(50);
//
////	glcd_clear();
}
void glcd_print(void)
{
	glcd_data(0x5A);
	glcd_data(0x5A);
	glcd_data(0x5A);
	glcd_data(0x5A);
	glcd_data(0x5A);
}
void glcd_set_contrast(uint8_t val) {
	glcd_command(PCD8544_FUNCTION_SET | PCD8544_EXTENDED_INSTRUCTION);
	glcd_command(PCD8544_SET_VOP | (val&0x7f));
	glcd_command(PCD8544_FUNCTION_SET);
	glcd_command(PCD8544_DISPLAY_CONTROL | PCD8544_DISPLAY_NORMAL);
}
void glcd_power_down(void)
{
	/* First, fill RAM with zeroes to ensure minimum specified current consumption */
	glcd_clear();

	/* Power down */
	glcd_command(PCD8544_FUNCTION_SET|PCD8544_POWER_DOWN);
}
void glcd_power_up(void)
{
	glcd_command(PCD8544_FUNCTION_SET);
}
void glcd_set_y_address(uint8_t y)
{
	glcd_command(PCD8544_SET_Y_ADDRESS | (y > 5 ? 5 : y));
	delay_us(PCD8544_TIME_DELAY);
}
void glcd_set_x_address(uint8_t x)
{
//	glcd_command(PCD8544_SET_X_ADDRESS | (x & 0x7f));
	glcd_command(0b10000000 | (x & 0b01111111));
	delay_us(PCD8544_TIME_DELAY);
}
void glcd_clear2()
{
	int i;
	for(i=0; i<PCD8544_MAX_BANKS*PCD8544_MAX_COLS; i++)
	{
//		glcd_set_x_address(i);
//		delay_ms(1);
//		for(j=0; i<PCD8544_MAX_COLS; j++)
		{
//			glcd_set_y_address(j);
			glcd_data(0);
		}
	}
//	for (bank = 0; bank < PCD8544_MAX_BANKS; bank++) {
//		/* Each bank is a single row 8 bits tall */
//		uint8_t column;
//
//		if (glcd_bbox_selected->y_min >= (bank+1)*8) {
//			continue; /* Skip the entire bank */
//		}
//
//		if (glcd_bbox_selected->y_max < bank*8) {
//			break;    /* No more banks need updating */
//		}
//
//		glcd_command(PCD8544_SET_Y_ADDRESS | bank);
//		delay_ms(10);
//		glcd_command(PCD8544_SET_X_ADDRESS | glcd_bbox_selected->x_min);
//		delay_ms(10);
//		for (column = glcd_bbox_selected->x_min; column <= glcd_bbox_selected->x_max; column++)
//		{
//			glcd_data( glcd_buffer_selected[PCD8544_MAX_COLS * bank + column] );
//			delay_ms(10);
//		}
//	}
}
void glcd_write()
{
	uint8_t bank;

	for (bank = 0; bank < PCD8544_MAX_BANKS; bank++) {
		/* Each bank is a single row 8 bits tall */
		uint8_t column;

		if (glcd_bbox_selected->y_min >= (bank+1)*8) {
			continue; /* Skip the entire bank */
		}

		if (glcd_bbox_selected->y_max < bank*8) {
			break;    /* No more banks need updating */
		}

		glcd_command(PCD8544_SET_Y_ADDRESS | bank);
		glcd_command(PCD8544_SET_X_ADDRESS | glcd_bbox_selected->x_min);
		for (column = glcd_bbox_selected->x_min; column <= glcd_bbox_selected->x_max; column++)
		{
			glcd_data( glcd_buffer_selected[PCD8544_MAX_COLS * bank + column] );
			delay_ms(10);
		}
	}

	glcd_reset_bbox();

}
void glcd_PCD8544_init(void) {

	glcd_reset();

	/* Get into the EXTENDED mode! */
	glcd_command(PCD8544_FUNCTION_SET | PCD8544_EXTENDED_INSTRUCTION);

	/* LCD bias select (4 is optimal?) */
	glcd_command(PCD8544_SET_BIAS | 0x2);

	/* Set VOP (affects contrast) */
	glcd_command(PCD8544_SET_VOP | 80); /* Experimentally determined, play with this figure until contrast looks nice */

	/* Back to standard instructions */
	glcd_command(PCD8544_FUNCTION_SET);

	/* Normal mode */
	glcd_command(PCD8544_DISPLAY_CONTROL | PCD8544_DISPLAY_NORMAL);
}
void glcd_put_char(char c)
{
	int i;
	glcd_data(0x00);
	for(i=0;i<5;i++)
	{
		glcd_data(FontNew[(c-32)*5+i]);
	}
}
void glcd_put_string(uint8_t x, uint8_t y, char *str)
{
	glcd_set_x_address(x);
	glcd_set_y_address(y);
	int i, length = strlen(str);

	for(i=0;i<length;i++)
		glcd_put_char(str[i]);
}
void glcd_example()
{
	glcd_init();

	char *str1 = "STM32F-M4";
	glcd_command(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);
	glcd_put_string(13, 3, str1);
}
