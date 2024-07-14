#include <iostream>
using namespace std;

const int M_MAX = 3;

int solve(const int (&adj)[M_MAX][M_MAX], const int &M);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int M;
        cin >> M;

        int adj[M_MAX][M_MAX] = {};

        for (int m = 0; m < M; m++) {
            int i, ui, ci;
            cin >> i >> ui >> ci;
            for (int c = 0; c < ci; c++) {
                int j;
                cin >> j;
                adj[i][j] += ui;
                adj[j][i] = adj[i][j];
            }
        }
        cout << solve(adj, M) << endl;
    }

    return 0;
}

int solve(const int (&adj)[M_MAX][M_MAX], const int &M) {
    return 0;
}
