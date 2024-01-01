#pragma once


#include  "Entry.h"
#include "FileReader.h"
#include "FileReader.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>  
#include <vcclr.h>  
#include "consts.h"

#include <sstream>

#include <fstream>
#include <string>
namespace Project10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
	 
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;


	private: System::Windows::Forms::Button^ openFileButton;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ offersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ accoutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ usageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	protected:

	private:
	
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		
		  void	LoadData(String^ method) {
	//	arrayOfPersonalData = gcnew array<String^>(5);
		std::string filename = "input.txt";
		FileReader reader(filename);
		reader.readFile();
		reader.clearConsts();
		reader.showStructureOfUsers();

		std::vector<std::string> data = reader.getArrayofGettedData();


	}
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->openFileButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->offersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->accoutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->usageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileButton
			// 
			this->openFileButton->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->openFileButton->Location = System::Drawing::Point(609, 114);
			this->openFileButton->Name = L"openFileButton";
			this->openFileButton->Size = System::Drawing::Size(260, 75);
			this->openFileButton->TabIndex = 0;
			this->openFileButton->Text = L"Open File";
			this->openFileButton->Visible = false;
			this->openFileButton->Click += gcnew System::EventHandler(this, &MyForm::openFileButton_Click);
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(35, 114);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(233, 75);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Offers";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(335, 114);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(233, 75);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Account";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::account);
			// 
			// button3
			// 
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(1643, 167);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(260, 75);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(1149, 488);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(724, 584);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(-122, 314);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(914, 775);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Location = System::Drawing::Point(0, 70);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1924, 1125);
			this->panel1->TabIndex = 6;
			this->panel1->Visible = false;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Candara", 59.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(702, 269);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(447, 96);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Incorrect file";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Candara", 48, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(718, 436);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(431, 125);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Ok";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::ok);
			// 
			// button5
			// 
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Font = (gcnew System::Drawing::Font(L"Candara", 38.75F, System::Drawing::FontStyle::Italic));
			this->button5->Location = System::Drawing::Point(901, 114);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(260, 75);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Usage";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::ab);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Candara", 38.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(1266, 180);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(260, 75);
			this->button6->TabIndex = 8;
			this->button6->Text = L"About";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::aboutClick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Candara", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->offersToolStripMenuItem,
					this->accoutToolStripMenuItem, this->openFileToolStripMenuItem, this->usageToolStripMenuItem, this->aboutToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1924, 67);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// offersToolStripMenuItem
			// 
			this->offersToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Candara", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->offersToolStripMenuItem->Margin = System::Windows::Forms::Padding(50, 0, 0, 0);
			this->offersToolStripMenuItem->Name = L"offersToolStripMenuItem";
			this->offersToolStripMenuItem->Size = System::Drawing::Size(155, 63);
			this->offersToolStripMenuItem->Text = L"Offers";
			this->offersToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::offers);
			// 
			// accoutToolStripMenuItem
			// 
			this->accoutToolStripMenuItem->Margin = System::Windows::Forms::Padding(50, 0, 0, 0);
			this->accoutToolStripMenuItem->Name = L"accoutToolStripMenuItem";
			this->accoutToolStripMenuItem->Size = System::Drawing::Size(174, 63);
			this->accoutToolStripMenuItem->Text = L"Accout";
			this->accoutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::account);
			// 
			// openFileToolStripMenuItem
			// 
			this->openFileToolStripMenuItem->Margin = System::Windows::Forms::Padding(50, 0, 0, 0);
			this->openFileToolStripMenuItem->Name = L"openFileToolStripMenuItem";
			this->openFileToolStripMenuItem->Size = System::Drawing::Size(219, 63);
			this->openFileToolStripMenuItem->Text = L"Open File";
			this->openFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openFileButton_Click);
			// 
			// usageToolStripMenuItem
			// 
			this->usageToolStripMenuItem->Margin = System::Windows::Forms::Padding(50, 0, 0, 0);
			this->usageToolStripMenuItem->Name = L"usageToolStripMenuItem";
			this->usageToolStripMenuItem->Size = System::Drawing::Size(156, 63);
			this->usageToolStripMenuItem->Text = L"Usage";
			this->usageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ab);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Margin = System::Windows::Forms::Padding(50, 0, 0, 0);
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(160, 63);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutClick);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Margin = System::Windows::Forms::Padding(500, 0, 0, 0);
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(113, 63);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Candara", 56.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(568, 291);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(810, 91);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Welcome to the industry ";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Candara", 56.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(677, 404);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(479, 91);
			this->label3->TabIndex = 11;
			this->label3->Text = L"booking app!!!";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(1924, 897);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->openFileButton);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void offers(System::Object^ sender, System::EventArgs^ e);
	private: System::Void account(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
		   size_t countCommas(const std::string& line) {
			   size_t count = 0;
			   for (char ch : line) {
				   if (ch == ',') {
					   count++;
				   }
			   }
			   return count;
		   }
		   System::Void openFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
			   openFileDialog1->Filter = "Text Files|*.txt|All Files|*.*";
			   openFileDialog1->Title = "Select a Text File";
			   if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				   String^ fileName = openFileDialog1->FileName;
				   std::string filename = msclr::interop::marshal_as<std::string>(fileName);
				   FileReader reader(filename);
				   reader.readdFile();
				   std::vector<std::string> data = reader.getArrayofGettedData();
				   std::vector<Entry> entries;
				   bool empy = false;
				   for (const std::string& line : data) {
					   int commasInLine = countCommas(line);
					   if (!line.empty()) {
						   Entry entry;
						   reader.parseInput(line, entry);
						   entries.push_back(entry);
					   }	
				   }
				   for (int i = 1; i < entries.size(); i++) {
					   if (entries[i].type.empty())
					   {
						   empy = true;
					   }
					   else {
					   }
					   if (entries[i].title.empty()) {
						   empy = true;
					   }
					   else {
					   }
					   if (entries[i].rate.empty()) {
						   empy = true;
					   }
					   else {
					   }
					   if (entries[i].price.empty()) {
						   empy = true;
					   }
					   else {
					   }
					   if (entries[i].accessibility.empty()) {
						   empy = true;
					   }
					   else {
					   }
					   if (entries[i].id.empty()) {
						   empy = true;
					   }
					   else {
					   }
					   if (entries[i].pit.empty()) {
						   empy = true;
					   }
					   else {
					   }
					   if (entries[i].data.empty()) {
						   empy = true;
					   }
					   else {
					   }
					   std::cout << "\n";
					   if (entries[i].url.empty()) {
						   empy = true;
					   }
					   else {
					   }
					   if (entries[i].country.empty()) {
						   empy = true;
					   }
					   else {
					   }
				   }
				   if (!empy && entries.size()!=1 && entries.size() != 0) {
					   std::ofstream outputFile("route.txt", std::ios::trunc);
					   if (!outputFile.is_open()) {
						   std::cout << "Failed to open the file: logs.txt" << std::endl;
					   }
					   else {
						   outputFile << filename;
					   }
					   outputFile.close();
				   }
				   else {
					   std::ofstream outputFile("route.txt", std::ios::trunc);
					   this->panel1->Visible = true;
					   this->panel1->BringToFront();
					   if (!outputFile.is_open()) {
						   std::cout << "Failed to open the file: logs.txt" << std::endl;
					   }
					   else {
						 
						   outputFile <<"input.txt";
					   }
					   outputFile.close();
				   }
			   }
		   }
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void ok(System::Object^ sender, System::EventArgs^ e) {
	this->panel1->Visible = false;
}
	private: System::Void about(System::Object^ sender, System::EventArgs^ e) {
		try {
			System::String^ filePath = "ruc.pdf";
			System::Diagnostics::Process::Start(filePath);
		}
		catch (System::Exception^ ex) {
			System::Windows::Forms::MessageBox::Show(ex->Message);
		}
	}

private: System::Void ab(System::Object^ sender, System::EventArgs^ e) {
	try {
		System::String^ filePath = "ruc.pdf";
		System::Diagnostics::Process::Start(filePath);
	}
	catch (System::Exception^ ex) { 
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}
private: System::Void aboutClick(System::Object^ sender, System::EventArgs^ e) {

	try {
		System::String^ filePath = "ab.pdf";
		System::Diagnostics::Process::Start(filePath);
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show(ex->Message);
	}
}
private: System::Void menuStrip1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void off(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}



