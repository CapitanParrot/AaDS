#include <iostream>

struct BNode {
    BNode** child;	// Array of pointers to children.
    int* key;				// Array of keys.
    unsigned size;		// Number of keys.
    bool leaf;			// Whether the node is a leaf.

    BNode(unsigned minDegree) {
        size = 0;
        key = new int[2 * minDegree - 1];
        child = new BNode* [2 * minDegree];
    }
};

class BTree {
public:
    explicit BTree(int t_param) {
        min_degree_ = t_param;
        root_ = new BNode(min_degree_);
        root_->leaf = true;
    };

    ~BTree() {
        clear(root_);
    }

    
    void insert(int k) {

        if (search(k) != nullptr) {
            return;
        }

        // Grow upwards if the root is full.
        if (root_->size == 2 * min_degree_ - 1) {
            BNode* newRoot = new BNode(min_degree_);
            newRoot->leaf = false;
            newRoot->child[0] = root_;
            root_ = newRoot;
            splitChild(newRoot, 0);
        }

        // Work down the tree.
        BNode* curr = root_;
        while (!curr->leaf) {

            // Find the proper child to go to.
            int index = curr->size - 1;
            while (index >= 0 && k < curr->key[index]) {
                index--;
            }
            index++;

            // Split child if full.
            if (curr->child[index]->size == 2 * min_degree_ - 1) {
                splitChild(curr, index);
                if (curr->key[index] < k) {
                    index++;
                }
            }
            curr = curr->child[index];
        }

        nodeInsert(curr, k);
    }

    size_t size() {
        if (root_->size == 0) {
            return 0;
        }
        return countNodes(root_);
    }

    int64_t sum() {
        return countSum(root_);
    }

    void print() {
        if (root_ != nullptr) {
            printf("\n");
            printNode(root_, 0);
            printf("\n");
        }
    }

private:
    BNode* search(int k) {

        // Start at root.
        BNode* x = root_;

        // Work down the tree.
        while (true) {

            // Find the proper index in the current node's array.
            unsigned i = findIndex(x, k);

            // Found it!
            if (i < x->size && !(k < x->key[i] || x->key[i]< k)) {
                return x;
            }

            // Hit the bottom of the tree.
            else if (x->leaf) {
                return nullptr;
            }

            // Keep going.
            else {
                x = x->child[i];
            }
        }
    }
    unsigned findIndex(BNode* x, int k) {
        unsigned i = 0;
        while (i < x->size && x->key[i] < k) {
            i++;
        }
        return i;
    }
    
    void printNode(BNode* node, unsigned tab) {

        // Indent
        for (unsigned i = 0; i < tab; i++) {
            printf("\t");
        }

        // Print the current node.
        for (unsigned i = 0; i < node->size; i++) {
            std::cout << node->key[i];
            printf(" ");
        }
        printf("\n");

        // Print all child nodes.
        if (!node->leaf) {
            tab++;
            for (unsigned i = 0; i <= node->size; i++) {
                printNode(node->child[i], tab);
            }
        }
    }
    size_t countNodes(BNode* node) {
        size_t counter = 0;
        if (!node->leaf) {
            for (unsigned i = 0; i <= node->size; i++) {
                counter += countNodes(node->child[i]);
            }
        }
        return counter + 1;
    }

    int64_t countSum(BNode* node) {
        int64_t sum = 0;
        
        if (!node->leaf) {
            for (unsigned i = 0; i <= node->size; i++) {
                sum += countSum(node->child[i]);
            }
        }
        else {
            for (unsigned i = 0; i < node->size; i++) {
                sum += node->key[i];
            }
        }
        return sum;
    }

    void splitChild(BNode* x, int i) {

        // z is the new node and y is the node to split.
        BNode* toSplit = x->child[i];
        BNode* newNode = new BNode(min_degree_);
        newNode->leaf = toSplit->leaf;
        newNode->size = min_degree_ - 1;

        // Copy the second half of y's keys and children into z.
        for (unsigned j = 0; j < min_degree_ - 1; j++) {
            newNode->key[j] = toSplit->key[j + min_degree_];
        }
        if (!toSplit->leaf) {
            for (unsigned j = 0; j < min_degree_; j++) {
                newNode->child[j] = toSplit->child[j + min_degree_];
            }
        }
        toSplit->size = min_degree_ - 1;

        nodeInsert(x, toSplit->key[min_degree_ - 1]);
        x->child[i + 1] = newNode;
    }

    unsigned nodeInsert(BNode* x, int k) {
        int index;

        // Make room for k.
        for (index = x->size; index > 0 && k < x->key[index - 1]; index--) {
            x->key[index] = x->key[index - 1];
            x->child[index + 1] = x->child[index];
        }

        // Insert k.
        if (index != 0 &&x->key[index - 1] == k) {
            return 0;
        }
        x->child[index + 1] = x->child[index];
        x->key[index] = k;
        x->size++;

        return index;
    }
    
    /*void initializeNode(BNode* x) {
        x->size = 0;
        x->key = new int [2 * minDegree - 1];
        x->child = new BNode* [2 * minDegree];
    }*/
    void clear(BNode* node) {
        /*if (node != nullptr) {
            for (int i = 0; i <= (2 * minDegree - 1); i++) {
                if (node->child[i] != nullptr) {
                    clear(node->child[i]); 
                } else {
                    delete(node);
                    break;
                }
            }
        }*/
        if (!node->leaf) {
            for (unsigned i = 0; i <= node->size; i++) {
                clear(node->child[i]);
            }
        }
        delete []node->child;
        delete []node->key;
        delete node;
    }
    unsigned min_degree_;
    BNode* root_;
};

int main()
{
    int n;
    std::cin >> n;
    BTree tree = BTree(2);
    for (size_t i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        tree.insert(temp);
    }
    tree.print();
    std::cout << '\n' << tree.size();
    std::cout << '\n' << tree.sum();
}

