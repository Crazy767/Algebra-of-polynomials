using namespace std;
#include "Gen_Interface.h"

Table::Table() {
    // Конструктор по умолчанию, можно инициализировать данные по необходимости
}

Table::~Table() {
    // Деструктор, освобождение ресурсов, если необходимо
}

void Table::insert(int value) {
    data.push_back(value);  // Добавление значения в конец таблицы
}

void Table::remove(int value) {
    // Поиск значения в таблице
    auto it = std::find(data.begin(), data.end(), value);
    if (it != data.end()) {
        data.erase(it);  // Удаление значения, если оно найдено
    }
}

int Table::getSize() const {
    return data.size();  // Возврат размера таблицы
}
