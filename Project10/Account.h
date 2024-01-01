#pragma once
#include "FileReader.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>  
#include <vcclr.h>  
#include "consts.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
#include <msclr/marshal_windows.h>
#include  "Entry.h"
namespace Project10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Account
	/// </summary>
	/// 
	

	public ref class Account : public System::Windows::Forms::Form
	{
	public:
		Account(void)
		{
			InitializeComponent();
		
		}

	protected:
		 
		~Account()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	 
	private: System::Windows::Forms::Panel^ panelFavourite;
	private: System::Windows::Forms::PictureBox^ deletePicture;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label28;

	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::ComboBox^ comboBox5;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Label^ label33;

	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ addToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::Panel^ panel12;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::Panel^ panel13;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Label^ label36;


	protected:

	protected:
		System::Windows::Forms::DataGridView^ dataGridView;

		System::Void DataGridView_ColumnHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
			DataGridView^ dataGridView = safe_cast<System::Windows::Forms::DataGridView^>(sender);

			if (dataGridView != nullptr && e->ColumnIndex >= 0) {

				int columnIndex = e->ColumnIndex;


				if (dataGridView->SortOrder == System::Windows::Forms::SortOrder::Ascending) {
					dataGridView->Sort(dataGridView->Columns[columnIndex], System::ComponentModel::ListSortDirection::Ascending);
				}
				else {
					dataGridView->Sort(dataGridView->Columns[columnIndex], System::ComponentModel::ListSortDirection::Descending);
				}
			}
		}


	private:
		System::ComponentModel::Container ^components;
 
		array<String^>^ headersOfTable;
		array<String^>^ arrayOfPersonalData;
		array<String^>^ arrayOfRenderItems;
		array<String^>^ arrayOfAllDataSortedByAccessibility;
		array<String^>^ arrayOfAllDataSortedByFull;
		array<String^>^ arrayOfAllDataSortedByParticularly;
		array<String^>^ arrayOfAllDataFoundElems;
		array<String^>^ arrayOfFoundedElement;
		array<String^>^ arrayOfPersonalFavItems;
		array<String^>^ arrayOfPersonalFavItemsCopy;
		array<String^>^ arrayOfRenderElement;
		array<String^>^ arrayOfFavStroke;
		array<String^>^ arrayOfFavStrokeFavourite;
		array<String^>^ arrayOfTitles;
		array<String^>^ arrayOfType;
		array<String^>^ arrayOfRate;
		array<String^>^ arrayOfAccesibility;
		array<String^>^ arrayOfPrice;
		array<String^>^ arrayOfId;
		array<String^>^ arrayOfPit;
		array<String^>^ arrayOfData;
		array<String^>^ arrayOfCountry;
		array<String^>^ arrayOfUrl;
		array<String^>^ arrayOfAllData;
		TextBox^ inputTextPassword;
		TextBox^ inputTextEmail;
		TextBox^ inputTextBox;
		TextBox^ inputAuthTextPassword;
		TextBox^ inputAuthTextEmail;
		int indexOfTitlesColumn = 0;
		int indexOfImage = 0;
		System::String^ indexOfImageString = "";
		int entriesSize = 0;
		System::String^ typedTitle = "";
		System::String^ loginStrokeString = "";
		System::String^ nameOfUser = "";
		System::String^ foundElement = "";
		System::String^ authEmail = "";
		System::String^ authPassword = "";
		System::Boolean isAutherizated = false;
		System::String^ renderFavourite = "";
		System::String^ favStroke = "";
		System::String^ getFavouriteElemsString = "";
		System::String^ selectedGrid = "";
		System::String^ selectedTodeleteItem = "";
		System::String^ selectedId = "";
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Button^ button7;
private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::Panel^ panel7;
private: System::Windows::Forms::Panel^ panel6;
private: System::Windows::Forms::Button^ button9;
private: System::Windows::Forms::Button^ button8;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::TextBox^ textBox6;
private: System::Windows::Forms::ComboBox^ comboBox1;
private: System::Windows::Forms::ComboBox^ comboBox2;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::TextBox^ textBox7;
private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Button^ button10;
private: System::Windows::Forms::TextBox^ textBox8;
private: System::Windows::Forms::Button^ button11;
	   System::String^ selectedElement = "";
	void	LoadData(String^ method) {
		arrayOfPersonalData = gcnew array<String^>(5);
			std::string filename = "input.txt";
			FileReader reader(filename);
			reader.readFile();
			try {
				nameOfUser = msclr::interop::marshal_as<System::String^>(reader.getConsts());
				isAutherizated = true;
				array<System::String^>^ arrayOf = loginStrokeString->Split(':');
				arrayOfPersonalData[0] = arrayOf[0];
				arrayOfPersonalData[1] = arrayOf[1];
				arrayOfPersonalData[2] = arrayOf[2];
				nameOfUser = arrayOfPersonalData[0];
				this->panel2->Visible = false;
				this->panel3->Visible = true;
				this->label10->Text = nameOfUser;
				 
			}
			catch (const System::Exception^ ex) {
			 
				isAutherizated = false;
			}
			reader.showStructureOfUsers();
			std::vector<std::string> data = reader.getArrayofGettedData();
			String^ imageUrl = "https://fikiwiki.com/uploads/posts/2022-02/1644918620_17-fikiwiki-com-p-krasivie-kartinki-visokogo-razresheniya-19.jpg";
			std::vector<Entry> entries;

			for (const std::string& line : data) {
				Entry entry;
				reader.parseInput(line, entry);
				entries.push_back(entry);
			}
			if (method->Contains("login")) {
				String^ text2 = textBox4->Text;
				String^ text1 = textBox5->Text;
				authEmail = text1;
				authPassword = text2;
				std::string loginStroke = reader.login(text2, text1);
				loginStrokeString = gcnew System::String(loginStroke.c_str());




				if (text1->Length > 0 && text2->Length > 0) {

				if (loginStrokeString->Contains("Incorrect")) {
					this->label11->Visible = true;
					this->label11->BringToFront();
				}
				else {
					if (nameOfUser != nullptr) {
						isAutherizated = true;
						array<System::String^>^ arrayOf = loginStrokeString->Split(':');
						arrayOfPersonalData[0] = arrayOf[0];
						arrayOfPersonalData[1] = arrayOf[1];
						arrayOfPersonalData[2] = arrayOf[2];
						nameOfUser = arrayOfPersonalData[0];
						if(arrayOfPersonalData[0]->Contains("admin")) {
							 this->panel5->Visible = true;
							 this->panel5->BringToFront();
							this->panel3->Visible = false;
							this->panel2->Visible = false;
						} 
						else {
						this->panel2->Visible = false;
						this->panel3->Visible = true;
						}
						this->label10->Text = nameOfUser;
						reader.storeConsts(arrayOfPersonalData[0], arrayOfPersonalData[1], arrayOfPersonalData[2]);

					}
				}

				}
				else {
					System::Windows::Forms::MessageBox::Show("Form boxes cannot be empty!!!");
				}





			}
			if (method->Contains("register")) {

				String^ text = textBox1->Text;
				String^ text1 = textBox2->Text;
				String^ text2= textBox3->Text;

				bool isUnique= reader.checkUsername(text);
				bool isEmail = false;
				if (text1->Contains("@")) {
					isEmail = true;
				}
				bool isCorrect = false;
				if (text2->Length > 6) {
					isCorrect = true;
				}




				if(!isUnique && isEmail && isCorrect){
				nameOfUser = text;

				//if (text->Length > 0 && text1->Length >0  && text2->Length >0) {

				reader.registerUser(text, text1, text2);
			//	}
				//else {
					System::Windows::Forms::MessageBox::Show("You have been successfully registered!");
			//	}
				 
	 	isAutherizated = true;
				arrayOfPersonalData[0] = text;
				arrayOfPersonalData[1] = text1;
				arrayOfPersonalData[2] = text2;  


			//if (!arrayOfPersonalData[0]->Contains("admin")) {

			
			 	this->panel1->Visible = false;
		 	this->panel2->Visible = true;
				} 
				else {
					if (isUnique) {
						this->label12->Visible = true;
					}
					if (!isEmail) {
						this->label13->Visible = true;
					}
					if (!isCorrect) {
						this->label14->Visible = true;
					}



					if (!isUnique) {
						this->label12->Visible = false;
					}
					if (isEmail) {
						this->label13->Visible = false;
					}
					if (isCorrect) {
						this->label14->Visible = false;
					}
				}

		//	}

			}





		}

		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->panel6->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel13->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(56, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(206, 50);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Account::back);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->panel1->Controls->Add(this->label14);
			this->panel1->Controls->Add(this->label13);
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(176, 92);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1616, 855);
			this->panel1->TabIndex = 2;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::Red;
			this->label14->Location = System::Drawing::Point(660, 421);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(469, 29);
			this->label14->TabIndex = 11;
			this->label14->Text = L"Passwort must contain more than 7 characters";
			this->label14->Visible = false;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Red;
			this->label13->Location = System::Drawing::Point(970, 316);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(153, 29);
			this->label13->TabIndex = 10;
			this->label13->Text = L"Enter an email";
			this->label13->Visible = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Red;
			this->label12->Location = System::Drawing::Point(929, 206);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(190, 29);
			this->label12->TabIndex = 9;
			this->label12->Text = L"This name is exists";
			this->label12->Visible = false;
			this->label12->Click += gcnew System::EventHandler(this, &Account::label12_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(542, 421);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(108, 29);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Password";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(542, 316);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 29);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Email";
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Candara", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(547, 530);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(592, 60);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Sign up";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Account::register_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label4->Font = (gcnew System::Drawing::Font(L"Candara", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(722, 622);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(271, 39);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Or have an account";
			this->label4->Click += gcnew System::EventHandler(this, &Account::label4_Click);
			// 
			// textBox3
			// 
			this->textBox3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox3->Location = System::Drawing::Point(539, 453);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(592, 35);
			this->textBox3->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox2->Location = System::Drawing::Point(539, 348);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(590, 35);
			this->textBox2->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox1->Location = System::Drawing::Point(539, 238);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(590, 35);
			this->textBox1->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(542, 206);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 29);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Name";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(741, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(182, 63);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign up";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->textBox5);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(155, 95);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1637, 840);
			this->panel2->TabIndex = 3;
			this->panel2->Visible = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Red;
			this->label11->Location = System::Drawing::Point(580, 429);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(464, 47);
			this->label11->TabIndex = 14;
			this->label11->Text = L"Incorrect password or email";
			this->label11->Visible = false;
			// 
			// textBox5
			// 
			this->textBox5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox5->Location = System::Drawing::Point(527, 354);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(592, 35);
			this->textBox5->TabIndex = 13;
			// 
			// textBox4
			// 
			this->textBox4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox4->Location = System::Drawing::Point(527, 232);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(592, 35);
			this->textBox4->TabIndex = 12;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label9->Font = (gcnew System::Drawing::Font(L"Candara", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(770, 581);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(151, 39);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Or sign up";
			this->label9->Click += gcnew System::EventHandler(this, &Account::label9_Click);
			// 
			// button3
			// 
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Candara", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(535, 498);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(592, 53);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Submit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Account::login);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(530, 305);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(108, 29);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Password";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(530, 191);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(66, 29);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Email";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(717, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(167, 63);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Sign in";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->button7);
			this->panel3->Controls->Add(this->button6);
			this->panel3->Controls->Add(this->button5);
			this->panel3->Controls->Add(this->button4);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Controls->Add(this->label10);
			this->panel3->Location = System::Drawing::Point(118, 84);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1530, 942);
			this->panel3->TabIndex = 4;
			this->panel3->Visible = false;
			// 
			// button7
			// 
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(514, 703);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(657, 59);
			this->button7->TabIndex = 0;
			this->button7->Text = L"Pay for all";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Visible = false;
			this->button7->Click += gcnew System::EventHandler(this, &Account::buyAll);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(568, 782);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(552, 63);
			this->button6->TabIndex = 4;
			this->button6->Text = L"Exit";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Account::exit);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(1000, 195);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(244, 54);
			this->button5->TabIndex = 3;
			this->button5->Text = L"History";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Account::history);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(405, 195);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(244, 54);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Favourite";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Account::fav);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Orange;
			this->panel4->Location = System::Drawing::Point(248, 255);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1159, 442);
			this->panel4->TabIndex = 1;
			this->panel4->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(751, 106);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(171, 63);
			this->label10->TabIndex = 0;
			this->label10->Text = L"label10";
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->panel8);
			this->panel5->Controls->Add(this->button12);
			this->panel5->Controls->Add(this->panel7);
			this->panel5->Controls->Add(this->button8);
			this->panel5->Controls->Add(this->panel6);
			this->panel5->Controls->Add(this->button11);
			this->panel5->Controls->Add(this->button9);
			this->panel5->Controls->Add(this->label15);
			this->panel5->Controls->Add(this->menuStrip1);
			this->panel5->Location = System::Drawing::Point(88, 77);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(1856, 914);
			this->panel5->TabIndex = 5;
			this->panel5->Visible = false;
			this->panel5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Account::panel5_Paint);
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->panel9);
			this->panel8->Controls->Add(this->label24);
			this->panel8->Controls->Add(this->button13);
			this->panel8->Controls->Add(this->textBox9);
			this->panel8->Controls->Add(this->label23);
			this->panel8->Location = System::Drawing::Point(56, 160);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(1680, 754);
			this->panel8->TabIndex = 8;
			this->panel8->Visible = false;
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->button18);
			this->panel9->Controls->Add(this->button15);
			this->panel9->Controls->Add(this->numericUpDown2);
			this->panel9->Controls->Add(this->textBox13);
			this->panel9->Controls->Add(this->textBox12);
			this->panel9->Controls->Add(this->textBox11);
			this->panel9->Controls->Add(this->comboBox5);
			this->panel9->Controls->Add(this->comboBox4);
			this->panel9->Controls->Add(this->comboBox3);
			this->panel9->Controls->Add(this->label32);
			this->panel9->Controls->Add(this->label31);
			this->panel9->Controls->Add(this->label30);
			this->panel9->Controls->Add(this->label29);
			this->panel9->Controls->Add(this->label28);
			this->panel9->Controls->Add(this->label26);
			this->panel9->Controls->Add(this->label25);
			this->panel9->Controls->Add(this->button14);
			this->panel9->Location = System::Drawing::Point(23, 13);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(1816, 638);
			this->panel9->TabIndex = 9;
			this->panel9->Visible = false;
			// 
			// button18
			// 
			this->button18->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button18->Location = System::Drawing::Point(1194, 201);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(129, 39);
			this->button18->TabIndex = 18;
			this->button18->Text = L"Directory";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &Account::button18_Click);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::IndianRed;
			this->button15->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button15->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->Location = System::Drawing::Point(962, 551);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(477, 61);
			this->button15->TabIndex = 17;
			this->button15->Text = L"Cancel";
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &Account::cancel);
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->numericUpDown2->Location = System::Drawing::Point(443, 432);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(256, 35);
			this->numericUpDown2->TabIndex = 16;
			// 
			// textBox13
			// 
			this->textBox13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox13->Location = System::Drawing::Point(1331, 327);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(251, 35);
			this->textBox13->TabIndex = 15;
			// 
			// textBox12
			// 
			this->textBox12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox12->Location = System::Drawing::Point(1331, 201);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(251, 35);
			this->textBox12->TabIndex = 14;
			// 
			// textBox11
			// 
			this->textBox11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox11->Location = System::Drawing::Point(443, 188);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(251, 35);
			this->textBox11->TabIndex = 13;
			// 
			// comboBox5
			// 
			this->comboBox5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"full", L"particularly" });
			this->comboBox5->Location = System::Drawing::Point(1331, 91);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(251, 37);
			this->comboBox5->TabIndex = 11;
			this->comboBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Account::comboBox5_KeyPress);
			// 
			// comboBox4
			// 
			this->comboBox4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"yes", L"not" });
			this->comboBox4->Location = System::Drawing::Point(443, 305);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(251, 37);
			this->comboBox4->TabIndex = 10;
			this->comboBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Account::comboBox4_KeyPress);
			// 
			// comboBox3
			// 
			this->comboBox3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"hotel", L"restaurant", L"cafe", L"excursion" });
			this->comboBox3->Location = System::Drawing::Point(438, 66);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(256, 37);
			this->comboBox3->TabIndex = 9;
			this->comboBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Account::comboBox3_KeyPress);
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->Location = System::Drawing::Point(1116, 305);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(143, 47);
			this->label32->TabIndex = 8;
			this->label32->Text = L"country";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(1116, 195);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(63, 47);
			this->label31->TabIndex = 7;
			this->label31->Text = L"url";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(1116, 82);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(140, 47);
			this->label30->TabIndex = 6;
			this->label30->Text = L"feeding";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(142, 427);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(99, 47);
			this->label29->TabIndex = 5;
			this->label29->Text = L"price";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->Location = System::Drawing::Point(142, 291);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(209, 47);
			this->label28->TabIndex = 4;
			this->label28->Text = L"accessibility";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(142, 166);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(85, 47);
			this->label26->TabIndex = 2;
			this->label26->Text = L"title";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(142, 54);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(92, 47);
			this->label25->TabIndex = 1;
			this->label25->Text = L"type";
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::DodgerBlue;
			this->button14->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button14->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(482, 550);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(477, 62);
			this->button14->TabIndex = 0;
			this->button14->Text = L"Submit";
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &Account::clickToEdit);
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(461, 129);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(248, 47);
			this->label24->TabIndex = 3;
			this->label24->Text = L"Type id to edit";
			// 
			// button13
			// 
			this->button13->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button13->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(469, 277);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(688, 52);
			this->button13->TabIndex = 2;
			this->button13->Text = L"Search";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Account::findToEdit);
			// 
			// textBox9
			// 
			this->textBox9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox9->Location = System::Drawing::Point(469, 191);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(688, 35);
			this->textBox9->TabIndex = 1;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &Account::textBox9_TextChanged);
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(295, 26);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(110, 63);
			this->label23->TabIndex = 0;
			this->label23->Text = L"Edit";
			// 
			// button12
			// 
			this->button12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button12->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(1128, 170);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(170, 48);
			this->button12->TabIndex = 7;
			this->button12->Text = L"Edit";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Visible = false;
			this->button12->Click += gcnew System::EventHandler(this, &Account::edit);
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->button19);
			this->panel7->Controls->Add(this->button10);
			this->panel7->Controls->Add(this->textBox8);
			this->panel7->Controls->Add(this->label22);
			this->panel7->Controls->Add(this->textBox7);
			this->panel7->Controls->Add(this->label21);
			this->panel7->Controls->Add(this->comboBox2);
			this->panel7->Controls->Add(this->label20);
			this->panel7->Controls->Add(this->numericUpDown1);
			this->panel7->Controls->Add(this->label19);
			this->panel7->Controls->Add(this->label18);
			this->panel7->Controls->Add(this->textBox6);
			this->panel7->Controls->Add(this->comboBox1);
			this->panel7->Controls->Add(this->label17);
			this->panel7->Controls->Add(this->label16);
			this->panel7->Location = System::Drawing::Point(91, 165);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(1751, 650);
			this->panel7->TabIndex = 4;
			this->panel7->Visible = false;
			// 
			// button19
			// 
			this->button19->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button19->Location = System::Drawing::Point(634, 354);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(136, 34);
			this->button19->TabIndex = 14;
			this->button19->Text = L"Directory";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &Account::button19_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button10->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(551, 461);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(531, 90);
			this->button10->TabIndex = 13;
			this->button10->Text = L"Submit";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &Account::addToDatabase);
			// 
			// textBox8
			// 
			this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox8->Location = System::Drawing::Point(384, 354);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(225, 35);
			this->textBox8->TabIndex = 12;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &Account::textBox8_TextChanged);
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(917, 348);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(98, 29);
			this->label22->TabIndex = 11;
			this->label22->Text = L"Location";
			// 
			// textBox7
			// 
			this->textBox7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox7->Location = System::Drawing::Point(1092, 354);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(225, 35);
			this->textBox7->TabIndex = 10;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(244, 348);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(72, 29);
			this->label21->TabIndex = 9;
			this->label21->Text = L"Image";
			// 
			// comboBox2
			// 
			this->comboBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"full", L"particularly" });
			this->comboBox2->Location = System::Drawing::Point(1092, 282);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(225, 37);
			this->comboBox2->TabIndex = 8;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Account::comboBox2_SelectedIndexChanged);
			this->comboBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Account::comboBox1_KeyPress);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(917, 273);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(89, 29);
			this->label20->TabIndex = 7;
			this->label20->Text = L"Feeding";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->numericUpDown1->Location = System::Drawing::Point(1092, 203);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown1->MaximumSize = System::Drawing::Size(1000, 0);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(225, 35);
			this->numericUpDown1->TabIndex = 6;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Account::numericUpDown1_ValueChanged);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(917, 193);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(61, 29);
			this->label19->TabIndex = 5;
			this->label19->Text = L"Price";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(244, 273);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(56, 29);
			this->label18->TabIndex = 4;
			this->label18->Text = L"Title";
			// 
			// textBox6
			// 
			this->textBox6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox6->Location = System::Drawing::Point(384, 282);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(225, 35);
			this->textBox6->TabIndex = 3;
			// 
			// comboBox1
			// 
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"hotel", L"restaurant", L"cafe", L"excursion" });
			this->comboBox1->Location = System::Drawing::Point(384, 203);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(225, 37);
			this->comboBox1->TabIndex = 8;
			this->comboBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Account::comboBox1_KeyPress);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(236, 194);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(59, 29);
			this->label17->TabIndex = 1;
			this->label17->Text = L"Type";
			this->label17->Click += gcnew System::EventHandler(this, &Account::label17_Click);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(683, 52);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(224, 47);
			this->label16->TabIndex = 0;
			this->label16->Text = L"Add industry";
			// 
			// button8
			// 
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(421, 167);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(170, 48);
			this->button8->TabIndex = 1;
			this->button8->Text = L"Add";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &Account::showAdd);
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->textBox10);
			this->panel6->Controls->Add(this->button16);
			this->panel6->Controls->Add(this->label27);
			this->panel6->Location = System::Drawing::Point(111, 167);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(1729, 619);
			this->panel6->TabIndex = 5;
			this->panel6->Visible = false;
			// 
			// textBox10
			// 
			this->textBox10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox10->Location = System::Drawing::Point(347, 260);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(831, 35);
			this->textBox10->TabIndex = 2;
			// 
			// button16
			// 
			this->button16->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button16->Font = (gcnew System::Drawing::Font(L"Candara", 29.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button16->Location = System::Drawing::Point(609, 351);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(314, 55);
			this->button16->TabIndex = 1;
			this->button16->Text = L"Delete";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &Account::del);
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Candara", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(104, 37);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(352, 59);
			this->label27->TabIndex = 0;
			this->label27->Text = L"Type id to delete";
			// 
			// button11
			// 
			this->button11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button11->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(1468, 173);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(182, 45);
			this->button11->TabIndex = 6;
			this->button11->Text = L"Exit";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Visible = false;
			this->button11->Click += gcnew System::EventHandler(this, &Account::exit);
			// 
			// button9
			// 
			this->button9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button9->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(735, 167);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(170, 48);
			this->button9->TabIndex = 2;
			this->button9->Text = L"Delete";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Visible = false;
			this->button9->Click += gcnew System::EventHandler(this, &Account::showPanelElems);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(33, 93);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(290, 63);
			this->label15->TabIndex = 0;
			this->label15->Text = L"Admin Panel";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->addToolStripMenuItem,
					this->deleteToolStripMenuItem, this->editToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1856, 71);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addToolStripMenuItem->Margin = System::Windows::Forms::Padding(50, 0, 0, 0);
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(124, 67);
			this->addToolStripMenuItem->Text = L"Add";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account::showAdd);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deleteToolStripMenuItem->Margin = System::Windows::Forms::Padding(50, 0, 0, 0);
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(172, 67);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account::showPanelElems);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editToolStripMenuItem->Margin = System::Windows::Forms::Padding(50, 0, 0, 0);
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(122, 67);
			this->editToolStripMenuItem->Text = L"Edit";
			this->editToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account::edit);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Candara", 38, System::Drawing::FontStyle::Italic));
			this->exitToolStripMenuItem->Margin = System::Windows::Forms::Padding(1000, 0, 0, 0);
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(120, 67);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account::exit);
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->button17);
			this->panel10->Controls->Add(this->label33);
			this->panel10->Location = System::Drawing::Point(44, 151);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(1918, 861);
			this->panel10->TabIndex = 9;
			this->panel10->Visible = false;
			// 
			// button17
			// 
			this->button17->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button17->Font = (gcnew System::Drawing::Font(L"Candara", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button17->Location = System::Drawing::Point(798, 423);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(390, 63);
			this->button17->TabIndex = 1;
			this->button17->Text = L"Ok";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &Account::ok);
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Candara", 56, System::Drawing::FontStyle::Italic));
			this->label33->Location = System::Drawing::Point(797, 270);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(350, 91);
			this->label33->TabIndex = 0;
			this->label33->Text = L"Not found";
			// 
			// panel11
			// 
			this->panel11->Controls->Add(this->button20);
			this->panel11->Controls->Add(this->label34);
			this->panel11->Location = System::Drawing::Point(23, 151);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(1921, 912);
			this->panel11->TabIndex = 10;
			this->panel11->Visible = false;
			// 
			// button20
			// 
			this->button20->Font = (gcnew System::Drawing::Font(L"Candara", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20->Location = System::Drawing::Point(782, 399);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(288, 72);
			this->button20->TabIndex = 1;
			this->button20->Text = L"Ok";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &Account::button20_Click);
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Candara", 57.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->Location = System::Drawing::Point(598, 243);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(647, 94);
			this->label34->TabIndex = 0;
			this->label34->Text = L"Successfully added!";
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->button21);
			this->panel12->Controls->Add(this->label35);
			this->panel12->Location = System::Drawing::Point(-3, 147);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(1915, 738);
			this->panel12->TabIndex = 2;
			this->panel12->Visible = false;
			// 
			// button21
			// 
			this->button21->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button21->Location = System::Drawing::Point(857, 478);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(261, 84);
			this->button21->TabIndex = 1;
			this->button21->Text = L"Ok";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &Account::button21_Click);
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Font = (gcnew System::Drawing::Font(L"Candara", 57.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label35->Location = System::Drawing::Point(652, 328);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(690, 94);
			this->label35->TabIndex = 0;
			this->label35->Text = L"Successfully deleted!";
			// 
			// panel13
			// 
			this->panel13->Controls->Add(this->button22);
			this->panel13->Controls->Add(this->label36);
			this->panel13->Location = System::Drawing::Point(68, 151);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(1915, 941);
			this->panel13->TabIndex = 11;
			this->panel13->Visible = false;
			// 
			// button22
			// 
			this->button22->Font = (gcnew System::Drawing::Font(L"Candara", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button22->Location = System::Drawing::Point(824, 448);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(281, 85);
			this->button22->TabIndex = 1;
			this->button22->Text = L"Ok";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &Account::button22_Click);
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"Candara", 57.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label36->Location = System::Drawing::Point(618, 294);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(697, 94);
			this->label36->TabIndex = 0;
			this->label36->Text = L"Successfully changed";
			// 
			// Account
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1045);
			this->Controls->Add(this->panel13);
			this->Controls->Add(this->panel12);
			this->Controls->Add(this->panel11);
			this->Controls->Add(this->panel10);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Account";
			this->Text = L"Account";
			this->Load += gcnew System::EventHandler(this, &Account::Form_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void comboBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
			e->Handled = true;  
		}
private: System::Void comboBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	e->Handled = true;  
}
	   private: System::Void comboBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		   e->Handled = true;  
	   }
			  private: System::Void comboBox4_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
				  e->Handled = true;
			  }
					 private: System::Void comboBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
						 e->Handled = true; 
					 }

	private: System::Void back(System::Object^ sender, System::EventArgs^ e) {
		this->Owner->Show();  
		this->Close(); 
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->panel1->Visible = false;
		this->panel2->Visible = true;
	}
