#pragma warning(disable : 4996)
#include <iostream>

const int N_MAX = 5; // Should be 100

int solve(const int (&adj)[N_MAX][N_MAX], const int N);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        int mat[N_MAX][N_MAX] = {};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> mat[i][j];

        int ans = solve(mat, N);
        cout << ans << endl;
    }

    return 0;
}

int solve(const int (&adj)[N_MAX][N_MAX], const int N) {
    int temp_adj[N_MAX][N_MAX] = {};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp_adj[i][j] = adj[i][j];

    int max = 0;
    int node = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int count_isolate = 0;
            int visited[N_MAX] = {};
        }
    }

    return 0;
}
