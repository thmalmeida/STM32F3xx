#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f30x.h"
#include "stm32f3_discovery.h"

TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
TIM_OCInitTypeDef  TIM_OCInitStructure;
__IO uint32_t time_us;
__IO uint32_t time_ms;

void init_TIM(void);
void init_SysTick(void);
void delay_us(int micro);
void delay_ms(int milli);

#ifdef __cplusplus
}
#endif
