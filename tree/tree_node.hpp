#ifndef TREE_NODE_H
#define TREE_NODE_H

class TreeNode {
  public:
    TreeNode *left, *right;
    int key;
  virtual int get_key();
};

#endif
