/******************************************************************************
Capture Knignt
A Mobile piece (a Knight, Move like an L shape), called the Attack Piece (A)
A Stationary Piece, called the Defend piece (D)
NxM chessboard
Capture the (D) by moving the (A) with minimum amount of moves.
Output that MINIMUM NUMBER OF MOVES.
[INPUT]
2               <- T, the number of Test cases
9 9             <- N M, the rows and cols of the chess board
3 5 2 8         <- R C S K, Location of (A) and (D)
20 20
2 3 7 9
[OUTPUT]
Case #1
2
Case #2
5

NOTES: The index of the input location is 1-based index.
That is, the location of the upper left most is (1,1)
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS // Suppress Warning	C4996: 'freopen': This function or variable may be unsafe. Consider using freopen_s instead.
#include "point.hpp"
#include "queue.hpp"
#include <iostream>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = MAX_N;
const int QUEUE_SIZE = MAX_M * MAX_N;

void Print(const int &N, const int &M, const Point &A, const Point &D);

int BFS(const int &N, const int &M, const Point &A, const Point &D);

/////////////////////////////////////MAIN//////////////////////////////////////
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T; // Number of Test cases
    cin >> T;

    for (int tn = 1; tn <= T; tn++) {
        int N, M; // Rows(y), Cols(x)
        cin >> N >> M;

        int R, C; // Row and Col of the Attacking piece
        int S, K; // Row and Col of the Defending piece

        cin >> R >> C >> S >> K;

        Point A(R, C);
        Point D(S, K);

        // Reset Pieces position to 0-based index
        --A;
        --D;

        int ans = BFS(N, M, A, D);
        cout << "Case #" << tn << endl;
        cout << ans << endl;
    }

    return 0;
}
/////////////////////////////////////MAIN//////////////////////////////////////

int BFS(const int &N, const int &M, const Point &A, const Point &D) {
    static const int dr[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
    static const int dc[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

    static Queue<Point, QUEUE_SIZE> q;
    static int visited[MAX_N][MAX_M] = {};

    q.clear();
    q.enQueue(A);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = 0;

    while (!q.isEmpty()) {
        Point current = q.deQueue();
        for (int d = 0; d < 8; d++) {
            Point next(current.r + dr[d], current.c + dc[d]);
            if (next.r >= 0 && next.r < N && next.c >= 0 && next.c < M && !visited[next.r][next.c]) {
                visited[next.r][next.c] = visited[current.r][current.c] + 1;
                if (next == D)
                    return visited[next.r][next.c];
                q.enQueue(next);
            }
        }
    }

    return -1;
}

void Print(const int &N, const int &M, const Point &A, const Point &D) {
    system("cls");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "|";
            if (A == Point(i, j))
                cout << "A";
            else if (D == Point(i, j))
                cout << "D";
            else
                cout << " ";
        }
        cout << "|" << endl;
    }
}