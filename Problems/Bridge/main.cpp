#define _CRT_SECURE_NO_WARNINGS // Suppress Warning C4996: 'freopen': This function or variable may be unsafe. Consider using freopen_s instead.
#include <iostream>
using namespace std;

const int MAX_W = 5;  // Width of the bridge should always be 5
const int MAX_L = 20; // Length of the bridge should be no more than 20

struct Point {
    Point();
    Point(int _x, int _y);

    bool operator==(const Point &rhs) const;
    bool operator!=(const Point &rhs) const;
    void operator+=(const Point &rhs);
    Point operator+(const Point &rhs) const;

    int x, y;
};

template <const int ROWS, const int COLS>
void DFS(const int (&mat)[ROWS][COLS], const int L, const int W, const Point current, int coin = 0);

int max_coin, check;

// MAIN
int main() {
    freopen("eval_input.txt", "r", stdin);

    int T; // the total number of test case
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int L; // Length of the bridge
        cin >> L;
        int W = MAX_W;

        int bridge[MAX_L][MAX_W] = {};
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < W; j++) {
                cin >> bridge[i][j];
            }
        }

        Point start(W / 2, L);

        max_coin = -1;
        check = 1;

        DFS<MAX_L, MAX_W>(bridge, L, W, start);
        cout << "#" << tc + 1 << " " << max_coin << endl;
    }
    return 0;
}
// END MAIN

template <const int ROWS, const int COLS>
void DFS(const int (&mat)[ROWS][COLS], const int L, const int W, const Point current, int coin) {
    static const Point d[3] = {Point(0, -1), Point(-1, -1), Point(1, -1)}; // Direction : up_straight, up_left, up_right.

    if (current.y == 0 && max_coin < coin)
        max_coin = coin;

    for (int i = 0; i < 3; i++) {
        Point next = current + d[i];

        if (next.x >= 0 && next.x < W && next.y >= 0) {
            if (mat[next.y][next.x] != 2)
                DFS(mat, L, W, next, coin + mat[next.y][next.x]);

            else if (check) {
                check = 0;
                DFS(mat, L, W, next, coin);
                check = 1;
            }
        }
    }
}

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int _x, int _y) {
    x = _x;
    y = _y;
}

bool Point::operator==(const Point &rhs) const {
    if (this->x == rhs.x && this->y == rhs.y)
        return true;
    else
        return false;
}

bool Point::operator!=(const Point &rhs) const {
    if (this->x == rhs.x && this->y == rhs.y)
        return false;
    else
        return true;
}

void Point::operator+=(const Point &rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
}

Point Point::operator+(const Point &rhs) const {
    Point tmp;

    tmp.x = this->x + rhs.x;
    tmp.y = this->y + rhs.y;

    return tmp;
}
