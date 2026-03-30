#ifndef STACK
#define STACK

#include <iostream>
#include <stdexcept>

template <typename Temp>
class Stack
{
private:
    Temp* arr;
    int capacity;
    int topIndex;

public:
    Stack<Temp>(int cap = 100)
    {
        if (cap <= 0) throw std::out_of_range("Capacity cannot be less than or equal to 0");
        capacity = cap;
        arr = new Temp[capacity];
        topIndex = -1;
    }

    ~Stack() { delete[] arr; }

    inline bool isEmpty() const { return topIndex == -1; }

    inline bool isFull() const { return topIndex == capacity - 1; }

    void push(Temp x)
    {
        if (topIndex >= capacity - 1) throw std::overflow_error("Stack overflow");
        arr[++topIndex] = x;
    }

    Temp top() const
    {
        if (isEmpty()) throw std::out_of_range("Stack is empty");
        return arr[topIndex];
    }

    void pop()
    {
        if (isEmpty()) throw std::out_of_range("Stack is empty");
        topIndex--;
    }
};

#endif /* STACK */
