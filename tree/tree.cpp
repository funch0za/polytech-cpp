#include "include/avl_node.hpp"
#include "include/avl_tree.hpp"

// ------------------------- BASE --------------------------

template <typename NodeType> Tree<NodeType>::~Tree() {}

template <typename NodeType>
NodeType *Tree<NodeType>::find_min(NodeType *node) {
  if (node->get_left() == nullptr) {
    return node;
  }
  return this->find_min(node->get_left());
}

template <typename NodeType> int Tree<NodeType>::find_min() {
  return (this->find_min(this->head))->get_key();
}

template <typename NodeType>
bool Tree<NodeType>::find(NodeType *node, int key) {
  if (node == nullptr) {
    return false;
  }
  if (node->get_key() == key) {
    return true;
  }
  return this->find(node->get_left(), key) || this->find(node->get_right(), key);
}

template <typename NodeType> bool Tree<NodeType>::find(int key) {
  return this->find(this->head, key);
}

template <typename NodeType> bool Tree<NodeType>::empty() {
  return this->head == nullptr;
}

template <typename NodeType> void Tree<NodeType>::print_sorted(NodeType *node) {
  if (node == nullptr) {
    return;
  }

  this->print_sorted(node->get_left());
  std::cout << node->get_key() << ' ';
  this->print_sorted(node->get_right());
}

template <typename NodeType> void Tree<NodeType>::print_sorted() {
  this->print_sorted(this->head);
}

template <typename NodeType>
void Tree<NodeType>::print_graph(NodeType *node, std::string prefix) {
  if (node == nullptr) {
    return;
  }

  if (node->get_left() == nullptr && node->get_right() == nullptr) {
    return;
  }

  std::cout << prefix;
  if (node->get_left() != nullptr && node->get_right() != nullptr) {
    std::cout << "├──";
  }
  if (node->get_left() == nullptr && node->get_right() != nullptr) {
    std::cout << "└──";
  }
  if (node->get_right() != nullptr) {
    std::string add_prefix = "";
    if (node->get_left() != nullptr &&
        (node->get_right()->get_right() != nullptr || node->get_right()->get_left() != nullptr)) {
      add_prefix += "│   ";
    } else {
      add_prefix += "    ";
    }
    std::cout << node->get_right()->get_key() << '\n';
    this->print_graph(node->get_right(), prefix + add_prefix);
  }
  if (node->get_left() != nullptr) {
    if (node->get_right() != nullptr) {
      std::cout << prefix;
    }
    std::cout << "└── " << node->get_left()->get_key() << '\n';
    prefix += "    ";
    this->print_graph(node->get_left(), prefix);
  }
}

template <typename NodeType> void Tree<NodeType>::print_graph() {
  if (this->head != nullptr) {
    std::cout << this->head->get_key() << '\n';
  }
  this->print_graph(this->head, "");
}

// --------------- AVL TREE ---------------

AvlTree::AvlTree() {
  this->head = nullptr;
}

AvlTree::~AvlTree() {}

AvlTreeNode *AvlTree::rotate_left(AvlTreeNode *node) {
  AvlTreeNode *b = node->get_right();
  node->set_right(b->get_left());
  b->set_left(node);

  node->fix_height();
  b->fix_height();

  return b;
}

AvlTreeNode *AvlTree::rotate_right(AvlTreeNode *node) {
  AvlTreeNode *b = node->get_left();
  node->set_left(b->get_right());
  b->set_right(node);

  node->fix_height();
  b->fix_height();

  return b;
}

AvlTreeNode *AvlTree::balance(AvlTreeNode *node) {
  if (node == nullptr) {
    return node;
  }

  node->fix_height();

  if (node->balance_factor() == -2) {
    if (node->get_left()->balance_factor() == 0 ||
        node->get_left()->balance_factor() == -1) {
      return this->rotate_left(node);
    }
    node->set_right(this->rotate_right(node->get_right()));
    return this->rotate_left(node);
  } else if (node->balance_factor() == 2) {
    if (node->get_right()->balance_factor() == 0 ||
        node->get_right()->balance_factor() == 1) {
      return this->rotate_right(node);
    }
    node->set_left(this->rotate_left(node->get_left()));
    return this->rotate_right(node);
  }

  return node;
}

AvlTreeNode *AvlTree::insert_node(AvlTreeNode *node, int key) {
  if (node == nullptr) {
    return new AvlTreeNode(key, nullptr);
  }
  if (key < node->get_key()) {
    node->set_left(this->insert_node(node->get_left(), key));
  } else {
    node->set_right(this->insert_node(node->get_right(), key));
  }
   
  return this->balance(node);
}

AvlTreeNode *AvlTree::remove_node(AvlTreeNode *node, int key) {
  if (node != nullptr) {
    if (key == node->get_key()) {
      AvlTreeNode *left = node->get_left();
      AvlTreeNode *right = node->get_right();
      delete node;

      if (left == nullptr) {
        return right;
      }
      if (right == nullptr) {
        return left;
      }

      AvlTreeNode *min = this->find_min(right);
      min->set_right(this->remove_min(right));
      min->set_left(left);
      return this->balance(min);

    } else if (key < node->get_key()) {
      node->set_left(this->remove_node(node->get_left(), key));
    } else {
      node->set_right(this->remove_node(node->get_right(), key));
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

AvlTreeNode *AvlTree::remove_min(AvlTreeNode *node) {
  if (node->get_left() == nullptr) {
    return node->get_right();
  }
  node->set_left(this->remove_min(node->get_left()));
  return this->balance(node);
}
