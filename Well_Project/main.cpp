#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define INT_MAX 2147483647

const int SIZE = 100;

class Graph {
private:
    int adj[SIZE][SIZE];
    int size;

    int minKey(int key[], bool mstSet[]);

public:
    Graph(int size);

    int &operator()(int i, int j);
    int operator()(int i, int j) const;

    int primMST();
};

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    const char *input = argv[1];
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int N;
        cin >> N;

        Graph g(N);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> g(i, j);

        int mst = g.primMST();

        cout << "Case #" << tc + 1 << "\n"
             << mst << endl;
    }

    return 0;
}

int &Graph::operator()(int i, int j) {
    return adj[i][j];
}

int Graph::operator()(int i, int j) const {
    return adj[i][j];
}

Graph::Graph(int size) {
    this->size = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adj[i][j] = 0;
        }
    }
}

int Graph::primMST() {
    int parent[SIZE] = {};

    int key[SIZE] = {};

    bool mstSet[SIZE] = {};

    for (int i = 0; i < size; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;

    parent[0] = -1;

    for (int count = 0; count < size - 1; count++) {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < size; v++) {
            if (u != v && mstSet[v] == false && adj[u][v] < key[v])
                parent[v] = u, key[v] = adj[u][v];
        }
    }

    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += key[i];

    return sum;
}

int Graph::minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < size; i++)
        if (!mstSet[i] && key[i] < min)
            min = key[i], min_index = i;

    return min_index;
}
