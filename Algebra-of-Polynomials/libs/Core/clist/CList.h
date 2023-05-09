#pragma once
#include <iterator>
#include "base.h"
template <class T>
class CNode {
    T data;
    CNode* next;
public:
    CNode() : next(nullptr) {}
    CNode(T& _data) {
        data = _data;
        next = nullptr;
    }
    void setNext(CNode* _next) {
        next = _next;
    }
    void print() {
        std::cout << data << " -> ";
    }
    CNode* getNext() {
        return next;
    }
    T& getData() {
        return data;
    }
};
template <class T>
class CList {
    CNode<T>* head;
    size_t size;

public:
    class Iterator : public std::iterator<std::forward_iterator_tag, T> {
        CNode<T>* ptr;
    public:
        Iterator(CNode<T>* p = nullptr) : ptr(p) {}

        Iterator& operator++() {
            ptr = ptr->getNext();
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

        T& operator*() const {
            return ptr->getData();
        }
    };


    CList() : head(nullptr), size(0) {}

    ~CList() { }

    bool empty() const {
        return head == nullptr;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void copy(const CList& obj) {
        clear();
        CNode<T>* tempNode = obj.head;
        for (int i = 0; i < obj.size && tempNode != nullptr; i++) {
            push_back(tempNode->getData());
            tempNode = tempNode->getNext();
        }
        size = obj.size;
    }

    void push_back(T _data) {
        CNode<T>* new_node = new CNode<T>(_data);
        if (empty()) {
            head = new_node;
        }
        else {
            CNode<T>* tempNode = head;
            while (tempNode->getNext() != nullptr) {
                tempNode = tempNode->getNext();
            }
            tempNode->setNext(new_node);
        }
        size++;
    }

    void push_front(T _data) {
        CNode<T>* new_node = new CNode<T>(_data);
        if (empty()) {
            head = new_node;
        }
        else {
            new_node->setNext(head);
            head = new_node;
        }
        size++;
    }

    T remove(int _i) {
        size_t len = size;
        if (_i < 0 || _i >= len) {
            throw std::out_of_range("Index out of range");
        }
        T tempType;
        if (_i == 0) {
            tempType = pop_front();
        }
        else if (_i == size - 1) {
            tempType = pop_back();
        }
        else {
            CNode<T>* _pos2 = head;
            for (int i = 0; i < _i - 1; i++) {
                _pos2 = _pos2->getNext();
            }
            CNode<T>* toDelete = _pos2->getNext();
            _pos2->setNext(toDelete->getNext());
            tempType = toDelete->getData();
            delete toDelete;
            size--;
        }
        return tempType;
    }

    void insert(int _index, T _data) {
        if (_index < 0 || _index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (_index == 0) {
            push_front(_data);
        }
        else if (_index == size) {
            push_back(_data);
        }
        else {
            CNode<T>* new_node = new CNode<T>(_data);
            CNode<T>* tempNode = head;
            for (int i = 0; i < _index - 1; i++) {
                tempNode = tempNode->getNext();
            }
            new_node->setNext(tempNode->getNext());
            tempNode->setNext(new_node);
            size++;
        }
    }
    T pop_front() {
        if (head == nullptr)
            throw("list is empty");
        CNode<T>* toDelete = head;
        T tempType = toDelete->getData();
        head = head->getNext();
        delete toDelete;
        size--;
        return tempType;
    }

    T pop_back() {
        if (head == nullptr)
            throw("list is empty");
        if (size == 1) {
            T tempType = head->getData();
            delete head;
            head = nullptr;
            size--;
            return tempType;
        }
        else {
            CNode<T>* tempNode = head;
            while (tempNode->getNext()->getNext() != nullptr) {
                tempNode = tempNode->getNext();
            }
            CNode<T>* toDelete = tempNode->getNext();
            T tempType = toDelete->getData();
            delete toDelete;
            tempNode->setNext(nullptr);
            size--;
            return tempType;
        }
    }


    T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        CNode<T>* tempNode = head;
        for (int i = 0; i < index; i++) {
            tempNode = tempNode->getNext();
        }
        return tempNode->getData();
    }


    bool operator==(const CList<T>& list) const {
        if (size != list.size)
            return false;
        CNode<T>* node1 = head;
        CNode<T>* node2 = list.head;
        while (node1 != nullptr) {
            if (node1->getData() != node2->getData())
                return false;
            node1 = node1->getNext();
            node2 = node2->getNext();
        }
        return true;
    }

    bool operator!=(const CList<T>& list) const {
        return !(*this == list);
    }

    size_t get_size() const {
        return size;
    }

    void print() {
        if (head == nullptr) {
            std::cout << "empty list";
            return;
        }
        CNode<T>* tempNode = head;
        while (tempNode != nullptr) {
            tempNode->print();
            tempNode = tempNode->getNext();
        }
        std::cout << "nullptr";
    }

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }
};
