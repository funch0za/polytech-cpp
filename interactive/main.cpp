#include "../tree/include/avl_tree.hpp"
#include <iostream>
#include <vector>

int main() {
  std::cout << "Enter size of sequence: ";
  int n;
  std::cin >> n;

  std::cout << "\nEnter sequence: ";
  std::vector<int> seq(n);
  for (auto &elem : seq) {
    std::cin >> elem;
  }

  AvlTree tree;
  for (auto &elem : seq) {
    tree.insert(elem);
  }

  std::cout << "\nAvl-Tree:\n";
  tree.print_graph();
}
