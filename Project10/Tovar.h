#pragma once
 

#include "FileReader.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>  
#include <vcclr.h>  
#include  "Entry.h"
namespace Project10 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class Tovar : public System::Windows::Forms::Form
	{
	public:
		Tovar(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
	 
		~Tovar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ addBtn;
	private: System::Windows::Forms::Button^ backBtn;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panelFavourite;
	private: System::Windows::Forms::PictureBox^ deletePicture;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::ComboBox^ comboBox2;
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
		array<String^>^ arrayOfAllDataSorted;
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
		System::String^ selectedGrid = "";
		System::String^ selectedTodeleteItem = "";
		System::String^ selectedElement = "";
		
#pragma region Windows Form Designer generated code
		
		void LoadData(String^ method) {
			arrayOfAllData = gcnew array<String^>(30 * 100);
			arrayOfPersonalData = gcnew array<String^>(5);
			arrayOfAllDataSortedByAccessibility = gcnew array<String^>(30 * 100);
			arrayOfAllDataSortedByFull = gcnew array<String^>(30 * 10);
			arrayOfAllDataSortedByParticularly = gcnew array<String^>(30 * 100);
			arrayOfAllDataSorted = gcnew array<String^>(30 * 100);
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
				if (!line.empty()) {
					Entry entry;
					reader.parseInput(line, entry);
					entries.push_back(entry);
				}
			}
			entriesSize = entries.size();
			for (int i = 0; i < entriesSize; i++) {
				arrayOfTitles[i] = msclr::interop::marshal_as<System::String^>(entries[i].title);
				arrayOfType[i] = msclr::interop::marshal_as<System::String^>(entries[i].type);
				arrayOfRate[i] = msclr::interop::marshal_as<System::String^>(entries[i].rate);
				arrayOfAccesibility[i] = msclr::interop::marshal_as<System::String^>(entries[i].accessibility);
				arrayOfPrice[i] = msclr::interop::marshal_as<System::String^>(entries[i].price);
				arrayOfId[i] = msclr::interop::marshal_as<System::String^>(entries[i].id);
				arrayOfPit[i] = msclr::interop::marshal_as<System::String^>(entries[i].pit);
				arrayOfCountry[i] = msclr::interop::marshal_as<System::String^>(entries[i].country);
				arrayOfUrl[i] = msclr::interop::marshal_as<System::String^>(entries[i].url);
				arrayOfData[i] = msclr::interop::marshal_as<System::String^>(entries[i].data);
			 
			}
			dataGridView = gcnew System::Windows::Forms::DataGridView();
			int indexOfDesiredColumn = 1;
			array<String^>^ headersOfTable = gcnew array<String^> { "Type", "Title", "Code", "Accessibility", "Price", " Id", "Feeding", "Date", "Country" };
			dataGridView->ColumnCount = headersOfTable->Length;
			dataGridView->Size = System::Drawing::Size(1550, 700);
			for (int i = 0; i < headersOfTable->Length; i++) {
				dataGridView->Columns[i]->Name = headersOfTable[i];
				dataGridView->Columns[i]->Width = 170;
			}
			for (int i = 0; i < entriesSize; i++) {
				dataGridView->ForeColor = System::Drawing::Color::Black;
				dataGridView->Rows->Add( arrayOfType[i], arrayOfTitles[i], arrayOfRate[i], arrayOfAccesibility[i], arrayOfPrice[i], arrayOfId[i], arrayOfPit[i], arrayOfData[i], arrayOfCountry[i]);
				if (i % 2 == 0) {
					dataGridView->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightGray;
				
				}
			//dataGridView->Columns[1]->DefaultCellStyle->BackColor = System::Drawing::Color::Red;
			}
			indexOfTitlesColumn = indexOfDesiredColumn;  
			dataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Tovar::dataGridView_CellClick);
			dataGridView->AllowUserToOrderColumns = true;
			dataGridView->AllowUserToResizeColumns = true;
			dataGridView->AllowUserToAddRows = false;
			dataGridView->Location = System::Drawing::Point(100, 200);
		 this->Controls->Add(dataGridView);
		 	dataGridView->BringToFront();
			if (method->Contains("grid")) {
				 this->panel2->Controls->Clear();
				 this->dataGridView->Visible = false;
				String^ text = selectedGrid;
				selectedElement = selectedGrid;
				std::string value = reader.findGridElem(text);
				System::String^ valueString = gcnew System::String(value.c_str());
				foundElement = valueString;
				array<System::String^>^ arrayOfFoundedElement = valueString->Split(':');
				std::string valuee = reader.searchImage(arrayOfFoundedElement[1]);
				indexOfImageString = gcnew System::String(valuee.c_str());
				PictureBox^ picturee = gcnew PictureBox();
				picturee->Location = System::Drawing::Point(116, 67);
				picturee->Name = L"pictureBox1";
				picturee->Size = System::Drawing::Size(650, 362);
				picturee->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				picturee->TabIndex = 2;
				picturee->TabStop = false;
				picturee->ImageLocation = indexOfImageString;
				panel2->Controls->Add(picturee);
				addBtn = gcnew System::Windows::Forms::Button();
				addBtn->Text = L"Add to favourite";
				addBtn->Location = System::Drawing::Point(166, 598);
				addBtn->Font = (gcnew System::Drawing::Font(L"Candara", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				addBtn->Size = System::Drawing::Size(300, 76);
				addBtn->Click += gcnew System::EventHandler(this, &Tovar::addToFavButton_Click);
				panel2->Controls->Add(addBtn);
				addBtn->BringToFront();
				backBtn = gcnew System::Windows::Forms::Button();
				backBtn->Location = System::Drawing::Point(0, 0);
				backBtn->Name = L"button2";
				backBtn->Size = System::Drawing::Size(100, 100);
				backBtn->TabIndex = 1;
				backBtn->Text = L"←";
				backBtn->Font = (gcnew System::Drawing::Font(L"Candara", 34, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				backBtn->UseVisualStyleBackColor = true;
				backBtn->Click += gcnew System::EventHandler(this, &Tovar::backToElems);
				panel2->Controls->Add(backBtn);
				for (int i = 0; i < arrayOfFoundedElement->Length; i++) {
					String^ elementText = arrayOfFoundedElement[i];
					Label^ elementLabel = gcnew Label();
					int labelX = 1000;
					int labelY = 250 + i * 30; 
					if (i == 1) {
					elementLabel->Font = (gcnew System::Drawing::Font(L"Candara", 32, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
							static_cast<System::Byte>(0)));
						elementLabel->Location = System::Drawing::Point(labelX, labelY - 100);
					}
					else {
						elementLabel->Font = (gcnew System::Drawing::Font(L"Candara", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
							static_cast<System::Byte>(0)));
						elementLabel->Location = System::Drawing::Point(labelX, labelY);
					}
					elementLabel->Text = headersOfTable[i] + ":" + elementText;
					elementLabel->ForeColor = Color::Black;  
					elementLabel->BackColor = Color::Transparent;
					elementLabel->AutoSize = true;
					panel2->Controls->Add(elementLabel);
					this->panel2->Visible = true;
				}
				} 
			if (method->Contains("search")) {
				this->dataGridView->Visible = false;
				this->panel2->Visible = true;
				reader.show();
				String^ text = textBox1->Text;
				String^ selected = comboBox1->SelectedItem ? comboBox1->SelectedItem->ToString() : nullptr;
				std::string value;
				if (selected != nullptr) {
					try {
						System::String^ filePath = "ruc.pdf";
						value = reader.sear(text, selected);
					}
					catch (System::Exception^ ex) {
						System::Windows::Forms::MessageBox::Show("Something gone wrong");

					}

				}
				else {
					try {

						System::String^ filePath = "ruc.pdf";
						value = reader.findElem(text);
					}
					catch (System::Exception^ ex) {
						System::Windows::Forms::MessageBox::Show("Something gone wrong");

					}
				}
				System::String^ valueString = gcnew System::String(value.c_str());
				foundElement = valueString;
				if (foundElement->Contains("Not Found"))
				{
					this->panel2->Controls->Clear();
					String^ elementText = "Not found";
					Label^ elementLabel = gcnew Label();
					elementLabel->Text = elementText;
					elementLabel->ForeColor = Color::Black;
					elementLabel->BackColor = Color::Transparent;
					elementLabel->AutoSize = true;
					elementLabel->Font = (gcnew System::Drawing::Font(L"Candara", 72, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					elementLabel->Location = System::Drawing::Point(700, 300);
					panel2->Controls->Add(elementLabel);
					this->panel2->Visible = true;

				}
				else {
					array<System::String^>^ arrayOfFoundedElement = valueString->Split(':');
					if (arrayOfFoundedElement->Length <= 9) {
						this->panel2->Controls->Clear();
						std::string valuee = reader.searchImage(arrayOfFoundedElement[1]);
						indexOfImageString = gcnew System::String(valuee.c_str());
						PictureBox^ picturee = gcnew PictureBox();
						picturee->Location = System::Drawing::Point(116, 67);
						picturee->Name = L"pictureBox1";
						picturee->Size = System::Drawing::Size(650, 362);
						picturee->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
						picturee->TabIndex = 2;
						picturee->TabStop = false;
						picturee->ImageLocation = indexOfImageString;
						panel2->Controls->Add(picturee);
						addBtn = gcnew System::Windows::Forms::Button();
						addBtn->Text = L"Add to favourite";
						addBtn->Location = System::Drawing::Point(166, 598);
					addBtn->Font = (gcnew System::Drawing::Font(L"Candara", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
							static_cast<System::Byte>(0)));
						addBtn->Size = System::Drawing::Size(300, 76);
						addBtn->Click += gcnew System::EventHandler(this, &Tovar::addToFavButton_Click);
						panel2->Controls->Add(addBtn);
						addBtn->BringToFront();
						for (int i = 0; i < arrayOfFoundedElement->Length; i++) {
							String^ elementText = arrayOfFoundedElement[i];
							Label^ elementLabel = gcnew Label();
							int labelX = 1000;
							int labelY = 250 + i * 30;
							if (i == 1) {
								selectedElement = arrayOfFoundedElement[i];
								elementLabel->Font = (gcnew System::Drawing::Font(L"Candara", 32, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
									static_cast<System::Byte>(0)));
								elementLabel->Location = System::Drawing::Point(labelX, labelY - 100);
							}
							else {
								elementLabel->Font = (gcnew System::Drawing::Font(L"Candara", 17, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
									static_cast<System::Byte>(0)));
								elementLabel->Location = System::Drawing::Point(labelX, labelY);
							}
							elementLabel->Text = headersOfTable[i] + ":" + elementText;
							elementLabel->ForeColor = Color::Black; 
							elementLabel->BackColor = Color::Transparent;
							elementLabel->AutoSize = true;
							panel2->Controls->Add(elementLabel);
							this->panel2->Visible = true;

						}
						backBtn = gcnew System::Windows::Forms::Button();
						backBtn->Location = System::Drawing::Point(0, 0);
						backBtn->Name = L"button2";
						backBtn->Size = System::Drawing::Size(100, 100);
						backBtn->TabIndex = 1;
						backBtn->Text = L"←";
						backBtn->Font = (gcnew System::Drawing::Font(L"Candara", 34, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
							static_cast<System::Byte>(0)));
						backBtn->UseVisualStyleBackColor = true;
						backBtn->Click += gcnew System::EventHandler(this, &Tovar::backToElems);
						panel2->Controls->Add(backBtn);
					}
					else {
						for (int i = 1; i <arrayOfFoundedElement->Length; i+=9) {
							for (int j = 0; j < entries.size(); j++) {
								System::String^ managedTitle = msclr::interop::marshal_as<System::String^>(entries[j].title);
								if (arrayOfFoundedElement[i]->Contains(managedTitle)) {
							System::String^ managedType = msclr::interop::marshal_as<System::String^>(entries[j].type);
								}
							}
						}
						this->panel2->Controls->Clear();
						panel2->AutoScroll = true;
						int lastI = 1;
						int index = ((arrayOfFoundedElement->Length) / 9) + 1;
						for (int i = 0; i < arrayOfFoundedElement->Length ; i++) {
							if (lastI == i) {
								Label^  marker = gcnew Label();
							marker->Text = arrayOfFoundedElement[i];
						marker->Text =  index.ToString()+")";
						marker->Font = (gcnew System::Drawing::Font(L"Candara", 22, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
							static_cast<System::Byte>(0)));
						marker->Size = System::Drawing::Size(panel2->Width, 80);
						marker->Cursor = Cursors::Hand;
								index--;
								Label^ favElems = gcnew Label();
								for (int j = 0; j < entries.size(); j++) {
									System::String^ managedString = msclr::interop::marshal_as<System::String^>(entries[j].title);
									if (arrayOfFoundedElement[i]->Contains(managedString)) {
									System::String^ managedPit = msclr::interop::marshal_as<System::String^>(entries[j].country);
										System::String^ managedPrice = msclr::interop::marshal_as<System::String^>(entries[j].price);
										System::String^ managedType= msclr::interop::marshal_as<System::String^>(entries[j].type);
										favElems->Text =" "+ arrayOfFoundedElement[i] + ": " + managedType + " " + managedPrice + "$ " + managedPit;
									}
								}
								if (index % 2 == 0) {
								favElems->BackColor = Color::Orange;
								}
								else {
								favElems->BackColor = System::Drawing::Color::Salmon;
								}
								favElems->Font = (gcnew System::Drawing::Font(L"Candara", 22, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
									static_cast<System::Byte>(0)));
								favElems->ForeColor = Color::Black;
								favElems->Size = System::Drawing::Size(700, 80);
								favElems->Cursor = Cursors::Hand;
								favElems->Click += gcnew System::EventHandler(this, &Tovar::navigateToFoundElement_Click);
								favElems->Dock = DockStyle::Top;
								Label^ markerr = gcnew Label();
								markerr->Text = arrayOfFoundedElement[i-1];
							markerr->Location = System::Drawing::Point(50, i*5);
								panel2->Controls->Add(favElems);
								lastI += 9;
							}
						}
					} 

				} 

			} 
		}
		//LoadData(" ");
		void InitializeComponent(void)
		{
			LoadData(" ");
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Candara", 24.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(171, 51);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Tovar::back);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			this->panel1->Controls->Add(this->comboBox2);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Location = System::Drawing::Point(-5, -4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1947, 1154);
			this->panel1->TabIndex = 1;
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0-30", L"31-60", L"60-100", L"0-100" });
			this->comboBox2->Location = System::Drawing::Point(1064, 77);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 37);
			this->comboBox2->TabIndex = 7;
			this->comboBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Tovar::comboBox1_KeyPress);
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Tovar::comboBox2_SelectedIndexChanged);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Candara", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(1421, 72);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(168, 42);
			this->button7->TabIndex = 6;
			this->button7->Text = L"All";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Tovar::all);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label2);
			this->panel4->Controls->Add(this->button6);
			this->panel4->Location = System::Drawing::Point(58, 169);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1958, 806);
			this->panel4->TabIndex = 2;
			this->panel4->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Candara", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(716, 277);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(453, 78);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Unable to book";
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(804, 428);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(310, 67);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Ok";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Tovar::unableToBook);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Candara", 17.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(1254, 67);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(100, 47);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Search";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Tovar::searchClick);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->button3);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Location = System::Drawing::Point(89, 166);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1927, 904);
			this->panel3->TabIndex = 0;
			this->panel3->Visible = false;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Candara", 48, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(608, 411);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(475, 84);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Ok";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Tovar::ok);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Candara", 59.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(552, 217);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(601, 96);
			this->label1->TabIndex = 0;
			this->label1->Text = L"You are unlogged";
			this->label1->Click += gcnew System::EventHandler(this, &Tovar::label1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Candara", 18.25F, System::Drawing::FontStyle::Italic));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"title", L"type", L"code", L"accessibility", L"price",
					L"pit", L"country"
			});
			this->comboBox1->Location = System::Drawing::Point(30, 79);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(380, 37);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Tovar::comboBox1_KeyPress);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button4);
			this->panel2->Location = System::Drawing::Point(139, 194);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1621, 781);
			this->panel2->TabIndex = 2;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 38.25F));
			this->button4->Location = System::Drawing::Point(35, 16);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(78, 80);
			this->button4->TabIndex = 0;
			this->button4->Text = L"←";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &Tovar::backToElems);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(0, 0);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
			this->textBox1->Location = System::Drawing::Point(428, 79);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(566, 35);
			this->textBox1->TabIndex = 0;
			// 
			// Tovar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 932);
			this->Controls->Add(this->panel1);
			this->Name = L"Tovar";
			this->Text = L"Tovar";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void dataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->ColumnIndex == indexOfTitlesColumn) {
				String^ selectedValue = dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString();
				selectedGrid = selectedValue;
				this->dataGridView->Visible = false;
				LoadData("grid");
			}
		}
