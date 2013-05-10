#pragma once

#include <cstdlib>
#include <algorithm>
#include "gc_cpp.h"

namespace yuzu {
namespace avl_tree {

template<typename K, typename V>
class AVLTree final : public gc {
public:
  ~AVLTree() = default;

  static AVLTree const *Empty() {
    return nullptr;
  }

  static int Height(AVLTree const *root) {
    if (root == nullptr) {
      return 0;
    }
    int height_left = Height(root->m_left);
    int height_right = Height(root->m_right);
    assert(std::abs(height_left - height_right) <= 1);
    assert(root->m_left == nullptr || root->m_left->m_key < root->m_key);
    assert(root->m_right == nullptr || root->m_key < root->m_right->m_key);
    return std::max(height_left, height_right) + 1;
  }

  static bool Lookup(AVLTree const *root, K key, V *value) {
    if (root == nullptr) {
      return false;
    }
    if (key < root->m_key) {
      return Lookup(root->m_left, key, value);
    }
    else if (root->m_key < key) {
      return Lookup(root->m_right, key, value);
    }
    else {
      *value = root->m_value;
      return true;
    }
  }
  
  static AVLTree const *Insert(AVLTree const *root, K key, V value) {
    if (root == nullptr) {
      return new AVLTree(key, value, nullptr, nullptr, Balance::kEqual);
    }
    if (key < root->m_key) {
      AVLTree const *left = Insert(root->m_left, key, value);
      assert(left != nullptr);
      switch (root->m_balance) {
      case Balance::kEqual:
        return new AVLTree(
          root->m_key, root->m_value, left, root->m_right, Balance::kLeft
        );
      case Balance::kRight:
        return new AVLTree(
          root->m_key, root->m_value, left, root->m_right, Balance::kEqual
        );
      case Balance::kLeft:
        return BalanceLeft(root, left);
      }
    }
    else if (root->m_key < key) {
      AVLTree const *right = Insert(root->m_right, key, value);
      assert(right != nullptr);
      switch (root->m_balance) {
      case Balance::kEqual:
        return new AVLTree(
          root->m_key, root->m_value, root->m_left, right, Balance::kRight
        );
      case Balance::kLeft:
        return new AVLTree(
          root->m_key, root->m_value, root->m_left, right, Balance::kEqual
        );
      case Balance::kRight:
        return BalanceRight(root, right);
      }
    }
    else {
      return new AVLTree(key, value, root->m_left, root->m_right, root->m_balance);
    }
  }
  
private:
  enum class Balance { kLeft, kEqual, kRight };
  
  AVLTree(K key, V value, AVLTree const *left, AVLTree const *right, Balance balance)
    : m_key(key), m_value(value), m_left(left), m_right(right), m_balance(balance) {
  }
  AVLTree(AVLTree const &) = delete;
  AVLTree(AVLTree &&) = delete;
  AVLTree &operator=(AVLTree const &) = delete;
  AVLTree &operator=(AVLTree &&) = delete;

  static AVLTree const *BalanceLeft(AVLTree const *root, AVLTree const *left) {
    switch (left->m_balance) {
    case Balance::kEqual:
      return new AVLTree(
        root->m_key, root->m_value, left, root->m_right, Balance::kLeft
      );
    case Balance::kLeft:
      return new AVLTree(
        left->m_key,
        left->m_value,
        left->m_left,
        new AVLTree(
          root->m_key, root->m_value, left->m_right, root->m_right, Balance::kEqual
        ),
        Balance::kEqual
      );
    case Balance::kRight:
      AVLTree const *left_right = left->m_right;
      assert(left_right != nullptr);
      return new AVLTree(
        left_right->m_key,
        left_right->m_value,
        new AVLTree(
          left->m_key, left->m_value, left->m_left, left_right->m_left, Balance::kEqual
        ),
        new AVLTree(
          root->m_key,
          root->m_value,
          left_right->m_right,
          root->m_right,
          Balance::kRight
        ),
        Balance::kEqual
      );
    }
  }

  static AVLTree const *BalanceRight(AVLTree const *root, AVLTree const *right) {
    switch (right->m_balance) {
    case Balance::kEqual:
      return new AVLTree(
        root->m_key, root->m_value, root->m_left, right, Balance::kRight
      );
    case Balance::kRight:
      return new AVLTree(
        right->m_key,
        right->m_value,
        new AVLTree(
          root->m_key, root->m_value, root->m_left, right->m_left, Balance::kEqual
        ),
        right->m_right,
        Balance::kEqual
      );
    case Balance::kLeft:
      AVLTree const *right_left = right->m_left;
      assert(right_left != nullptr);
      return new AVLTree(
        right_left->m_key,
        right_left->m_value,
        new AVLTree(
          root->m_key, root->m_value, root->m_left, right_left->m_left, Balance::kLeft
        ),
        new AVLTree(
          right->m_key,
          right->m_value,
          right_left->m_right,
          right->m_right,
          Balance::kEqual
        ),
        Balance::kEqual
      );
    }
  }
  
  K const m_key;
  V const m_value;
  AVLTree const *const m_left;
  AVLTree const *const m_right;
  Balance const m_balance;
};

} // namespace avl_tree
} // namespace yuzu
