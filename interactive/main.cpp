#include "../tree/include/avl_tree.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {-2,   0,  2, 10, -1, 5, 100, 132, 32,  -33, -100, 234,
                        2544, -5, 0, 1,  2,  3, -3,  4,   -22, -32, -33,  -34};
  for (int i = 20; i <= 30; ++i) {
    v.push_back(i);
  }

  AvlTree tree;

  for (auto &e : v) {
    std::cout << e << '\n';
    tree.print();
    tree.insert(e);
    std::cout << '\n';
  }
  std::cout << '\n';

  tree.print();

  while (tree.head != nullptr) {
    std::cout << tree.find_min() << '\n';
    tree.remove(tree.find_min());
  }
}
