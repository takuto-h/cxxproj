#pragma once

#include "gc_cpp.h"

namespace yuzu {
namespace insn {

class Insn : public gc {
public:
  virtual ~Insn() = 0;
protected:
  Insn() = default;
private:
  Insn(Insn const &) = delete;
  Insn(Insn &&) = delete;
  Insn &operator=(Insn const &) = delete;
  Insn &operator=(Insn &&) = delete;
};

} // namespace insn
} // namespace yuzu
