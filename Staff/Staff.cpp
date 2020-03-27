#include"Staff.h"



void Init(string FileName, Staff*&AllStaff, int&Size_Staff){
	ifstream fin;
	fin.open(FileName);
	bool isOpen = fin.is_open();
	if (isOpen == false)
		cout << "The file couldn't be opened.\n";
	
	else {

		int currentString = 0,index=0,countString=0;
		string data;
		
		while (getline(fin,data)) {
			countString++;			
		}
		if (countString > 0) {
			fin.close();
			fin.open(FileName);
			Size_Staff = countString / 4;
			Staff* res = new Staff[Size_Staff];
			while (getline(fin,data)) {
				++currentString;
				if (currentString == 1)
					res[index].FirstName = data;
				else if (currentString == 2)
					res[index].SecondName = data;
				else if (currentString == 3)
					res[index].Age = stoi(data);
				else {
					res[index].Position = data;
					currentString = 0;
					++index;
				}
			}
			cout << "The list of staff has been successfully downloaded from the " << FileName << endl;
			SLEEP
			delete[]AllStaff;
			AllStaff = res;
		}
		else {
			CLEAR
			cout << "File is empty.\n";
			SLEEP
		}
	}
	fin.close();
	
	
}

Staff FillNewEmployee(){
	Staff NewStaff;
		cout << "Enter first name->_";
		cin >> NewStaff.FirstName;
		CLEAR
		cout << "Enter second name->_";
		cin >> NewStaff.SecondName;
		do {

			CLEAR
			cout << "Enter age->_";
			cin >> NewStaff.Age;

			if (NewStaff.Age < 0) {
				INVALID_VALUE
			}

		} while (NewStaff.Age < 0);
			CLEAR		
			cout << "Enter position->_";
			cin.ignore(1313131, '\n');
			getline(cin, NewStaff.Position);
			return NewStaff;
}

void AddNewEmployee(Staff NewStaff, Staff*&AllStaff, int&Size_Staff){
	Staff* res= new Staff[++Size_Staff];
	for (int i = 0; i < Size_Staff - 1; i++) {
		res[i].Age = AllStaff[i].Age;
		res[i].FirstName = AllStaff[i].FirstName;
		res[i].SecondName = AllStaff[i].SecondName;
		res[i].Position = AllStaff[i].Position;
	}
	res[Size_Staff - 1].Age = NewStaff.Age;
	res[Size_Staff - 1].FirstName = NewStaff.FirstName;
	res[Size_Staff - 1].SecondName= NewStaff.SecondName;
	res[Size_Staff - 1].Position = NewStaff.Position;
	delete[]AllStaff;
	AllStaff = res;
	
}

void DeleteEmployee(int pos, Staff*&AllStaff,int&Size_Staff){
	if (Size_Staff == 0) {
		cout << "List of staff is empty.\n";
		SLEEP
			return;
	}
	Staff* res = new Staff[--Size_Staff];
	for (int i = 0; i < Size_Staff; i++) {
		if (i < pos - 1) {
			res[i].Age = AllStaff[i].Age;
			res[i].FirstName = AllStaff[i].FirstName;
			res[i].SecondName = AllStaff[i].SecondName;
			res[i].Position = AllStaff[i].Position;
		}
		else {
			res[i].Age = AllStaff[i+1].Age;
			res[i].FirstName = AllStaff[i+1].FirstName;
			res[i].SecondName = AllStaff[i+1].SecondName;
			res[i].Position = AllStaff[i+1].Position;
		}
	}
	delete[]AllStaff;
	AllStaff = res;
}