private: System::Void register_Click(System::Object^ sender, System::EventArgs^ e) {
	LoadData("register");
	if (textBox2 != nullptr) {
		String^ text = textBox2->Text;
		 
	}
	if (textBox3 != nullptr) {
		String^ text = textBox3->Text;
	}

	if (textBox4 != nullptr) {
		String^ text = textBox4->Text;
	}
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
	this->panel2->Visible = false;
	this->panel1->Visible = true;
}
private: System::Void login(System::Object^ sender, System::EventArgs^ e) {
	LoadData("login");
	if (isAutherizated)
	{
		this->panel2->Visible = false;
		this->panel1->Visible = false;
		this->panel3->Visible = true; 
	}
}
private: System::Void history(System::Object^ sender, System::EventArgs^ e) {
	this->button7->Visible = false;
	this->panel4->Visible = true;
	this->panel4->Controls->Clear();
	std::string filename = "input.txt";
	FileReader reader(filename);
	reader.readFile();
	std::vector<std::string> data = reader.getArrayofGettedData();

	std::vector<Entry> entries;
	for (const std::string& line : data) {
		Entry entry;
		reader.parseInput(line, entry);
		entries.push_back(entry);
	}

	std::string value = reader.getActualData(nameOfUser);
	reader.showStructureOfUsers();
	std::string getFavouriteElems = reader.getHistory(nameOfUser);
	getFavouriteElemsString = gcnew System::String(getFavouriteElems.c_str());
	array<System::String^>^ arrayOfPersonalFavItems = getFavouriteElemsString->Split('-');
	for (int i = 1; i < arrayOfPersonalFavItems->Length; i++) {
		Panel^ panelFavourite = gcnew Panel();
		panelFavourite->BackColor = Color::Black;
		panelFavourite->Size = System::Drawing::Size(this->panel4->Width, 80);
		panelFavourite->Dock = DockStyle::Top;
		panel4->Controls->Add(panelFavourite);

		System::String^ testt = "";
		for (int j = 0; j < entries.size(); j++) {
			String^ item = msclr::interop::marshal_as<System::String^>(entries[j].title);
			if (item->Contains(arrayOfPersonalFavItems[i])) {
				testt += item;
				testt += ":";
				String^ itemm = msclr::interop::marshal_as<System::String^>(entries[j].price);
				testt += itemm;
				testt += "$";
			}
		}
		Panel^ favPanel = gcnew Panel();
		favPanel->BackColor = Color::Orange;
		favPanel->Size = System::Drawing::Size(this->panel4->Width, 80);
		favPanel->Dock = DockStyle::Top;
		panelFavourite->Controls->Add(favPanel);
		Label^ favElems = gcnew Label();
		favElems->Text = testt;
		favElems->Padding = System::Windows::Forms::Padding(50, 25, 0, 0);
		favElems->Font = gcnew System::Drawing::Font("Candara", 20);
		favElems->ForeColor = Color::Black;
		favElems->Size = System::Drawing::Size(this->panel4->Width, 80);
		favPanel->Controls->Add(favElems);
		Panel^ border = gcnew Panel();
		border->BackColor = Color::Black;
		border->Size = System::Drawing::Size(this->panel4->Width, 5);
		border->Dock = DockStyle::Bottom;
		favPanel->Controls->Add(border);
		border->BringToFront();

	}
	panel4->AutoScroll = true;
}
private: System::Void fav(System::Object^ sender, System::EventArgs^ e) {
	this->panel4->Visible = true;
	this->button7->Visible = true;
	this->panel4->Controls->Clear();
	std::string filename = "input.txt";
	FileReader reader(filename);
	reader.readFile();

	std::vector<std::string> data = reader.getArrayofGettedData();

	std::vector<Entry> entries;
	for (const std::string& line : data) {
		Entry entry;
		reader.parseInput(line, entry);
		entries.push_back(entry);
	}

	std::string value = reader.getActualData(nameOfUser);

	reader.showStructureOfUsers();
	std::string getFavouriteElems = reader.getFav(nameOfUser);
	getFavouriteElemsString = gcnew System::String(getFavouriteElems.c_str());
	array<System::String^>^ arrayOfPersonalFavItems = getFavouriteElemsString->Split('-');

	for (int i = 1; i < arrayOfPersonalFavItems->Length; i++) {
		Panel^ panelFavourite = gcnew Panel();
		panelFavourite->BackColor = Color::Black;
		panelFavourite->Size = System::Drawing::Size(this->panel4->Width, 80);
		panelFavourite->Dock = DockStyle::Top;

	 
		panel4->Controls->Add(panelFavourite);

		System::String^ testt = "";
		for (int j = 0; j < entries.size(); j++) {
			String^ item = msclr::interop::marshal_as<System::String^>(entries[j].title);
			if (item->Contains(arrayOfPersonalFavItems[i])) {
				testt += item;
				testt += ":";
				String^ itemm = msclr::interop::marshal_as<System::String^>(entries[j].price);
				testt += itemm;
				testt += "$";
			}
		}
		Panel^ favPanel = gcnew Panel();
		favPanel->BackColor = Color::Orange;
		favPanel->Size = System::Drawing::Size(this->panel4->Width, 80);
		favPanel->Dock = DockStyle::Top;
		panelFavourite->Controls->Add(favPanel);
		Label^ favElems = gcnew Label();
		favElems->Text = testt;
		favElems->Padding = System::Windows::Forms::Padding(50, 25, 0, 0);
		favElems->Font = gcnew System::Drawing::Font("Candara", 20);
		favElems->ForeColor = Color::Black;
		favElems->Size = System::Drawing::Size(this->panel4->Width, 80);
		favPanel->Controls->Add(favElems);
		Panel^ border = gcnew Panel();
		border->BackColor = Color::Black;
		border->Size = System::Drawing::Size(this->panel4->Width, 5);
		border->Dock = DockStyle::Bottom;
		favPanel->Controls->Add(border);
		Label^ favElemss = gcnew Label();
		favElemss->Text ="delete "+ arrayOfPersonalFavItems[i];
		favElemss->BackColor = Color::Red;
		favElemss->Padding = System::Windows::Forms::Padding(25, 25, 0, 0);
		favElemss->Font = gcnew System::Drawing::Font("Candara", 20);
		favElemss->ForeColor = Color::Black;
		favElemss->Size = System::Drawing::Size(180, 80);
		favElemss->Location = System::Drawing::Point(910, 0);
		favPanel->Controls->Add(favElemss);
		favElemss->Click += gcnew System::EventHandler(this, &Account::deleteFromFavButton_Click);
		favElemss->Cursor = System::Windows::Forms::Cursors::Hand;
		favElemss->BringToFront();
		Label^ favElemsss = gcnew Label();
		favElemsss->Text = "buy "+ arrayOfPersonalFavItems[i];
		favElemsss->Click += gcnew System::EventHandler(this, &Account::buyButton_Click);
		favElemsss->BackColor = Color::Green;
		favElemsss->Padding = System::Windows::Forms::Padding(25, 25, 0, 0);
		favElemsss->Font = gcnew System::Drawing::Font("Candara", 20);
		favElemsss->ForeColor = Color::Black;
		favElemsss->Size = System::Drawing::Size(180, 80);
		favElemsss->Location = System::Drawing::Point(710, 0);
		favElemsss->Cursor = System::Windows::Forms::Cursors::Hand;
		favPanel->Controls->Add(favElemsss);
		favElemsss->BringToFront();
		border->BringToFront();
	}
	panel4->AutoScroll = true;
}
private: void buyButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->panel4->Visible = false;
	Console::WriteLine("delete");
	String^ buyItem = "";
	Label^ buyLabel = dynamic_cast<Label^>(sender);
	if (buyLabel != nullptr) {
		buyItem =buyLabel->Text;
	}
	std::string filename = "input.txt";
	FileReader reader(filename);
	reader.readFile();
	std::vector<std::string> data = reader.getArrayofGettedData();
	std::vector<Entry> entries;
	for (const std::string& line : data) {
		Entry entry;
		reader.parseInput(line, entry);
		entries.push_back(entry);
	}
	std::string value = reader.getActualData(nameOfUser);
	reader.showStructureOfUsers();
	reader.buyFav(buyItem, nameOfUser);
	 
}
private: void deleteFromFavButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->panel4->Visible = false;
	String^ deleteItem = "";
	Label^ deleteLabel = dynamic_cast<Label^>(sender);
	if (deleteLabel != nullptr) {
		deleteItem = deleteLabel->Text;
	}
	std::string filename = "input.txt";
	FileReader reader(filename);
	reader.readFile();
	std::vector<std::string> data = reader.getArrayofGettedData();
	std::vector<Entry> entries;
	for (const std::string& line : data) {
		Entry entry;
		reader.parseInput(line, entry);
		entries.push_back(entry);
	}
	std::string value = reader.getActualData(nameOfUser);
	reader.showStructureOfUsers();
	reader.deleteItemFromFav(deleteItem, nameOfUser);
	std::string loginStroke = reader.login(authEmail, authPassword);
}

