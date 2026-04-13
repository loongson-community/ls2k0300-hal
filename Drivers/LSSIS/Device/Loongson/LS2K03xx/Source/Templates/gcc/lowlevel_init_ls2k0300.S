#ifndef __ASSEMBLY__
#define __ASSEMBLY__
#endif

#include <linux/linkage.h>
#include <asm/regdef.h>
#include <asm/loongarch.h>
#include <asm/addrspace.h>
#include <ls2k0300.h>

// Note: the Address mapping window NOT setup yet.
// 		 so, use the real physicl address.

ENTRY(lowlevel_init)
    or     a4, ra, zero

	// CPUCFG 0x4 CC_FREQ 恒定频率计时器和定时器所用时钟对应的晶振频率 0x0727 0E00 (120,000,000Hz = 120MHz)
	// CPUCFG 0x5 CC_MUL 恒定频率计时器和定时器所用时钟对应的倍频因子 0x1
	// CPUCFG 0x5 CC_DIV 恒定频率计时器和定时器所用时钟对应的分频系数 0x1
	// 修复参考时钟计算错误的问题（可能默认值为 100MHz?）
	li.d	t0, 0x0001000107270e00
	csrwr	t0, LOONGARCH_CSR_MCSR2

	// 芯片通用配置寄存器 00 : ddr4_regs_default 窗口不命中处理 1：当访问内存控制器所有窗口不命中时，由内存配置空间默认给出响应，防止内存访问卡死
	li.d	t0, LS_GENERAL_CFG0
	ld.w	t1, t0, 0x0
	li.w	t2, (1 << 5)
	or	t1, t1, t2
	st.w	t1, t0, 0x0

	// SPI0 0x4 SFC_PARAM clk_div=4 
	// fast_read = 1 快速读模式
	// burst_en = 1 SPI flash 支持连续地址读模式
	// memory_en = 1 SPI flash 读使能，无效时 csn[0]可由软件控制。
	li.d	t0, SPI0_BASE
	li.w	t1, 0x47
	st.b	t1, t0, 0x4

	// 手册里没看到
	/*close usb & ddr soft reset: [0] ddr, [7] usbm*/
	li.w  	t1, 0xffffff7e
	st.w 	t1, t0, 0x1c

	/*unvalid ddr soft reset: [0] ddr*/
	ld.w	t1, t0, 0x1c
	ori     t1, t1, 0x1
	st.w 	t1, t0, 0x1c

	// apb设备DMA/usb/gmac0/gmac1/dc 使能设备CACHE访问配置有效 + 开启CACHE加速访问
	/*[103:96] en [111:104] coherent*/
	/*0:cpu    1:usb     2:gmac0    3:gmac1   4:dc
		5:apb-dma(sdio spi can .etc)*/
	li.d	t0, LS_GENERAL_CFG3
	ld.w	t1, t0, 0x0
	li.w	t2, ((0x1f << 1) | (0x1f << 9))  //cache coherent for usb/gmac0/gmac1/dc
	or	t1, t1, t2
	st.w	t1, t0, 0x0

	#include "clksetting_2k0300.S"

	//delay a while
	li.d	t1, 0x100
1:
	addi.d	t1, t1, -1
	bnez	t1, 1b
	nop

	or	ra, a4, zero
	ret
ENDPROC(lowlevel_init)

ENTRY(ram_init)
	or	s1, ra, zero


	// 见《龙芯3A5000_3B5000处理器寄存器使用手册》 第九节 共享 Cache（SCache）
	// Lock Scache
	li.d	t0, LS_SCACHE_LOCK_WIN0_BASE
	li.d	t1, ~(LOCK_CACHE_SIZE - 1)
	// 写 LS_SCACHE_LOCK_WIN0_MASK 0xFFFF FFFF FFFC 0000
	st.d	t1, t0, 0x40
	li.d	t1, (LOCK_CACHE_BASE & 0xffffffffffff) | (1 << 63)
	// 写 LS_SCACHE_LOCK_WIN0_BASE 0x8000 0000 9000 0000
	st.d	t1, t0, 0x0

	// 循环每 4B 从 SPI0 Boot 地址复制程序到 __image_copy_start __image_copy_end 之间的 locked scache
	// copy spl code to locked scache
	li.d	t0, BOOT_SPACE_BASE_CACHED
	/* la 伪指令会被错误的优化成 pcaddi 指令 */
	la.abs t1, __image_copy_start
	la.abs t2, __image_copy_end

1:
	ld.w	t3, t0, 0
	st.w	t3, t1, 0
	addi.d	t0, t0, 4
	addi.d	t1, t1, 4
	blt	t1, t2, 1b

	li.d	a0, LOCK_CACHE_BASE + LOCK_CACHE_SIZE

	or	ra, s1, zero
	ret
ENDPROC(ram_init)
