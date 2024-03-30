#include <iostream>
using namespace std;

/*int* createThirdArray(int* A, int M, int* B, int N, int& size)
{
	int* thirdArray = new int[M];
	size = 0;
	for (int i = 0; i < M; ++i)
	{
		bool found = false;
		for (int j = 0; j < N; ++j)
		{
			if (A[i] == B[j])
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			thirdArray[size] = A[i];
			size++;
		}
	}
	return thirdArray;
}*/

int main()
{
	//Task 1

/*  int M, N;
	cout << "Enter the size of array A: ";
	cin >> M;
	int* A = new int[M];
	cout << "Enter elements of array A: ";
	for (int i = 0; i < M; ++i)
	{
		cin >> A[i];
	}
	cout << "Enter the size of array B: ";
	cin >> N;
	int* B = new int[N];
	cout << "Enter elements of array B: ";
	for (int i = 0; i < N; ++i)
	{
		cin >> B[i];
	}
	int size;
	int* thirdArray = createThirdArray(A, M, B, N, size);
	cout << "Third array: ";
	for (int i = 0; i < size; ++i)
	{
		cout << thirdArray[i] << " ";
	}
	cout << endl;

	delete[] A;
	delete[] B;
	delete[] thirdArray;

	thirdArray = nullptr;
	size = 0;*/

	//Task 2

	int M, N;

	cout << "Enter the size of array A: ";
	cin >> M;
	cout << "Enter the size of array B: ";
	cin >> N;

	int* A = new int[M];
	int* B = new int[N];

	cout << "Enter elements of array A: ";
	for (int i = 0; i < M; ++i)
	{
		cin >> A[i];
	}
	cout << "Enter elements of array B: ";
	for (int i = 0; i < N; ++i)
	{
		cin >> B[i];
	}
	int thirdArraySize = 0;
	int* thirdArray = new int[M];
	bool isUnique;
	for (int i = 0; i < M; ++i)
	{
		isUnique = true;
		for (int j = 0; j < N; ++j)
		{
			if (A[i] == B[j])
			{
				isUnique = false;
				break;
			}
		}
		if (isUnique)
		{
			thirdArray[thirdArraySize] = A[i];
			thirdArraySize++;
		}
	}
	cout << "Third array: ";
	for (int i = 0; i < thirdArraySize; ++i)
	{
		cout << thirdArray[i] << " ";
	}
	cout << endl;
	
	delete[] A;
	delete[] B;
	delete[] thirdArray;

	A = nullptr;
	B = nullptr;
	thirdArray = nullptr;
}