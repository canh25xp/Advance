#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int MAX_N = 100; // should be 100
const int MAX_M = 100; // should be 100

// Direction : right down, left, up
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template <typename T, unsigned int MAX>
class Queue
{
public:
    Queue();
    ~Queue();

    bool isFull();
    bool isEmpty();
    void enQueue(T item);
    T deQueue();

    T peek();
    int size();

private:
    T items[MAX];
    int front, rear, count;
};

struct Point{
	Point();
	Point(int _x, int _y);

	bool operator!=(const Point& rhs) const ;
	bool operator==(const Point& rhs) const ;

	int x,y;
};

int main(){
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++){
        int N, M; // cols(x), rows(y)
        cin >> N >> M;

        int mat[MAX_M][MAX_N];
        for (int m = 0; m < M; m++){
            for (int n = 0; n < N; n++){
                cin >> mat[m][n];
            }
        }
        Point bomb;
        cin >> bomb.x >> bomb.y;
        bomb.x--;
        bomb.y--;

        int visited[MAX_M][MAX_N] = {};
        Queue<Point, 50000> q;
        int ans = 0;
        visited[bomb.y][bomb.x] = 1;
        q.enQueue(bomb);
        while(!q.isEmpty()){
	        Point current = q.deQueue();
            for (int d = 0; d < 4; d++){
                Point next(current.x + dx[d], current.y + dy[d]);
                if (next.y >= 0 && next.y < M && next.x >= 0 && next.x < N && !visited[next.y][next.x] && mat[next.y][next.x] == 1){
                    visited[next.y][next.x] = visited[current.y][current.x] + 1;
                    ans = visited[next.y][next.x];
                    q.enQueue(next);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

template <typename T, unsigned int MAX>
Queue<T, MAX>::Queue()
{
    front = -1;
    rear = -1;
    count = 0;
}

template <typename T, unsigned int MAX>
Queue<T, MAX>::~Queue()
{
}

template <typename T, unsigned int MAX>
bool Queue<T, MAX>::isEmpty(){
    if (front == rear)
        return true;
    else
        return false;
}

template <typename T, unsigned int MAX>
bool Queue<T, MAX>::isFull(){
    if (front == 0 && rear == MAX - 1)
        return true;
    else
        return false;
}

template <typename T, unsigned int MAX>
void Queue<T, MAX>::enQueue(T item){
    if (isFull())
        return;
    rear++;
    count++;
    items[rear] = item;
}

template <typename T, unsigned int MAX>
T Queue<T, MAX>::deQueue(){
    T item;
    if (isEmpty())
        return item;

    front++;
    count--;
    item = this->items[front];
    return item;
}

template <typename T, unsigned int MAX>
T Queue<T, MAX>::peek(){
    T item;
    if (isEmpty())
        return item;
    item = this->items[front];
    return item;
}

template <typename T, unsigned int MAX>
int Queue<T, MAX>::size() {
    return count;
}

Point::Point(){
	x=0;
	y=0;
}

Point::Point(int _x, int _y){
	x = _x;
	y = _y;
}

bool Point::operator!=(const Point& rhs) const{
	if(this->x == rhs.x && this->y == rhs.y)
		return false;
	else
		return true;
}

bool Point::operator==(const Point& rhs) const {
	if(this->x == rhs.x && this->y == rhs.y)
		return true;
	else
		return false;
}
