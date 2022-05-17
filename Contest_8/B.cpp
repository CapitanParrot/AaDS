#include <iostream>
#include <cmath>
using std::abs;
using std::cin;
using std::cout;
class TreeElem {
public:
    int data;
    int counter;
    TreeElem *left;
    TreeElem *right;
    explicit TreeElem(int val) {
        left = nullptr;
        right = nullptr;
        data = val;
        counter = 1;
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
    void printLeafs(TreeElem *curr) {
        if (curr) {
            printLeafs(curr->left);
            if (curr->left == nullptr && curr->right == nullptr) {
                cout << curr->data << '\n';
            }
            printLeafs(curr->right);
        }
    }
    void deleteTree(TreeElem *curr) {
        if (curr) {
            deleteTree(curr->left);
            deleteTree(curr->right);
            delete curr;
        }
    }
    int heightTree(TreeElem *elem) {
        int left = 0, right = 0, height = 0;
        if (elem != nullptr) {
            left = heightTree(elem->left);
            right = heightTree(elem->right);
            height = ((left > right) ? left : right) + 1;
        }
        return height;
    }
    bool balanceTravelsal(TreeElem *curr) {
        if (curr) {
            if (abs(heightTree(curr->left) - heightTree(curr->right)) > 1) {
                return false;
            }
            if (!balanceTravelsal(curr->left)) {
                return false;
            }
            if (!balanceTravelsal(curr->right)) {
                return false;
            }
        }
        return true;
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
    void printL() {
        printLeafs(root_);
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
        cout << heightTree(root_);
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
    bool checkBalance() {
        if (balanceTravelsal(root_)) {
            return true;
        }
        return false;
    }
};
int main() {
    int elem;
    cin >> elem;
    if (elem == 0) {
        cout << "Yes";
        return 0;
    }
    BinaryTree tree = BinaryTree(elem);
    int key = 1;
    while (key) {
        int number;
        cin >> number;
        if (number == 0) {
            key = 0;
            break;
        }
        tree.insert(number);
    }
    if (tree.checkBalance()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
