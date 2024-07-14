#pragma once
#include "queue.hpp"
#include <iostream>

template <typename T = int, int MAX = 10000>
class Graph {
private:
    int size;
    int adj[MAX][MAX]; // adjacent matrix

    bool DFS(int vertex, int target, int (&vst)[MAX]);

public:
    Graph(int n);
    T &operator()(int i, int j);
    T operator()(int i, int j) const;

    void add_edge(int u, int v);
    bool DFS(int start, int target);
    bool BFS(int start, int target);
};

template <typename T, int MAX>
Graph<T, MAX>::Graph(int n) {
    size = n;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            adj[i][j] = 0;
}

template <typename T, int MAX>
T &Graph<T, MAX>::operator()(int i, int j) {
    return adj[i][j];
}

template <typename T, int MAX>
T Graph<T, MAX>::operator()(int i, int j) const {
    return adj[i][j];
}

template <typename T, int MAX>
void Graph<T, MAX>::add_edge(int u, int v) {
    adj[u][v] = 1; // Set edge from u to v
    // adj[v][u] = 1; // Set edge from v to u (if undirected graph)
}

template <typename T, int MAX>
bool Graph<T, MAX>::DFS(int vertex, int target, int (&visited)[MAX]) {
    if (vertex == target)
        return true;

    visited[vertex] = 1;

    for (int i = 0; i < size; i++)
        if (adj[vertex][i] && !visited[i])
            if (DFS(i, target, visited))
                return true;

    return false;
}

template <typename T, int MAX>
bool Graph<T, MAX>::DFS(int start, int target) {
    int visited[MAX] = {};
    return DFS(start, target, visited);
}

template <typename T, int MAX>
bool Graph<T, MAX>::BFS(int start, int target) {
    int visited[MAX] = {};
    Queue<int, 100> q;

    q.enQueue(start);

    while (!q.isEmpty()) {
        int t = q.deQueue();
        if (t == 99)
            return true;
        visited[t] = 1;
        for (int i = 0; i < size; i++) {
            if (adj[t][i] && !visited[i]) {
                visited[i] = 1;
                q.enQueue(i);
            }
        }
    }

    return false;
}