void DeleteLabel_Click(System::Object^ sender, System::EventArgs^ e, String^ elementText) {
	Label^ deleteLabel = dynamic_cast<Label^>(sender);
	if (deleteLabel != nullptr) {
		Console::WriteLine("Deleted: " + elementText);
	}
}
			private: void addToFavButton_Click(System::Object^ sender, System::EventArgs^ e) {
				if (isAutherizated) {
					Console::WriteLine("AUTHER");

					std::string filename = "input.txt";
					FileReader reader(filename);
					reader.readFile();
					std::vector<std::string> data = reader.getArrayofGettedData();

					std::vector<Entry> entries;
					for (const std::string& line : data) {
						Entry entry;
						reader.parseInput(line, entry);
						entries.push_back(entry);
					}

					std::string value = reader.getActualData(nameOfUser);
					reader.showStructureOfUsers();
					std::string loginStroke = reader.login(authEmail, authPassword);
					loginStrokeString = gcnew System::String(loginStroke.c_str());
					int indexOfColon = loginStrokeString->IndexOf(":");
					Console::WriteLine("LOGIN STROKE" + loginStrokeString);
					if (indexOfColon != -1) {
						String^ loginValue = loginStrokeString->Substring(0, indexOfColon);
						reader.addToFav(selectedElement, loginValue);
					}

				}
			}




				   private: System::Void Form_Load(System::Object^ sender, System::EventArgs^ e) {
					   LoadData(" ");

					   arrayOfPersonalData = gcnew array<String^>(5);
					   std::string filename = "input.txt";
					   FileReader reader(filename);
					   reader.readFile();


					   try {
						   nameOfUser = msclr::interop::marshal_as<System::String^>(reader.getConsts());
						  

						   if (nameOfUser!=nullptr) {
							 
							   isAutherizated = true;

							
							   if (nameOfUser =="admin") {
								

								   this->panel2->Visible = false;
								   this->panel1->Visible = false;
								   this->panel5->Visible = true;
								
							   }
							   if (nameOfUser != "admin") {
								  

								   this->panel2->Visible = false;
								   this->panel1->Visible = false;
								   this->panel3->Visible = true;
								 
							   }


							   else {
								   this->panel3->Visible = false;
								   this->panel1->Visible = true;
						
								   if (nameOfUser->Length > 1) {
							
								   }
							   }
					 
						   this->label10->Text = nameOfUser;
						   } 
						   else {

						
							   this->panel3->Visible = false;
							   this->panel1->Visible = true;
						   }

						   array<System::String^>^ arrayOf = loginStrokeString->Split(':');
						  
						   arrayOfPersonalData[0] = arrayOf[0];
						   arrayOfPersonalData[1] = arrayOf[1];
						   arrayOfPersonalData[2] = arrayOf[2];

					   nameOfUser = arrayOfPersonalData[0];

						   this->label10->Text = nameOfUser;
					   }
					   catch (const System::Exception^ ex) {
						   
						   Console::WriteLine("Unlogged");
						 
					   }
				   }
			 
