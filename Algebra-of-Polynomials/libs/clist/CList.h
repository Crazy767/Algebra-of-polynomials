#pragma once
#include "../base.h"
template <class T>
class CNode {
    T data;
    CNode* next;
public:
    CNode(T _data) {
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
    T getData() {
        return data;
    }
};
template <class T>
class CList {
    CNode<T>* head;
    size_t size;
public:
    CList() {
        head = nullptr;
        size = 0;
    }
    ~CList() {
        clear();
    }
    bool empty() const {
        return head == nullptr;
    }
    void clear() {
        while (head != nullptr)
            pop_front();
    }
    void copy(const CList& obj) {
        clear();
        CNode<T>* tempNode = obj.head;
        for (int i = 0; i < obj.size && tempNode != nullptr; i++)
        {
            push_back(tempNode->getData());
            tempNode = tempNode->getNext();
        }
        size = obj.size;
    }
    void push_back(T _data) {
        CNode<T>* new_node = new CNode<T>(_data);
        if (head == nullptr) {
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
        if (head == nullptr) {
            head = new_node;
        }
        else {
            new_node->setNext(head);
            head = new_node;
        }
        size++;
    }
    T remove(int _i) {
        size_t len = 0;
        len = this->size;
        if (_i < 0 || _i > len - 1)
            throw("can't remove in nullptr");
        if (_i == 0) {
            size--;
            return this->pop_front();
        }
        else if (_i == size - 1) {
            size--;
            return this->pop_back();
        }
        else {
            CNode<T>* _pos = head;
            CNode<T>* _pos2 = head;
            for (int i = 0; i < _i - 1; i++) {
                _pos2 = _pos2->getNext();
            }
            for (int i = 0; i < _i; i++) {
                _pos = _pos->getNext();
            }
            _pos2->setNext(_pos->getNext());
            CNode<T>* toRet = _pos;
            T tempType = toRet->getData();
            delete _pos;
            size--;
            return tempType;
        }
    }
    void insert(int _index, T _data) {
        if (_index < 0 || _index > size)
            throw("can't insert in nullptr");
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

    bool operator==(const CList<T>& list) {
        if (size != list.get_size())
            return false;
        for (int i = 0; i < list.get_size(); i++) {
            auto a = this[i];
            auto b = list[i];
            if (1 != 2)
                return false;
        }
        return true;
    }

    bool operator!=(const CList<T>& list) {
        return !(*this == list);
    }

    size_t get_size() const {
        return size;
    }

    void print() const {
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
};
