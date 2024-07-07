#include <iostream>

using namespace std;

const int TEST_CASE = 10;
const int MAX_SIZE	= 201;
const int PATH		= 1;
const int TRAP		= 0;
const int PRICESS	= 2;

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

int BFS(Point srt, Point dst, int maze[MAX_SIZE][MAX_SIZE], int size);

// MAIN
int main(){
	//FILE *input;
	//freopen_s(&input, "input.txt", "r", stdin);

    int test_case = TEST_CASE;
    cin >> test_case;
	for(int case_index = 0 ; case_index < test_case ; case_index++){
		int maze_size = 0;
		cin >> maze_size;
		int maze[MAX_SIZE][MAX_SIZE] = {};

		Point Princess;
		Point Entrance(0,0);
		Point Exit(maze_size-1,maze_size-1);

		for (int i = 0; i < maze_size; i++){
			for (int j = 0; j < maze_size; j++){
				cin >> maze[i][j];
				if(maze[i][j] == PRICESS)
					Princess = Point(j,i);
			}
		}

		int Found_Princess = BFS(Entrance, Princess, maze, maze_size);
		int Found_Exit = BFS(Princess, Exit, maze, maze_size);

        int Step = (Found_Princess == -1 || Found_Exit == -1) ? -1 : (Found_Princess+Found_Exit); 

		cout<< Step << endl;
	}
	//fclose(input);
	return 0;
}
//END MAIN

int BFS(Point srt, Point dst, int maze[MAX_SIZE][MAX_SIZE], int size){
    Queue<Point, 50000> queue;
	queue.enQueue(srt);

    int visited[MAX_SIZE][MAX_SIZE] = {};

	while(!queue.isEmpty()){
		Point current = queue.deQueue();
        for (int d = 0; d < 4; d++)
        {
            Point next(current.x + dx[d], current.y + dy[d]);
            if (next.y >= 0 && next.y < size && next.x >= 0 && next.x < size && !visited[next.y][next.x] && maze[next.y][next.x] != TRAP)
            {
                visited[next.y][next.x] = visited[current.y][current.x] + 1;
                if (next == dst){
                    return visited[next.y][next.x];
                }
                queue.enQueue(next);
            }
        }
	}

	return -1;
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
