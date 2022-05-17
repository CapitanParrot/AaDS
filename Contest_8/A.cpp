#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

class RBTreeNode {
public:
    int key = 0;
    int left = 0;
    int right = 0;
    bool color = 0;
    RBTreeNode() {
    }
};

bool checkColors(RBTreeNode *tree, int root, int father) {
    RBTreeNode root_node = tree[root];
    if (father != 0) {
        if (root_node.color && tree[father].color) {
            return false;
        }
    }
    if (root_node.left != -1) {
        if (!checkColors(tree, root_node.left, root)) {
            return false;
        }
    }

    if (tree[root].right != -1) {
        if (!checkColors(tree, root_node.right, root)) {
            return false;
        }
    }
    return true;
}
int blackHeight(RBTreeNode *tree, int root) {
    RBTreeNode root_node = tree[root];
    int left = 0, right = 0, height = 0;
    if (root != -1) {
        left = blackHeight(tree, root_node.left);
        right = blackHeight(tree, root_node.right);
        if (root_node.color) {
            height = ((left > right) ? left : right);
        } else {
            height = ((left > right) ? left : right) + 1;
        }
    } else {
        height = 1;
    }
    return height;
}

bool checkHeight(RBTreeNode *tree, int root) {
    RBTreeNode root_node = tree[root];
    if (blackHeight(tree, root_node.left) - blackHeight(tree, root_node.right) != 0) {
        return false;
    }
    if (root_node.left != -1) {
        if (!checkHeight(tree, root_node.left)) {
            return false;
        }
    }
    if (tree[root].right != -1) {
        if (!checkHeight(tree, root_node.right)) {
            return false;
        }
    }
    return true;
}
int maxTree(RBTreeNode *tree, int root) {
    RBTreeNode root_node = tree[root];
    if (root == -1) {
        return -2000000000;
    }
    int left_max = maxTree(tree, root_node.left);
    int right_max = maxTree(tree, root_node.right);

    if (root_node.key > left_max && root_node.key > right_max) {
        return root_node.key;
    } else if (left_max > root_node.key && left_max > right_max) {
        return left_max;
    } else {
        return right_max;
    }
}
int minTree(RBTreeNode *tree, int root) {
    RBTreeNode root_node = tree[root];
    if (root == -1) {
        return 2000000000;
    }
    int left_min = minTree(tree, root_node.left);
    int right_min = minTree(tree, root_node.right);

    if (root_node.key < left_min && root_node.key < right_min) {
        return root_node.key;
    } else if (left_min < root_node.key && left_min < right_min) {
        return left_min;
    } else {
        return right_min;
    }
}
bool checkSearch(RBTreeNode *tree, int root) {
    RBTreeNode root_node = tree[root];
    if (root == -1) {
        return true;
    }
    if (maxTree(tree, root_node.left) >= root_node.key ||
        minTree(tree, root_node.right) <= root_node.key) {
        return false;
    }
    if (!checkSearch(tree, root_node.left)) {
        return false;
    }
    if (!checkSearch(tree, root_node.right)) {
        return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int size, root;

    cin >> size;
    if (size == 0) {
        cout << "YES";
        return 0;
    }
    cin >> root;

    RBTreeNode *tree = new RBTreeNode[size + 1];

    for (int counter = 0; counter < size; ++counter) {
        int number, key;
        string left, right;
        char color;
        cin >> number >> key >> left >> right >> color;
        tree[number].key = key;

        if (left == "null") {
            tree[number].left = -1;
        } else {
            tree[number].left = stoi(left);
        }

        if (right == "null") {
            tree[number].right = -1;
        } else {
            tree[number].right = stoi(right);
        }
        if (color == 'R') {
            tree[number].color = true;
        } else {
            tree[number].color = false;
        }
    }
    if (tree[root].color || !checkSearch(tree, root) || !checkColors(tree, root, 0) ||
        !checkHeight(tree, root)) {
        cout << "NO";
        delete[] tree;
        return 0;
    }
    cout << "YES";
    delete[] tree;
}
