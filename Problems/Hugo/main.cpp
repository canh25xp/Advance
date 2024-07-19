#define _CRT_SECURE_NO_WARNINGS
#include "point.hpp"
#include "queue.hpp"
#include <iostream>
using namespace std;

const int N_MAX = 20;
const int M_MAX = 20;
const int QUEUE_MAX = 1000;
const int A_HUGE_NUMBER = INT_MAX;

// Direction : up, down, left, right
const int di[4] = {-1, 1, 0, 0};
const int dj[4] = {0, 0, -1, 1};

void HandleFire(int (&fires)[N_MAX][M_MAX], const int (&lakes)[N_MAX][M_MAX], const Point Size);
int solve(int (&fires)[N_MAX][M_MAX], const int (&lakes)[N_MAX][M_MAX], const int (&diamonds)[N_MAX][M_MAX], const int (&gates)[N_MAX][M_MAX], const Point Size, const Point Hugo);

void DFS(int (&visited)[N_MAX][M_MAX], int (&fires)[N_MAX][M_MAX], const int (&lakes)[N_MAX][M_MAX], const int (&diamonds)[N_MAX][M_MAX], const int (&gates)[N_MAX][M_MAX], const Point Size, Point Hugo, int time, int score, int &ans);

int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M, R, C;
        cin >> N >> M >> R >> C;
        Point Hugo(R - 1, C - 1);
        Point Size(N, M);

        int F; // Total number of fires
        cin >> F;
        int fires[N_MAX][M_MAX] = {};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                fires[i][j] = A_HUGE_NUMBER;

        for (int f = 0; f < F; f++) {
            int i, j;
            cin >> i >> j;
            fires[i - 1][j - 1] = 0;
        }

        int L; // Total number of lakes
        cin >> L;
        int lakes[N_MAX][M_MAX] = {};
        for (int l = 0; l < L; l++) {
            int i, j;
            cin >> i >> j;
            lakes[i - 1][j - 1] = 1;
        }

        int G; // Total number of exit gates
        cin >> G;
        int gates[N_MAX][M_MAX] = {};
        for (int g = 0; g < G; g++) {
            int i, j;
            cin >> i >> j;
            gates[i - 1][j - 1] = 1;
        }

        int diamonds[N_MAX][M_MAX] = {};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> diamonds[i][j];

        cout << "Case #" << t + 1 << endl;
        cout << solve(fires, lakes, diamonds, gates, Size, Hugo) << endl;
    }

    return 0;
}

int solve(int (&fires)[N_MAX][M_MAX], const int (&lakes)[N_MAX][M_MAX], const int (&diamonds)[N_MAX][M_MAX], const int (&gates)[N_MAX][M_MAX], const Point Size, const Point Hugo) {
    HandleFire(fires, lakes, Size);
    int visited[N_MAX][M_MAX] = {};
    visited[Hugo.i][Hugo.j] = 1;

    int ans = -1;

    DFS(visited, fires, lakes, diamonds, gates, Size, Hugo, 0, diamonds[Hugo.i][Hugo.j], ans);

    return ans;
}

void DFS(int (&visited)[N_MAX][M_MAX], int (&fires)[N_MAX][M_MAX], const int (&lakes)[N_MAX][M_MAX], const int (&diamonds)[N_MAX][M_MAX], const int (&gates)[N_MAX][M_MAX], const Point Size, Point Hugo, int time, int score, int &ans) {
    int h = time;
    int c = score;

    if (gates[Hugo.i][Hugo.j]) {
        if (c > ans)
            ans = c;
    }

    if (lakes[Hugo.i][Hugo.j])
        h += 2;
    else
        h += 1;

    for (int k = 0; k < 4; k++) {
        Point n(Hugo.i + di[k], Hugo.j + dj[k]);
        if (n.isValid(Size) && !visited[n.i][n.j] && lakes[n.i][n.j] && fires[n.i][n.j] > h) {
            visited[n.i][n.j] = 1;
            DFS(visited, fires, lakes, diamonds, gates, Size, n, h, c + diamonds[n.i][n.j], ans);
            // DFS(nx, ny, h, c + diamonds[nx][ny]);
            visited[n.i][n.j] = 0;
        }
    }
}

void HandleFire(int (&fires)[N_MAX][M_MAX], const int (&lakes)[N_MAX][M_MAX], const Point Size) {
    Queue<Point, 600> q;
    for (int i = 0; i < Size.i; i++) {
        for (int j = 0; j < Size.j; j++) {
            if (fires[i][j] == 0) {
                q.enQueue(Point(i, j));
            }
        }
    }

    while (!q.isEmpty()) {
        Point t = q.deQueue();
        for (int d = 0; d < 4; d++) {
            Point n(t.i + di[d], t.j + dj[d]); // next Point
            if (n.isValid(Size) && (fires[n.i][n.j] == A_HUGE_NUMBER || fires[n.i][n.j] > fires[t.i][t.j] + 1) && !lakes[n.i][n.j]) {
                q.enQueue(n);
                fires[n.i][n.j] = fires[t.i][t.j] + 1;
            }
        }
    }
}