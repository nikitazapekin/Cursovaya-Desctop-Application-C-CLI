#include "FileReader.h"
#include <iostream>
#include <sstream>
#include <string>;
#include <msclr\marshal_cppstd.h>  
#include <vcclr.h>  
#include "Windows.h"
#include <fstream>
#include <sstream>
using namespace std;
FileReader::FileReader(const std::string& filename) : filename(filename) {
}

FileReader::FileReader() {
}

FileReader::~FileReader() {
}
bool FileReader::readdFile() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the file: " << filename << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        arrayOfgettedData.push_back(line);
    }
    file.close();
    return true;
}
bool FileReader::readFile() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string filename;
    std::ifstream inputFile("route.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            filename = line;
        }
    }
        inputFile.close();
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the file: " << filename << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        arrayOfgettedData.push_back(line);
    }
    file.close();
    return true;
}
int FileReader::searchIndexOfElement(System::String^ method) {
    for (int i = 0; i < entries.size(); i++) {
        System::String^ title = gcnew System::String(entries[i].title.c_str());
        if (title->Contains(method)) {
            return i;
        }
    }
     
    return -1;
}



