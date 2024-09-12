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
  this = this->insert(this->head, key);
}

template <typename NodeType>
NodeType Tree<NodeType>::remove(NodeType *node, int key) {
  if (node != nullptr) {
    if (key == node->key) {
      NodeType *left = node->left;
      NodeType *right = node->right;
      delete node;

      if (left == nullptr) {
        return right;
      }
      if (right == nullptr) {
        return left;
      }
      
      NodeType *min = this->find_min(right);
      min->right = this->remove_min(right);
      min->left = left;
      return min;
    
    } else if (key < node->key) {
      node->left = this->remove(node->left, key);
    } else {
      node->right = this->remove(node->right, key);
    }
  }
  return node;
}

template <typename NodeType>
void Tree<NodeType>::remove(int key) {
  this = this->remove(this->head, key);
}

template <typename NodeType>
NodeType Tree<NodeType>::find_min(NodeType *node) {
  return node->left ? this->find_min(node->left) != nullptr : node;
}

template <typename NodeType>
int Tree<NodeType>::find_min() {
  return (this->find_min(this->head))->key;
}

template <typename NodeType>
NodeType Tree<NodeType>::remove_min(NodeType *node) {
  if (node->left == nullptr) {
    return node->right;
  }
  node->left = this->remove_min(node->left);
  return node;
}

template<typename NodeType>
bool Tree<NodeType>::find(int key) {
  return this->find(this->head);
}

template<typename NodeType>
bool Tree<NodeType>::find(NodeType *node, int key) {
  if (node == nullptr) {
    return false;
  }
  if (node->key == key) {
    return true;
  }
  return this->find(node->left, key) || this->find(node->right, key);
}
