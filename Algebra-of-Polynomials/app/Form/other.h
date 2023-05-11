#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "Tables/avl_tree_table/AVLTreeTable.h"
#include "Tables/linear_array_table/linear_array_table.h"
#include "Tables/linear_list_table/linear_list_table.h"
#include "Tables/open_addressing_hash/open_addressing_hash.h"
#include "Tables/hash_chain_table/hash_chain_table.h"
#include "Tables/sorted_array_table/sorted_array_table.h"

using namespace System::Windows::Forms;
using namespace System::Drawing;

CList<Monomial> monoms;
AVLTreeTable<std::string, Polynomial>* avlTreeTable = new AVLTreeTable<std::string, Polynomial>();
LinearArrayTable<std::string, Polynomial>* linearArrayTable = new LinearArrayTable<std::string, Polynomial>();
LinearListTable<std::string, Polynomial>* linearListTable = new LinearListTable<std::string, Polynomial>();
HashOpenTable<std::string, Polynomial>* hashOpenTable = new HashOpenTable<std::string, Polynomial>();
HashChainTable<std::string, Polynomial>* hashChainTable = new HashChainTable<std::string, Polynomial>();
SortedTable<std::string, Polynomial>* sortedTable = new SortedTable<std::string, Polynomial>();

std::string toString(System::String^ input) {
    msclr::interop::marshal_context context;
    const char* characters = context.marshal_as<const char*>(input);
    return std::string(characters);
}

System::String^ toSystemString(const std::string& input) {
    msclr::interop::marshal_context context;
    return context.marshal_as<System::String^>(input.c_str());
}

void TextBoxEnter(TextBox^ textBox, System::String^ placeholderText)
{
    if (textBox->Text == placeholderText)
    {
        textBox->Text = "";
        textBox->ForeColor = System::Drawing::SystemColors::WindowText;
    }
}

void TextBoxLeave(TextBox^ textBox, System::String^ placeholderText)
{
    if (textBox->Text->Length == 0)
    {
        textBox->Text = placeholderText;
        textBox->ForeColor = System::Drawing::SystemColors::GrayText;
    }
}

void redrawDataGridMonoms(DataGridView^ dataGridView, CList<Monomial>& monoms) {
    dataGridView->Rows->Clear();
    for (int i = 0; i < monoms.get_size(); i++) {
        dataGridView->Rows->Add(toSystemString(monoms[i].toString()));
    }
}

template<typename T>
void redrawDataGridPolynoms(DataGridView^ dataGridView, T& table) {
    dataGridView->Rows->Clear();
    auto tempList = table->getAll();
    for (int i = 0; i < tempList.get_size(); i++) {
        if (tempList[i].key.empty()) { continue; }
        dataGridView->Rows->Add();
        dataGridView->Rows[i]->Cells[1]->Value = toSystemString(tempList[i].key);
        dataGridView->Rows[i]->Cells[2]->Value = toSystemString(tempList[i].value.toString());
    }
}

