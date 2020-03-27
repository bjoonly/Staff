#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include<fstream>
using namespace std;
#define CLEAR system("cls");
#define SLEEP Sleep(1500);
#define INVALID_VALUE system("cls"); cout<<"Invalid value.\n"; Sleep(1500); 


struct Staff {
	string FirstName;
	string SecondName;
	int Age;
	string Position;
};



void Init(string FileName, Staff*& AllStaff, int& Size_Staff);
Staff FillNewEmployee();
void SaveFoundData(Staff Employee);
void AddNewEmployee(Staff NewStaff, Staff*& AllStaff, int& Size_Staff);
void DeleteEmployee(int pos, Staff*& AllStaff, int& Size_Staff);
void SeachBySecondName(string SecondName, bool action, Staff*& AllStaff, int& Size_Staff);
void SeachByAge(int age, bool action, Staff*& AllStaff, int& Size_Staff);
void SaveInFileStaff(string FileName, Staff*& AllStaff, int& Size_Staff);
void ShowStaff(Staff*& AllStaff, int& Size_Staff);
void ShowEmployee(Staff Employee);
void SeahByFirstLetterInSecondName(char letter, bool action, Staff*& AllStaff, int& Size_Staff);
void EditEmployee(Staff*& AllStaff, int& Size_Staff);
