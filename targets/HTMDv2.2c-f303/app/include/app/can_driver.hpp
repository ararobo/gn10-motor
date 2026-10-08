/**
 * @file driver_stm32_can.hpp
 * @author Gento Aiba (aiba-gento)
 * @brief STM32 CANのドライバ具体化クラスのヘッダファイル
 * @version 0.1.0
 * @date 2026-01-11
 *
 * @copyright Copyright (c) 2026
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <cstdint>

#include "gn10_can/drivers/can_driver_interface.hpp"
#include "main.h"

namespace gn10_can {
namespace drivers {

class CANDriver : public ICANDriver
{
public:
    CANDriver(CAN_HandleTypeDef* hcan) : hcan_(hcan) {}

    bool init();
    bool send(const CANFrame& frame) override;
    bool receive(CANFrame& out_frame) override;

private:
    CAN_HandleTypeDef* hcan_;
    const uint32_t TX_FIFO_TIMEOUT = 2;  // 送信FIFOが空くまで待つ際のタイムアウト
};
}  // namespace drivers
}  // namespace gn10_can
