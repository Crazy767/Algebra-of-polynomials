#pragma once
#ifndef TABLE_H
#define TABLE_H

class Table {
public:
    Table();  // Конструктор по умолчанию
    ~Table(); // Деструктор

    void insert(int value);  // Вставка значения в таблицу
    void remove(int value);  // Удаление значения из таблицы
    int getSize() const;     // Получение размера таблицы

private:
    std::vector<int> data;   // Хранение данных таблицы
};

#endif
