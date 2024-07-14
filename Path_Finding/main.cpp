#define _CRT_SECURE_NO_WARNINGS
#include "point.hpp"
#include "stack.hpp"
#include <iostream>

using namespace std;

const int N_MAX = 21;
const int STACK_SIZE = 100000;

bool solve(Point start_point, Point end_point, int matrix[N_MAX][N_MAX], const int &N);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        int matrix[N_MAX][N_MAX] = {};
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                cin >> matrix[row][col];
            }
        }

        Point start_point(0, 0);
        Point end_point(N - 1, N - 1);

        bool flag = solve(start_point, end_point, matrix, N);

        if (flag == 1)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}

bool solve(Point start_point, Point end_point, int matrix[N_MAX][N_MAX], const int &N) {
    // up, right, down, left
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {-1, 0, 1, 0};
    Stack<Point, STACK_SIZE> stack;
    stack.push(start_point);
    bool checked[N_MAX][N_MAX] = {};

    while (!stack.isEmpty()) {
        Point current_point = stack.pop();

        if (current_point == end_point)
            return true;

        int row = current_point.i;
        int col = current_point.j;
        int distance = matrix[row][col];
        checked[row][col] = 1;

        for (int direction = 0; direction < 4; direction++) {
            int new_col = col + distance * dx[direction];
            int new_row = row + distance * dy[direction];

            if (new_row < N && new_row >= 0 && new_col < N && new_col >= 0 && checked[new_row][new_col] == 0) {
                stack.push(Point(new_row, new_col));
            }
        }
    }
    return false;
}