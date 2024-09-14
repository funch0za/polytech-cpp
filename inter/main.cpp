#include "../tree/avl-tree/avl_tree.hpp"
#include <iostream>

int main() {
  AvlTree at;
  at.insert(1);

  std::cout << at.find_min();
}
