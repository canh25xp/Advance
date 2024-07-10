#include <iostream>
using namespace std;

const int SIZE = 8;       // Size of a chess board
const int MAX_BOARDS = 20; // Maximum number of chess boards in a test case

int solve(const int (&board)[SIZE][SIZE]);

void BackTracking(const int (&board)[SIZE][SIZE], int (&map)[SIZE][SIZE], int &max_score, int i = 0, int score = 0);

// Check if the horizontal and vertical direction already contains a queen
bool CheckOrthogonal(const int (&map)[SIZE][SIZE], int i, int j);

// Check if the diagonal direction already contains a queen
bool CheckDiagonal(const int (&map)[SIZE][SIZE], int i, int j);

int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T; // Total number of test cases
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int K; // The total number of chess boards
        cin >> K;

        int board[MAX_BOARDS][SIZE][SIZE] = {};

        for (int k = 0; k < K; k++) {
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                    cin >> board[k][i][j];
        }

        cout << "Case #" << tc + 1 << endl;
        for (int k = 0; k < K; k++)
            cout << solve(board[k]) << endl;
    }

    return 0;
}

int solve(const int (&board)[SIZE][SIZE]) {
    int map[SIZE][SIZE] = {}; // A matrix that map locations of the 8 queens on the board.
    int max_score = 0;
    BackTracking(board, map, max_score);
    return max_score;
}

void BackTracking(const int (&board)[SIZE][SIZE], int (&map)[SIZE][SIZE], int &max_score, int i, int score) {
    if (i == SIZE) {
        if (score > max_score)
            max_score = score;
        return;
    }

    for (int j = 0; j < SIZE; j++) {
        if (CheckOrthogonal(map, i, j) && CheckDiagonal(map, i, j)) {
            map[i][j] = 1;
            score += board[i][j];
            BackTracking(board, map, max_score, i + 1, score);
            map[i][j] = 0;
            score -= board[i][j];
        }
    }
}

bool CheckOrthogonal(const int (&map)[SIZE][SIZE], int i, int j) {
    for (int x = 0; x < 8; x++)
        if (map[i][x] || map[x][j])
            return false;

    return true;
}

bool CheckDiagonal(const int (&map)[SIZE][SIZE], int i, int j) {
    int x = i, y = j;
    while (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (map[x][y])
            return false;
        x--;
        y--;
    }
    x = i + 1;
    y = j + 1;
    while (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (map[x][y])
            return false;
        x++;
        y++;
    }
    x = i - 1;
    y = j + 1;
    while (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (map[x][y])
            return false;
        x--;
        y++;
    }
    x = i + 1;
    y = j - 1;
    while (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (map[x][y])
            return false;
        x++;
        y--;
    }
    return true;
}