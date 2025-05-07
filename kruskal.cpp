#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unionSets(int a, int b) {
    parent[find(a)] = find(b);
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<Edge> edges(e);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), compare);

    int totalCost = 0;
    cout << "Edges in MST:\n";
    for (Edge edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
            totalCost += edge.weight;
            unionSets(edge.u, edge.v);
        }
    }

    cout << "Total cost of MST: " << totalCost << "\n";
    return 0;
}
