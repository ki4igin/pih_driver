#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_gpio.h"

#if defined(USE_FULL_ASSERT)
#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */

void Error_Handler(void);

#define LED_Pin             LL_GPIO_PIN_13
#define LED_GPIO_Port       GPIOC
#define BTN_Pin             LL_GPIO_PIN_0
#define BTN_GPIO_Port       GPIOA
#define USART1_DE_Pin       LL_GPIO_PIN_8
#define USART1_DE_GPIO_Port GPIOA
#define S4_Pin              LL_GPIO_PIN_6
#define S4_GPIO_Port        GPIOB
#define S3_Pin              LL_GPIO_PIN_7
#define S3_GPIO_Port        GPIOB
#define S2_Pin              LL_GPIO_PIN_8
#define S2_GPIO_Port        GPIOB
#define S1_Pin              LL_GPIO_PIN_9
#define S1_GPIO_Port        GPIOB

#ifndef NVIC_PRIORITYGROUP_0
#define NVIC_PRIORITYGROUP_0 ((uint32_t)0x00000007)
#define NVIC_PRIORITYGROUP_1 ((uint32_t)0x00000006)
#define NVIC_PRIORITYGROUP_2 ((uint32_t)0x00000005)
#define NVIC_PRIORITYGROUP_3 ((uint32_t)0x00000004)
#define NVIC_PRIORITYGROUP_4 ((uint32_t)0x00000003)
#endif

enum cmd_id {
    CMD_RESET = 1,
    CMD_TEST = 2,
    CMD_LED_TOGGLE,
    CMD_AZ_SET_K,
    CMD_EL_SET_K,
    CMD_SET_ORIGIN,
    CMD_STOP,
    CMD_AZ_STOP,
    CMD_EL_STOP,
    CMD_AZ_OFFSET,
    CMD_EL_OFFSET,
    CMD_AZ_GET_POS,
    CMD_EL_GET_POS,
    CMD_GET_POS,
    CMD_AZ_GET_OFFSET,
    CMD_EL_GET_OFFSET,
    CMD_GET_OFFSET,
    CMD_AZ_REQ_DN,
    CMD_EL_REQ_DN,
};

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
