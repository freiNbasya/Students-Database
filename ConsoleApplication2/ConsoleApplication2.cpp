#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

 class student {

public:
	
	void getData();
	void showData();
	void menu();
	void changeData();
	void searchData();
	void deleteRecord();
private:
	string name;
	int age;
	int math;
	int physics;
	int english;
};

void student::menu() {
	
	string ch;
	int select;
	cout << "===========================================" << endl;
	cout << "               "  << "Menu:" << endl;
	cout << "===========================================" << endl;
	cout << "          " << "1. New record" << endl;
	cout << "          " << "2. Show records" << endl;
	cout << "          " << "3. Change record" << endl;
	cout << "          " << "4. Find record" << endl;
	cout << "          " << "5. Delete record" << endl;
	cout << "          " << "6. Exit" << endl;
	cin >> select;

	switch (select)
	{
	case 1:
		do
		{
			getData();
			cout << "          " << "Add another record? (Y/N)" << endl;
			cin >> ch;
		} while (ch == "Y");
		
		break;
	case 2:
		showData();
		break;
	case 3:
		changeData();
		break;
	case 4:
		searchData();
		break;
	case 5:
		deleteRecord();
		break;
	default:
		break;
	}
	cout << "Go back to main menu?" << endl;
	string repeat;
	cin >> repeat;
	if (repeat == "Y") {
		menu();
	}


}

void student::getData() {
	fstream file;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter age: ";
	cin >> age;
	cout << "Enter math mark: ";
	cin >> math;
	cout << "Enter physics mark: ";
	cin >> physics;
	cout << "Enter english mark: ";
	cin >> english;
	file.open("students.txt", ios::app | ios::out);
	file << " " << name << " " << age << " " << math << " " << physics << " " << english << "\n";
	file.close();

}
void student::showData() {
	fstream file;
	int id=1;
	cout << "===========================================" << endl;
	cout << "               " << "Student records:" << endl;
	cout << "===========================================" << endl;
	file.open("students.txt", ios::in);
	file >> name >> age >> math >> physics >> english;
	while (!file.eof())
	{
		cout << "\n\nId: " << id++ << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Math mark: " << math << endl;
		cout << "Physics mark: " << physics << endl;
		cout << "English mark: " << english << endl;
		file >> name >> age >> math >> physics >> english;
	}
	file.close();
}
void student::changeData() {
	fstream file, file1;
	int found = 0;
	string nameC;
	cout << "===========================================" << endl;
	cout << "               " << "Change records:" << endl;
	cout << "===========================================" << endl;
	file.open("students.txt", ios::in);
	cout << "Enter name of student: ";
	cin >> nameC;
	file1.open("studentsRecord.txt", ios::app | ios::out);
	file >> name >> age >> math >> physics >> english;
	while (!file.eof())
	{
		if (nameC!=name)
		{
			file1 << " " << name << " " << age << " " << math << " " << physics << " " << english << "\n";
		}
		else
		{
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter age: ";
			cin >> age;
			cout << "Enter math mark: ";
			cin >> math;
			cout << "Enter physics mark: ";
			cin >> physics;
			cout << "Enter english mark: ";
			cin >> english;
			file1 << " " << name << " " << age << " " << math << " " << physics << " " << english << "\n";
			found++;
		}
		file >> name >> age >> math >> physics >> english;
		if (found == 0)
		{
			cout << "Student not found. " << endl;
		}
	}
	file1.close();
	file.close();
	remove("students.txt");
	rename("studentsRecord.txt", "students.txt");

}
void student::searchData() {
	fstream file;
	int found = 0;
	file.open("students.txt", ios::in);
	cout << "===========================================" << endl;
	cout << "               " << "Find records:" << endl;
	cout << "===========================================" << endl;
	string nameF;
	cout << "Enter student name: " << endl;
	cin >> nameF;
	file >> name >> age >> math >> physics >> english;
	while (!file.eof())
	{


		if (nameF == name)
		{
			cout << "\n\nName: " << name << endl;
			cout << "Age: " << age << endl;
			cout << "Math mark: " << math << endl;
			cout << "Physics mark: " << physics << endl;
			cout << "English mark: " << english << endl;
			found++;
		}
		file >> name >> age >> math >> physics >> english;
		
	}
	if (found == 0)
	{
		cout << "No student with such name found." << endl;
	}
	file.close();
}

void student::deleteRecord() {
	fstream file;
	fstream file1;
	int found = 0;
	file.open("students.txt", ios::in);
	cout << "===========================================" << endl;
	cout << "               " << "Delete record:" << endl;
	cout << "===========================================" << endl;
	string nameF;
	cout << "Enter student name: " << endl;
	cin >> nameF;
	file1.open("studentsRecord.txt", ios::app | ios::out);
	file >> name >> age >> math >> physics >> english;
	while (!file.eof())
	{


		if (nameF != name)
		{
			file1 << " " << name << " " << age << " " << math << " " << physics << " " << english << "\n";
			found++;
		}
		file >> name >> age >> math >> physics >> english;
		
		
	}
	if (found == 0)
	{
		cout << "No student with such name found." << endl;
	}
	file.close();
	file1.close();
	remove("students.txt");
	rename("studentsRecord.txt", "students.txt");
}

int main()
{
	student project;
	project.menu();
}

