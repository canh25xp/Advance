#include "point.hpp"
#include <iostream>
using namespace std;

const int MAX_N = 5;  // Width
const int MAX_M = 12; // Length

const int SCREEN_W = 5;
const int SCREEN_H = 5;

const int EMPTY = 0;
const int COINS = 1;
const int ENEMY = 2;

template <const int ROWS, const int COLS>
void DFS(const int (&mat)[ROWS][COLS], const int I, const int J, const Point current, int coin = 0);

template <const int ROWS, const int COLS>
void Bomb(const int (&mat)[ROWS][COLS], const int I, const int J);

template <const int ROWS, const int COLS>
void Print(const int (&mat)[ROWS][COLS], const int I, const int J);

// MAIN
int main() {
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int N = MAX_N;
        int M;
        cin >> M;
        int mat[MAX_M][MAX_N] = {};

        for (int m = 0; m < M; m++)
            for (int n = 0; n < N; n++)
                cin >> mat[m][n];

        Print<MAX_M, MAX_N>(mat, M, N);

        cout << "#" << endl;
    }
    return 0;
}
// END MAIN

template <const int ROWS, const int COLS>
void DFS(const int (&mat)[ROWS][COLS], const int L, const int W, const Point current, int coin) {
    static const Point d[3] = {Point(0, -1), Point(-1, -1), Point(1, -1)}; // Direction : up_straight, up_left, up_right.

    if (current.y == 0 && max_coin < coin)
        max_coin = coin;

    for (int i = 0; i < 3; i++) {
        Point next = current + d[i];

        if (next.x >= 0 && next.x < W && next.y >= 0) {
            if (mat[next.y][next.x] != 2) {
                DFS(mat, L, W, next, coin + mat[next.y][next.x]);
            } else if (check) {
                check = 0;
                DFS(mat, L, W, next, coin);
                check = 1;
            }
        }
    }
}

template <const int ROWS, const int COLS>
void Print(const int (&mat)[ROWS][COLS], const int I, const int J) {
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

template <const int ROWS, const int COLS>
void Bomb(const int (&mat)[ROWS][COLS], const int I, const int J) {
    for (int k = 0; k < M - SCREEN_H; k++) {
        for (int i = 0; i < SCREEN_H; i++) {
            for (int j = 0; j < SCREEN_W; j++) {
                mat[i][j] = 0;
            }
        }
    }
}
