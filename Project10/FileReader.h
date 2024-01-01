
#pragma once
#include <string>
#include <vector>
#include <string>
#include  "Entry.h"
#include  "Users.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <limits> 
#include <cstdlib> 
#include <ctime>
#include <algorithm>
#include <iomanip> 
#include <sstream>
#include <msclr\marshal_cppstd.h>  
#include <vcclr.h>  
class FileReader {
private:
    std::vector<Entry> entries;
    std::vector<Users>users;
    std::vector<std::string> arrayOfgettedData;
    std::vector<std::string> arrayOfType;
    std::vector<std::string> arrayOfTitle;
    std::vector<std::string> arrayOfRate;
    std::vector<std::string> arrayOfAccesebility;
    std::vector<std::string> arrayOfPosition;
    std::vector<std::string> allWords;
    std::vector<std::string> arr1;
    std::vector<std::string> arr2;
    std::vector<std::string> arr3;
    std::vector<std::string> arr4;
    std::vector<std::string> arr5;
    std::vector<std::string> arr6;
    std::vector<std::string> arr7;
    std::vector<std::string> arr8;
    std::string filename;
public:
    FileReader(const std::string& filename);
    FileReader();
    ~FileReader();
    static bool compareByAccessibility(const Entry& entry1, const Entry& entry2) {
        std::string item1 = entry1.price.substr(1);
        std::string item2 = entry2.price.substr(1);
        return std::stoi(item1) < std::stoi(item2);
    }
    static bool compareByAccessibility1(const Entry& entry1, const Entry& entry2) {
        std::string item1 = entry1.rate.substr(1);
        size_t pos = item1.find("st");
        if (pos != std::string::npos) {
            item1.erase(pos, 2);
        }
        std::string item2 = entry2.rate.substr(1);
        pos = item2.find("st");
        if (pos != std::string::npos) {
            item2.erase(pos, 2);
        }
        return std::stoi(item1) < std::stoi(item2);
    }
    std::vector<std::string> FileReader::getArrayofGettedData() {
        return arrayOfgettedData;
    }
    std::vector<Entry> FileReader::getTest() {
        return entries;
    }
    void parseInput(const std::string& input, Entry& entry) {
        std::istringstream iss(input);
        std::string segment;
        while (std::getline(iss, segment, ';')) {
            std::string category, value1, value2, value3, value4, value5, value6, value7, value8, value9;
            size_t colon_pos = segment.find(':');
            if (colon_pos != std::string::npos) {
                category = segment.substr(0, colon_pos);
                segment.erase(0, colon_pos + 1);
                std::istringstream sub_iss(segment);
                std::getline(sub_iss, value1, ',');
                std::getline(sub_iss, value2, ',');
                std::getline(sub_iss, value3, ',');
                std::getline(sub_iss, value4, ',');
                std::getline(sub_iss, value5, ',');
                std::getline(sub_iss, value6, ',');
                std::getline(sub_iss, value7, ',');
                std::getline(sub_iss, value8, ',');
                std::getline(sub_iss, value9, ',');
                entry.type = category;
                entry.title = value1;
                entry.rate = value2;
                entry.accessibility = value3;
                entry.price = value4;
                entry.id = value5;
                entry.pit = value6;
                entry.data = value7;
                entry.url = value8;
                entry.country = value9;
                entries.push_back(entry);
            }
        }
    }
    std::string encrypt(const std::string& input, const std::string& key) {
        std::string encrypted = input;
        for (char& c : encrypted) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                c = key[c - base];
            }
        }
        return encrypted;
    }
    void parseAndAddToUsers(const std::string& line) {
        Users newUser;
        std::istringstream iss(line);
        std::string segment;
        while (std::getline(iss, segment, ';')) {
            std::string username, email, password, favourite, history;
            std::istringstream sub_iss(segment);
            std::getline(sub_iss, username, ',');
            std::getline(sub_iss, email, ',');
            std::getline(sub_iss, password, ',');
            std::getline(sub_iss, favourite, ',');
            std::getline(sub_iss, history, ',');
            newUser.username = username;
            newUser.email = email;
            newUser.password = password;
            newUser.favourite = favourite;
            newUser.history = history;
            users.push_back(newUser);
        }
    }
    void showStructureOfUsers() {
        std::ifstream inputFile("logs.txt");
        if (!inputFile.is_open()) {
            std::cout << "Failed to open the file: " << filename << std::endl;
        }
        else {
            std::string line;
            while (std::getline(inputFile, line)) {
                parseAndAddToUsers(line);
            }
            inputFile.close();
        }
    };
    std::string decrypt(const std::string& encrypted, const std::string& key) {
        std::string decrypted = encrypted;
        for (char& c : decrypted) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                size_t index = key.find(c);
                if (index != std::string::npos) {
                    c = base + static_cast<char>(index);
                }
            }
        }
        return decrypted;
    }
  bool  checkUsername(System::String^ username) {
      std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
      for (const Users& user : users) {
          std::cout << user.username <<std::endl;
          std::cout << usernameStr << std::endl;
          if (user.username == usernameStr) {
              return 1;
          }
      }
       return 0;
    }
    void show() {
        for (const auto& entry : entries) {
            std::cout << "Type: " << entry.type << std::endl;
            std::cout << "Title: " << entry.title << std::endl;
            std::cout << "Rate: " << entry.rate << std::endl;
            std::cout << "Accessibility: " << entry.accessibility << std::endl;
            std::cout << "Price: " << entry.price << std::endl;
            std::cout << "Country: " << entry.country << std::endl;
            std::cout << "Feeding: " << entry.pit << std::endl;
            std::cout << "Data: " << entry.data << std::endl;
        }
    }
    std::string getFav(System::String^ nameOfUser) {
        std::string nameOfUserStr = msclr::interop::marshal_as<std::string>(nameOfUser);
        for (const Users& user : users) {
            if (nameOfUserStr == user.username) {
                std::cout << "Username: " << user.username << std::endl;
                std::cout << "Email: " << user.email << std::endl;
                std::cout << "Password: " << user.password << std::endl;
                std::cout << "Favourite: " << user.favourite << std::endl;
                std::cout << "History: " << user.history << std::endl;
                std::cout << std::endl;
                return user.favourite;
            }
        }
        return "";
    }
    std::string getHistory(System::String^ nameOfUser) {
        std::string nameOfUserStr = msclr::interop::marshal_as<std::string>(nameOfUser);
        for (const Users& user : users) {
            if (nameOfUserStr == user.username) {
                return user.history;
            }
        }
        return "";
    }
    void addToFav(System::String^ element, System::String^ username) {
        std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
        std::string elementStr = msclr::interop::marshal_as<std::string>(element);
        std::set<std::string> uniqueUsernames;
        std::vector<Users> usersCopyFile;
        std::string userId;
        std::string favId = "";
        for (const auto& entry : entries) {
            if (entry.title == elementStr) {
                favId = entry.title;
                favId.erase(0, 1);
            }
        }
        std::ofstream outputFile("logs.txt", std::ios::trunc);
        if (!outputFile.is_open()) {
            std::cout << "Failed to open the file: logs.txt" << std::endl;
            return;  
        }
        for (const Users& user : users) {
            if (user.username == usernameStr) {
                userId = user.username;
                Users newUser = user;
                newUser.username = user.username;
                newUser.email = user.email;
                newUser.password = user.password;
                newUser.favourite += "-";
                newUser.favourite += favId;
                newUser.history = user.history;
                usersCopyFile.push_back(newUser);
            }
            else {
                usersCopyFile.push_back(user);
            }
        }
        for (const Users& user : usersCopyFile) {
            std::string strokeForDatabase = user.username + "," + user.email + "," + user.password + "," + user.favourite + "," + user.history + ";";
            if (uniqueUsernames.insert(user.username).second) {
                std::string strokeForDatabase = user.username + "," + user.email + "," + user.password + "," + user.favourite + "," + user.history + ";";
                outputFile << strokeForDatabase << std::endl;
            }
            else {
            }
        }
        outputFile.close(); 
    }
    std::string getActualData(System::String^ username) {
        users.clear(); 
        std::ifstream inputFile("logs.txt");
        if (inputFile.is_open()) {
            std::string line;
            while (std::getline(inputFile, line)) {
                parseAndAddToUsers(line);
            }
            inputFile.close();
        }
        std::string finalStroke = "";
        for (const Users& user : users) {
            std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
            if (usernameStr == user.username) {
                finalStroke = user.username + ":" + user.favourite;
            }
        }
        return finalStroke;
    }
    std::string login(System::String^ email, System::String^ password) {
        std::string emailStr = msclr::interop::marshal_as<std::string>(email);
        std::string passwordStr = msclr::interop::marshal_as<std::string>(password);
        std::string message = "";
        for (const Users& user : users) {
            if (user.email == emailStr && user.password == passwordStr) {
                message = user.username + ":" + user.favourite + ":" + user.history;
            }
        }
        if (message.size() == 0) {
            message = "Incorrect";
        }

        return message;
    }
    void registerUser(System::String^ username, System::String^ email, System::String^ password) {
        std::vector<std::string> arrayOfDataBefore;
        std::string encryptionKey = "XZVPOIJKLMNHYWQRSTUFGCDEAB";
        std::ifstream inputFile("logs.txt", std::ios_base::binary);
        if (!inputFile.is_open()) {
            std::cout << "Failed to open the file: logs.txt" << std::endl;
        }
        else {
            std::string line;
            while (std::getline(inputFile, line)) {
                arrayOfDataBefore.push_back(line);
            }
            inputFile.close();
        }
        std::string usernameStr = msclr::interop::marshal_as<std::string>(username);
        std::string emailStr = msclr::interop::marshal_as<std::string>(email);
        std::string passwordStr = msclr::interop::marshal_as<std::string>(password);
        std::string encryptPassword = encrypt(passwordStr, encryptionKey);
        std::string encryptEmail = encrypt(emailStr, encryptionKey);
        std::string strokeForDatabase = usernameStr + "," + emailStr + "," + passwordStr + ";";
        std::ofstream outputFile("logs.txt", std::ios::trunc);
        if (!outputFile.is_open()) {
            std::cout << "Failed to open the file: logs.txt" << std::endl;
        }
        else {
            for (int i = 0; i < arrayOfDataBefore.size(); i++) {
                outputFile << arrayOfDataBefore[i] << std::endl;
            }
            outputFile << strokeForDatabase << std::endl;
        }
        outputFile.close();
    }
    std::string sear(System::String^ inputValue, System::String^ selected) {
        inputValue = inputValue->ToLower();
        std::vector<std::string> data;
        std::string finalStroke = "";
        int count = 0;
        if(selected->Contains("type")){
        for (const Entry& entry : entries) {
            System::String^ lowercaseTitle = gcnew System::String(entry.title.c_str());
            System::String^ lowercaseType = gcnew System::String(entry.type.c_str());
            lowercaseTitle = lowercaseTitle->ToLower();    
        if (lowercaseType->Contains(" " + inputValue)  ){
                data.push_back(entry.type);
                data.push_back(entry.title);
                data.push_back(entry.rate);
                data.push_back(entry.accessibility);
                data.push_back(entry.price);
                data.push_back(entry.id);
                data.push_back(entry.pit);
                data.push_back(entry.data);
                data.push_back(entry.country);
                count++;
            }
        }
        if (count == 1) {
            return data[0] + ":" + data[1] + ":" + data[2] + ":" + data[3] + ":" + data[4] + ":" + data[5] + ":" + data[6] + ":" + data[7] + ":" + data[8];
        }
        if (count > 1) {
            std::string finalStroke = "";
            int prevI = 0;
            for (int i = 0; i < data.size(); i += 1) {              
                finalStroke += data[i] + ":";
            }
            return finalStroke;
        }
        else {
            return "Not Found";
        }
        }
        if (selected->Contains("title")) {
            System::Console::WriteLine("SEl"+selected);
            for (const Entry& entry : entries) {
                System::String^ lowercaseTitle = gcnew System::String(entry.title.c_str());
                System::String^ lowercaseType = gcnew System::String(entry.type.c_str());
                lowercaseTitle = lowercaseTitle->ToLower();           
                if (lowercaseTitle->Contains(" " + inputValue)) {
                    data.push_back(entry.type);
                    data.push_back(entry.title);
                    data.push_back(entry.rate);
                    data.push_back(entry.accessibility);
                    data.push_back(entry.price);
                    data.push_back(entry.id);
                    data.push_back(entry.pit);
                    data.push_back(entry.data);
                    data.push_back(entry.country);
                    count++;
                }
            }
            if (count == 1) {
                return data[0] + ":" + data[1] + ":" + data[2] + ":" + data[3] + ":" + data[4] + ":" + data[5] + ":" + data[6] + ":" + data[7] + ":" + data[8];
            }
            if (count > 1) {
                std::string finalStroke = "";
                int prevI = 0;
                for (int i = 0; i < data.size(); i += 1) {
                    finalStroke += data[i] + ":";
                }
                return finalStroke;
            }
            else {
                return "Not Found";
            }
        }
        if (selected->Contains("price")) {
            for (const Entry& entry : entries) {
                System::String^ lowercaseTitle = gcnew System::String(entry.title.c_str());
                System::String^ lowercaseType = gcnew System::String(entry.price.c_str());
                if (lowercaseType->Contains("" + inputValue)) {
                    data.push_back(entry.type);
                    data.push_back(entry.title);
                    data.push_back(entry.rate);
                    data.push_back(entry.accessibility);
                    data.push_back(entry.price);
                    data.push_back(entry.id);
                    data.push_back(entry.pit);
                    data.push_back(entry.data);
                    data.push_back(entry.country);
                    count++;
                }
            }
            if (count == 1) {
                return data[0] + ":" + data[1] + ":" + data[2] + ":" + data[3] + ":" + data[4] + ":" + data[5] + ":" + data[6] + ":" + data[7] + ":" + data[8];
            }
            if (count > 1) {
                std::string finalStroke = "";
                int prevI = 0;
                for (int i = 0; i < data.size(); i += 1) {
                    finalStroke += data[i] + ":";
                }
                return finalStroke;
            }
            else {
                return "Not Found";
            }
        }
        if (selected->Contains("country")) {
            for (const Entry& entry : entries) {
                System::String^ lowercaseTitle = gcnew System::String(entry.title.c_str());
                System::String^ lowercaseType = gcnew System::String(entry.country.c_str());
                lowercaseType = lowercaseType->ToLower();
                if (lowercaseType->Contains(" " + inputValue)) {
                    data.push_back(entry.type);
                    data.push_back(entry.title);
                    data.push_back(entry.rate);
                    data.push_back(entry.accessibility);
                    data.push_back(entry.price);
                    data.push_back(entry.id);
                    data.push_back(entry.pit);
                    data.push_back(entry.data);
                    data.push_back(entry.country);
                    count++;
                }
            }
            if (count == 1) {
                return data[0] + ":" + data[1] + ":" + data[2] + ":" + data[3] + ":" + data[4] + ":" + data[5] + ":" + data[6] + ":" + data[7] + ":" + data[8];
            }
            if (count > 1) {
                std::string finalStroke = "";
                int prevI = 0;
                for (int i = 0; i < data.size(); i += 1) {
                    finalStroke += data[i] + ":";
                }
                return finalStroke;
            }
            else {
                return "Not Found";
            }
        }
        if (selected->Contains("pit")) {
            for (const Entry& entry : entries) {
                System::String^ lowercaseTitle = gcnew System::String(entry.title.c_str());
                System::String^ lowercaseType = gcnew System::String(entry.pit.c_str());
                lowercaseType = lowercaseType->ToLower();
                if (lowercaseType->Contains(" " + inputValue)) {
                    data.push_back(entry.type);
                    data.push_back(entry.title);
                    data.push_back(entry.rate);
                    data.push_back(entry.accessibility);
                    data.push_back(entry.price);
                    data.push_back(entry.id);
                    data.push_back(entry.pit);
                    data.push_back(entry.data);
                    data.push_back(entry.country);
                    count++;
                }
            }
            if (count == 1) {
                return data[0] + ":" + data[1] + ":" + data[2] + ":" + data[3] + ":" + data[4] + ":" + data[5] + ":" + data[6] + ":" + data[7] + ":" + data[8];
            }
            if (count > 1) {
                std::string finalStroke = "";
                int prevI = 0;
                for (int i = 0; i < data.size(); i += 1) {
                    finalStroke += data[i] + ":";
                }
                return finalStroke;
            }
            else {
                return "Not Found";
            }
        }
        if (selected->Contains("accessibility")) {
            for (const Entry& entry : entries) {
                System::String^ lowercaseTitle = gcnew System::String(entry.title.c_str());
                System::String^ lowercaseType = gcnew System::String(entry.accessibility.c_str());
                lowercaseType = lowercaseType->ToLower();
                if (lowercaseType->Contains(" " + inputValue)) {
                    data.push_back(entry.type);
                    data.push_back(entry.title);
                    data.push_back(entry.rate);
                    data.push_back(entry.accessibility);
                    data.push_back(entry.price);
                    data.push_back(entry.id);
                    data.push_back(entry.pit);
                    data.push_back(entry.data);
                    data.push_back(entry.country);
                    count++;
                }
            }
            if (count == 1) {
                return data[0] + ":" + data[1] + ":" + data[2] + ":" + data[3] + ":" + data[4] + ":" + data[5] + ":" + data[6] + ":" + data[7] + ":" + data[8];
            }
            if (count > 1) {
                std::string finalStroke = "";
                int prevI = 0;
                for (int i = 0; i < data.size(); i += 1) {
                    finalStroke += data[i] + ":";
                }
                return finalStroke;
            }
            else {
                return "Not Found";
            }
        }
        if (selected->Contains("code")) {
            for (const Entry& entry : entries) {
                System::String^ lowercaseTitle = gcnew System::String(entry.title.c_str());
                System::String^ lowercaseType = gcnew System::String(entry.rate.c_str());
                if (lowercaseType->Contains(" " + inputValue)) {
                    data.push_back(entry.type);
                    data.push_back(entry.title);
                    data.push_back(entry.rate);
                    data.push_back(entry.accessibility);
                    data.push_back(entry.price);
                    data.push_back(entry.id);
                    data.push_back(entry.pit);
                    data.push_back(entry.data);
                    data.push_back(entry.country);
                    count++;
                }
            }
            if (count == 1) {
                return data[0] + ":" + data[1] + ":" + data[2] + ":" + data[3] + ":" + data[4] + ":" + data[5] + ":" + data[6] + ":" + data[7] + ":" + data[8];
            }
            if (count > 1) {
                std::string finalStroke = "";
                int prevI = 0;
                for (int i = 0; i < data.size(); i += 1) {
                    finalStroke += data[i] + ":";
                }
                return finalStroke;
            }
            else {
                return "Not Found";
            }
        }
    }
    std::string findElem(System::String^ inputValue ) {
        inputValue = inputValue->ToLower();
        std::vector<std::string> data;
        std::string finalStroke = "";
        int count = 0;
        for (const Entry& entry : entries) {
            System::String^ lowercaseTitle = gcnew System::String(entry.title.c_str());
            lowercaseTitle = lowercaseTitle->ToLower();
            if (lowercaseTitle->Contains(" " + inputValue)) {
                data.push_back(entry.type);
                data.push_back(entry.title);
                data.push_back(entry.rate);
                data.push_back(entry.accessibility);
                data.push_back(entry.price);
                data.push_back(entry.id);
                data.push_back(entry.pit);
                data.push_back(entry.data);
                data.push_back(entry.country);
                count++;
            }
        }
        System::Console::WriteLine("COUNT " + count);
        if (count == 1) {
            return data[0] + ":" + data[1] + ":" + data[2] + ":" + data[3] + ":" + data[4] + ":" + data[5] + ":" + data[6] + ":" + data[7] + ":" + data[8];
        }
        if (count > 1) {
            std::string finalStroke = "";
            int prevI = 0;
            for (int i = 0; i < data.size(); i += 1) {
                finalStroke += data[i] + ":";   
            }
            return finalStroke;
        }
        else {
            return "Not Found";
        }
    }
    std::string  searchImage(System::String^ inputValue) {
        inputValue = inputValue->ToLower();
        std::vector<std::string> data;
        std::string finalStroke = "";
        int count = 0;
        std::string url = "";
        for (const Entry& entry : entries) {
            System::String^ lowercaseTitle = gcnew System::String(entry.title.c_str());
            lowercaseTitle = lowercaseTitle->ToLower();
            if (lowercaseTitle->Contains(inputValue)) {
                url = entry.url;
            }
        }
        return url;
    }
    std::string findGridElem(System::String^ inputValue) {
        inputValue = inputValue->ToLower();
        std::vector<std::string> data;
        std::string finalStroke = "";
        int count = 0;
        for (const Entry& entry : entries) {
            System::String^ lowercaseTitle = gcnew System::String(entry.title.c_str());
            lowercaseTitle = lowercaseTitle->ToLower();
            if (lowercaseTitle->Contains(inputValue)) {
                data.push_back(entry.type);
                data.push_back(entry.title);
                data.push_back(entry.rate);
                data.push_back(entry.accessibility);
                data.push_back(entry.price);
                data.push_back(entry.id);
                data.push_back(entry.pit);
                data.push_back(entry.data);
                data.push_back(entry.country);
            }
        }
        return data[0] + ":" + data[1] + ":" + data[2] + ":" + data[3] + ":" + data[4] + ":" + data[5] + ":" + data[6] + ":" + data[7] + ":" + data[8];
    }
    void typeTitle(std::vector<Entry>& entries, System::String^ inputValue) {
        std::vector<Entry> availableEntries;
        System::Console::WriteLine("FROM func" + inputValue);
        inputValue = inputValue->ToLower();
        for (const Entry& entry : entries) {
            System::String^ lowercaseTitle = gcnew System::String(entry.title.c_str());
            lowercaseTitle = lowercaseTitle->ToLower();
            if (lowercaseTitle->Contains(" " + inputValue)) {
                availableEntries.push_back(entry);
            }
        }
        entries.clear();
        entries = availableEntries;
        for (const Entry& entry : entries) {
            System::String^ pit = gcnew System::String(entry.pit.c_str());
            System::String^ title = gcnew System::String(entry.title.c_str());
        }
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
    void addToDatabase(System::String^ text, System::String^ text1, System::String^ text2, System::String^ selected, System::String^ selected1, System::String^ numericValue, System::String^ uniqueCode, System::String^ uniqueIdStr) {
        std::string text1Str = msclr::interop::marshal_as<std::string>(text);
        std::string text2Str = msclr::interop::marshal_as<std::string>(text1);
        std::string text3Str = msclr::interop::marshal_as<std::string>(text2);
        std::string text4Str = msclr::interop::marshal_as<std::string>(selected);
        std::string text5Str = msclr::interop::marshal_as<std::string>(selected1);
        std::string text6Str = msclr::interop::marshal_as<std::string>(numericValue);
        std::string codeStr = msclr::interop::marshal_as<std::string>(uniqueCode);
        std::string uniqueIdString = msclr::interop::marshal_as<std::string>(uniqueIdStr);
        std::string incrementedIdStr = "";
        try {
    std::string currentIdStr = entries[entries.size() - 1].id;
        int currentId = std::stoi(currentIdStr);
        currentId++;
        std::string incrementedIdStr = std::to_string(currentId);
        }
        catch(const std::exception& e) {
            incrementedIdStr = "999";
        }
        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        int year = now->tm_year + 1900;  
        int month = now->tm_mon + 1;    
        int day = now->tm_mday;         
        std::string yearStr = std::to_string(year);
        std::string monthStr = (month < 10) ? "0" + std::to_string(month) : std::to_string(month);
        std::string dayStr = (day < 10) ? "0" + std::to_string(day) : std::to_string(day);
        std::string currentDate = dayStr + "-" + monthStr + "-" + yearStr;
        std::string strokeForDatabase = " ";
        strokeForDatabase = strokeForDatabase + text4Str + ": " + text1Str + ", " + codeStr + "," + " yes" + "," + text6Str + ", " + uniqueIdString + ", " + text5Str + ", " + currentDate + ", " + text3Str + ", " + text2Str + ";";
        std::vector<std::string> arrayOfDataBefore;
        std::string filename;
        std::ifstream innputFile("route.txt");
        if (innputFile.is_open()) {
            std::string line;
            while (std::getline(innputFile, line)) {
                filename = line;
            }
        }
        innputFile.close();
        std::ifstream inputFile(filename, std::ios_base::binary);
        if (!inputFile.is_open()) {
            std::cout << "Failed to open the file: logs.txt" << std::endl;
        }
        else {
            std::string line;
            while (std::getline(inputFile, line)) {
                arrayOfDataBefore.push_back(line);
            }
            inputFile.close();
        }
        std::ofstream outputFile(filename, std::ios::trunc);
        if (!outputFile.is_open()) {
            std::cout << "Failed to open the file: logs.txt" << std::endl;
        }
        else {
            for (int i = 0; i < arrayOfDataBefore.size(); i++) {
                outputFile << arrayOfDataBefore[i] << std::endl;
            }
            outputFile << strokeForDatabase << std::endl;
        }
        outputFile.close();

    }
    void getData() {
        for (const std::string& strr : arrayOfgettedData) {
            std::istringstream iss(strr);
            std::string word;
            while (iss >> word) {
                allWords.push_back(word);
            }
        }
        std::string finalStroke = "";
        for (int i = 1; i < allWords.size(); i++) {
            finalStroke += allWords[i] + " ";
        }
    }
    void buyAllFav( System::String^ nameOfUser) {
        std::vector<Users> usersCopyFile;
    std::string  nameOfUserStr = msclr::interop::marshal_as<std::string>(nameOfUser);
        std::set<std::string> uniqueUsernames;
        std::string toRemovee = "buy ";
        for (const Users& user : users) {
            if (user.username == nameOfUserStr) {
                std::vector<std::string> arrayOfFavouriteItems;
                Users newUser = user;
                newUser.username = user.username;
                newUser.email = user.email;
                newUser.password = user.password;
                std::string str = user.favourite;
                newUser.history = user.history + user.favourite;
                newUser.favourite = "";
                usersCopyFile.push_back(newUser);
            }
            else {
                usersCopyFile.push_back(user);
            }
        }
        std::vector<std::string> strokesForDatabase;
        for (const Users& user : usersCopyFile) {
            if (uniqueUsernames.insert(user.username).second) {
                std::string strokeForDatabase = user.username + "," + user.email + "," + user.password + "," + user.favourite + "," + user.history + ";";
                strokesForDatabase.push_back(strokeForDatabase);
            }
        }
        std::ofstream outputFile("logs.txt", std::ios::trunc);
        if (!outputFile.is_open()) {
            std::cout << "Failed to open the file: logs.txt" << std::endl;
        }
        else {
            for (int i = 0; i < strokesForDatabase.size(); i++) {
                outputFile << strokesForDatabase[i] << std::endl;
            }
        }
        outputFile.close();
    }
    void buyFav(System::String^ deleteItem, System::String^ nameOfUser) {
        std::vector<Users> usersCopyFile;
        std::string buyItemStr = msclr::interop::marshal_as<std::string>(deleteItem);
        std::set<std::string> uniqueUsernames;
        std::string toRemovee = "buy ";
        std::cout << toRemovee << std::endl;
        size_t found = buyItemStr.find(toRemovee);
        if (found != std::string::npos) {
           buyItemStr.erase(found, toRemovee.length());
        }
        std::string nameOfUserStr = msclr::interop::marshal_as<std::string>(nameOfUser);
        for (const Users& user : users) {
            if (user.username == nameOfUserStr) {
                std::vector<std::string> arrayOfFavouriteItems;
                Users newUser = user;
                newUser.username = user.username;
                newUser.email = user.email;
                newUser.password = user.password;
                std::string str = user.favourite;
                std::string toRemove = "-" + buyItemStr;
                size_t found = str.find(toRemove);
                if (found != std::string::npos) {
                    str.erase(found, toRemove.length());
                }
                newUser.favourite = str;
                newUser.history =user.history+ "-" + buyItemStr;
                usersCopyFile.push_back(newUser);
            }
            else {
                usersCopyFile.push_back(user);
            }
        }
        std::vector<std::string> strokesForDatabase;
        for (const Users& user : usersCopyFile) {
            if (uniqueUsernames.insert(user.username).second) {
                std::string strokeForDatabase = user.username + "," + user.email + "," + user.password + "," + user.favourite + "," + user.history + ";";
                strokesForDatabase.push_back(strokeForDatabase);
            }
        }
        std::ofstream outputFile("logs.txt", std::ios::trunc);
        if (!outputFile.is_open()) {
            std::cout << "Failed to open the file: logs.txt" << std::endl;
        }
        else {
            for (int i = 0; i < strokesForDatabase.size(); i++) {
                outputFile << strokesForDatabase[i] << std::endl;
            }
        }
        outputFile.close();
    }
    void deleteItemFromFav(System::String^ deleteItem, System::String^ nameOfUser) {
        std::vector<Users> usersCopyFile;
        std::string deleteItemStr = msclr::interop::marshal_as<std::string>(deleteItem);
        std::set<std::string> uniqueUsernames;
        std::string toRemovee = "delete ";
        size_t found = deleteItemStr.find(toRemovee);
        if (found != std::string::npos) {
            deleteItemStr.erase(found, toRemovee.length());
        }
        std::string nameOfUserStr = msclr::interop::marshal_as<std::string>(nameOfUser);
        for (const Users& user : users) {
            if (user.username == nameOfUserStr) {
                std::vector<std::string> arrayOfFavouriteItems;
                Users newUser = user;
                newUser.username = user.username;
                newUser.email = user.email;
                newUser.password = user.password;
                newUser.history = user.history;
                std::string str = user.favourite;
                std::string toRemove = "-" + deleteItemStr;
                size_t found = str.find(toRemove);
                if (found != std::string::npos) {
                    str.erase(found, toRemove.length());
                }
                newUser.favourite = str;
                usersCopyFile.push_back(newUser);
            }
            else {
                usersCopyFile.push_back(user);
            }
        }
        std::vector<std::string> strokesForDatabase;
        for (const Users& user : usersCopyFile) {
            if (uniqueUsernames.insert(user.username).second) {
                std::string strokeForDatabase = user.username + "," + user.email + "," + user.password + "," + user.favourite + "," + user.history + ";";
                strokesForDatabase.push_back(strokeForDatabase);
            }
        }
        std::ofstream outputFile("logs.txt", std::ios::trunc);
        if (!outputFile.is_open()) {
            std::cout << "Failed to open the file: logs.txt" << std::endl;
        }
        else {
            for (int i = 0; i < strokesForDatabase.size(); i++) {
                outputFile << strokesForDatabase[i] << std::endl;
            }
        }
        outputFile.close();
    }
    void clearConsts() {
        std::ofstream outputFile("consts.txt", std::ios::trunc);
        if (!outputFile.is_open()) {
            std::cout << "Failed to open the file: consts.txt" << std::endl;
        }
        else {
            outputFile.close();
        }
    }
    void storeConsts(System::String^ item1, System::String^ item2, System::String^ item3 ) {
        System::Console::WriteLine("Consts:" + item1 + ":" + item2 + ":" + item3);
        std::ofstream outputFile("consts.txt", std::ios::trunc);
        if (!outputFile.is_open()) {
            std::cout << "Failed to open the file: logs.txt" << std::endl;
        }
        else {
            std::string item1Str = msclr::interop::marshal_as<std::string>(item1);
            outputFile <<item1Str << std::endl;
        }
        outputFile.close();
    }
   std::string getConsts() {
        std::ifstream inputFile("consts.txt");
        if (!inputFile.is_open()) {
            std::cout << "Failed to open the file: " << filename << std::endl;
        }
        else {
            std::string line;
            while (std::getline(inputFile, line)) {
                return line;
            }
            inputFile.close();
        }
    }
   void removeFromDatabase(System::String^ item) {
       std::vector<std::string> arrayOfStrokes;
       std::string item1Str = msclr::interop::marshal_as<std::string>(item);
       std::string filename;
       std::ifstream inputFile("route.txt");
       if (inputFile.is_open()) {
           std::string line;
           while (std::getline(inputFile, line)) {
               filename = line;
           }
       }
       inputFile.close();
       std::ofstream outputFile(filename, std::ios::trunc);
       if (!outputFile.is_open()) {
           std::cout << "Failed to open the file: logs.txt" << std::endl;
       }
       else {
       for (int i = 0; i < entries.size(); i++) {
           std::string strokeForDatabase = "";
           if (entries[i].id == item1Str) {
               continue;
           }
           else {
               strokeForDatabase = strokeForDatabase +entries[i].type + ":" + entries[i].title + "," + entries[i].rate + "," + entries[i].accessibility + "," + entries[i].price + "," + entries[i].id + "," + entries[i].pit + "," + entries[i].data + "," + entries[i].url  + "," +entries[i].country + ";";
               arrayOfStrokes.push_back(strokeForDatabase);
               outputFile << strokeForDatabase << std::endl;
           }
       }
       outputFile.close();
       }
   }

   std::string findToEdit(System::String^ value) {
       for (int i = 0; i < entries.size(); i++) {
           System::String^ lowercaseTitle = gcnew System::String(entries[i].id.c_str());
           lowercaseTitle = lowercaseTitle->ToLower();
           System::String^ lowercaseValue = value->ToLower();
           if (lowercaseTitle->Contains(lowercaseValue)) {
               std::string found = "" + entries[i].type + ":" + entries[i].title + ":" + entries[i].rate + ":" + entries[i].accessibility + ": " + entries[i].price + ":" + entries[i].id + ":" + entries[i].pit + ":" + entries[i].data + ":" + entries[i].url + ":" + entries[i].country;
               return found;
           }
       }
       return "Not found";
   }
   void changeElement(System::String^ selectedId, System::String^ type, System::String^ title, System::String^ accessibility, System::String^ feeding, System::String^ url, System::String^ country, System::String^ numericValue) {
       std::string idStr = msclr::interop::marshal_as<std::string>(selectedId);
       std::string typeStr = msclr::interop::marshal_as<std::string>(type);
       std::string titleStr = msclr::interop::marshal_as<std::string>(title);
       std::string accessibilityStr = msclr::interop::marshal_as<std::string>(accessibility);
       std::string feedingStr = msclr::interop::marshal_as<std::string>(feeding);
       std::string urlStr = msclr::interop::marshal_as<std::string>(url);
       std::string countryStr = msclr::interop::marshal_as<std::string>(country);
       std::string numericValueStr = msclr::interop::marshal_as<std::string>(numericValue);
       std::string found = "";
       std::set<std::string> uniqueUsernames;
       std::vector<std::string> data;
       for (int i = 0; i < entries.size(); i++) {
           System::String^ lowercaseTitle = gcnew System::String(entries[i].id.c_str());
           lowercaseTitle = lowercaseTitle->ToLower();
           System::String^ lowercaseValue = selectedId->ToLower();
           if (lowercaseTitle->Contains(lowercaseValue)) {
               found = "" + typeStr + ": " + titleStr + "," + entries[i].rate + ", " + accessibilityStr + ", " + numericValueStr + ", " + idStr + ", " + feedingStr + "," + entries[i].data + ", " + urlStr + ", " + countryStr + ";";
               data.push_back(found);
           }
           else {
               std::string strokeForDatabase = "";
               strokeForDatabase = strokeForDatabase + entries[i].type + ":" + entries[i].title + "," + entries[i].rate + "," + entries[i].accessibility + "," + entries[i].price + "," + entries[i].id + "," + entries[i].pit + "," + entries[i].data + "," + entries[i].url + "," + entries[i].country + ";";
               data.push_back(strokeForDatabase);
           }
       }
       std::ofstream outputFile("input.txt", std::ios::trunc);
       if (!outputFile.is_open()) {
                  std::cout << "Failed to open the file: logs.txt" << std::endl;
              }
       else {
           for (int i = 0; i < data.size(); i++) {
               outputFile << data[i] << std::endl;
           }
       }
       outputFile.close();
   }
   std::string gettingRoute() {
       std::ifstream inputFile("route.txt");
       std::string route;
       if (inputFile.is_open()) {
           std::string line;
           while (std::getline(inputFile, line)) {
               route = line;
           }
           inputFile.close();
           return route;
       }
   }
   std::string searchByPrice(System::String^ inputValue, System::String^ price1, System::String^ price2) {
       int count = 0;
       std::vector<std::string> data;
       for (const Entry& entry : entries) {
           System::String^ lowercaseTitle = gcnew System::String(entry.price.c_str());
           int loww = System::Convert::ToInt32(lowercaseTitle);
           int intPrice1 = System::Convert::ToInt32(price1);
           int intPrice2 = System::Convert::ToInt32(price2);
           if(loww>intPrice1 && loww<intPrice2){
               data.push_back(entry.type);
               data.push_back(entry.title);
               data.push_back(entry.rate);
               data.push_back(entry.accessibility);
               data.push_back(entry.price);
               data.push_back(entry.id);
               data.push_back(entry.pit);
               data.push_back(entry.data);
               data.push_back(entry.country);
               count++;
           }
       }
       if (count == 1) {
           return data[0] + ":" + data[1] + ":" + data[2] + ":" + data[3] + ":" + data[4] + ":" + data[5] + ":" + data[6] + ":" + data[7] + ":" + data[8];
       }
       if (count > 1) {
           std::string finalStroke = "";
           int prevI = 0;
           for (int i = 0; i < data.size(); i += 1) {
               finalStroke += data[i] + ":";
           }
           return finalStroke;
       }
       else {
           return "Not Found";
       }
   }
   bool readdFile();
    bool readFile();
    int searchIndexOfElement(System::String^ method);

};
