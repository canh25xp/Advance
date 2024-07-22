#include "point.hpp"
#include "stack.hpp"
#include <iostream>

const int MAX_SIZE = 25;

const int di[4] = {0, 0, -1, 1};
const int dj[4] = {1, -1, 0, 0};

using namespace std;
int main() {
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int size = 0;
        cin >> size;

        int matrix[MAX_SIZE][MAX_SIZE] = {};

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                cin >> matrix[i][j];

        Stack<Point, MAX_SIZE * MAX_SIZE> s;
        int checked[MAX_SIZE][MAX_SIZE] = {};
        int constellars = 0;
        int max = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] == 1 && checked[i][j] != 1) {
                    s.push(Point(i, j));
                    checked[i][j] = 1;
                    constellars++;
                    int stars = 1;
                    while (!s.empty()) {
                        Point p = s.pop();
                        for (int d = 0; d < 4; d++) {
                            Point n(p.i + di[d], p.j + dj[d]);
                            if (n.valid(size) && matrix[n.i][n.j] == 1 && !checked[n.i][n.j]) {
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

    return 0;
}