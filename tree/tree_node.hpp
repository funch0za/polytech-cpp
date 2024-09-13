#ifndef TREE_NODE_H
#define TREE_NODE_H

template<typename NodeType>
class TreeNode {
  public:
    NodeType *left, *right;
    int key;
  virtual int get_key();
};

#endif
