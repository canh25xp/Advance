#define _CRT_SECURE_NO_WARNINGS
#include "point.hpp"
#include "queue.hpp"
#include <iostream>
using namespace std;

const int N_MAX = 4;
const int M_MAX = 4;
const int K_MAX = 16;
const int QUEUE_MAX = 100000;

// Direction : up, down, left, right
const int di[4] = {-1, 1, 0, 0};
const int dj[4] = {0, 0, -1, 1};

void HandleFire(int (&fires)[N_MAX][M_MAX], const int (&lakes)[N_MAX][M_MAX], const int N, const int M);
int play(int (&fires)[N_MAX][M_MAX], const int (&lakes)[N_MAX][M_MAX], const int (&diamonds)[N_MAX][M_MAX], const int (&gates)[N_MAX][M_MAX], const int N, const int M, const int R, const int C);

int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M, R, C;
        cin >> N >> M >> R >> C;
        R--;
        C--;

        int F; // Total number of fires
        cin >> F;
        int fires[N_MAX][M_MAX] = {};
        for (int f = 0; f < F; f++) {
            int i, j;
            cin >> i >> j;
            fires[i - 1][j - 1] = 1;
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

        int max_score = play(fires, lakes, diamonds, gates, N, M, R, C);
        cout << "Case #" << t + 1 << endl;
        cout << max_score << endl;
    }

    return 0;
}

int play(int (&fires)[N_MAX][M_MAX], const int (&lakes)[N_MAX][M_MAX], const int (&diamonds)[N_MAX][M_MAX], const int (&gates)[N_MAX][M_MAX], const int N, const int M, const int R, const int C) {
    static int score = diamonds[R][C];
    static int vst[N_MAX][M_MAX] = {};

    Queue<Point, QUEUE_MAX> q;
    q.enQueue(Point(R, C));

    while (!q.isEmpty()) {
        Point t = q.deQueue();
        vst[t.i][t.j] = 1;

        int fires_p[N_MAX][M_MAX] = {};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                fires_p[i][j] = fires[i][j];

        HandleFire(fires, lakes, N, M);

        if (gates[t.i][t.j])
            return score;

        for (int d = 0; d < 4; d++) {
            int ni = R + di[d];
            int nj = C + dj[d];
            if (ni >= 0 && nj >= 0 && ni < N && nj < M && !fires[ni][nj] && !vst[ni][nj]) {
                score += diamonds[ni][nj];
                q.enQueue(Point(ni, nj));
            }
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                fires[i][j] = fires_p[i][j];
    }

    return score;
}

void HandleFire(int (&fires)[N_MAX][M_MAX], const int (&lakes)[N_MAX][M_MAX], const int N, const int M) {
    int vst[N_MAX][M_MAX] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (fires[i][j] && !vst[i][j]) {
                for (int d = 0; d < 4; d++) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if (ni >= 0 && nj >= 0 && ni < N && nj < M && !lakes[ni][nj] && !fires[ni][nj]) {
                        vst[ni][nj] = 1;
                        fires[ni][nj] = 1;
                    }
                }
            }
        }
    }
}