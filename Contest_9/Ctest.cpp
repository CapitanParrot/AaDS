#include <iostream>
#include <cmath>
using std::abs;
using std::cin;
using std::cout;

struct Node {
public:
    int key;
    Node* left;
    Node* right;
    Node* parent;

    explicit Node(int value) {
        key = value;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class SplayTree {
public:
    SplayTree() {
        root_ = nullptr;
    }

    ~SplayTree() {
        deleteTree(root_);
    }

    void insert(int val) {
        if (root_ == nullptr) {
            root_ = new Node(val);
            return;
        }
        Node* curr = this->root_;
        while (curr != nullptr) {
            if (val < curr->key) {
                if (curr->left == nullptr) {
                    Node* new_node = new Node(val);
                    curr->left = new_node;
                    new_node->parent = curr;
                    // splay(new_node);
                    // this->root = new_node;
                    return;
                }
                else {
                    curr = curr->left;
                }
            }
            else if (val > curr->key) {
                if (curr->right == nullptr) {
                    Node* new_node = new Node(val);
                    curr->right = new_node;
                    new_node->parent = curr;
                    // splay(new_node);
                    // this->root = new_node;
                    return;
                }
                else {
                    curr = curr->right;
                }
            }
            else {
                // splay(curr);
                return;
            }
        }
    }

    Node* find(int val) {
        Node* result = nullptr;
        Node* current = this->root_;
        Node* previous = nullptr;
        while (current != nullptr) {
            previous = current;
            if (val < current->key) {
                current = current->left;
            }
            else if (val > current->key) {
                current = current->right;
            }
            else {
                result = current;
                break;
            }
        }
        return result;
    }

    int splay(Node* val) {
        int counter = 0;
        while (val->parent != nullptr) {
            Node* parent_node = val->parent;
            Node* grandparent_node = parent_node->parent;
            if (grandparent_node == nullptr) {
                zig(val);
                ++counter;
            }
            else if (grandparent_node->left == parent_node && parent_node->left == val) {
                zigZig(val);
                ++counter;
                ++counter;
            }
            else if (grandparent_node->right == parent_node && parent_node->right == val) {
                zigZig(val);
                ++counter;
                ++counter;
            }
            else {
                zigZag(val);
                ++counter;
            }
        }
        root_ = val;
        return counter;
    }

    int getHeight() {
        return heightTree(root_);
    }
    void print() {
        printTree(root_);
    }

private:
    Node* root_;
    void printTree(Node* curr) {
        if (curr) {
            std::cout << curr->key << '\n';
            printTree(curr->left);
            printTree(curr->right);
        }
    }
    void deleteTree(Node* curr) {
        if (curr) {
            deleteTree(curr->left);
            deleteTree(curr->right);
            delete curr;
        }
    }
    int heightTree(Node* elem) {
        if (elem == nullptr) {
            return -1;
        }
        int left = 0, right = 0, height = 0;
        left = heightTree(elem->left);
        right = heightTree(elem->right);
        height = ((left > right) ? left : right) + 1;
        return height;
    }
    void zig(Node* val) {
        Node* parent_node = val->parent;
        if (parent_node->left == val) {
            // Zig
            Node* a = val->right;

            val->parent = nullptr;
            val->right = parent_node;

            parent_node->parent = val;
            parent_node->left = a;

            if (a != nullptr) {
                a->parent = parent_node;
            }
        }
        else {
            // Zag
            Node* a = val->left;

            val->parent = nullptr;
            val->left = parent_node;

            parent_node->parent = val;
            parent_node->right = a;

            if (a != nullptr) {
                a->parent = parent_node;
            }
        }
    }
    void zigZig(Node* val) {
        Node* parent_node = val->parent;
        Node* grandparent_node = parent_node->parent;

        if (parent_node->left == val) {
            // zig-zig
            Node* a = val->right;
            Node* b = parent_node->right;

            val->parent = grandparent_node->parent;
            val->right = parent_node;

            parent_node->parent = val;
            parent_node->left = a;
            parent_node->right = grandparent_node;

            grandparent_node->parent = parent_node;
            grandparent_node->left = b;

            if (val->parent != nullptr) {
                if (val->parent->left == grandparent_node) {
                    val->parent->left = val;
                }
                else {
                    val->parent->right = val;
                }
            }
            if (a != nullptr) {
                a->parent = parent_node;
            }
            if (b != nullptr) {
                b->parent = grandparent_node;
            }
        }
        else {
            // zag-zag
            Node* a = parent_node->left;
            Node* b = val->left;

            val->parent = grandparent_node->parent;
            val->left = parent_node;

            parent_node->parent = val;
            parent_node->left = grandparent_node;
            parent_node->right = b;

            grandparent_node->parent = parent_node;
            grandparent_node->right = a;

            if (val->parent != nullptr) {
                if (val->parent->left == grandparent_node) {
                    val->parent->left = val;
                }
                else {
                    val->parent->right = val;
                }
            }

            if (a != nullptr) {
                a->parent = grandparent_node;
            }

            if (b != nullptr) {
                b->parent = parent_node;
            }
        }
    }

    void zigZag(Node* val) {
        Node* parent_node = val->parent;
        Node* grandparent_node = parent_node->parent;

        if (parent_node->right == val) {
            // zig-zag
            Node* a = val->left;
            Node* b = val->right;

            val->parent = grandparent_node->parent;
            val->left = parent_node;
            val->right = grandparent_node;

            parent_node->parent = val;
            parent_node->right = a;

            grandparent_node->parent = val;
            grandparent_node->left = b;

            if (val->parent != nullptr) {
                if (val->parent->left == grandparent_node) {
                    val->parent->left = val;
                }
                else {
                    val->parent->right = val;
                }
            }

            if (a != nullptr) {
                a->parent = parent_node;
            }

            if (b != nullptr) {
                b->parent = grandparent_node;
            }
        }
        else {
            // zag-zig
            Node* a = val->left;
            Node* b = val->right;

            val->parent = grandparent_node->parent;
            val->left = grandparent_node;
            val->right = parent_node;

            parent_node->parent = val;
            parent_node->left = b;

            grandparent_node->parent = val;
            grandparent_node->right = a;

            if (val->parent != nullptr) {
                if (val->parent->left == grandparent_node) {
                    val->parent->left = val;
                }
                else {
                    val->parent->right = val;
                }
            }

            if (a != nullptr) {
                a->parent = grandparent_node;
            }

            if (b != nullptr) {
                b->parent = parent_node;
            }
        }
    }
};


int main()
{
    int n, m;
    cin >> n >> m;
    SplayTree tree;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        tree.insert(temp);
    }
    //cout << ->key<<'\n';
    tree.find(m);

    tree.print();
    cout << tree.getHeight();
    /*void printTree(Node *curr) {
        if (curr) {
            std::cout << curr->key << '\n';
            printTree(curr->left);
            printTree(curr->right);
        }
    }
    void print() {
        printTree(root_);
    }
    */
}
