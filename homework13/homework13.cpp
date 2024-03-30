#include <iostream>
using namespace std;


//Task 1


void removeChar(char* text, int removeChar)
{
	if (removeChar < 0 || removeChar >= strlen(text))
	{
		cout << "ERROR" << endl;
	}
	else
	{
		int length = strlen(text);
		for (int i = removeChar; i < length - 1; i++)
		{
			text[i] = text[i + 1];
		}
		text[length - 1] = '0';
	}	
}


//Task 2


void removeCharacter(char* str, char character)
{
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != character)
		{
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}


//Task 3


int stringLength(const char* str)
{
	int length = 0;
	while (*str != '\0')
	{
		++length;
		++str;
	}
	return length;
}

void SwapChar(char* text, int deleteIndex, char replaceChar)
{
	int length = stringLength(text);
	if (deleteIndex < 0 || deleteIndex >= length)
	{
		cout << "Invalid index!" << endl;
		return;
	}
	text[deleteIndex] = replaceChar;
}


//Task 4


void deletePoints(char* text)
{
	int length = 0;
	while (text[length] != '\0')
	{
		if (text[length] == '.')
		{
			text[length] = '!';
		}
		++length;
	}
}


//Task 5


int charCount(const char* str, char target)
{
	int count = 0;
	int length = 0;
	while (str[length] != '\0')
	{
		if ((str[length] == target))
		{
			++count;
		}
		++length;
	}
	return count;
}


//Task 6


void countCharacters(const char* str, int& letters, int& digits, int& others)
{
	letters = digits = others = 0;
	int index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] >= 'a' && str[index] <= 'z') || (str[index] >= 'A' && str[index] <= 'Z'))
		{
			++letters;
		}
		else if (str[index] >= '0' && str[index] <= '9')
		{
			++digits;
		}
		else
		{
			++others;
		}
		++index;
	}
}
int main()
{

	//Task1


/*	char text[20] = "Hello, world!";
	int symbol;

	cout << "Enter the index of the character you want to delete: ";
	cin >> symbol;

	removeChar(text, symbol);

	cout << "Text after deletion: " << text << endl; */


	//Task 2


/*	char str[100];
	char character;

	cout << "Enter a string: ";
	cin >> str;

	cout << "Enter the character you want to remove: ";
	cin >> character;

	removeCharacter(str, character);

	cout << "String after removal: " << str << endl; */


	//Task 3


/*	char text[20] = "Hello! 11";
	int index;
	char replaceChar;

	cout << "Enter the index of the character you want to replace: ";
	cin >> index;

	cout << "Enter the character you want to replace it with: ";
	cin >> replaceChar;

	SwapChar(text, index, replaceChar);

	cout << text; */


	//Task 4


/*	char text[20] = "Hello. 14.6";
	deletePoints(text);
	cout << text << endl; */
	

	//Task 5


/*	const int MAX_LENGTH = 100;
	char str[MAX_LENGTH];
	char target;

	cout << "Enter a string: ";
	cin >> str;

	cout << "Enter the character you want to count: ";
	cin >> target;

	int occurrences = charCount(str, target);
	cout << "The character '" << target << "' occurs " << occurrences << " times in the string." << endl; */


	//Task 6


	const int MAX_LENGTH = 100;
	char str[MAX_LENGTH];

	cout << "Enter a string: ";
	cin.getline(str, MAX_LENGTH);

	int letters, digits, others;
	countCharacters(str, letters, digits, others);

	cout << "Letters: " << letters << endl;
	cout << "Digits: " << digits << endl;
	cout << "Others: " << others << endl;
}