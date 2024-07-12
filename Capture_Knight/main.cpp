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
#include <iostream>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = MAX_N;
const int QUEUE_SIZE = MAX_M * MAX_N;

template <typename T, unsigned int MAX>
class Queue {
public:
    Queue();
    ~Queue();

    void reset();
    bool isFull();
    bool isEmpty();
    void enQueue(T item);
    T deQueue();

private:
    T items[MAX];
    int front, rear;
};

struct Point {
    Point();
    Point(int x, int y);

    bool operator==(const Point &rhs) const;
    bool operator!=(const Point &rhs) const;

    Point operator+(const Point &rhs) const;
    void operator+=(const Point &rhs);
    void operator+=(const int &rhs);
    void operator++();

    Point operator-(const Point &rhs) const;
    void operator-=(const Point &rhs);
    void operator-=(const int &rhs);
    void operator--();

    int x, y;
};

void Print(const int &N, const int &M, const Point &A, const Point &D);

int BFS(const int &N, const int &M, const Point &A, const Point &D);

/////////////////////////////////////MAIN//////////////////////////////////////
int main() {
    // freopen("eval_input.txt", "r", stdin);
    int T; // Number of Test cases
    cin >> T;

    for (int tn = 1; tn <= T; tn++) {
        int N, M; // Rows(y), Cols(x)
        cin >> N >> M;

        int R, C; // Row and Col of the Attacking piece
        int S, K; // Row and Col of the Defending piece

        cin >> R >> C >> S >> K;

        Point A(C, R);
        Point D(K, S);

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
    static const int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
    static const int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

    static Queue<Point, QUEUE_SIZE> q;
    static int visited[MAX_N][MAX_M] = {};

    q.reset();
    q.enQueue(A);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = 0;

    while (!q.isEmpty()) {
        Point current = q.deQueue();
        for (int d = 0; d < 8; d++) {
            Point next(current.x + dx[d], current.y + dy[d]);
            if (next.y >= 0 && next.y < N && next.x >= 0 && next.x < M && !visited[next.y][next.x]) {
                visited[next.y][next.x] = visited[current.y][current.x] + 1;
                if (next == D)
                    return visited[next.y][next.x];
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
            if (A == Point(j, i))
                cout << "A";
            else if (D == Point(j, i))
                cout << "D";
            else
                cout << " ";
        }
        cout << "|" << endl;
    }
}

template <typename T, unsigned int MAX>
Queue<T, MAX>::Queue() : front(-1), rear(-1) {}

template <typename T, unsigned int MAX>
Queue<T, MAX>::~Queue() {}

template <typename T, unsigned int MAX>
void Queue<T, MAX>::reset() {
    front = -1;
    rear = -1;
}

template <typename T, unsigned int MAX>
bool Queue<T, MAX>::isEmpty() {
    if (front == rear)
        return true;
    return false;
}

template <typename T, unsigned int MAX>
bool Queue<T, MAX>::isFull() {
    if (front == 0 && rear == MAX - 1)
        return true;
    return false;
}

template <typename T, unsigned int MAX>
void Queue<T, MAX>::enQueue(T item) {
    if (isFull())
        return;
    rear++;
    items[rear] = item;
}

template <typename T, unsigned int MAX>
T Queue<T, MAX>::deQueue() {
    T item;
    if (isEmpty())
        return item;
    front++;
    item = this->items[front];
    return item;
}

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

bool Point::operator==(const Point &rhs) const {
    if (this->x == rhs.x && this->y == rhs.y)
        return true;
    return false;
}

bool Point::operator!=(const Point &rhs) const {
    if (this->x == rhs.x && this->y == rhs.y)
        return false;
    return true;
}

void Point::operator+=(const Point &rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
}

void Point::operator+=(const int &rhs) {
    this->x += rhs;
    this->y += rhs;
}

void Point::operator++() {
    this->x++;
    this->y++;
}

void Point::operator-=(const Point &rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
}

void Point::operator-=(const int &rhs) {
    this->x -= rhs;
    this->y -= rhs;
}

Point Point::operator+(const Point &rhs) const {
    return Point(this->x + rhs.x, this->y + rhs.y);
}

Point Point::operator-(const Point &rhs) const {
    return Point(this->x - rhs.x, this->y - rhs.y);
}

void Point::operator--() {
    this->x--;
    this->y--;
}
