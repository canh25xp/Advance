#include <iostream>

const int N = 100;
const int M = 100;

int solve(int (&mat)[N][M], int n, int m);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;

        int mat[N][M] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        cout << "Case #" << t + 1 << endl;
        cout << solve(mat, n, m) << endl;
    }

    return 0;
}