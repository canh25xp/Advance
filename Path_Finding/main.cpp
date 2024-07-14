#define _CRT_SECURE_NO_WARNINGS
#include "stack.hpp"
#include "point.hpp"
#include <iostream>

using namespace std;

#define MATRIX_SIZE 21
#define SIZE 100000

int TEST_CASE = 0;
int N = 0;

bool solveMaze(Point start_point, Point end_point, int matrix[MATRIX_SIZE][MATRIX_SIZE]);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    cin >> TEST_CASE;
    for (int case_index = 0; case_index < TEST_CASE; case_index++) {
        cin >> N;
        int matrix[MATRIX_SIZE][MATRIX_SIZE] = {};
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                cin >> matrix[row][col];
            }
        }

        Point start_point(0, 0);
        Point end_point(N - 1, N - 1);

        bool flag = solveMaze(start_point, end_point, matrix);

        if (flag == 1)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}

bool solveMaze(Point start_point, Point end_point, int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    // up, right, down, left
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {-1, 0, 1, 0};
    Stack<Point> stack;
    stack.push(start_point);
    bool checked[MATRIX_SIZE][MATRIX_SIZE] = {};

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