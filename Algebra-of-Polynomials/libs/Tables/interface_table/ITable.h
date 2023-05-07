#include "Core/polynomial/polynomial.h"

template <class TKey, class TValue>
struct TableNode {
    TKey key;
    TValue value;

    bool operator == (const TableNode& record) const {
        return this->key == record.key && this->value == record.value;
    }
};

template <class TKey, class TValue>
class Table {
public:
    virtual void add(const TKey, const TValue) = 0;
    virtual void remove(const TKey) = 0;
    virtual bool contains(const TKey) const = 0;
    virtual Polynomial get(const TKey) const = 0;
    virtual CList<Polynomial> getAll() const = 0;
    virtual void clear() = 0;
};
