#include <memory>
#include <iostream>

namespace binary_tree {
    template <typename T>
    class Node {
    public:
        Node(const T value)
        : m_value(value)
        , m_pLeft(nullptr)
        , m_pRight(nullptr) {
            
        };

        const T getValue() const {
            return m_value;
        }

        void print(const size_t depth = 0) const {
            for(size_t i = 0; i < depth; i++) {
                std::cout << " ";
            }
            std::cout << m_value << std::endl;
            if(m_pLeft) {
                std::cout << "l";
                m_pLeft->print(depth + 1);
            }
            if(m_pRight) {
                std::cout << "r";
                m_pRight->print(depth + 1);
            }
        }

        static bool printTheNodesOrNone(const std::shared_ptr<Node<T>>& node) {
            bool found = false;
            if((node->m_value % 5) == 0) {
                if(node->m_pLeft) {
                    found = true;
                    std::cout << node->m_pLeft->getValue() << " ";
                }
                if(node->m_pRight) {
                    found = true;
                    std::cout << node->m_pRight->getValue() << " ";
                }
            }
            if(node->m_pLeft){
                found |= Node<T>::printTheNodesOrNone(node->m_pLeft);
            }
            if(node->m_pRight){
                found |= Node<T>::printTheNodesOrNone(node->m_pRight);
            }
            return found;
        }

        void insert(const T value) {
            if(value < m_value) {
                if(m_pLeft) {
                    m_pLeft->insert(value);
                } else {
                    m_pLeft = std::make_shared<Node<T>>(value);
                }
            } else {
                if(m_pRight) {
                    m_pRight->insert(value);
                } else {
                    m_pRight = std::make_shared<Node<T>>(value);
                }
            }
        }

        static void findMin(std::shared_ptr<Node<T>>& node) {
            if(!node->m_pLeft) {
                return;
            }
            node = node->m_pLeft;
            findMin(node);
        }

        static void findMax(std::shared_ptr<Node<T>>& node) {
            if(!node->m_pRight) {
                return;
            }
            node = node->m_pRight;
            findMax(node);
        }

        static bool remove(const T value, std::shared_ptr<Node<T>>& node) {
            if(value < node->getValue()) {
                if(!node->m_pLeft) {
                    return false;
                }
                return remove(value, node->m_pLeft);
            }
            if(value > node->getValue()) {
                if(!node->m_pRight) {
                    return false;
                }
                return remove(value, node->m_pRight);
            }

            // node found, remove this
            if(!node->m_pLeft && !node->m_pRight) {
                node = std::shared_ptr<Node<T>>(nullptr);
                return true;
            }

            if(!node->m_pLeft) {
                node = node->m_pRight;
                return true;
            }

            if(!node->m_pRight) {
                node = node->m_pLeft;
                return true;
            }

            std::shared_ptr<Node<T>> nextBiggest = node->m_pRight;
            Node<T>::findMin(nextBiggest);
            Node<T>::remove(nextBiggest->getValue(), node);
            nextBiggest->m_pLeft = node->m_pLeft;
            nextBiggest->m_pRight = node->m_pRight;
            node = nextBiggest;
            return true;
        }

        static bool find(const T value, std::shared_ptr<Node<T>>& node) {
            if(value == node->m_value) {
                return true;
            }
            if(value < node->m_value) {
                if(!node->m_pLeft) {
                    node = nullptr;
                    return false;
                }
                node = node->m_pLeft;
                return Node<T>::find(value, node);
            }

            if(!node->m_pRight) {
                node = nullptr;
                return false;
            }
            node = node->m_pRight;
            return Node<T>::find(value, node);
        }

        const T m_value;
        std::shared_ptr<Node<T>> m_pLeft;
        std::shared_ptr<Node<T>> m_pRight;
    };

    template <typename T>
    class Tree {
    public:
        Tree()
        : m_pRoot(nullptr) {
            
        }
        void print() const {
            if(m_pRoot) {
                m_pRoot->print();
            }
        }

        void printTheNodesOrNone() const {
            if(!m_pRoot || !Node<T>::printTheNodesOrNone(m_pRoot)) {
                std::cout << "None";
            }
            std::cout << std::endl;
        }

        const std::shared_ptr<Node<T>> find(const T value) const {
            if(!m_pRoot) {
                return nullptr;
            }

            auto ret = m_pRoot;
            Node<T>::find(value, ret);
            return ret;
        }

        const std::shared_ptr<Node<T>> findMin() const {
            if(!m_pRoot) {
                return nullptr;
            }

            auto newPtr = m_pRoot;
            Node<T>::findMin(newPtr);
            return newPtr;
        }

        const std::shared_ptr<Node<T>> findMax() const {
            if(!m_pRoot) {
                return nullptr;
            }

            auto newPtr = m_pRoot;
            Node<T>::findMax(newPtr);
            return newPtr;
        }

        void insert(const T value) {
            if(m_pRoot) {
                m_pRoot->insert(value);
            } else {
                m_pRoot = std::make_shared<Node<T>>(value);
            }
        }

        bool remove(const T value) {
            if(!m_pRoot) {
                return false;
            }
            return Node<T>::remove(value, m_pRoot);
        }
    private:
        std::shared_ptr<Node<T>> m_pRoot;
    };
}

