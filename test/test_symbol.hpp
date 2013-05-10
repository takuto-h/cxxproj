#pragma once

#include "gc_cpp.h"
#include "gtest/gtest.h"
#include "yuzu/symbol.hpp"

namespace test_symbol {

using ::yuzu::symbol::Symbol;

class SymbolTest : public ::testing::Test, public gc {
protected:
  SymbolTest() = default;
  virtual ~SymbolTest() = default;

  virtual void SetUp() {
    m_sym_abc = Symbol::Intern("abc");
    m_sym_abc2 = Symbol::Intern("abc");
    m_sym_def = Symbol::Intern("def");
  }
  virtual void TearDown() {
  }

  Symbol const *m_sym_abc;
  Symbol const *m_sym_abc2;
  Symbol const *m_sym_def;
};

TEST_F(SymbolTest, InternWorks) {
  EXPECT_EQ(m_sym_abc, m_sym_abc2);
  EXPECT_NE(m_sym_def, m_sym_abc);
  EXPECT_NE(m_sym_def, m_sym_abc2);
}

} // namespace test_symbol
