#include <iostream>

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
};

template <class T>
class CList {
    CNode<T>* head = nullptr;
    CNode<T>* tail = nullptr;
    size_t size = 0;
public:
    CList() = default;
    bool isEmpty() { return head == nullptr; }
    void clear() {
        while (head != nullptr)
            pop_front();
    }

    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("index is out of range");
        CNode<T>* currNode = head;
        for (int i = 0; i < index; i++) {
            currNode = currNode->next;
        }
        return currNode->data;
    }

    bool operator==(CList& other) {
        if (size != other.size)
            return false;

        CNode<T>* currNode = head;
        CNode<T>* otherNode = other.head;
        while (currNode != nullptr) {
            if (currNode->data != otherNode->data)
                return false;

            currNode = currNode->next;
            otherNode = otherNode->next;
        }

        return true;
    }

    void copy(const CList& obj) {
        clear();
        if (obj.isEmpty())
            return;
        head = new CNode<T>(obj.head->data);
        CNode<T>* tempNode = obj.head->next;
        CNode<T>* currNode = head;
        while (tempNode != nullptr) {
            CNode<T>* newNode = new CNode<T>(tempNode->data);
            currNode->next = newNode;
            currNode = newNode;
            tempNode = tempNode->next;
        }
        tail = currNode;
        size = obj.size;
    }
    void push_back(const T& _data) {
        CNode<T>* newNode = new CNode<T>(_data);
        if (isEmpty()) {
            CList
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
        CNode<T>* newNode = new CNode<T>(_data);
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
    T remove(int _i) {
        if (_i < 0 || _i >= size)
            throw std::out_of_range("index is out of range");

        if (_i == 0)
            return pop_front();

        if (_i == size - 1)
            return pop_back();

        CNode<T>* currNode = head;
        CNode<T>* prevNode = nullptr;
        for (int i = 0; i < _i; i++) {
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = currNode->next;
        T data = currNode->data;
        delete currNode;
        size--;
        return data;
    }
    void insert(int _i, const T& _data) {
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

        CNode<T>* currNode = head;
        CNode<T>* prevNode = nullptr;
        for (int i = 0; i < _i; i++) {
            prevNode = currNode;
            currNode = currNode->next;
        }
        CNode<T>* newNode = new CNode<T>(_data);
        prevNode->next = newNode;
        newNode->next = currNode;
        size++;
    }
    T pop_front() {
        if (head == nullptr) {
            throw std::out_of_range("list is empty");
        }
        CNode<T>* toRet = head;
        T tempType = toRet->data;
        if (head != nullptr) {
            CNode<T>* toDel = head;
            head = head->next;
            delete toDel;
            size--;
            if (head == nullptr) {
                tail = nullptr;
            }
            return tempType;
        }
    }
    T pop_back() {
        if (tail == nullptr) {
            throw std::out_of_range("list is empty");
        }
        CNode<T>* toRet = tail;
        T temp = toRet->data;
        if (head != tail) {
            CNode<T>* toDel = head;
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

    size_t get_size() { return size; }
};