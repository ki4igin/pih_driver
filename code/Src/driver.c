#include "driver.h"
#include "main.h"
#include "motor.h"
#include "stm32f4xx_ll_gpio.h"

static struct motor az = {
    .gpio_p = {S3_GPIO_Port, S3_Pin},
    .gpio_n = {S4_GPIO_Port, S4_Pin},
    .k_deg2pulse = 19,
    .RESP_DN = CMD_AZ_REQ_DN,
};

static struct motor el = {
    .gpio_p = {S1_GPIO_Port, S1_Pin},
    .gpio_n = {S2_GPIO_Port, S2_Pin},
    .k_deg2pulse = 19,
    .RESP_DN = CMD_EL_REQ_DN,
};

void driver_az_offset(int32_t offset_deg)
{
    motor_offset(&az, offset_deg);
}

void driver_el_offset(int32_t offset_deg)
{
    motor_offset(&el, offset_deg);
}

void driver_offset(struct coord offset)
{
    motor_offset(&az, offset.az);
    motor_offset(&el, offset.el);
}

void driver_az_req_dn(int32_t offset_deg)
{
    motor_req_dn(&az, offset_deg);
}

void driver_el_req_dn(int32_t offset_deg)
{
    motor_req_dn(&el, offset_deg);
}

void driver_az_stop(void)
{
    motor_stop(&az);
}

void driver_el_stop(void)
{
    motor_stop(&el);
}

void driver_stop(void)
{
    motor_stop(&az);
    motor_stop(&el);
}

void driver_az_set_k(uint32_t k_deg2pulse)
{
    az.k_deg2pulse = k_deg2pulse;
}

void driver_el_set_k(uint32_t k_deg2pulse)
{
    el.k_deg2pulse = k_deg2pulse;
}

struct coord driver_get_pos(void)
{
    return (struct coord){
        .az = motor_get_pos(&az),
        .el = motor_get_pos(&el),
    };
}

struct coord driver_get_offset(void)
{
    return (struct coord){
        .az = motor_get_offset(&az),
        .el = motor_get_offset(&el),
    };
}

void driver_origin(void)
{
    motor_set_origin(&az);
    motor_set_origin(&el);
}

void driver_tick_ms(void)
{
    motor_mov_process(&az);
    motor_mov_process(&el);
}
