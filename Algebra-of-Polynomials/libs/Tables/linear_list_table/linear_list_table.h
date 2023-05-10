//#pragma once
//#include "base.h"
//#include "Core/clist/CList.h"
//#ifndef LINEAR_TABLE_H
//#define LINEAR_TABLE_H
//#include <iterator>
//#include "base.h"
//template <class T>
//class CNode {
//    T data;
//    CNode* next;
//public:
//    CNode() : next(nullptr) {}
//    CNode(T& _data) {
//        data = _data;
//        next = nullptr;
//    }
//
//    void setNext(CNode* _next) {
//        next = _next;
//    }
//
//    void print() {
//        std::cout << data << " -> ";
//    }
//
//    CNode* getNext() {
//        return next;
//    }
//
//    T& getData() {
//        return data;
//    }
//};
//template <class T>
//class CList {
//    CNode<T>* head;
//    size_t size;
//public:
//    class Iterator : public std::iterator<std::forward_iterator_tag, T> {
//        CNode<T>* ptr;
//
//    public:
//        Iterator(CNode<T>* p = nullptr) : ptr(p) {}
//
//        Iterator& operator++() {
//            ptr = ptr->getNext();
//            return *this;
//        }
//
//        Iterator operator++(int) {
//            Iterator tmp(*this);
//            ++(*this);
//            return tmp;
//        }
//
//        bool operator==(const Iterator& other) const {
//            return ptr == other.ptr;
//        }
//
//        bool operator!=(const Iterator& other) const {
//            return !(*this == other);
//        }
//
//        T& operator*() const {
//            return ptr->getData();
//        }
//    };
//
//    CList() : head(nullptr), size(0) {}
//
//    ~CList() {
//        clear();
//    }
//
//    bool empty() const {
//        return head == nullptr;
//    }
//
//    void clear() {
//        while (!empty()) {
//            pop_front();
//        }
//    }
//
//    void copy(const CList& obj) {
//        clear();
//        CNode<T>* tempNode = obj.head;
//        for (int i = 0; i < obj.size && tempNode != nullptr; i++) {
//            push_back(tempNode->getData());
//            tempNode = tempNode->getNext();
//        }
//        size = obj.size;
//    }
//
//    void push_back(T _data) {
//        CNode<T>* new_node = new CNode<T>(_data);
//        if (empty()) {
//            head = new_node;
//        }
//        else {
//            CNode<T>* tempNode = head;
//            while (tempNode->getNext() != nullptr) {
//                tempNode = tempNode->getNext();
//            }
//            tempNode->setNext(new_node);
//        }
//        size++;
//    }
//
//    void push_front(T _data) {
//        CNode<T>* new_node = new CNode<T>(_data);
//        if (empty()) {
//            head = new_node;
//        }
//        else {
//            new_node->setNext(head);
//            head = new_node;
//        }
//        size++;
//    }
//
//    T remove(int _i) {
//        size_t len = size;
//        if (_i < 0 || _i >= len) {
//            throw std::out_of_range("Index out of range");
//        }
//        T tempType;
//        if (_i == 0) {
//            tempType = pop_front();
//        }
//        else if (_i == size - 1) {
//            tempType = pop_back();
//        }
//        else {
//            CNode<T>* _pos2 = head;
//            for (int i = 0; i < _i - 1; i++) {
//                _pos2 = _pos2->getNext();
//            }
//            CNode<T>* toDelete = _pos2->getNext();
//            _pos2->setNext(toDelete->getNext
//                CNode<T>*toDelete = _pos2->getNext();
//            _pos2->setNext(toDelete->getNext());
//            tempType = toDelete->getData();
//            delete toDelete;
//        }
//        size--;
//        return tempType;
//    }
//
//    T pop_front() {
//        if (empty()) {
//            throw std::runtime_error("List is empty");
//        }
//        CNode<T>* tempNode = head;
//        T tempType = tempNode->getData();
//        head = head->getNext();
//        delete tempNode;
//        size--;
//        return tempType;
//    }
//
//    T pop_back() {
//        if (empty()) {
//            throw std::runtime_error("List is empty");
//        }
//        if (size == 1) {
//            return pop_front();
//        }
//        CNode<T>* tempNode = head;
//        while (tempNode->getNext()->getNext() != nullptr) {
//            tempNode = tempNode->getNext();
//        }
//        CNode<T>* lastNode = tempNode->getNext();
//        T tempType = lastNode->getData();
//        tempNode->setNext(nullptr);
//        delete lastNode;
//        size--;
//        return tempType;
//    }
//
//    size_t getSize() const {
//        return size;
//    }
//
//    Iterator begin() const {
//        return Iterator(head);
//    }
//
//    Iterator end() const {
//        return Iterator(nullptr);
//    }
//};
//#endif
