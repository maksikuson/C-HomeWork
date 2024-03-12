#include <iostream>
#include <iomanip>
using namespace std;


//Task 1


/*int power(int base, int exponent)
{
	int result = 1.0;
	for (int i = 0; i < exponent; ++i)
	{
		result *= base;
	}
	return result;
}*/


//Task 2


/*int sumInRange(int start, int end)
{
	int sum = 0;
	for (int i = start; i <= end; ++i)
	{
		sum += i;
	}
	return sum;
}*/


//Task 3


/*bool isPerfect(int num)
{
	int sum = 0;
	for (int i = 1; i < num; ++i)
	{
		if (num % 1 == 0)
		{
			sum += i;
		}
	}
	return sum == num;
}
void findPerfectNumbers(int start, int end)
{
	cout << "Perfect numbers in the range from " << start << " to " << end << ":\n";
	for (int i = start; i <= end; ++i)
	{
		if (isPerfect(i))
		{
			cout << i << endl;
		}
	}
}*/


//Task 4


/*void card(int suit, int num)
{
	char card[13] = { 'A','2','3','4','5','6','7','8','9','0','J','Q','K' };
	cout << " ___________________\n";
	cout << "|                   |\n";
	cout << "|                   |\n";
	if (num == 10)cout << '|' << setw(4) << "1" << card[num - 1] << "              |\n";
	else cout << '|' << setw(4) << card[num - 1] << "               |\n";
	cout << "|                   |\n";
	cout << "|                   |\n";
	cout << "|                   |\n";
	cout << "|                   |\n";
	cout << "|                   |\n";
	switch (suit)
	{
		case 1: cout <<'|'<< setw(12) << "HEART"<<"       |\n"; break;
        case 2: cout << '|' << setw(12) << "DIAMOND" << "       |\n"; break;
        case 3: cout << '|' << setw(12) << "CLUB" << "       |\n"; break;
        case 4: cout << '|' << setw(12) << "SPADE" << "       |\n"; break;
	}
	cout << "|                   |\n";
	cout << "|                   |\n";
	cout << "|                   |\n";
	cout << "|                   |\n";
	if (num == 10)cout << "|              " << "1" << card[num - 1] << "   |\n";
	else cout << "|               " << card[num - 1] << "   |\n";
	cout << "|                   |\n";
	cout << "|___________________|\n";
}*/


//Task 5


/*bool isLucky(int number)
{
	if (number < 100000 || number > 999999)
	{
		return false;
	}

	int firstHalf = number / 1000;
	int secondHalf = number % 1000;
	int sumFirstHalf = 0;
	int sumSecondHalf = 0;

	while (firstHalf > 0)
	{
		sumFirstHalf += firstHalf % 10;
		firstHalf /= 10;
	}
	while (secondHalf > 0) {
		sumSecondHalf += secondHalf % 10;
		secondHalf /= 10;
	}
	return sumFirstHalf == sumSecondHalf;
}*/


//Task 6


/*int linearSearch(int arr[], int size, int key)
{
	int i = 0;
	while (i < size)
	{
		if (arr[i] == key)
		{
			return i;
		}
		++i;
	}
	return -1;
}*/


//Task 7


/*int binarySearch(int arr[], int size, int key)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = left + (right = left) / 2;
		if (arr[mid] == key)
		{
			return mid;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}*/


//Task 8


int binaryToDecimal(int n)
{
	int decimalNumber = 0, i = 0, remainder;
	while (n!=0)
	{
		remainder = n % 10;
		n /= 10;
		decimalNumber += remainder * (1 << i);
		++i;
	}
	return decimalNumber;
}


int main()
{


	//Task 1


/*	int base, exponent;
	cout << "Enter the base degree: ";
	cin >> base;
	cout << "Enter exponent: ";
	cin >> exponent;

	cout << "Result: " << power(base, exponent) << endl;*/
	

	//Task 2


/*	int start, end;
	cout << "Enter the beginning of the point: ";
	cin >> start;
	cout << "Enter the end of the range: ";
	cin >> end;

	cout << "Sum of numbers in the range: " << sumInRange(start, end) << endl;*/


	//Task 3


	/*int start, end;
	cout << "Enter the beginning of the interval: ";
	cin >> start;
	cout << "Enter the end of the interval: ";
	cin >> end;

	findPerfectNumbers(start, end);*/

 
	//Task 4


/*	int a, s;
	cout << "Enter card\n1 - Ace \n2 - Two\n3 - Three\n4 - Four\n5 - Five\n6 - Six\n7 - Seven\n8 - Eight\n9 - Nine\n10 - Ten\n11 - Jacket\n12 - Quin\n13 - King" << endl;
	cin >> a;
	cout << "\n\t\t\tCard suits\n1. Heart.\n2. Diamond\n3. Club\n4. Spade\n";
	cout << "Input a card suit: ";
	cin >> s;
	card(s, a);*/


	//Task5


/*	int number;
	cout << "Enter a six-digit number: ";
	cin >> number;

	if (isLucky(number))
	{
		cout << number << " is a lucky number!" << endl;
	}
	else
	{
		cout << number << " is not a lucky number." << endl;
	}*/


	//Task 6


/*	int arr[] = { 5, 2, 8, 10, 3, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int key;
    cout << "Enter the key to search: ";
	cin >> key;

	int result = linearSearch(arr, size, key);
	if (result != -1)
	{
		cout << "Key found at index " << result << endl;
	}
	else
	{
		cout << "Key not found" << endl;
	}*/


	//Task 7


/*	int arr[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int key;
	cout << "Enter the key to search: ";
	cin >> key;
	int result = binarySearch(arr, size, key);

	if (result != -1)
	{
		cout << "Key found at index " << result << endl;
	}
	else
	{
		cout << "Key not found" << endl;
	}*/


    //Task 8


    int binaryNumber;
	cout << "Enter a binary number: ";
	cin >> binaryNumber;

	int decimalNumber = binaryToDecimal(binaryNumber);
	cout << "Decimal equivalent: " << decimalNumber;


}