private: System::Void exit(System::Object^ sender, System::EventArgs^ e) {
	arrayOfPersonalData->Clear;
	isAutherizated = false;
	this->panel3->Visible = false;	
	this->panel7->Visible = false;
	this->panel5->Visible = false;
	this->panel1->Visible =true;
		std::string filename = "input.txt";
		FileReader reader(filename);
		reader.readFile();
		reader.clearConsts();
		reader.showStructureOfUsers();
		std::vector<std::string> data = reader.getArrayofGettedData();
}
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buyAll(System::Object^ sender, System::EventArgs^ e) {
	this->panel4->Visible = false;
	std::string filename = "input.txt";
	FileReader reader(filename);
	reader.readFile();
	std::vector<std::string> data = reader.getArrayofGettedData();
	std::vector<Entry> entries;
	for (const std::string& line : data) {
		Entry entry;
		reader.parseInput(line, entry);
		entries.push_back(entry);
	}
	std::string value = reader.getActualData(nameOfUser);
	reader.buyAllFav(nameOfUser);
}
private: System::Void label17_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void showAdd(System::Object^ sender, System::EventArgs^ e) {
	this->panel7->Visible = true;
	this->panel8->Visible = false;

	this->panel6->Visible = false;
}
	   std::string generateUniqueDigits() {
		   std::string result = "";
		   std::srand(static_cast<unsigned int>(std::time(nullptr)));
		   std::string digits = "0123456789";
 
		   std::random_shuffle(digits.begin(), digits.end());

		   
		   result = digits.substr(0, 8);

		   
		   result += "st";

		   return result;
	   }


	   std::string generateUniqueId() {
		   std::string result = "";
		   std::srand(static_cast<unsigned int>(std::time(nullptr)));
		   std::string digits = "0123456789";
		   std::random_shuffle(digits.begin(), digits.end());
		   result = digits.substr(0, 8);
		   return result;
	   }
