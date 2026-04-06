# LS2K03xx SoC Firmware Package

Loongson LS2K03xx 系列处理器固件开发包，基于 STM32 HAL 风格 API 移植。

## 目录

- [概述](#概述)
- [HAL 完成进度](#hal-完成进度)
- [工具链构建](#工具链构建)
- [Example 构建教程](#example-构建教程)

## 概述

本项目提供 LS2K03xx 系列芯片的硬件抽象层 (HAL) 驱动，API 设计风格参考 STM32 HAL，便于开发者快速上手。

## HAL 完成进度

### 外设驱动支持与测试情况

| 外设          | Polling            | IRQ    | DMA    | 备注                     |
| :------------ | :-------:          | :----: | :----: | :----------------------- |
| **GPIO**      | TESTED             | -      | -      | 输入输出，复用管理       |
| **UART**      | TESTED             | -      | -      | 串口收发(Polling 模式)   |
| **I2C**       | TESTED             | OK     | -      | 仅测试驱动 VL53L0x 模块  |
| **SPI_IO**    | OK(发送功能已测试) | -      | -      | 仅测试发送               |
| **SPI_Flash** | OK(发送功能已测试) | -      | N/A    | 仅测试发送               |
| **ADC**       | OK                 | OK     | TESTED | 仅测试 ADC DMA 连续转换  |
| **TIM**       | TESTED             | TESTED | TESTED | ATIM/GTIM/BTIM           |
| **DMA**       | -                  | TESTED | TESTED | 通用 DMA 控制器          |
| **LIOINTC**   | N/A                | TESTED | N/A    | 传统 IO 中断控制器       |

**图例**:

- TESTED = 已完成且可用
- OK = 部分测试或仅编译通过
- WIP = 开发中
- \- = 暂不支持
- N/A = 硬件无此特性

## 工具链构建

### 已验证的环境

- Linux 环境 (WSL2 可用)
- `crosstool-ng` >= 1.28.0

### 构建步骤

#### 1. 安装 crosstool-ng

#### 2. 创建工具链配置

```bash
# 创建目录并进入目录

# 套用模板
ct-ng loongarch64-unknown-linux-gnu
# 修改配置
ct-ng menuconfig
```

修改 `Operating System ---> Target OS` 为 `bare-metal`

修改 `C-library  --->  Source of newlib` 为 `Vendor/custom repository`

修改 `C-library  --->  Repository URL` 为 `https://github.com/loongson/newlib.git`

修改 `C-library  --->  Branch/tag to check out` 为 `loongarch_v4.5.0`

保存并退出

#### 3. 构建工具链

```bash
# 开始构建
ct-ng build

# 构建完成后，工具链安装在 ~/xtools/loongarch64-unknown-elf
export PATH=$PATH:~/x-tools/loongarch64-unknown-elf/bin/
```

#### 4. 验证工具链

```bash
loongarch64-unknown-elf-gcc --version
# 应显示: loongarch64-unknown-elf-gcc (crosstool-NG ...) ...

# 测试编译
loongarch64-unknown-elf-gcc -v
```

## Example 构建教程

### 前置要求

1. **安装 `CMake`, `Ninja`**
2. **安装工具链**: `loongarch64-unknown-elf` (见上节)
3. **设置环境变量**: 见上节

### 构建示例

#### 使用 CMake 预设 (推荐)

每个 Example 都包含 `CMakePresets.json`，已配置好构建参数。

```bash
cd Projects/ATK-DL2K0300B/Examples/ADC

cmake --preset Release
cmake --build --preset Release

# 生成的文件位于 build/Release/
ls -la build/Release/
```

### 运行

编译生成的 `.bin` 文件可通过以下方式运行：

#### U-boot 加载运行

这是目前支持的唯一方法

```bash
# 假设已经配置好 ip
tftpboot qwq.bin 0x9000000003000000
go 0x9000000003000000
```
