/*
 * Copyright (C) 2020-2025 Loongson Technology Corporation Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Description: this header is forked from linux project.
 *              LoongArch arch privilege CSR Registers
 *              Detailed documents access website:
 *              https://loongson.cn 
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-03-10     LoongsonLab  the first version
 * 2025-03-13     LoongsonLab  Add CSR operation
 * 2025-03-13     LoongsonLab  Add TLB Refill operations
 */

#ifndef _ASM_LOONGARCH_H
#define _ASM_LOONGARCH_H

#ifndef __ASSEMBLY__
#include <larchintrin.h>
/* CPUCFG */
#define read_cpucfg(reg) __cpucfg(reg)

#endif /* !__ASSEMBLY__ */

#define BIT(x) (1UL << (x))

/* Bit fields for CPUCFG registers */
#define LOONGARCH_CPUCFG0		0x0
#define  CPUCFG0_PRID			GENMASK(31, 0)

#define LOONGARCH_CPUCFG1		0x1
#define  CPUCFG1_ISGR32			BIT(0)
#define  CPUCFG1_ISGR64			BIT(1)
#define  CPUCFG1_ISA			GENMASK(1, 0)
#define  CPUCFG1_PAGING			BIT(2)
#define  CPUCFG1_IOCSR			BIT(3)
#define  CPUCFG1_PABITS			GENMASK(11, 4)
#define  CPUCFG1_VABITS			GENMASK(19, 12)
#define  CPUCFG1_UAL			BIT(20)
#define  CPUCFG1_RI			BIT(21)
#define  CPUCFG1_EP			BIT(22)
#define  CPUCFG1_RPLV			BIT(23)
#define  CPUCFG1_HUGEPG			BIT(24)
#define  CPUCFG1_CRC32			BIT(25)
#define  CPUCFG1_MSGINT			BIT(26)

#define LOONGARCH_CPUCFG2		0x2
#define  CPUCFG2_FP			BIT(0)
#define  CPUCFG2_FPSP			BIT(1)
#define  CPUCFG2_FPDP			BIT(2)
#define  CPUCFG2_FPVERS			GENMASK(5, 3)
#define  CPUCFG2_LSX			BIT(6)
#define  CPUCFG2_LASX			BIT(7)
#define  CPUCFG2_COMPLEX		BIT(8)
#define  CPUCFG2_CRYPTO			BIT(9)
#define  CPUCFG2_LVZP			BIT(10)
#define  CPUCFG2_LVZVER			GENMASK(13, 11)
#define  CPUCFG2_LLFTP			BIT(14)
#define  CPUCFG2_LLFTPREV		GENMASK(17, 15)
#define  CPUCFG2_X86BT			BIT(18)
#define  CPUCFG2_ARMBT			BIT(19)
#define  CPUCFG2_MIPSBT			BIT(20)
#define  CPUCFG2_LSPW			BIT(21)
#define  CPUCFG2_LAM			BIT(22)
#define  CPUCFG2_PTW			BIT(24)

#define LOONGARCH_CPUCFG3		0x3
#define  CPUCFG3_CCDMA			BIT(0)
#define  CPUCFG3_SFB			BIT(1)
#define  CPUCFG3_UCACC			BIT(2)
#define  CPUCFG3_LLEXC			BIT(3)
#define  CPUCFG3_SCDLY			BIT(4)
#define  CPUCFG3_LLDBAR			BIT(5)
#define  CPUCFG3_ITLBT			BIT(6)
#define  CPUCFG3_ICACHET		BIT(7)
#define  CPUCFG3_SPW_LVL		GENMASK(10, 8)
#define  CPUCFG3_SPW_HG_HF		BIT(11)
#define  CPUCFG3_RVA			BIT(12)
#define  CPUCFG3_RVAMAX			GENMASK(16, 13)

#define LOONGARCH_CPUCFG4		0x4
#define  CPUCFG4_CCFREQ			GENMASK(31, 0)

#define LOONGARCH_CPUCFG5		0x5
#define  CPUCFG5_CCMUL			GENMASK(15, 0)
#define  CPUCFG5_CCDIV			GENMASK(31, 16)

#define LOONGARCH_CPUCFG6		0x6
#define  CPUCFG6_PMP			BIT(0)
#define  CPUCFG6_PAMVER			GENMASK(3, 1)
#define  CPUCFG6_PMNUM			GENMASK(7, 4)
#define  CPUCFG6_PMNUM_SHIFT		4
#define  CPUCFG6_PMBITS			GENMASK(13, 8)
#define  CPUCFG6_UPM			BIT(14)

#define LOONGARCH_CPUCFG16		0x10
#define  CPUCFG16_L1_IUPRE		BIT(0)
#define  CPUCFG16_L1_IUUNIFY		BIT(1)
#define  CPUCFG16_L1_DPRE		BIT(2)
#define  CPUCFG16_L2_IUPRE		BIT(3)
#define  CPUCFG16_L2_IUUNIFY		BIT(4)
#define  CPUCFG16_L2_IUPRIV		BIT(5)
#define  CPUCFG16_L2_IUINCL		BIT(6)
#define  CPUCFG16_L2_DPRE		BIT(7)
#define  CPUCFG16_L2_DPRIV		BIT(8)
#define  CPUCFG16_L2_DINCL		BIT(9)
#define  CPUCFG16_L3_IUPRE		BIT(10)
#define  CPUCFG16_L3_IUUNIFY		BIT(11)
#define  CPUCFG16_L3_IUPRIV		BIT(12)
#define  CPUCFG16_L3_IUINCL		BIT(13)
#define  CPUCFG16_L3_DPRE		BIT(14)
#define  CPUCFG16_L3_DPRIV		BIT(15)
#define  CPUCFG16_L3_DINCL		BIT(16)

#define LOONGARCH_CPUCFG17		0x11
#define LOONGARCH_CPUCFG18		0x12
#define LOONGARCH_CPUCFG19		0x13
#define LOONGARCH_CPUCFG20		0x14
#define  CPUCFG_CACHE_WAYS_M		GENMASK(15, 0)
#define  CPUCFG_CACHE_SETS_M		GENMASK(23, 16)
#define  CPUCFG_CACHE_LSIZE_M		GENMASK(30, 24)
#define  CPUCFG_CACHE_WAYS	 	0
#define  CPUCFG_CACHE_SETS		16
#define  CPUCFG_CACHE_LSIZE		24

#define LOONGARCH_CPUCFG48		0x30
#define  CPUCFG48_MCSR_LCK		BIT(0)
#define  CPUCFG48_NAP_EN		BIT(1)
#define  CPUCFG48_VFPU_CG		BIT(2)
#define  CPUCFG48_RAM_CG		BIT(3)

#ifndef __ASSEMBLY__

/* CSR */
#define csr_read32(reg) __csrrd_w(reg)
#define csr_read64(reg) __csrrd_d(reg)
#define csr_write32(val, reg) __csrwr_w(val, reg)
#define csr_write64(val, reg) __csrwr_d(val, reg)
#define csr_xchg32(val, mask, reg) __csrxchg_w(val, mask, reg)
#define csr_xchg64(val, mask, reg) __csrxchg_d(val, mask, reg)

/* IOCSR */
#define iocsr_read32(reg) __iocsrrd_w(reg)
#define iocsr_read64(reg) __iocsrrd_d(reg)
#define iocsr_write32(val, reg) __iocsrwr_w(val, reg)
#define iocsr_write64(val, reg) __iocsrwr_d(val, reg)

#endif /* !__ASSEMBLY__ */

#ifdef __ASSEMBLY__
#define _ULCAST_ 
#define __CONST64_(X,Y)	(X)
#define _CONST64_(X)	__CONST64_(X, UL)
#define BIT_ULL(x)
#else 
#define _ULCAST_ (unsigned long)
#define __CONST64_(X,Y)	(X##Y)
#define _CONST64_(X)	__CONST64_(X, UL)
#define BIT_ULL(x) (1ULL<<x)
#endif

