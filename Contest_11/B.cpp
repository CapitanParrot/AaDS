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

void setup(int *nodes, int *mass, int node_count) {
    for (int i = 1; i < node_count + 1; ++i) {
        nodes[i] = i;
        mass[i] = 1;
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int node_count, edge_count;
    cin >> node_count >> edge_count;

    Edge **edges = new Edge *[edge_count];
    Edge **minimum_spanning_tree = new Edge *[edge_count];
    int spanning_tree_counter = 0;

    int *nodes = new int[node_count + 1];
    int *mass = new int[node_count + 1];
    setup(nodes, mass, node_count);
    for (int i = 0; i < edge_count; ++i) {
        int node_one, node_two, mass;
        cin >> node_one >> node_two >> mass;
        edges[i] = new Edge(node_one, node_two, mass);
    }
    qsortRecursive(edges, edge_count);
    int first_min = 0;
    for (int i = 0; i < edge_count; ++i) {
        if (checkMinimalTree(nodes, node_count)) {
            break;
        }
        if (find(nodes, edges[i]->node_one) != find(nodes, edges[i]->node_two)) {
            unite(nodes, mass, edges[i]->node_one, edges[i]->node_two);
            first_min += edges[i]->weight;
            minimum_spanning_tree[spanning_tree_counter] = edges[i];
            spanning_tree_counter++;
        }
    }
    int second_min = 2000 * 300 + 1;
    for (int idx = 0; idx < spanning_tree_counter; ++idx) {
        setup(nodes, mass, node_count);
        int min = 0;
        for (int j = 0; j < edge_count; ++j) {
            if (checkMinimalTree(nodes, node_count)) {
                break;
            }
            if ((find(nodes, edges[j]->node_one) != find(nodes, edges[j]->node_two)) &&
                edges[j] != minimum_spanning_tree[idx]) {
                unite(nodes, mass, edges[j]->node_one, edges[j]->node_two);
                min += edges[j]->weight;
                minimum_spanning_tree[spanning_tree_counter] = edges[j];
            }
        }
        if (checkMinimalTree(nodes, node_count)) {
            if (min < second_min) {
                second_min = min;
            }
        }
    }
    cout << first_min << " " << second_min;

    for (int i = 0; i < edge_count; ++i) {
        delete edges[i];
    }
    delete[] edges;
    delete[] mass;
    delete[] nodes;
    delete[] minimum_spanning_tree;
}
