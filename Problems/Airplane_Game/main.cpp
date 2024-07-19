#include <iostream>
using namespace std;

// Up-Straight, Up-Left, Up-Right
const int di[3] = {-1, -1, -1};
const int dj[3] = {0, -1, 1};

const int ROWS = 12;
const int COLS = 5;

const int SCREEN_W = 5;
const int SCREEN_H = 5;

const int EMPTY = 0;
const int COINS = 1;
const int ENEMY = 2;

int solve(const int (&mat)[ROWS][COLS], const int N, const int M);
void backtrack(int &ans, const int (&mat)[ROWS][COLS], const int N, const int M, int i, int j, int coins = 0, int bomb = 1, int effect = 0);

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

        cout << "#" << tc + 1 << " " << solve(mat, N, M) << endl;
    }
    return 0;
}

int solve(const int (&mat)[ROWS][COLS], const int N, const int M) {
    int ans = 0;
    int start_i = N;
    int start_j = M / 2;

    backtrack(ans, mat, N, M, start_i, start_j);

    return ans;
}

void backtrack(int &ans, const int (&mat)[ROWS][COLS], const int N, const int M, int i, int j, int coins, int bomb, int effect) {
    if (i == 0) {
        if (coins > ans)
            ans = coins;
        return;
    }

    for (int d = 0; d < 3; d++) {
        int ni = i + di[d];
        int nj = j + dj[d];
        if (nj < 0 || nj > M - 1)
            continue;

        if (mat[ni][nj] != ENEMY) {
            if (bomb == 0)
                backtrack(ans, mat, N, M, ni, nj, coins + mat[ni][nj], bomb, effect - 1);
            else
                backtrack(ans, mat, N, M, ni, nj, coins + mat[ni][nj], bomb, effect);
        } else {
            if (bomb == 0) {
                if (effect > 0)
                    backtrack(ans, mat, N, M, ni, nj, coins, bomb, effect - 1);
            } else
                backtrack(ans, mat, N, M, ni, nj, coins, 0, 5);
        }
    }
}
