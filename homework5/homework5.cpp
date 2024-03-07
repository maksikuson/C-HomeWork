#include <iostream>
using namespace std;

int main()
{
	//Task1
	int a;
	int sum = 0;

	cout << "Enter first number: ";
	cin >> a;

	for (int i = a; i <= 500; i++)
	{
		sum += i;
	}

	cout << "Sum of numbers from " << a << " to 500: " << sum << endl;

	//Task2
	int x, y;
	int result = 1;

	cout << "Enter the x: ";
	cin >> x;

	cout << "Enter the exponent y: ";
	cin >> y;

	for (int i = 0; i < y; i++)
	{
		result *= x;
	}
		
	cout << x << " Raised to the exponent " << y << " is: " << result << endl;

	//Task3
	int sum1 = 0;
	int count = 0;

	for (int i = 1; i <= 1000; i++)
	{
		sum1 += i;
		count++;
	}
	double average = sum / double(count);

	cout << "Average of numbers from 1 to 1000 is: " << average << endl;

	//Task4
	int a1, product = 1;

	cout << "Enter a number from 1 to 20: ";
	cin >> a1;

	for (int i = a1; i <= 20; ++i)
	{
		product *= i;
	}

	cout << "Product of numbers from " << a << " to 20: " << product << endl;

	//Task5
	int k;

	cout << "Enter the variant number: ";
	cin >> k;

	for (int i = 2; i <= 10; ++i)
	{
		cout << k << " x " << i << " = " << k * i << endl;
	}

	//Task6
	int counts = 0;

	for (int num = 100; num <= 999; ++num)
	{
		int hundreds = num / 100;
		int tens = (num / 10) % 10;
		int units = num % 10;

		if (hundreds == tens || hundreds == units || tens == units)
		{
			counts++;
		}
	}

	cout << "Total numbers with at least two identical digits: " << counts << endl;

	//Task7
	int countss = 0;
	int hundreds1, tens1, ones1;

	cout << "Count of numbers with all different digits: ";

	for (int i = 100; i < 1000; i++)
	{
		hundreds1 = i / 100;
		tens1 = (i / 10) % 10;
		ones1 = i % 10;

		if ((hundreds1 != tens1) && (hundreds1 != ones1) && (tens1 != ones1))
		{
			countss++;
		}
	}

	//Task8
	int number;
	cout << "Enter an integer: ";
	cin >> number;

	int result1 = 0;
	int multiplier = 1;

	while (number > 0)
	{
		int digit1 = number % 10;
		number /= 10;

		if (digit1 != 3 && digit1 != 6)
		{
			result1 += digit1 * multiplier;
			multiplier *= 10;
		}
	}

	cout << "Number with all 3s and 6s removed: " << result1 << endl;

	//Task9
	int A1;

	cout << "Enter A : " << endl;
	cin >> A1;

	for (size_t B1 = 1; B1 < 5000; B1++)
	{
		if (A1 % (B1 * B1) == 0 && A1 % (B1 * B1 * B1) != 0)
		{
			cout << B1 << " ";
		}
	}

	//Task10
	int A2; int number2;
	int sum2 = 0;

	cout << "Enter A : " << endl;
	cin >> A2;
	do
	{
		number2 = A2 % 10;
		sum2 += number2;
		A2 /= 10;
	} while (number2 > 0);
	cout << sum << endl;
	A2* A2 == sum2 * sum2 * sum2 ? cout << true << endl : cout << false << endl;

	//Task11
	int n;

	cout << "Enter a number: ";
	cin >> n;
	cout << "Multiples of " << n << ": ";

	for (int i = 0; i <= 99; i++) {
		if (i % n == 0) {
			cout << i << " ";
		}
	}

	cout << endl;

	//Task12
	int n1, n2;
	int num1, num2;

	cout << "Enter two integers: ";
	cin >> num1 >> num2;
	cout << "Common divisors of " << num1 << " and " << num2 << ": ";

	for (int i = 1; i <= min(num1, num2); i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			cout << i << " ";
		}
	}

	cout << endl;
}