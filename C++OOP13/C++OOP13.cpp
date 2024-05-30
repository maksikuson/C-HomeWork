#include <iostream>
#include <vector>
using namespace std;

void divideNumbers()
{
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    try
    {
        if (num2 == 0) 
        {
            throw runtime_error("Error: Division by zero!");
        }
        double result = num1 / num2;
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error& e)
    {
        cout << e.what() << endl;
    }
}

class NegativeNumberException : public runtime_error 
{
public:
    NegativeNumberException() : runtime_error("Error: Negative number!") {}
};

void checkPositive(int number) 
{
    if (number < 0) 
    {
        throw NegativeNumberException();
    }
    cout << "Positive number: " << number << endl;
}

void accessArrayElement(const vector<int>& arr, int index)
{
    try 
    {
        if (index < 0 || index >= arr.size()) 
        {
            throw out_of_range("Error: Index out of range!");
        }
        cout << "Element at index " << index << ": " << arr[index] << endl;
    }
    catch (const out_of_range& e) 
    {
        cout << e.what() << endl;
    }
}

void nestedExceptions() 
{
    vector<int> arr = { 1, 2, 3, 4, 5 };
    double num1, num2;

    cout << "Enter two numbers (for division): ";
    cin >> num1 >> num2;

    try 
    {
        try 
        {
            if (num2 == 0) 
            {
                throw runtime_error("Error: Division by zero!");
            }
            double result = num1 / num2;
            cout << "Result: " << result << endl;
        }
        catch (const runtime_error& e) 
        {
            cout << e.what() << endl;
            throw;
        }

        int index;
        cout << "Enter index to access array: ";
        cin >> index;
        if (index < 0 || index >= arr.size()) 
        {
            throw out_of_range("Error: Index out of range!");
        }
        cout << "Element at index " << index << ": " << arr[index] << endl;
    }
    catch (const out_of_range& e)
    {
        cout << e.what() << endl;
    }
}

void allocateMemory() 
{
    try 
    {
        int* largeArray = new int[1000000000];
        delete[] largeArray;
    }
    catch (const bad_alloc& e)
    {
        cout << "Error: Unable to allocate memory!" << endl;
    }
}

class MyClass
{
public:
    MyClass() 
    {
        throw runtime_error("Error in MyClass constructor!");
    }
};

void functionThatThrows()
{
    throw runtime_error("Error in function!");
}

void functionThatCatchesAndRethrows()
{
    try
    {
        functionThatThrows();
    }
    catch (...) 
    {
        cout << "Catching and rethrowing..." << endl;
        throw;
    }
}

void functionWithExceptionSpecification() 
{
    throw runtime_error("Exception in function with specification!");
}

void multipleExceptions() 
{
    throw out_of_range("This is an out_of_range exception!");
}

class CustomException : public runtime_error
{
    int errorCode;
public:
    CustomException(const string& message, int code) : runtime_error(message), errorCode(code) {}
    int getCode() const { return errorCode; }
};

void functionThatThrowsCustomException()
{
    throw CustomException("This is a CustomException!", 404);
}

int main() 
{
    divideNumbers();

    int number;
    cout << "Enter a number: ";
    cin >> number;
    try 
    {
        checkPositive(number);
    }
    catch (const NegativeNumberException& e)
    {
        cout << e.what() << endl;
    }

    vector<int> arr = { 1, 2, 3, 4, 5 };
    int index;

    cout << "Enter index to access array: ";
    cin >> index;
    accessArrayElement(arr, index);

    nestedExceptions();
    allocateMemory();

    try 
    {
        MyClass obj;
    }
    catch (const runtime_error& e)
    {
        cout << e.what() << endl;
    }

    try 
    {
        functionThatCatchesAndRethrows();
    }
    catch (const runtime_error& e) 
    {
        cout << e.what() << endl;
    }

    try 
    {
        functionWithExceptionSpecification();
    }
    catch (const runtime_error& e) 
    {
        cout << e.what() << endl;
    }

    try
    {
        multipleExceptions();
    }
    catch (const runtime_error& e) 
    {
        cout << "runtime_error: " << e.what() << endl;
    }
    catch (const out_of_range& e)
    {
        cout << "out_of_range: " << e.what() << endl;
    }

    try 
    {
        functionThatThrowsCustomException();
    }
    catch (const CustomException& e)
    {
        cout << "Error code: " << e.getCode() << ", Message: " << e.what() << endl;
    }
}