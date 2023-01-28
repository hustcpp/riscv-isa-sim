require_extension(EXT_ZCA);
set_pc(pc + insn.rvc_j_imm());
insn.is_uncond_jmp = 1;
