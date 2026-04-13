#ifndef __ASSEMBLY__
#define __ASSEMBLY__
#endif

#include <asm/regdef.h>
#include <asm/loongarch.h>
#include <asm/addrspace.h>
#include <linux/linkage.h>

.section .text.Reset_Handler
.global Reset_Handler
.type Reset_Handler, %function
Reset_Handler:

pcaddi t0, 0
li.d t1, 0xF000000000000000
and t0, t0, t1
bnez t0, boot_from_uboot

  // CPUCFG 0x0 PRID 处理器标识
  li.d   t0, (1 << (24 + 32))  //set CPUCFG 0 bit24
  csrxchg  t0, t0, LOONGARCH_CSR_MCSR0

  // CPUCFG 0x13 Index-log2 配置字 10 中 L2 IU Present 对应的 Cache
  // log2(每一路 Cache 行数) = 0xa
  li.d  t0, (0xa << (16 + 32))  //set CPUCFG 0x13 bit16-23
  li.d  t1, (0xff << (16 + 32))
  csrxchg  t0, t1, LOONGARCH_CSR_MCSR9

  // PLV0 特权等级下该性能监测器的计数使能。1——进行计数，0——停止计数。
  /* enable perf counter as cp0 counter */
  li.w  t0, (0x1 << 16)
  csrxchg t0, t0, LOONGARCH_CSR_PERFCTRL0

  /* open auto flush SFB */
  li.w  t0, (0x1 << 9)
  csrxchg t0, t0, LOONGARCH_CSR_IMPCTL1

  /* fast_ldq_dis close */
  li.w  t0, (0x1 << 12)
  csrxchg zero, t0, LOONGARCH_CSR_IMPCTL1

  /* low power setting */
  li.w  t0, 0xe
  csrxchg t0, t0, LOONGARCH_CSR_MCSR24

/*
* set DMW0(0x180) to uncached
* set DMW1(0x181) to cached
*/
  // DMW0: 强序非缓存，特权等级 PLV0-3 可用，0x8000 0000 0000 0000 - 0x8000 FFFF FFFF FFFF (PALEN = 48 时)
  li.d  t0, UNCACHED_MEMORY_ADDR | 0xf
  csrwr  t0, LOONGARCH_CSR_DMWIN0
  // DMW1: 一致可缓存，特权等级 PLV0-3 可用，0x9000 0000 0000 0000 - 0x9000 FFFF FFFF FFFF (PALEN = 48 时)
  li.d  t0, CACHED_MEMORY_ADDR | 0x1f
  csrwr  t0, LOONGARCH_CSR_DMWIN1

	// CSR ECFG VS 清零，所有例外和中断的入口地址是同一个。
	/* clear Vint cofigure */
	li.d	t0, (0x7 << 16)
	csrxchg zero, t0, LOONGARCH_CSR_ECFG

	// CSR EENTRY 异常入口 = 0x9000 0000 1c00 1000
	/* set ebase address */
	li.d	t0, PHYS_TO_CACHED(BOOT_SPACE_BASE + 0x1000)
	csrwr	t0, LOONGARCH_CSR_EENTRY

	// CSR TLBRENTRY 异常入口 = 0x1c00 1000
	/* set TLB excption address */
	li.d	t0, BOOT_SPACE_BASE + 0x1000
	csrwr	t0, LOONGARCH_CSR_TLBRENTRY

  // CPUCFG 0x3 LLEXC 为 1 表示支持 LL 指令取独占块功能
  /* enable llexc */
  li.w  t0, (1 << 3)
  csrxchg zero, t0, LOONGARCH_CSR_MCSR1

  // CSR IE 当前全局中断使能，高有效
  /* disable interrupt */
  li.d  t0, (1 << 2)
  csrxchg zero, t0, LOONGARCH_CSR_CRMD

  bl  lowlevel_init
  nop

  // 跳转到一致可缓存类型内存窗口继续执行
  li.d  t1, CACHED_MEMORY_ADDR
  pcaddi  t0, 3
  or  t0, t1, t0
  jirl  zero, t0, 0
  /* now pc run to 0x90xxxxxxxxxxxxxx */

  // DATF = 0b01 一致可缓存类型
  // DATM = 0b01 一致可缓存类型
  // PG = 1 DA = 0 使能映射地址翻译模式
  /* DA disable for 0x80xxxxxxxxxxxxxx and 0x90xxxxxxxxxxxx address can be used */
  li.w  t0, 0xb0
  csrwr  t0, LOONGARCH_CSR_CRMD

  // DBAR 指令用于完成 load/store 访存操作之间的栅障功能。
  dbar 0
  // IBAR 指令使用完成单个处理器核内部 store 操作与取指操作之间的同步。
  ibar 0
  nop

  // 将 SPL 程序搬运到 Locked Scache
  // a0 = LOCK_CACHE_BASE + LOCK_CACHE_SIZE
  bl    ram_init
  // now the ram top addr is in reg a0
  or  sp, a0, zero

	la.abs t0, boot_from_uboot
	jirl	zero, t0, 0

