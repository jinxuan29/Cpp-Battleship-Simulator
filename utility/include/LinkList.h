#pragma once
#include "../../ships/shipType/include/Ship.h"
#include "Logger.h"
#include "Queue.h"
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <utility>

class Battlefield;

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
  int size;

public:
  LinkList() : head(nullptr), tail(nullptr), size(0) {}

  ~LinkList() {
    Node *current = head;
    while (current != nullptr) {
      Node *next = current->next;
      delete current;       // Delete the Node
      current = next;
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

  T get(int position) const {
    if (position >= size) {
      throw std::out_of_range("Position out of range");
    }

    Node *current = head;
    for (int i = 0; i < position; i++) {
      current = current->next;
    }

    return current->data;
  }

  void remove(int position) {
    if (position >= size) {
      throw std::out_of_range("Position out of range");
    }

    Node *current = head;
    for (int i = 0; i < position; i++) {
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

      Logger logger;
      logger.logEvent("Symbol: " + current->data->getSymbol()); // Log symbol
                                                                //
      logger.logEvent("Ship Type: " +
                      current->data->getShipType()); // Log ship type
      logger.logEvent("Ship Position: ");
      std::string position =
          "Position: (" +
          std::to_string(current->data->getPosition().getXValuePosition()) +
          ", " +
          std::to_string(current->data->getPosition().getYValuePosition()) +
          ")";
      logger.logEvent(position); // Log position

      logger.logEvent(
          "Ship IsDestroyed: " +
          std::to_string(
              current->data->getIsDestroyed())); // Log if ship is destroyed
      logger.logEvent("Ship Name: " +
                      current->data->getShipName()); // Log ship name
      std::cout << "Symbol: " << current->data->getSymbol() << " " << std::endl;
      std::cout << "Ship Type: " << current->data->getShipType() << std::endl;
      std::cout << "Ship Position: ";
      current->data->getPosition().printXYValue();
      std::cout << std::endl;
      std::cout << "Ship IsDestroyed:" << current->data->getIsDestroyed()
                << std::endl;
      std::cout << "Ship Name: " << current->data->getShipName() << std::endl;
      std::cout << "Ship Lives: " << current->data->getLives() << std::endl;
      current = current->next;
    }
    std::cout << "\n";
  }

  void runShip(Battlefield &battlefield) {
    Node *current = head;
    while (current) {
      current->data->runShip(battlefield);
      Ship *ship2 = current->data->upgradeShip();
      if (ship2) {
        current->data = ship2;
      }
      current = current->next;
    }
    std::cout << "\n";
  }

  int getSize() const { return size; }
};
