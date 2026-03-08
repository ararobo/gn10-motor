# gn10-motor

[English](README.md) | [日本語](README_ja.md)

このリポジトリには [HTMDv2.2c](https://github.com/ararobo/HTMDv2.2c)・[HTMDv2.2s](https://github.com/ararobo/HTMDv2.2s) という基板のファームウェアが含まれています。

HTMDv2.2c は STM32F303K8T6 と STM32G431K8T6 の2つの MCU に対応しており、HTMDv2.2s は STM32G431CEU6 に対応しています。

## ボード概要

### 共通機能 (全ボード)

| 機能 | 詳細 |
| :-- | :-- |
| モータードライバー IC | A3921 ゲートドライバ |
| エンコーダ | インクリメンタルエンコーダ（4096 count/rev） |
| ボード ID | 4bit DIP スイッチ（0～15） |
| リミットスイッチ | LIM1 |
| 制御周期 | 1 ms（1 kHz） |
| 通信 | CAN バス（gn10_can） |

### HTMDv2.2c-f303 (STM32F303K8T6)

| 機能 | 詳細 |
| :-- | :-- |
| CAN | Standard CAN 2.0B |
| センサー | — |

#### LED インジケーター

| LED | 色 | 動作 |
| :-- | :-- | :-- |
| LED1 | 赤 | 100 ms ごとにトグル — 制御ループ動作確認 |
| LED2 | 赤 | 逆回転中点灯（目標値 < 0） |
| LED3 | 青 | 回転中点灯（目標値 ≠ 0） |
| LED4 | 緑 | 初期化完了後常時点灯 |

### HTMDv2.2c-g431 (STM32G431K8T6)

| 機能 | 詳細 |
| :-- | :-- |
| CAN | FDCAN |
| センサー | — |

#### LED インジケーター

| LED | 色 | 動作 |
| :-- | :-- | :-- |
| LED1 | 赤 | 100 ms ごとにトグル — 制御ループ動作確認 |
| LED2 | 赤 | 逆回転中点灯（目標値 < 0） |
| LED3 | 青 | 回転中点灯（目標値 ≠ 0） |
| LED4 | 緑 | 初期化完了後常時点灯 |

### HTMDv2.2s (STM32G431CEU6)

| 機能 | 詳細 |
| :-- | :-- |
| CAN | FDCAN |
| 温度センサー | TMP275（I2C、置度精度 ±0.5°C） |
| 電流センサー | MCP3421（I2C、16-bit ADC、PGA ×1） |

#### LED インジケーター

| LED | 動作 |
| :-- | :-- |
| LED\_LGC\_PWR | 100 ms ごとにトグル — 制御ループ動作確認 |
| LED\_CAN | 初期化完了後常時点灯 |
## ドキュメント

| ドキュメント | 説明 |
| :-: | :-: |
| [CONTRIBUTING.md](./CONTRIBUTING.md) | 開発フロー・コミット規約・コーディング規約 |
| [docs/coding-rules.md](./docs/coding-rules.md) | コーディング規約の詳細 |

## 開発環境のセットアップ

### 共通
VSCode の **CMake Tools** 拡張機能をインストールしてください。

### Ubuntu
```bash
sudo apt update
sudo apt install -y build-essential cmake ninja-build gcc-arm-none-eabi gdb-multiarch
```

### Windows (STM32用)
STM32CubeCLT をインストールしてください。

## ビルド方法

STM32F303K8T6 用 (HTMDv2.2c-f303):
```bash
cmake --preset HTMDv2.2c-f303-debug
cmake --build --preset HTMDv2.2c-f303-debug
```

STM32G431K8T6 用 (HTMDv2.2c-g431):
```bash
cmake --preset HTMDv2.2c-g431-debug
cmake --build --preset HTMDv2.2c-g431-debug
```

HTMDv2.2s 用:
```bash
cmake --preset HTMDv2.2s-debug
cmake --build --preset HTMDv2.2s-debug
```

## クラス図

![class simplified](docs/uml/motor_driver_architecture_simplified.png)

## コントリビューション

[CONTRIBUTING.md](./CONTRIBUTING.md) を参照してください。

## ライセンス
このプロジェクトは Apache-2.0 ライセンスの下で提供されています。詳細は [LICENSE](LICENSE) ファイルを参照してください。
