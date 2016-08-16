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
#include <stdio.h>

void S3_ON();
void S3_OFF();
void S7_ON();
void S7_OFF();

// Abertura do Cilindro de tração. Solenoide 3 e 7.
void C7_TR();
void C7_STOP();
void C6_EX();
void C6_STOP();
void C5_UP();
void C5_STOP();
void RGI_LED(unsigned int load, FunctionalState status);
void RGI_Out(unsigned int load, FunctionalState status);
void RGI_Demo();
void RGI_Process();
void RGI_Init();

#ifdef __cplusplus
}
#endif



#endif /* RGI_H_ */
