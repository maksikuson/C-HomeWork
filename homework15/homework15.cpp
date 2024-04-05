#include <iostream>
#include <string>
using namespace std;

//Task 1

struct Complex 
{
    float real;
    float imag;
};

//Task 2

struct Car 
{
    double length;
    double clearance;
    double engineVolume;
    int enginePower;
    double wheelDiameter;
    string color;
    string transmissionType;
};

void setCarParameters(Car& car)
{
    cout << "Enter length of the car: ";
    cin >> car.length;
    cout << "Enter clearance of the car: ";
    cin >> car.clearance;
    cout << "Enter engine volume of the car: ";
    cin >> car.engineVolume;
    cout << "Enter engine power of the car: ";
    cin >> car.enginePower;
    cout << "Enter wheel diameter of the car: ";
    cin >> car.wheelDiameter;
    cout << "Enter color of the car: ";
    cin >> car.color;
    cout << "Enter transmission type of the car: ";
    cin >> car.transmissionType;
}

void displayCarParameters(Car car) 
{
    cout << "Length: " << car.length << endl;
    cout << "Clearance: " << car.clearance << endl;
    cout << "Engine volume: " << car.engineVolume << endl;
    cout << "Engine power: " << car.enginePower << endl;
    cout << "Wheel diameter: " << car.wheelDiameter << endl;
    cout << "Color: " << car.color << endl;
    cout << "Transmission type: " << car.transmissionType << endl;
}

void searchCarParameter(Car car, string parameter) 
{
    cout << "Searching for parameter: " << parameter << endl;
    switch (parameter[0]) {
    case 'l':
        cout << "Length: " << car.length << endl;
        break;
    case 'c':
        cout << "Clearance: " << car.clearance << endl;
        break;
    case 'e':
        if (parameter[1] == 'v')
            cout << "Engine volume: " << car.engineVolume << endl;
        else
            cout << "Engine power: " << car.enginePower << endl;
        break;
    case 'w':
        cout << "Wheel diameter: " << car.wheelDiameter << endl;
        break;
    case 'o':
        cout << "Color: " << car.color << endl;
        break;
    case 't':
        cout << "Transmission type: " << car.transmissionType << endl;
        break;
    default:
        cout << "Parameter not found." << endl;
        break;
    }
}
int main() 
{

    //Task 1

    Complex num1, num2;

    cout << "Enter real part of first number: ";
    cin >> num1.real;
    cout << "Enter imaginary part of first number: ";
    cin >> num1.imag;

    cout << "Enter real part of second number: ";
    cin >> num2.real;
    cout << "Enter imaginary part of second number: ";
    cin >> num2.imag;

    cout << "Sum: " << num1.real + num2.real << " + " << num1.imag + num2.imag << "i" << endl;
    cout << "Difference: " << num1.real - num2.real << " + " << num1.imag - num2.imag << "i" << endl;
    cout << "Multiplication: " << num1.real * num2.real - num1.imag * num2.imag << " + " << num1.real * num2.imag + num1.imag * num2.real << "i" << endl;

    if (num2.real != 0 || num2.imag != 0)
        cout << "Division: " << (num1.real * num2.real + num1.imag * num2.imag) / (num2.real * num2.real + num2.imag * num2.imag) << " + " << (num1.imag * num2.real - num1.real * num2.imag) / (num2.real * num2.real + num2.imag * num2.imag) << "i" << endl;
    else
        cout << "Division by zero is not defined." << endl;


    //Task 2

    Car myCar;
    setCarParameters(myCar);
    cout << "\nCar parameters:" << endl;
    displayCarParameters(myCar);
    string parameterToSearch;
    cout << "\nEnter parameter to search: ";
    cin >> parameterToSearch;
    searchCarParameter(myCar, parameterToSearch);
}