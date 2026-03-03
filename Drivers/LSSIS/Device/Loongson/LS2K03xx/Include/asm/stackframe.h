/*
 * Copyright (C) 2020-2025 Loongson Technology Corporation Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-03-10     LoongsonLab  the first version
 * 2025-03-12     LoongsonLab  add fpu support
 * 2025-03-13     LoongsonLab  fix save and restore
 */

#ifndef __ASM_STACKFRAME_H__
#define __ASM_STACKFRAME_H__

#include <asm/regdef.h>
#include <asm/asm-offsets.h>
#include <asm/loongarch.h>

#ifdef USING_FPU
#include <fpregdef.h>
#endif

#ifdef __ASSEMBLY__

#define LONG_ADD    add.d
#define LONG_ADDI   addi.d
#define LONG_STUB   sub.d
#define LONG_LD     ld.d
#define LONG_ST     st.d
#define LONG_FLD    fld.d
#define LONG_FST    fst.d

.macro BACKUP_T0T1
	csrwr	t0, EXCEPTION_KS0
	csrwr	t1, EXCEPTION_KS1
.endm

.macro RELOAD_T0T1
	csrrd   t0, EXCEPTION_KS0
	csrrd   t1, EXCEPTION_KS1
.endm

.macro	SAVE_TEMP
	RELOAD_T0T1
	LONG_ST	t0, sp, PT_R12
	LONG_ST	t1, sp, PT_R13
	LONG_ST	t2, sp, PT_R14
	LONG_ST	t3, sp, PT_R15
	LONG_ST	t4, sp, PT_R16
	LONG_ST	t5, sp, PT_R17
	LONG_ST	t6, sp, PT_R18
	LONG_ST	t7, sp, PT_R19
	LONG_ST	t8, sp, PT_R20
.endm

.macro	SAVE_STATIC
	LONG_ST	s0, sp, PT_R23
	LONG_ST	s1, sp, PT_R24
	LONG_ST	s2, sp, PT_R25
	LONG_ST	s3, sp, PT_R26
	LONG_ST	s4, sp, PT_R27
	LONG_ST	s5, sp, PT_R28
	LONG_ST	s6, sp, PT_R29
	LONG_ST	s7, sp, PT_R30
	LONG_ST	s8, sp, PT_R31
.endm


.macro	SAVE_SOME
	csrrd	t1, LOONGARCH_CSR_PRMD
	andi	t1, t1, 0x3	/* extract pplv bit */
	move	t0, sp
	beqz	t1, 8f
	/* Called from user mode, new stack. */
	csrrd   sp, EXCEPTION_KS2
8:
	addi.d  sp, sp, -PT_SIZE
	LONG_ST	t0, sp, PT_R3
	LONG_ST	zero, sp, PT_R0
	csrrd	t0, LOONGARCH_CSR_PRMD
	LONG_ST	t0, sp, PT_PRMD
	csrrd	t0, LOONGARCH_CSR_CRMD
	LONG_ST	t0, sp, PT_CRMD
	csrrd	t0, LOONGARCH_CSR_EUEN
	LONG_ST t0, sp, PT_EUEN
	csrrd	t0, LOONGARCH_CSR_ECFG
	LONG_ST	t0, sp, PT_ECFG
	csrrd	t0, LOONGARCH_CSR_ESTAT
	LONG_ST	t0, sp, PT_ESTAT
	LONG_ST	ra, sp, PT_R1
	LONG_ST	a0, sp, PT_R4
	LONG_ST	a1, sp, PT_R5
	LONG_ST	a2, sp, PT_R6
	LONG_ST	a3, sp, PT_R7
	LONG_ST	a4, sp, PT_R8
	LONG_ST	a5, sp, PT_R9
	LONG_ST	a6, sp, PT_R10
	LONG_ST	a7, sp, PT_R11
	csrrd	ra, LOONGARCH_CSR_ERA
	LONG_ST	ra, sp, PT_ERA
	LONG_ST	tp, sp, PT_R2
	LONG_ST	fp, sp, PT_R22

	/* Set thread_info if we're coming from user mode */
	csrrd	t0, LOONGARCH_CSR_PRMD
	andi	t0, t0, 0x3	/* extract pplv bit */
	beqz	t0, 9f

	LONG_ST	u0, sp, PT_R21
	csrrd	u0, PERCPU_BASE_KS
9:
.endm


.macro SAVE_ALL
	SAVE_SOME
	SAVE_TEMP
	SAVE_STATIC
.endm


.macro	RESTORE_TEMP
	LONG_LD	t0, sp, PT_R12
	LONG_LD	t1, sp, PT_R13
	LONG_LD	t2, sp, PT_R14
	LONG_LD	t3, sp, PT_R15
	LONG_LD	t4, sp, PT_R16
	LONG_LD	t5, sp, PT_R17
	LONG_LD	t6, sp, PT_R18
	LONG_LD	t7, sp, PT_R19
	LONG_LD	t8, sp, PT_R20
.endm

.macro	RESTORE_STATIC
	LONG_LD	s0, sp, PT_R23
	LONG_LD	s1, sp, PT_R24
	LONG_LD	s2, sp, PT_R25
	LONG_LD	s3, sp, PT_R26
	LONG_LD	s4, sp, PT_R27
	LONG_LD	s5, sp, PT_R28
	LONG_LD	s6, sp, PT_R29
	LONG_LD	s7, sp, PT_R30
	LONG_LD	s8, sp, PT_R31
.endm


.macro	RESTORE_SOME
	LONG_LD	a0, sp, PT_PRMD
	andi    a0, a0, 0x3	/* extract pplv bit */
	beqz    a0, 8f
	LONG_LD  u0, sp, PT_R21
8:
	LONG_LD	a0, sp, PT_ERA
	csrwr	a0, LOONGARCH_CSR_ERA
	LONG_LD	a0, sp, PT_PRMD
	csrwr	a0, LOONGARCH_CSR_PRMD
	LONG_LD	ra, sp, PT_R1
	LONG_LD	a0, sp, PT_R4
	LONG_LD	a1, sp, PT_R5
	LONG_LD	a2, sp, PT_R6
	LONG_LD	a3, sp, PT_R7
	LONG_LD	a4, sp, PT_R8
	LONG_LD	a5, sp, PT_R9
	LONG_LD	a6, sp, PT_R10
	LONG_LD	a7, sp, PT_R11
	LONG_LD	fp, sp, PT_R22

	addi.d  tp, sp, PT_SIZE
	csrwr	tp, EXCEPTION_KS2

	LONG_LD	tp, sp, PT_R2
.endm

.macro	RESTORE_SP_AND_RET
	LONG_LD	sp, sp, PT_R3
	ertn
.endm

.macro RESTORE_ALL_AND_RET
	RESTORE_STATIC
	RESTORE_TEMP
	RESTORE_SOME
	RESTORE_SP_AND_RET
.endm

#endif


#endif /* __ASM_STACKFRAME_H__ */