private: System::Void addToDatabase(System::Object^ sender, System::EventArgs^ e) {
	this->panel6->Visible = false;
	this->panel7->Visible = true;
	String^ selected = comboBox1->SelectedItem ? comboBox1->SelectedItem->ToString() : nullptr;
	String^ selected1 = comboBox2->SelectedItem ? comboBox2->SelectedItem->ToString() : nullptr;
	String^ text = textBox6->Text;
	String^ text1 = textBox7->Text;
	String^ text2 = textBox8->Text;
	String^ numericValue = numericUpDown1->Value.ToString();
	std::string filename = "input.txt";
	FileReader reader(filename);
	reader.readFile();
	std::vector<std::string> data = reader.getArrayofGettedData();
	std::vector<Entry> entries;
	for (const std::string& line : data) {
		std::cout << line << std::endl;

	}
	for (const std::string& line : data) {
		Entry entry;
		reader.parseInput(line, entry);


		entries.push_back(entry);
	}
	std::string uniqueCode = generateUniqueDigits();
	std::string uniqueId = generateUniqueId();
	 
	String^ uniqueCodeStr = msclr::interop::marshal_as<System::String^>(uniqueCode);
	String^ uniqueIdStr = msclr::interop::marshal_as<System::String^>(uniqueId);

	try {

		System::String^ filePath = "ruc.pdf";
		reader.addToDatabase(text, text1, text2, selected, selected1, numericValue, uniqueCodeStr, uniqueIdStr);
		this->panel11->Visible = true;
		this->panel11->BringToFront();
	

	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show("Form boxes cannot be empty!!!");

	}
	std::string currentIdStr = entries[entries.size() - 1].id;
	int currentId = std::stoi(currentIdStr);







	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);

	int year = now->tm_year + 1900;
	int month = now->tm_mon + 1;
	int day = now->tm_mday;

	std::string yearStr = std::to_string(year);
	std::string monthStr = (month < 10) ? "0" + std::to_string(month) : std::to_string(month);
	std::string dayStr = (day < 10) ? "0" + std::to_string(day) : std::to_string(day);

	
	std::string currentDate = dayStr + "-" + monthStr + "-" + yearStr;


	String^ currentDateString = msclr::interop::marshal_as<String^>(currentDate);
	
	String^ uniqueCodeString = msclr::interop::marshal_as<String^>(uniqueCode);
	
	
 
}

	 
private: System::Void showPanelElems(System::Object^ sender, System::EventArgs^ e) {
	this->panel7->Visible = false;
	this->panel6->Visible = true;
	this->panel8->Visible = false;






	arrayOfAllData = gcnew array<String^>(30 * 100);
	arrayOfPersonalData = gcnew array<String^>(5);
	arrayOfAllDataSortedByAccessibility = gcnew array<String^>(30 * 100);
	arrayOfAllDataSortedByFull = gcnew array<String^>(30 * 10);
	arrayOfAllDataSortedByParticularly = gcnew array<String^>(30 * 100);
	arrayOfAllDataFoundElems = gcnew array<String^>(30 * 100);
	arrayOfTitles = gcnew array<String^>(30 * 100);

	arrayOfType = gcnew array<String^>(30 * 100);

	arrayOfRate = gcnew array<String^>(30 * 100);

	arrayOfAccesibility = gcnew array<String^>(30 * 100);

	arrayOfPrice = gcnew array<String^>(30 * 100);

	arrayOfId = gcnew array<String^>(30 * 100);


	arrayOfPit = gcnew array<String^>(30 * 100);

	arrayOfCountry = gcnew array<String^>(30 * 100);

	arrayOfUrl = gcnew array<String^>(30 * 100);
	arrayOfData = gcnew array<String^>(30 * 100);

	arrayOfAllData = gcnew array<String^>(30 * 100);


	arrayOfFoundedElement = gcnew array<String^>(30 * 100);

	std::string filename = "input.txt";
	FileReader reader(filename);
	reader.readFile();

	try {
		nameOfUser = msclr::interop::marshal_as<System::String^>(reader.getConsts());
		isAutherizated = true;
	}
	catch (const System::Exception^ ex) {
		isAutherizated = false;
	}

	reader.showStructureOfUsers();

	std::vector<std::string> data = reader.getArrayofGettedData();
	
	String^ imageUrl = "https://fikiwiki.com/uploads/posts/2022-02/1644918620_17-fikiwiki-com-p-krasivie-kartinki-visokogo-razresheniya-19.jpg";
	headersOfTable = gcnew array<String^> { "type", "title", "code", "accessibility", "price", "id", "pit", "data", "country" };


	std::vector<Entry> entries;




	for (const std::string& line : data) {
		Entry entry;
		reader.parseInput(line, entry);


		entries.push_back(entry);
	}



	entriesSize = entries.size();












}
 



