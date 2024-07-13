#pragma once
#include <iostream>

template <typename T = int, unsigned int MAX = 10000>
class Queue {
private:
    int front, rear, count;
    T items[MAX] = {};

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

template <typename T, unsigned int MAX>
Queue<T, MAX>::Queue() : front(-1), rear(-1), count(0) {}

template <typename T, unsigned int MAX>
Queue<T, MAX>::~Queue() {}

template <typename T, unsigned int MAX>
bool Queue<T, MAX>::isEmpty() const {
    if (front == rear)
        return true;
    else
        return false;
}

template <typename T, unsigned int MAX>
bool Queue<T, MAX>::isFull() const {
    if (front == 0 && rear == MAX - 1)
        return true;
    else
        return false;
}

template <typename T, unsigned int MAX>
void Queue<T, MAX>::enQueue(const T &item) {
    if (isFull())
        return;
    rear++;
    count++;
    items[rear] = item;
}

template <typename T, unsigned int MAX>
T Queue<T, MAX>::deQueue() {
    T item;
    if (isEmpty())
        return item;

    front++;
    count--;
    item = this->items[front];
    return item;
}

template <typename T, unsigned int MAX>
T Queue<T, MAX>::peek() const {
    T item;
    if (isEmpty())
        return item;
    item = this->items[front];
    return item;
}

template <typename T, unsigned int MAX>
int Queue<T, MAX>::size() const {
    return count;
}

template <typename T, unsigned int MAX>
bool Queue<T, MAX>::has(const T &item) const {
    for (int i = 0; i < this->size(); ++i) {
        if (this->items[(this->front + i) % MAX] == item) {
            return true;
        }
    }
    return false;
}

template <typename T, unsigned int MAX>
void Queue<T, MAX>::clear() {
    this->front = -1;
    this->rear = -1;
    this->count = 0;
}
