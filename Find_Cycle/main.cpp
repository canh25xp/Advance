#include "stack.hpp"
#include <iostream>
using namespace std;

const int SIZE = 100;
const int STACK_SIZE = 1000;

class Graph {
private:
    int adj[SIZE][SIZE]; // adjacent matrix
    int nodes, edges;

public:
    Graph(int nodes, int edges);

    void add_edge(int u, int v);
    bool DFS(int (&vst)[SIZE], int vertex, int target, int step = 0);
    bool DFS(int vertex, int target);
    bool hasPath(int start, int target);
    bool hasCycle();
};

int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    const char *log = "log.txt";
    freopen(input, "r", stdin);
    freopen(log, "w", stderr);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int nodes, edges;
        cin >> nodes >> edges;

        Graph g(nodes, edges);

        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
            g.add_edge(u - 1, v - 1);
        }

        bool hasCycles = g.hasCycle();
        cout << "Case #" << tc + 1 << "\n"
             << hasCycles << endl;
    }

    return 0;
}

Graph::Graph(int nodes, int edges) {
    this->nodes = nodes;
    this->edges = edges;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            adj[i][j] = 0;
        }
    }
}

void Graph::add_edge(int u, int v) {
    adj[u][v] = 1; // Set edge from u to v
    // adj[v][u] = 1; // Set edge from v to u (if undirected graph)
}

bool Graph::DFS(int (&vst)[SIZE], int vertex, int target, int step) {
    if (vertex == target && step > 0)
        return true;

    if (step > 0)
        vst[vertex] = 1;

    for (int i = 0; i < nodes; i++)
        if (adj[vertex][i] == 1 && !vst[i])
            if (DFS(vst, i, target, step + 1))
                return true;

    return false;
}

bool Graph::DFS(int vertex, int target) {
    int vst[SIZE] = {};
    Stack<int, STACK_SIZE> s;

    s.push(vertex);
    while (!s.isEmpty()) {
        int v = s.pop();
        vst[v] = 1;
        for (int i = 0; i < nodes; i++) {
            if (adj[vertex][i] == 1) {
                if (!vst[i])
                    s.push(i);
                else if (i == target)
                    return true;
            }
        }
    }

    return false;
}

bool Graph::hasCycle() {
    for (int i = 0; i < nodes; i++)
        if(hasPath(i, i))
            return true;

    return false;

    // for (int i = 0; i < nodes; i++)
    //     if (DFS(i, i))
    //         return true;

    return false;
}

bool Graph::hasPath(int start, int target) {
    int vst[SIZE] = {};
    return DFS(vst, start, target);
}