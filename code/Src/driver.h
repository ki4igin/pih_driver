#ifndef __DRIVER_H__
#define __DRIVER_H__

#include "stm32f4xx.h"

void driver_az_offset(int32_t offset_deg);
void driver_el_offset(int32_t offset_deg);
void driver_az_stop(void);
void driver_el_stop(void);
void driver_stop(void);
void driver_az_set_k(uint32_t k_deg2pulse);
void driver_el_set_k(uint32_t k_deg2pulse);
void driver_tick_ms(void);
int32_t driver_az_get_pos(void);
int32_t driver_el_get_pos(void);
void driver_origin(void);

#endif
