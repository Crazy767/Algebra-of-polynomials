#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "monomial.h"
template <class Type> class CNode;
template <class Type> class CList;
template <class Type>
class CNode {
	Type data;
	CNode* next;

public:
	CNode(Type _data) {
		data = _data;
		next = nullptr;
	}
	void setNext(CNode* _next) {
		next = _next;
	}
	void print() {
		std::cout << data << " -> ";
	}

	friend class CList<Type>;
};
template <class Type>
class CNode {
    Type data;
    CNode* next = nullptr;
public:
    CNode(Type _data) : data(_data) {}
    void setNext(CNode* _next) { next = _next; }
    void print() { std::cout << data << " -> "; }
    friend class CList<Type>;
};

template <typename Type>
class CList {
    CNode<Type>* head = nullptr;
    CNode<Type>* tail = nullptr;
    size_t size = 0;
public:
    CList() = default;
    bool isEmpty() { return head == nullptr; }
    void clear() {
        while (head != nullptr)
            pop_front();
    }
    void copy(const CList& obj) {
        clear();
        if (obj.isEmpty())
            return;
        head = new CNode<Type>(obj.head->data);
        CNode<Type>* tempNode = obj.head->next;
        CNode<Type>* currNode = head;
        while (tempNode != nullptr) {
            CNode<Type>* newNode = new CNode<Type>(tempNode->data);
            currNode->next = newNode;
            currNode = newNode;
            tempNode = tempNode->next;
        }
        tail = currNode;
        size = obj.size;
    }
    void push_back(const Type& _data) {
        CNode<Type>* newNode = new CNode<Type>(_data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void push_front(const Type& _data) {
        CNode<Type>* newNode = new CNode<Type>(_data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    Type remove(int _i) {
        if (_i < 0 || _i >= size)
            throw std::out_of_range("index is out of range");

        if (_i == 0)
            return pop_front();

        if (_i == size - 1)
            return pop_back();

        CNode<Type>* currNode = head;
        CNode<Type>* prevNode = nullptr;
        for (int i = 0; i < _i; i++) {
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = currNode->next;
        Type data = currNode->data;
        delete currNode;
        size--;
        return data;
    }
    void insert(int _i, const Type& _data) {
        if (_i < 0 || _i > size)
            throw std::out_of_range("index is out of range");

        if (_i == 0) {
            push_front(_data);
            return;
        }

        if (_i == size) {
            push_back(_data);
            return;
        }

        CNode<Type>* currNode = head;
        CNode<Type>* prevNode = nullptr;
        for (int i = 0; i < _i; i++) {
            prevNode = currNode;
            currNode = currNode->next;
        }
        CNode<Type>* newNode = new CNode<Type>(_data);
        prevNode->next = newNode;
        newNode->next = currNode;
        size++;
    }
    Type pop_front() {
        if (head == nullptr) {
            throw std::out_of_range("list is empty");
        }
        CNode<Type>* toRet = head;
        Type tempType = toRet->data;
        if (head != nullptr) {
            CNode<Type>* toDel = head;
            head = head->next;
            delete toDel;
            size--;
            if (head == nullptr) {
                tail = nullptr;
            }
            return tempType;
        }
    }
    Type pop_back() {
        if (tail == nullptr) {
            throw std::out_of_range("list is empty");
        }
        CNode<Type>* toRet = tail;
        Type temp = toRet->data;
        if (head != tail) {
            CNode<Type>* toDel = head;
            while (toDel->next != tail) {
                toDel = toDel->next;
            }
            delete tail;
            tail = toDel;
        }
        else {
            head = nullptr;
            tail = nullptr;
        }
        size--;
        return temp;
    }

class Polynomial {
public:
    Polynomial() {}
    Polynomial(const Polynomial& other);
    Polynomial(CList<Monomial> list);
    ~Polynomial() {}

    csharp

        std::string toString();

    bool operator==(const Polynomial& other) const;
    bool operator!=(const Polynomial& other) const;
    double findResult(double x, double y, double z) const;
    void Parse(std::string str);

    Polynomial operator+(const Monomial& monomial) const;
    Polynomial operator-(const Monomial& monomial) const;
    Polynomial operator*(const Monomial& monomial) const;
    Polynomial operator/(const Monomial& monomial) const;

    Polynomial& operator=(const Polynomial& other);

    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
    Polynomial operator*(double coefficient) const;
    Polynomial operator/(const Polynomial& other) const;

    Polynomial getDerivative() const;

    CList<Monomial> list;

    friend class CList;

};

#endif