private: System::Void dataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	String^ selected;
	if (e->ColumnIndex == indexOfTitlesColumn && e->RowIndex >= 0) {
	 
		String^ clickedTitle = dataGridView->Rows[e->RowIndex]->Cells[indexOfTitlesColumn]->Value->ToString();
		selected = clickedTitle;
	
	}
	if (e->RowIndex >= 0 && e->ColumnIndex >= 0) {
		String^ message = "Delete?";
		String^ caption = "Sure";
		 
		

		MessageBoxButtons buttons = MessageBoxButtons::YesNo;
		System::Windows::Forms::DialogResult result = MessageBox::Show(message, caption, buttons);

		
		if (result == System::Windows::Forms::DialogResult::Yes) {
			dataGridView->Rows->RemoveAt(e->RowIndex);




			std::string filename = "input.txt";
			FileReader reader(filename);
			reader.readFile();


			std::vector<std::string> data = reader.getArrayofGettedData();

			std::vector<Entry> entries;
			for (const std::string& line : data) {
				Entry entry;
				reader.parseInput(line, entry);
				entries.push_back(entry);
			}
			reader.removeFromDatabase(selected);







		}
		 


	}
}



private: System::Void edit(System::Object^ sender, System::EventArgs^ e) {
	this->panel7->Visible = false;
	this->panel6->Visible = false;
	this->panel8->Visible = true;

}
private: System::Void textBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void findToEdit(System::Object^ sender, System::EventArgs^ e) {

	String^ text = textBox9->Text;


	std::string filename = "input.txt";
	FileReader reader(filename);
	reader.readFile();


	std::vector<std::string> data = reader.getArrayofGettedData();

	std::vector<Entry> entries;



	




	for (const std::string& line : data) {
		Entry entry;
		reader.parseInput(line, entry);


		entries.push_back(entry);
	}

	selectedId = text;
	
	std::string found = reader.findToEdit(text);


	
	System::String^ valueString = gcnew System::String(found.c_str());
	foundElement = valueString;


	if (foundElement->Contains("Not")) {
		this->panel10->Visible = true;
		this->panel10->BringToFront();
		
	}

	else {

		if (selectedId->Length > 0) {

		array<System::String^>^ arrayOfFoundedElement = valueString->Split(':');
		//	if (!valueString->Contains("Not found") {


		this->panel9->Visible = true;


		String^ type = comboBox3->SelectedItem ? comboBox3->SelectedItem->ToString() : nullptr;
		String^ accessibility = comboBox4->SelectedItem ? comboBox4->SelectedItem->ToString() : nullptr;
		String^ feeding = comboBox5->SelectedItem ? comboBox5->SelectedItem->ToString() : nullptr;
		String^ title = textBox11->Text;
		String^ url = textBox12->Text;
		String^ country = textBox13->Text;

		String^ numericValue = numericUpDown2->Value.ToString();
		}
		else {
			System::Windows::Forms::MessageBox::Show("Form boxes cannot be empty!!!");
		}
	}
	//}

}
private: System::Void cancel(System::Object^ sender, System::EventArgs^ e) {
	this->panel9->Visible = false;
}
private: System::Void clickToEdit(System::Object^ sender, System::EventArgs^ e) {
	String^ type = comboBox3->SelectedItem ? comboBox3->SelectedItem->ToString() : nullptr;
	String^ accessibility = comboBox4->SelectedItem ? comboBox4->SelectedItem->ToString() : nullptr;
	String^ feeding = comboBox5->SelectedItem ? comboBox5->SelectedItem->ToString() : nullptr;
	String^ title = textBox11->Text;
	String^ url = textBox12->Text;
	String^ country = textBox13->Text;
	
	String^ numericValue = numericUpDown2->Value.ToString();
	

	std::string filename = "input.txt";
	FileReader reader(filename);
	reader.readFile();


	std::vector<std::string> data = reader.getArrayofGettedData();

	std::vector<Entry> entries;








	for (const std::string& line : data) {
		Entry entry;
		reader.parseInput(line, entry);


		entries.push_back(entry);
	}




	try {
 
		System::String^ filePath = "ruc.pdf";
		reader.changeElement(selectedId, type, title, accessibility, feeding, url, country, numericValue);
		this->panel9->Visible = false;
		this->panel8->Visible = false;
		this->panel13->Visible = true;
		this->panel13->BringToFront();
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show("Form boxes cannot be empty!!!");
		//System::Windows::Forms::MessageBox::Show("Form boxes cannot be empty!!!");

	}


	

}
private: System::Void del(System::Object^ sender, System::EventArgs^ e) {


	String^ text = textBox10->Text;
	std::string filename = "input.txt";
	FileReader reader(filename);
	reader.readFile();


	std::vector<std::string> data = reader.getArrayofGettedData();

	std::vector<Entry> entries;


	for (const std::string& line : data) {
		Entry entry;
		reader.parseInput(line, entry);


		entries.push_back(entry);
	}

	int cs = 0;
	for (int i = 0; i < entries.size(); i++) {
		
		String^ item = msclr::interop::marshal_as<String^>(entries[i].id);
		
		if (item->Contains(" "+text)) {
			cs++;
			Console::WriteLine("YEEEEEEEEEEEEEESSSS");
		}
		
		
	}
	if (cs == 0) {
		this->panel10->Visible = true;
		this->panel10->BringToFront();
	}
	else {
		if (text->Length > 0) {

	this->panel12->Visible = true;
	this->panel12->BringToFront();
		}
		else {
			System::Windows::Forms::MessageBox::Show("Form boxes cannot be empty!!!");
		}

	}
	reader.removeFromDatabase(" "+text);

}
private: System::Void panel10_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void ok(System::Object^ sender, System::EventArgs^ e) {
	this->panel10->Visible = false;

}
private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
	 
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
	 
	openFileDialog1->Filter = "Image Files (*.bmp;*.jpg;*.png;*.gif)|*.bmp;*.jpg;*.png;*.gif|All files (*.*)|*.*";
	openFileDialog1->Title = "Выберите изображение";
	 
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		 
		String^ selectedImagePath = openFileDialog1->FileName;
 
		textBox12->Text = selectedImagePath;
	}



}
private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
	 
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

 
	openFileDialog1->Filter = "Image Files (*.bmp;*.jpg;*.png;*.gif)|*.bmp;*.jpg;*.png;*.gif|All files (*.*)|*.*";
	openFileDialog1->Title = "Выберите изображение";

	 
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		 
		String^ selectedImagePath = openFileDialog1->FileName;

	 
		textBox8->Text = selectedImagePath;
	}



}
private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
	this->panel11->Visible = false;
}
private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
	this->panel12->Visible = false;
}
private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
	this->panel13->Visible = false;
}
};
}
