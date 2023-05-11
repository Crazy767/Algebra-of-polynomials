#include "base.h"
#include "Tables/interface_table/ITable.h"
template <class TKey, class TValue>
class HashOpenTable : public Table<TKey, TValue> {
private:
    static const int TABLE_SIZE = 100; // Размер хеш-таблицы
    TableNode<TKey, TValue>* table[TABLE_SIZE];

    int getHash(const TKey& key) const {
        int stringSize = 0;
        for (int i = 0; i < key.length(); i++) {
            stringSize += static_cast<int>(key[i]);
        }
        return stringSize % TABLE_SIZE;
    }
public:
    HashOpenTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    ~HashOpenTable() {
        clear();
    }

    void add(const TKey key, const TValue value) override {
        int index = getHash(key);
        while (table[index] != nullptr && table[index]->key != key) {
            index = (index + 1) % TABLE_SIZE; // Открытое перемешивание
        }
        if (table[index] == nullptr) {
            table[index] = new TableNode<TKey, TValue>(key, value);
        }
        else {
            table[index]->value = value; // Обновление значения, если ключ уже существует
        }
    }

    void remove(const TKey key) override {
        int index = getHash(key);
        while (table[index] != nullptr && table[index]->key != key) {
            index = (index + 1) % TABLE_SIZE;
        }
        if (table[index] != nullptr) {
            delete table[index];
            table[index] = nullptr;
        }
    }

    bool contains(const TKey key) override {
        int index = getHash(key);
        while (table[index] != nullptr && table[index]->key != key) {
            index = (index + 1) % TABLE_SIZE;
        }
        return (table[index] != nullptr);
    }

    TValue get(const TKey key) override {
        int index = getHash(key);
        while (table[index] != nullptr && table[index]->key != key) {
            index = (index + 1) % TABLE_SIZE;
        }
        if (table[index] != nullptr) {
            return table[index]->value;
        }
        // Вернуть значение по умолчанию, если ключ не найден
        return TValue();
    }

    CList<TableNode<TKey, TValue>>& getAll() override {
        CList<TableNode<TKey, TValue>> resultList;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                resultList.push_back(*table[i]);
            }
        }
        return resultList;
    }

    void clear() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                delete table[i];
                table[i] = nullptr;
            }
        }
    }
};