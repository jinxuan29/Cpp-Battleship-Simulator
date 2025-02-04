#include <iostream>
#include <stdexcept>

template <typename T> class Queue {
private:
  struct Node {
    T data;
    Node *next;
    Node(const T &value) : data(value), next(nullptr) {}
  };

  Node *front;
  Node *rear;
  int size;

public:
  Queue() : front(nullptr), rear(nullptr), size(0) {}

  ~Queue() {
    while (front) {
      Node *temp = front;
      front = front->next;
      delete temp;
    }
  }

  // Add an element to the queue
  void enqueue(const T &value) {
    Node *newNode = new Node(value);
    if (!rear) {
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
    size++;
  }

  // Remove an element from the queue
  void dequeue() {
    if (!front) {
      throw std::out_of_range("Queue is empty");
    }

    Node *temp = front;
    front = front->next;
    if (!front) {
      rear = nullptr;
    }
    delete temp;
    size--;
  }

  // Get the front element of the queue
  T peek() const {
    if (!front) {
      throw std::out_of_range("Queue is empty");
    }
    return front->data;
  }

  // Return the element at a specific index without removing it
  T peekAt(int index) const {
    if (index < 0 || index >= size) {
      throw std::out_of_range("Index out of range");
    }
    Node *current = front;
    for (int i = 0; i < index; i++) {
      current = current->next;
    }
    return current->data;
  }

  // Check if the queue is empty
  bool isEmpty() const { return size == 0; }

  // Get the size of the queue
  int getSize() const { return size; }

  // only works for Ship class

  // Print the queue
  void print() const {
    Node *current = front;
    while (current) {
      std::cout << current->data->getShipName() << " ";
      current = current->next;
    }
    std::cout << "\n";
  }
};