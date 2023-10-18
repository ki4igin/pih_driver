#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "stm32f4xx.h"
#include "stm32f4xx_ll_gpio.h"
#include "uart.h"

struct gpio {
    GPIO_TypeDef *port;
    uint32_t pin;
};

struct motor {
    struct gpio gpio_p;
    struct gpio gpio_n;
    int32_t pos_ms;
    int32_t offset_ms;
    uint32_t k_deg2pulse;
    uint32_t is_req_dn;
    const uint16_t RESP_DN;
};

inline static void motor_offset(struct motor *s, int32_t offset_deg)
{
    s->offset_ms += offset_deg * s->k_deg2pulse;
}

inline static int16_t motor_get_pos(struct motor *s)
{
    return s->offset_ms / (int16_t)s->k_deg2pulse;
}

inline static int16_t motor_get_offset(struct motor *s)
{
    return s->pos_ms / (int16_t)s->k_deg2pulse;
}

inline static void motor_set_origin(struct motor *s)
{
    s->pos_ms = 0;
}

inline static void motor_req_dn(struct motor *s, int32_t offset_deg)
{
    s->offset_ms = offset_deg * s->k_deg2pulse;
    s->is_req_dn = 1;
}

inline static void motor_mov_process(struct motor *s)
{
    if (s->offset_ms > 0) {
        LL_GPIO_ResetOutputPin(s->gpio_n.port, s->gpio_n.pin);
        LL_GPIO_SetOutputPin(s->gpio_p.port, s->gpio_p.pin);
        s->offset_ms--;
        s->pos_ms++;
    } else if (s->offset_ms < 0) {
        LL_GPIO_ResetOutputPin(s->gpio_p.port, s->gpio_p.pin);
        LL_GPIO_SetOutputPin(s->gpio_n.port, s->gpio_n.pin);
        s->offset_ms++;
        s->pos_ms--;
    } else {
        LL_GPIO_ResetOutputPin(s->gpio_n.port, s->gpio_n.pin);
        LL_GPIO_ResetOutputPin(s->gpio_p.port, s->gpio_p.pin);
        if (s->is_req_dn) {
            s->is_req_dn = 0;
            uint16_t buf[2] = {s->RESP_DN, 0};
            UART_Send_Array(&buf, sizeof(buf));
        }
    }
}

inline static void motor_stop(struct motor *s)
{
    s->offset_ms = 0;
}

#endif
