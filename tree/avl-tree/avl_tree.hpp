#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "../tree.hpp"
#include "avl_tree_node.hpp"

template<typename T>
class AvlTree: private Tree<T> {
  AvlTree();
  ~AvlTree();

  void balance(AvlTreeNode *node);
  void rotate_right(AvlTreeNode *node);
  void rotate_left(AvlTreeNode *node);
};

#endif
