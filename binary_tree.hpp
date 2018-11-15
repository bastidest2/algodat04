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
        bool remove(const T value, std::shared_ptr<Node<T>>& node) {
            
        }
        const std::shared_ptr<Node<T>> find(const T value) const;
    private:
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
        const std::shared_ptr<Node<T>>& find(const T value) const {
            if(!m_pRoot) {
                return nullptr;
            }

            if(m_pRoot->getValue() == value) {
                return m_pRoot;
            }

            return m_pRoot->find(value);
        }
        const std::shared_ptr<Node<T>>& findMin() const;
        const std::shared_ptr<Node<T>>& findMax() const;
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
            
        }
    private:
        std::shared_ptr<Node<T>> m_pRoot;
    };
}

