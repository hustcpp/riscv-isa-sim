if (RS1 < RS2) {
  set_pc(BRANCH_TARGET);
  insn.is_cond_br_taken = 1;
}
insn.is_cond_br = 1;
