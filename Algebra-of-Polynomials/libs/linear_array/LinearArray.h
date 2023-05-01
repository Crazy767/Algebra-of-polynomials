#include <iostream>
#include <vector>

class LinearArray {
private:
    std::vector<int> arr; // ������ ���������

public:
    // �����������
    LinearArray() {
    }

    // ���������� �������� � �������
    void add(int elem) {
        arr.push_back(elem);
    }

    // ��������� �������� �� �������
    int get(int index) {
        if (index < 0 || index >= arr.size()) {
            std::cout << "Index out of range" << std::endl;
            return -1;
        }
        return arr[index];
    }

    // ��������� ������� �������
    int get_size() {
        return arr.size();
    }

    // �������� �������� �� �������
    void remove(int index) {
        if (index < 0 || index >= arr.size()) {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        arr.erase(arr.begin() + index);
    }

    // �������� ������� �������� � �������
    bool contains(int elem) {
        return std::find(arr.begin(), arr.end(), elem) != arr.end();
    }
};