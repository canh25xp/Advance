#include <iostream>
using namespace std;

const int N = 10;

int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int nodes, edges;
        cin >> nodes >> edges;

        int adj[N][N] = {};
        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
        }
    }

    return 0;
}