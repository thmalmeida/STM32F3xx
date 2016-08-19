/*
 * pcd8544.h
 *
 *  Created on: 30 de mar de 2016
 *      Author: titi
 */

#ifndef RGI_H_
#define RGI_H_

#ifdef __cplusplus
 extern "C" {
#endif


#include <stm32f30x.h>

// Abertura do Cilindro de tração. Solenoide 3 e 7.
 uint8_t RGI_get_In(uint8_t inValue);
void RGI_set_Out(unsigned int load, FunctionalState status);
void RGI_set_LED(unsigned int load, FunctionalState status);
void valve_1(uint8_t solenoid, FunctionalState status);
void valve_2(uint8_t solenoid, FunctionalState status);
void valve_3(uint8_t solenoid, FunctionalState status);
void valve_4(FunctionalState status);
uint8_t buttonUP();
uint8_t buttonDOWN();
uint8_t buttonLEFT();
uint8_t buttonRIGHT();
uint8_t buttonEAST();
uint8_t buttonWEST();
uint8_t button1();
uint8_t button2();
void RGI_Demo();
void RGI_Process();
void RGI_Init();

#ifdef __cplusplus
}
#endif



#endif /* RGI_H_ */
