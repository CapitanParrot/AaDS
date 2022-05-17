#include <iostream>

struct BNode {
    BNode **child;
    int *key;
    unsigned size;
    bool leaf;

    explicit BNode(unsigned min_degree) {
        size = 0;
        key = new int[2 * min_degree - 1];
        child = new BNode *[2 * min_degree];
    }
};

class BTree {
public:
    explicit BTree(int t_param) {
        min_degree_ = t_param;
        root_ = new BNode(min_degree_);
        root_->leaf = true;
    }

    ~BTree() {
        clear(root_);
    }

    void insert(int value) {
        // Если элемент уже есть не вставляем.
        if (search(value) != nullptr) {
            return;
        }
        // Растем вверх если корень полон.
        if (root_->size == 2 * min_degree_ - 1) {
            BNode *new_root = new BNode(min_degree_);
            new_root->leaf = false;
            new_root->child[0] = root_;
            root_ = new_root;
            splitChild(new_root, 0);
        }

        // Спускаемся по дереву.
        BNode *curr = root_;
        while (!curr->leaf) {
            // Ищем подходящего ребенка, к которому можно пойти.
            int index = curr->size - 1;
            while (index >= 0 && value < curr->key[index]) {
                index--;
            }
            index++;

            // Разделяем ребенка если полон.
            if (curr->child[index]->size == 2 * min_degree_ - 1) {
                splitChild(curr, index);
                if (curr->key[index] < value) {
                    index++;
                }
            }
            curr = curr->child[index];
        }

        nodeInsert(curr, value);
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

private:
    BNode *search(int value) {
        BNode *node = root_;
        int exit = 1;
        while (exit) {
            unsigned i = findIndex(node, value);

            if (i < node->size && !(value < node->key[i] || node->key[i] < value)) {
                return node;
            } else if (node->leaf) {
                return nullptr;
            } else {
                node = node->child[i];
            }
        }
    }
    unsigned findIndex(BNode *node, int value) {
        unsigned idx = 0;
        while (idx < node->size && node->key[idx] < value) {
            idx++;
        }
        return idx;
    }
    size_t countNodes(BNode *node) {
        size_t counter = 0;
        if (!node->leaf) {
            for (unsigned i = 0; i <= node->size; ++i) {
                counter += countNodes(node->child[i]);
            }
        }
        return counter + 1;
    }

    int64_t countSum(BNode *node) {
        int64_t sum = 0;
        if (!node->leaf) {
            for (unsigned i = 0; i <= node->size; ++i) {
                sum += countSum(node->child[i]);
            }
        } else {
            for (unsigned i = 0; i < node->size; ++i) {
                sum += node->key[i];
            }
        }
        return sum;
    }

    void splitChild(BNode *x, int idx) {
        BNode *to_split = x->child[idx];
        BNode *new_node = new BNode(min_degree_);
        new_node->leaf = to_split->leaf;
        new_node->size = min_degree_ - 1;

        // Копируем вторую половину toSplit ключей и детей в newNode.
        for (unsigned j = 0; j < min_degree_ - 1; ++j) {
            new_node->key[j] = to_split->key[j + min_degree_];
        }
        if (!to_split->leaf) {
            for (unsigned j = 0; j < min_degree_; ++j) {
                new_node->child[j] = to_split->child[j + min_degree_];
            }
        }
        to_split->size = min_degree_ - 1;

        nodeInsert(x, to_split->key[min_degree_ - 1]);
        x->child[idx + 1] = new_node;
    }

    unsigned nodeInsert(BNode *x, int value) {
        int index;

        // Делаем место для value.
        for (index = x->size; index > 0 && value < x->key[index - 1]; --index) {
            x->key[index] = x->key[index - 1];
            x->child[index + 1] = x->child[index];
        }

        // Вставляем k.
        x->child[index + 1] = x->child[index];
        x->key[index] = value;
        x->size++;

        return index;
    }
    void clear(BNode *node) {
        if (!node->leaf) {
            for (unsigned i = 0; i <= node->size; ++i) {
                clear(node->child[i]);
            }
        }
        delete[] node->child;
        delete[] node->key;
        delete node;
    }
    unsigned min_degree_;
    BNode *root_;
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
    //tree.print();
    std::cout << '\n' << tree.size();
    std::cout << '\n' << tree.sum();
}

