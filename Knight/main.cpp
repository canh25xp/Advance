#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int SIZE_N = 5;
const int SIZE_M = 7;

static const int di[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
static const int dj[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

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

class Solution{
public:
    Solution(int (&chessboard)[SIZE_N][SIZE_M], int N, int M);

    int Solve();

private:
    int ans;
    int N, M;
    int (&chessboard)[SIZE_N][SIZE_M];

    Point start;
    Point target[SIZE_N*SIZE_M];
    int targets;
    int distance[SIZE_N*SIZE_M];

    int BFS(Point start, int target_index);
};

using namespace std;
int main(int argc, char **argv) {
    const char* input = (argc > 1) ? argv[1] : "input.txt";
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

        cout << "Case #" << t + 1 << "\n" << s.Solve() << endl;
    }

    return 0;
}

Solution::Solution(int (&chessboard)[SIZE_N][SIZE_M], int N, int M) : chessboard(chessboard), N(N), M(M), ans(0) {}

int Solution::Solve() {
    ans = INT_MAX;
    targets = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (chessboard[i][j] == 3)
                start = Point(i, j);

            else if (chessboard[i][j] == 1){
                target[targets] = Point(i,j);
                targets++;
            }
        }
    }

    return ans;
}

int Solution::BFS(Point start, int target_index) {
    int visited [SIZE_N][SIZE_M] = {};
    int count = 0;

    Queue<Point> q;
    q.enQueue(start);

    while (!q.isEmpty()) {
        Point t = q.deQueue();
        for (int d = 0; d < 8; d++) {
            Point n(t.i + di[d], t.j + dj[d]);
            if (n.i >= 0 && n.j >= 0 && n.i < N && n.j < M && !visited[n.i][n.j]) {
                visited[n.i][n.j] = visited[t.i][t.j] + 1;
                q.enQueue(n);
                if (chessboard[n.i][n.j] == 1) {

                }
            }
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
