#pragma once
#include "base.h"
#include "Tables/interface_table/ITable.h"
template <class TKey, class TValue>
class LinearListTable : public Table<TKey, TValue> {
    CList<TableNode<TKey, TValue>> data;
public:
    void add(const TKey key, const TValue value) override {
        TableNode<TKey, TValue> newRecord = { key, value };
        data.push_back(newRecord);
    }
    void remove(TKey key) override {
        for (int i = 0; i < data.get_size(); i++) {
            if (data[i].key == key) {
                data.remove(i);
                return;
            }
        }
    }
    TValue get(TKey key) override {
        try {
            for (const TableNode<TKey, TValue>& record : data) {
                if (record.key == key) {
                    return record.value;
                }
            }
            throw std::runtime_error("This object not found");
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
            return TValue();
        }
    }
    void clear() override {
        data.clear();
    }
    bool contains(TKey key) override {
        for (const TableNode<TKey, TValue>& record : data) {
            if (record.key == key) {
                return true;
            }
        }
        return false;
    }
    CList<TableNode<TKey, TValue>>& getAll() override {
        return data;
    }
};