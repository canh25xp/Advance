#include "point.hpp"
#include <iostream>
using namespace std;

const int N = 20; // Length of the bridge should be no more than 20
const int M = 5;  // Width of the bridge should always be 5

void DFS(const int (&mat)[N][M], const int n, const int m, const Point current, int coin = 0);

int max_coin, check;

// MAIN
int main() {
    freopen("input.txt", "r", stdin);

    int T; // the total number of test case
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int n; // Length of the bridge
        cin >> n;
        int m = M;

        int bridge[N][M] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> bridge[i][j];

        Point start(n, m / 2);

        max_coin = -1;
        check = 1;

        DFS(bridge, n, m, start);
        cout << "#" << tc + 1 << " " << max_coin << endl;
    }
    return 0;
}
// END MAIN

void DFS(const int (&mat)[N][M], const int n, const int m, const Point current, int coin) {
    static const Point d[3] = {Point(-1, 0), Point(-1, -1), Point(-1, 1)}; // Direction : up_straight, up_left, up_right.

    if (current.i == 0 && max_coin < coin)
        max_coin = coin;

    for (int i = 0; i < 3; i++) {
        Point next = current + d[i];

        if (next.j >= 0 && next.j < m && next.i >= 0) {
            if (mat[next.i][next.j] != 2)
                DFS(mat, n, m, next, coin + mat[next.i][next.j]);

            else if (check) {
                check = 0;
                DFS(mat, n, m, next, coin);
                check = 1;
            }
        }
    }
}
