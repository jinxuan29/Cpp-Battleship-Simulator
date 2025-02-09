/**********|**********|**********|
Program: Queue.h

Course: Object Oriented Programing and Data Structure 
Trimester: 2410
Name: Yen Jin Xuan
ID: 242UC243R3
Lecture Section: TC
Tutorial Section: TT1L
Email: yen.jin.xuan@student.mmu.edu.my
Phone: 01633131910

Course: Object Oriented Programing and Data Structure 
Trimester: 2410
Name: Nishant A/L Kesavan 
ID: 241UC2407W
Lecture Section: TC1L
Tutorial Section: TT1L
Email: NISHANT.KESAVAN@student.mmu.edu.my
Phone: 019-8960477

Course: Object Oriented Programing and Data Structure 
Trimester: 2410
Name: Raveen A/L PARAMASIWAM 
ID: 241UC24180
Lecture Section: TC1L
Tutorial Section: TT1L
Email: RAVEEN.AL.PARAMASIWAM@student.mmu.edu.my
Phone: 017-6476584
**********|**********|**********/



#pragma once
#include <iostream>
#include <stdexcept>
#include "Logger.h"

template <typename T>
class Queue
{
private:
  struct Node
  {
    T data;
    Node *next;
    Node(const T &value) : data(value), next(nullptr) {}
  };

  Node *front;
  Node *rear;
  int size;

public:
  Queue() : front(nullptr), rear(nullptr), size(0) {}

  ~Queue()
  {
    while (front)
    {
      Node *temp = front;
      front = front->next;
      delete temp;
    }
  }

  // Add an element to the queue
  void enqueue(const T &value)
  {
    Node *newNode = new Node(value);
    if (!rear)
    {
      front = rear = newNode;
    }
    else
    {
      rear->next = newNode;
      rear = newNode;
    }
    size++;
  }

  // Remove an element from the queue
  void dequeue()
  {
    if (!front)
    {
      throw std::out_of_range("Queue is empty");
    }

    Node *temp = front;
    front = front->next;
    if (!front)
    {
      rear = nullptr;
    }
    delete temp;
    size--;
  }

  // Get the front element of the queue
  T peek() const
  {
    if (!front)
    {
      throw std::out_of_range("Queue is empty");
    }
    return front->data;
  }

  // Return the element at a specific index without removing it
  T peekAt(int index) const
  {
    if (index < 0 || index >= size)
    {
      throw std::out_of_range("Index out of range");
    }
    Node *current = front;
    for (int i = 0; i < index; i++)
    {
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
  void print() const
  {
    Node *current = front;
    while (current)
    {
      Logger().logEvent(current->data->getShipName() + " ");
      std::cout << current->data->getShipName() << " ";
      current = current->next;
    }
    std::cout << "\n";
  }
};