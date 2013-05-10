#include "gtest/gtest.h"
#include "test/test_slist.hpp"
#include "test/test_avl_tree.hpp"
#include "test/test_symbol.hpp"

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
