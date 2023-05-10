#include "base.h"
#include "Tables/interface_table/ITable.h"


template <class TKey, class TValue>
class SortedTable : public Table<TKey, TValue> {
private:
    TableNode<TKey, TValue>* table;
    int factSize;
    int realSize;
public:
    SortedTable();
    ~SortedTable();

    virtual void add(const TKey, const TValue) override;
    virtual void remove(TKey) override;
    virtual bool contains(TKey) override;
    virtual Polynomial get(TKey) override;
    virtual CList<TableNode<TKey, TValue>>& getAll() override;
    virtual void clear() override;
};

template <class TKey, class TValue>
SortedTable<TKey, TValue>::SortedTable() {
    factSize = 100;
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
        throw std::logic_error("Key doesnt found");

    TableNode<TKey, TValue>* temp_table = new TableNode<TKey, TValue>[factSize];
    for (int i = 0; i < realSize; i++)
    {
        if (table[i].key != key)
            temp_table[i] = table[i];
    }

}

template<class TKey, class TValue>
bool SortedTable<TKey, TValue>::contains(TKey key)
{
    int left = 0;
    int right = realSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (table[mid].key == key)
            return true;
        if (table[mid].key < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

template<class TKey, class TValue>
Polynomial SortedTable<TKey, TValue>::get(TKey key)
{
    int left = 0;
    int right = realSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (table[mid].key == key)
            return table[mid].value;
        if (table[mid].key < key)
            left = mid + 1;
        else
            right = mid - 1;
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
}
