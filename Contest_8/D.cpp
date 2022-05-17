#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;


template <class ValueType>
class RBTreeNode {
    ValueType value = 0;
    RBTreeNode* left = nullptr;
    RBTreeNode* right = nullptr;
    bool color = true;
    RBTreeNode() {
    }
    RBTreeNode(ValueType v) {
        value = v;
    }
    RBTreeNode(const RBTreeNode& other) {
        value = other.value;
        left = other.left;
        right = other.right;
        color = other.color;
    }
};

template <class ValueType>
class RBTree {
public:
    RBTree();

    RBTree(const RBTree& other) {
        root = new RBTreeNode(other.root);

    }

    RBTree& operator=(const RBTree& other);

    ~RBTree();

    size_t size() {
        return size;
    }

    bool empty() {
        if (root == nullptr) {
            return true;
        }
        return false;
    }

    void insert(const ValueType& value);

    void erase(const ValueType& value);

    ValueType* lower_bound(const ValueType& value) const;  // NOLINT

    ValueType* find(const ValueType& value) const;

    ValueType* traversal() const;
private:
    size_t size = 0;
    RBTreeNode* root= nullptr;

    RBTreeNode* copyNode(RBTreeNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        

        RBTreeNode* node_copy = new RBTreeNode(node);
        node_copy->left = copyNode(node_copy->left);
    }

};
int main()
{
    std::cout << "Hello World!\n";
}
