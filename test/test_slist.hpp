#pragma once

#include "gc_cpp.h"
#include "gtest/gtest.h"
#include "yuzu/slist.hpp"

namespace test_slist {

using ::yuzu::slist::SList;

class SListTest : public ::testing::Test, public gc {
protected:
  SListTest() = default;
  virtual ~SListTest() = default;

  virtual void SetUp() {
    m_int_list_nil = SList<int>::Nil();
    m_int_list_1 = SList<int>::Nil();
    m_int_list_1 = SList<int>::Cons(1, m_int_list_1);
    m_int_list_123 = SList<int>::Nil();
    m_int_list_123 = SList<int>::Cons(3, m_int_list_123);
    m_int_list_123 = SList<int>::Cons(2, m_int_list_123);
    m_int_list_123 = SList<int>::Cons(1, m_int_list_123);
  }
  virtual void TearDown() {
  }

  SList<int> const *m_int_list_nil;
  SList<int> const *m_int_list_1;
  SList<int> const *m_int_list_123;
};

TEST_F(SListTest, IsNilWorks) {
  EXPECT_TRUE(SList<int>::IsNil(m_int_list_nil));
  EXPECT_FALSE(SList<int>::IsNil(m_int_list_1));
  EXPECT_FALSE(SList<int>::IsNil(m_int_list_123));
}

TEST_F(SListTest, HeadWorks) {
  EXPECT_EQ(1, SList<int>::Head(m_int_list_1));
  EXPECT_EQ(1, SList<int>::Head(m_int_list_123));
}

TEST_F(SListTest, TailWorks) {
  SList<int> const *list;
  list = SList<int>::Tail(m_int_list_1);
  EXPECT_TRUE(SList<int>::IsNil(m_int_list_nil));
  list = SList<int>::Tail(m_int_list_123);
  EXPECT_FALSE(SList<int>::IsNil(list));
  EXPECT_EQ(2, SList<int>::Head(list));
  list = SList<int>::Tail(list);
  EXPECT_FALSE(SList<int>::IsNil(list));
  EXPECT_EQ(3, SList<int>::Head(list));
  list = SList<int>::Tail(list);
  EXPECT_TRUE(SList<int>::IsNil(list));
}

} // namespace test_slist
