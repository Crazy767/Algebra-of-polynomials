#include "base.h"
#include "Core/clist/CList.h"
#include "Tables/interface_table/ITable.h"

template <class T>
struct MyStruct
{
    T list;
};

template <class TKey, class TValue>
class HashChainTable : public Table<TKey, TValue> {
    int size;
    int count;
    MyStruct<CList<TableNode<TKey, TValue>>>* table;
    int getHash(std::string key);

public:
    HashChainTable();
    ~HashChainTable();

    void add(const TKey key, const TValue value) override;
    void remove(TKey key) override;
    bool contains(TKey key) override;
    TValue get(TKey key) override;
    CList<TableNode<TKey, TValue>>& getAll() override;
    void clear() override;
};

template<class TKey, class TValue>
int HashChainTable<TKey, TValue>::getHash(std::string key)
{
    int string_size = 0;
    for (int i = 0; i < key.length(); i++) {
        string_size += static_cast<int>(key[i]);
    }
    return string_size % size;
}

template<class TKey, class TValue>
HashChainTable<TKey, TValue>::HashChainTable()
{
    size = 100;
    count = 0;
    table = new MyStruct<CList<TableNode<TKey, TValue>>>[size];
}

template<class TKey, class TValue>
HashChainTable<TKey, TValue>::~HashChainTable()
{
    delete[] table;
}

template<class TKey, class TValue>
void HashChainTable<TKey, TValue>::add(const TKey key, const TValue value)
{
    int index = getHash(key);
    if (size <= index + 2)
    {
        size += index;
        MyStruct<CList<TableNode<TKey, TValue>>>* temp_table = new MyStruct<CList<TableNode<TKey, TValue>>>[size];

        for (int i = 0; i < size; i++)
            temp_table[i] = table[i];

        delete[] table;
        table = temp_table;
    }

    CList<TableNode<TKey, TValue>> list_table = table[index].list;
    for (auto& i : list_table) 
    {
        if (i.key == key)
        {
            throw std::logic_error("Key already exist");
            return;
        }
    }

    TableNode<TKey, TValue> n = { key, value };
    table[index].list.push_back(n);
    
}

template<class TKey, class TValue>
void HashChainTable<TKey, TValue>::remove(TKey key)
{
    int index = getHash(key);

    CList<TableNode<TKey, TValue>>& list_table = table[index].list;
    for (int i = 0; i < list_table.get_size(); i++)
    {
        if (list_table[i].key == key)
        {

            list_table.remove(i);
            return;
        }
    }
    throw std::logic_error("Key doesnt found");
}

template<class TKey, class TValue>
bool HashChainTable<TKey, TValue>::contains(TKey key)
{
    int index = getHash(key);

    CList<TableNode<TKey, TValue>> list_table = table[index].list;
    for (auto& i : list_table)
    {
        if (i.key == key)
        {
            return true;
        }
    }
    return false;
}

template<class TKey, class TValue>
TValue HashChainTable<TKey, TValue>::get(TKey key)
{
    int index = getHash(key);

    CList<TableNode<TKey, TValue>> list_table = table[index].list;
    for (auto& i : list_table)
    {
        if (i.key == key)
        {
            return i.value;
        }
    }
    throw std::logic_error("Key doesnt found");
}

template<class TKey, class TValue>
CList<TableNode<TKey, TValue>>& HashChainTable<TKey, TValue>::getAll()
{
    CList<TableNode<TKey, TValue>> polynoms_list;

    for (int i = 0; i < size; i++)
    {
        if (table[i].list.get_size() != 0)
        {
            for (int j = 0; j < table[i].list.get_size(); j++)
                polynoms_list.push_back(table[i].list[j]);
        }
    }
        
    return polynoms_list;
}

template<class TKey, class TValue>
void HashChainTable<TKey, TValue>::clear()
{
    MyStruct<CList<TableNode<TKey, TValue>>>* temp_table = new MyStruct<CList<TableNode<TKey, TValue>>>[size];
    delete[] table;
    table = temp_table;
}
