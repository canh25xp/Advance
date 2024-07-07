#include <iostream>

using namespace std;

#define SIZE 5

template <class T> class Path_Finding {
public:
	Path_Finding();

	bool push(T k);

	T pop();

	T topElement();

	bool isFull();

	bool isEmpty();

private:

	int top;

	T st[SIZE];
};

template <class T> Path_Finding<T>::Path_Finding() {
	top = -1; 
}

template <class T> bool Path_Finding<T>::push(T k){

	if (isFull()) {
		return 1;
	}

	top = top + 1;

	st[top] = k;

	return 0;
}

template <class T> bool Path_Finding<T>::isEmpty(){
	if (top == -1)
		return 1;
	else
		return 0;
}

template <class T> bool Path_Finding<T>::isFull(){
	if (top == (SIZE - 1))
		return 1;
	else
		return 0;
}

template <class T> T Path_Finding<T>::pop(){
	T popped_element = st[top];
	top--;
	return popped_element;
}

template <class T> T Path_Finding<T>::topElement(){
	T top_element = st[top];
	return top_element;
}

int main(){
	Path_Finding<int> Stack;

	return 0;
}
