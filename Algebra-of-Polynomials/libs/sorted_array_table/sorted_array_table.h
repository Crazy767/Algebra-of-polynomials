#include <stdexcept>
#include <string>
#include <iostream>
#include "../polynomial/polynomial.h"

struct TableElement {
    std::string key;
    Polynomial value;
};

class SortedTable {
private:
    TableElement* table;
    int factSize;
    int realSize;
public:
    SortedTable(int factSize) {
        this->factSize = factSize;
        this->realSize = 0;
        table = new TableElement[factSize];
    }

    bool is_full() {
        if (realSize >= factSize) {
            return true;
        }
        return false;
    }

    bool is_empty() {
        if (realSize == 0){
            return true;
        }
        return false;
    }

    void push(TableElement element) 
    {
        if (is_full())
            throw std::out_of_range("Table is full");
        if (is_empty()) 
        {
            table[0] = element;
            realSize++;
            return;
        }
        for (int i = realSize-1; i >= 0; i--) 
        {
            if (table[i].key == element.key) {
                throw std::logic_error("Key already exists");
            }
            else if (table[i].key < element.key)
            {
                if (i == realSize-1) 
                {
                    table[i + 1] = element;
                    realSize++;
                    return;
                }
                else 
                {
                    TableElement* temp_table = new TableElement[factSize];
                    for (int j = realSize; j >= 0; j--)
                    {
                        if (i + 1 == j)
                            temp_table[j] = element;
                        else if (i < j)
                            temp_table[j] = table[j-1];
                        else
                            temp_table[j] = table[j];
                    }
                    table = temp_table;
                    realSize++;
                    return;
                }
            }
        }
    }

    int get_fact_size() {
        return factSize;
    }

    int get_real_size() {
        return realSize;
    }

    TableElement search(std::string key) {
        if (is_empty())
            throw std::out_of_range("Table is empty");
        for (int i = 0; i <= realSize-1; i++) {
            if (table[i].key == key) {
                return table[i];
            }
        }
        throw std::logic_error("Element not found");
    }

    void print_table() {
        for (int i = 0; i <= realSize-1; i++) {
            if (table[i].key != "")
                std::cout << '{' << table[i].key << ' ' << table[i].value.toString() << '}' << std::endl;
        }
    }
};
