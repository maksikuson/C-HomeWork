#include <iostream>
using namespace std;

//Task 1

class Overcoat
{
	string type;
	int size;
	int price;
public:
	Overcoat(string type, int size, int price) :type{ type }, size{ size }, price{ price } {}
    
	void Show()const
	{
		cout << "Overcoat Information:" << endl;
		cout << "Type: " << type << endl;
		cout << "Size: " << size << endl;
		cout << "Price: $" << price << endl;
	}

	Overcoat& operator=(Overcoat& other)
	{
		this->size = other.size;
		return *this;
	}

	friend bool operator==(const Overcoat& o1, const Overcoat& o2);
	friend bool operator>(const Overcoat& o1, const Overcoat& o2);
};

bool operator==(const Overcoat& o1, const Overcoat& o2)
{
	return o1.type == o2.type;
}

bool operator>(const Overcoat& o1, const Overcoat& o2)
{
	return o1.price > o2.price;
}

//Task 2

class Flat
{
	float area;
	int object;
	int price1;
public:
	Flat(float area, int object, int price1) :area{ area }, object{ object }, price1{ price1 } {}

	void Show1()const
	{
		cout << "Flat Information:" << endl;
		cout << "Area: " << area << endl;
		cout << "Object: " << object << endl;
		cout << "Price: $" << price1 << endl;
	}
	Flat& operator=(Flat& other)
	{
		this->object = other.object;
		return *this;
	}

	friend bool operator==(const Flat& f1, const Flat& f2);
	friend bool operator>(const Flat& f1, const Flat& f2);
};

bool operator==(const Flat& f1, const Flat& f2)
{
	return f1.area == f2.area;
}

bool operator>(const Flat& f1, const Flat& f2)
{
	return f1.price1 > f2.price1;
}


int main()
{
	//Task 1

	Overcoat o1("Top", 31, 4);
	o1.Show();
	Overcoat o2("Top", 22, 4);
	o2.Show();
	o1 = o2;
	cout << "New size: ";
	o1.Show();

	bool abc = o1 == o2;
	cout << "If you see 1 - type are the same, 0 - type aren't the same: " << abc << endl;

	cout << "__________________________________________________________" << endl;

	cout << "Result of comparison:" << endl;
	cout << "Type comparison result: " << (abc ? "Type are the same" : "Type aren't the same") << endl;
	cout << "Price comparison result: " << (o1 > o2 ? "Top1 more expensive" : "Top1 the cheapest") << endl;

	//Task 2

	Flat f1(32.3, 31, 4);
	f1.Show1();
	Flat f2(33.4, 22, 4);
	f2.Show1();

	f1 = f2;
	cout << "New object: ";
	f1.Show1();

	bool abc1 = f1 == f2;
	cout << "If you see 1 - type are the same, 0 - type aren't the same: " << abc1 << endl;

	if (f1 > f2)
	{
		cout << "Flat1 more expencive";
	}
	else
	{
		cout << "Flat1 the cheapest";
	}
}


