#include <iostream>
using namespace std;

const int SIZE = 8; // Size of a chess board
const int BOARDS_MAX = 2; // Maximum number of chess boards in a test case

int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T; // Total number of test cases
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int K; // The total number of chess boards
        cin >> K;

        int board[BOARDS_MAX][SIZE][SIZE] = {};

        for (int k = 0; k < K; k++)
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                    cin >> board[k][i][j];

        int max_score = 0;

        cout << "Case #" << tc + 1 << "\n"
             << max_score << endl;
    }

    return 0;
}