/* Basic CSR registers */
#define LOONGARCH_CSR_CRMD		0x0	/* Current mode info */
#define  CSR_CRMD_WE_SHIFT		9
#define  CSR_CRMD_WE			(_ULCAST_(0x1) << CSR_CRMD_WE_SHIFT)
#define  CSR_CRMD_DACM_SHIFT		7
#define  CSR_CRMD_DACM_WIDTH		2
#define  CSR_CRMD_DACM			(_ULCAST_(0x3) << CSR_CRMD_DACM_SHIFT)
#define  CSR_CRMD_DACF_SHIFT		5
#define  CSR_CRMD_DACF_WIDTH		2
#define  CSR_CRMD_DACF			(_ULCAST_(0x3) << CSR_CRMD_DACF_SHIFT)
#define  CSR_CRMD_PG_SHIFT		4
#define  CSR_CRMD_PG			(_ULCAST_(0x1) << CSR_CRMD_PG_SHIFT)
#define  CSR_CRMD_DA_SHIFT		3
#define  CSR_CRMD_DA			(_ULCAST_(0x1) << CSR_CRMD_DA_SHIFT)
#define  CSR_CRMD_IE_SHIFT		2
#define  CSR_CRMD_IE			(_ULCAST_(0x1) << CSR_CRMD_IE_SHIFT)
#define  CSR_CRMD_PLV_SHIFT		0
#define  CSR_CRMD_PLV_WIDTH		2
#define  CSR_CRMD_PLV			(_ULCAST_(0x3) << CSR_CRMD_PLV_SHIFT)

#define PLV_KERN			0
#define PLV_USER			3
#define PLV_MASK			0x3

#define LOONGARCH_CSR_PRMD		0x1	/* Prev-exception mode info */
#define  CSR_PRMD_PWE_SHIFT		3
#define  CSR_PRMD_PWE			(_ULCAST_(0x1) << CSR_PRMD_PWE_SHIFT)
#define  CSR_PRMD_PIE_SHIFT		2
#define  CSR_PRMD_PIE			(_ULCAST_(0x1) << CSR_PRMD_PIE_SHIFT)
#define  CSR_PRMD_PPLV_SHIFT		0
#define  CSR_PRMD_PPLV_WIDTH		2
#define  CSR_PRMD_PPLV			(_ULCAST_(0x3) << CSR_PRMD_PPLV_SHIFT)

#define LOONGARCH_CSR_EUEN		0x2	/* Extended unit enable */
#define  CSR_EUEN_LBTEN_SHIFT		3
#define  CSR_EUEN_LBTEN			(_ULCAST_(0x1) << CSR_EUEN_LBTEN_SHIFT)
#define  CSR_EUEN_LASXEN_SHIFT		2
#define  CSR_EUEN_LASXEN		(_ULCAST_(0x1) << CSR_EUEN_LASXEN_SHIFT)
#define  CSR_EUEN_LSXEN_SHIFT		1
#define  CSR_EUEN_LSXEN			(_ULCAST_(0x1) << CSR_EUEN_LSXEN_SHIFT)
#define  CSR_EUEN_FPEN_SHIFT		0
#define  CSR_EUEN_FPEN			(_ULCAST_(0x1) << CSR_EUEN_FPEN_SHIFT)

#define LOONGARCH_CSR_MISC		0x3	/* Misc config */

#define LOONGARCH_CSR_ECFG		0x4	/* Exception config */
#define  CSR_ECFG_VS_SHIFT		16
#define  CSR_ECFG_VS_WIDTH		3
#define  CSR_ECFG_VS_SHIFT_END		(CSR_ECFG_VS_SHIFT + CSR_ECFG_VS_WIDTH - 1)
#define  CSR_ECFG_VS			(_ULCAST_(0x7) << CSR_ECFG_VS_SHIFT)
#define  CSR_ECFG_IM_SHIFT		0
#define  CSR_ECFG_IM_WIDTH		14
#define  CSR_ECFG_IM			(_ULCAST_(0x3fff) << CSR_ECFG_IM_SHIFT)

#define LOONGARCH_CSR_ESTAT		0x5	/* Exception status */
#define  CSR_ESTAT_ESUBCODE_SHIFT	22
#define  CSR_ESTAT_ESUBCODE_WIDTH	9
#define  CSR_ESTAT_ESUBCODE		(_ULCAST_(0x1ff) << CSR_ESTAT_ESUBCODE_SHIFT)
#define  CSR_ESTAT_EXC_SHIFT		16
#define  CSR_ESTAT_EXC_WIDTH		6
#define  CSR_ESTAT_EXC			(_ULCAST_(0x3f) << CSR_ESTAT_EXC_SHIFT)
#define  CSR_ESTAT_IS_SHIFT		0
#define  CSR_ESTAT_IS_WIDTH		15
#define  CSR_ESTAT_IS			(_ULCAST_(0x7fff) << CSR_ESTAT_IS_SHIFT)

#define  CSR_ESTAT_IS_IPI		(_ULCAST_(0x1000) << CSR_ESTAT_IS_SHIFT)
#define  CSR_ESTAT_IS_TI		(_ULCAST_(0x800) << CSR_ESTAT_IS_SHIFT)
#define  CSR_ESTAT_IS_PMC		(_ULCAST_(0x400) << CSR_ESTAT_IS_SHIFT)
#define  CSR_ESTAT_IS_HW		(_ULCAST_(0x3fc) << CSR_ESTAT_IS_SHIFT)
#define  CSR_ESTAT_IS_SW		(_ULCAST_(0x3) << CSR_ESTAT_IS_SHIFT)

// CSR ECFG
#define ECFG0_IM		0x00005fff
#define ECFGB_SIP0		0
#define ECFGF_SIP0		(_ULCAST_(1) << ECFGB_SIP0)
#define ECFGB_SIP1		1
#define ECFGF_SIP1		(_ULCAST_(1) << ECFGB_SIP1)
#define ECFGB_IP0		2
#define ECFGF_IP0		(_ULCAST_(1) << ECFGB_IP0)
#define ECFGB_IP1		3
#define ECFGF_IP1		(_ULCAST_(1) << ECFGB_IP1)
#define ECFGB_IP2		4
#define ECFGF_IP2		(_ULCAST_(1) << ECFGB_IP2)
#define ECFGB_IP3		5
#define ECFGF_IP3		(_ULCAST_(1) << ECFGB_IP3)
#define ECFGB_IP4		6
#define ECFGF_IP4		(_ULCAST_(1) << ECFGB_IP4)
#define ECFGB_IP5		7
#define ECFGF_IP5		(_ULCAST_(1) << ECFGB_IP5)
#define ECFGB_IP6		8
#define ECFGF_IP6		(_ULCAST_(1) << ECFGB_IP6)
#define ECFGB_IP7		9
#define ECFGF_IP7		(_ULCAST_(1) << ECFGB_IP7)
#define ECFGB_PMC		10
#define ECFGF_PMC		(_ULCAST_(1) << ECFGB_PMC)
#define ECFGB_TIMER		11
#define ECFGF_TIMER		(_ULCAST_(1) << ECFGB_TIMER)
#define ECFGB_IPI		12
#define ECFGF_IPI		(_ULCAST_(1) << ECFGB_IPI)
#define ECFGF(hwirq)		(_ULCAST_(1) << hwirq)

#define ESTATF_IP		0x00003fff


#define set_csr_estat(val)	\
	csr_xchg32(val, val, LOONGARCH_CSR_ESTAT)
#define clear_csr_estat(val)	\
	csr_xchg32(~(val), val, LOONGARCH_CSR_ESTAT)


#define LOONGARCH_CSR_ERA		0x6	/* Exception return address */

#define LOONGARCH_CSR_BADV		0x7	/* Bad virtual address */

#define LOONGARCH_CSR_BADI		0x8	/* Bad instruction */

#define LOONGARCH_CSR_EENTRY		0xc	/* Exception entry */

