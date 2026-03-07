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

1:
b 1b

// todo: 内存训练，reloc 到 0x9000000003000000……
// 现在 ld 文件暂时写的是不初始化内存，用 Cache As RAM

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

/* Call static constructors */
	bl __libc_init_array

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

/* Enable FPU */
	li.d	t0, (1 << 0)
	csrxchg t0, t0, LOONGARCH_CSR_EUEN

/* Call the application's entry point.*/
	bl main
1:
b 1b