void SeachBySecondName(string SecondName,bool action,Staff*&AllStaff,int&Size_Staff){
	bool res = false;
	for (int i = 0; i < Size_Staff; i++) {
		if (AllStaff[i].SecondName == SecondName) {
			ShowEmployee(AllStaff[i]);
			if (action == 1)
				SaveFoundData(AllStaff[i]);
			res = true;
		}
	}
	if (res == 0) {
		cout << "No employees were found with entered second name.";
		SLEEP
	}
}
void SeahByFirstLetterInSecondName(char letter, bool action,Staff*&AllStaff,int&Size_Staff) {
	bool res = false;

	for (int i = 0; i < Size_Staff; i++) {
		if (toupper(AllStaff[i].SecondName[0]) == toupper(letter)) {
			ShowEmployee(AllStaff[i]);
			if (action == 1)
				SaveFoundData(AllStaff[i]);
			res = true;
		}
	}
	if (res == 0) {
		cout << "No employees were found whose second name begin with the letter you entered.";
		SLEEP
	}
}
void EditEmployee(Staff*&AllStaff,int&Size_Staff){
	if (Size_Staff == 0) {
		cout << "List of staff is empty.\n";
		SLEEP
			return;
	}
	int pos = -1;
	do {
		CLEAR
		cout << "Enter position->_";
		cin >> pos;
		if (pos<1 || pos>Size_Staff) {
			INVALID_VALUE
		}
	} while (pos<0 || pos>Size_Staff);
	int action;
	do {
		CLEAR
			cout << "Enter action:\n1.Edit first name\n2.Edit second name\n3.Edit age"
			"\n4.Edit position\n5.Exit\n";
		cin >> action;
		CLEAR
		switch (action) {
		case 1:
			cout << "Enter new first name->_";
			cin >> AllStaff[pos-1].FirstName;
			CLEAR
				cout << "First name has been changed successufully.\n";
			SLEEP
			break;
		case 2:
			cout << "Enter new second name->_";
			cin >> AllStaff[pos-1].SecondName;
			CLEAR
				cout << "Second name has been changed successufully.\n";
			SLEEP
			break;
		case 3:
			do {
				cout << "Enter new age->_";
				cin >> AllStaff[pos-1].Age;
				if (AllStaff[pos - 1].Age < 0) {
					INVALID_VALUE
				}
			} while (AllStaff[pos-1].Age < 0);
			CLEAR
				cout << "Age has been changed successufully.\n";
			SLEEP
			break;
		case 4:
			cout << "Enter new position->_";
			cin.ignore(122332, '\n');
			getline(cin,AllStaff[pos-1].Position);
			CLEAR
				cout << "Position has been changed successufully.\n";
			SLEEP
			break;
		case 5:
			break;
		default:
			INVALID_VALUE
		}
	} while (action != 5);
}
void SeachByAge(int age,bool action,Staff*&AllStaff,int&Size_Staff){
	bool res = false;
	for (int i = 0; i < Size_Staff; i++) {
		if (AllStaff[i].Age == age) {
			ShowEmployee(AllStaff[i]);
			if (action == 1)
				SaveFoundData(AllStaff[i]);
			res = true;
		}
	}
	if (res == 0) {
		cout << "No employees were found with entered age.";
		SLEEP
	}
}

void SaveInFileStaff(string FileName,Staff*&AllStaff,int&Size_Staff){
	ofstream fout;
	fout.open(FileName);
	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "The file couldn't be opened.\n";
		SLEEP
	}
	else {
		for (int i = 0; i < Size_Staff; i++) {
			fout << AllStaff[i].FirstName << endl << AllStaff[i].SecondName << endl;
			fout << AllStaff[i].Age << endl << AllStaff[i].Position << endl;
	}
	}
	fout.close();
}

void SaveFoundData(Staff Employee){
	ofstream fout;
	fout.open("FoundData.txt", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "The file couldn't be opened.\n";
		SLEEP
	}
	else {
		fout << Employee.FirstName << endl << Employee.SecondName << endl;
		fout << Employee.Age << endl << Employee.Position<<endl;
	}
	fout.close();
}

void ShowStaff(Staff*&AllStaff,int&Size_Staff){
	if (Size_Staff == 0) {
		cout << "List of staff is empty.\n";
		SLEEP
		return;
	}
	cout << "Staff: \n";
	for (int i = 0; i < Size_Staff; i++) {
		cout << i + 1 << ".";
		ShowEmployee(AllStaff[i]);
		Sleep(500);
	}
}

void ShowEmployee(Staff Employee){
	cout << "\tFirst name: " << Employee.FirstName << "\n\tSecond name: " << Employee.SecondName <<
		"\n\tAge: " << Employee.Age << "\n\tPosition: " << Employee.Position << "\n\n";
}
