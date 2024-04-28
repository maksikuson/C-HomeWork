#include <iostream>
using namespace std;

template <typename T>
T findMax(T arr[], int size);

template <typename T>
T findMin(T arr[], int size);

template <typename T>
void bubbleSort(T arr[], int size);

template <typename T>
int binarySearch(T arr[], int size, T value);

template <typename T>
void replaceElement(T arr[], int size, int index, T newValue);

template <typename T>
T findMax(T arr[], int size) 
{
    T max = arr[0];
    for (int i = 1; i < size; i++) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
T findMin(T arr[], int size) 
{
    T min = arr[0];
    for (int i = 1; i < size; i++) 
    {
        if (arr[i] < min) 
        {
            min = arr[i];
        }
    }
    return min;
}

template <typename T>
void bubbleSort(T arr[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
int binarySearch(T arr[], int size, T value) 
{
    int left = 0;
    int right = size - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) 
        {
            return mid;
        }
        else if (arr[mid] < value) 
        {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

template <typename T>
void replaceElement(T arr[], int size, int index, T newValue)
{
    if (index >= 0 && index < size)
    {
        arr[index] = newValue;
    }
    else 
    {
        cout << "Index out of bounds" << endl;
    }
}

int main() 
{
    int arr[] = { 10, 5, 8, 3, 12, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum: " << findMax<int>(arr, size) << endl;
    cout << "Minimum: " << findMin<int>(arr, size) << endl;

    bubbleSort<int>(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int valueToSearch = 8;
    int index = binarySearch<int>(arr, size, valueToSearch);
    if (index != -1) 
    {
        cout << "Value : " << valueToSearch << " found at index : " << index << endl;
    }
    else 
    {
        cout << "Value " << valueToSearch << " not found" << endl;
    }

    replaceElement<int>(arr, size, 2, 20);
    cout << "Array after replacement: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}