

#include "MyForm.h"
#include "Offers.h"
#include "FileReader.h"
#include <locale>
#include "Account.h"
#include "Tovar.h"
#include "Windows.h"
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;
FileReader exe;
[STAThread]
int main(array<String^>^ args) {
	setlocale(LC_ALL, "rus");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Project10::MyForm());

	return 0;
}

System::Void Project10::MyForm::offers(System::Object^ sender, System::EventArgs^ e)
{


	Project10::Tovar^ f2 = gcnew Project10::Tovar();
	f2->Owner = this;
	this->Hide();
	f2->ShowDialog();
}
System::Void Project10::MyForm::account(System::Object^ sender, System::EventArgs^ e)
{
	
	Project10::Account^ f2 = gcnew Project10::Account();
	f2->Owner = this;
	this->Hide();
	f2->ShowDialog();



}

