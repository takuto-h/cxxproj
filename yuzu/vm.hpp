#pragma once

#include "gc_cpp.h"

namespace yuzu {
namespace vm {

class VM final : public gc {
public:
  ~VM() = default;
private:
  VM() = default;
  VM(VM const &) = delete;
  VM(VM &&) = delete;
  VM &operator=(VM const &) = delete;
  VM &operator=(VM &&) = delete;
};

} // namespace vm
} // namespace yuzu
