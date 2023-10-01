
#include "tim.h"

void MX_TIM10_Init(void)
{
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM10);

    NVIC_SetPriority(TIM1_UP_TIM10_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
    NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);

    LL_TIM_InitTypeDef TIM_InitStruct = {
        .Prescaler = 2 - 1,
        .CounterMode = LL_TIM_COUNTERMODE_UP,
        .Autoreload = 42000 - 1,
        .ClockDivision = LL_TIM_CLOCKDIVISION_DIV1,
    };
    LL_TIM_Init(TIM10, &TIM_InitStruct);
    LL_TIM_EnableARRPreload(TIM10);
    LL_TIM_EnableIT_UPDATE(TIM10);
}

void MX_TIM11_Init(void)
{
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM11);

    NVIC_SetPriority(TIM1_TRG_COM_TIM11_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 0, 0));
    NVIC_EnableIRQ(TIM1_TRG_COM_TIM11_IRQn);

    LL_TIM_InitTypeDef TIM_InitStruct = {
        .Prescaler = 84 - 1,
        .CounterMode = LL_TIM_COUNTERMODE_UP,
        .Autoreload = 400 - 1,
        .ClockDivision = LL_TIM_CLOCKDIVISION_DIV1,
    };
    LL_TIM_Init(TIM11, &TIM_InitStruct);
    LL_TIM_EnableARRPreload(TIM11);
    LL_TIM_EnableIT_UPDATE(TIM11);
}
