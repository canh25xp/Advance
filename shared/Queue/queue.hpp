#pragma once
#include <iostream>

template <typename T = int, int MAX = 10000>
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

template <typename T, int MAX>
Queue<T, MAX>::Queue() : front(-1), rear(-1), count(0) {}

template <typename T, int MAX>
Queue<T, MAX>::~Queue() {}

template <typename T, int MAX>
bool Queue<T, MAX>::isEmpty() const {
    return front == rear;
}

template <typename T, int MAX>
bool Queue<T, MAX>::isFull() const {
    return front == 0 && rear == MAX - 1;
}

template <typename T, int MAX>
void Queue<T, MAX>::enQueue(const T &item) {
    if (isFull()) {
        std::cerr << "Queue is full\n";
        return;
    }
    rear++;
    count++;
    items[rear] = item;
}

template <typename T, int MAX>
T Queue<T, MAX>::deQueue() {
    T item{};
    if (isEmpty()) {
        std::cerr << "Queue is empty\n";
        return item;
    }

    front++;
    count--;
    item = items[front];
    return item;
}

template <typename T, int MAX>
T Queue<T, MAX>::peek() const {
    T item{};
    if (isEmpty()) {
        std::cerr << "Queue is empty\n";
        return item;
    }
    item = items[front];
    return item;
}

template <typename T, int MAX>
int Queue<T, MAX>::size() const {
    return count;
}

template <typename T, int MAX>
bool Queue<T, MAX>::has(const T &item) const {
    for (int i = 0; i < this->size(); ++i) {
        if (items[(front + i) % MAX] == item) {
            return true;
        }
    }
    return false;
}

template <typename T, int MAX>
void Queue<T, MAX>::clear() {
    front = -1;
    rear = -1;
    count = 0;
}
