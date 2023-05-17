#include <iostream>
#include <string>
using namespace std;
//Розробіть програму «Бібліотека».Створіть  структуру «Книга»(назва, автор, видавництво, жанр).Створіть масив з 10 книг.Реалізуйте для нього такі можливості :
struct Book
{
	string name;
	string author;
	string publisher;
	string genre;
};
//■ Редагувати книгу;
void edit(Book& obj)
{
	cout << "\n\t===================== Edit book --> " << obj.name << " =======================" << endl;
	cout << "\t\t Enter Name      :: "; getline(cin, obj.name);
	cout << "\t\t Enter Author    :: "; getline(cin, obj.author);
	cout << "\t\t Enter Publisher :: "; getline(cin, obj.publisher);
	cout << "\t\t Enter Genre     :: "; getline(cin, obj.genre);
}
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
//■ Пошук книг за автором;
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
//■ Пошук книги за назвою;

//■ Сортування масиву за назвою книг;
void sortByName(Book* library, const int& size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			if (library[j].name > library[j + 1].name) {
				Book tmp = library[j];
				library[j] = library[j + 1];
				library[j + 1] = tmp;
			}
		}
	}
}
//■ Сортування масиву за автором;
//■ Сортування масиву за видавництвом.
//■ Видалення книги за певним критерієм.
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
//■ Додавання нової книги у масив
void addBook(Book*& library, int& size)
{
	// змінили розмір (тобто який розмір має новий масив)
	size++;
	Book* tmp = new Book[size]; // Створили новий масив нв один елемент більше
	for (size_t i = 0; i < size - 1; i++)
	{
		tmp[i] = library[i]; // Переписила значення в новий масив з старого
	}
	edit(tmp[size - 1]); // Додали нове значення в кінець масиву
	delete[] library; // видалили старий масив
	library = tmp; // зберегли новий масив

}
int main()
{
	int size = 10;
	Book* library = new Book[size]{
		{"Carrie","Stephen King","Anchor","Horror"},
		{"Night Shift","Stephen King","Anchor","Horror"},
		{"Harry Potter and the Sorcerer's Stone","J.K. Rowling","Pottermore Publishing","Fantasy"},
		{"It: A Novel","Stephen King","Scribner","Horror"},
		{"Identity: A Novel","Nora Roberts","St. Martin's Press","Thrillers"},
		{"Harry Potter and the Goblet of Fire","J.K. Rowling","Pottermore Publishing","Fantasy"},
		{"The Wager","David Grann","Doubleday","Memoirs"},
		{"The Book Thief","Markus Zusak","Knopf Books for Young Readers","Fiction"},
		{"Salem's Lot","Stephen King","Anchor","Horror"},
		{"Harry Potter and the Order of the Phoenix","J.K. Rowling","Pottermore Publishing","Fiction"},
	};
	string find;
	int choice;
	do
	{
		cout << "Select choice :: \n\t 1 - Edit book; \n\t 2 - Print All book; \n\t 3 - Find book; \n\t 4 - sort; \n\t 5 - delete book; \n\t 6 - add book \n\t 0 - exit; \n\t Enter choice :: ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			printAll(library, size, true);
			cout << "\t 1 - by author; \n\t 2 - by name; \n\t 3 - by number ";
			cin >> choice;
			switch (choice)
			{
			case 1: {
				cout << "Enter name author :: ";
				getline(cin, find);
				int index = findByAuthor(library, size, find);
				if (index != -1) {
					cin.ignore();
					edit(library[index]);
				}
				else {
					cout << "Error. Book not found" << endl;
				}
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				int index;
				cout << "Enter position book :: ";
				cin >> index;
				if (index > 0 && index <= size) {
					cin.ignore();
					edit(library[index - 1]);
				}
				else {
					cout << "Error. Book not found! Enter true position" << endl;
				}
				break;
			}
			default:
				break;
			}

			break;
		}
		case 2: {
			printAll(library, size);
			break;
		}
		case 4: {
			cout << "\t 1 - by author; \n\t 2 - by name; \n\t 3 - by publish ";
			cin >> choice;
			switch (choice)
			{
			case 1: {
				break;
			}
			case 2: {
				sortByName(library, size);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 5: {
			cout << "\t 1 - by author; \n\t 2 - by name; \n\t 3 - by number ";
			cin >> choice;
			switch (choice)
			{
			case 1: {
				cin.ignore();
				cout << "Enter name author :: ";
				getline(cin, find);
				int index = findByAuthor(library, size, find);
				if (index != -1) {
					deleteBook(library, size, index);
				}
				else {
					cout << "Error. Book not found" << endl;
				}
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				int index;
				cout << "Enter position book :: ";
				cin >> index;
				if (index > 0 && index <= size) {
					deleteBook(library, size, index - 1);
				}
				else {
					cout << "Error. Book not found! Enter true position" << endl;
				}
				break;
			}
			}
			break;
		}
		case 6: {
			cout << "======== Adding new book ===========" << endl;
			cin.ignore();
			addBook(library, size);
			break;
		}
		default:
			break;
		}
	} while (choice != 0);
}


