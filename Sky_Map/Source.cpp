#include <iostream>
using namespace std;

#define DEFAULT_TEST_CASE 10

const int MAX_SIZE = 25;

// Direction : left, right, up, down
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,-1,1};

template <typename T, unsigned int MAX>
class Stack
{
public:
    Stack();
    ~Stack();

    bool isFull();
    bool isEmpty();
    void push(T item);
    T pop();

private:
    T items[MAX];
    int top;
};

struct Point
{
    Point();
    Point(int _x, int _y);
    int x,y;
};

int main(){
	FILE *input;
	errno_t error = freopen_s(&input, "eval_input.txt", "r", stdin);

	int TEST_CASE = DEFAULT_TEST_CASE;
	cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
        int size = 0;
        cin >> size;

        int matrix[MAX_SIZE][MAX_SIZE] = {};

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cin >> matrix[i][j];
            }
        }

		Stack<Point ,MAX_SIZE*MAX_SIZE> s;
        int checked[MAX_SIZE][MAX_SIZE] = {};
        int constellars = 0;
        int max = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (matrix[i][j] == 1 && checked[i][j] != 1)
                {
                    s.push(Point(j,i));
                    checked[i][j] = 1;
                    constellars++;
                    int stars = 1;
                    while (!s.isEmpty())
                    {
                        Point p = s.pop();
                        for (int d = 0; d < 4; d++)
                        {
                            int x = p.x + dx[d];
                            int y = p.y + dy[d];
                            if (matrix[y][x] == 1 && checked[y][x] != 1 && y >= 0 && y < size && x >= 0 && x < size){
                                s.push(Point(x,y));
                                stars++;
                                checked[y][x] = 1;
                            }
                        }
                    }
                    if(stars>max)
                        max = stars;
                }
            }
        }

		cout<< constellars << " " << max << endl;
	}

	return 0;
}

template <typename T, unsigned int MAX>
Stack<T, MAX>::Stack()
{
    this->top = -1;
}

template <typename T, unsigned int MAX>
Stack<T, MAX>::~Stack()
{
}

template <typename T, unsigned int MAX>
bool Stack<T, MAX>::isEmpty(){
    if (this->top == -1)
        return true;
    else
        return false;
}

template <typename T, unsigned int MAX>
bool Stack<T, MAX>::isFull(){
    if (this->top == MAX - 1)
        return true;
    else
        return false;
}

template <typename T, unsigned int MAX>
void Stack<T, MAX>::push(T item){
    if (this->isFull())
        return;
    this->top++;
    this->items[this->top] = item;
}

template <typename T, unsigned int MAX>
T Stack<T, MAX>::pop(){
    T item;
    if (isEmpty())
        return item;
    item = this->items[this->top];
    this->top--;
    return item;
}

Point::Point(){
    this->x = 0;
    this->y = 0;
}

Point::Point(int _x, int _y){
    this->x = _x;
    this->y = _y;
}