#include "app/ir2302_gate_driver.hpp"

#include <algorithm>
#include <cstdint>

#include "gpio.h"
#include "tim.h"

IR2302GateDriver::IR2302GateDriver(uint16_t max_duty) : max_duty_(max_duty) {}

void IR2302GateDriver::hardware_init()
{
    // PWM および GPIO の初期化
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

    set_brake(true);  // 自クラスの set_brake() 経由で統一する
}

void IR2302GateDriver::output(float output)
{
    output = std::clamp(output, -1.0f, 1.0f) * static_cast<float>(max_duty_);

    if (output < 0.0f) {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, static_cast<uint32_t>(output));
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
    } else {
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, static_cast<uint32_t>(-output));
    }
}

void IR2302GateDriver::set_brake(bool brake)
{
    /**/
}