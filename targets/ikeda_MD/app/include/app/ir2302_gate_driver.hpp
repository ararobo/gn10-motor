
#pragma once
#include <cstdint>

#include "gn10_motor/i_gate_driver.hpp"

/**
 * @brief A3921 IC を使用したゲートドライバの具象クラス
 *
 * htim2 (CH1/CH2) と PHASE/SR GPIO を使用してモーターを駆動する。
 */
class IR2302GateDriver : public gn10_motor::IGateDriver
{
public:
    /**
     * @brief コンストラクタ
     * @param max_duty PWMタイマーのオートリロード値 (= 最大デューティ)
     */
    explicit IR2302GateDriver(uint16_t max_duty);

    /** @brief PWM・GPIOの初期化 */
    void hardware_init() override;

    /**
     * @brief モーター出力を設定する
     * @param output 正規化デューティ値 [-1.0, 1.0] (正: 正転, 負: 逆転)
     *               内部で max_duty_ にスケーリングする
     */
    void output(float output) override;

    /**
     * @brief ブレーキの有効/無効を設定する
     * @param brake true: ブレーキ有効, false: ブレーキ解除
     */
    void set_brake(bool brake) override;

private:
    uint16_t max_duty_;  ///< PWMタイマーの最大デューティ値
};