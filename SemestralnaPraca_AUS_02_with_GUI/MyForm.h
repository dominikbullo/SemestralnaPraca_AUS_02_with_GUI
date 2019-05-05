#pragma once
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
			app = new App(loader->getData());

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
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::RadioButton^  prveKolo;
	private: System::Windows::Forms::RadioButton^  obidveKola;


	private: System::Windows::Forms::RadioButton^  druheKolo;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::RadioButton^  filterNazovRadio;

	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;






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
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->filterNazovRadio = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->zobrazObce = (gcnew System::Windows::Forms::RadioButton());
			this->zobrazOkresy = (gcnew System::Windows::Forms::RadioButton());
			this->zobrazKraje = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->obidveKola = (gcnew System::Windows::Forms::RadioButton());
			this->druheKolo = (gcnew System::Windows::Forms::RadioButton());
			this->prveKolo = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->filterNazovRadio);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->numericUpDown4);
			this->groupBox1->Controls->Add(this->numericUpDown3);
			this->groupBox1->Controls->Add(this->numericUpDown2);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Location = System::Drawing::Point(581, 160);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(357, 247);
			this->groupBox1->TabIndex = 28;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Filtre";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(6, 168);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(111, 17);
			this->radioButton3->TabIndex = 44;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Volebná účasť (%)";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 93);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(97, 17);
			this->radioButton2->TabIndex = 43;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Zapísaný voliči";
			this->radioButton2->UseVisualStyleBackColor = true;
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
			this->textBox1->Location = System::Drawing::Point(111, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(140, 20);
			this->textBox1->TabIndex = 41;
			this->textBox1->Text = L"Žilina";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(6, 54);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(245, 21);
			this->comboBox1->TabIndex = 40;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(139, 200);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(112, 20);
			this->numericUpDown4->TabIndex = 39;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// numericUpDown3
			// 
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
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 70000, 0, 0, 0 });
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
			this->groupBox2->Location = System::Drawing::Point(720, 23);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(103, 118);
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
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->radioButton4);
			this->groupBox3->Controls->Add(this->radioButton5);
			this->groupBox3->Controls->Add(this->radioButton6);
			this->groupBox3->Location = System::Drawing::Point(581, 426);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(103, 118);
			this->groupBox3->TabIndex = 41;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Zoraď";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(6, 84);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(54, 17);
			this->radioButton4->TabIndex = 2;
			this->radioButton4->Text = L"Účasť";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(6, 52);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(50, 17);
			this->radioButton5->TabIndex = 1;
			this->radioButton5->Text = L"Voliči";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Checked = true;
			this->radioButton6->Location = System::Drawing::Point(6, 19);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(56, 17);
			this->radioButton6->TabIndex = 0;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"Nazov";
			this->radioButton6->UseVisualStyleBackColor = true;
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
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(863, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 118);
			this->button1->TabIndex = 42;
			this->button1->Text = L"ZOBRAZ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(964, 617);
			this->Controls->Add(this->button1);
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
			 void updateTable()
			 {
				 updateTableHeaders();
				 if (this->dataGridView1->Columns->Count <= 0) { return; }

				 this->dataGridView1->Rows->Clear();
				 VolebneKolo* tmp = app->getVolebneKolo(1);
				 int i = 0;

				 if (zobrazKraje->Checked)
				 {
					 for (auto * item : *tmp->getKraje())
					 {
						 this->dataGridView1->Rows->Add();
						 this->dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(item->accessData()->getName().c_str());
						 ++i;
					 }
				 }
				 else if (zobrazOkresy->Checked)
				 {
					 for (auto * item : *tmp->getOkresy())
					 {
						 this->dataGridView1->Rows->Add();
						 this->dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(item->accessData()->getName().c_str());
						 ++i;
					 }
				 }
				 else if (zobrazObce->Checked)
				 {
					 for (auto * item : *tmp->getObce())
					 {
						 this->dataGridView1->Rows->Add();
						 this->dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(item->accessData()->getName().c_str());
						 ++i;
					 }
				 }
			 }

			 void updateTableHeaders()
			 {
				 this->dataGridView1->Columns->Clear();
				 this->dataGridView1->Columns->Add("Area", "Area");

				 string test[8] = {
					 "Voliči 1.kolo", "Voliči 2.kolo",
					 "Účasť 1.kolo","Účasť 2.kolo",
					 "Vydané obálky 1.kolo","Vydané obálky 2.kolo",
					 "Prijaté obálky 1.kolo","Prijaté obálky 2.kolo"
				 };

				 for (int i = 0; i < _countof(test); i++)
				 {
					 if (this->obidveKola->Checked)
					 {
						 auto selection = test[i];
						 this->dataGridView1->Columns->Add(gcnew String(selection.c_str()), gcnew String(selection.c_str()));
					 }
					 else
					 {
						 if (this->prveKolo->Checked && i % 2 == 0)
						 {
							 auto selection = test[i];
							 this->dataGridView1->Columns->Add(gcnew String(selection.c_str()), gcnew String(selection.c_str()));

						 }
						 if (this->druheKolo->Checked && i % 2 != 0)
						 {
							 auto selection = test[i];
							 this->dataGridView1->Columns->Add(gcnew String(selection.c_str()), gcnew String(selection.c_str()));
						 }
					 }

					 // TODO parsing string as oznacenie/kluc toho stlpca
				 }
			 }

	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
		//app->test();
		using System::Runtime::InteropServices::Marshal;

		if (filterNazovRadio->Checked) {
			app->getArea(toStandardString(textBox1->Text->ToString()));
		}
		updateTable();
	}
	public:  static std::string toStandardString(System::String^ string)
	{
		using System::Runtime::InteropServices::Marshal;

		if (string->Length == 0 || string->Length < 0)
		{
			MessageBox::Show("No field can be empty");

		}

		System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
		char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
		std::string returnString(charPointer, string->Length);
		Marshal::FreeHGlobal(pointer);


		return returnString;
	}
	};
}
