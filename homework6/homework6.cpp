#include<iostream>
using namespace std;

int main()
{
	//Task 1

/*	int choice;
	cout << "Enter shape : " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				if (i == j || j > i)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 2:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				if (i == j || j < i)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 3:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if ((j > i && i + j < N - 1) || i == j || i + j == N - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 4:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if ((j < i && i + j > N - 1) || i == j || i + j == N - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 5:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if ((j > i && i + j < N - 1) || ((j < i && i + j > N - 1) || i == j || i + j == N - 1))
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 6:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if ((j < i && i + j < N - 1) || ((j > i && i + j > N - 1) || i == j || i + j == N - 1))
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 7:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if ((j < i && i + j < N - 1) || i == j || i + j == N - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 8:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if ((j > i && i + j > N - 1) || i == j || i + j == N - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 9:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if (j + i < N - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 10:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if (j - i < N + 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	default:
		break;
	}*/





    //Task 2





/*  int choice;
    do
	{
		cout << "\nMenu:" << endl;
		cout << "1. Process a number" << endl;
		cout << "2. Exit the program" << endl;
		cout << "Choose an option: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int number;
			cout << "Enter a number: ";
			cin >> number;

			int digitCount = 0, sum = 0, zeroCount = 0;
			double average = 0.0;

			int tempNumber = number;
			while (tempNumber != 0)
			{
				int digit = tempNumber % 10;
				sum += digit;
				digitCount++;
				if (digit == 0)
				{
					zeroCount++;
				}
				tempNumber /= 10;
			}

			if (digitCount > 0)
			{
				average = sum / double(digitCount);
			}
			cout << "Number of digits in the number: " << digitCount << endl;
			cout << "Sum of digits in the number: " << sum << endl;
			cout << "Average of digits in the number: " << average << endl;
			cout << "Number of zeros in the number: " << zeroCount << endl;

			break;
		}
		case 2:
			cout << "Program terminated." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 2);*/




    
    //Task 3





    int rows = 5, cols = 5, cellSize = 3;

	for (size_t i = 0; i < rows * cellSize; i++)
	{
		for (size_t j = 0; j < cols * cellSize; j++)
		{
			if ((i / cellSize + j / cellSize) % 2 == 0)
			{
				for (size_t k = 0; k < cellSize; k++)
				{
					cout << "*";
				}
			}
			else
			{
				for (size_t k = 0; k < cellSize; k++)
				{
					cout << "-";
				}
			}
		}
		cout << endl;
	}
}