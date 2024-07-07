#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int SIZE = 5;

class Graph {
private:
    int data[SIZE][SIZE];
    int size;

public:
    Graph(int size);

    int& operator()(int i, int j);
    int operator()(int i, int j) const;
};

int main(int argc, char* argv[]) {
    const char* input = argv[1];
    FILE* fp = freopen(input, "r", stdin);
    unsigned int T; cin >> T;

    for (size_t tc = 0; tc < T; tc++) {
        unsigned int N; cin >> N;
        Graph g(N);

        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < N; j++)
                cin >> g(i, j);

        cout << "" << endl;
    }

    return 0;
}

Graph::Graph(int size) {
    this->size = size;
    for (size_t i = 0; i < this->size; i++)
        for (size_t j = 0; j < this->size; j++)
            data[i][j] = 0;
}

int& Graph::operator()(int i, int j) {
    return data[i][j];
}

int Graph::operator()(int i, int j) const {
    return data[i][j];
}
