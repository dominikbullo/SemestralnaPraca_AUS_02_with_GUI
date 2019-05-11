﻿#pragma once
#include <limits>

#include "App.h"
#include "Nacitanie.h"


namespace SemestralnaPracaAUS02withGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->numericUpDown1->Maximum = System::Decimal(std::numeric_limits<int>::max());
			this->numericUpDown2->Maximum = System::Decimal(std::numeric_limits<int>::max());

			loader = new Nacitanie();
			app = new App(loader);

			updateTable();

			//fillComboBoxes();

			//app = new App(new Nacitanie()->getData());

		}

		/*void fillComboBoxes()
		{
			VolebneKolo* data = app->getVolebneKolo(1);
			for (auto * item : *data->getKraje())
			{
				this->comboBox1->Items->Add(gcnew String(item->accessData()->getName().c_str()));
			}
			for (auto * item : *data->getOkresy())
			{
				this->comboBox2->Items->Add(gcnew String(item->accessData()->getName().c_str()));
			}
			for (auto * item : *data->getObce())
			{
				item->accessData()->toString();
				this->comboBox3->Items->Add(gcnew String(item->accessData()->getName().c_str()));
			}
		}*/

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			if (loader) {
				delete loader;
				loader = nullptr;
			}
			if (app) {
				delete app;
				app = nullptr;
			}
		}



	private: Nacitanie* loader;
	private: App* app;


	private: System::Windows::Forms::DataGridView^  dataGridView1;












	private: System::Windows::Forms::GroupBox^  groupBox1;







	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  zobrazObce;

	private: System::Windows::Forms::RadioButton^  zobrazOkresy;

	private: System::Windows::Forms::RadioButton^  zobrazKraje;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::RadioButton^  sortUcastRadio;

	private: System::Windows::Forms::RadioButton^  sortVoliciRadio;

	private: System::Windows::Forms::RadioButton^  sortNazovRadio;

	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::RadioButton^  prveKolo;
	private: System::Windows::Forms::RadioButton^  obidveKola;


	private: System::Windows::Forms::RadioButton^  druheKolo;
	private: System::Windows::Forms::Button^  button1;


	private: System::Windows::Forms::RadioButton^  filterNazovRadio;
	private: System::Windows::Forms::RadioButton^  filterUcastRadio;


	private: System::Windows::Forms::RadioButton^  filterVoliciRadio;
	private: System::Windows::Forms::TextBox^  textBox1;



	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button2;







	protected:

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->filterUcastRadio = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->filterVoliciRadio = (gcnew System::Windows::Forms::RadioButton());
			this->filterNazovRadio = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->zobrazObce = (gcnew System::Windows::Forms::RadioButton());
			this->zobrazOkresy = (gcnew System::Windows::Forms::RadioButton());
			this->zobrazKraje = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->sortUcastRadio = (gcnew System::Windows::Forms::RadioButton());
			this->sortVoliciRadio = (gcnew System::Windows::Forms::RadioButton());
			this->sortNazovRadio = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->obidveKola = (gcnew System::Windows::Forms::RadioButton());
			this->druheKolo = (gcnew System::Windows::Forms::RadioButton());
			this->prveKolo = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(540, 593);
			this->dataGridView1->TabIndex = 21;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->filterUcastRadio);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->filterVoliciRadio);
			this->groupBox1->Controls->Add(this->filterNazovRadio);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->numericUpDown4);
			this->groupBox1->Controls->Add(this->numericUpDown3);
			this->groupBox1->Controls->Add(this->numericUpDown2);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Location = System::Drawing::Point(577, 306);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(282, 299);
			this->groupBox1->TabIndex = 28;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Filtre";
			// 
			// filterUcastRadio
			// 
			this->filterUcastRadio->AutoSize = true;
			this->filterUcastRadio->Location = System::Drawing::Point(6, 168);
			this->filterUcastRadio->Name = L"filterUcastRadio";
			this->filterUcastRadio->Size = System::Drawing::Size(111, 17);
			this->filterUcastRadio->TabIndex = 44;
			this->filterUcastRadio->Text = L"Volebná účasť (%)";
			this->filterUcastRadio->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(10, 237);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(241, 44);
			this->button1->TabIndex = 42;
			this->button1->Text = L"ZOBRAZ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// filterVoliciRadio
			// 
			this->filterVoliciRadio->AutoSize = true;
			this->filterVoliciRadio->Location = System::Drawing::Point(6, 93);
			this->filterVoliciRadio->Name = L"filterVoliciRadio";
			this->filterVoliciRadio->Size = System::Drawing::Size(97, 17);
			this->filterVoliciRadio->TabIndex = 43;
			this->filterVoliciRadio->Text = L"Zapísaný voliči";
			this->filterVoliciRadio->UseVisualStyleBackColor = true;
			// 
			// filterNazovRadio
			// 
			this->filterNazovRadio->AutoSize = true;
			this->filterNazovRadio->Checked = true;
			this->filterNazovRadio->Location = System::Drawing::Point(6, 29);
			this->filterNazovRadio->Name = L"filterNazovRadio";
			this->filterNazovRadio->Size = System::Drawing::Size(98, 17);
			this->filterNazovRadio->TabIndex = 42;
			this->filterNazovRadio->TabStop = true;
			this->filterNazovRadio->Text = L"Hľadaný názov";
			this->filterNazovRadio->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 52);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(245, 20);
			this->textBox1->TabIndex = 41;
			this->textBox1->Text = L"Žilina";
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->DecimalPlaces = 2;
			this->numericUpDown4->Location = System::Drawing::Point(139, 200);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(112, 20);
			this->numericUpDown4->TabIndex = 39;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDown4->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown4_ValueChanged);
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->DecimalPlaces = 2;
			this->numericUpDown3->Location = System::Drawing::Point(6, 200);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(112, 20);
			this->numericUpDown3->TabIndex = 38;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(139, 125);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 70000, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(112, 20);
			this->numericUpDown2->TabIndex = 37;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(6, 125);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(112, 20);
			this->numericUpDown1->TabIndex = 36;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->zobrazObce);
			this->groupBox2->Controls->Add(this->zobrazOkresy);
			this->groupBox2->Controls->Add(this->zobrazKraje);
			this->groupBox2->Location = System::Drawing::Point(702, 23);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(80, 118);
			this->groupBox2->TabIndex = 40;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Zobraz";
			// 
			// zobrazObce
			// 
			this->zobrazObce->AutoSize = true;
			this->zobrazObce->Checked = true;
			this->zobrazObce->Location = System::Drawing::Point(6, 84);
			this->zobrazObce->Name = L"zobrazObce";
			this->zobrazObce->Size = System::Drawing::Size(51, 17);
			this->zobrazObce->TabIndex = 2;
			this->zobrazObce->TabStop = true;
			this->zobrazObce->Text = L"Obce";
			this->zobrazObce->UseVisualStyleBackColor = true;
			this->zobrazObce->CheckedChanged += gcnew System::EventHandler(this, &MyForm::zobrazObce_CheckedChanged);
			// 
			// zobrazOkresy
			// 
			this->zobrazOkresy->AutoSize = true;
			this->zobrazOkresy->Location = System::Drawing::Point(6, 52);
			this->zobrazOkresy->Name = L"zobrazOkresy";
			this->zobrazOkresy->Size = System::Drawing::Size(58, 17);
			this->zobrazOkresy->TabIndex = 1;
			this->zobrazOkresy->Text = L"Okresy";
			this->zobrazOkresy->UseVisualStyleBackColor = true;
			this->zobrazOkresy->CheckedChanged += gcnew System::EventHandler(this, &MyForm::zobrazOkresy_CheckedChanged);
			// 
			// zobrazKraje
			// 
			this->zobrazKraje->AutoSize = true;
			this->zobrazKraje->Location = System::Drawing::Point(6, 19);
			this->zobrazKraje->Name = L"zobrazKraje";
			this->zobrazKraje->Size = System::Drawing::Size(49, 17);
			this->zobrazKraje->TabIndex = 0;
			this->zobrazKraje->Text = L"Kraje";
			this->zobrazKraje->UseVisualStyleBackColor = true;
			this->zobrazKraje->CheckedChanged += gcnew System::EventHandler(this, &MyForm::zobrazKraje_CheckedChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Controls->Add(this->comboBox1);
			this->groupBox3->Controls->Add(this->sortUcastRadio);
			this->groupBox3->Controls->Add(this->sortVoliciRadio);
			this->groupBox3->Controls->Add(this->sortNazovRadio);
			this->groupBox3->Location = System::Drawing::Point(578, 165);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(281, 116);
			this->groupBox3->TabIndex = 41;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Zoraď";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(124, 50);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 47);
			this->button2->TabIndex = 44;
			this->button2->Text = L"ZORAĎ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"vzostupne", L"zostupne" });
			this->comboBox1->Location = System::Drawing::Point(124, 15);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(97, 21);
			this->comboBox1->Sorted = true;
			this->comboBox1->TabIndex = 43;
			this->comboBox1->Text = L"vzostupne";
			// 
			// sortUcastRadio
			// 
			this->sortUcastRadio->AutoSize = true;
			this->sortUcastRadio->Location = System::Drawing::Point(9, 80);
			this->sortUcastRadio->Name = L"sortUcastRadio";
			this->sortUcastRadio->Size = System::Drawing::Size(54, 17);
			this->sortUcastRadio->TabIndex = 2;
			this->sortUcastRadio->Text = L"Účasť";
			this->sortUcastRadio->UseVisualStyleBackColor = true;
			// 
			// sortVoliciRadio
			// 
			this->sortVoliciRadio->AutoSize = true;
			this->sortVoliciRadio->Location = System::Drawing::Point(9, 49);
			this->sortVoliciRadio->Name = L"sortVoliciRadio";
			this->sortVoliciRadio->Size = System::Drawing::Size(50, 17);
			this->sortVoliciRadio->TabIndex = 1;
			this->sortVoliciRadio->Text = L"Voliči";
			this->sortVoliciRadio->UseVisualStyleBackColor = true;
			// 
			// sortNazovRadio
			// 
			this->sortNazovRadio->AllowDrop = true;
			this->sortNazovRadio->AutoSize = true;
			this->sortNazovRadio->Checked = true;
			this->sortNazovRadio->Location = System::Drawing::Point(7, 19);
			this->sortNazovRadio->Name = L"sortNazovRadio";
			this->sortNazovRadio->Size = System::Drawing::Size(56, 17);
			this->sortNazovRadio->TabIndex = 0;
			this->sortNazovRadio->TabStop = true;
			this->sortNazovRadio->Text = L"Nazov";
			this->sortNazovRadio->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->obidveKola);
			this->groupBox4->Controls->Add(this->druheKolo);
			this->groupBox4->Controls->Add(this->prveKolo);
			this->groupBox4->Location = System::Drawing::Point(581, 23);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(105, 118);
			this->groupBox4->TabIndex = 40;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Volebné kolo";
			// 
			// obidveKola
			// 
			this->obidveKola->Appearance = System::Windows::Forms::Appearance::Button;
			this->obidveKola->Location = System::Drawing::Point(6, 84);
			this->obidveKola->Name = L"obidveKola";
			this->obidveKola->Size = System::Drawing::Size(77, 23);
			this->obidveKola->TabIndex = 29;
			this->obidveKola->Text = L"SPOLU";
			this->obidveKola->UseVisualStyleBackColor = true;
			this->obidveKola->CheckedChanged += gcnew System::EventHandler(this, &MyForm::obidveKola_CheckedChanged);
			// 
			// druheKolo
			// 
			this->druheKolo->Appearance = System::Windows::Forms::Appearance::Button;
			this->druheKolo->Location = System::Drawing::Point(6, 52);
			this->druheKolo->Name = L"druheKolo";
			this->druheKolo->Size = System::Drawing::Size(77, 23);
			this->druheKolo->TabIndex = 28;
			this->druheKolo->Text = L"2. KOLO";
			this->druheKolo->UseVisualStyleBackColor = true;
			this->druheKolo->CheckedChanged += gcnew System::EventHandler(this, &MyForm::druheKolo_CheckedChanged);
			// 
			// prveKolo
			// 
			this->prveKolo->Appearance = System::Windows::Forms::Appearance::Button;
			this->prveKolo->Checked = true;
			this->prveKolo->Location = System::Drawing::Point(6, 19);
			this->prveKolo->Name = L"prveKolo";
			this->prveKolo->Size = System::Drawing::Size(77, 23);
			this->prveKolo->TabIndex = 27;
			this->prveKolo->TabStop = true;
			this->prveKolo->Text = L"1. KOLO";
			this->prveKolo->UseVisualStyleBackColor = true;
			this->prveKolo->CheckedChanged += gcnew System::EventHandler(this, &MyForm::prveKolo_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(878, 617);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"Semestralna praca 2 - Výsledky volieb";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		int getSelectedKolo()
		{
			if (prveKolo->Checked) { return 1; };
			if (druheKolo->Checked) { return 2; };
			if (obidveKola->Checked) { return 0; };
			return -1;
		}

		void updateTable()
		{
			updateTableHeaders();

			this->dataGridView1->Rows->Clear();
			/* if (zobrazKraje->Checked)
			 {
				 zobrazTabulkuDoDataGridView(*loader->getKraje());
			 }
			 else if (zobrazOkresy->Checked)
			 {
				 zobrazTabulkuDoDataGridView(*loader->getOkresy());
			 }
			 else
			 {
				 zobrazTabulkuDoDataGridView(*loader->getObce());
			 }*/
		}
		template <typename T>
		void zobrazTabulkuDoDataGridView(T *tabulka)
		{
			int i;
			for (auto item : *tabulka)
			{
				i = this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[i]->Cells[0]->Value = System::Convert::ToString(item->accessData()->getClassName().c_str());
				this->dataGridView1->Rows[i]->Cells[1]->Value = System::Convert::ToString(item->accessData()->getName().c_str());
			}
		}

		void arrayListToDataGridTable(structures::ArrayList<Area*> *arrayList)
		{
			//throw std::exception("Not finished yet!");

			this->dataGridView1->Rows->Clear();
			for each (Area* area in *arrayList)
			{
				//cout << typeid(area).name() << endl;
				cout << "Found  wit filter Area type " << area->getClassName() << endl;
				auto row = this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[row]->Cells[0]->Value = gcnew String(area->getClassName().c_str());
				this->dataGridView1->Rows[row]->Cells[1]->Value = gcnew String(area->getName().c_str());
				this->dataGridView1->Rows[row]->Cells[2]->Value = roundAndFormat(area->getPocetVolicov(1));
				this->dataGridView1->Rows[row]->Cells[3]->Value = roundAndFormat(area->getPocetVolicov(2));
				this->dataGridView1->Rows[row]->Cells[4]->Value = roundAndFormat(area->getUcastVolicov(1), 2);
				this->dataGridView1->Rows[row]->Cells[5]->Value = roundAndFormat(area->getUcastVolicov(2), 2);
			}
		}

		System::String^  roundAndFormat(const double x) { return roundAndFormat(x, 0); }
		System::String^  roundAndFormat(const double x, const int decDigits) {
			stringstream ss;
			ss << fixed;
			ss.precision(decDigits); // set # places after decimal
			ss << x;
			return gcnew String(ss.str().c_str());
		}

		void updateTableHeaders()
		{
			// TODO parsing string as oznacenie/kluc toho stlpca
			string headerTableItems[14] = {
				"Kraj","Okres",
				"Voliči 1.kolo", "Voliči 2.kolo","Voliči spolu",
				"Účasť 1.kolo","Účasť 2.kolo","Účasť spolu",
				"Vydané obálky 1.kolo","Vydané obálky 2.kolo","Vydané obálky spolu",
				"Prijaté obálky 1.kolo","Prijaté obálky 2.kolo","Prijaté obálky spolu"
			};

			this->dataGridView1->Columns->Add("Typ", "Typ");
			this->dataGridView1->Columns->Add("Nazov", "Názov");
			//this->dataGridView1->Columns["Voliči 1.kolo"]->Visible = false;

			// TODO vytvor tabuľku a následne len skry odkry stĺpce
			for (int i = 0; i < _countof(headerTableItems); i++)
			{
				if (this->obidveKola->Checked)
				{
					this->dataGridView1->Columns->Add(gcnew String(headerTableItems[i].c_str()), gcnew String(headerTableItems[i].c_str()));
				}
				else
				{
					if (this->prveKolo->Checked && i % 3 == 0)
					{
						this->dataGridView1->Columns->Add(gcnew String(headerTableItems[i].c_str()), gcnew String(headerTableItems[i].c_str()));

					}
					if (this->druheKolo->Checked && i % 3 == 1)
					{
						this->dataGridView1->Columns->Add(gcnew String(headerTableItems[i].c_str()), gcnew String(headerTableItems[i].c_str()));
					}
				}

			}
		}

	public: static std::string toStandardString(System::String^ string)
	{
		using System::Runtime::InteropServices::Marshal;
		if (string->Length == 0 || string->Length < 0) { MessageBox::Show("No field can be empty"); }
		System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
		char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
		std::string returnString(charPointer, string->Length);
		Marshal::FreeHGlobal(pointer);
		return returnString;
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//selectedArea = 
		//textBox1->Text = gcnew String(selectedArea);
	}

	private: System::Void comboBox1_ContextMenuStripChanged(System::Object^  sender, System::EventArgs^  e) {
		//selectedArea = comboBox1->GetItemText();
		//textBox1->Text = gcnew String(comboBox1->SelectedItem->ToString());
		//textBox1->Text = gcnew String(selectedArea->toString());
	}
	private: System::Void comboBox1_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) {
		//textBox1->Text = gcnew String(comboBox1->SelectedItem->ToString());
	}
	private: System::Void checkedListBox1_ItemCheck(System::Object^  sender, System::Windows::Forms::ItemCheckEventArgs^  e) {
		updateTable();
	}
	private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		updateTable();
	}
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
		updateTableHeaders();
		if (filterNazovRadio->Checked)
		{
			// TODO tabuľka - skryť odkryť ? zobraziť nezobraziť ?
			//throw std::exception("Not finished yet!");

			structures::ArrayList<Area*>* areas = app->getAreasNazov(toStandardString(textBox1->Text->ToString()));
			arrayListToDataGridTable(areas);

			delete areas;
		}

		if (filterVoliciRadio->Checked)
		{
			if (numericUpDown1->Value > numericUpDown2->Value) {
				MessageBox::Show("Hodnota od musí byť menšia ako hodnota do");
				return;
			}

			int selectedKolo = getSelectedKolo();

			if (selectedKolo == 1 || selectedKolo == 2)
			{
				structures::ArrayList<Area*>* areas = app->getAreasVolici((int)numericUpDown1->Value, (int)numericUpDown2->Value, selectedKolo);
				arrayListToDataGridTable(areas);
				delete areas;
			}
			else
			{
				MessageBox::Show("Pre toto kolo, alebo ich súčet, nie je možné nájsť výsledky");
			}
		}
		if (filterUcastRadio->Checked)
		{
			if (numericUpDown3->Value > numericUpDown4->Value) {
				MessageBox::Show("Hodnota od musí byť menšia ako hodnota do");
				return;
			}

			int selectedKolo = getSelectedKolo();
			if (selectedKolo == 1 || selectedKolo == 2)
			{
				structures::ArrayList<Area*>* areas = app->getAreasUcast((double)numericUpDown3->Value, (double)numericUpDown4->Value, selectedKolo);
				arrayListToDataGridTable(areas);
				delete areas;
			}
			else
			{
				MessageBox::Show("Pre toto kolo, alebo ich súčet, nie je možné nájsť výsledky");
			}
		}
	}

	private: System::Void zobrazKraje_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (zobrazKraje->Checked)
		{
			updateTable();
		}
	}
	private: System::Void zobrazObce_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (zobrazObce->Checked)
		{
			// len vtedy, keď zaškrtnem túto možnosť
			updateTable();
		}
	}
	private: System::Void zobrazOkresy_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (zobrazOkresy->Checked)
		{
			// len vtedy, keď zaškrtnem túto možnosť
			updateTable();
		}
	}
	private: System::Void prveKolo_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (prveKolo->Checked)
		{
			// len vtedy, keď zaškrtnem túto možnosť
			/*updateTable();*/
		}
	}
	private: System::Void druheKolo_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (prveKolo->Checked)
		{
			// len vtedy, keď zaškrtnem túto možnosť
			/*updateTable();*/
		}
	}
	private: System::Void obidveKola_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (obidveKola->Checked)
		{
			//this->dataGridView1->Columns->Add(gcnew String(headerTableItems[i].c_str()), gcnew String(headerTableItems[i].c_str()));
			// len vtedy, keď zaškrtnem túto možnosť
			/*updateTable();*/
		}
	}
	private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void numericUpDown4_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		auto test = comboBox1->SelectedItem->ToString();

		if (this->getSelectedKolo() == 1 || this->getSelectedKolo() == 2)
		{
			this->dataGridView1->Rows->Clear();

			if (test == "zostupne")
			{
				if (sortNazovRadio->Checked)
				{
					// vypíše SST tabuľku v opačnom poradí 
					int i = loader->getObce()->size() - 1;
					this->dataGridView1->Rows->Add(loader->getObce()->size());

					for each (auto obec in *loader->getObce())
					{
						this->dataGridView1->Rows[i]->Cells[0]->Value =
							gcnew String(obec->accessData()->getName().c_str());
						i--;
					}
				}
				if (sortVoliciRadio->Checked)
				{
					structures::UnsortedSequenceTable<SortingKey<int>*, Obec*>*  obce;
					if (this->getSelectedKolo() == 1)
					{
						obce = loader->getObceUnsortedVolici1();
					}
					else
					{
						obce = loader->getObceUnsortedVolici2();
					}

					app->sortTable(obce);
					for (int i = obce->size() - 1; i >= 0; --i) {
						mojatest<structures::TableItem<SortingKey<int> *, Obec *>>(obce->getItemAtIndex(i));
					}
				}
				if (sortUcastRadio->Checked)
				{
					structures::UnsortedSequenceTable<SortingKey<double>*, Obec*>*  obce;
					if (this->getSelectedKolo() == 1)
					{
						obce = loader->getObceUnsortedUcast1();
					}
					else
					{
						obce = loader->getObceUnsortedUcast2();
					}

					app->sortTable(obce);
					for (int i = obce->size() - 1; i >= 0; --i) {
						mojatest<structures::TableItem<SortingKey<double> *, Obec *>>(obce->getItemAtIndex(i));
					}
				}
			}
			else
			{
				if (sortNazovRadio->Checked)
				{
					// vypíše SST tabuľku v opačnom poradí 
					for each (auto obec in *loader->getObce())
					{
						this->dataGridView1->Rows[this->dataGridView1->Rows->Add()]->Cells[0]->Value =
							gcnew String(obec->accessData()->getName().c_str());
					}
				}
				if (sortVoliciRadio->Checked)
				{
					structures::UnsortedSequenceTable<SortingKey<int>*, Obec*>*  obce;
					if (this->getSelectedKolo() == 1)
					{
						obce = loader->getObceUnsortedVolici1();
					}
					else
					{
						obce = loader->getObceUnsortedVolici2();
					}

					app->sortTable(obce);
					for (auto i = 0; i < obce->size(); i++) {
						mojatest<structures::TableItem<SortingKey<int> *, Obec *>>(obce->getItemAtIndex(i));
					}
				}
				if (sortUcastRadio->Checked)
				{
					structures::UnsortedSequenceTable<SortingKey<double>*, Obec*>*  obce;
					if (this->getSelectedKolo() == 1)
					{
						obce = loader->getObceUnsortedUcast1();
					}
					else
					{
						obce = loader->getObceUnsortedUcast2();
					}

					app->sortTable(obce);
					for (auto i = 0; i < obce->size(); i++) {
						mojatest<structures::TableItem<SortingKey<double> *, Obec *>>(obce->getItemAtIndex(i));
					}
				}
			}
		}
		else
		{
			MessageBox::Show("Pre toto kolo, alebo ich súčet, nie je možné zoradiť výsledky");
		}
	}
			 template <typename T>
			 void mojatest(T &test)
			 {
				 int index = this->dataGridView1->Rows->Add();
				 this->dataGridView1->Rows[index]->Cells[0]->Value =
					 System::Convert::ToString(test.accessData()->getName().c_str());
				 this->dataGridView1->Rows[index]->Cells[1]->Value =
					 System::Convert::ToString(test.accessData()->getPocetVolicov(1));
				 this->dataGridView1->Rows[index]->Cells[2]->Value =
					 System::Convert::ToString(test.accessData()->getPocetVolicov(2));
				 this->dataGridView1->Rows[index]->Cells[3]->Value =
					 System::Convert::ToString(test.accessData()->getUcastVolicov(1));
				 this->dataGridView1->Rows[index]->Cells[4]->Value =
					 System::Convert::ToString(test.accessData()->getUcastVolicov(2));
			 }

	};
}
