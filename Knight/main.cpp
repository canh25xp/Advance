#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define INT_MAX 2147483647

const int SIZE_N = 100;
const int SIZE_M = 100;
const int MAX_TARGET = 10 + 1;

const int di[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
const int dj[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

template <typename T = int, int MAX = 10000>
class Queue {
private:
    int front, rear, count;
    T data[MAX];

public:
    Queue();
    ~Queue();

    void enQueue(const T &item);
    T deQueue();
    T peek() const;
    bool isFull() const;
    bool isEmpty() const;
    int size() const;
    bool has(const T &item) const;
    void clear();
};

struct Point {
    Point();
    Point(int i, int j);

    int i, j;
};

class Solution {
public:
    Solution(int (&chessboard)[SIZE_N][SIZE_M], int N, int M);

    int Solve();

private:
    int ans;
    int N, M;
    int (&chessboard)[SIZE_N][SIZE_M];

    Point target[MAX_TARGET];
    int count; // Total number of targets in the board

    int distance[MAX_TARGET][MAX_TARGET] = {}; // TODO: initialize somewhere else
    int visitedUV[MAX_TARGET] = {};            // TODO: initialize somewhere else

    int BFS(Point start, int target_index);
    void BackTrack(int u, int step, int ith);
};

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;
        int chessboard[SIZE_N][SIZE_M] = {};

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> chessboard[i][j];

        Solution s(chessboard, N, M);

        cout << "Case #" << t + 1 << "\n"
             << s.Solve() << endl;
    }

    return 0;
}

Solution::Solution(int (&chessboard)[SIZE_N][SIZE_M], int N, int M) : chessboard(chessboard), N(N), M(M), ans(0) {}

int Solution::Solve() {
    ans = INT_MAX;
    count = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (chessboard[i][j] == 3)
                target[0] = Point(i, j);

            else if (chessboard[i][j] == 1) {
                target[count] = Point(i, j);
                count++;
            }
        }
    }

    for (int i = 0; i < count; i++)
        BFS(target[i], i);

    visitedUV[0] = 1;
    BackTrack(0, 0, 1);

    return ans;
}

int Solution::BFS(Point start, int target_index) {
    int visited[SIZE_N][SIZE_M] = {};

    Queue<Point> q;
    q.enQueue(start);

    while (!q.isEmpty()) {
        Point t = q.deQueue();
        for (int d = 0; d < 8; d++) {
            Point n(t.i + di[d], t.j + dj[d]);
            if (n.i >= 0 && n.j >= 0 && n.i < N && n.j < M && !visited[n.i][n.j]) {
                visited[n.i][n.j] = visited[t.i][t.j] + 1;
                q.enQueue(n);
                if (chessboard[n.i][n.j] == 1 || chessboard[n.i][n.j] == 3)
                    for (int i = 0; i < count; i++)
                        if (n.i == target[i].i && n.j == target[i].j)
                            distance[target_index][i] = visited[target[i].i][target[i].j];
            }
        }
    }

    return 0;
}

void Solution::BackTrack(int u, int step, int ith) {
    if (ith == count) {
        if (step < ans)
            ans = step;
        return;
    }
    if (step > ans)
        return;

    for (int v = 0; v < count; v++) {
        if (!visitedUV[v] && distance[u][v] > 0) {
            visitedUV[v] = 1;
            BackTrack(v, step + distance[u][v], ith + 1);
            visitedUV[v] = 0;
        }
    }
}

Point::Point() : i(0), j(0) {}

Point::Point(int i, int j) : i(i), j(j) {}

template <typename T, int MAX>
Queue<T, MAX>::Queue() : front(-1), rear(-1), count(0) {}

template <typename T, int MAX>
Queue<T, MAX>::~Queue() {}

template <typename T, int MAX>
bool Queue<T, MAX>::isEmpty() const {
    return front == rear;
}

template <typename T, int MAX>
bool Queue<T, MAX>::isFull() const {
    return front == 0 && rear == MAX - 1;
}

template <typename T, int MAX>
void Queue<T, MAX>::enQueue(const T &item) {
    if (isFull()) {
        std::cerr << "Queue is full\n";
        return;
    }
    rear++;
    count++;
    data[rear] = item;
}

template <typename T, int MAX>
T Queue<T, MAX>::deQueue() {
    T item;
    if (isEmpty()) {
        std::cerr << "Queue is empty\n";
        return item;
    }

    front++;
    count--;
    item = data[front];
    return item;
}

template <typename T, int MAX>
T Queue<T, MAX>::peek() const {
    T item;
    if (isEmpty()) {
        std::cerr << "Queue is empty\n";
        return item;
    }
    item = data[front];
    return item;
}

template <typename T, int MAX>
int Queue<T, MAX>::size() const {
    return count;
}

template <typename T, int MAX>
bool Queue<T, MAX>::has(const T &item) const {
    for (int i = 0; i < this->size(); ++i) {
        if (data[(front + i) % MAX] == item) {
            return true;
        }
    }
    return false;
}

template <typename T, int MAX>
void Queue<T, MAX>::clear() {
    front = -1;
    rear = -1;
    count = 0;
}
