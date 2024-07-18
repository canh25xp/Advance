#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int MAX_M = 3;
const int MAX_N = 4;

int main() {
    freopen("input.txt", "r", stdin);
    int T; // Number of test cases
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int M, N; // COLS, ROWS
        cin >> M >> N;

        char mat[MAX_M][MAX_N] = {};
        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                cin >> mat[m][n];
            }
        }
        cout << endl;
    }
    return 0;
}