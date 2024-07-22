#include "point.hpp"
#include "queue.hpp"
#include <iostream>

const int N = 5;
const int Q = 10000;
const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};

using namespace std;

int solve(int (&mat)[N][N], int n);

void backtracking(int (&mat)[N][N], int n, int (&visited)[N][N], Point bruh, int diff, int &ans);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        int mat[N][N] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];

        cout << "#" << t + 1 << " " << solve(mat, n) << endl;
    }

    return 0;
}

int solve(int (&mat)[N][N], int n) {
    int visited[N][N] = {};
    int ans = INT_MAX;
    visited[0][0] = 1;

    backtracking(mat, n, visited, Point(0, 0), 0, ans);

    return ans;
}

void backtracking(int (&mat)[N][N], int n, int (&visited)[N][N], Point bruh, int diff, int &ans) {
    if (bruh == Point(N - 1, N - 1)) {
        ans = min(diff, ans);
        return;
    }

    for (int d = 0; d < 4; d++) {
        Point next(bruh.i + di[d], bruh.j + dj[d]);
        if (next.isValid(n) && !visited[next.i][next.j]) {
            int heightDiff = abs(mat[next.i][next.j] - mat[bruh.i][bruh.j]);
            int nextDiff = max(diff, heightDiff);
            if (nextDiff <= INT_MAX) {
                visited[next.i][next.j] = 1;
                backtracking(mat, n, visited, next, nextDiff, ans);
                visited[next.i][next.j] = 0;
            }
        }
    }
}