/* all exception entry */
	.org 0x1000
early_exception_vector:
1:
	b	1b


boot_from_uboot: // PC 在 dmw 窗口
// 我们假设此时文件已经被加载到了期望的内存地址 0x9000000003000000
// uboot 已经完成了内存训练、时钟初始化、UART0 初始化
// 所以理论上我可以直接跳转到初始化函数

/* Call the clock system initialization function.*/
	bl  SystemInit

/* Copy the data segment initializers from flash to SRAM */
	la.local t0, _sidata
	la.local t1, _sdata
	la.local t2, _edata
	b LoopCopyDataInit

LoopCopyDataInit:
	ld.w	t3, t0, 0
	st.w	t3, t1, 0
	addi.d	t0, t0, 4
	addi.d	t1, t1, 4
	blt	t1, t2, LoopCopyDataInit

/* Copy the small data segment initializers from flash to SRAM */
	la.local t0, _sisdata
	la.local t1, _ssdata
	la.local t2, _esdata
	b LoopCopySmallDataInit

LoopCopySmallDataInit:
	ld.w	t3, t0, 0
	st.w	t3, t1, 0
	addi.d	t0, t0, 4
	addi.d	t1, t1, 4
	blt	t1, t2, LoopCopySmallDataInit

/* Copy the GOT initializers from flash to SRAM */
	la.local t0, _sigot
	la.local t1, _sgot
	la.local t2, _egot
	b LoopCopyGOTInit

LoopCopyGOTInit:
	ld.w	t3, t0, 0
	st.w	t3, t1, 0
	addi.d	t0, t0, 4
	addi.d	t1, t1, 4
	blt	t1, t2, LoopCopyGOTInit

/* Zero fill the bss segment. */
	la.local	t0, _sbss
	la.local	t1, _ebss
	b LoopFillZerobss

LoopFillZerobss:
	st.w	zero, t0, 0
	addi.d	t0, t0, 4
	blt	t0, t1, LoopFillZerobss

	li.d	t0, (0x7 << 16)
	li.d	t1, (0x1 << 16)
	csrxchg t1, t0, LOONGARCH_CSR_ECFG

	li.d	t0, 0x1FFF
	li.d	t1, 0x1FFF
	csrxchg t1, t0, LOONGARCH_CSR_ECFG

	la t0, exception_vector_base
	csrwr	t0, LOONGARCH_CSR_EENTRY
	li.d	t1, TO_PHYS_MASK
	and t0, t0, t1
	csrwr	t0, LOONGARCH_CSR_TLBRENTRY

	li.d	t0, (1 << 2)
	csrxchg t0, t0, LOONGARCH_CSR_CRMD

/* Call static constructors */
	bl __libc_init_array

/* Enable FPU */
	li.d	t0, (1 << 0)
	csrxchg t0, t0, LOONGARCH_CSR_EUEN

/* Call the application's entry point.*/
	bl main
1:
b 1b
