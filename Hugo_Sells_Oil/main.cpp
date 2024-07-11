#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N_MAX = 5;
const int M_MAX = 6;
const int QUEUE_SIZE = 100000;

enum PIPE {
    UDLR    = 1,    // Up-Down, Left-Right
    UD      = 2,    // Up-Down
    LR      = 3,    // Left-Right
    UR      = 4,    // Up-Right 
    DR      = 5,    // Down-Right
    DL      = 6,    // Down-Left
    UL      = 7,    // Up-Left
};

const int di[4] = {-1,1,0,0};
const int dj[4] = {0,0,-1,1};

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
    Point(int i, int j);

    bool operator==(const Point& rhs) const;
    bool operator!=(const Point& rhs) const;

    Point operator+(const Point& rhs) const;
    void operator+=(const Point& rhs);
    void operator+=(const int& rhs);
    void operator++();

    Point operator-(const Point& rhs) const;
    void operator-=(const Point& rhs);
    void operator-=(const int& rhs);
    void operator--();

    int i, j;
};

int BFS(const int (&mat)[N_MAX][M_MAX], const int &N, const int &M, const Point &start, const int &steps);

/////////////////////////////////////MAIN//////////////////////////////////////
int main(int argc, char* argv[]){
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M; // Matrix size NxM
        int r, c; // Hugo's location (row, col)
        int P;    // Hugo's mana
        cin >> N >> M >> r >> c >> P;
        int mat[N_MAX][M_MAX] = {};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> mat[i][j];

        Point hugo(r, c);

        int ans = BFS(mat, N, M, hugo, P);
        cout << "Case #" << t + 1 << endl
             << ans << endl;
    }
    return 0;
}
/////////////////////////////////////MAIN//////////////////////////////////////

int BFS(const int (&mat)[N_MAX][M_MAX], const int &N, const int &M, const Point &start, const int &steps){
    int count = 0; // Count the number of pipes
    int vst[N_MAX][M_MAX] = {};

    vst[start.i][start.j] = 1;
    count++;

    Queue<Point, QUEUE_SIZE> q;

    q.enQueue(start);

    while (!q.isEmpty()) {
        Point t = q.deQueue();

        if (vst[t.i][t.j] == steps)
            return count;

        PIPE pipe = (PIPE) mat[t.i][t.j];

        switch (pipe) {
        case UDLR:
            // d = 0,1,2,3
            for (int d = 0; d < 4; d++) {
                int ni = t.i+di[d];
                int nj = t.j+dj[d];
                if (ni >= 0 && nj >= 0 && ni < N && nj < M && !vst[ni][nj] && mat[ni][nj]) {
                    vst[ni][nj] = vst[t.i][t.j] + 1;
                    count++;
                    q.enQueue(Point(ni, nj));
                }
            }
            break;
        case UD:
            // d = 0,1
            for (int d = 0; d <= 1; d++) {
                int ni = t.i+di[d];
                int nj = t.j+dj[d];
                if (ni >= 0 && nj >= 0 && ni < N && nj < M && !vst[ni][nj] && mat[ni][nj]) {
                    vst[ni][nj] = vst[t.i][t.j] + 1;
                    count++;
                    q.enQueue(Point(ni, nj));
                }
            }
            break;
        case LR:
            // d = 2,3
            for (int d = 2; d <= 3; d++) {
                int ni = t.i+di[d];
                int nj = t.j+dj[d];
                if (ni >= 0 && nj >= 0 && ni < N && nj < M && !vst[ni][nj] && mat[ni][nj]) {
                    vst[ni][nj] = vst[t.i][t.j] + 1;
                    count++;
                    q.enQueue(Point(ni, nj));
                }
            }
            break;
        case UR:
            // d = 0,3
            for (int d = 0; d <= 3; d+=3) {
                int ni = t.i+di[d];
                int nj = t.j+dj[d];
                if (ni >= 0 && nj >= 0 && ni < N && nj < M && !vst[ni][nj] && mat[ni][nj]) {
                    vst[ni][nj] = vst[t.i][t.j] + 1;
                    count++;
                    q.enQueue(Point(ni, nj));
                }
            }
            break;
        case DR:
            // d = 1,3
            for (int d = 1; d <= 3; d+=2) {
                int ni = t.i+di[d];
                int nj = t.j+dj[d];
                if (ni >= 0 && nj >= 0 && ni < N && nj < M && !vst[ni][nj] && mat[ni][nj]) {
                    vst[ni][nj] = vst[t.i][t.j] + 1;
                    count++;
                    q.enQueue(Point(ni, nj));
                }
            }
            break;
        case DL:
            // d = 1,2
            for (int d = 1; d <= 2; d++) {
                int ni = t.i+di[d];
                int nj = t.j+dj[d];
                if (ni >= 0 && nj >= 0 && ni < N && nj < M && !vst[ni][nj] && mat[ni][nj]) {
                    vst[ni][nj] = vst[t.i][t.j] + 1;
                    count++;
                    q.enQueue(Point(ni, nj));
                }
            }
            break;
        case UL:
            // d = 0,2
            for (int d = 0; d <= 2; d+=2) {
                int ni = t.i+di[d];
                int nj = t.j+dj[d];
                if (ni >= 0 && nj >= 0 && ni < N && nj < M && !vst[ni][nj] && mat[ni][nj]) {
                    vst[ni][nj] = vst[t.i][t.j] + 1;
                    count++;
                    q.enQueue(Point(ni, nj));
                }
            }
            break;
        default:
            break;
        }
    }
    return count;
}

template <typename T, unsigned int MAX>
Queue<T, MAX>::Queue() :front(-1), rear(-1) {}

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

Point::Point() :i(0), j(0) {}

Point::Point(int i, int j) :i(i), j(j) {}

bool Point::operator==(const Point& rhs) const {
    if (this->i == rhs.i && this->j == rhs.j)
        return true;
    return false;
}

bool Point::operator!=(const Point& rhs) const {
    if (this->i == rhs.i && this->j == rhs.j)
        return false;
    return true;
}

void Point::operator+=(const Point& rhs) {
    this->i += rhs.i;
    this->j += rhs.j;
}

void Point::operator+=(const int& rhs) {
    this->i += rhs;
    this->j += rhs;
}

void Point::operator++() {
    this->i++;
    this->j++;
}

void Point::operator-=(const Point& rhs) {
    this->i -= rhs.i;
    this->j -= rhs.j;
}

void Point::operator-=(const int& rhs) {
    this->i -= rhs;
    this->j -= rhs;
}

Point Point::operator+(const Point& rhs) const {
    return Point(this->i + rhs.i, this->j + rhs.j);
}

Point Point::operator-(const Point& rhs) const {
    return Point(this->i - rhs.i, this->j - rhs.j);
}

void Point::operator--() {
    this->i--;
    this->j--;
}