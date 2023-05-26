#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
   // ofstram ---> write file; out file
   // ifstrem ---> read file; in file
	/*int size = 5;
	string colors[]{ "red","blue","yellow","gold","magenta" };*/
	//string fname = "myfile.txt";
	//ofstream file(fname, ios_base::app);
	////file.open(fname,ios_base::app);
	//if (!file.is_open()) {
	//	cout << "Error!!!!";
	//}
	//else {
	//	for (size_t i = 0; i < size; i++)
	//	{
	//		file << colors[i] << " ";
	//		/*file << "\t";
	//		for (size_t j = 0; j < colors[i].size(); j++)
	//		{
	//			file << colors[i][j] << "  ";
	//		}
	//		file << endl;*/
	//	}
	//	file << endl;
	//}
	//file.close();
	//remove(fname.c_str());
	/*int numbers[]{ 5,7,8,4,5,-2,10 };
	string numberFile = "number.dat";
	ofstream file(numberFile, ios_base::app);
	if (!file.is_open()) {
		cout << "Error";
	}
	else {
		for (size_t i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
		{
			file << numbers[i] << endl;
		}
	}
	file.close();*/

	ifstream file("number.dat");
	if (!file.is_open()) {
		cout << "Error" << endl;
	}
	else {
		// way 1
		//string value;
		//while (!file.eof()) // true - коли кінець файлу
		//{
		//	file >> value; // запише з файлу текст до пропуску або ентер
		//	cout << value << endl;
		//}
		//while (file >> value) // true - коли кінець файлу
		//{
		//	cout << value << endl;
		//}
		// way 2
		/*char symbol;
		while (file.get(symbol))
		{
			cout << symbol << endl;
		}*/

		// way 3
		/*char value[50];
		while (file.getline(value,50))
		{
			cout << value << endl;
			cout << "=================" << endl;
		}*/

		// way 4 
		/*string value;
		while (getline(file,value))
		{
			cout << value << endl;
			cout << "=================" << endl;
		}*/
		
		int size = 0;
		int value;
		int sum = 0;
		while (file >> value)
		{
			size++;
		}
		cout << "Size = " << size << endl;
		int* arr = new int[size];
		int i = 0;
		file.clear(); // чистимо буфер
		file.seekg(0); // на початок файлу для читання (переміститися в 0 байт відносно початку)
		while (file >> arr[i++])
		{
		}
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	file.close();
}
