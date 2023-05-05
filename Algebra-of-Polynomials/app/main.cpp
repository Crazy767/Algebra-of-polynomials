#include "sorted_array_table/sorted_array_table.h"

using namespace std;

int main() {
    CList<Monomial> monom_list;
    int degree_1[3] = {1, 1, 1};
    int degree_2[3] = {2, 2, 2};
    Monomial monom1(2.0, degree_1);
    Monomial monom2(3.0, degree_2);
    auto a_1 = monom1.toString();
    auto a_2 = monom2.toString();
    monom_list.push_back(monom1);
    cout << monom_list.get_size();

    Polynomial pol(&monom_list);
}
