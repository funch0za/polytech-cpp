#include "../tree/include/avl_tree.hpp"
#include <iostream>
#include <vector>

int main() {
  std::cout << "Enter size of sequence: ";
  int n;
  std::cin >> n;

  std::cout << "\nEnter sequence: ";
  AvlTree tree;
  while (n--) {
    int new_key;
    std::cin >> new_key;
    tree.insert(new_key);
  }

  std::cout << "\nAvl-Tree:\n";
  tree.print_graph();
}
