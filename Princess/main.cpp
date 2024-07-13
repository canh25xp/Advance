#include "point.hpp"
#include "queue.hpp"
#include <iostream>

using namespace std;

const int SIZE = 201;

const int PATH = 1;
const int TRAP = 0;
const int PRICESS = 2;

// Direction : right down, left, up
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(Point srt, Point dst, int maze[SIZE][SIZE], int size);

// MAIN
int main(int argc, char *argv[]) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T{};
    cin >> T;
    for (int case_index = 0; case_index < T; case_index++) {
        int N = 0; // Size of the maze
        cin >> N;
        int maze[SIZE][SIZE] {};

        Point Princess;
        Point Entrance(0, 0);
        Point Exit(N - 1, N - 1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> maze[i][j];
                if (maze[i][j] == PRICESS)
                    Princess = Point(i, j);
            }
        }

        int Found_Princess = BFS(Entrance, Princess, maze, N);
        int Found_Exit = BFS(Princess, Exit, maze, N);

        int Step = (Found_Princess == -1 || Found_Exit == -1) ? -1 : (Found_Princess + Found_Exit);

        cout << Step << endl;
    }

    return 0;
}
// END MAIN

int BFS(Point srt, Point dst, int maze[SIZE][SIZE], int size) {
    Queue<Point, 50000> q;
    q.enQueue(srt);

    int visited[SIZE][SIZE] = {};

    while (!q.isEmpty()) {
        Point current = q.deQueue();
        for (int d = 0; d < 4; d++) {
            Point next(current.r + dx[d], current.c + dy[d]);
            if (next.c >= 0 && next.c < size && next.r >= 0 && next.r < size && !visited[next.r][next.c] && maze[next.r][next.c] != TRAP) {
                visited[next.r][next.c] = visited[current.r][current.c] + 1;
                if (next == dst) {
                    return visited[next.r][next.c];
                }
                q.enQueue(next);
            }
        }
    }

    return -1;
}
