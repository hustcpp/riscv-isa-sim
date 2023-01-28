reg_t tmp = npc;
set_pc(JUMP_TARGET);
WRITE_RD(tmp);
insn.is_uncond_jmp = 1;
