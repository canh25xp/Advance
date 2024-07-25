#include <iostream>

const int N = 15;
const int M = 15;

int n, m, k;
int mat[N][M] = {};

void flip(int j);

int countRows();

using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    int ans = countRows();

    return ans;
}

void flip(int j) {
    for (int i = 0; i < n; i++)
        mat[i][j] = !mat[i][j];
}

int countRows() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < m; j++)
            tmp += mat[i][j];
        if (tmp == m)
            cnt++;
    }

    return cnt;
}
