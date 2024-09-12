#include "tree.hpp"
#include "tree_node.hpp"

template <typename NodeType>
NodeType Tree<NodeType>::insert(NodeType *node, int key) {
  if (node == nullptr) {
    return new NodeType(key);
  }
  if (key < node->key) {
    node->left = this->insert(node->left, key);
  } else {
    node->right = this->insert(node->right, key);
  }
  return node;
}

template <typename NodeType>
void Tree<NodeType>::insert(int key) {
  this->insert(this->head, key);
}

template<typename NodeType>
NodeType Tree<NodeType>::remove(NodeType *node, int key) {
  if (node == nullptr) {
    return nullptr;
  } 
  if (key == node->key) {
    NodeType *left = node->left;
    NodeType  *right = node->right;
    delete node;
    
    if (left == nullptr) {
      return right;
    }
    if (right == nullptr) {
      return left;
    }
  
  } else if (key < node->key) {
    node->left = remove(node->left, key);   
  } else {
    node->right = remove(node->right, key);
  }

  return node;
}

template<typename NodeType>
void Tree<NodeType>::remove(int key) {
  this->remove(this->head, key); 
}
