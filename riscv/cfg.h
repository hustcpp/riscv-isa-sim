// See LICENSE for license details.
#ifndef _RISCV_CFG_H
#define _RISCV_CFG_H

#include <optional>
#include <vector>
#include "decode.h"
#include <cassert>

typedef enum {
  endianness_little,
  endianness_big
} endianness_t;

template <typename T>
class cfg_arg_t {
public:
  cfg_arg_t(T default_val)
    : value(default_val), was_set(false) {}

  bool overridden() const { return was_set; }

  T operator()() const { return value; }

  T operator=(const T v) {
    value = v;
    was_set = true;
    return value;
  }

private:
  T value;
  bool was_set;
};

// Configuration that describes a memory region
class mem_cfg_t
{
public:
  static bool check_if_supported(reg_t base, reg_t size);

  mem_cfg_t(reg_t base, reg_t size);

  reg_t get_base() const {
    return base;
  }

  reg_t get_size() const {
    return size;
  }

  reg_t get_inclusive_end() const {
    return base + size - 1;
  }

private:
  reg_t base;
  reg_t size;
};

class cfg_t
{
public:
  cfg_t(std::pair<reg_t, reg_t> default_initrd_bounds,
        const char *default_bootargs,
        const char *default_isa, const char *default_priv,
        const char *default_varch,
        const bool default_misaligned,
        const endianness_t default_endianness,
        const bool default_dirty_enabled,
        const reg_t default_pmpregions,
        const std::vector<mem_cfg_t> &default_mem_layout,
        const std::vector<int> default_hartids,
        bool default_real_time_clint)
    : initrd_bounds(default_initrd_bounds),
      bootargs(default_bootargs),
      isa(default_isa),
      priv(default_priv),
      varch(default_varch),
      misaligned(default_misaligned),
      endianness(default_endianness),
      dirty_enabled(default_dirty_enabled),
      pmpregions(default_pmpregions),
      mem_layout(default_mem_layout),
      hartids(default_hartids),
      explicit_hartids(false),
      real_time_clint(default_real_time_clint)
  {}

  cfg_arg_t<std::pair<reg_t, reg_t>> initrd_bounds;
  cfg_arg_t<const char *>            bootargs;
  cfg_arg_t<const char *>            isa;
  cfg_arg_t<const char *>            priv;
  cfg_arg_t<const char *>            varch;
  bool                               misaligned;
  endianness_t                       endianness;
  bool                               dirty_enabled;
  reg_t                              pmpregions;
  cfg_arg_t<std::vector<mem_cfg_t>>  mem_layout;
  std::optional<reg_t>               start_pc;
  cfg_arg_t<std::vector<int>>        hartids;
  bool                               explicit_hartids;
  cfg_arg_t<bool>                    real_time_clint;
  std::optional<reg_t>               pf_start_pc;
  std::optional<reg_t>               pf_end_pc;

  size_t nprocs() const { return hartids().size(); }
};

#endif
