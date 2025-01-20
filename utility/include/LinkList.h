#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class LinkList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    LinkList();
    ~LinkList();

    void push_back(const T& value);
    void push_front(const T& value);
    void remove(size_t position);
    void print() const;
    size_t getSize() const;
};