require_extension(EXT_ZCA);
if (RVC_RS1S == 0) {
  set_pc(pc + insn.rvc_b_imm());
  insn.is_cond_br_taken = 1;
}
insn.is_cond_br = 1;
