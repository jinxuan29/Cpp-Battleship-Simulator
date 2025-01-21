#include "../include/Queue.h"
// had to change to header file only later on..
template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), size(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (front) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    Node* newNode = new Node(value);
    if (!rear) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

template <typename T>
void Queue<T>::dequeue() {
    if (!front) {
        throw std::out_of_range("Queue is empty");
    }

    Node* temp = front;
    front = front->next;
    if (!front) {
        rear = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
T Queue<T>::peek() const {
    if (!front) {
        throw std::out_of_range("Queue is empty");
    }
    return front->data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
size_t Queue<T>::getSize() const {
    return size;
}

template <typename T>
void Queue<T>::print() const {
    Node* current = front;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}