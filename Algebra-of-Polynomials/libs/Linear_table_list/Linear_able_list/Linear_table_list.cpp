#include "Linear_table_list.h"
using namespace std;
LinearTable::LinearTable() {
    head = nullptr;
    size = 0;
}

LinearTable::~LinearTable() {
    // Удаление всех узлов списка при уничтожении объекта
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinearTable::insert(int value) {
    Node* newNode = createNode(value);

    // Вставка нового узла в начало списка
    newNode->next = head;
    head = newNode;
    size++;
}

void LinearTable::remove(int value) {
    Node* current = head;
    Node* prev = nullptr;

    // Поиск узла с заданным значением
    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        // Удаление найденного узла из списка
        if (prev != nullptr) {
            prev->next = current->next;
        }
        else {
            head = current->next;
        }

        deleteNode(current);
        size--;
    }
}

int LinearTable::getSize() const {
    return size;
}

void LinearTable::display() const {
    Node* current = head;

    std::cout << "Table: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* LinearTable::createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void LinearTable::deleteNode(Node* node) {
    delete node;
}

