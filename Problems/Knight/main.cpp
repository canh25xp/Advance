#define _CRT_SECURE_NO_WARNINGS
#include "point.hpp"
#include "queue.hpp"
#include <iostream>

#define INT_MAX 2147483647
#define INF INT_MAX

const int SIZE_N = 100;
const int SIZE_M = 100;
const int MAX_TARGET = 10 + 1;

const int di[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
const int dj[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

class Solution {
public:
    Solution(int (&chessboard)[SIZE_N][SIZE_M], int N, int M);

    int Solve();

private:
    int ans;
    int N, M;
    int (&chessboard)[SIZE_N][SIZE_M];

    Point target[MAX_TARGET];
    int count; // Total number of targets in the board (the knight is counted too)

    int distance[MAX_TARGET][MAX_TARGET] = {}; // TODO: initialize somewhere else
    int visitedUV[MAX_TARGET] = {};            // TODO: initialize somewhere else

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
        int N, M;
        cin >> N >> M;
        int chessboard[SIZE_N][SIZE_M] = {};

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> chessboard[i][j];

        Solution s(chessboard, N, M);

        cout << "Case #" << t + 1 << "\n"
             << s.Solve() << endl;
    }

    return 0;
}

Solution::Solution(int (&chessboard)[SIZE_N][SIZE_M], int N, int M) : chessboard(chessboard), N(N), M(M), ans(0) {
    for (size_t i = 0; i < MAX_TARGET; i++) {
        for (int j = 0; j < MAX_TARGET; j++) {
            distance[i][j] = 0;
        }
        visitedUV[i] = 0;
    }
}

int Solution::Solve() {
    ans = INT_MAX;
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
    int visited[SIZE_N][SIZE_M] = {};
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