/* TLB related CSR registers */
#define LOONGARCH_CSR_TLBIDX		0x10	/* TLB Index, EHINV, PageSize, NP */
#define  CSR_TLBIDX_EHINV_SHIFT		31
#define  CSR_TLBIDX_EHINV		(_ULCAST_(1) << CSR_TLBIDX_EHINV_SHIFT)
#define  CSR_TLBIDX_PS_SHIFT		24
#define  CSR_TLBIDX_PS_WIDTH		6
#define  CSR_TLBIDX_PS			(_ULCAST_(0x3f) << CSR_TLBIDX_PS_SHIFT)
#define  CSR_TLBIDX_IDX_SHIFT		0
#define  CSR_TLBIDX_IDX_WIDTH		12
#define  CSR_TLBIDX_IDX			(_ULCAST_(0xfff) << CSR_TLBIDX_IDX_SHIFT)
#define  CSR_TLBIDX_SIZEM		0x3f000000
#define  CSR_TLBIDX_SIZE		CSR_TLBIDX_PS_SHIFT
#define  CSR_TLBIDX_IDXM		0xfff
#define  CSR_INVALID_ENTRY(e)		(CSR_TLBIDX_EHINV | e)

#define LOONGARCH_CSR_TLBEHI		0x11	/* TLB EntryHi */

#define LOONGARCH_CSR_TLBELO0		0x12	/* TLB EntryLo0 */
#define  CSR_TLBLO0_RPLV_SHIFT		63
#define  CSR_TLBLO0_RPLV		(_ULCAST_(0x1) << CSR_TLBLO0_RPLV_SHIFT)
#define  CSR_TLBLO0_NX_SHIFT		62
#define  CSR_TLBLO0_NX			(_ULCAST_(0x1) << CSR_TLBLO0_NX_SHIFT)
#define  CSR_TLBLO0_NR_SHIFT		61
#define  CSR_TLBLO0_NR			(_ULCAST_(0x1) << CSR_TLBLO0_NR_SHIFT)
#define  CSR_TLBLO0_PFN_SHIFT		12
#define  CSR_TLBLO0_PFN_WIDTH		36
#define  CSR_TLBLO0_PFN			(_ULCAST_(0xfffffffff) << CSR_TLBLO0_PFN_SHIFT)
#define  CSR_TLBLO0_GLOBAL_SHIFT	6
#define  CSR_TLBLO0_GLOBAL		(_ULCAST_(0x1) << CSR_TLBLO0_GLOBAL_SHIFT)
#define  CSR_TLBLO0_CCA_SHIFT		4
#define  CSR_TLBLO0_CCA_WIDTH		2
#define  CSR_TLBLO0_CCA			(_ULCAST_(0x3) << CSR_TLBLO0_CCA_SHIFT)
#define  CSR_TLBLO0_PLV_SHIFT		2
#define  CSR_TLBLO0_PLV_WIDTH		2
#define  CSR_TLBLO0_PLV			(_ULCAST_(0x3) << CSR_TLBLO0_PLV_SHIFT)
#define  CSR_TLBLO0_WE_SHIFT		1
#define  CSR_TLBLO0_WE			(_ULCAST_(0x1) << CSR_TLBLO0_WE_SHIFT)
#define  CSR_TLBLO0_V_SHIFT		0
#define  CSR_TLBLO0_V			(_ULCAST_(0x1) << CSR_TLBLO0_V_SHIFT)

#define LOONGARCH_CSR_TLBELO1		0x13	/* TLB EntryLo1 */
#define  CSR_TLBLO1_RPLV_SHIFT		63
#define  CSR_TLBLO1_RPLV		(_ULCAST_(0x1) << CSR_TLBLO1_RPLV_SHIFT)
#define  CSR_TLBLO1_NX_SHIFT		62
#define  CSR_TLBLO1_NX			(_ULCAST_(0x1) << CSR_TLBLO1_NX_SHIFT)
#define  CSR_TLBLO1_NR_SHIFT		61
#define  CSR_TLBLO1_NR			(_ULCAST_(0x1) << CSR_TLBLO1_NR_SHIFT)
#define  CSR_TLBLO1_PFN_SHIFT		12
#define  CSR_TLBLO1_PFN_WIDTH		36
#define  CSR_TLBLO1_PFN			(_ULCAST_(0xfffffffff) << CSR_TLBLO1_PFN_SHIFT)
#define  CSR_TLBLO1_GLOBAL_SHIFT	6
#define  CSR_TLBLO1_GLOBAL		(_ULCAST_(0x1) << CSR_TLBLO1_GLOBAL_SHIFT)
#define  CSR_TLBLO1_CCA_SHIFT		4
#define  CSR_TLBLO1_CCA_WIDTH		2
#define  CSR_TLBLO1_CCA			(_ULCAST_(0x3) << CSR_TLBLO1_CCA_SHIFT)
#define  CSR_TLBLO1_PLV_SHIFT		2
#define  CSR_TLBLO1_PLV_WIDTH		2
#define  CSR_TLBLO1_PLV			(_ULCAST_(0x3) << CSR_TLBLO1_PLV_SHIFT)
#define  CSR_TLBLO1_WE_SHIFT		1
#define  CSR_TLBLO1_WE			(_ULCAST_(0x1) << CSR_TLBLO1_WE_SHIFT)
#define  CSR_TLBLO1_V_SHIFT		0
#define  CSR_TLBLO1_V			(_ULCAST_(0x1) << CSR_TLBLO1_V_SHIFT)

#define LOONGARCH_CSR_GTLBC		0x15	/* Guest TLB control */
#define  CSR_GTLBC_TGID_SHIFT		16
#define  CSR_GTLBC_TGID_WIDTH		8
#define  CSR_GTLBC_TGID_SHIFT_END	(CSR_GTLBC_TGID_SHIFT + CSR_GTLBC_TGID_WIDTH - 1)
#define  CSR_GTLBC_TGID			(_ULCAST_(0xff) << CSR_GTLBC_TGID_SHIFT)
#define  CSR_GTLBC_TOTI_SHIFT		13
#define  CSR_GTLBC_TOTI			(_ULCAST_(0x1) << CSR_GTLBC_TOTI_SHIFT)
#define  CSR_GTLBC_USETGID_SHIFT	12
#define  CSR_GTLBC_USETGID		(_ULCAST_(0x1) << CSR_GTLBC_USETGID_SHIFT)
#define  CSR_GTLBC_GMTLBSZ_SHIFT	0
#define  CSR_GTLBC_GMTLBSZ_WIDTH	6
#define  CSR_GTLBC_GMTLBSZ		(_ULCAST_(0x3f) << CSR_GTLBC_GMTLBSZ_SHIFT)

#define LOONGARCH_CSR_TRGP		0x16	/* TLBR read guest info */
#define  CSR_TRGP_RID_SHIFT		16
#define  CSR_TRGP_RID_WIDTH		8
#define  CSR_TRGP_RID			(_ULCAST_(0xff) << CSR_TRGP_RID_SHIFT)
#define  CSR_TRGP_GTLB_SHIFT		0
#define  CSR_TRGP_GTLB			(1 << CSR_TRGP_GTLB_SHIFT)

#define LOONGARCH_CSR_ASID		0x18	/* ASID */
#define  CSR_ASID_BIT_SHIFT		16	/* ASIDBits */
#define  CSR_ASID_BIT_WIDTH		8
#define  CSR_ASID_BIT			(_ULCAST_(0xff) << CSR_ASID_BIT_SHIFT)
#define  CSR_ASID_ASID_SHIFT		0
#define  CSR_ASID_ASID_WIDTH		10
#define  CSR_ASID_ASID			(_ULCAST_(0x3ff) << CSR_ASID_ASID_SHIFT)

#define LOONGARCH_CSR_PGDL		0x19	/* Page table base address when VA[VALEN-1] = 0 */

#define LOONGARCH_CSR_PGDH		0x1a	/* Page table base address when VA[VALEN-1] = 1 */

#define LOONGARCH_CSR_PGD		0x1b	/* Page table base */

