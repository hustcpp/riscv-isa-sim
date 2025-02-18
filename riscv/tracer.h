// See LICENSE for license details.

#ifndef _RISCV_TRACER_H
#define _RISCV_TRACER_H

#include "processor.h"

static inline void trace_opcode(processor_t UNUSED *p, insn_bits_t UNUSED opc, insn_t UNUSED insn) {
}

void execute_mods(processor_t *p, insn_bits_t opc, insn_t insn, reg_t pc);

#endif
