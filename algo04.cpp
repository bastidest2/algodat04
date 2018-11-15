#include "binary_tree.hpp"
#include <vector>


int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cout << "Usage: algo04 \"[<numer1>[<number2> ...]]\"" << std::endl;
    return 2;
  }

  if(std::string{argv[1]} == std::string{"test"}) {
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
    tree.remove(12);
    tree.print();
    std::cout << tree.findMin()->getValue() << std::endl;
    std::cout << tree.find(23)->getValue() << std::endl;
    return 0;
  }

  std::vector<int> inputs;
  for(size_t i = 1; i < static_cast<size_t>(argc); i++) {
    try {
      inputs.push_back(std::stoi(argv[i]));
    } catch(const std::exception& e) {
      std::cerr << "invalid argument \"" << argv[i] << "\": unable to convert to integer" << std::endl;
      return 3;
    }
  }

  if(inputs.size() <= 0) {
    std::cerr << "at least one numer has to be supplied" << std::endl;
    return 4;
  }

  binary_tree::Tree<int> tree;

  for(size_t i = 0; i < inputs.size(); i++) {
    tree.insert(inputs[i]);
  }

  tree.printTheNodesOrNone();
  
  return 0;
}