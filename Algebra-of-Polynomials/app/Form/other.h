#pragma once

#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "Tables/avl_tree_table/AVLTreeTable.h"

using namespace System::Windows::Forms;

CList<Monomial> monoms;
AVLTreeTable<std::string, Polynomial> avlTreeTable;

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