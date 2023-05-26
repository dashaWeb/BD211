#include <iostream>
#include <string>
using namespace std;
//Створіть динамічний масив, що зберігає
//в першому рядку ім'я, а в другому — телефон. Організуйте пошук за ім'ям і номером телефону та можливість
//введення і зміни даних.

void print(string** arr, const int& row, const int& col) {
	for (size_t i = 0; i < col; i++)
	{
		cout << "\t" << arr[0][i] << (arr[0][i].size() >= 8 ? "" : "\t") << " :: \t" << arr[1][i] << endl;
	}
}

int findName(string** arr, const int& col, string value)
{
	for (size_t i = 0; i < col; i++)
	{
		if (arr[0][i] == value) {
			return i;
		}
	}
	return -1;
}
void editContact(string** arr, const int& col, int index)
{
	cout << "Enter name :: ";
	getline(cin, arr[0][index]);
	cout << "Enter phone :: ";
	getline(cin, arr[1][index]);
}
void deleteContact(string** arr, const int& row, int& col, int index)
{
	col--;
	for (size_t i = 0; i < row; i++)
	{
		string* tmp = new string[col];

		for (size_t j = 0; j < col; j++)
		{
			if (j < index)
			{
				tmp[j] = arr[i][j];
			}
			else {
				tmp[j] = arr[i][j + 1];
			}
		}
		delete[] arr[i];
		arr[i] = tmp;
	}
}
void sortByName(string** arr, const int& col)
{
	for (size_t i = 0; i < col - 1; i++)
	{
		for (size_t j = 0; j < col - 1 - i; j++)
		{
			if (arr[0][j] > arr[0][j + 1]) {
				// міняємо місцями імена
				string tmp = arr[0][j];
				arr[0][j] = arr[0][j + 1];
				arr[0][j + 1] = tmp;
				// міняємо місцями номера
				tmp = arr[1][j];
				arr[1][j] = arr[1][j + 1];
				arr[1][j + 1] = tmp;
			}
		}
	}
}
int main()
{

	int row = 2, col = 10;
	string** contact = new string * [row];
	contact[0] = new string[col]{
		"Leonore",
		"Pietra",
		"Lion",
		"Byrle",
		"Edin",
		"Pepito",
		"Vicky",
		"Chloris",
		"Cordelia",
		"Ozzie"
	};
	contact[1] = new string[col]{
		"766-142-9881",
		"636-989-9197",
		"407-849-3393",
		"593-718-9446",
		"504-658-1449",
		"175-905-7084",
		"259-543-8837",
		"764-833-7440",
		"550-348-3976",
		"463-892-0603"
	};
	print(contact, row, col);
	string value;
	cout << "Enter name :: ";
	getline(cin, value);
	int index = findName(contact, col, value);
	if (index != -1) {
		cout << index << endl;
		editContact(contact, col, index);
		cout << endl << endl;
		print(contact, row, col);
		deleteContact(contact, row, col, index);
		cout << endl << endl;
		print(contact, row, col);

		sortByName(contact, col);
		cout << endl << endl;
		print(contact, row, col);
	}
}