template<typename T>
void addPolynomToTable(T& table, DataGridView^ dataGridPolynoms,std::string& key, Polynomial& polynoms) {
    if (table->contains(key)) {
        System::Windows::Forms::DialogResult result = MessageBox::Show("Уже есть полином с таким ключом, вы уверены что хотите перезаписать полином?", "Предупреждение", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

        if (result == System::Windows::Forms::DialogResult::Yes)
            table->remove(key);
        else return;
    }
    table->add(key, polynoms);
    redrawDataGridPolynoms(dataGridPolynoms, table);
}

template<typename T>
void deletePolynomTable(T& table, DataGridView^ dataGridPolynoms, int index) {
    auto key = dataGridPolynoms->Rows[index]->Cells[1]->Value->ToString();
    table->remove(toString(key));
    redrawDataGridPolynoms(dataGridPolynoms, table);
}

template<typename T>
void searchPolynomTable(T& table, DataGridView^ dataGridPolynoms, std::string& key) {
    int rowIndex = -1;
    if (table->contains(key)) {
        for (int i = 0; i < dataGridPolynoms->RowCount; i++) {
            if (toSystemString(key) == dataGridPolynoms->Rows[i]->Cells[1]->Value->ToString()) {
                rowIndex = i;
                break;
            }
        }
    }

    if (rowIndex != -1)
    {
        System::Collections::Generic::List<bool>^ selectedStates = gcnew System::Collections::Generic::List<bool>();
        for (int i = 0; i < dataGridPolynoms->Rows->Count; i++) {
            dataGridPolynoms->Rows[i]->DefaultCellStyle->SelectionBackColor = SystemColors::Highlight;
            selectedStates->Add(dataGridPolynoms->Rows[i]->Selected);
        }

        dataGridPolynoms->Rows[rowIndex]->DefaultCellStyle->SelectionBackColor = Color::Green;
        // Установите CurrentCell
        dataGridPolynoms->CurrentCell = dataGridPolynoms->Rows[rowIndex]->Cells[1];

        // Восстановите состояние выделения всех строк
        for (int i = 0; i < dataGridPolynoms->Rows->Count; i++)
            dataGridPolynoms->Rows[i]->Selected = selectedStates[i];

        
        dataGridPolynoms->Rows[rowIndex]->Selected = true;
    }
    else {
        MessageBox::Show("Ключ не найден.", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
}

bool str_to_xyz(const std::string& input, int& x, int& y, int& z) {
    std::istringstream iss(input);
    if (iss >> x && iss >> y && iss >> z && iss.eof()) {
        return true;
    }
    return false;
}

bool str_to_monomstr(const std::string& input) {
    std::istringstream iss(input);
    int a, b, c, d;
    if (iss >> a && iss >> b && iss >> c && iss >> d && iss.eof()) {
        if (a != 0 && b >= 0 && c >= 0 && d >= 0)
            return true;
    }
    return false;
}

template<typename T>
void getResultPolynom(T& table, System::String^ key, ToolStripStatusLabel^ statusLabelResult, int& x, int& y, int& z) {
    Polynomial p = table->get(toString(key));
    auto r = p.findResult(x, y, z);
    statusLabelResult->Text = "Результат полинома: " + key + " = " + r.ToString();
}

template<typename T>
void clearTable(T& table, DataGridView^ dataGridPolynoms) {
    table->clear();
    redrawDataGridPolynoms(dataGridPolynoms, table);
}

template <typename Table>
nlohmann::json tableToJson(Table& table) {
    nlohmann::json j;
    auto tableNodes = table->getAll();
    for (auto& tableNode : tableNodes) {
        if (!tableNode.key.empty())
            j.push_back({ tableNode.key, tableNode.value.toString()});
    }

    return j;
}

template <typename Table>
void jsonToTable(nlohmann::json& j, Table& table) {
    table->clear();
    for (auto& node : j) {
        std::string key = node[0].get<std::string>();
        std::string polynom_str = node[1].get<std::string>();
        Polynomial p = parsePolynom(polynom_str);
        table->add(key, p);
    }
}

// Функция для сохранения данных в формате JSON
void SaveDataAsJson(const std::string& filePath)
{
    nlohmann::json data;
    // Добавьте ваш код для заполнения данных в формате JSON
    // Пример:
    data["avlTreeTable"] = tableToJson(avlTreeTable);
    data["linearArrayTable"] = tableToJson(linearArrayTable);
    data["linearListTable"] = tableToJson(linearListTable);
    data["hashOpenTable"] = tableToJson(hashOpenTable);
    data["hashChainTable"] = tableToJson(hashChainTable);
    data["sortedTable"] = tableToJson(sortedTable);
    // Сохранение данных в JSON файл
    std::ofstream file(filePath);
    if (file.is_open()) {
        file << data.dump(4); // Запись данных с отступами (4 пробела)
        file.close();
        std::cout << "Данные сохранены в файл: " << filePath << std::endl;
    }
    else {
        std::cout << "Не удалось открыть файл для сохранения." << std::endl;
    }
}

// Функция для загрузки данных из файла JSON
void LoadDataFromJson(const std::string& filePath) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        nlohmann::json data;
        file >> data; // Загрузка данных из файла

        // Загрузите данные из JSON в ваши таблицы
        // Пример:
        jsonToTable(data["avlTreeTable"], avlTreeTable);
        jsonToTable(data["linearArrayTable"], linearArrayTable);
        jsonToTable(data["linearListTable"], linearListTable);
        jsonToTable(data["hashOpenTable"], hashOpenTable);
        jsonToTable(data["hashChainTable"], hashChainTable);
        jsonToTable(data["sortedTable"], sortedTable);

        file.close();
        std::cout << "Данные загружены из файла: " << filePath << std::endl;
    }
}

Polynomial parsePolynom(std::string polynoms)
{
    CList<Monomial> temp_monom_list;

    int coef = 0;
    int degree[3] = { 0, 0, 0 };
    int degree_index = -1;

    std::string temp_string = "";

    for (int i = 0; i < polynoms.length(); i++)
    {
        auto a = polynoms[i];
        if (polynoms[i] == ' ')
        {
            degree[degree_index] = stoi(temp_string);
            temp_string.clear();

            Monomial temp_monom(coef, degree[0], degree[1], degree[2]);
            temp_monom_list.push_back(temp_monom);

            coef = 0;
            degree[0] = 0;
            degree[1] = 0;
            degree[2] = 0;

            i += 2;
        }
        else if (polynoms[i] != 'x' && polynoms[i] != 'y' && polynoms[i] != 'z' && polynoms[i] != '^')
        {
            temp_string += polynoms[i];
        }
        else
        {
            if ((polynoms[i] == 'x' || polynoms[i] == 'y' || polynoms[i] == 'z') && coef == 0)
                coef = 1;
            if (coef == 0 && !temp_string.empty())
            {
                coef = stoi(temp_string);
                temp_string.clear();
            }
            if (!temp_string.empty())
            {
                degree[degree_index] = stoi(temp_string);
                temp_string.clear();
            }
            if (polynoms[i] == 'x')
            {
                degree_index = 0;
            }
            else if (polynoms[i] == 'y')
            {
                degree_index = 1;
            }
            else if (polynoms[i] == 'z')
            {
                degree_index = 2;
            }
        }
    }
    degree[degree_index] = stoi(temp_string);

    Monomial temp_monom(coef, degree[0], degree[1], degree[2]);
    temp_monom_list.push_back(temp_monom);
    return Polynomial(temp_monom_list);
}