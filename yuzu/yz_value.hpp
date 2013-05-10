#pragma once

#include "gc_cpp.h"

namespace yuzu {
namespace yz_value {

class YzValue : public gc {
public:
  virtual ~YzValue() = default;
protected:
  YzValue() = default;
private:
  YzValue(YzValue const &) = delete;
  YzValue(YzValue &&) = delete;
  YzValue &operator=(YzValue const &) = delete;
  YzValue &operator=(YzValue &&) = delete;
};

} // namespace yz_value
} // namespace yuzu
