#include <iostream>
#include <stdexcept>

template<typename T>
class StackBasedOnArray {
private:
    int* stackArray;
    int capacity;
    int top;

public:
    // Конструктор инициализации
    StackBasedOnArray(int size = 10) : capacity(size), top(-1) {
        stackArray = new int[capacity];
    }

    // Конструктор копирования
    StackBasedOnArray(const StackBasedOnArray& other) : capacity(other.capacity), top(other.top) {
        stackArray = new int[capacity];
        for (int i = 0; i <= top; ++i) {
            stackArray[i] = other.stackArray[i];
        }
    }

    // Конструктор перемещения
    StackBasedOnArray(StackBasedOnArray&& other) noexcept : stackArray(other.stackArray), capacity(other.capacity), top(other.top) {
        other.stackArray = nullptr;
        other.capacity = 0;
        other.top = -1;
    }

    // Деструктор
    ~StackBasedOnArray() {
        delete[] stackArray;
    }

    StackBasedOnArray& operator=(const StackBasedOnArray& other) {
        if (this != &other) {
            delete[] stackArray;
            capacity = other.capacity;
            top = other.top;
            stackArray = new T[capacity];
            for (int i = 0; i <= top; ++i) {
                stackArray[i] = other.stackArray[i];
            }
        }
        return *this;
    }

    StackBasedOnArray& operator=(StackBasedOnArray&& other) noexcept {
        if (this != &other) {
            delete[] stackArray;
            stackArray = other.stackArray;
            capacity = other.capacity;
            top = other.top;
            other.stackArray = nullptr;
            other.capacity = 0;
            other.top = -1;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const StackBasedOnArray& stack) {
        for (int i = 0; i <= stack.top; ++i) {
            os << stack.stackArray[i] << " ";
        }
        return os;
    }

    int GetSize() const {
        return top + 1;
    }

    bool Push(const T& element) {
        if (top == capacity - 1) {
            return false;
        }
        stackArray[++top] = element;
        return true;
    }

    bool Pop(T& element) {
        if (top == -1) {
            return false;
        }
        element = stackArray[top--];
        return true;
    }

    bool Peek(T& element) const {
        if (top == -1) {
            return false;
        }
        element = stackArray[top];
        return true;
    }
};