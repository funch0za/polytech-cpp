#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>

template <typename NodeType> class TreeNode {
public:
  NodeType *left, *right;
  int key;
  virtual ~TreeNode<NodeType>();
  virtual int get_key();
};

#endif
