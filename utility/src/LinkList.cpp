#include "../include/LinkList.h"

template <typename T>
LinkList<T>::LinkList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T> LinkList<T>::~LinkList() {
  while (head) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

template <typename T> void LinkList<T>::push_back(const T &value) {
  Node *newNode = new Node(value);
  if (!head) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  size++;
}

template <typename T> void LinkList<T>::push_front(const T &value) {
  Node *newNode = new Node(value);
  if (!head) {
    head = tail = newNode;
  } else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  size++;
}

template <typename T> void LinkList<T>::remove(size_t position) {
  if (position >= size) {
    throw std::out_of_range("Position out of range");
  }

  Node *current = head;
  for (size_t i = 0; i < position; i++) {
    current = current->next;
  }

  if (current->prev) {
    current->prev->next = current->next;
  } else {
    head = current->next;
  }

  if (current->next) {
    current->next->prev = current->prev;
  } else {
    tail = current->prev;
  }

  delete current;
  size--;
}

// only works for ship dispite being template class cuz it will call the
// getShipName function bad code will change later on
template <typename T> void LinkList<T>::print() const {
  Node *current = head;
  while (current) {
    std::cout << current->data->getShipName() << " ";
    current = current->next;
  }
  std::cout << "\n";
}

template <typename T> size_t LinkList<T>::getSize() const { return size; }