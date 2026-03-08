# gn10-motor

[English](README.md) | [日本語](README_ja.md)

This repository contains firmware for the [HTMDv2.2c](https://github.com/ararobo/HTMDv2.2c) and [HTMDv2.2s](https://github.com/ararobo/HTMDv2.2s) boards.

HTMDv2.2c supports two MCUs: STM32F303K8T6 and STM32G431K8T6. HTMDv2.2s supports STM32G431CEU6.

## Board Overview

### Common Features (all boards)

| Feature | Detail |
| :-- | :-- |
| Motor driver IC | A3921 gate driver |
| Encoder | Incremental encoder (4096 counts/rev) |
| Board ID | 4-bit DIP switch (0– 15) |
| Limit switch | LIM1 |
| Control cycle | 1 ms (1 kHz) |
| Communication | CAN bus (gn10_can) |

### HTMDv2.2c-f303 (STM32F303K8T6)

| Feature | Detail |
| :-- | :-- |
| CAN | Standard CAN 2.0B |
| Sensors | — |

#### LED Indicators

| LED | Color | Behavior |
| :-- | :---- | :------- |
| LED1 | Red | Toggles every 100 ms — confirms control loop is running |
| LED2 | Red | Lit during reverse rotation (target < 0) |
| LED3 | Blue | Lit while rotating (target ≠ 0) |
| LED4 | Green | Lit after initialization |

### HTMDv2.2c-g431 (STM32G431K8T6)

| Feature | Detail |
| :-- | :-- |
| CAN | FDCAN |
| Sensors | — |

#### LED Indicators

| LED | Color | Behavior |
| :-- | :---- | :------- |
| LED1 | Red | Toggles every 100 ms — confirms control loop is running |
| LED2 | Red | Lit during reverse rotation (target < 0) |
| LED3 | Blue | Lit while rotating (target ≠ 0) |
| LED4 | Green | Lit after initialization |

### HTMDv2.2s (STM32G431CEU6)

| Feature | Detail |
| :-- | :-- |
| CAN | FDCAN |
| Temperature sensor | TMP275 (I2C, ±0.5°C accuracy) |
| Current sensor | MCP3421 (I2C, 16-bit ADC, PGA ×1) |

#### LED Indicators

| LED | Behavior |
| :-- | :------- |
| LED\_LGC\_PWR | Toggles every 100 ms — confirms control loop is running |
| LED\_CAN | Lit after initialization |

## Documentation

| Document | Description |
| :-: | :-: |
| [CONTRIBUTING.md](./CONTRIBUTING.md) | Development flow, commit conventions, coding rules |
| [docs/coding-rules.md](./docs/coding-rules.md) | Detailed coding rules |

## Development Environment Setup

### Common
Install **CMake Tools** extension for VSCode.

### Ubuntu
```bash
sudo apt update
sudo apt install -y build-essential cmake ninja-build gcc-arm-none-eabi gdb-multiarch
```

### Windows(for STM32)

Install STM32CubeCLT.

## Build

for STM32F303K8T6 (HTMDv2.2c-f303):
```bash
cmake --preset HTMDv2.2c-f303-debug
cmake --build --preset HTMDv2.2c-f303-debug
```
for STM32G431K8T6 (HTMDv2.2c-g431):
```bash
cmake --preset HTMDv2.2c-g431-debug
cmake --build --preset HTMDv2.2c-g431-debug
```
for HTMDv2.2s:
```bash
cmake --preset HTMDv2.2s-debug
cmake --build --preset HTMDv2.2s-debug
```

## Class Diagram

![class simplified](docs/uml/motor_driver_architecture_simplified.png)

## Contributing

See [CONTRIBUTING.md](./CONTRIBUTING.md) for details.

## License
This project is licensed under the Apache-2.0 - see the [LICENSE](LICENSE) file for details.