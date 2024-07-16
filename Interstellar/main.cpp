#include <iostream>

const int SIZE = 5;

struct Point {
    int x, y;

    Point() : x(0), y(0) {}

    Point(int x, int y) : x(x), y(y) {}
};

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        Point S, D;

        cin >> S.x >> S.y >> D.x >> D.y;

        Point A[SIZE], B[SIZE];
        int time[SIZE];
        for (int i = 0; i < N; i++)
            cin >> A[i].x >> A[i].y >> B[i].x >> B[i].y >> time[i];

        cout << "#" << t + 1 << endl;
    }

    return 0;
}
