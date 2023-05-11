#include "base.h"
#include "Tables/interface_table/ITable.h"


template <class TKey, class TValue>
class LinearArrayTable : public Table<TKey, TValue> {
private:
    TableNode<TKey, TValue>* table;
    int factSize;
    int realSize;
public:
    LinearArrayTable() {
        factSize = 10;
        realSize = 0;
        table = new TableNode<TKey, TValue>[factSize];
    }
    ~LinearArrayTable() { delete[] table; }

    void add(const TKey key, const TValue value) override {
        if (realSize >= factSize) {
            factSize *= 2;

            TableNode<TKey, TValue>* temp_table = new TableNode<TKey, TValue>[factSize];

            for (int i = 0; i < realSize; i++)
                temp_table[i] = table[i];

            delete[] table;
            table = temp_table;
        }

        if (!contains(key))
        {
            table[realSize].key = key;
            table[realSize].value = value;
            realSize++;
        }
    }

    void remove(TKey key) override {
        if (!contains(key))
            throw std::logic_error("Key not found");

        // Поиск элемента с заданным ключом и удаление его из массива
        int i = 0;
        for (; i < realSize; i++) {
            if (table[i].key == key) {
                break;
            }
        }

        // Если элемент не найден, то ничего не делаем
        if (i == realSize) {
            return;
        }

        // Уменьшаем размер массива на 1 и сдвигаем элементы справа от удаленного элемента
        realSize--;
        for (; i < realSize; i++) {
            table[i] = table[i + 1];
        }
    }

    bool contains(TKey key) override {
        int left = 0;
        int right = realSize - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (table[mid].key == key)
                return true;
            if (table[mid].key < key)
                left++;
            else
                right--;
        }
        return false;
    }

    TValue get(TKey key) override {
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
    CList<TableNode<TKey, TValue>>& getAll() override {
        CList<TableNode<TKey, TValue>> polynoms_list;
        for (int i = 0; i < realSize; i++) {
            polynoms_list.push_back(table[i]);
        }
        return polynoms_list;
    }
    void clear() override {
        TableNode<TKey, TValue>* temp_table = new TableNode<TKey, TValue>[factSize];
        delete[] table;
        table = temp_table;
        realSize = 0;
    }
};
