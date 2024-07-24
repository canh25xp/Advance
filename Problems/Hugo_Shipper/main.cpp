#include <climits>
#include <cmath>
#include <iostream>

const int N = 10;

int solve(int (&)[N][2], int, int (&)[2], int (&)[2]);

int dis(int (&)[2], int (&)[2]);

void backtrack(int (&coords)[N][2], int n, int (&S)[2], int (&H)[2], int (&visited)[N], int &ans, int i, int currDis, int cnt);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int ti = 0; ti < T; ti++) {
        int S[2], H[2]; // Sx, Sy, Hx, Hy
        cin >> S[0] >> S[1] >> H[0] >> H[1];
        int n;
        cin >> n;
        int coords[N][2]; // x, y coordinates
        for (int i = 0; i < n; i++)
            cin >> coords[i][0] >> coords[i][1];

        cout << "Case #" << ti + 1 << " " << solve(coords, n, S, H) << endl;
    }

    return 0;
}

int solve(int (&coords)[N][2], int n, int (&S)[2], int (&H)[2]) {
    int visited[N] = {};
    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
        backtrack(coords, n, S, H, visited, ans, i, dis(S, coords[i]), n);

    return ans;
}

int dis(int (&A)[2], int (&B)[2]) {
    return abs(A[0] - B[0]) + abs(A[1] - B[1]);
}

void backtrack(int (&coords)[N][2], int n, int (&S)[2], int (&H)[2], int (&visited)[N], int &ans, int i, int currDis, int nodeLeft) {
    if (currDis > ans)
        return;

    if (nodeLeft <= 1) {
        int totalDis = currDis + dis(coords[i], H);
        if (totalDis < ans)
            ans = totalDis;

        return;
    }

    visited[i] = 1;
    for (int j = 0; j < n; j++) {
        if (!visited[j]) {
            backtrack(coords, n, S, H, visited, ans, j, dis(coords[j], coords[i]), nodeLeft - 1);
        }
    }
    visited[i] = 0;
}
