#pragma once
#include "Core/polynomial/polynomial.h"

template <class TKey, class TValue>
struct TableNode {
    TKey key;
    TValue value;

    TableNode() : key(key), value(value) {};

    TableNode(const TKey& key) : key(key) {}

    TableNode(const TKey& key, const TValue& value) : key(key), value(value) {}

    bool operator == (const TableNode& record) const {
        return this->key == record.key;
    }
    bool operator > (TableNode& record) {
        return this->key > record.key;
    }

    bool operator < (TableNode& record) {
        return this->key < record.key;
    }
};


template <class TKey, class TValue>
class Table {
public:
    virtual void add(const TKey, const TValue) = 0;
    virtual void remove(TKey) = 0;
    virtual bool contains(TKey) = 0;
    virtual TValue get(TKey) = 0;
    virtual CList<TableNode<TKey, TValue>>& getAll() = 0;
    virtual void clear() = 0;
};
