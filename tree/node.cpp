#include "include/avl_node.hpp"

template <typename NodeType>
int TreeNode<NodeType>::get_key() {
  return this->key;
}

AvlTreeNode::AvlTreeNode(int _key) {
  this->key = _key;
  this->left = this->right = nullptr;
  this->height = 1;
}

void AvlTreeNode::fix_height() {
  this->height = std::max(this->left->height, this->right->height) + 1;
}

int AvlTreeNode::balance_factor() {
  if (this->left == nullptr) {
    return (this->right == nullptr) ? 0 : -(this->right->height);    
  }
  if (this->right == nullptr) {
   return 0; 
  }
  return this->left->height - this->right->height;
}

AvlTreeNode::~AvlTreeNode() {}