private: System::Void comboBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	e->Handled = true; 
}
	private: System::Void back(System::Object^ sender, System::EventArgs^ e) {
		this->Owner->Show();  
		this->Close(); 
	}
	 private: System::Void navigateToFoundElement_Click(System::Object^ sender, System::EventArgs^ e) {
			   Label^ clickedLabel = dynamic_cast<Label^>(sender); 
			   if (clickedLabel != nullptr) {
				   String^ labelText = clickedLabel->Text;
				   labelText = labelText->Substring(1);
				   std::string filename = "input.txt";
				   FileReader reader(filename);
				   reader.readFile();
				   reader.showStructureOfUsers();
				   std::vector<std::string> data = reader.getArrayofGettedData();
				   std::vector<Entry> entries;
				   for (const std::string& line : data) {
					   Entry entry;
					   reader.parseInput(line, entry);
					   entries.push_back(entry);
				   }
				   panel2->Controls->Clear();
				   int indexOfColon = labelText->IndexOf(':');
				   if (indexOfColon != -1)
				   { 
					  labelText = labelText->Substring(0, indexOfColon)->Trim();
					 
				   }
				   std::string value = reader.findElem(labelText);
				   System::String^ valueString = gcnew System::String(value.c_str());
				   foundElement = valueString;
				   array<System::String^>^ arrayOfFoundedElement = valueString->Split(':');
				   std::string valuee;
				   for (int j = 0; j < entries.size(); j++) {
					   System::String^ managedTitle = msclr::interop::marshal_as<System::String^>(entries[j].title);
					   if (arrayOfFoundedElement[1]->Contains(managedTitle)) {
						   System::String^ managedType = msclr::interop::marshal_as<System::String^>(entries[j].type);
						   valuee = entries[j].url;
					   }
				   }
				 indexOfImageString = gcnew System::String(valuee.c_str());
				   PictureBox^ picturee = gcnew PictureBox();
				   picturee->Location = System::Drawing::Point(116, 67);
				   picturee->Name = L"pictureBox1";
				   picturee->Size = System::Drawing::Size(650, 362);
				   picturee->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				   picturee->TabIndex = 2;
				   picturee->TabStop = false;
				   picturee->ImageLocation = indexOfImageString;
				   panel2->Controls->Add(picturee);
				   for (int i = 0; i < arrayOfFoundedElement->Length; i++) {
					   String^ elementText = arrayOfFoundedElement[i];
											  Label^ elementLabel = gcnew Label();
											  int labelX = 1000;
											  int labelY = 250 + i * 30;
											  if (i == 1) {
												  selectedElement = arrayOfFoundedElement[i];
												  elementLabel->Font = (gcnew System::Drawing::Font(L"Candara", 32, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
													  static_cast<System::Byte>(0)));
												  elementLabel->Location = System::Drawing::Point(labelX, labelY - 100);
											  }
											  else {
												  elementLabel->Font = (gcnew System::Drawing::Font(L"Candara", 17, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
													  static_cast<System::Byte>(0)));
												  elementLabel->Location = System::Drawing::Point(labelX, labelY);
											  }
											 elementLabel->Text = headersOfTable[i] + ":" + elementText;
											  elementLabel->ForeColor = Color::Black;
											  elementLabel->BackColor = Color::Transparent;
											  elementLabel->AutoSize = true;
											  panel2->Controls->Add(elementLabel);
										  } 
										  addBtn = gcnew System::Windows::Forms::Button();
										  addBtn->Text = L"Add to favourite";
										 addBtn->Cursor = System::Windows::Forms::Cursors::Hand;
										  addBtn->Location = System::Drawing::Point(166, 598);
										addBtn->Font = (gcnew System::Drawing::Font(L"Candara", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
											  static_cast<System::Byte>(0)));
										  addBtn->Size = System::Drawing::Size(300, 76);
										  addBtn->Click += gcnew System::EventHandler(this, &Tovar::addToFavButton_Click);
										  panel2->Controls->Add(addBtn);
										  addBtn->BringToFront();
										  backBtn = gcnew System::Windows::Forms::Button();
										  backBtn->Location = System::Drawing::Point(0, 0);
										  backBtn->Name = L"button2";
										  backBtn->Size = System::Drawing::Size(100, 100);
										  backBtn->TabIndex = 1;
										  backBtn->Text = L"←";
										backBtn->Font = (gcnew System::Drawing::Font(L"Candara", 34, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
											  static_cast<System::Byte>(0)));
										  backBtn->UseVisualStyleBackColor = true;
										  backBtn->Click += gcnew System::EventHandler(this, &Tovar::backToElems);
										  panel2->Controls->Add(backBtn);

			   } 
		   }
		   void Tovar::searchClick(System::Object^ sender, System::EventArgs^ e)
		   {
			   this->dataGridView->Visible = false;
			   LoadData("search");
			   
		   }
		   private: System::Void addToFavButton_Click(System::Object^ sender, System::EventArgs^ e) {
			   if (isAutherizated) {
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
				   int indexOfSel = 0;
				   int cAccess = 0;
				   std::string inf;
				   for (int i = 0; i < entriesSize; i++) {
					   System::String^ selectedAccessibility = msclr::interop::marshal_as<System::String^>(entries[i].accessibility);
					   System::String^ selectedTitle = msclr::interop::marshal_as<System::String^>(entries[i].title);
					   if (selectedElement->Contains(selectedTitle)) {
						   if (selectedAccessibility->Contains(" not")) {
							   this->panel4->Visible = true;
							   cAccess++;
						   }
					   }
				   }
				   if (cAccess == 0) {
				   reader.addToFav(selectedElement, nameOfUser);
				   }
			   }
			   else {
				   this->panel3->Visible = true;
				   this->panel3->BringToFront();
			   }
		   }
	private: System::Void ok(System::Object^ sender, System::EventArgs^ e) {
		this->panel3->Visible = false;
	}