#define LOONGARCH_CSR_PWCTL0		0x1c	/* PWCtl0 */
#define  CSR_PWCTL0_PTEW_SHIFT		30
#define  CSR_PWCTL0_PTEW_WIDTH		2
#define  CSR_PWCTL0_PTEW		(_ULCAST_(0x3) << CSR_PWCTL0_PTEW_SHIFT)
#define  CSR_PWCTL0_DIR1WIDTH_SHIFT	25
#define  CSR_PWCTL0_DIR1WIDTH_WIDTH	5
#define  CSR_PWCTL0_DIR1WIDTH		(_ULCAST_(0x1f) << CSR_PWCTL0_DIR1WIDTH_SHIFT)
#define  CSR_PWCTL0_DIR1BASE_SHIFT	20
#define  CSR_PWCTL0_DIR1BASE_WIDTH	5
#define  CSR_PWCTL0_DIR1BASE		(_ULCAST_(0x1f) << CSR_PWCTL0_DIR1BASE_SHIFT)
#define  CSR_PWCTL0_DIR0WIDTH_SHIFT	15
#define  CSR_PWCTL0_DIR0WIDTH_WIDTH	5
#define  CSR_PWCTL0_DIR0WIDTH		(_ULCAST_(0x1f) << CSR_PWCTL0_DIR0WIDTH_SHIFT)
#define  CSR_PWCTL0_DIR0BASE_SHIFT	10
#define  CSR_PWCTL0_DIR0BASE_WIDTH	5
#define  CSR_PWCTL0_DIR0BASE		(_ULCAST_(0x1f) << CSR_PWCTL0_DIR0BASE_SHIFT)
#define  CSR_PWCTL0_PTWIDTH_SHIFT	5
#define  CSR_PWCTL0_PTWIDTH_WIDTH	5
#define  CSR_PWCTL0_PTWIDTH		(_ULCAST_(0x1f) << CSR_PWCTL0_PTWIDTH_SHIFT)
#define  CSR_PWCTL0_PTBASE_SHIFT	0
#define  CSR_PWCTL0_PTBASE_WIDTH	5
#define  CSR_PWCTL0_PTBASE		(_ULCAST_(0x1f) << CSR_PWCTL0_PTBASE_SHIFT)

#define LOONGARCH_CSR_PWCTL1		0x1d	/* PWCtl1 */
#define  CSR_PWCTL1_PTW_SHIFT		24
#define  CSR_PWCTL1_PTW_WIDTH		1
#define  CSR_PWCTL1_PTW			(_ULCAST_(0x1) << CSR_PWCTL1_PTW_SHIFT)
#define  CSR_PWCTL1_DIR3WIDTH_SHIFT	18
#define  CSR_PWCTL1_DIR3WIDTH_WIDTH	5
#define  CSR_PWCTL1_DIR3WIDTH		(_ULCAST_(0x1f) << CSR_PWCTL1_DIR3WIDTH_SHIFT)
#define  CSR_PWCTL1_DIR3BASE_SHIFT	12
#define  CSR_PWCTL1_DIR3BASE_WIDTH	5
#define  CSR_PWCTL1_DIR3BASE		(_ULCAST_(0x1f) << CSR_PWCTL0_DIR3BASE_SHIFT)
#define  CSR_PWCTL1_DIR2WIDTH_SHIFT	6
#define  CSR_PWCTL1_DIR2WIDTH_WIDTH	5
#define  CSR_PWCTL1_DIR2WIDTH		(_ULCAST_(0x1f) << CSR_PWCTL1_DIR2WIDTH_SHIFT)
#define  CSR_PWCTL1_DIR2BASE_SHIFT	0
#define  CSR_PWCTL1_DIR2BASE_WIDTH	5
#define  CSR_PWCTL1_DIR2BASE		(_ULCAST_(0x1f) << CSR_PWCTL0_DIR2BASE_SHIFT)

#define LOONGARCH_CSR_STLBPGSIZE	0x1e
#define  CSR_STLBPGSIZE_PS_WIDTH	6
#define  CSR_STLBPGSIZE_PS		    (_ULCAST_(0x3f))

#define LOONGARCH_CSR_RVACFG		0x1f
#define  CSR_RVACFG_RDVA_WIDTH		4
#define  CSR_RVACFG_RDVA		(_ULCAST_(0xf))

/* Config CSR registers */
#define LOONGARCH_CSR_CPUNUM		0x20	/* CPU core number */
#define  CSR_CPUNUM_CID_WIDTH		9
#define  CSR_CPUNUM_CID			_ULCAST_(0x1ff)


/* KSave registers */
#define LOONGARCH_CSR_KS0		0x30
#define LOONGARCH_CSR_KS1		0x31
#define LOONGARCH_CSR_KS2		0x32
#define LOONGARCH_CSR_KS3		0x33
#define LOONGARCH_CSR_KS4		0x34
#define LOONGARCH_CSR_KS5		0x35
#define LOONGARCH_CSR_KS6		0x36
#define LOONGARCH_CSR_KS7		0x37
#define LOONGARCH_CSR_KS8		0x38

/* Exception allocated KS0, KS1 and KS2 statically */
#define EXCEPTION_KS0			LOONGARCH_CSR_KS0
#define EXCEPTION_KS1			LOONGARCH_CSR_KS1
#define EXCEPTION_KS2			LOONGARCH_CSR_KS2
#define EXC_KSAVE_MASK			(1 << 0 | 1 << 1 | 1 << 2)

/* Percpu-data base allocated KS3 statically */
#define PERCPU_BASE_KS			LOONGARCH_CSR_KS3
#define PERCPU_KSAVE_MASK		(1 << 3)


/* Timer registers */
#define LOONGARCH_CSR_TMID		0x40	/* Timer ID */

#define LOONGARCH_CSR_TCFG		0x41	/* Timer config */
#define  CSR_TCFG_VAL_SHIFT		2
#define	 CSR_TCFG_VAL_WIDTH		48
#define  CSR_TCFG_VAL			(_ULCAST_(0x3fffffffffff) << CSR_TCFG_VAL_SHIFT)
#define  CSR_TCFG_PERIOD_SHIFT		1
#define  CSR_TCFG_PERIOD		(_ULCAST_(0x1) << CSR_TCFG_PERIOD_SHIFT)
#define  CSR_TCFG_EN			(_ULCAST_(0x1))

#define LOONGARCH_CSR_TVAL		0x42	/* Timer value */

#define LOONGARCH_CSR_CNTC		0x43	/* Timer offset */

#define LOONGARCH_CSR_TINTCLR		0x44	/* Timer interrupt clear */
#define  CSR_TINTCLR_TI_SHIFT		0
#define  CSR_TINTCLR_TI			(1 << CSR_TINTCLR_TI_SHIFT)

#define DMW_PABITS	48

/* LLBCTL register */
#define LOONGARCH_CSR_LLBCTL		0x60	/* LLBit control */
#define  CSR_LLBCTL_ROLLB_SHIFT		0
#define  CSR_LLBCTL_ROLLB		(_ULCAST_(1) << CSR_LLBCTL_ROLLB_SHIFT)
#define  CSR_LLBCTL_WCLLB_SHIFT		1
#define  CSR_LLBCTL_WCLLB		(_ULCAST_(1) << CSR_LLBCTL_WCLLB_SHIFT)
#define  CSR_LLBCTL_KLO_SHIFT		2
#define  CSR_LLBCTL_KLO			(_ULCAST_(1) << CSR_LLBCTL_KLO_SHIFT)

