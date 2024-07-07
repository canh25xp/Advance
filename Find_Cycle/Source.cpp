#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int SIZE = 100;

template <typename T, unsigned int MAX>
class Stack
{
public:
    Stack();
    ~Stack();

    bool isFull();
    bool isEmpty();
    void push(T item);
    T pop();

private:
    T items[MAX];
    int top;
};

class Graph{
private:
    int adj[SIZE][SIZE] ; // adjacent matrix
    int nodes, edges;

public:
    Graph(int nodes, int edges);

    void add_edge(int u, int v);
    bool DFS(int (&vst)[SIZE], int vertex, int target, int step=0);
    bool DFS(int vertex, int target);
    bool hasPath(int start, int target);
    bool hasCycle();
};

int main(int argc, char* argv[]){
    ios::sync_with_stdio(false);
    const char* input = argv[1];
    freopen(input, "r", stdin);

    int T; cin >> T;

    for (int tc = 0; tc < T; tc++){
        int nodes, edges;
        cin >> nodes >> edges;

        Graph g(nodes, edges);

        for (int i = 0; i < edges; i++){
            int u,v;
            cin >> u >> v;
            g.add_edge(u-1, v-1);
        }

        bool hasCycles = g.hasCycle();
        cout << "Case #" << tc+1 << "\n" << hasCycles << endl;
    }

    return 0;
}

Graph::Graph(int nodes, int edges){
    this->nodes = nodes;
    this->edges = edges;
    for (int i = 0; i < nodes; i++){
        for (int j = 0; j < nodes; j++){
            adj[i][j] = 0;
        }
    }
}

void Graph::add_edge(int u, int v){
    adj[u][v] = 1;   // Set edge from u to v
    //adj[v][u] = 1; // Set edge from v to u (if undirected graph)
}

bool Graph::DFS(int (&vst)[SIZE], int vertex, int target, int step){
    if (vertex == target && step > 0)
        return true;

    if (step>0)
        vst[vertex] = 1;

    for (int i = 0; i < nodes; i++)
        if (adj[vertex][i] == 1 && !vst[i])
            if (DFS(vst, i, target, step+1))
                return true;

    return false;
}

bool Graph::DFS(int vertex, int target){
    int vst[SIZE] = {};
    Stack<int, SIZE> s;
    s.push(vertex);
    while (!s.isEmpty()){
        int v = s.pop();
        vst[v] = 1;
        for (int i = 0; i < nodes; i++){
            if (adj[vertex][i] == 1){
                if (!vst[i])
                    s.push(i);
                else if(i == target)
                    return true;
            }
        }
    }

    return false;
}


bool Graph::hasCycle(){
    //for (int i = 0; i < nodes; i++)
    //    if(hasPath(i, i))
    //        return true;

    //return false;

    for (int i = 0; i < nodes; i++)
        if(DFS(i, i))
            return true;

    return false;
}

bool Graph::hasPath(int start, int target){
    int vst[SIZE] = {};
    return DFS(vst, start, target);
}

template <typename T, unsigned int MAX>
Stack<T, MAX>::Stack()
{
    this->top = -1;
}

template <typename T, unsigned int MAX>
Stack<T, MAX>::~Stack()
{
}

template <typename T, unsigned int MAX>
bool Stack<T, MAX>::isEmpty(){
    if (this->top == -1)
        return true;
    else
        return false;
}

template <typename T, unsigned int MAX>
bool Stack<T, MAX>::isFull(){
    if (this->top == MAX - 1)
        return true;
    else
        return false;
}

template <typename T, unsigned int MAX>
void Stack<T, MAX>::push(T item){
    if (this->isFull())
        return;
    this->top++;
    this->items[this->top] = item;
}

template <typename T, unsigned int MAX>
T Stack<T, MAX>::pop(){
    T item;
    if (isEmpty())
        return item;
    item = this->items[this->top];
    this->top--;
    return item;
}