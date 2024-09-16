#include "include/avl_node.hpp"

template <typename NodeType> TreeNode<NodeType>::~TreeNode() {}

template <typename NodeType> int TreeNode<NodeType>::get_key() {
  return this->key;
}

AvlTreeNode::AvlTreeNode(int _key) {
  this->key = _key;
  this->left = this->right = nullptr;
  this->height = 1;
}

void AvlTreeNode::fix_height() {
  if (this->left == nullptr) {
    this->height = this->right == nullptr ? 1 : this->right->height + 1;
  } else {
    this->height = this->right == nullptr
                       ? this->left->height + 1
                       : std::max(this->right->height, this->left->height) + 1;
  }
}

int AvlTreeNode::balance_factor() {
  if (this == nullptr) {
    return 0;
  }

  if (this->left == nullptr) {
    if (this->right == nullptr) {
      return 0;
    }
    return -(this->right->height);
  }

  if (this->right == nullptr) {
    return this->left->height;
  }

  return this->left->height - this->right->height;
}

int AvlTreeNode::get_height() { return this->height; }

AvlTreeNode::~AvlTreeNode() {}
