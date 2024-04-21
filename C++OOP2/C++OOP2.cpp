#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
	static int count;
	char* str;

public:
	String() : String(80) {}

	String(int size)
	{
		str = new char[size + 1];
		for (int i = 0; i <= size; i++)
		{
			str[i] = '\0';
		}
		count++;
	}

	String(const char* s)
	{
		int size = strlen(s);
		str = new char[size + 1];
		for (int i = 0; i < size; ++i)
		{
			str[i] = s[i];
		}
		str[size] = '\0';
		count++;
	}

	~String()
	{
		delete[]str;
		count--;
	}

	void input()
	{
		cout << "Enter a string: ";
		char buffer[256];
		cin.getline(buffer, 256);
		int size = strlen(buffer);
		str = new char[size + 1];
		for (int i = 0; i < size; ++i) 
		{
			str[i] = buffer[i];
		}
		str[size] = '\0';
	}

	void display() const
	{
		cout << "String: " << str << endl;
	}

	static int getCount()
	{
		return count;
	}

};

int String::count = 0;

int main()
{
	String s1;
	String s2(100);
	String s3("Hello");

	cout << "Number of String objects created: " << String::getCount() << endl;

	s1.input();
	cout << "String s1: ";
	s1.display();

	cout << "Number of String objects: " << String::getCount() << endl;
}