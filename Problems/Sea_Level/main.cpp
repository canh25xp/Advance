#include <iostream>

const int N = 100;
const int M = 100;

int solve(int (&mat)[N][M], int n, int m);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int n, m;
    int t = 0;

    while (true) {
        cin >> n >> m;
        if (!n || !m)
            break;

        int mat[N][M] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        cout << "Case #" << ++t << " " << endl;
    }

    return 0;
}

int solve(int (&mat)[N][M], int n, int m) {
    return 0;
}
