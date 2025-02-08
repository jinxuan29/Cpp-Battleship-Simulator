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

template <typename T>
class LinkList {
private:
    struct Node {
        Ship *data;
        Node *next;
        Node(Ship *value) : data(value), next(nullptr) {}
    };

    Node *head;  // Pointer to the first node
    Node *tail;  // Pointer to the last node
    int size;    // Number of nodes in the list

public:
    // Constructor
    LinkList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~LinkList() {
        Node *current = head;
        while (current != nullptr) {
            Node *next = current->next;
            delete current; // Delete the Node
            current = next;
        }
    }

    // Add a new node to the end of the list
    void push_back(const T &value) {
        Node *newNode = new Node(value);
        if (!head) {
            // If the list is empty, set both head and tail to the new node
            head = tail = newNode;
        } else {
            // Append the new node to the end and update the tail
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Add a new node to the front of the list
    void push_front(const T &value) {
        Node *newNode = new Node(value);
        if (!head) {
            // If the list is empty, set both head and tail to the new node
            head = tail = newNode;
        } else {
            // Insert the new node at the front and update the head
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    // Get the value at a specific position
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

    // Remove a node at a specific position
    void remove(int position) {
        if (position >= size) {
            throw std::out_of_range("Position out of range");
        }

        Node *current = head;
        Node *previous = nullptr;

        // Traverse to the desired position
        for (int i = 0; i < position; i++) {
            previous = current;
            current = current->next;
        }

        // Update pointers
        if (previous) {
            previous->next = current->next;
        } else {
            // Removing the head node
            head = current->next;
        }

        // If removing the tail node, update the tail pointer
        if (current == tail) {
            tail = previous;
        }

        delete current;
        size--;
    }

    // Print the contents of the list
    void print() const {
        Node *current = head;
        while (current) {
            Logger logger;
            logger.logEvent("Symbol: " + std::string(1, current->data->getSymbol()) + " ");
            logger.logEvent("Ship Type: " + current->data->getShipType());
            std::string position =
                "Position: (" +
                std::to_string(current->data->getPosition().getXValuePosition()) +
                ", " +
                std::to_string(current->data->getPosition().getYValuePosition()) +
                ")";
            logger.logEvent(position);
            logger.logEvent(
                "Ship IsDestroyed: " +
                std::to_string(current->data->getIsDestroyed()));
            logger.logEvent("Ship Name: " + current->data->getShipName());
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

    // Run all ships in the list
    void RunShip(Battlefield &battlefield, Ship **&shipArray, int arraySize) {
        if (!head) {
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
                std::cout << "Error: Ship Broken and Should not be in link list";
                break;
            }
            if (current->data) {
                try {
                    current->data->runShip(battlefield);
                    Ship *ship2 = current->data->upgradeShip();
                    if (ship2 != nullptr) {
                        std::string currentShipName = current->data->getShipName();
                        battlefield.printBattlefieldShipArray();
                        //std::cout << "\n after \n";
                        bool check = battlefield.replaceShipInBattlefieldShipByName(
                            currentShipName, ship2);
                        //battlefield.printBattlefieldShipArray();
                        bool check1 = false;
                        for (int i = 0; i < arraySize; ++i) {
                            if (shipArray[i]->getShipName() == current->data->getShipName()) {
                                shipArray[i] = ship2;
                                check1 = true;
                                break;
                            }
                        }
                        if (check && check1) {
                            battlefield.printBattlefieldShipArray();
                            if (current->data != ship2 && current->data != nullptr) {
                                delete current->data;
                            }
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
                std::cout << "Warning: Encountered a null data pointer in the linked list.\n";
            }
            current = current->next;
        }
        std::cout << "\n";
    }

    // Get the size of the list
    int getSize() const { return size; }
};