#define _CRT_SECURE_NO_WARNINGS
#include "point.hpp"
#include "queue.hpp"
#include <iostream>

using namespace std;

const int MAX_N = 100; // should be 100
const int MAX_M = 100; // should be 100

// Direction : right down, left, up
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int N, M;
        cin >> M >> N;

        int mat[MAX_M][MAX_N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> mat[i][j];

        Point bomb;
        cin >> bomb.j >> bomb.i;
        bomb--;

        int visited[MAX_N][MAX_M] = {};
        Queue<Point, 50000> q;
        int ans = 0;
        visited[bomb.i][bomb.j] = 1;
        q.push(bomb);
        while (!q.empty()) {
            Point curr = q.pop();
            for (int d = 0; d < 4; d++) {
                Point next(curr.i + di[d], curr.j + dj[d]);
                if (next.valid(N, M) && !visited[next.i][next.j] && mat[next.i][next.j]) {
                    visited[next.i][next.j] = visited[curr.i][curr.j] + 1;
                    ans = visited[next.i][next.j];
                    q.push(next);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
