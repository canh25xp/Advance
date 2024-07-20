#define _CRT_SECURE_NO_WARNINGS
#include "point.hpp"
#include "queue.hpp"
#include <iostream>

using namespace std;

const int N = 8; // should be 700
const int M = 7; // should be 700

int n, m;
int mat[N][M] = {};
int vst[N][M] = {};

Queue<Point, 100000> q;

int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int solve();
bool BFS(Point t);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "test.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
                vst[i][j] = 0;
            }
        }

        cout << "#" << tc + 1 << " " << solve() << endl;
    }
    return 0;
}

int solve() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vst[i][j]) {
                vst[i][j] = 1;
                if (!BFS(Point(i, j)))
                    ans++;
            }
        }
    }

    return ans;
}

bool BFS(Point x) {
    q.clear();
    q.enQueue(x);
    while (!q.isEmpty()) {
        Point curr = q.deQueue();
        for (int d = 0; d < 8; d++) {
            Point next(curr.i + di[d], curr.j + dj[d]);
            if (next.isValid(n, m) && !vst[next.i][next.j] && mat[next.i][next.j] == mat[curr.i][curr.j]) {
                vst[next.i][next.j] = 1;
                q.enQueue(next);
            } else if (next.isValid(n, m) && mat[next.i][next.j] > mat[curr.i][curr.j])
                return true;
        }
    }

    return false;
}