/* Implement dependent */
#define LOONGARCH_CSR_IMPCTL1		0x80	/* Loongson config1 */
#define  CSR_MISPEC_SHIFT		20
#define  CSR_MISPEC_WIDTH		8
#define  CSR_MISPEC			(_ULCAST_(0xff) << CSR_MISPEC_SHIFT)
#define  CSR_SSEN_SHIFT			18
#define  CSR_SSEN			(_ULCAST_(1) << CSR_SSEN_SHIFT)
#define  CSR_SCRAND_SHIFT		17
#define  CSR_SCRAND			(_ULCAST_(1) << CSR_SCRAND_SHIFT)
#define  CSR_LLEXCL_SHIFT		16
#define  CSR_LLEXCL			(_ULCAST_(1) << CSR_LLEXCL_SHIFT)
#define  CSR_DISVC_SHIFT		15
#define  CSR_DISVC			(_ULCAST_(1) << CSR_DISVC_SHIFT)
#define  CSR_VCLRU_SHIFT		14
#define  CSR_VCLRU			(_ULCAST_(1) << CSR_VCLRU_SHIFT)
#define  CSR_DCLRU_SHIFT		13
#define  CSR_DCLRU			(_ULCAST_(1) << CSR_DCLRU_SHIFT)
#define  CSR_FASTLDQ_SHIFT		12
#define  CSR_FASTLDQ			(_ULCAST_(1) << CSR_FASTLDQ_SHIFT)
#define  CSR_USERCAC_SHIFT		11
#define  CSR_USERCAC			(_ULCAST_(1) << CSR_USERCAC_SHIFT)
#define  CSR_ANTI_MISPEC_SHIFT		10
#define  CSR_ANTI_MISPEC		(_ULCAST_(1) << CSR_ANTI_MISPEC_SHIFT)
#define  CSR_ANTI_FLUSHSFB_SHIFT	9
#define  CSR_ANTI_FLUSHSFB		(_ULCAST_(1) << CSR_ANTI_FLUSHSFB_SHIFT)
#define  CSR_STFILL_SHIFT		8
#define  CSR_STFILL			(_ULCAST_(1) << CSR_STFILL_SHIFT)
#define  CSR_LIFEP_SHIFT		7
#define  CSR_LIFEP			(_ULCAST_(1) << CSR_LIFEP_SHIFT)
#define  CSR_LLSYNC_SHIFT		6
#define  CSR_LLSYNC			(_ULCAST_(1) << CSR_LLSYNC_SHIFT)
#define  CSR_BRBTDIS_SHIFT		5
#define  CSR_BRBTDIS			(_ULCAST_(1) << CSR_BRBTDIS_SHIFT)
#define  CSR_RASDIS_SHIFT		4
#define  CSR_RASDIS			(_ULCAST_(1) << CSR_RASDIS_SHIFT)
#define  CSR_STPRE_SHIFT		2
#define  CSR_STPRE_WIDTH		2
#define  CSR_STPRE			(_ULCAST_(3) << CSR_STPRE_SHIFT)
#define  CSR_INSTPRE_SHIFT		1
#define  CSR_INSTPRE			(_ULCAST_(1) << CSR_INSTPRE_SHIFT)
#define  CSR_DATAPRE_SHIFT		0
#define  CSR_DATAPRE			(_ULCAST_(1) << CSR_DATAPRE_SHIFT)

#define LOONGARCH_CSR_IMPCTL2		0x81	/* Loongson config2 */
#define  CSR_FLUSH_MTLB_SHIFT		0
#define  CSR_FLUSH_MTLB			(_ULCAST_(1) << CSR_FLUSH_MTLB_SHIFT)
#define  CSR_FLUSH_STLB_SHIFT		1
#define  CSR_FLUSH_STLB			(_ULCAST_(1) << CSR_FLUSH_STLB_SHIFT)
#define  CSR_FLUSH_DTLB_SHIFT		2
#define  CSR_FLUSH_DTLB			(_ULCAST_(1) << CSR_FLUSH_DTLB_SHIFT)
#define  CSR_FLUSH_ITLB_SHIFT		3
#define  CSR_FLUSH_ITLB			(_ULCAST_(1) << CSR_FLUSH_ITLB_SHIFT)
#define  CSR_FLUSH_BTAC_SHIFT		4
#define  CSR_FLUSH_BTAC			(_ULCAST_(1) << CSR_FLUSH_BTAC_SHIFT)

#define LOONGARCH_CSR_GNMI		0x82

/* TLB Refill registers */
#define LOONGARCH_CSR_TLBRENTRY		0x88	/* TLB refill exception entry */
#define LOONGARCH_CSR_TLBRBADV		0x89	/* TLB refill badvaddr */
#define LOONGARCH_CSR_TLBRERA		0x8a	/* TLB refill ERA */
#define LOONGARCH_CSR_TLBRSAVE		0x8b	/* KSave for TLB refill exception */
#define LOONGARCH_CSR_TLBRELO0		0x8c	/* TLB refill entrylo0 */
#define LOONGARCH_CSR_TLBRELO1		0x8d	/* TLB refill entrylo1 */
#define LOONGARCH_CSR_TLBREHI		0x8e	/* TLB refill entryhi */
#define  CSR_TLBREHI_PS_SHIFT		0
#define  CSR_TLBREHI_PS			(_ULCAST_(0x3f) << CSR_TLBREHI_PS_SHIFT)
#define LOONGARCH_CSR_TLBRPRMD		0x8f	/* TLB refill mode info */

/* Machine Error registers */
#define LOONGARCH_CSR_MERRCTL		0x90	/* MERRCTL */
#define LOONGARCH_CSR_MERRENTRY		0x93	/* MError exception entry */

/* Shadow MCSR : 0xc0 ~ 0xff */
#define LOONGARCH_CSR_MCSR0		0xc0	/* CPUCFG0 and CPUCFG1 */
#define  MCSR0_INT_IMPL_SHIFT		58
#define  MCSR0_INT_IMPL			0
#define  MCSR0_IOCSR_BRD_SHIFT		57
#define  MCSR0_IOCSR_BRD		(_ULCAST_(1) << MCSR0_IOCSR_BRD_SHIFT)
#define  MCSR0_HUGEPG_SHIFT		56
#define  MCSR0_HUGEPG			(_ULCAST_(1) << MCSR0_HUGEPG_SHIFT)
#define  MCSR0_RPLMTLB_SHIFT		55
#define  MCSR0_RPLMTLB			(_ULCAST_(1) << MCSR0_RPLMTLB_SHIFT)
#define  MCSR0_EXEPROT_SHIFT		54
#define  MCSR0_EXEPROT			(_ULCAST_(1) << MCSR0_EXEPROT_SHIFT)
#define  MCSR0_RI_SHIFT			53
#define  MCSR0_RI			(_ULCAST_(1) << MCSR0_RI_SHIFT)
#define  MCSR0_UAL_SHIFT		52
#define  MCSR0_UAL			(_ULCAST_(1) << MCSR0_UAL_SHIFT)
#define  MCSR0_VABIT_SHIFT		44
#define  MCSR0_VABIT_WIDTH		8
#define  MCSR0_VABIT			(_ULCAST_(0xff) << MCSR0_VABIT_SHIFT)
#define  VABIT_DEFAULT			0x2f
#define  MCSR0_PABIT_SHIFT		36
#define  MCSR0_PABIT_WIDTH		8
#define  MCSR0_PABIT			(_ULCAST_(0xff) << MCSR0_PABIT_SHIFT)
#define  PABIT_DEFAULT			0x2f
#define  MCSR0_IOCSR_SHIFT		35
#define  MCSR0_IOCSR			(_ULCAST_(1) << MCSR0_IOCSR_SHIFT)
#define  MCSR0_PAGING_SHIFT		34
#define  MCSR0_PAGING			(_ULCAST_(1) << MCSR0_PAGING_SHIFT)
#define  MCSR0_GR64_SHIFT		33
#define  MCSR0_GR64			(_ULCAST_(1) << MCSR0_GR64_SHIFT)
#define  GR64_DEFAULT			1
#define  MCSR0_GR32_SHIFT		32
#define  MCSR0_GR32			(_ULCAST_(1) << MCSR0_GR32_SHIFT)
#define  GR32_DEFAULT			0
#define  MCSR0_PRID_WIDTH		32
#define  MCSR0_PRID			0x14C010

