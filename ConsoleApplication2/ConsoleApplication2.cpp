#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using std::string;
using std::fstream;
using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::numeric_limits;
using std::streamsize;

 class student {

public:
	
	void getData();
	void showData();
	void menu();
	void changeData();
	void searchData();
	void deleteRecord();
private:
	int id;
	string name;
	int age;
	int math;
	int physics;
	int english;
};

 template <class T> void getnum(T& choice)
 {
	 bool inputFail = false;
	 do {
		 cin >> choice;
		 inputFail = cin.fail();
		 if (inputFail)
		 {
			 cout << "Wrong number!" << endl;
			 cout << "Please, try again" << endl;
		 }
		 cin.clear();
		 cin.ignore(numeric_limits<streamsize>::max(), '\n');
	 } while (inputFail);
 }

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
	getnum(select);

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
	cout << "Enter id: ";
	getnum(id);
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter age: ";
	getnum(age);
	cout << "Enter math mark: ";
	getnum(math);
	cout << "Enter physics mark: ";
	getnum(physics);
	cout << "Enter english mark: ";
	getnum(english);
	file.open("students.txt", ios::app | ios::out);
	file << id << " " << name << " " << age << " " << math << " " << physics << " " << english << "\n";
	file.close();

}
void student::showData() {
	fstream file;
	cout << "===========================================" << endl;
	cout << "               " << "Student records:" << endl;
	cout << "===========================================" << endl;
	file.open("students.txt", ios::in);
	file >> id >> name >> age >> math >> physics >> english;
	while (!file.eof())
	{
		cout << "\nId: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Math mark: " << math << endl;
		cout << "Physics mark: " << physics << endl;
		cout << "English mark: " << english << endl;
		file >> id >> name >> age >> math >> physics >> english;
	}
	file.close();
}
void student::changeData() {
	fstream file, file1;
	int found = 0;
	int idC;
	cout << "===========================================" << endl;
	cout << "               " << "Change records:" << endl;
	cout << "===========================================" << endl;
	file.open("students.txt", ios::in);
	cout << "Enter student id: ";
	getnum(idC);
	file1.open("studentsRecord.txt", ios::app | ios::out);
	file >> id >> name >> age >> math >> physics >> english;
	while (!file.eof())
	{
		if (idC!=id)
		{
			file1 << id << " " << name << " " << age << " " << math << " " << physics << " " << english << "\n";
		}
		else
		{
			found++;
			cout << "Enter id: ";
			getnum(id);
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter age: ";
			getnum(age);
			cout << "Enter math mark: ";
			getnum(math);
			cout << "Enter physics mark: ";
			getnum(physics);
			cout << "Enter english mark: ";
			getnum(english);
			file1 <<  id << " " << name << " " << age << " " << math << " " << physics << " " << english << "\n";
			
		}
		file >> id >> name >> age >> math >> physics >> english;
		
	}
	if (found == 0)
	{
		cout << "Student not found. " << endl;
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
	int idF;
	cout << "Enter student id: " << endl;
	getnum(idF);
	file >> id >> name >> age >> math >> physics >> english;
	while (!file.eof())
	{


		if (idF == id)
		{
			cout << "Id: " << id << endl;
			cout << "Name: " << name << endl;
			cout << "Age: " << age << endl;
			cout << "Math mark: " << math << endl;
			cout << "Physics mark: " << physics << endl;
			cout << "English mark: " << english << endl;
			found++;
		}
		file >> id >> name >> age >> math >> physics >> english;
		
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
	int idF;
	cout << "Enter student id: " << endl;
	getnum(idF);
	file1.open("studentsRecord.txt", ios::app | ios::out);
	file >> id >> name >> age >> math >> physics >> english;
	while (!file.eof())
	{


		if (idF != id)
		{
			file1 << id << " " << name << " " << age << " " << math << " " << physics << " " << english << "\n";
			found++;
		}
		file >> id >> name >> age >> math >> physics >> english;
		
		
	}
	if (found == 0)
	{
		cout << "No student with such name found or student data file is empty." << endl;
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

