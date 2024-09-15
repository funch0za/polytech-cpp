#include "include/avl_node.hpp"
#include "include/avl_tree.hpp"

template <typename NodeType> Tree<NodeType>::~Tree() {}

template <typename NodeType>
NodeType *Tree<NodeType>::find_min(NodeType *node) {
  if (node->left == nullptr) {
    return node;
  }
  return this->find_min(node->left);
}

template <typename NodeType> int Tree<NodeType>::find_min() {
  return (this->find_min(this->head))->key;
}

template <typename NodeType>
bool Tree<NodeType>::find(NodeType *node, int key) {
  if (node == nullptr) {
    return false;
  }
  if (node->key == key) {
    return true;
  }
  return this->find(node->left, key) || this->find(node->right, key);
}

template <typename NodeType> bool Tree<NodeType>::find(int key) {
  return this->find(this->head, key);
}

template <typename NodeType> bool Tree<NodeType>::empty() {
  return this->head == nullptr;
}

// --------------- AVL TREE ---------------

AvlTree::AvlTree() { this->head = nullptr; }

AvlTree::~AvlTree() {}

AvlTreeNode *AvlTree::rotate_left(AvlTreeNode *node) {
  AvlTreeNode *right = node->right;
  node->right = right->left;
  right->left = node;

  node->fix_height();
  right->fix_height();

  return right;
}

AvlTreeNode *AvlTree::rotate_right(AvlTreeNode *node) {
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

  if (node->balance_factor() == 2) {
    if (node->right->balance_factor() < 0) {
      node->right = this->rotate_right(node->right);
    }
    return this->rotate_left(node);
  } else if (node->balance_factor() == -2) {
    if (node->left->balance_factor() > 0) {
      node->left = this->rotate_left(node->left);
    }
    return this->rotate_right(node);
  }

  return node;
}

AvlTreeNode *AvlTree::insert_node(AvlTreeNode *node, int key) {
  if (node == nullptr) {
    return new AvlTreeNode(key);
  }
  if (key < node->key) {
    node->left = this->insert_node(node->left, key);
  } else {
    node->right = this->insert_node(node->right, key);
  }
  return this->balance(node);
}

AvlTreeNode *AvlTree::remove_node(AvlTreeNode *node, int key) {
  if (node != nullptr) {
    if (key == node->get_key()) {
      AvlTreeNode *left = node->left;
      AvlTreeNode *right = node->right;
      delete node;

      if (left == nullptr) {
        return right;
      }
      if (right == nullptr) {
        return left;
      }

      AvlTreeNode *min = this->find_min(right);
      min->right = this->remove_min(right);
      min->left = left;
      return this->balance(min);

    } else if (key < node->key) {
      node->left = this->remove_node(node->left, key);
    } else {
      node->right = this->remove_node(node->right, key);
    }
  }
  return this->balance(node);
}

void AvlTree::insert(int key) {
  this->head = this->insert_node(this->head, key);
}

void AvlTree::remove(int key) {
  this->head = this->remove_node(this->head, key);
}

void AvlTree::print() { this->print(this->head); }

AvlTreeNode *AvlTree::remove_min(AvlTreeNode *node) {
  if (node->left == nullptr) {
    return node->right;
  }
  node->left = this->remove_min(node->left);
  return this->balance(node);
}

void AvlTree::print(AvlTreeNode *node) {
  if (node == nullptr) {
    return;
  }

  this->print(node->left);

  std::cout << "key : " << node->key << " balance factor : " << node->balance_factor() << '\n';
  
  this->print(node->right);
}

