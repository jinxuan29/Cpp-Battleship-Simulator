#pragma once
#include "../../ships/shipType/include/Ship.h"
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>

template <typename T> class LinkList {
private:
  struct Node {
    T data;
    Node *prev;
    Node *next;
    Node(const T &value) : data(value), prev(nullptr), next(nullptr) {}
  };

  Node *head;
  Node *tail;
  size_t size;

public:
  LinkList() : head(nullptr), tail(nullptr), size(0) {}

  ~LinkList() {
    while (head) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }

  void push_back(const T &value) {
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

  void push_front(const T &value) {
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

  void remove(size_t position) {
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

// only works for ship class 

  // Generic print method
  void print() const {
    Node *current = head;
    while (current) {
      std::cout << "Symbol: "<< current->data->getSymbol()<< " " << std::endl;
      std::cout << "Ship Type: " << current->data->getShipType() << std::endl;
      std::cout << "Ship Position: ";
      current->data->getPosition().printXYValue();
      std::cout << std::endl;
      std::cout <<"Ship IsDestroyed:" << current->data->getIsDestroyed() << std::endl;
      current = current->next;
    }
    std::cout << "\n";
  }

  void runShip(){
    Node *current = head;
    while (current) {
      current->data->runShip(); 
      current = current->next;
    }
    std::cout << "\n";
  }

  size_t getSize() const { return size; }
};
