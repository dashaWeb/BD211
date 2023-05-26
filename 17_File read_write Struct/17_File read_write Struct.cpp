#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int LEN = 50;

struct Book {
	char name[LEN] = "";
	char author[LEN] = "";
	char publisher[LEN] = "";
	char genre[LEN] = "";
};
//■ Заповнення бд, доповнення;
//■ Редагувати книгу;
void edit(Book& obj)
{
	if (strlen(obj.name) == 0) {
		cout << "\n\t===================== New book =======================" << endl;
	}
	else {
		cout << "\n\t===================== Edit book --> " << obj.name << " =======================" << endl;
	}
	cout << "\t\t Enter Name      :: "; cin.getline(obj.name, LEN);
	cout << "\t\t Enter Author    :: "; cin.getline(obj.author, LEN);
	cout << "\t\t Enter Publisher :: "; cin.getline(obj.publisher, LEN);
	cout << "\t\t Enter Genre     :: "; cin.getline(obj.genre, LEN);
}
//■ Пошук книг за автором;
//■ Пошук книги за назвою;
int findByAuthor(Book* library, const int& size, string author, int index = 0)
{
	for (size_t i = index; i < size; i++)
	{
		if (library[i].author == author) {
			return i;
		}
	}
	return -1;
}
//■ Сортування масиву за назвою книг;
//■ Сортування масиву за автором;
//■ Сортування масиву за видавництвом.
//■ Видалення книги за певним критерієм.


//■ Додавання нової книги

//■ Друк усіх книг;
void print(Book obj, int index = 0) {

	string text = to_string(index) + ".) ";
	cout << "\n\t===================== " << (index == 0 ? "" : text) << obj.name << " =======================" << endl;
	cout << "\t\t Author    :: " << obj.author << endl;
	cout << "\t\t Publisher :: " << obj.publisher << endl;
	cout << "\t\t Genre     :: " << obj.genre << endl;
}
void printAll(Book* library, const int& size, bool flag = false) {
	for (size_t i = 0; i < size; i++)
	{
		if (!flag)
		{
			print(library[i]);
			continue;
		}
		print(library[i], i + 1);
	}
}

Book* readBook(string fname, int& size)
{
	fstream file(fname, ios_base::in);
	if (!file.is_open()) {
		return nullptr;
	}

	file.seekg(0, ios_base::end); // розмістити файловий курсов в 0 байт відносно кінця файлу
	size = file.tellg() / sizeof(Book);
	//file.clear();
	file.seekg(0, ios_base::beg);
	Book* library = new Book[size];
	for (size_t i = 0; i < size; i++)
	{
		file.read((char*)&library[i], sizeof(Book));
	}
	return library;
}

