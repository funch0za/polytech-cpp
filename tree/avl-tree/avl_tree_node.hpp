#include "../tree_node.hpp"

class AvlTreeNode : private TreeNode {
  private:
    int height;
  void fix_height();
  int balance_factor();
  AvlTreeNode(int value);
  ~AvlTreeNode();
};
