#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    size_t size;

public:
    Queue();
    ~Queue();

    void enqueue(const T& value);
    void dequeue();
    T peek() const;
    bool isEmpty() const;
    size_t getSize() const;
    void print() const;
};
