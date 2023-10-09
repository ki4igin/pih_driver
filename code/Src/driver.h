#ifndef __DRIVER_H__
#define __DRIVER_H__

#include "stm32f4xx.h"

struct coord {
    int16_t az;
    int16_t el;
};

void driver_az_offset(int32_t offset_deg);
void driver_el_offset(int32_t offset_deg);
void driver_az_req_dn(int32_t offset_deg);
void driver_el_req_dn(int32_t offset_deg);
void driver_az_stop(void);
void driver_el_stop(void);
void driver_stop(void);
void driver_az_set_k(uint32_t k_deg2pulse);
void driver_el_set_k(uint32_t k_deg2pulse);
void driver_tick_ms(void);
struct coord driver_get_pos(void);
struct coord driver_get_offset(void);
void driver_origin(void);

#endif
