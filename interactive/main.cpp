#include "../tree/include/avl_tree.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {-2,   0,  2, 10, -1, 5, 100, 132, 32,  -33, -100, 234,
                      2544, -5, 0, 1,  2,  3, -3,  4,   -22, -32, -33,  -34};

  AvlTree tree;

  for (auto &e : v) {
    tree.insert(e);
  }

  tree.print_sorted();



  std::cout << '\n';
  tree.print_graph();
}
