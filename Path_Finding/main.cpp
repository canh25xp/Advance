#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define MATRIX_SIZE 21
#define SIZE 100000

int TEST_CASE = 0;
int N=0;


template <class T> class Stack {
public:
	Stack();
	bool push(T k);
	T pop();
	T topElement();
	bool isFull();
	bool isEmpty();
private:
	int top;
	T st[SIZE];
};

struct Point{
	Point();
	Point(int _row, int _col);

	bool operator!=(const Point& rhs) const ;
	bool operator==(const Point& rhs) const ;

	int row,col;
};

bool solveMaze(Point start_point, Point end_point, int matrix[MATRIX_SIZE][MATRIX_SIZE]);

int main(){
	freopen("eval_input.txt", "r", stdin);
	cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		cin >> N;
		int matrix[MATRIX_SIZE][MATRIX_SIZE]={};
		for(int row=0; row<N; row++){
			for(int col=0; col<N; col++){
				cin >> matrix[row][col];
			}
		}

		Point start_point(0,0);
		Point end_point(N-1,N-1);

		bool flag=solveMaze(start_point, end_point, matrix);

		if(flag==1)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}

	return 0;
}

bool solveMaze(Point start_point, Point end_point, int matrix[MATRIX_SIZE][MATRIX_SIZE]){
	//up, right, down, left
	const int dx[] = {0 ,1 ,0 ,-1};
	const int dy[] = {-1,0 ,1 ,0};
	Stack<Point> stack;
	stack.push(start_point);
	bool checked[MATRIX_SIZE][MATRIX_SIZE]={};

	while(!stack.isEmpty()){
		Point current_point = stack.pop();

		if(current_point == end_point)
			return true;
		
		int row = current_point.row;
		int col = current_point.col;
		int distance = matrix[row][col];
		checked[row][col] = 1;

		for(int direction=0; direction<4; direction++){
			int new_col = col + distance*dx[direction];
			int new_row = row + distance*dy[direction];

			if( new_row < N	&& new_row >= 0 && new_col < N && new_col >= 0 && checked[new_row][new_col] == 0){
				stack.push(Point(new_row, new_col));
			}
		}
	}
	return false;
}

Point::Point(){
	row=0;
	col=0;
}

Point::Point(int _row, int _col){
	row = _row;
	col = _col;
}

bool Point::operator!=(const Point& rhs) const{
	if(row==rhs.row && col == rhs.col)
		return false;
	else
		return true;
}

bool Point::operator==(const Point& rhs) const {
	if(row==rhs.row && col == rhs.col)
		return true;
	else
		return false;
}


template <class T>
Stack<T>::Stack() {
	top = -1; 
}

template <class T>
bool Stack<T>::push(T k){

	if (isFull()) {
		return 1;
	}
	top++;
	st[top] = k;
	return 0;
}

template <class T>
bool Stack<T>::isEmpty(){
	if (top == -1)
		return 1;
	else
		return 0;
}

template <class T>
bool Stack<T>::isFull(){
	if (top == (SIZE - 1))
		return 1;
	else
		return 0;
}

template <class T>
T Stack<T>::pop(){
	T popped_element = st[top];
	top--;
	return popped_element;
}

template <class T>
T Stack<T>::topElement(){
	T top_element = st[top];
	return top_element;
}