#define LOONGARCH_CSR_MCSR1		0xc1	/* CPUCFG2 and CPUCFG3 */
#define  MCSR1_HPFOLD_SHIFT		43
#define  MCSR1_HPFOLD			(_ULCAST_(1) << MCSR1_HPFOLD_SHIFT)
#define  MCSR1_SPW_LVL_SHIFT		40
#define  MCSR1_SPW_LVL_WIDTH		3
#define  MCSR1_SPW_LVL			(_ULCAST_(7) << MCSR1_SPW_LVL_SHIFT)
#define  MCSR1_ICACHET_SHIFT		39
#define  MCSR1_ICACHET			(_ULCAST_(1) << MCSR1_ICACHET_SHIFT)
#define  MCSR1_ITLBT_SHIFT		38
#define  MCSR1_ITLBT			(_ULCAST_(1) << MCSR1_ITLBT_SHIFT)
#define  MCSR1_LLDBAR_SHIFT		37
#define  MCSR1_LLDBAR			(_ULCAST_(1) << MCSR1_LLDBAR_SHIFT)
#define  MCSR1_SCDLY_SHIFT		36
#define  MCSR1_SCDLY			(_ULCAST_(1) << MCSR1_SCDLY_SHIFT)
#define  MCSR1_LLEXC_SHIFT		35
#define  MCSR1_LLEXC			(_ULCAST_(1) << MCSR1_LLEXC_SHIFT)
#define  MCSR1_UCACC_SHIFT		34
#define  MCSR1_UCACC			(_ULCAST_(1) << MCSR1_UCACC_SHIFT)
#define  MCSR1_SFB_SHIFT		33
#define  MCSR1_SFB			(_ULCAST_(1) << MCSR1_SFB_SHIFT)
#define  MCSR1_CCDMA_SHIFT		32
#define  MCSR1_CCDMA			(_ULCAST_(1) << MCSR1_CCDMA_SHIFT)
#define  MCSR1_LAMO_SHIFT		22
#define  MCSR1_LAMO			(_ULCAST_(1) << MCSR1_LAMO_SHIFT)
#define  MCSR1_LSPW_SHIFT		21
#define  MCSR1_LSPW			(_ULCAST_(1) << MCSR1_LSPW_SHIFT)
#define  MCSR1_LOONGARCHBT_SHIFT	20
#define  MCSR1_LOONGARCHBT		(_ULCAST_(1) << MCSR1_LOONGARCHBT_SHIFT)
#define  MCSR1_ARMBT_SHIFT		19
#define  MCSR1_ARMBT			(_ULCAST_(1) << MCSR1_ARMBT_SHIFT)
#define  MCSR1_X86BT_SHIFT		18
#define  MCSR1_X86BT			(_ULCAST_(1) << MCSR1_X86BT_SHIFT)
#define  MCSR1_LLFTPVERS_SHIFT		15
#define  MCSR1_LLFTPVERS_WIDTH		3
#define  MCSR1_LLFTPVERS		(_ULCAST_(7) << MCSR1_LLFTPVERS_SHIFT)
#define  MCSR1_LLFTP_SHIFT		14
#define  MCSR1_LLFTP			(_ULCAST_(1) << MCSR1_LLFTP_SHIFT)
#define  MCSR1_VZVERS_SHIFT		11
#define  MCSR1_VZVERS_WIDTH		3
#define  MCSR1_VZVERS			(_ULCAST_(7) << MCSR1_VZVERS_SHIFT)
#define  MCSR1_VZ_SHIFT			10
#define  MCSR1_VZ			(_ULCAST_(1) << MCSR1_VZ_SHIFT)
#define  MCSR1_CRYPTO_SHIFT		9
#define  MCSR1_CRYPTO			(_ULCAST_(1) << MCSR1_CRYPTO_SHIFT)
#define  MCSR1_COMPLEX_SHIFT		8
#define  MCSR1_COMPLEX			(_ULCAST_(1) << MCSR1_COMPLEX_SHIFT)
#define  MCSR1_LASX_SHIFT		7
#define  MCSR1_LASX			(_ULCAST_(1) << MCSR1_LASX_SHIFT)
#define  MCSR1_LSX_SHIFT		6
#define  MCSR1_LSX			(_ULCAST_(1) << MCSR1_LSX_SHIFT)
#define  MCSR1_FPVERS_SHIFT		3
#define  MCSR1_FPVERS_WIDTH		3
#define  MCSR1_FPVERS			(_ULCAST_(7) << MCSR1_FPVERS_SHIFT)
#define  MCSR1_FPDP_SHIFT		2
#define  MCSR1_FPDP			(_ULCAST_(1) << MCSR1_FPDP_SHIFT)
#define  MCSR1_FPSP_SHIFT		1
#define  MCSR1_FPSP			(_ULCAST_(1) << MCSR1_FPSP_SHIFT)
#define  MCSR1_FP_SHIFT			0
#define  MCSR1_FP			(_ULCAST_(1) << MCSR1_FP_SHIFT)

#define LOONGARCH_CSR_MCSR2		0xc2	/* CPUCFG4 and CPUCFG5 */
#define  MCSR2_CCDIV_SHIFT		48
#define  MCSR2_CCDIV_WIDTH		16
#define  MCSR2_CCDIV			(_ULCAST_(0xffff) << MCSR2_CCDIV_SHIFT)
#define  MCSR2_CCMUL_SHIFT		32
#define  MCSR2_CCMUL_WIDTH		16
#define  MCSR2_CCMUL			(_ULCAST_(0xffff) << MCSR2_CCMUL_SHIFT)
#define  MCSR2_CCFREQ_WIDTH		32
#define  MCSR2_CCFREQ			(_ULCAST_(0xffffffff))
#define  CCFREQ_DEFAULT			0x5f5e100	/* 100MHz */

#define LOONGARCH_CSR_MCSR3		0xc3	/* CPUCFG6 */
#define  MCSR3_UPM_SHIFT		14
#define  MCSR3_UPM			(_ULCAST_(1) << MCSR3_UPM_SHIFT)
#define  MCSR3_PMBITS_SHIFT		8
#define  MCSR3_PMBITS_WIDTH		6
#define  MCSR3_PMBITS			(_ULCAST_(0x3f) << MCSR3_PMBITS_SHIFT)
#define  PMBITS_DEFAULT			0x40
#define  MCSR3_PMNUM_SHIFT		4
#define  MCSR3_PMNUM_WIDTH		4
#define  MCSR3_PMNUM			(_ULCAST_(0xf) << MCSR3_PMNUM_SHIFT)
#define  MCSR3_PAMVER_SHIFT		1
#define  MCSR3_PAMVER_WIDTH		3
#define  MCSR3_PAMVER			(_ULCAST_(0x7) << MCSR3_PAMVER_SHIFT)
#define  MCSR3_PMP_SHIFT		0
#define  MCSR3_PMP			(_ULCAST_(1) << MCSR3_PMP_SHIFT)

#define LOONGARCH_CSR_MCSR8		0xc8	/* CPUCFG16 and CPUCFG17 */
#define  MCSR8_L1I_SIZE_SHIFT		56
#define  MCSR8_L1I_SIZE_WIDTH		7
#define  MCSR8_L1I_SIZE			(_ULCAST_(0x7f) << MCSR8_L1I_SIZE_SHIFT)
#define  MCSR8_L1I_IDX_SHIFT		48
#define  MCSR8_L1I_IDX_WIDTH		8
#define  MCSR8_L1I_IDX			(_ULCAST_(0xff) << MCSR8_L1I_IDX_SHIFT)
#define  MCSR8_L1I_WAY_SHIFT		32
#define  MCSR8_L1I_WAY_WIDTH		16
#define  MCSR8_L1I_WAY			(_ULCAST_(0xffff) << MCSR8_L1I_WAY_SHIFT)
#define  MCSR8_L3DINCL_SHIFT		16
#define  MCSR8_L3DINCL			(_ULCAST_(1) << MCSR8_L3DINCL_SHIFT)
#define  MCSR8_L3DPRIV_SHIFT		15
#define  MCSR8_L3DPRIV			(_ULCAST_(1) << MCSR8_L3DPRIV_SHIFT)
#define  MCSR8_L3DPRE_SHIFT		14
#define  MCSR8_L3DPRE			(_ULCAST_(1) << MCSR8_L3DPRE_SHIFT)
#define  MCSR8_L3IUINCL_SHIFT		13
#define  MCSR8_L3IUINCL			(_ULCAST_(1) << MCSR8_L3IUINCL_SHIFT)
#define  MCSR8_L3IUPRIV_SHIFT		12
#define  MCSR8_L3IUPRIV			(_ULCAST_(1) << MCSR8_L3IUPRIV_SHIFT)
#define  MCSR8_L3IUUNIFY_SHIFT		11
#define  MCSR8_L3IUUNIFY		(_ULCAST_(1) << MCSR8_L3IUUNIFY_SHIFT)
#define  MCSR8_L3IUPRE_SHIFT		10
#define  MCSR8_L3IUPRE			(_ULCAST_(1) << MCSR8_L3IUPRE_SHIFT)
#define  MCSR8_L2DINCL_SHIFT		9
#define  MCSR8_L2DINCL			(_ULCAST_(1) << MCSR8_L2DINCL_SHIFT)
#define  MCSR8_L2DPRIV_SHIFT		8
#define  MCSR8_L2DPRIV			(_ULCAST_(1) << MCSR8_L2DPRIV_SHIFT)
#define  MCSR8_L2DPRE_SHIFT		7
#define  MCSR8_L2DPRE			(_ULCAST_(1) << MCSR8_L2DPRE_SHIFT)
#define  MCSR8_L2IUINCL_SHIFT		6
#define  MCSR8_L2IUINCL			(_ULCAST_(1) << MCSR8_L2IUINCL_SHIFT)
#define  MCSR8_L2IUPRIV_SHIFT		5
#define  MCSR8_L2IUPRIV			(_ULCAST_(1) << MCSR8_L2IUPRIV_SHIFT)
#define  MCSR8_L2IUUNIFY_SHIFT		4
#define  MCSR8_L2IUUNIFY		(_ULCAST_(1) << MCSR8_L2IUUNIFY_SHIFT)
#define  MCSR8_L2IUPRE_SHIFT		3
#define  MCSR8_L2IUPRE			(_ULCAST_(1) << MCSR8_L2IUPRE_SHIFT)
#define  MCSR8_L1DPRE_SHIFT		2
#define  MCSR8_L1DPRE			(_ULCAST_(1) << MCSR8_L1DPRE_SHIFT)
#define  MCSR8_L1IUUNIFY_SHIFT		1
#define  MCSR8_L1IUUNIFY		(_ULCAST_(1) << MCSR8_L1IUUNIFY_SHIFT)
#define  MCSR8_L1IUPRE_SHIFT		0
#define  MCSR8_L1IUPRE			(_ULCAST_(1) << MCSR8_L1IUPRE_SHIFT)

