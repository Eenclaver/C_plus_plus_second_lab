#pragma once
#include <string>
#include<vector>
#include <conio.h>
#include <fstream>
#include<iostream>
#include <io.h>

class Document {
public:
	std::string name;
	int size=0;
};

class Letter:public Document {
public:
	std::string getTitle();
	void setTitle(std::string inputData);
private:
	std::string title;
};


class UserVector {
public:
	void vectorClear() {
		std::vector<Letter>* vectorPointer = getPointer();
		vectorPointer->clear();
	}
	std::vector<Letter>* getPointer(){
		std::vector<Letter>* vectorPointer = &dataVector;
		return vectorPointer;
	}
	void setElement(Letter element) {
		std::vector<Letter>* vectorPointer = getPointer();
		vectorPointer->push_back(element);
	}
	Letter getElement(int num) {
		return dataVector[num];
	}
private:
	std::vector<Letter> dataVector;
};

namespace Input {
	int user_Int_Input();
	void user_Console_Input(UserVector* vectorPointer);
	int user_File_Input(UserVector* vectorPointer);
};

namespace Checks {
	bool is_Number_Check(std::string inputData);
	int user_Is_Number_Check(std::string inputData);
	bool File_Exists(std::string fileName);
	bool Only_Read(std::string fileName);
};

namespace Output {
	void vectorOutput(UserVector* vectorPointer);
	void module_Tests();
	void save_User_Data_To_File(UserVector* vectorPointer);
}

enum console_Or_File { console = 1, file };

enum letter_Or_Document { letter = 1, document };

enum yes_Or_No {yes=1,no};

enum firstUserMenu {listOutput=1,newData,moduleTests, exitMenu};

enum { eror =0, allGood};