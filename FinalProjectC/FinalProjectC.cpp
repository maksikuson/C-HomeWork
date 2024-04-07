#define SIZE 5
#include <iostream>
#include <fstream>
using namespace std;

struct book
{
	int id;
	char title[100];
	char author[100];
	int year;
};

void Show(const book& b)
{
	cout << "ID: " << b.id << endl;
	cout << "Title: " << b.title << endl;
	cout << "Author: " << b.author << endl;
	cout << "Year: " << b.year << endl;
}

void AddBook(book books[], int& size)
{
	if (size < SIZE)
	{
		cout << "Enter book details" << endl;
		cout << "ID: " << endl;
		cin >> books[size].id;
		cin.ignore();
		cout << "Title: ";
		cin.getline(books[size].title, 100);
		cout << "Author: ";
		cin.getline(books[size].author, 100);
		cout << "Year: ";
		cin >> books[size].year;
		size++;
	}
	else
	{
		cout << "Library is full." << endl;
	}
}

void SaveToFile(const book books[], int size, const char* filename)
{
	ofstream file(filename);
	if (file.is_open())
	{
		for (int i = 0; i < size; i++)
		{
			file << books[i].id << endl;
			file << books[i].title << endl;
			file << books[i].author << endl;
			file << books[i].year << endl;
		}
		cout << "Library saved to file" << endl;
	}
	else
	{
		cerr << "Error opening file" << endl;
	}
	file.close();
}

void LoadFromFile(book books[], int& size, const char* filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Error opening file" << endl;
		return;
	}
	size = 0;
	while (!file.eof() && size < SIZE)
	{
		file >> books[size].id;
		file.ignore();
		file.getline(books[size].title, 100);
		file.getline(books[size].author, 100);
		file >> books[size].year;
		size++;
	}
	cout << "Library loaded from file" << endl;
	file.close();
}
int main()
{
	int choice, size = 0;
	book books[SIZE];

	do
	{
		cout << "----- MENU -----" << endl;
		cout << "[1] - Add a book" << endl;
		cout << "[2] - Show all books" << endl;
		cout << "[3] - Save library to file" << endl;
		cout << "[4] - Load library from file" << endl;
		cout << "[0] - Exit" << endl;
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
		{
			AddBook(books, size);
			break;
		}
		case 2:
		{
			cout << "Books in the library:" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << "Book " << i + 1 << endl;
				Show(books[i]);
			}
			break;
		}
		case 3:
		{
			SaveToFile(books, size, "library.txt");
			break;
		}
		case 4:
		{
			LoadFromFile(books, size, "library.txt");
			break;
		}
		case 0:
		{
			cout << "Exiting..." << endl;
			break;
		}

		default:
		{
			cout << "Invalid choice, try one more time" << endl;
			break;
		}
		}
	} while (choice != 0);
}