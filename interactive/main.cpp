#include "../tree/avl-tree/avl_tree.hpp"
#include <iostream>

int main() {
  AvlTreeNode node(2);
  std::cout << node.get_key();
}
