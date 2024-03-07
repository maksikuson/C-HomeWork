#include <iostream>
using namespace std;

int main()
{
	//Task1
	int number;
	cout << "Enter a six-digit number: ";
	cin >> number;

	if (number >= 100000 || number < 999999)
	{
		int degit01 = number / 100000;
		int degit02 = (number / 100000) % 10;
		int degit03 = (number / 1000) % 10;
		int degit04 = (number / 100) % 10;
		int degit05 = (number / 10) % 10;
		int degit06 = number % 10;

		if (degit01 + degit02 + degit03 == degit04 + degit05 + degit06)
		{
			cout << "Number is lucky" << endl;
		}
		else
		{
			cout << "The number is not lucky" << endl;
		}
	}
	else
	{
		cout << "The number is not a six-digit number" << endl;
	}
    //Task2

	int number1;
	int degit1, degit2, degit3, degit4;
	cout << "Enter a four-digit number: " << endl;
	cin >> number1;

	if (number1 >= 1000 && number1 <= 9999)
	{
		cout << "A number is four-digit" << endl;
	}
	else
	{
		cout << "Enter corect number" << endl;
	}
		
	degit1 = number1 / 1000 % 10;
	degit2 = number1 / 100 % 10;
	degit3 = number1 / 10 % 10;
	degit4 = number1 % 10;
    
	cout << degit2 << degit1 << degit4 << degit3 << endl;

	//Task3

	int num1, num2, num3, num4, num5, num6, num7;
	cout << "Enter 7 integers: " << endl;
	cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7;

	int maxNumber = num1;
	if (num2 > maxNumber) maxNumber = num2;
	if (num3 > maxNumber) maxNumber = num3;
	if (num4 > maxNumber) maxNumber = num4;
	if (num5 > maxNumber) maxNumber = num5;
	if (num6 > maxNumber) maxNumber = num6;
	if (num7 > maxNumber) maxNumber = num7;

	cout << "The maximum number is: " << maxNumber << endl;

	//Task4

	int distance_AB, distance_BC, weight;
	cout << "Enter the distance between points A and B: ";
	cin >> distance_AB;
	cout << "Enter the distance between points B and C: ";
	cin >> distance_BC;
	cout << "Enter the weight of the cargo: ";
	cin >> weight;

	int consumption;
	if (weight <= 500)
		consumption = 1; 
	else if (weight <= 1000)
		consumption = 4; 
	else if (weight <= 1500)
		consumption = 7; 
	else if (weight <= 2000)
		consumption = 9;
	else
	{
		cout << "The aircraft cannot lift such cargo. The flight is impossible." << endl;
	}

	int fuel_required = distance_AB * consumption + distance_BC * consumption;

	if (fuel_required <= 300)
		cout << "The minimum amount of fuel needed for refueling at point B to fly from point A to point C is: " << fuel_required << " liters." << endl;
	else
		cout << "The aircraft cannot fly the required distance due to fuel capacity." << endl;

	//Task5

	const int SALARY = 200;
	int sales, sales2, sales3;
	cout << "Enter sum of first manager's sales: ";
	cin >> sales;
	cout << "Enter sum of second manager's sales: ";
	cin >> sales2;
	cout << "Enter sum of third manager's sales: ";
	cin >> sales3;

	int salary1, salary2, salary3;

	if (sales > 500)
        salary1 = sales / 100 * 5 + SALARY;
    else if (sales > 100)
        salary1 = sales / 100 * 8 + SALARY;
    else
        salary1 = sales / 100 * 3 + SALARY;

    if (sales2 > 500)
        salary2 = sales2 / 100 * 5 + SALARY;
    else if (sales2 > 100)
        salary2 = sales2 / 100 * 8 + SALARY;
    else
        salary2 = sales2 / 100 * 3 + SALARY;

    if (sales3 > 500)
        salary3 = sales3 / 100 * 5 + SALARY;
    else if (sales3 > 100)
        salary3 = sales3 / 100 * 8 + SALARY;
    else
        salary3 = sales3 / 100 * 3 + SALARY;

	cout << "Maneger 1's full salary: $" << salary1 << endl;
	cout << "Maneger 2's full salary: $" << salary2 << endl;
	cout << "Maneger 3's full salary: $" << salary3 << endl;

	int maxSales = max(sales, max(sales2, sales3));
	int bestSalary = maxSales / 100 * 8 + SALARY;
	cout << "The best manager's total salary: $" << bestSalary << endl;

	//Task6

	int dayStart, monthStart, yearStart;
	int dayFinish, monthFinish, yearFinish;

	cout << "Enter first day: ";
	cin >> dayStart;
	if (dayStart < 1 || dayStart > 31) {
		cout << "Enter correct date (1-31)" << endl;
	}
	cout << "Enter first month: ";
	cin >> monthStart;
	if (monthStart < 1 || monthStart > 12) {
		cout << "Enter correct date (1-12)" << endl;
		
	}
	cout << "Enter first year: ";
	cin >> yearStart;

	cout << "Enter end day: ";
	cin >> dayFinish;
	if (dayFinish < 1 || dayFinish > 31) {
		cout << "Enter correct date (1-31)" << endl;
	}
	cout << "Enter end month: ";
	cin >> monthFinish;
	if (monthFinish < 1 || monthFinish > 12) {
		cout << "Enter correct date (1-12)" << endl;
	} 
	cout << "Enter end year: ";
	cin >> yearFinish;

	cout << "First date: " << dayStart << "/" << monthStart << "/" << yearStart << endl;
	cout << "End date: " << dayFinish << "/" << monthFinish << "/" << yearFinish << endl;

	int date1 = dayFinish - dayStart;
	int date2 = monthFinish - monthStart;
	int date3 = yearFinish - yearStart;

	if (date1 < 0)
	{
		date2--;
		date1 += 31;
	}
	if (date2 < 0)
	{
		date3--;
		date2 += 12;
	}
	cout << "Difference between dates: " << abs(date1) << " days, " << abs(date2) << " months, " << abs(date3) << " years" << endl;
		
}