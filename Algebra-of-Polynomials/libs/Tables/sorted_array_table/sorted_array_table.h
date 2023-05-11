#pragma once
#include "base.h"
#include "Tables/interface_table/ITable.h"


template <class TKey, class TValue>
class SortedTable : public Table<TKey, TValue> {
private:
    int factSize;
    int realSize;
    TableNode<TKey, TValue>* table;
public:
    SortedTable();
    ~SortedTable();

    void add(const TKey key, const TValue value) override;
    void remove(TKey key) override;
    bool contains(TKey key) override;
    TValue get(TKey key) override;
    CList<TableNode<TKey, TValue>>& getAll() override;
    void clear() override;
};

template <class TKey, class TValue>
SortedTable<TKey, TValue>::SortedTable() {
    factSize = 2;
    realSize = 0;
    table = new TableNode<TKey, TValue>[factSize];
}

template <class TKey, class TValue>
SortedTable<TKey, TValue>::~SortedTable() {
    delete[] table;
}

template <class TKey, class TValue>
void SortedTable<TKey, TValue>::add(TKey key, TValue value) {
    if (realSize >= factSize - 2) {
        factSize *= 2;

        TableNode<TKey, TValue>* temp_table = new TableNode<TKey, TValue>[factSize];

        for (int i = 0; i < realSize; i++)
            temp_table[i] = table[i];

        delete[] table;
        table = temp_table;
    }
    

    if (realSize == 0)
    {
        table[0].key = key;
        table[0].value = value;
        realSize++;
        return;
    }
    if (table[realSize - 1].key < key)
    {
        table[realSize].key = key;
        table[realSize].value = value;
        realSize++;
        return;
    }
    for (int i = realSize - 1; i >= 0; i--)
    {
        if (table[i].key == key) {
            throw std::logic_error("Key already exists");
        }
        else if (table[i].key < key)
        {
            TableNode<TKey, TValue>* temp_table = new TableNode<TKey, TValue>[factSize];
            for (int j = realSize; j >= 0; j--)
            {
                if (i + 1 == j) 
                {
                    temp_table[j].key = key;
                    temp_table[j].value = value;
                }
                else if (i < j)
                    temp_table[j] = table[j - 1];
                else
                    temp_table[j] = table[j];
            }
            table = temp_table;
            realSize++;
            return;
        }
    }
}

template<class TKey, class TValue>
void SortedTable<TKey, TValue>::remove(TKey key)
{
    if (!contains(key))
        throw std::logic_error("Key not found");

    int i = 0;
    for (; i < realSize; i++) {
        if (table[i].key == key) {
            break;
        }
    }

    realSize--;
    for (; i < realSize; i++) {
        table[i] = table[i + 1];
    }
}

template<class TKey, class TValue>
bool SortedTable<TKey, TValue>::contains(TKey key)
{
    int left = 0;
    int right = realSize - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (table[mid].key == key)
            return true;
        if (table[mid].key < key)
            left ++;
        else
            right --;
    }
    return false;
}

template<class TKey, class TValue>
TValue SortedTable<TKey, TValue>::get(TKey key)
{
    int left = 0;
    int right = realSize - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (table[mid].key == key)
            return table[mid].value;
        if (table[mid].key < key)
            left++;
        else
            right--;
    }
    throw std::logic_error("Key doesnt found");
}

template<class TKey, class TValue>
CList<TableNode<TKey, TValue>>& SortedTable<TKey, TValue>::getAll()
{
    CList<TableNode<TKey, TValue>> polynoms_list;
    for (int i = 0; i < realSize; i++) {
        polynoms_list.push_back(table[i]);
    }
    return polynoms_list;
}

template<class TKey, class TValue>
inline void SortedTable<TKey, TValue>::clear()
{
    TableNode<TKey, TValue>* temp_table = new TableNode<TKey, TValue>[factSize];
    delete[] table;
    table = temp_table;
    realSize = 0;
}
