#include<iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#define SIZE 5

using namespace std;

//Task 1

/*template<typename T>
void initializeArr(T arr[SIZE][SIZE]) 
{
    for (size_t i = 0; i < SIZE; ++i) 
    {
        for (size_t j = 0; j < SIZE; ++j) 
        {
            arr[i][j] = rand() % 100;
        }
    }
}

template<typename T>
void printArr(T arr[SIZE][SIZE]) 
{
    for (size_t i = 0; i < SIZE; i++) 
    {
        for (size_t j = 0; j < SIZE; j++) 
        {
            cout << setw(5) << arr[i][j];
        }
        cout << endl;
    }
}

template<typename T>
void findMinMax(T arr[SIZE][SIZE], int size)
{
    T min = arr[0][0];
    T max = arr[0][0];

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (i == j) {
                if (arr[i][j] < min) 
                {
                    min = arr[i][j];
                }
                if (arr[i][j] > max) 
                {
                    max = arr[i][j];
                }
            }
        }
    }
    cout << "min : " << min << endl;
    cout << "max : " << max << endl;
}

template<typename T>
void sortRows(T arr[SIZE][SIZE])
{
    for (size_t i = 0; i < SIZE; i++)
    {
        sort(arr[i], arr[i] + SIZE);
    }
}*/

//Task 2

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main() 
{
/*  srand(time(0));

    //Task 1

    int arr[SIZE][SIZE]{};
    initializeArr(arr);
    cout << "The initialized arr is:" << endl;
    printArr(arr);
    cout << "Min and max elements on the main diagonal:" << endl;
    findMinMax(arr, SIZE);
    sortRows(arr);
    cout << "Arr after sorting each row:" << endl;
    printArr(arr); */

    //Task 2

    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    int result = gcd(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;

}