#include"Staff.h"

int main() {
	Staff* AllStaff = nullptr;
	int Size_Staff = 0;
	string FileName,secondname;
	char letter;
	int action = 0,pos,age, Save_action = 0;
	cout << "Enter file name->_";
	cin >> FileName;
	CLEAR
	Init(FileName,AllStaff,Size_Staff);
	do {
		CLEAR
			cout << "Enter action:\n1.Add new employee\n2.Edit employee"
			"\n3.Delete employee \n4.Show all staff\n5.Seach by second name"
			"\n6.Seach by age\n7.Seach by first letter in second name"
			"\n8.Save staff\n9.Exit\n";
		cin >> action;
		CLEAR
		switch (action) {
		case 1:
			AddNewEmployee(FillNewEmployee(),AllStaff,Size_Staff);
			CLEAR
			cout << "Employee successufully added.\n";
			SLEEP
			break;
		case 2:
			CLEAR			
				EditEmployee(AllStaff,Size_Staff);
			break;
		case 3:
			do {
				CLEAR
					cout << "Enter position->_";
				cin >> pos;
				if (pos<1 || pos>Size_Staff) {
					INVALID_VALUE
				}
			} while (pos<1 || pos>Size_Staff);
				DeleteEmployee(pos,AllStaff,Size_Staff);
				CLEAR
				cout << "Employee has been successufully deleted.";
				SLEEP
			break;
		case 4:
			ShowStaff(AllStaff,Size_Staff);
			cout << "\nPress space to continue.\n";
			while (_getch() != 32);
			break;
		case 5:
			cout << "Enter second name->_";
			cin >> secondname;
			do {
				CLEAR
					cout << "Save found data(1-yes/2-no)?";
				cin >> Save_action;
				if (Save_action != 1 && Save_action != 2) {
					INVALID_VALUE
				}
			} while (Save_action != 1 && Save_action != 2);
			CLEAR
			SeachBySecondName(secondname,Save_action,AllStaff,Size_Staff);
			cout << "\nPress space to continue.\n";
			while (_getch() != 32);
			break;
		case 6:
			do {
				CLEAR
				cout << "Enter age->_";
				cin >> age;
				if (age < 0) {
					INVALID_VALUE
				}
			} while (age < 0);
			do {
				CLEAR
					cout << "Save found data(1-yes/2-no)?";
				cin >> Save_action;
				if (Save_action != 1 && Save_action != 2) {
					INVALID_VALUE
				}
			} while (Save_action != 1 && Save_action != 2);
			CLEAR
				SeachByAge(age, Save_action,AllStaff,Size_Staff);
				cout << "\nPress space to continue.\n";
				while (_getch() != 32);
			break;
		case 7:
			cout << "Enter first letter in second name->_";
			cin >> letter;
			do {
				CLEAR
					cout << "Save found data(1-yes/2-no)?";
				cin >> Save_action;
				if (Save_action != 1 && Save_action != 2) {
					INVALID_VALUE
				}
			} while (Save_action != 1 && Save_action != 2);
			CLEAR
				SeahByFirstLetterInSecondName(letter, Save_action,AllStaff,Size_Staff);
				cout << "\nPress space to continue.\n";
				while (_getch() != 32);
			break;
		case 8:
			SaveInFileStaff(FileName,AllStaff,Size_Staff);
			cout << "The list of staff has been successfully saved.";
			SLEEP
			break;
		case 9:
			SaveInFileStaff(FileName,AllStaff,Size_Staff);
			cout << "The list of staff has been successfully saved.";
			SLEEP
			break;
		default:
			INVALID_VALUE
		}
	} while (action!=9);
	delete[]AllStaff;
	return 0;
}