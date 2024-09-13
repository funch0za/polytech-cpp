#include "avl_tree_node.hpp"
#include "avl_tree.hpp"

AvlTree::AvlTree() {}
AvlTree::~AvlTree() {}

void AvlTree::insert(int key) {
  this->head = this->insert_node(this->head, key);
  this->head = this->balance(this->head);
}

void AvlTree::remove(int key) {
  this->head = this->remove_node(this->head, key);
  this->head = this->balance(this->head);
}

AvlTreeNode* AvlTree::rotate_left(AvlTreeNode *node) {
  AvlTreeNode *right = node->right;
  node->right = right->left;
  right->left = node;
  
  node->fix_height();
  right->fix_height();

  return right;
}

AvlTreeNode* AvlTree::rotate_right(AvlTreeNode *node) {
  AvlTreeNode *left = node->left;
  node->left = left->right;
  left->right = node;
  
  node->fix_height();
  left->fix_height();

  return left;
}

AvlTreeNode *AvlTree::balance(AvlTreeNode *node) {
  if (node == nullptr) {
    return node;
  }
  
  node->fix_height();
  
  if (node->height >= 2) {
    node->left = this->balance(node->left);
    node->right = this->balance(node->right);   
    
    if (node->balance_factor() == 2) {
      if (node->right->balance_factor() < 0) {
        node->right = this->rotate_right(node->right);
        return rotate_left(node); 
      }
    } else if (node->balance_factor() == -2) {
      if (node->left->balance_factor() > 0) {
        node->left = this->rotate_left(node->left);
      }
      return rotate_right(node);
    }
  }

  return node;
}
