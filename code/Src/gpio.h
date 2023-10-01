
/**
 ******************************************************************************
 * @file    gpio.h
 * @brief   This file contains all the function prototypes for
 *          the gpio.c file
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

void MX_GPIO_Init(void);

#define gpio_on_off_toggle_declare(_name, _port, _pin) \
    inline static void gpio_##_name##_on(void)         \
    {                                                  \
        LL_GPIO_SetOutputPin(_port, _pin);             \
    }                                                  \
    inline static void gpio_##_name##_off(void)        \
    {                                                  \
        LL_GPIO_ResetOutputPin(_port, _pin);           \
    }                                                  \
    inline static void gpio_##_name##_toggle(void)     \
    {                                                  \
        LL_GPIO_TogglePin(_port, _pin);                \
    }

// clang-format off
gpio_on_off_toggle_declare(led, LED_GPIO_Port, LED_Pin)
gpio_on_off_toggle_declare(s1, S1_GPIO_Port, S1_Pin)
gpio_on_off_toggle_declare(s2, S2_GPIO_Port, S2_Pin)
gpio_on_off_toggle_declare(s3, S3_GPIO_Port, S3_Pin)
gpio_on_off_toggle_declare(s4, S4_GPIO_Port, S4_Pin)
// clang-format on

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */
