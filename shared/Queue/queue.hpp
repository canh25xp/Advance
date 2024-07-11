template <typename T, unsigned int MAX>
class Queue {
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

template <typename T, unsigned int MAX>
Queue<T, MAX>::Queue() {
    front = -1;
    rear = -1;
    count = 0;
}

template <typename T, unsigned int MAX>
Queue<T, MAX>::~Queue() {
}

template <typename T, unsigned int MAX>
bool Queue<T, MAX>::isEmpty() {
    if (front == rear)
        return true;
    else
        return false;
}

template <typename T, unsigned int MAX>
bool Queue<T, MAX>::isFull() {
    if (front == 0 && rear == MAX - 1)
        return true;
    else
        return false;
}

template <typename T, unsigned int MAX>
void Queue<T, MAX>::enQueue(T item) {
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
T Queue<T, MAX>::peek() {
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
