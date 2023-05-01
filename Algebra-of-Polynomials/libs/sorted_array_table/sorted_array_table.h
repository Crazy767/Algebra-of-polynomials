#include <stdexcept>
#include <string>

struct TableElement {
    std::string value;
};

class SortedTable {
private:
    TableElement* table;
    int physicalSize;
    int logicalSize;
public:
    SortedTable(int physicalSize) {
        this->physicalSize = physicalSize;
        this->logicalSize = 0;
        table = new TableElement[physicalSize];
    }

    bool is_full() {
        if (logicalSize >= physicalSize) {
            return true;
        }
        return false;
    }

    void push(std::string value) {
        if (is_full())
            throw std::out_of_range("Table is full");

    }

    void insert(TableElement element) {
        if (is_full())
            throw std::out_of_range("Table is full");
        table[logicalSize] = element;
        /*int i;
        for (i = logicalSize; i >= 0 && table[i].key > element.key; i--) {
            table[i + 1] = table[i];
        }
        table[i + 1] = element;*/
        logicalSize++;
    }

    int get_physical_size() {
        return physicalSize;
    }

    int get_logical_size() {
        return logicalSize;
    }

    std::string search(int key) {
        return table[key].value;
        /*int left = 0;
        int right = logicalSize - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (table[mid].key == key) {
                return table[mid].value;
            }
            else if (table[mid].key < key) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }*/
        throw std::out_of_range("Element not found");
    }
};
