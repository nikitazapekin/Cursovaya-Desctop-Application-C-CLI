#pragma once

#include "FileReader.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>  
#include <vcclr.h>  

//#include <msclr/marshal_cppstd.h>

#include  "Entry.h"



/*
namespace Project10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
 
	public ref class Offers : public System::Windows::Forms::Form
	{
	public:
		Offers(void)
		{
			InitializeComponent();
			
		}

	protected:
	 


		~Offers()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;
	//private: System::Windows::Forms::Button^ addBtn;
	protected:

	

	private:
		
		System::ComponentModel::Container ^components;

/*
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
		// string typedTitle = "";
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

			//array<String^>^ arrayOfFoundedElement;
			std::string filename = "input.txt";
			FileReader reader(filename);
			reader.readFile();
			reader.showStructureOfUsers();

			std::vector<std::string> data = reader.getArrayofGettedData();
			String^ imageUrl = "https://fikiwiki.com/uploads/posts/2022-02/1644918620_17-fikiwiki-com-p-krasivie-kartinki-visokogo-razresheniya-19.jpg";
			headersOfTable = gcnew array<String^> { "type", "title", "rate", "accessibility", "price", "id", "pit", "data", "country" };


			std::vector<Entry> entries;

			//	reader.showStructureOfUsers();

			for (const std::string& line : data) {
				std::cout << line << std::endl;

			}



			//	std::vector<Entry> entries;


			for (const std::string& line : data) {
				Entry entry;
				reader.parseInput(line, entry);
			//   System::Console::WriteLine(line);
				std::cout << line << std::endl;
				entries.push_back(entry);
			}



			entriesSize = entries.size();




			for (int i = 0; i < entriesSize; i++) {
				arrayOfTitles[i] = msclr::interop::marshal_as<System::String^>(entries[i].title); // ñïåö ôîðìàò çàïîëíåíèÿ  ýëåìåíòàìè òàêîãî ðîäà ìàññèâîâ   array<String^>^ arrayOfTitles;
				arrayOfType[i] = msclr::interop::marshal_as<System::String^>(entries[i].type);

				arrayOfRate[i] = msclr::interop::marshal_as<System::String^>(entries[i].rate);
				arrayOfAccesibility[i] = msclr::interop::marshal_as<System::String^>(entries[i].accessibility);
				arrayOfPrice[i] = msclr::interop::marshal_as<System::String^>(entries[i].price);

				arrayOfId[i] = msclr::interop::marshal_as<System::String^>(entries[i].id);
				arrayOfPit[i] = msclr::interop::marshal_as<System::String^>(entries[i].pit);
				arrayOfCountry[i] = msclr::interop::marshal_as<System::String^>(entries[i].country);
				arrayOfUrl[i] = msclr::interop::marshal_as<System::String^>(entries[i].url);
				arrayOfData[i] = msclr::interop::marshal_as<System::String^>(entries[i].data);
				//Console::WriteLine("DAT" + arrayOfData[i]);
			}



			for (int i = 0; i < entriesSize; i++) {

				Console::WriteLine("ARRRAY" + arrayOfTitles[i]);
			}


  


			dataGridView = gcnew System::Windows::Forms::DataGridView();
			//dataGridView->Visible = false;
			int indexOfDesiredColumn = 1;
			array<String^>^ headersOfTable = gcnew array<String^> { "Type", "Title", "Rate", "Accessibility", "Price", " Id", "Feeding", "Date", "Country" }; // Replace these with your desired column names

			dataGridView->ColumnCount = headersOfTable->Length;
			dataGridView->Size = System::Drawing::Size(1550, 700);
			for (int i = 0; i < headersOfTable->Length; i++) {
				dataGridView->Columns[i]->Name = headersOfTable[i];
			}

			for (int i = 0; i < entriesSize; i++) {
				dataGridView->ForeColor = System::Drawing::Color::Black;
				dataGridView->Rows->Add(arrayOfType[i], arrayOfTitles[i], arrayOfRate[i], arrayOfAccesibility[i], arrayOfPrice[i], arrayOfId[i], arrayOfPit[i], arrayOfData[i], arrayOfCountry[i]);
			}

			indexOfTitlesColumn = indexOfDesiredColumn;  // Set the desired column index

			// Add a DataGridView CellClick event handler
		//	 dataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView_CellClick);
			dataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Offers::dataGridView_CellClick);
			dataGridView->AllowUserToOrderColumns = true;
			dataGridView->AllowUserToResizeColumns = true;
			dataGridView->AllowUserToAddRows = false;

			dataGridView->Location = System::Drawing::Point(100, 200);
		//	this->panel9->Visible = true;
		//	this->panel1->Controls->Add(dataGridView);
				this->Controls->Add(dataGridView);
			dataGridView->BringToFront();
		 

 


		} 
	 




//#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{

		//	LoadData(" ");
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(159, 59);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"back";
			this->button1->UseVisualStyleBackColor = true;
		//	this->button1->Click += gcnew System::EventHandler(this, &Offers::back);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->Location = System::Drawing::Point(204, 116);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1193, 499);
			this->panel1->TabIndex = 1;
			// 
			// Offers
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1840, 875);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Name = L"Offers";
			this->Text = L"Offers";
			this->ResumeLayout(false);

		}
#pragma endregion

	 
	//	void MyForm::dataGridView_CellClick(System::Object ^ sender, System::Windows::Forms::DataGridViewCellEventArgs ^ e) {
	/*	private: System::Void dataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		//	this->panel8->Visible = false;
			if (e->ColumnIndex == indexOfTitlesColumn) {

				String^ selectedValue = dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString();


			 
				selectedGrid = selectedValue;
				LoadData("grid");
				this->dataGridView->Visible = false;
				//this->panel7->Visible = false;

			}
		}

	 

			 

	private: System::Void back(System::Object^ sender, System::EventArgs^ e) {

		this->Owner->Show(); // Ïîêàçûâàåì ïåðâóþ ôîðìó
		this->Close(); // Çàêðûâàåì âòîðóþ ôîðìó

	} ) 
	};
}
*/









#pragma once

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
	public ref class Offers : public System::Windows::Forms::Form
	{
	public:
		Offers(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Offers()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(152, 81);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Offers::back);
			// 
			// Account
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1045);
			this->Controls->Add(this->button1);
			this->Name = L"Offers";
			this->Text = L"Offers";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void back(System::Object^ sender, System::EventArgs^ e) {
		this->Owner->Show(); // Ïîêàçûâàåì ïåðâóþ ôîðìó
		this->Close(); // Çàêðûâàåì âòîðóþ ôîðìó


	}
	};
}
