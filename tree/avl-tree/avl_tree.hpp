#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "../tree.hpp"
#include "avl_tree_node.hpp"

class AvlTree: public Tree<AvlTreeNode> {
  public:
    AvlTree();
    ~AvlTree();

    void insert(int key) override;
    void remove(int key) override;

    AvlTreeNode* balance(AvlTreeNode *node);
    AvlTreeNode* rotate_right(AvlTreeNode *node);
    AvlTreeNode* rotate_left(AvlTreeNode *node);
};

#endif
