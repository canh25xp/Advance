#include "point.hpp"
#include <iostream>
using namespace std;

const int ROWS = 12;
const int COLS = 5;

const int SCREEN_W = 5;
const int SCREEN_H = 5;

const int EMPTY = 0;
const int COINS = 1;
const int ENEMY = 2;

int solve(const int (&mat)[ROWS][COLS], const int N, const int M);

// MAIN
int main() {
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        const int M = COLS;
        int N;
        cin >> N;
        int mat[ROWS][COLS] = {};

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> mat[i][j];

        // Print<MAX_M, MAX_N>(mat, M, N);

        cout << "#" << tc + 1 << " " << solve(mat, N, M) << endl;
    }
    return 0;
}