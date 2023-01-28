if (sreg_t(RS1) < sreg_t(RS2)) {
  set_pc(BRANCH_TARGET);
  insn.is_cond_br_taken = 1;
}
insn.is_cond_br = 1;
