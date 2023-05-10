#pragma once

#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "Tables/avl_tree_table/AVLTreeTable.h"
#include "Tables/linear_array_table/linear_array_table.h"

using namespace System::Windows::Forms;
using namespace System::Drawing;

CList<Monomial> monoms;
AVLTreeTable<std::string, Polynomial> avlTreeTable;
LinearArrayTable<std::string, Polynomial> linearArrayTable;

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
    auto tempList = table.getAll();
    for (int i = 0; i < tempList.get_size(); i++) {
        dataGridView->Rows->Add();
        dataGridView->Rows[i]->Cells[1]->Value = toSystemString(tempList[i].key);
        dataGridView->Rows[i]->Cells[2]->Value = toSystemString(tempList[i].value.toString());
    }
}

template<typename T>
void addPolynomToTable(T& table, DataGridView^ dataGridPolynoms,std::string& key, Polynomial& polynoms) {
    if (table.contains(key)) {
        System::Windows::Forms::DialogResult result = MessageBox::Show("Уже есть полином с таким ключом, вы уверены что хотите перезаписать полином?", "Предупреждение", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

        if (result == System::Windows::Forms::DialogResult::Yes)
            table.remove(key);
    }
    table.add(key, polynoms);
    redrawDataGridPolynoms(dataGridPolynoms, table);
}

template<typename T>
void deletePolynomTable(T& table, DataGridView^ dataGridPolynoms, int index) {
    auto key = dataGridPolynoms->Rows[index]->Cells[1]->Value->ToString();
    table.remove(toString(key));
    redrawDataGridPolynoms(dataGridPolynoms, table);
}

template<typename T>
void searchPolynomTable(T& table, DataGridView^ dataGridPolynoms, std::string& key) {
    int rowIndex = -1;
    if (table.contains(key)) {
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

template<typename T>
void getResultPolynom(T& table, System::String^ key, ToolStripStatusLabel^ statusLabelResult, int& x, int& y, int& z) {
    Polynomial p = avlTreeTable.get(toString(key));
    auto r = p.findResult(x, y, z);
    statusLabelResult->Text = "Результат полинома: " + key + " = " + r.ToString();
}