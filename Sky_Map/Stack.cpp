#include <iostream>

using namespace std;

#define SIZE 5

template <class T> class Sky_Map {
public:
	Sky_Map();

	bool push(T k);

	T pop();

	T topElement();

	bool isFull();

	bool isEmpty();

private:

	int top;

	T st[SIZE];
};

template <class T> Sky_Map<T>::Sky_Map() {
	top = -1; 
}

template <class T> bool Sky_Map<T>::push(T k){

	if (isFull()) {
		return 1;
	}

	top = top + 1;

	st[top] = k;

	return 0;
}

template <class T> bool Sky_Map<T>::isEmpty(){
	if (top == -1)
		return 1;
	else
		return 0;
}

template <class T> bool Sky_Map<T>::isFull(){
	if (top == (SIZE - 1))
		return 1;
	else
		return 0;
}

template <class T> T Sky_Map<T>::pop(){
	T popped_element = st[top];
	top--;
	return popped_element;
}

template <class T> T Sky_Map<T>::topElement(){
	T top_element = st[top];
	return top_element;
}

int main(){
	Sky_Map<int> Stack;

	return 0;
}
