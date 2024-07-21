#define _CRT_SECURE_NO_WARNINGS
#include "point.hpp"
#include "queue.hpp"
#include <iostream>

#define INT_MAX 2147483647
#define INF INT_MAX

const int N = 100;
const int M = 100;
const int K = 10 + 1; // count the knight as target too.

const int di[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
const int dj[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

class Solution {
public:
    Solution(int (&chessboard)[N][M], int n, int m);

    int Solve();

private:
    int ans;
    int n, m;
    int (&chessboard)[N][M];

    Point target[K];
    int count; // Total number of targets in the board (the knight is counted too)

    int distance[K][K] = {}; // TODO: initialize somewhere else
    int visitedUV[K] = {};   // TODO: initialize somewhere else

    int BFS(int target_index);
    void BackTrack(int u, int step, int ith);
};

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        int chessboard[N][M] = {};

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> chessboard[i][j];

        Solution s(chessboard, n, m);

        cout << "Case #" << t + 1 << "\n"
             << s.Solve() << endl;
    }

    return 0;
}

Solution::Solution(int (&chessboard)[N][M], int n, int m) : chessboard(chessboard), n(n), m(m), ans(0) {
    for (size_t i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            distance[i][j] = 0;
        }
        visitedUV[i] = 0;
    }
}

int Solution::Solve() {
    ans = INF;
    count = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (chessboard[i][j] == 3)
                target[0] = Point(i, j);

            else if (chessboard[i][j] == 1) {
                target[count] = Point(i, j);
                count++;
            }
        }
    }

    for (int i = 0; i < count; i++)
        BFS(i);

    BackTrack(0, 0, 1);

    return ans;
}

int Solution::BFS(int index) {
    int visited[N][M] = {};
    Queue<Point> q;
    q.enQueue(target[index]);
    visited[target[index].i][target[index].j] = 1;

    while (!q.isEmpty()) {
        Point t = q.deQueue();
        for (int d = 0; d < 8; d++) {
            Point n(t.i + di[d], t.j + dj[d]);
            if (n.i >= 0 && n.j >= 0 && n.i < N && n.j < M && !visited[n.i][n.j]) {
                visited[n.i][n.j] = visited[t.i][t.j] + 1;
                q.enQueue(n);
            }
        }
    }

    for (int i = 0; i < count; i++) {
        if (visited[target[i].i][target[i].j]) {
            distance[index][i] = visited[target[i].i][target[i].j] - 1;
            distance[i][index] = visited[target[i].i][target[i].j] - 1;
        } else {
            distance[index][i] = -1;
            distance[i][index] = -1;
        }
    }

    return 0;
}

void Solution::BackTrack(int u, int step, int ith) {
    if (ith == count) {
        if (step < ans)
            ans = step;
        return;
    }
    if (step > ans)
        return;

    for (int v = 1; v <= count; v++) {
        if (!visitedUV[v] && distance[u][v] > 0) {
            visitedUV[v] = 1;
            BackTrack(v, step + distance[u][v], ith + 1);
            visitedUV[v] = 0;
        }
    }
}