void writeBooks(Book* library, const int& size, string fname) {
	fstream file(fname, ios_base::out);
	if (!file.is_open()) {
		cout << "Error" << endl;
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		file.write((char*)&library[i], sizeof(Book));
	}
}
void writeBook(Book book, string fname) {
	fstream file(fname, ios_base::out | ios_base::app);
	if (!file.is_open()) {
		cout << "Error" << endl;
		return;
	}

	file.write((char*)&book, sizeof(Book));

}
void deleteBook(Book*& library, int& size, int index) {
	if (index < 0 || index >= size) return;
	if (size == 1) {
		delete[] library;
		library = nullptr;
		return;
	}

	Book* tmp = new Book[--size];
	for (size_t i = 0; i < size; i++)
	{
		if (i < index) {
			tmp[i] = library[i];
		}
		else {
			tmp[i] = library[i + 1];
		}
	}
	delete[] library;
	library = tmp;
}
int main()
{
	string fname = "library.txt";
	int size;
	Book* library = readBook(fname, size);
	int choice;

	do
	{
		cout << "\n\t\t 1 - Fill DB;";
		cout << "\n\t\t 2 - Print DB;";
		cout << "\n\t\t 3 - Edit Book;";
		cout << "\n\t\t 4 - Search Book;";
		cout << "\n\t\t 5 - Delete Book;";
		cout << "\n\t\t 0 - Exit;";
		cout << "\n\t\t Enter :: ";
		cin >> choice;

		switch (choice)
		{
		case 1: {
			Book book;
			cin.ignore();
			edit(book); // add new Book;
			writeBook(book, fname);
			delete[] library;
			library = readBook(fname, size);
			break;
		}
		case 2: {
			if (library == nullptr) {
				cout << "Error!!! Library is Empty" << endl;
			}
			else {
				printAll(library, size, true);
			}
			break;
		}
		case 3: {

			break;
		}
		case 4: {
			string text;
			cout << "Enter author :: ";
			cin.ignore();
			getline(cin,text);
			int index = findByAuthor(library, size,text);
			if (index == -1) {
				cout << "Book not found" << endl;
				break;
			}
			print(library[index]);
			break;
		}
		case 5: {
			string text;
			cout << "Enter author :: ";
			cin.ignore();
			getline(cin, text);
			int index = findByAuthor(library, size, text);
			if (index == -1) {
				cout << "Book not found" << endl;
				break;
			}
			deleteBook(library, size, index);
			writeBooks(library, size, fname);
		}
		default:
			break;
		}


	} while (choice != 0);





















	/*Book book1{ "Carrie","Stephen King","Anchor","Horror" };
	Book book2{ "Harry Potter and the Goblet of Fire","J.K. Rowling","Pottermore Publishing","Fantasy" };
	Book book3{ "Salem's Lot","Stephen King","Anchor","Horror" };*/
	//int size = 7;
	//Book* library = new Book[size]{
	//	{"Night Shift","Stephen King","Anchor","Horror"},
	//	{"Harry Potter and the Sorcerer's Stone","J.K. Rowling","Pottermore Publishing","Fantasy"},
	//	{"It: A Novel","Stephen King","Scribner","Horror"},
	//	{"Identity: A Novel","Nora Roberts","St. Martin's Press","Thrillers"},
	//	{"The Wager","David Grann","Doubleday","Memoirs"},
	//	{"The Book Thief","Markus Zusak","Knopf Books for Young Readers","Fiction"},
	//	{"Harry Potter and the Order of the Phoenix","J.K. Rowling","Pottermore Publishing","Fiction"},
	//};

	//// fstream --> ofstream & ifstream
	////remove("library.txt");
	//fstream file("library.txt", ios_base::out | ios_base::app /* | ios_base::in | ios_base::app*/);
	//if (!file.is_open()) {
	//	cout << "Error" << endl;
	//	return 0;
	//}

	//// file.write(); --> для запису користувацького типу (явно перетворить нашу структуру(книгу) в масив символів і запише у файл певну кількість символів)
	//for (size_t i = 0; i < size; i++)
	//{
	//	file.write((char*)&library[i], sizeof(Book));
	//}
	//file.close();
	//------------------------------
	// file.read();  --> для читання з файлу користувацького типу

	//fstream file("library.txt", ios_base::in);
	//if (!file.is_open()) {
	//	cout << "Error!! File not found" << endl;
	//	return 0;
	//}

	//Book res;
	///*while (!file.eof()) {

	//	file.read((char*)&res, sizeof(Book));
	//	print(res);
	//}*/
	////file.seekg(0, ios_base::beg); // розмістити файловий курсов в 0 байт відносно початку
	//file.seekg(0, ios_base::end); // розмістити файловий курсов в 0 байт відносно кінця файлу
	////cout << file.tellg() / sizeof(Book) << endl; // повертає поточний байт файлового курсора
	//int size = file.tellg() / sizeof(Book);
	////file.clear();
	//file.seekg(0, ios_base::beg);
	//Book* library = new Book[size];
	//for (size_t i = 0; i < size; i++)
	//{
	//	file.read((char*)&library[i], sizeof(Book));
	//}
	//file.close();

	//printAll(library, size, true);


}