#define LOONGARCH_CSR_MCSR9		0xc9	/* CPUCFG18 and CPUCFG19 */
#define  MCSR9_L2U_SIZE_SHIFT		56
#define  MCSR9_L2U_SIZE_WIDTH		7
#define  MCSR9_L2U_SIZE			(_ULCAST_(0x7f) << MCSR9_L2U_SIZE_SHIFT)
#define  MCSR9_L2U_IDX_SHIFT		48
#define  MCSR9_L2U_IDX_WIDTH		8
#define  MCSR9_L2U_IDX			(_ULCAST_(0xff) << MCSR9_IDX_LOG_SHIFT)
#define  MCSR9_L2U_WAY_SHIFT		32
#define  MCSR9_L2U_WAY_WIDTH		16
#define  MCSR9_L2U_WAY			(_ULCAST_(0xffff) << MCSR9_L2U_WAY_SHIFT)
#define  MCSR9_L1D_SIZE_SHIFT		24
#define  MCSR9_L1D_SIZE_WIDTH		7
#define  MCSR9_L1D_SIZE			(_ULCAST_(0x7f) << MCSR9_L1D_SIZE_SHIFT)
#define  MCSR9_L1D_IDX_SHIFT		16
#define  MCSR9_L1D_IDX_WIDTH		8
#define  MCSR9_L1D_IDX			(_ULCAST_(0xff) << MCSR9_L1D_IDX_SHIFT)
#define  MCSR9_L1D_WAY_SHIFT		0
#define  MCSR9_L1D_WAY_WIDTH		16
#define  MCSR9_L1D_WAY			(_ULCAST_(0xffff) << MCSR9_L1D_WAY_SHIFT)

#define LOONGARCH_CSR_MCSR10		0xca	/* CPUCFG20 */
#define  MCSR10_L3U_SIZE_SHIFT		24
#define  MCSR10_L3U_SIZE_WIDTH		7
#define  MCSR10_L3U_SIZE		(_ULCAST_(0x7f) << MCSR10_L3U_SIZE_SHIFT)
#define  MCSR10_L3U_IDX_SHIFT		16
#define  MCSR10_L3U_IDX_WIDTH		8
#define  MCSR10_L3U_IDX			(_ULCAST_(0xff) << MCSR10_L3U_IDX_SHIFT)
#define  MCSR10_L3U_WAY_SHIFT		0
#define  MCSR10_L3U_WAY_WIDTH		16
#define  MCSR10_L3U_WAY			(_ULCAST_(0xffff) << MCSR10_L3U_WAY_SHIFT)

#define LOONGARCH_CSR_MCSR24		0xf0	/* cpucfg48 */
#define  MCSR24_RAMCG_SHIFT		3
#define  MCSR24_RAMCG			(_ULCAST_(1) << MCSR24_RAMCG_SHIFT)
#define  MCSR24_VFPUCG_SHIFT		2
#define  MCSR24_VFPUCG			(_ULCAST_(1) << MCSR24_VFPUCG_SHIFT)
#define  MCSR24_NAPEN_SHIFT		1
#define  MCSR24_NAPEN			(_ULCAST_(1) << MCSR24_NAPEN_SHIFT)
#define  MCSR24_MCSRLOCK_SHIFT		0
#define  MCSR24_MCSRLOCK		(_ULCAST_(1) << MCSR24_MCSRLOCK_SHIFT)

/* Direct Map windows registers */
#define LOONGARCH_CSR_DMWIN0		0x180	/* 64 direct map win0: MEM & IF */
#define LOONGARCH_CSR_DMWIN1		0x181	/* 64 direct map win1: MEM & IF */
#define LOONGARCH_CSR_DMWIN2		0x182	/* 64 direct map win2: MEM */
#define LOONGARCH_CSR_DMWIN3		0x183	/* 64 direct map win3: MEM */

/* Direct Map window 0/1/2/3 */
#define CSR_DMW0_PLV0		_CONST64_(1 << 0)
#define CSR_DMW0_VSEG		_CONST64_(0x8000)
#define CSR_DMW0_BASE		(CSR_DMW0_VSEG << DMW_PABITS)
#define CSR_DMW0_INIT		(CSR_DMW0_BASE | CSR_DMW0_PLV0)

#define CSR_DMW1_PLV0		_CONST64_(1 << 0)
#define CSR_DMW1_MAT		_CONST64_(1 << 4)
#define CSR_DMW1_VSEG		_CONST64_(0x9000)
#define CSR_DMW1_BASE		(CSR_DMW1_VSEG << DMW_PABITS)
#define CSR_DMW1_INIT		(CSR_DMW1_BASE | CSR_DMW1_MAT | CSR_DMW1_PLV0)

#define CSR_DMW2_PLV0		_CONST64_(1 << 0)
#define CSR_DMW2_MAT		_CONST64_(2 << 4)
#define CSR_DMW2_VSEG		_CONST64_(0xa000)
#define CSR_DMW2_BASE		(CSR_DMW2_VSEG << DMW_PABITS)
#define CSR_DMW2_INIT		(CSR_DMW2_BASE | CSR_DMW2_MAT | CSR_DMW2_PLV0)

#define CSR_DMW3_INIT		0x0

/* Performance counter registers */
#define LOONGARCH_CSR_PERFCTRL0		0x200	/* 32 perf event 0 config */
#define LOONGARCH_CSR_PERFCNTR0		0x201	/* 64 perf event 0 count value */
#define LOONGARCH_CSR_PERFCTRL1		0x202	/* 32 perf event 1 config */
#define LOONGARCH_CSR_PERFCNTR1		0x203	/* 64 perf event 1 count value */
#define LOONGARCH_CSR_PERFCTRL2		0x204	/* 32 perf event 2 config */
#define LOONGARCH_CSR_PERFCNTR2		0x205	/* 64 perf event 2 count value */
#define LOONGARCH_CSR_PERFCTRL3		0x206	/* 32 perf event 3 config */
#define LOONGARCH_CSR_PERFCNTR3		0x207	/* 64 perf event 3 count value */
#define  CSR_PERFCTRL_PLV0		(_ULCAST_(1) << 16)
#define  CSR_PERFCTRL_PLV1		(_ULCAST_(1) << 17)
#define  CSR_PERFCTRL_PLV2		(_ULCAST_(1) << 18)
#define  CSR_PERFCTRL_PLV3		(_ULCAST_(1) << 19)
#define  CSR_PERFCTRL_IE		(_ULCAST_(1) << 20)
#define  CSR_PERFCTRL_EVENT		0x3ff

