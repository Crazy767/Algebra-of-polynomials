#include <iostream>
#include <vector>

class LinearArray {
private:
    std::vector<int> arr; // Вектор элементов

public:
    // Конструктор
    LinearArray() {
    }

    // Добавление элемента в таблицу
    void add(int elem) {
        arr.push_back(elem);
    }

    // Получение элемента по индексу
    int get(int index) {
        if (index < 0 || index >= arr.size()) {
            std::cout << "Index out of range" << std::endl;
            return -1;
        }
        return arr[index];
    }

    // Получение размера таблицы
    int get_size() {
        return arr.size();
    }

    // Удаление элемента из таблицы
    void remove(int index) {
        if (index < 0 || index >= arr.size()) {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        arr.erase(arr.begin() + index);
    }

    // Проверка наличия элемента в таблице
    bool contains(int elem) {
        return std::find(arr.begin(), arr.end(), elem) != arr.end();
    }
};