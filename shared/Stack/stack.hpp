template <typename T = int, int MAX = 10000>
class Stack {
private:
    int top;
    T items[MAX];

public:
    Stack();
    ~Stack();

    void push(T item);
    T pop();
    bool isFull();
    bool isEmpty();
};

template <typename T, int MAX>
Stack<T, MAX>::Stack() : top(-1) {}

template <typename T, int MAX>
Stack<T, MAX>::~Stack() {}

template <typename T, int MAX>
void Stack<T, MAX>::push(T item) {
    if (this->isFull()) {
        std::cerr << "Stack Overflow \n";
        return;
    }
    this->top++;
    this->items[this->top] = item;
}

template <typename T, int MAX>
T Stack<T, MAX>::pop() {
    T item{};
    if (isEmpty()) {
        std::cerr << "Stack Underflow \n";
        return item;
    }
    item = this->items[this->top];
    this->top--;
    return item;
}

template <typename T, int MAX>
bool Stack<T, MAX>::isEmpty() {
    return (this->top < 0);
}

template <typename T, int MAX>
bool Stack<T, MAX>::isFull() {
    if (this->top >= (MAX - 1))
        return true;
    else
        return false;
}