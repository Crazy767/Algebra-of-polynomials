#pragma once
#ifndef LINEAR_TABLE_H
#define LINEAR_TABLE_H

struct Node {
    int data;
    Node* next;
};

class LinearTable {
public:
    LinearTable();  // Конструктор по умолчанию
    ~LinearTable(); // Деструктор
    void display() const;             
private:
    Node* head;   // Указатель на начало списка
    int size;     // Размер таблицы

    Node* createNode(int value);      // Создание нового узла
    void deleteNode(Node* node);      // Удаление узла
};

#endif
