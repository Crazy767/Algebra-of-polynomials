#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
template <typename Key, typename Value>
class HashTable {
private:
    struct Entry {
        Key key;
        Value value;
        bool isOccupied;

        Entry() : isOccupied(false) {}
    };

    std::vector<Entry> table;
    std::function<size_t(const Key&)> hashFunction;
    size_t size;
    size_t capacity;

public:
    HashTable(size_t initialCapacity = 100)
        : table(initialCapacity), size(0), capacity(initialCapacity) {
        hashFunction = std::hash<Key>();
    }

    void insert(const Key& key, const Value& value) {
        if (size == capacity) {
            rehash();
        }

        size_t index = hashFunction(key) % capacity;
        size_t startIndex = index;

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                throw std::runtime_error("Key already exists in the hash table");
            }

            index = (index + 1) % capacity;

            // If we have traversed the entire table without finding an empty slot,
            // it means the table is full and we cannot insert the key-value pair.
            if (index == startIndex) {
                throw std::runtime_error("Hash table is full");
            }
        }

        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
        size++;
    }

    bool contains(const Key& key) const {
        size_t index = hashFunction(key) % capacity;
        size_t startIndex = index;

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                return true;
            }

            index = (index + 1) % capacity;

            // If we have traversed the entire table without finding the key,
            // it means the key is not present in the hash table.
            if (index == startIndex) {
                return false;
            }
        }

        return false;
    }

    const Value& get(const Key& key) const {
        size_t index = hashFunction(key) % capacity;
        size_t startIndex = index;

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                return table[index].value;
            }

            index = (index + 1) % capacity;

            // If we have traversed the entire table without finding the key,
            // it means the key is not present in the hash table.
            if (index == startIndex) {
                throw std::runtime_error("Key not found in the hash table");
            }
        }

        throw std::runtime_error("Key not found in the hash table");
    }

    void remove(const Key& key) {
        size_t index = hashFunction(key) % capacity;
        size_t startIndex = index;

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                table[index].isOccupied = false;
                size--;
                return;
            }

            index = (index + 1) % capacity;

            // If we have traversed the entire table without finding the key,
            // it means the key is not present in the hash table.
            if (index == startIndex) {
                throw std::runtime_error("Key not found in the hash table");
            }
        }

        throw std::runtime_error("Key not found in the hash table");
    }

     size_t getSize() const{
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

private:
    void rehash() {
        size_t newCapacity = capacity * 2;
        std::vector<Entry> newTable(newCapacity);

        for (const auto& entry : table) {
            if (entry.isOccupied) {
                size_t index = hashFunction(entry.key) % newCapacity;
                size_t startIndex = index;

                while (newTable[index].isOccupied) {
                    index = (index + 1) % newCapacity;

                    // If we have traversed the entire table without finding an empty slot,
                    // it means the table is full and we cannot rehash the entry.
                    if (index == startIndex) {
                        throw std::runtime_error("Hash table is full during rehashing");
                    }
                }

                newTable[index].key = entry.key;
                newTable[index].value = entry.value;
                newTable[index].isOccupied = true;
            }
        }

        table = std::move(newTable);
        capacity = newCapacity;
    }
};