#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

#include "node_base.hpp"
#include <algorithm>

class AvlTreeNode : public TreeNode<AvlTreeNode>{
  public: 
  int height;  
  ~AvlTreeNode();
  AvlTreeNode(int _key);
  
  void fix_height();
  int balance_factor();
};

#endif
