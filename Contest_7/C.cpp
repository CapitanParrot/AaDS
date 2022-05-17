#include <iostream>
using std::cin;
using std::cout;
class TreeElem {
public:
    int data;
    TreeElem *left;
    TreeElem *right;
    explicit TreeElem(int val) {
        left = nullptr;
        right = nullptr;
        data = val;
    }
};

class BinaryTree {
private:
    TreeElem *root_;
    int size_;
    void printTree(TreeElem *curr) {
        if (curr) {
            printTree(curr->left);
            cout << curr->data << '\n';
            printTree(curr->right);
        }
    }
    
    void deleteTree(TreeElem *curr) {
        if (curr) {
            deleteTree(curr->left);
            deleteTree(curr->right);
            delete curr;
        }
    }
    int height(TreeElem *elem) {
        int l = 0, r = 0, h = 0;
        if (elem != nullptr) {
            l = height(elem->left);
            r = height(elem->right);
            h = ((l > r) ? l : r) + 1;
        }
        return h;
    }

public:
    explicit BinaryTree(int key) {
        root_ = new TreeElem(key);
        size_ = 1;
    }
    ~BinaryTree() {
        deleteTree(root_);
    }
    void print() {
        printTree(root_);
    }
    void insert(int key) {
        TreeElem *curr = root_;
        while (curr && curr->data != key) {
            if (curr->data > key && curr->left == nullptr) {
                curr->left = new TreeElem(key);
                ++size_;
                return;
            }
            if (curr->data < key && curr->right == nullptr) {
                curr->right = new TreeElem(key);
                ++size_;
                return;
            }
            if (curr->data > key) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }
    void printHeight() {
        cout << height(root_);
    }
    int secondMax() {
        TreeElem *temp = root_;

        if (temp->right) {
            while (temp->right->right) {
                temp = temp->right;
            }
            if (temp->right->left != nullptr) {
                temp = temp->right->left;
                while (temp->right != nullptr) {
                    temp = temp->right;
                }
            }
            return temp->data;
        } else if (!temp->left->right) {
            return temp->left->data;
        } else {
            temp = temp->left;
            while (temp->right) {
                temp = temp->right;
            }
            return temp->data;
        }
    }
};
int main() {
    int elem;
    cin >> elem;
    if (elem == 0) {
        return 0;
    }
    BinaryTree tree = BinaryTree(elem);
    while (true) {
        int temp;
        cin >> temp;
        if (temp == 0) {
            break;
        }
        tree.insert(temp);
    }
    tree.print();
}
