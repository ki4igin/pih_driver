#ifndef __DRIVER_H__
#define __DRIVER_H__

#include "stm32f4xx.h"

struct driver_pos {
    int16_t az;
    int16_t el;
};

void driver_az_offset(int32_t offset_deg);
void driver_el_offset(int32_t offset_deg);
void driver_az_stop(void);
void driver_el_stop(void);
void driver_stop(void);
void driver_az_set_k(uint32_t k_deg2pulse);
void driver_el_set_k(uint32_t k_deg2pulse);
void driver_tick_ms(void);
struct driver_pos driver_get_pos(void);
void driver_origin(void);

#endif
