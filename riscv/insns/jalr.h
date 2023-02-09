reg_t tmp = npc;
set_pc((RS1 + insn.i_imm()) & ~reg_t(1));
WRITE_RD(tmp);
insn.is_uncond_jmp = 1;
insn.is_end_pack = 1;
