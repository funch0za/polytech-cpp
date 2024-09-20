#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

#include "node_base.hpp"
#include <algorithm>

class AvlTreeNode final : public TreeNode<AvlTreeNode> {
private:
  int height;

public:
  ~AvlTreeNode();
  AvlTreeNode(int _key, AvlTreeNode *parent);

  void fix_height();
  int balance_factor();
  int get_height();
};

#endif
