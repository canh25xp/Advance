#pragma once
#include <iostream>

template <typename T = int, int MAX = 10000>
class Stack {
private:
    int top;
    T data[MAX] = {};

public:
    Stack();
    ~Stack();

    void push(const T &item);      // Add an item to the Stack
    T pop();                       // Remove an item from the Stack
    T peek() const;                // Get an item from the Stack without remove it
    bool isFull() const;           // Check if the Stack if Full
    bool isEmpty() const;          // Check if the Stack if Empty
    int size() const;              // Get the current number of items in the Stack
    bool has(const T &item) const; // Check if the Stack has an item.
};

template <typename T, int MAX>
Stack<T, MAX>::Stack() : top(-1) {}

template <typename T, int MAX>
Stack<T, MAX>::~Stack() {}

template <typename T, int MAX>
void Stack<T, MAX>::push(const T &item) {
    if (this->isFull()) {
        std::cerr << "Stack Overflow\n";
        return;
    }
    this->top++;
    this->data[this->top] = item;
}

template <typename T, int MAX>
T Stack<T, MAX>::pop() {
    T item{};
    if (isEmpty()) {
        std::cerr << "Stack Underflow\n";
        return item;
    }
    item = this->data[this->top];
    this->top--;
    return item;
}

template <typename T, int MAX>
T Stack<T, MAX>::peek() const {
    T item{};
    if (isEmpty()) {
        std::cerr << "Stack empty\n";
        return item;
    }

    item = this->data[this->top];

    return item;
}

template <typename T, int MAX>
bool Stack<T, MAX>::isEmpty() const {
    return (this->top < 0);
}

template <typename T, int MAX>
bool Stack<T, MAX>::isFull() const {
    if (this->top >= (MAX - 1))
        return true;
    else
        return false;
}

template <typename T, int MAX>
int Stack<T, MAX>::size() const {
    return this->top + 1;
}

template <typename T, int MAX>
bool Stack<T, MAX>::has(const T &item) const {
    for (int i = 0; i < this->size(); i++) {
        if (this->data[i] == item) {
            return true;
        }
    }
    return false;
}
