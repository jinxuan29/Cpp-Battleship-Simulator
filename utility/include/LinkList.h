#pragma once
#include "../../game/include/Battlefield.h"
#include "../../ships/shipType/include/Ship.h"
#include "Logger.h"
#include "Queue.h"
#include <cstddef>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <utility>

template <typename T> class LinkList {
private:
  struct Node {
    Ship *data;
    Node *prev;
    Node *next;
    Node(Ship *value) : prev(nullptr), next(nullptr) { data = value; }
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
      delete current; // Delete the Node
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

  void RunShip(Battlefield &battlefield, Ship **&shipArray, int arraySize) {
    if (head == nullptr) {
      std::cout << "Error: RunShip called on an empty linked list!\n";
      return;
    }

    Node *current = head;
    while (current) {

      if (!current) {
        std::cout << "Error: Encountered null current pointer\n";
        break;
      }

      if (current->data->getLives() < 1 && current->data->getIsDestroyed()) {
        std::cout << "Error: Ship Broken and Shold not be in link list";
        break;
      }

      // std::cout << current->data << "----1------\n";

      if (current->data) {
        try {
          current->data->runShip(battlefield);
          //       std::cout << "----1.5------\n";

          Ship *ship2 = current->data->upgradeShip();

          if (ship2 != nullptr) {
            std::string currentShipName = current->data->getShipName();
            battlefield.printBattlefieldShipArray();
            std::cout << "\n after \n";
            bool check = battlefield.replaceShipInBattlefieldShipByName(
                currentShipName, ship2);
            battlefield.printBattlefieldShipArray();
            bool check1 = false;
            for (int i = 0; i < arraySize; ++i) {
              if (shipArray[i]->getShipName() == current->data->getShipName()) {
                shipArray[i] = ship2;
                // std::cout << "Updated shipArray[" << i << "] to "
                //           << ship2->getShipName() << "\n";
                check1 = true;
                break;
              }
            };
            if (check && check1) {
              // std::cout << "-------------1.7----------- \n";
              battlefield.printBattlefieldShipArray();
              if (current->data != ship2 && current->data != nullptr) {
                // std::cout << "-------------1.8----------- \n";
                battlefield.printBattlefieldShipArray();
                delete current->data;
                // std::cout << "after delete data \n";
                battlefield.printBattlefieldShipArray();
              }
              // std::cout << "-------------1.9----------- \n";
              battlefield.printBattlefieldShipArray();
              current->data = ship2;

              std::cout << "Successfully upgraded " << currentShipName << " to "
                        << ship2->getShipName() << "\n";
            } else {
              std::cout << "Failed to replace ship in battlefield: "
                        << currentShipName << "\n";
            }
          }
        } catch (const std::exception &e) {
          std::cout << "Error during ship operations: " << e.what() << "\n";
        }
      } else {
        std::cout
            << "Warning: Encountered a null data pointer in the linked list.\n";
      }

      current = current->next;
      //     std::cout << "----2------\n";
    }

    std::cout << "\n";
  }

  int getSize() const { return size; }
};
