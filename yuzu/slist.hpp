#pragma once

#include <cassert>
#include "gc_cpp.h"

namespace yuzu {
namespace slist {

template<typename T>
class SList final : public gc {
public:
  ~SList() = default;

  static SList const *Nil() {
    return nullptr;
  }
  
  static SList const *Cons(T head, SList const *tail) {
    return new SList(head, tail);
  }
  
  static bool IsNil(SList const *list) {
    return list == nullptr;
  }
  
  static T Head(SList const *list) {
    assert(list != nullptr);
    return list->m_head;
  }

  static SList const *Tail(SList const *list) {
    assert(list != nullptr);
    return list->m_tail;
  }

private:
  SList(T head, SList const *tail) : m_head(head), m_tail(tail) {}
  SList(SList const &) = delete;
  SList(SList &&) = delete;
  SList &operator=(SList const &) = delete;
  SList &operator=(SList &&) = delete;

  T const m_head;
  SList const *const m_tail;
};

} // namespace slist
} // namespace yuzu
