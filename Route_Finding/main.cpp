#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int T = 10;
const int MAX_NODES = 100;

class Graph {
private:
    int adj[MAX_NODES][MAX_NODES]; // adjacent matrix
    int size;

public:
    Graph(int n);

    void add_edge(int u, int v);
    bool DFS(int vertex, int vst[], int target);
    bool hasPath(int start, int target);
};

int main(int argc, char *argv[]) {
    const char *input = argv[1];
    freopen(input, "r", stdin);

    for (int t = 0; t < T; t++) {
        int ti;
        cin >> ti;
        int N;
        cin >> N;

        Graph g(MAX_NODES);

        for (int i = 0; i < N; i++) {
            int u, v;
            cin >> u >> v;
            g.add_edge(u, v);
        }

        bool found = g.hasPath(0, 99);

        cout << "#" << t + 1 << " " << found << endl;
    }

    return 0;
}

Graph::Graph(int n) {
    size = n;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adj[i][j] = 0;
        }
    }
}

void Graph::add_edge(int u, int v) {
    adj[u][v] = 1; // Set edge from u to v
    // adj[v][u] = 1; // Set edge from v to u (if undirected graph)
}

bool Graph::DFS(int vertex, int vst[], int target) {
    vst[vertex] = 1;

    // cout << "(" << u << "," << v << ")" << endl;

    if (vertex == target)
        return true;

    for (int i = 0; i < size; i++)
        if (adj[vertex][i] == 1 && !vst[i])
            if (DFS(i, vst, target))
                return true;

    return false;
}

bool Graph::hasPath(int start, int target) {
    int vst[MAX_NODES] = {};
    return DFS(start, vst, target);
}