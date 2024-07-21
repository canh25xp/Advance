#include "point.hpp"
#include "queue.hpp"
#include <iostream>

#define INF INT_MAX

const int N = 100;
const int M = 100;
const int K = 11;
const int MAX_QUEUE = 1000;

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};

int solve(int (&mat)[N][M], int n, int m);
void BFS(int (&mat)[N][M], int n, int m, Point (&target)[K], int count, int index, int (&dis)[K][K]);

void backtracking(int &res, int totalDirty, int used[], int distancE[K][K], int currDir, int cnt, int sum);

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

int solve(int (&mat)[N][M], int n, int m) {
    int ans = INF;
    int k = 1;
    Point target[K];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 3)
                target[0].i = i, target[0].j = j;
            else if (mat[i][j] == 1) {
                target[k].i = i, target[k].j = j;
                k++;
            }
        }
    }

    int dis[K][K] = {};
    for (int i = 0; i < k; i++)
        BFS(mat, n, m, target, k, i, dis);

    int used[K] = {};
    backtracking(ans, k - 1, used, dis, 0, 0, 0);
    return ans;
}

void backtracking(int &res, int totalDirty, int used[], int distancE[K][K], int currDir, int cnt, int sum) {
    if (sum > res)
        return;
    if (cnt == totalDirty) {
        if (sum < res)
            res = sum;
        return;
    }
    for (int i = 1; i <= totalDirty; i++) {
        if (used[i] == 0 && distancE[currDir][i] > 0) {
            used[i] = 1;
            backtracking(res, totalDirty, used, distancE, i, cnt + 1, sum + distancE[currDir][i]);
            used[i] = 0;
        }
    }
}

void BFS(int (&mat)[N][M], int n, int m, Point (&target)[K], int count, int index, int (&dis)[K][K]) {
    int visited[N][M] = {};
    Queue<Point, MAX_QUEUE> q;
    q.enQueue(target[index]);
    visited[target[index].i][target[index].j] = 1;

    while (!q.isEmpty()) {
        Point curr = q.deQueue();
        for (int d = 0; d < 4; d++) {
            Point next(curr.i + di[d], curr.j + dj[d]);
            if (next.isValid(n, m) && !visited[next.i][next.j] && mat[next.i][next.j] != 2) {
                visited[next.i][next.j] = visited[curr.i][curr.j] + 1;
                q.enQueue(next);
            }
        }
    }

    for (int i = 0; i < count; i++) {
        if (visited[target[i].i][target[i].j]) {
            dis[index][i] = visited[target[i].i][target[i].j] - 1;
            dis[i][index] = visited[target[i].i][target[i].j] - 1;
        } else {
            dis[index][i] = -1;
            dis[i][index] = -1;
        }
    }
}