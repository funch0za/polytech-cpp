#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "tree_base.hpp"
#include "avl_node.hpp"

class AvlTree: public Tree<AvlTreeNode> {
  public:
    AvlTree();
    void recursive_destructor(AvlTreeNode *node);

    void insert(int key) override;
    void remove(int key) override;

    AvlTreeNode* balance(AvlTreeNode *node);
    AvlTreeNode* rotate_right(AvlTreeNode *node);
    AvlTreeNode* rotate_left(AvlTreeNode *node);
};

#endif
