require_extension(EXT_ZCA);
require(insn.rvc_rs1() != 0);
set_pc(RVC_RS1 & ~reg_t(1));
insn.is_uncond_jmp = 1;
insn.is_end_pack = 1;
