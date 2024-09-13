#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

#include "../tree_node.hpp"
#include <algorithm>

class AvlTreeNode : public TreeNode<AvlTreeNode>{
  public: 
  int height;  
  AvlTreeNode(int _key);
  ~AvlTreeNode();
  
  void fix_height();
  int balance_factor();
};

#endif
