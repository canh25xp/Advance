#include "deque.hpp"
#include "point.hpp"
#include "queue.hpp"
#include <iostream>

const int N = 200;
const int M = 200;

const int di[4] = {0, -1, 0, 1};
const int dj[4] = {1, 0, -1, 0};

struct State {
    Point p;
    int d;
    State() : p(), d() {}
    State(Point p, int d) : p(p), d(d) {}
};

int solve(int (&)[N][M], int, int, Point, Point);
int BFS(int (&)[N][M], int, int, Point, Point, int);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> m >> n;
        Point s, d;
        cin >> s.j >> s.i >> d.j >> d.i;
        s--;
        d--;
        int mat[N][M] = {};
        for (int i = 0; i < n; i++) {
            char c[M + 1] = {};
            cin >> c;
            for (int j = 0; j < m; j++)
                if (c[j] == '1')
                    mat[i][j] = 1;
        }

        cout << solve(mat, n, m, s, d) << endl;
    }

    return 0;
}

int solve(int (&mat)[N][M], int n, int m, Point s, Point d) {
    int res1 = BFS(mat, n, m, s, d, 0);
    int res2 = BFS(mat, n, m, s, d, 1);
    int res3 = BFS(mat, n, m, s, d, 2);
    int res4 = BFS(mat, n, m, s, d, 3);

    int res = min(min(res1, res2), min(res3, res4));

    return res == INT_MAX ? -1 : res;
}

int BFS(int (&mat)[N][M], int n, int m, Point src, Point dst, int dir) {
    int visited[N][M] = {};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = INT_MAX;

    Deque<State, 10000> dq;
    dq.push_back(State(src, dir));
    visited[src.i][src.j] = 0;

    while (!dq.empty()) {
        State t = dq.pop_front();
        Point curr = t.p;
        int dir = t.d;
        for (int i = 0; i < 4; i++) {
            Point next(curr.i + di[i], curr.j + dj[i]);
            if (!next.valid(n, m) || mat[next.i][next.j])
                continue;

            int cost = (i == dir) ? 0 : 1;
            if (visited[next.i][next.j] > visited[curr.i][curr.j] + cost) {
                visited[next.i][next.j] = visited[curr.i][curr.j] + cost;
                if (cost == 0)
                    dq.push_front(State(next, i));
                else
                    dq.push_front(State(next, i));
            }
        }
    }

    return visited[dst.i][dst.j];
}