/* ExStatus.ExcCode */
#define EXCCODE_RSV		0	/* Reserved */
#define EXCCODE_TLBL		1	/* TLB miss on a load */
#define EXCCODE_TLBS		2	/* TLB miss on a store */
#define EXCCODE_TLBI		3	/* TLB miss on a ifetch */
#define EXCCODE_TLBM		4	/* TLB modified fault */
#define EXCCODE_TLBNR		5	/* TLB Read-Inhibit exception */
#define EXCCODE_TLBNX		6	/* TLB Execution-Inhibit exception */
#define EXCCODE_TLBPE		7	/* TLB Privilege Error */
#define EXCCODE_ADE		8	/* Address Error */
	#define EXSUBCODE_ADEF		0	/* Fetch Instruction */
	#define EXSUBCODE_ADEM		1	/* Access Memory*/
#define EXCCODE_ALE		9	/* Unalign Access */
#define EXCCODE_BCE		10	/* Bounds Check Error */
#define EXCCODE_SYS		11	/* System call */
#define EXCCODE_BP		12	/* Breakpoint */
#define EXCCODE_INE		13	/* Inst. Not Exist */
#define EXCCODE_IPE		14	/* Inst. Privileged Error */
#define EXCCODE_FPDIS		15	/* FPU Disabled */
#define EXCCODE_LSXDIS		16	/* LSX Disabled */
#define EXCCODE_LASXDIS		17	/* LASX Disabled */
#define EXCCODE_FPE		18	/* Floating Point Exception */
	#define EXCSUBCODE_FPE		0	/* Floating Point Exception */
	#define EXCSUBCODE_VFPE		1	/* Vector Exception */
#define EXCCODE_WATCH		19	/* WatchPoint Exception */
	#define EXCSUBCODE_WPEF		0	/* ... on Instruction Fetch */
	#define EXCSUBCODE_WPEM		1	/* ... on Memory Accesses */
#define EXCCODE_BTDIS		20	/* Binary Trans. Disabled */
#define EXCCODE_BTE		21	/* Binary Trans. Exception */
#define EXCCODE_GSPR		22	/* Guest Privileged Error */
#define EXCCODE_HVC		23	/* Hypercall */
#define EXCCODE_GCM		24	/* Guest CSR modified */
	#define EXCSUBCODE_GCSC		0	/* Software caused */
	#define EXCSUBCODE_GCHC		1	/* Hardware caused */
#define EXCCODE_SE		25	/* Security */

/* Interrupt numbers */
#define INT_SWI0	0	/* Software Interrupts */
#define INT_SWI1	1
#define INT_HWI0	2	/* Hardware Interrupts */
#define INT_HWI1	3
#define INT_HWI2	4
#define INT_HWI3	5
#define INT_HWI4	6
#define INT_HWI5	7
#define INT_HWI6	8
#define INT_HWI7	9
#define INT_PCOV	10	/* Performance Counter Overflow */
#define INT_TI		11	/* Timer */
#define INT_IPI		12
#define INT_NMI		13
#define INT_AVEC	14

/* ExcCodes corresponding to interrupts */
#define EXCCODE_INT_NUM		(INT_AVEC + 1)
#define EXCCODE_INT_START	64
#define EXCCODE_INT_END		(EXCCODE_INT_START + EXCCODE_INT_NUM - 1)


// IOCSR
#define LOONGARCH_IOCSR_VENDOR		0x10

#define LOONGARCH_IOCSR_CPUNAME		0x20

#define LOONGARCH_IOCSR_NODECNT		0x408

#define LOONGARCH_IOCSR_MISC_FUNC	0x420
#define  IOCSR_MISC_FUNC_SOFT_INT	BIT_ULL(10)
#define  IOCSR_MISC_FUNC_TIMER_RESET	BIT_ULL(21)
#define  IOCSR_MISC_FUNC_EXT_IOI_EN	BIT_ULL(48)
#define  IOCSR_MISC_FUNC_AVEC_EN	BIT_ULL(51)


#ifndef __ASSEMBLY__

#define read_csr_asid()			csr_read32(LOONGARCH_CSR_ASID)
#define write_csr_asid(val)		csr_write32(val, LOONGARCH_CSR_ASID)
#define read_csr_entryhi()		csr_read64(LOONGARCH_CSR_TLBEHI)
#define write_csr_entryhi(val)		csr_write64(val, LOONGARCH_CSR_TLBEHI)
#define read_csr_entrylo0()		csr_read64(LOONGARCH_CSR_TLBELO0)
#define write_csr_entrylo0(val)		csr_write64(val, LOONGARCH_CSR_TLBELO0)
#define read_csr_entrylo1()		csr_read64(LOONGARCH_CSR_TLBELO1)
#define write_csr_entrylo1(val)		csr_write64(val, LOONGARCH_CSR_TLBELO1)
#define read_csr_ecfg()			csr_read32(LOONGARCH_CSR_ECFG)
#define write_csr_ecfg(val)		csr_write32(val, LOONGARCH_CSR_ECFG)
#define read_csr_estat()		csr_read32(LOONGARCH_CSR_ESTAT)
#define write_csr_estat(val)		csr_write32(val, LOONGARCH_CSR_ESTAT)
#define read_csr_tlbidx()		csr_read32(LOONGARCH_CSR_TLBIDX)
#define write_csr_tlbidx(val)		csr_write32(val, LOONGARCH_CSR_TLBIDX)
#define read_csr_euen()			csr_read32(LOONGARCH_CSR_EUEN)
#define write_csr_euen(val)		csr_write32(val, LOONGARCH_CSR_EUEN)
#define read_csr_cpuid()		csr_read32(LOONGARCH_CSR_CPUID)
#define read_csr_prcfg1()		csr_read64(LOONGARCH_CSR_PRCFG1)
#define write_csr_prcfg1(val)		csr_write64(val, LOONGARCH_CSR_PRCFG1)
#define read_csr_prcfg2()		csr_read64(LOONGARCH_CSR_PRCFG2)
#define write_csr_prcfg2(val)		csr_write64(val, LOONGARCH_CSR_PRCFG2)
#define read_csr_prcfg3()		csr_read64(LOONGARCH_CSR_PRCFG3)
#define write_csr_prcfg3(val)		csr_write64(val, LOONGARCH_CSR_PRCFG3)
#define read_csr_stlbpgsize()		csr_read32(LOONGARCH_CSR_STLBPGSIZE)
#define write_csr_stlbpgsize(val)	csr_write32(val, LOONGARCH_CSR_STLBPGSIZE)
#define read_csr_rvacfg()		csr_read32(LOONGARCH_CSR_RVACFG)
#define write_csr_rvacfg(val)		csr_write32(val, LOONGARCH_CSR_RVACFG)
#define write_csr_tintclear(val)	csr_write32(val, LOONGARCH_CSR_TINTCLR)
#define read_csr_impctl1()		csr_read64(LOONGARCH_CSR_IMPCTL1)
#define write_csr_impctl1(val)		csr_write64(val, LOONGARCH_CSR_IMPCTL1)
#define write_csr_impctl2(val)		csr_write64(val, LOONGARCH_CSR_IMPCTL2)

static inline unsigned long set_csr_ecfg(unsigned long set_val)
{
	unsigned long res, new_val;
	res = read_csr_ecfg();
	new_val = res | set_val;
	write_csr_ecfg(new_val);
	return res;
}

static inline unsigned long clear_csr_ecfg(unsigned long clear)
{
	unsigned long res, new_val;
	res = read_csr_ecfg();
	new_val = res & ~clear;
	write_csr_ecfg(new_val);
	return res;
}


static inline void write_csr_pagesize(unsigned int size)
{
	csr_xchg32(size << CSR_TLBIDX_SIZE, CSR_TLBIDX_SIZEM, LOONGARCH_CSR_TLBIDX);
}
#define write_csr_stlbpgsize(val)	csr_write32(val, LOONGARCH_CSR_STLBPGSIZE)

static inline void write_csr_tlbrefill_pagesize(unsigned int size)
{
	csr_xchg64(size << CSR_TLBREHI_PS_SHIFT, CSR_TLBREHI_PS, LOONGARCH_CSR_TLBREHI);
}

#endif




#endif /* _ASM_LOONGARCH_H */

