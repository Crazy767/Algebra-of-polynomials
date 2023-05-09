#pragma once
#include "other.h"

namespace WinFormApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;


	/// <summary>
	/// Сводка для AppForm1
	/// </summary>
	public ref class AppForm1 : public System::Windows::Forms::Form
	{
		System::Windows::Forms::Button^ currentButtonTable;
		float targetWidth;
		float currentWidth;
		float animationStep;
		private: System::Windows::Forms::Timer^ collapseTimer;
		private: System::Windows::Forms::Button^ buttonTableAVL;
		private: System::Windows::Forms::Button^ buttonTableHashList;
		private: System::Windows::Forms::Button^ buttonTableSorted;
		private: System::Windows::Forms::Button^ buttonTableHashSorted;
		private: System::Windows::Forms::Button^ buttonTableLinearList;
		private: System::Windows::Forms::DataGridView^ dataGridPolynoms;
		private: System::Windows::Forms::MenuStrip^ menuStrip1;
		private: System::Windows::Forms::ToolStripMenuItem^ сохранитьToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ загрузитьToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ загрузитьToolStripMenuItem1;
		private: System::Windows::Forms::StatusStrip^ statusStrip1;
		private: System::Windows::Forms::Panel^ panel2;
		private: System::Windows::Forms::Button^ button10;
		private: System::Windows::Forms::Button^ button_add_pol;
		private: System::Windows::Forms::Button^ buttonMonomToPolynom;
		private: System::Windows::Forms::Button^ button7;
		private: System::Windows::Forms::TextBox^ textBoxMonom;
		private: System::Windows::Forms::TextBox^ textBoxPolynom;
		private: System::Windows::Forms::TextBox^ textBoxKey;
		private: System::Windows::Forms::DataGridView^ dataGridMonoms;
		private: System::Windows::Forms::ToolStripStatusLabel^ statusLabelTable;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ ColumnMonoms;
		private: System::Windows::Forms::DataGridViewButtonColumn^ ColumnButtonDelete;
		private: System::Windows::Forms::DataGridViewButtonColumn^ ColumnDelete;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ Ключик;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ Полиномчик;

	public:
		AppForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			// Инициализация переменных для анимации
			targetWidth = this->panel1->Width * 2;
			currentWidth = this->panel1->Width;
			animationStep = 3;
			currentButtonTable = buttonTableLinearArray;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AppForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonTableLinearArray;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ expandTimer;


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		///

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonTableLinearArray = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonTableHashList = (gcnew System::Windows::Forms::Button());
			this->buttonTableSorted = (gcnew System::Windows::Forms::Button());
			this->buttonTableHashSorted = (gcnew System::Windows::Forms::Button());
			this->buttonTableLinearList = (gcnew System::Windows::Forms::Button());
			this->buttonTableAVL = (gcnew System::Windows::Forms::Button());
			this->expandTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->collapseTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->dataGridPolynoms = (gcnew System::Windows::Forms::DataGridView());
			this->ColumnDelete = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->Ключик = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Полиномчик = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->загрузитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->загрузитьToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->statusLabelTable = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button_add_pol = (gcnew System::Windows::Forms::Button());
			this->buttonMonomToPolynom = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBoxMonom = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPolynom = (gcnew System::Windows::Forms::TextBox());
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->dataGridMonoms = (gcnew System::Windows::Forms::DataGridView());
			this->ColumnMonoms = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ColumnButtonDelete = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridPolynoms))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridMonoms))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 1;
			// 
			// buttonTableLinearArray
			// 
			this->buttonTableLinearArray->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonTableLinearArray->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonTableLinearArray->Location = System::Drawing::Point(0, 0);
			this->buttonTableLinearArray->Name = L"buttonTableLinearArray";
			this->buttonTableLinearArray->Size = System::Drawing::Size(69, 63);
			this->buttonTableLinearArray->TabIndex = 2;
			this->buttonTableLinearArray->Text = L"Линейная таблица на массиве";
			this->buttonTableLinearArray->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonTableLinearArray->UseVisualStyleBackColor = true;
			this->buttonTableLinearArray->Click += gcnew System::EventHandler(this, &AppForm1::buttonTable_Click);
			this->buttonTableLinearArray->MouseEnter += gcnew System::EventHandler(this, &AppForm1::button_MouseEnter);
			this->buttonTableLinearArray->MouseLeave += gcnew System::EventHandler(this, &AppForm1::button_MouseLeave);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->buttonTableHashList);
			this->panel1->Controls->Add(this->buttonTableSorted);
			this->panel1->Controls->Add(this->buttonTableHashSorted);
			this->panel1->Controls->Add(this->buttonTableLinearList);
			this->panel1->Controls->Add(this->buttonTableAVL);
			this->panel1->Controls->Add(this->buttonTableLinearArray);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel1->Location = System::Drawing::Point(1167, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(69, 393);
			this->panel1->TabIndex = 3;
			this->panel1->MouseEnter += gcnew System::EventHandler(this, &AppForm1::panel1_MouseEnter);
			this->panel1->MouseLeave += gcnew System::EventHandler(this, &AppForm1::panel1_MouseLeave);
			// 
			// buttonTableHashList
			// 
			this->buttonTableHashList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonTableHashList->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->buttonTableHashList->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonTableHashList->Location = System::Drawing::Point(0, 300);
			this->buttonTableHashList->Name = L"buttonTableHashList";
			this->buttonTableHashList->Size = System::Drawing::Size(69, 63);
			this->buttonTableHashList->TabIndex = 7;
			this->buttonTableHashList->Text = L"Хеш-таблица со списками (метод цепочек)";
			this->buttonTableHashList->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonTableHashList->UseVisualStyleBackColor = true;
			this->buttonTableHashList->Click += gcnew System::EventHandler(this, &AppForm1::buttonTable_Click);
			this->buttonTableHashList->MouseEnter += gcnew System::EventHandler(this, &AppForm1::button_MouseEnter);
			this->buttonTableHashList->MouseLeave += gcnew System::EventHandler(this, &AppForm1::button_MouseLeave);
			// 
			// buttonTableSorted
			// 
			this->buttonTableSorted->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonTableSorted->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->buttonTableSorted->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonTableSorted->Location = System::Drawing::Point(0, 240);
			this->buttonTableSorted->Name = L"buttonTableSorted";
			this->buttonTableSorted->Size = System::Drawing::Size(69, 63);
			this->buttonTableSorted->TabIndex = 6;
			this->buttonTableSorted->Text = L"Упорядоченная таблица на массиве";
			this->buttonTableSorted->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonTableSorted->UseVisualStyleBackColor = true;
			this->buttonTableSorted->Click += gcnew System::EventHandler(this, &AppForm1::buttonTable_Click);
			this->buttonTableSorted->MouseEnter += gcnew System::EventHandler(this, &AppForm1::button_MouseEnter);
			this->buttonTableSorted->MouseLeave += gcnew System::EventHandler(this, &AppForm1::button_MouseLeave);
			// 
			// buttonTableHashSorted
			// 
			this->buttonTableHashSorted->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonTableHashSorted->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->buttonTableHashSorted->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonTableHashSorted->Location = System::Drawing::Point(0, 180);
			this->buttonTableHashSorted->Name = L"buttonTableHashSorted";
			this->buttonTableHashSorted->Size = System::Drawing::Size(69, 63);
			this->buttonTableHashSorted->TabIndex = 5;
			this->buttonTableHashSorted->Text = L"Хеш-таблица с открытым перемешиванием";
			this->buttonTableHashSorted->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonTableHashSorted->UseVisualStyleBackColor = true;
			this->buttonTableHashSorted->Click += gcnew System::EventHandler(this, &AppForm1::buttonTable_Click);
			this->buttonTableHashSorted->MouseEnter += gcnew System::EventHandler(this, &AppForm1::button_MouseEnter);
			this->buttonTableHashSorted->MouseLeave += gcnew System::EventHandler(this, &AppForm1::button_MouseLeave);
			// 
			// buttonTableLinearList
			// 
			this->buttonTableLinearList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonTableLinearList->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->buttonTableLinearList->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonTableLinearList->Location = System::Drawing::Point(0, 120);
			this->buttonTableLinearList->Name = L"buttonTableLinearList";
			this->buttonTableLinearList->Size = System::Drawing::Size(69, 63);
			this->buttonTableLinearList->TabIndex = 4;
			this->buttonTableLinearList->Text = L"Линейная таблица на списке";
			this->buttonTableLinearList->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonTableLinearList->UseVisualStyleBackColor = true;
			this->buttonTableLinearList->Click += gcnew System::EventHandler(this, &AppForm1::buttonTable_Click);
			this->buttonTableLinearList->MouseEnter += gcnew System::EventHandler(this, &AppForm1::button_MouseEnter);
			this->buttonTableLinearList->MouseLeave += gcnew System::EventHandler(this, &AppForm1::button_MouseLeave);
			// 
			// buttonTableAVL
			// 
			this->buttonTableAVL->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonTableAVL->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->buttonTableAVL->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonTableAVL->Location = System::Drawing::Point(0, 60);
			this->buttonTableAVL->Name = L"buttonTableAVL";
			this->buttonTableAVL->Size = System::Drawing::Size(69, 63);
			this->buttonTableAVL->TabIndex = 3;
			this->buttonTableAVL->Text = L"Таблица на поисковом дереве (АВЛ)";
			this->buttonTableAVL->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonTableAVL->UseVisualStyleBackColor = true;
			this->buttonTableAVL->Click += gcnew System::EventHandler(this, &AppForm1::buttonTable_Click);
			this->buttonTableAVL->MouseEnter += gcnew System::EventHandler(this, &AppForm1::button_MouseEnter);
			this->buttonTableAVL->MouseLeave += gcnew System::EventHandler(this, &AppForm1::button_MouseLeave);
			// 
			// expandTimer
			// 
			this->expandTimer->Interval = 1;
			this->expandTimer->Tick += gcnew System::EventHandler(this, &AppForm1::expandTimer_Tick);
			// 
			// collapseTimer
			// 
			this->collapseTimer->Interval = 1;
			this->collapseTimer->Tick += gcnew System::EventHandler(this, &AppForm1::collapseTimer_Tick);
			// 
			// dataGridPolynoms
			// 
			this->dataGridPolynoms->AllowUserToAddRows = false;
			this->dataGridPolynoms->AllowUserToDeleteRows = false;
			this->dataGridPolynoms->AllowUserToResizeColumns = false;
			this->dataGridPolynoms->AllowUserToResizeRows = false;
			this->dataGridPolynoms->BackgroundColor = System::Drawing::Color::LightGray;
			this->dataGridPolynoms->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridPolynoms->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridPolynoms->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ColumnDelete,
					this->Ключик, this->Полиномчик
			});
			this->dataGridPolynoms->Location = System::Drawing::Point(497, 46);
			this->dataGridPolynoms->MultiSelect = false;
			this->dataGridPolynoms->Name = L"dataGridPolynoms";
			this->dataGridPolynoms->ReadOnly = true;
			this->dataGridPolynoms->RowHeadersVisible = false;
			this->dataGridPolynoms->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridPolynoms->Size = System::Drawing::Size(586, 349);
			this->dataGridPolynoms->TabIndex = 4;
			this->dataGridPolynoms->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AppForm1::dataGridPolynoms_CellContentClick);
			this->dataGridPolynoms->CellLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AppForm1::dataGrid_CellLeave);
			// 
			// ColumnDelete
			// 
			this->ColumnDelete->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ColumnDelete->HeaderText = L"";
			this->ColumnDelete->MinimumWidth = 60;
			this->ColumnDelete->Name = L"ColumnDelete";
			this->ColumnDelete->ReadOnly = true;
			this->ColumnDelete->Text = L"Удалить";
			this->ColumnDelete->UseColumnTextForButtonValue = true;
			// 
			// Ключик
			// 
			this->Ключик->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->Ключик->FillWeight = 50.76142F;
			this->Ключик->HeaderText = L"Ключик";
			this->Ключик->MinimumWidth = 100;
			this->Ключик->Name = L"Ключик";
			this->Ключик->ReadOnly = true;
			this->Ключик->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Полиномчик
			// 
			this->Полиномчик->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->Полиномчик->FillWeight = 149.2386F;
			this->Полиномчик->HeaderText = L"Полиномчик";
			this->Полиномчик->MinimumWidth = 415;
			this->Полиномчик->Name = L"Полиномчик";
			this->Полиномчик->ReadOnly = true;
			this->Полиномчик->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Полиномчик->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Полиномчик->Width = 415;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->сохранитьToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1236, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->загрузитьToolStripMenuItem,
					this->загрузитьToolStripMenuItem1
			});
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->сохранитьToolStripMenuItem->Text = L"Файл";
			// 
			// загрузитьToolStripMenuItem
			// 
			this->загрузитьToolStripMenuItem->Name = L"загрузитьToolStripMenuItem";
			this->загрузитьToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->загрузитьToolStripMenuItem->Text = L"Сохранить";
			// 
			// загрузитьToolStripMenuItem1
			// 
			this->загрузитьToolStripMenuItem1->Name = L"загрузитьToolStripMenuItem1";
			this->загрузитьToolStripMenuItem1->Size = System::Drawing::Size(133, 22);
			this->загрузитьToolStripMenuItem1->Text = L"Загрузить";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->statusLabelTable });
			this->statusStrip1->Location = System::Drawing::Point(0, 395);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1167, 22);
			this->statusStrip1->TabIndex = 7;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// statusLabelTable
			// 
			this->statusLabelTable->Name = L"statusLabelTable";
			this->statusLabelTable->Size = System::Drawing::Size(230, 17);
			this->statusLabelTable->Text = L"Выбрано: Линейная таблица на массиве";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button10);
			this->panel2->Controls->Add(this->button_add_pol);
			this->panel2->Controls->Add(this->buttonMonomToPolynom);
			this->panel2->Controls->Add(this->button7);
			this->panel2->Controls->Add(this->textBoxMonom);
			this->panel2->Controls->Add(this->textBoxPolynom);
			this->panel2->Controls->Add(this->textBoxKey);
			this->panel2->Location = System::Drawing::Point(12, 46);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(237, 349);
			this->panel2->TabIndex = 8;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(15, 180);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(83, 34);
			this->button10->TabIndex = 6;
			this->button10->Text = L"Найти";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button_add_pol
			// 
			this->button_add_pol->Location = System::Drawing::Point(73, 60);
			this->button_add_pol->Name = L"button_add_pol";
			this->button_add_pol->Size = System::Drawing::Size(83, 34);
			this->button_add_pol->TabIndex = 5;
			this->button_add_pol->Text = L"Добавить";
			this->button_add_pol->UseVisualStyleBackColor = true;
			this->button_add_pol->Click += gcnew System::EventHandler(this, &AppForm1::button_add_pol_Click);
			// 
			// buttonMonomToPolynom
			// 
			this->buttonMonomToPolynom->Location = System::Drawing::Point(127, 180);
			this->buttonMonomToPolynom->Name = L"buttonMonomToPolynom";
			this->buttonMonomToPolynom->Size = System::Drawing::Size(83, 34);
			this->buttonMonomToPolynom->TabIndex = 4;
			this->buttonMonomToPolynom->Text = L"Объединить мономы";
			this->buttonMonomToPolynom->UseVisualStyleBackColor = true;
			this->buttonMonomToPolynom->Click += gcnew System::EventHandler(this, &AppForm1::buttonMonomToPolynom_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(73, 314);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(83, 34);
			this->button7->TabIndex = 3;
			this->button7->Text = L"Создать";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// textBoxMonom
			// 
			this->textBoxMonom->ForeColor = System::Drawing::SystemColors::GrayText;
			this->textBoxMonom->Location = System::Drawing::Point(41, 22);
			this->textBoxMonom->Name = L"textBoxMonom";
			this->textBoxMonom->Size = System::Drawing::Size(143, 20);
			this->textBoxMonom->TabIndex = 2;
			this->textBoxMonom->Text = L"Введите моном...";
			this->textBoxMonom->Enter += gcnew System::EventHandler(this, &AppForm1::textBox_Enter);
			this->textBoxMonom->Leave += gcnew System::EventHandler(this, &AppForm1::textBox_Leave);
			// 
			// textBoxPolynom
			// 
			this->textBoxPolynom->ForeColor = System::Drawing::SystemColors::GrayText;
			this->textBoxPolynom->Location = System::Drawing::Point(41, 283);
			this->textBoxPolynom->Name = L"textBoxPolynom";
			this->textBoxPolynom->Size = System::Drawing::Size(143, 20);
			this->textBoxPolynom->TabIndex = 1;
			this->textBoxPolynom->Text = L"Введите полином...";
			this->textBoxPolynom->Enter += gcnew System::EventHandler(this, &AppForm1::textBox_Enter);
			this->textBoxPolynom->Leave += gcnew System::EventHandler(this, &AppForm1::textBox_Leave);
			// 
			// textBoxKey
			// 
			this->textBoxKey->ForeColor = System::Drawing::SystemColors::GrayText;
			this->textBoxKey->Location = System::Drawing::Point(41, 142);
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->Size = System::Drawing::Size(143, 20);
			this->textBoxKey->TabIndex = 0;
			this->textBoxKey->Text = L"Введите ключ...";
			this->textBoxKey->Enter += gcnew System::EventHandler(this, &AppForm1::textBox_Enter);
			this->textBoxKey->Leave += gcnew System::EventHandler(this, &AppForm1::textBox_Leave);
			// 
			// dataGridMonoms
			// 
			this->dataGridMonoms->AllowUserToAddRows = false;
			this->dataGridMonoms->AllowUserToDeleteRows = false;
			this->dataGridMonoms->AllowUserToResizeColumns = false;
			this->dataGridMonoms->AllowUserToResizeRows = false;
			this->dataGridMonoms->BackgroundColor = System::Drawing::Color::LightGray;
			this->dataGridMonoms->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridMonoms->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridMonoms->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->ColumnMonoms,
					this->ColumnButtonDelete
			});
			this->dataGridMonoms->Location = System::Drawing::Point(255, 46);
			this->dataGridMonoms->MultiSelect = false;
			this->dataGridMonoms->Name = L"dataGridMonoms";
			this->dataGridMonoms->ReadOnly = true;
			this->dataGridMonoms->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->dataGridMonoms->RowHeadersVisible = false;
			this->dataGridMonoms->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridMonoms->Size = System::Drawing::Size(236, 349);
			this->dataGridMonoms->TabIndex = 9;
			this->dataGridMonoms->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AppForm1::DataGridMonoms_CellContentClick);
			this->dataGridMonoms->CellLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AppForm1::dataGrid_CellLeave);
			// 
			// ColumnMonoms
			// 
			this->ColumnMonoms->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->ColumnMonoms->Frozen = true;
			this->ColumnMonoms->HeaderText = L"Сохраненные мономы";
			this->ColumnMonoms->MinimumWidth = 175;
			this->ColumnMonoms->Name = L"ColumnMonoms";
			this->ColumnMonoms->ReadOnly = true;
			this->ColumnMonoms->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->ColumnMonoms->Width = 175;
			// 
			// ColumnButtonDelete
			// 
			this->ColumnButtonDelete->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ColumnButtonDelete->HeaderText = L"";
			this->ColumnButtonDelete->MinimumWidth = 60;
			this->ColumnButtonDelete->Name = L"ColumnButtonDelete";
			this->ColumnButtonDelete->ReadOnly = true;
			this->ColumnButtonDelete->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->ColumnButtonDelete->Text = L"Удалить";
			this->ColumnButtonDelete->UseColumnTextForButtonValue = true;
			// 
			// AppForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1236, 417);
			this->Controls->Add(this->dataGridPolynoms);
			this->Controls->Add(this->dataGridMonoms);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"AppForm1";
			this->Text = L"Алгебра полиномов";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridPolynoms))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridMonoms))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void panel1_MouseEnter(System::Object^ sender, EventArgs^ e)
	{
		collapseTimer->Stop(); // Остановка таймера затухания, если он запущен
		expandTimer->Start(); // Запуск таймера выдвигания
		std::cout << "PMouseEnter" << std::endl;
	}
	private: System::Void panel1_MouseLeave(System::Object^ sender, EventArgs^ e)
	{
		expandTimer->Stop(); // Остановка таймера выдвигания, если он запущен
		collapseTimer->Start(); // Запуск таймера затухания
		std::cout << "PMouseLeave" << std::endl;
	}
	private: System::Void button_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = dynamic_cast<Button^>(sender);
		collapseTimer->Stop(); // Остановка таймера затухания, если он запущен
		expandTimer->Start(); // Запуск таймера выдвигания
		button->Height += 10;
		button->BringToFront();
		std::cout << "MouseEnter   " << panel1->Width << " - " << button->Width << std::endl;
	}
	private: System::Void button_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = dynamic_cast<Button^>(sender);
		expandTimer->Stop(); // Остановка таймера выдвигания, если он запущен
		collapseTimer->Start(); // Запуск таймера затухания
		button->Height -= 10;
		std::cout << "MouseLeave" << std::endl;
	}
	private: System::Void expandTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (this->panel1->Width < targetWidth) // Проверка, не достигла ли панель целевой ширины
		{
			currentWidth += animationStep; // Увеличение ширины панели

			if (currentWidth > targetWidth) // Проверка, достигла ли панель целевой ширины
			{
				currentWidth = targetWidth; // Установка точной целевой ширины панели
				expandTimer->Stop(); // Остановка таймера выдвигания
			}
			this->panel1->Width = currentWidth; // Применение изменений ширины панели
		}
		else
		{
			this->expandTimer->Stop(); // Остановка таймера выдвигания, если панель уже полностью выдвинута
		}
	}
	private: System::Void collapseTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (panel1->Width > targetWidth / 2) // Проверка, не достигла ли панель целевой ширины
		{
			currentWidth -= animationStep; // Уменьшение ширины панели

			if (currentWidth < targetWidth / 2) // Проверка, достигла ли панель целевой ширины
			{
				currentWidth = targetWidth / 2; // Установка точной целевой ширины панели
				collapseTimer->Stop(); // Остановка таймера затухания
			}
			panel1->Width = currentWidth; // Применение изменений ширины панели
		}
		else
		{
			collapseTimer->Stop(); // Остановка таймера затухания, если панель уже полностью затухла
		}
	}
	private: System::Void textBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);

		if (textBox->Name == L"textBoxMonom")
			TextBoxLeave(textBox, "Введите моном...");
		else if (textBox->Name == L"textBoxKey")
			TextBoxLeave(textBox, "Введите ключ...");
		else if (textBox->Name == L"textBoxPolynom")
			TextBoxLeave(textBox, "Введите полином...");
	}
	private: System::Void textBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);

		if (textBox->Name == L"textBoxMonom")
			TextBoxEnter(textBox, "Введите моном...");
		else if (textBox->Name == L"textBoxKey")
			TextBoxEnter(textBox, "Введите ключ...");
		else if (textBox->Name == L"textBoxPolynom")
			TextBoxEnter(textBox, "Введите полином...");
	}
	private: System::Void button_add_pol_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string str = toString(textBoxMonom->Text);
		Monomial m(str);
		monoms.push_back(m);
		redrawDataGridMonoms(dataGridMonoms, monoms);
	}
	private: System::Void buttonMonomToPolynom_Click(System::Object^ sender, System::EventArgs^ e) {
		if (monoms.empty()) {
			MessageBox::Show("Нельзя создать полином без объявления как минимум одного монома", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (textBoxKey->ForeColor == System::Drawing::SystemColors::GrayText) {
			MessageBox::Show("Нельзя создать полином без ключа", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Polynomial polynoms(monoms);

		if (currentButtonTable->Name == "buttonTableAVL") {
			avlTreeTable.add(toString(textBoxKey->Text), polynoms);
			redrawDataGridPolynoms(dataGridPolynoms, avlTreeTable);
		}
	}
	private: System::Void DataGridMonoms_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (!e->ColumnIndex) { return; }
		if (e->RowIndex >= 0) {
			monoms.remove(e->RowIndex);
			redrawDataGridMonoms(dataGridMonoms, monoms);
			if (dataGridMonoms->RowCount > 1 && e->RowIndex > 0)
				dataGridMonoms->CurrentCell = dataGridMonoms->Rows[e->RowIndex - 1]->Cells[0];
		}
	}
	private: System::Void buttonTable_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = dynamic_cast<Button^>(sender);
		currentButtonTable = button;
		statusLabelTable->Text = "Выбрано: " + button->Text;
	}
	private: System::Void dataGrid_CellLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		dataGridMonoms->ClearSelection();
		dataGridPolynoms->ClearSelection();
	}
	private: System::Void dataGridPolynoms_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->ColumnIndex) { return; }
		if (e->RowIndex >= 0) {
			if (currentButtonTable->Name == "buttonTableAVL") {
				auto key = dataGridPolynoms->Rows[e->RowIndex]->Cells[1]->Value->ToString();
				avlTreeTable.remove(toString(key));
				redrawDataGridPolynoms(dataGridPolynoms, avlTreeTable);
			}
			if (dataGridPolynoms->RowCount > 1 && e->RowIndex > 0)
				dataGridPolynoms->CurrentCell = dataGridPolynoms->Rows[e->RowIndex - 1]->Cells[0];
		}
	}
};
}
