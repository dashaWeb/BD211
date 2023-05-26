#include <iostream>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};
struct Name {
	string name;
	string lastName;
	string fatherName;
};
struct Student
{
	Name name;
	string phone;
	double rating;
	Date birthDate;
	int age;
	string email;
	int marks[10];
};

void printDate(Date obj)
{
	cout << (obj.day < 10 ? "0" : "") << obj.day << "." << (obj.month < 10 ? "0" : "") << obj.month << "." << obj.year;
}
Name printName(Name obj)
{
	cout << obj.name << " "  << obj.lastName << " " << obj.fatherName;
	Name tmp;
	tmp.name = obj.name + "test";
	return tmp;
}

void printStudent(Student obj)
{
	//cout << "\t===================" << obj.name.lastName
	cout << "\t=================== ";
	printName(obj.name);
	cout << " =================== \n";
	cout << "\t\tPhone      :: \t" << obj.phone << endl;
	cout << "\t\tRating     :: \t" << obj.rating << endl;
	cout << "\t\tBirthdate  :: \t"; printDate(obj.birthDate); cout << endl;
	cout << "\t\tAge        :: \t" << obj.age << endl;
	cout << "\t\tEmail      :: \t" << obj.email << endl;
	cout << "\t\tMarks      :: \t";
	for (size_t i = 0; i < 10; i++)
	{
		cout << obj.marks[i];
		if (i == 9) continue;
		cout << ", ";
	}
	cout << endl;
}

void inputStudent(Student& obj)
{
	cout << "Enter name       :: "; cin >> obj.name.name;
	cout << "Enter lastname   :: "; cin >> obj.name.lastName;
	cout << "Enter fatherName :: "; cin >> obj.name.fatherName;
	cout << "Enter Phone      :: "; cin >> obj.phone;
	cout << "Enter Rating     :: "; cin >> obj.rating;
	cout << "Enter Birthdate  :: "; cin >> obj.birthDate.day >> obj.birthDate.month >> obj.birthDate.year;
	cout << "Enter Age        :: "; cin >> obj.age;
	cout << "Enter Email      :: "; cin >> obj.email;
	cout << "Enter Marks      :: ";
	for (size_t i = 0; i < 10; i++)
	{
		cin >> obj.marks[i];
	}
}

int main()
{
	Date date{ 23,6,2000 };
	printDate(date);
	cout << endl;

	Date today{ 12,05,2023 };
	printDate(today);
	cout << endl;

	//Name studName{ "Ivan", "Bondar", "Ivanovich" };
	
	Student ivan{ { "Ivan", "Bondar", "Ivanovich" },"33-333-3333",10.7,{12,12,1996},17,"blabla.gmail.com", {1,2,5,8,6,5,8} };
	printStudent(ivan);
	Student roman;
	inputStudent(roman);
	printStudent(roman);
}
