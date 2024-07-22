#include "point.hpp"
#include "stack.hpp"
#include <iostream>

const int N_MAX = 25;

const int di[4] = {0, 0, -1, 1};
const int dj[4] = {1, -1, 0, 0};

void solve(int (&mat)[N_MAX][N_MAX], int N);

using namespace std;
int main() {
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N = 0;
        cin >> N;

        int matrix[N_MAX][N_MAX] = {};

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> matrix[i][j];

        solve(matrix, N);
    }

    return 0;
}

void solve(int (&mat)[N_MAX][N_MAX], int N) {
    Stack<Point, N_MAX * N_MAX> s;
    int checked[N_MAX][N_MAX] = {};
    int constellars = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] == 1 && checked[i][j] != 1) {
                s.push(Point(i, j));
                checked[i][j] = 1;
                constellars++;
                int stars = 1;
                while (!s.empty()) {
                    Point p = s.pop();
                    for (int d = 0; d < 4; d++) {
                        Point n(p.i + di[d], p.j + dj[d]);
                        if (n.valid(N) && mat[n.i][n.j] == 1 && !checked[n.i][n.j]) {
                            s.push(n);
                            checked[n.i][n.j] = 1;
                            stars++;
                        }
                    }
                }
                if (stars > max)
                    max = stars;
            }
        }
    }
    cout << constellars << " " << max << endl;
}
