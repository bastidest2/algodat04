#include "binary_tree.hpp"

int main() {
  binary_tree::Tree<int> tree{};
  tree.insert(12);
  tree.insert(7);
  tree.insert(18);
  tree.insert(2);
  tree.insert(10);
  tree.insert(14);
  tree.insert(23);
  tree.insert(8);
  tree.insert(9);
  tree.print();
  return 0;
}