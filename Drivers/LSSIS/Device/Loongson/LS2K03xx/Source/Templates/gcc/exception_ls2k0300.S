#ifndef __ASSEMBLY__
#define __ASSEMBLY__
#endif

#include <asm/stackframe.h>

.equ INSTR_SIZE, 4
.equ VECTOR_SPACING_INSTRS, 2
.equ SPACING, (VECTOR_SPACING_INSTRS * INSTR_SIZE)

.macro BUILD_HANDLER_ENTRY nr
  .global exception_vector_\nr
  .type exception_vector_\nr, @function

  .set start_addr, .

exception_vector_\nr:
  b   exception_handler_\nr

  .set current_size, . - start_addr

  .if current_size > SPACING
    .error "Entry \nr too large: exceeds SPACING!"
  .endif

  .org start_addr + SPACING
.endm

.altmacro
.section .text.vector_entry, "ax"
.balign 4096
.global exception_vector_base
exception_vector_base:
.set nr, 0
.rept 77
  BUILD_HANDLER_ENTRY %nr
  .set nr, nr + 1
.endr

.type default_exception_handler, @function
default_exception_handler:
1:
    b 1b

.type exception_handler_0, @function
exception_handler_0:
tlb_refill_exception_handler:
1:
  b 1b

.type exception_handler_64, @function
exception_handler_64:
exception_handler_swi0:
	BACKUP_T0T1
	SAVE_ALL

	li.d	t0, 0b01
	csrxchg zero, t0, LOONGARCH_CSR_ESTAT

	RESTORE_ALL_AND_RET

.type exception_handler_65, @function
exception_handler_65:
exception_handler_swi1:
	BACKUP_T0T1
	SAVE_ALL

	li.d	t0, 0b10
	csrxchg zero, t0, LOONGARCH_CSR_ESTAT

	RESTORE_ALL_AND_RET

.type exception_handler_66, @function
exception_handler_66:
exception_handler_hwi0:
	BACKUP_T0T1
	SAVE_ALL

	RESTORE_ALL_AND_RET

.type exception_handler_67, @function
exception_handler_67:
exception_handler_hwi1:
	BACKUP_T0T1
	SAVE_ALL

	RESTORE_ALL_AND_RET

.macro define_exception nr
  .weak exception_handler_\nr
  .ifndef exception_handler_\nr
    .set exception_handler_\nr, default_exception_handler
  .endif
.endm

.set nr, 0
.rept 77
  define_exception %nr
  .set nr, nr + 1
.endr
