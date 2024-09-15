#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "avl_node.hpp"
#include "tree_base.hpp"
#include <iostream>

class AvlTree : public Tree<AvlTreeNode> {
public:
  AvlTree();
  ~AvlTree();

  AvlTreeNode *insert_node(AvlTreeNode *node, int key) override;
  AvlTreeNode *remove_node(AvlTreeNode *node, int key) override;
  AvlTreeNode *remove_min(AvlTreeNode *node) override;

  void insert(int key) override;
  void remove(int key) override;

  void print(AvlTreeNode *node);
  void print();

private:
  AvlTreeNode *balance(AvlTreeNode *node);
  AvlTreeNode *rotate_right(AvlTreeNode *node);
  AvlTreeNode *rotate_left(AvlTreeNode *node);
};

#endif
