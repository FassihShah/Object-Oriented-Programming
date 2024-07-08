#include<iostream>
#include<fstream>
using namespace std;
struct Student
{
	int rollNo;
	char name[50];
	float cgpa;
};
int findIndex(int rollNo, const char file[])
{
	ifstream ifs;
	ifs.open(file);
	Student student;
	int i = 0;
	bool find = false;
	while (!ifs.eof() && (find == false))
	{
		i = i + 1;
		ifs >> student.rollNo;
		ifs.ignore();
		ifs.getline(student.name, 50);
		ifs >> student.cgpa;
		if (student.rollNo == rollNo)
		{
			find = true;
		}
	}
	ifs.close();
	return find ? i : -1;
}
void deleteRecord(const char file[], int index)
{
	int  i = 0;
	bool find = false;
	char temp[10] = "temp.txt";
	ifstream ifs;
	ifs.open(file);
	ofstream ofs;
	ofs.open(temp);
	Student student;
	while (!ifs.eof())
	{
		i = i + 1;
		ifs >> student.rollNo;
		ifs.ignore();
		ifs.getline(student.name, 50);
		ifs >> student.cgpa;
		if ((!ifs.eof()) && (i != index))
		{
			ofs << student.rollNo << "\n" << student.name << "\n" << student.cgpa << "\n";
		}
	}
	ifs.close();
	ofs.close();
	remove(file);
	rename(temp, file);
}
void deleteRecordApp(const char file[])
{
	int index, rollNo;
	cout << "Enter rollNo of which you want to delete record : ";
	cin >> rollNo;
	if (findIndex(rollNo, file) == -1)
	{
		cout << "Record is not present...\n";
		return;
	}
	index = findIndex(rollNo, file);
	deleteRecord(file, index);
}
void updateRecord(const char file[])
{
	Student student;
	cout << "Enter rollNo of which you want to update record : ";
	cin >> student.rollNo;
	if (findIndex(student.rollNo, file) == -1)
	{
		cout << "Record is not present...\n";
		return;
	}
	cout << "Enter updated name : ";
	cin.ignore();
	cin.getline(student.name, 50);
	cout << "Enter updated cgpa : ";
	cin >> student.cgpa;
	int index = findIndex(student.rollNo, file);
	deleteRecord(file, index);
	ofstream ofs;
	ofs.open(file, ios::app);
	ofs << student.rollNo << "\n" << student.name << "\n" << student.cgpa << "\n";
	ofs.close();
}
void addRecord(const char file[])
{
	fstream fs;
	fs.open(file, ios::app);
	Student student;
	cout << "Enter rollNo : ";
	cin >> student.rollNo;
	if (findIndex(student.rollNo, file) != -1)
	{
		cout << "Record already exists...\n";
		return;
	}
	cout << "Enter name : ";
	cin.ignore();
	cin.getline(student.name, 50);
	cout << "Enter cgpa : ";
	cin >> student.cgpa;
	fs << student.rollNo << "\n" << student.name << "\n" << student.cgpa << "\n";
	fs.close();
}
void studentDatabaseApp(const char file[])
{
	int choice;
	cout << "\t\t\t\tDATABASE APP\t\t\t\t\n\n";
	do
	{
		cout << "\t\t\tEnter 1 =====< to add record \t\t\n";
		cout << "\t\t\tEnter 2 =====< to delete record\t\t\n";
		cout << "\t\t\tEnter 3 =====< to update any record\t\t\n";
		cout << "\t\t\tEnter 4 =====< to exit\t\t\n";
		cout << "\t\t\tEnter : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addRecord(file);
			break;
		case 2:
			deleteRecordApp(file);
			break;
		case 3:
			updateRecord(file);
			break;
		case 4:
			break;
		}
	} while (choice != 4);
}