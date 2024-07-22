#define _CRT_SECURE_NO_WARNINGS
#include "point.hpp"
#include "queue.hpp"
#include <iostream>

using namespace std;

const int MAX_N = 100; // should be 100
const int MAX_M = 100; // should be 100

// Direction : right down, left, up
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int N, M;
        cin >> N >> M;

        int mat[MAX_M][MAX_N];
        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                cin >> mat[m][n];
            }
        }
        Point bomb;
        cin >> bomb.i >> bomb.j;

        bomb--;

        int visited[MAX_M][MAX_N] = {};
        Queue<Point, 50000> q;
        int ans = 0;
        visited[bomb.j][bomb.i] = 1;
        q.push(bomb);
        while (!q.empty()) {
            Point curr = q.pop();
            for (int d = 0; d < 4; d++) {
                Point next(curr.i + dx[d], curr.j + dy[d]);
                if (next.valid(N, M) && !visited[next.j][next.i] && mat[next.j][next.i]) {
                    visited[next.j][next.i] = visited[curr.j][curr.i] + 1;
                    ans = visited[next.j][next.i];
                    q.push(next);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
