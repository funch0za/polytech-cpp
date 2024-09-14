#include "include/avl_tree.hpp"

template<typename NodeType>
Tree<NodeType>::~Tree() {
}

template <typename NodeType>
NodeType* Tree<NodeType>::insert_node(NodeType *node, int key) {
  if (node == nullptr) {
    return new NodeType(key);
  }
  if (key < node->key) {
    node->left = this->insert_node(node->left, key);
  } else {
    node->right = this->insert_node(node->right, key);
  }
  return node;
}

template <typename NodeType>
void Tree<NodeType>::insert(int key) {
  this->head = this->insert_node(this->head, key);
}

template <typename NodeType>
NodeType* Tree<NodeType>::remove_node(NodeType *node, int key) {
  if (node != nullptr) {
    if (key == node->get_key()) {
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
      node->left = this->remove_node(node->left, key);
    } else {
      node->right = this->remove_node(node->right, key);
    }
  }
  return node;
}

template <typename NodeType>
void Tree<NodeType>::remove(int key) {
  this->head = this->remove_node(this->head, key);
}

template <typename NodeType>
NodeType* Tree<NodeType>::find_min(NodeType *node) {
  return this->find_min(node->left) != nullptr ? node->left : node;
}

template <typename NodeType>
int Tree<NodeType>::find_min() {
  return (this->find_min(this->head))->key;
}

template <typename NodeType>
NodeType* Tree<NodeType>::remove_min(NodeType *node) {
  if (node->left == nullptr) {
    return node->right;
  }
  node->left = this->remove_min(node->left);
  return node;
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

template<typename NodeType>
bool Tree<NodeType>::find(int key) {
  return this->find(this->head, key);
}

AvlTree::AvlTree() {
  this->head = nullptr;
}

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