private: System::Void backToElems(System::Object^ sender, System::EventArgs^ e) {
	this->panel2->Controls->Clear();
	this->dataGridView->Visible = true;
}
private: System::Void unableToBook(System::Object^ sender, System::EventArgs^ e) {
	this->panel4->Visible = false;
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void all(System::Object^ sender, System::EventArgs^ e) {
	dataGridView->Visible = true;
	this->panel4->Visible = false;
	this->panel3->Visible = false;
	this->panel2->Visible = false;
}
	   private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) { 
		   System::String^ selectedText = comboBox2->SelectedItem->ToString();
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
		   array<System::String^>^ arrayOfPrice = selectedText->Split('-');
		 std::string value = reader.searchByPrice(selectedText, arrayOfPrice[0], arrayOfPrice[1]);
		   this->dataGridView->Visible = false;
		   this->panel2->Visible = true;
		   reader.show();
		   String^ text = textBox1->Text;
		   String^ selected = comboBox1->SelectedItem ? comboBox1->SelectedItem->ToString() : nullptr;
		   if (selected != nullptr) {
			   try {
				   System::String^ filePath = "ruc.pdf";
				   value = reader.sear(text, selected);
			   }
			   catch (System::Exception^ ex) {
				   System::Windows::Forms::MessageBox::Show("Something gone wrong");
			   }
		   }
		   else {
			   try {
				   System::String^ filePath = "ruc.pdf";
			   }
			   catch (System::Exception^ ex) {
				   System::Windows::Forms::MessageBox::Show("Something gone wrong");
			   }
		   }
		   System::String^ valueString = gcnew System::String(value.c_str());
		   foundElement = valueString;
		   if (foundElement->Contains("Not Found"))
		   {
			   this->panel2->Controls->Clear();
			   String^ elementText = "Not found";
			   Label^ elementLabel = gcnew Label();
			   elementLabel->Text = elementText;
			   elementLabel->ForeColor = Color::Black;
			   elementLabel->BackColor = Color::Transparent;
			   elementLabel->AutoSize = true;
			   elementLabel->Font = (gcnew System::Drawing::Font(L"Candara", 72, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   elementLabel->Location = System::Drawing::Point(700, 300);
			   panel2->Controls->Add(elementLabel);
			   this->panel2->Visible = true;
		   }
		   else {
			   array<System::String^>^ arrayOfFoundedElement = valueString->Split(':');
			   if (arrayOfFoundedElement->Length <= 9) {
				   this->panel2->Controls->Clear();
				   std::string valuee = reader.searchImage(arrayOfFoundedElement[1]);
				   indexOfImageString = gcnew System::String(valuee.c_str());
				   PictureBox^ picturee = gcnew PictureBox();
				   picturee->Location = System::Drawing::Point(116, 67);
				   picturee->Name = L"pictureBox1";
				   picturee->Size = System::Drawing::Size(650, 362);
				   picturee->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				   picturee->TabIndex = 2;
				   picturee->TabStop = false;
				   picturee->ImageLocation = indexOfImageString;
				   panel2->Controls->Add(picturee);
				   addBtn = gcnew System::Windows::Forms::Button();
				   addBtn->Text = L"Add to favourite";
				   addBtn->Location = System::Drawing::Point(166, 598);
				   addBtn->Font = (gcnew System::Drawing::Font(L"Candara", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					   static_cast<System::Byte>(0)));
				   addBtn->Size = System::Drawing::Size(300, 76);
				   addBtn->Click += gcnew System::EventHandler(this, &Tovar::addToFavButton_Click);
				   panel2->Controls->Add(addBtn);
				   addBtn->BringToFront();
				   for (int i = 0; i < arrayOfFoundedElement->Length; i++) {
					   String^ elementText = arrayOfFoundedElement[i];
					   Label^ elementLabel = gcnew Label();
					   int labelX = 1000;
					   int labelY = 250 + i * 30;
					   if (i == 1) {
						   selectedElement = arrayOfFoundedElement[i];
						   elementLabel->Font = (gcnew System::Drawing::Font(L"Candara", 32, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
							   static_cast<System::Byte>(0)));
						   elementLabel->Location = System::Drawing::Point(labelX, labelY - 100);
					   }
					   else {
						   elementLabel->Font = (gcnew System::Drawing::Font(L"Candara", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
							   static_cast<System::Byte>(0)));
						   elementLabel->Location = System::Drawing::Point(labelX, labelY);
					   }
					   elementLabel->Text = headersOfTable[i] + ":" + elementText;
					   elementLabel->ForeColor = Color::Black;
					   elementLabel->BackColor = Color::Transparent;
					   elementLabel->AutoSize = true;
					   panel2->Controls->Add(elementLabel);
					   this->panel2->Visible = true;

				   }
				   addBtn = gcnew System::Windows::Forms::Button();
				   addBtn->Text = L"Add to favourite";
				   addBtn->Location = System::Drawing::Point(1466, 798);
				   addBtn->Size = System::Drawing::Size(300, 76);
				   addBtn->Click += gcnew System::EventHandler(this, &Tovar::addToFavButton_Click);
				   panel2->Controls->Add(addBtn);
				   addBtn->BringToFront();
				   backBtn = gcnew System::Windows::Forms::Button();
				   backBtn->Location = System::Drawing::Point(0, 0);
				   backBtn->Name = L"button2";
				   backBtn->Size = System::Drawing::Size(100, 100);
				   backBtn->TabIndex = 1;
				   backBtn->Text = L"←";
				   backBtn->Font = (gcnew System::Drawing::Font(L"Candara", 34, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					   static_cast<System::Byte>(0)));
				   backBtn->UseVisualStyleBackColor = true;
				   backBtn->Click += gcnew System::EventHandler(this, &Tovar::backToElems);
				   panel2->Controls->Add(backBtn);
			   }
			   else {
				   for (int i = 1; i < arrayOfFoundedElement->Length; i += 9) {
					   Console::WriteLine("ELLLLLLLLLLLLLLLLLLLLLLLEEEEEEEEEEEEMENT" + arrayOfFoundedElement[i]);
					   for (int j = 0; j < entries.size(); j++) {
						   System::String^ managedTitle = msclr::interop::marshal_as<System::String^>(entries[j].title);
						   if (arrayOfFoundedElement[i]->Contains(managedTitle)) {
							   System::String^ managedType = msclr::interop::marshal_as<System::String^>(entries[j].type);
						   }
					   }

				   }
				   this->panel2->Controls->Clear();
				   panel2->AutoScroll = true;
				   int lastI = 1;
				   int index = ((arrayOfFoundedElement->Length) / 9) + 1;
				   for (int i = 0; i < arrayOfFoundedElement->Length; i++) {
					   if (lastI == i) {
						   Label^ marker = gcnew Label();
						   marker->Text = arrayOfFoundedElement[i];
						   marker->Text = index.ToString() + ")";
						   marker->Font = (gcnew System::Drawing::Font(L"Candara", 22, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
							   static_cast<System::Byte>(0)));
						   marker->Size = System::Drawing::Size(panel2->Width, 80);
						   marker->Cursor = Cursors::Hand;
						   index--;
						   Label^ favElems = gcnew Label();
						   for (int j = 0; j < entries.size(); j++) {
							   System::String^ managedString = msclr::interop::marshal_as<System::String^>(entries[j].title);
							   if (arrayOfFoundedElement[i]->Contains(managedString)) {
								   System::String^ managedPit = msclr::interop::marshal_as<System::String^>(entries[j].country);
								   System::String^ managedPrice = msclr::interop::marshal_as<System::String^>(entries[j].price);
								   System::String^ managedType = msclr::interop::marshal_as<System::String^>(entries[j].type);
								   favElems->Text = " " + arrayOfFoundedElement[i] + ": " + managedType + " " + managedPrice + "$ " + managedPit;
							   }
						   }
						   if (index % 2 == 0) {
							   favElems->BackColor = Color::Orange;
						   }
						   else {
							   favElems->BackColor = System::Drawing::Color::Salmon;

						   }
						   favElems->Font = (gcnew System::Drawing::Font(L"Candara", 22, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
							   static_cast<System::Byte>(0)));
						   favElems->ForeColor = Color::Black;
						   favElems->Size = System::Drawing::Size(700, 80);
						   favElems->Cursor = Cursors::Hand;
						   favElems->Click += gcnew System::EventHandler(this, &Tovar::navigateToFoundElement_Click);
						   favElems->Dock = DockStyle::Top;
						   Label^ markerr = gcnew Label();
						   markerr->Text = arrayOfFoundedElement[i - 1];
						   markerr->Location = System::Drawing::Point(50, i * 5);
						   panel2->Controls->Add(favElems);
						   lastI += 9;

					   }
				   }
			  		   } 

		   }

	 //  }




















		   // Выводим "Hello" и выбранный элемент
		//   System::Windows::Forms::MessageBox::Show("Hello! Выбран элемент: " + selectedText);
	   }

//private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
//}
};
}
