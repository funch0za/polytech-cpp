#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

#include "../tree_node.hpp"

class AvlTreeNode : private TreeNode {
  private:
    int height;
  void fix_height();
  int balance_factor();
  AvlTreeNode(int key);
  ~AvlTreeNode();
};

#endif
