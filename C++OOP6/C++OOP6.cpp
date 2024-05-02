#include <iostream>
#include <algorithm> 
#include <cctype> 
using namespace std;

int main()
{
	//1
	string strings = "Hello, world!";
	cout << strings << endl;
	//2
	cout << strings.length() << endl;
	//3
	cout << strings[0] << endl;
	//4
	strings.replace(7, 11, "Earth!");
	cout << strings << endl;
	//5
	strings += " How are you? ";
	cout << strings << endl;
	//6
	string strings1 = "Hello, world!";
	cout << strings1.compare(strings) << endl;
	//7
	string strings2 = "Hello, Earth, how are you?";
	cout << strings.substr(strings.find("Earth"), 5) << endl;
	//8
	cout << strings.find("Earth") << endl;
	//9
	cout << strings.erase(7, 13) << endl;
	//10
	cout << strings2.insert(7, "Big ") << endl;
	//11
	string strings3 = "Hello, World!";
	reverse(strings3.begin(), strings3.end());
	cout << strings3 << endl;
	//12
	string strings4 = "o";
	size_t count = 0;
	size_t pos = strings3.find(strings4);
	while (pos != string::npos)
	{
		count++;
		pos = strings3.find(strings4, pos + 1);
	}
	cout << count << endl;
	//13
	string strings5 = "Hello World!";
	transform(strings5.begin(), strings5.end(), strings5.begin(), ::toupper);
	cout << strings5 << endl;
	//14
	string strings6 = "Hello, it`s very easy!";
	string result;
	for (char c : strings6)
	{
		if (c != ' ')
		{
			result += c;
		}
	}
	cout << result << endl;
	//15
	string strings7 = "It`s very very interesting";
	string strings8 = "very";
	string strings9 = "unusual";
	size_t pos1 = strings7.find(strings8);
	while (pos1 != string::npos)
	{
		strings7.replace(pos1, strings8.length(), strings9);
		pos1 = strings7.find(strings8, pos1 + strings9.length());
	}
	cout << strings7 << endl;
	//16
	string strings10 = "It's very, very interesting";
	string strings11 = "extremely";
	strings10.replace(5, 10, strings11);
	cout << "#16: " << strings10 << endl;
	//17
	string strings12 = "abba";
	bool isPalindrome = true;
	int length = strings12.length();
	for (int i = 0; i < length / 2; i++) 
	{
		if (strings12[i] != strings12[length - i - 1]) 
		{
			isPalindrome = false;
			break;
		}
	}
	if (isPalindrome) 
	{
		cout << strings12 << " is a palindrom" << endl;
	}
	else
	{
		cout << strings12 << " is a not palindrom" << endl;
	}
	//18
	string strings13 = "abrakadabra";
	sort(strings13.begin(), strings13.end());
	cout << strings13 << endl;
	//19
	string strings14 = "Today 2024-04-22";
	for (int i = 0; i < strings14.length(); i++)
	{
		if (isdigit(strings14[i]))
		{
			strings14[i] = 'X';
		}
	}
	cout << strings14 << endl;
	//20
	string strings15 = "Hello";
	string strings16 = "World";
	string result1 = strings15;
	result1.insert(result1.length(), strings16);
	cout << result1 << endl;
}