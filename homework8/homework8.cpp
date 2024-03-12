#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{


    //Task 1


/*  int num;
    cout << "Enter number: ";
    cin >> num;

    const int size = 3;

    int array[size][size];

    for (int i = 0; i < size; ++i)
    {
        int value = num;
        for (int j = 0; j < size; ++j)
        {
            array[i][j] = value;
            value *= 2;
            num *= 2;
        }
    }
    cout << "The resulting array:\n";
    for (int i = 0; i < size; ++i)
    {
        int value = num;
        for (int j = 0; j < size; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }*/



    //Task 2


/*  int num;
    cout << "Enter number: ";
    cin >> num;

    const int size = 3;

    int array[size];

    for (int i = 0; i < size; ++i)
    {
        array[i] = num + i;
    }
    cout << "The resulting array:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;*/


    //Task 3


    const int rows = 3;
    const int cols = 6;
    int arr[rows][cols] = {
        {1, 2, 0, 4, 5, 3},
        {4, 5, 3, 9, 0, 1},
        {2, 4, 9, 6, 1, 7}
    };

    cout << "Initial array:\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int shifts;
    cout << "Enter the number of shifts: ";
    cin >> shifts;

    string direction;
    cout << "Enter the direction of shift (l == left, r == right, u == up, d == down): ";
    cin >> direction;

    for (int s = 0; s < shifts; ++s) 
    {
        switch (direction[0]) 
        {
        case 'l':
            for (int i = 0; i < rows; ++i) 
            {
                int temp = arr[i][0];
                for (int j = 0; j < cols - 1; ++j) 
                {
                    arr[i][j] = arr[i][j + 1];
                }
                arr[i][cols - 1] = temp;
            }
            break;
        case 'r':
            for (int i = 0; i < rows; ++i) 
            {
                int temp = arr[i][cols - 1];
                for (int j = cols - 1; j > 0; --j) 
                {
                    arr[i][j] = arr[i][j - 1];
                }
                arr[i][0] = temp;
            }
            break;
        case 'u':
            for (int j = 0; j < cols; ++j) 
            {
                int temp = arr[0][j];
                for (int i = 0; i < rows - 1; ++i) 
                {
                    arr[i][j] = arr[i + 1][j];
                }
                arr[rows - 1][j] = temp;
            }
            break;
        case 'd':
            for (int j = 0; j < cols; ++j) 
            {
                int temp = arr[rows - 1][j];
                for (int i = rows - 1; i > 0; --i) 
                {
                    arr[i][j] = arr[i - 1][j];
                }
                arr[0][j] = temp;
            }
            break;
        default:
            cout << "Incorrect input!";
        }
    }
    cout << endl;
    cout << "The array after the landslide:\n";
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}