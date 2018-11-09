#include <iostream>
#include <memory>
#include <vector>

class TreeNode {
private:
  const int m_iValue;
  std::shared_ptr<TreeNode> m_pLeft;
  std::shared_ptr<TreeNode> m_pRight;

public:
  TreeNode(const int value)
  : m_iValue(value)
  , m_pLeft(nullptr)
  , m_pRight(nullptr)
  {

  }

  int getValue() const {
    return m_iValue;
  }

  void insert(int i) {
    if(i < m_iValue) {
      if(m_pLeft.get() == nullptr) {
        m_pLeft = std::make_shared<TreeNode>(TreeNode(i));
      } else {
        m_pLeft->insert(i);
      }
    } else {
      if(m_pRight.get() == nullptr) {
        m_pRight = std::make_shared<TreeNode>(TreeNode(i));
      } else {
        m_pRight->insert(i);
      }
    }
  }

  void printTheNodesOrNone() const {
    if((m_iValue % 5) == 0) {
      if(m_pLeft.get() != nullptr) {
        std::cout << m_pLeft->getValue() << " ";
      }
      if(m_pRight.get() != nullptr) {
        std::cout << m_pRight->getValue() << " ";
      }
    }
    if(m_pLeft.get() != nullptr){
      m_pLeft->printTheNodesOrNone();
    }
    if(m_pRight.get() != nullptr){
      m_pRight->printTheNodesOrNone();
    }
  }
};


int main(int argc, char* argv[]) {
  if(argc < 2) {
    std::cout << "Usage: algo04 \"[<numer1>[<number2> ...]]\"" << std::endl;
    return 2;
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

  TreeNode root(inputs[0]);

  for(size_t i = 1; i < inputs.size(); i++) {
    root.insert(inputs[i]);
  }

  root.printTheNodesOrNone();
  std::cout << std::endl;

  return 0;
}
