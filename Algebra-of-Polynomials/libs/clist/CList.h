#include <list>
#include <iostream>
template <class T> class CNode;
template <class T> class CList;
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

    friend class CList<T>;
};

template <class T>
class CList {
    CNode<T>* head;
    CNode<T>* tail;
public:
    size_t size;
    CList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    bool empty() {
        return head == nullptr;
    }
    void clr() {
        while (head != nullptr)
            pop_front();
    }
    void cpy(const CList& obj) {
        clr();
        CNode<T>* tempNode = obj.head;

        for (int i = 0; i < obj.size && tempNode->next != nullptr; i++)
        {
            push_back(tempNode->data);
            tempNode = tempNode->next;
        }
        if (obj.size != 0 && tempNode == obj.tail) {
            push_back(tempNode->data);
        }
        size = obj.size;
    }
    void push_back(T _data) {
        CNode<T>* new_node = new CNode<T>(_data);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }
    void push_front(T _data) {
        CNode<T>* new_node = new CNode<T>(_data);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        }
        else {
            new_node->next = head;
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
            return this->pop_back();
        }
        else if (_i == size - 1) {
            size--;
            return this->pop_front();
        }
        else {
            CNode<T>* _pos = head;
            CNode<T>* _pos2 = head;
            for (int i = 0; i < _i - 1; i++) {
                _pos2 = _pos2->next;
            }
            for (int i = 0; i < _i; i++) {
                _pos = _pos->next;
            }
            _pos2->next = _pos->next;
            CNode<T>* toRet = _pos;
            T tempType = toRet->data;
            delete _pos;
            size--;
            return tempType;
        }
    }
    void insert(int_index, T _data) {
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
            for (int i = 0; i < _index - 1; i++)
                tempNode = tempNode->next;
            new_node->next = tempNode->next;
            tempNode->next = new_node;
            size++;
        }
    }
    T pop_front() {
        if (empty())
            throw("can't pop from empty list");
        CNode<T>* toRet = head;
        T tempType = toRet->data;
        head = head->next;
        delete toRet;
        size--;
        return tempType;
    }
    T pop_back() {
        if (empty())
            throw("can't pop from empty list");
        CNode<T>* toRet = tail;
        T tempType = toRet->data;
        CNode<T>* tempNode = head;
        while (tempNode->next != tail)
            tempNode = tempNode->next;
        tail = tempNode;
        tail->next = nullptr;
        delete toRet;
        size--;
        return tempType;
    }
    void print() {
        if (empty())
            return;
        CNode<T>* tempNode = head;
        while (tempNode != nullptr) {
            tempNode->print();
            tempNode = tempNode->next;
        }
        std::cout << "nullptr\n";
    }
};
