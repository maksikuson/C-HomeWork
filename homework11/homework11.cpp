#include <iostream>
using namespace std;

int main()
{
	//Task 1

/*	const int SIZE = 10;
	int arr1[SIZE] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr2[SIZE] = {};

	int* fromPtr = arr1;
	int* toPtr = arr2;

	for (size_t i = 0; i < SIZE; i++)
	{
		*(toPtr + i) = *(fromPtr + i);
	}
	cout << "arr2 : ";
	for (int i = 0; i < SIZE; ++i)
	{
		cout << arr2[i] << " ";
	} */
	
	//Task 2

/*	const int SIZE = 5;
	int myArr[]{ 1,2,3,4,5 };
	cout << "Original arr : ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << myArr[i] << " ";
	}
	cout << endl;

	int* start = myArr;
	int* end = myArr + SIZE - 1;

	while (start < end)
	{
		int temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	cout << "Reversed arr : ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << myArr[i] << " ";
	}
	cout << endl; */

	//Task 3

	const int SIZE = 5;
	int arr1[SIZE] = { 1,2,3,4,5 };
	int arr2[SIZE];

	int* ptr1 = arr1 + SIZE - 1;
	int* ptr2 = arr2;

	for (int i = 0; i < SIZE; i++)
	{
		*ptr2 = *ptr1;
		ptr1--;
		ptr2++;
	}
	cout << "Copied arr with reversed order : ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
}