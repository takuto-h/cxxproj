#pragma once

#include "gc_cpp.h"
#include "gtest/gtest.h"
#include "yuzu/avl_tree.hpp"

namespace test_avl_tree {

using ::yuzu::avl_tree::AVLTree;

class AVLTreeTest : public ::testing::Test, public gc {
protected:
  AVLTreeTest() = default;
  virtual ~AVLTreeTest() = default;

  virtual void SetUp() {
    m_int_int_avl_tree_empty = AVLTree<int, int>::Empty();
    m_int_int_avl_tree_12345 = AVLTree<int, int>::Empty();
    m_int_int_avl_tree_12345 = AVLTree<int, int>::Insert(m_int_int_avl_tree_12345, 1, 25);
    m_int_int_avl_tree_12345 = AVLTree<int, int>::Insert(m_int_int_avl_tree_12345, 2, 16);
    m_int_int_avl_tree_12345 = AVLTree<int, int>::Insert(m_int_int_avl_tree_12345, 3, 9);
    m_int_int_avl_tree_12345 = AVLTree<int, int>::Insert(m_int_int_avl_tree_12345, 4, 4);
    m_int_int_avl_tree_12345 = AVLTree<int, int>::Insert(m_int_int_avl_tree_12345, 5, 1);
    m_int_int_avl_tree_0_to_9 = AVLTree<int, int>::Empty();
    m_int_int_avl_tree_0_to_9 = AVLTree<int, int>::Insert(m_int_int_avl_tree_0_to_9, 3, 0);
    m_int_int_avl_tree_0_to_9 = AVLTree<int, int>::Insert(m_int_int_avl_tree_0_to_9, 8, 6);
    m_int_int_avl_tree_0_to_9 = AVLTree<int, int>::Insert(m_int_int_avl_tree_0_to_9, 1, 0);
    m_int_int_avl_tree_0_to_9 = AVLTree<int, int>::Insert(m_int_int_avl_tree_0_to_9, 4, 0);
    m_int_int_avl_tree_0_to_9 = AVLTree<int, int>::Insert(m_int_int_avl_tree_0_to_9, 5, 7);
    m_int_int_avl_tree_0_to_9 = AVLTree<int, int>::Insert(m_int_int_avl_tree_0_to_9, 2, 0);
    m_int_int_avl_tree_0_to_9 = AVLTree<int, int>::Insert(m_int_int_avl_tree_0_to_9, 9, 0);
    m_int_int_avl_tree_0_to_9 = AVLTree<int, int>::Insert(m_int_int_avl_tree_0_to_9, 0, 0);
    m_int_int_avl_tree_0_to_9 = AVLTree<int, int>::Insert(m_int_int_avl_tree_0_to_9, 7, 0);
    m_int_int_avl_tree_0_to_9 = AVLTree<int, int>::Insert(m_int_int_avl_tree_0_to_9, 6, 0);
  }
  virtual void TearDown() {
  }

  AVLTree<int, int> const *m_int_int_avl_tree_empty;
  AVLTree<int, int> const *m_int_int_avl_tree_12345;
  AVLTree<int, int> const *m_int_int_avl_tree_0_to_9;
};

TEST_F(AVLTreeTest, HeightWorks) {
  EXPECT_EQ(0, (AVLTree<int, int>::Height(m_int_int_avl_tree_empty)));
  EXPECT_EQ(3, (AVLTree<int, int>::Height(m_int_int_avl_tree_12345)));
  EXPECT_EQ(4, (AVLTree<int, int>::Height(m_int_int_avl_tree_0_to_9)));
}

TEST_F(AVLTreeTest, LookupWorks) {
  int value;
  EXPECT_FALSE((AVLTree<int, int>::Lookup(m_int_int_avl_tree_empty, 0, &value)));
  EXPECT_FALSE((AVLTree<int, int>::Lookup(m_int_int_avl_tree_empty, 4, &value)));
  EXPECT_FALSE((AVLTree<int, int>::Lookup(m_int_int_avl_tree_12345, 0, &value)));
  EXPECT_TRUE((AVLTree<int, int>::Lookup(m_int_int_avl_tree_12345, 1, &value)));
  EXPECT_EQ(25, value);
  EXPECT_TRUE((AVLTree<int, int>::Lookup(m_int_int_avl_tree_12345, 4, &value)));
  EXPECT_EQ(4, value);
  EXPECT_TRUE((AVLTree<int, int>::Lookup(m_int_int_avl_tree_12345, 5, &value)));
  EXPECT_EQ(1, value);
  EXPECT_TRUE((AVLTree<int, int>::Lookup(m_int_int_avl_tree_0_to_9, 8, &value)));
  EXPECT_EQ(6, value);
  EXPECT_TRUE((AVLTree<int, int>::Lookup(m_int_int_avl_tree_0_to_9, 5, &value)));
  EXPECT_EQ(7, value);
}

} // namespace test_avl_tree
