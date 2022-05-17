#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

class Edge {
public:
    int node_one;
    int node_two;
    int weight;
    Edge(int first, int second, int mass) {
        node_one = first;
        node_two = second;
        weight = mass;
    }
    bool operator>(Edge edge) {
        return this->weight > edge.weight;
    }
    bool operator<(Edge edge) {
        return this->weight < edge.weight;
    }
};
void insertionSort(Edge **data, int len_d) {
    Edge *key = nullptr;
    int idx = 0;
    for (int j = 1; j < len_d; ++j) {
        key = data[j];
        idx = j - 1;
        while (idx >= 0 && *data[idx] > *key) {
            data[idx + 1] = data[idx];
            idx = idx - 1;
            data[idx + 1] = key;
        }
    }
}

void qsortRecursive(Edge **mas, int size) {
    int idx = 0;
    int jdx = size - 1;

    Edge *mid = mas[size / 2];

    do {
        while (*mas[idx] < *mid) {
            idx++;
        }
        while (*mas[jdx] > *mid) {
            jdx--;
        }
        if (idx <= jdx) {
            Edge *tmp = mas[idx];
            mas[idx] = mas[jdx];
            mas[jdx] = tmp;
            idx++;
            jdx--;
        }
    } while (idx <= jdx);
    if (jdx > 0) {
        qsortRecursive(mas, jdx + 1);
    }
    if (idx < size) {
        qsortRecursive(&mas[idx], size - idx);
    }
}

void unite(int *nodes, int *mass, int first, int second) {
    int senior_first = nodes[first];
    while (senior_first != nodes[senior_first]) {
        senior_first = nodes[senior_first];
    }

    int senior_second = nodes[second];
    while (senior_second != nodes[senior_second]) {
        senior_second = nodes[senior_second];
    }
    if (senior_first == senior_second) {
        return;
    }
    if (mass[senior_first] > mass[senior_second]) {
        nodes[senior_second] = senior_first;
        mass[senior_first] += mass[senior_second];
    } else {
        nodes[senior_first] = senior_second;
        mass[senior_second] += mass[senior_first];
    }
}

int find(int *nodes, int key) {
    if (nodes[key] == key) {
        return key;
    } else {
        return nodes[key] = find(nodes, nodes[key]);
    }
}

bool checkMinimalTree(int *nodes, int number) {
    int senior = find(nodes, 1);
    for (int i = 1; i < number + 1; ++i) {
        if (senior != find(nodes, i)) {
            return false;
        }
    }
    return true;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int node_count, edge_count;
    cin >> node_count >> edge_count;

    Edge **edges = new Edge *[edge_count];

    int *nodes = new int[node_count + 1];
    int *mass = new int[node_count + 1];
    for (int i = 1; i < node_count + 1; ++i) {
        nodes[i] = i;
        mass[i] = 1;
    }
    for (int i = 0; i < edge_count; ++i) {
        int node_one, node_two, mass;
        cin >> node_one >> node_two >> mass;
        edges[i] = new Edge(node_one, node_two, mass);
    }
    qsortRecursive(edges, edge_count);
    int final_weight = 0;
    for (int i = 0; i < edge_count; ++i) {
        if (checkMinimalTree(nodes, node_count)) {
            break;
        }
        if (find(nodes, edges[i]->node_one) != find(nodes, edges[i]->node_two)) {
            unite(nodes, mass, edges[i]->node_one, edges[i]->node_two);
            final_weight += edges[i]->weight;
        }
    }
    cout << final_weight;

    for (int i = 0; i < edge_count; ++i) {
        delete edges[i];
    }
    delete[] edges;
    delete[] mass;
    delete[] nodes;
}
