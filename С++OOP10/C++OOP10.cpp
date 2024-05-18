#include <iostream>
#include <iostream>
using namespace std;

class Pet
{
protected:
	string name;
	string type;
	string voice;
public:
	Pet() : name("no name"), type("no type"), voice("no voice") {}
	Pet(string name, string type, string voice) : name(name), type(type), voice(voice) {}

	virtual	void Sound() const = 0;
	virtual	void Show() const = 0;
	virtual	void Type() const = 0;

	void setName(string name)
	{
		this->name = name;
	}
	void setType(string type)
	{
		this->type = type;
	}
	void setVoice(string voice)
	{
		this->voice = voice;
	}

	string getName() const
	{
		return name;
	}
	string getType() const
	{
		return type;
	}
	string getVoice() const
	{
		return voice;
	}
};

class Dog : public Pet
{
public:
	Dog() : Pet() {}
	Dog(string name, string type, string voice) : Pet(name, type, voice) {}

	void Sound() const override
	{
		cout << voice << endl;
	}
	void Show() const override
	{
		cout << "Name : " << name << endl;
	}
	void Type() const override
	{
		cout << "Type : " << type << endl;
	}
};

class Cat : public Pet
{
public:
	Cat() : Pet() {}
	Cat(string name, string type, string voice) : Pet(name, type, voice) {}

	void Sound() const override
	{
		cout << voice << endl;
	}
	void Show() const override
	{
		cout << "Name : " << name << endl;
	}
	void Type() const override
	{
		cout << "Type : " << type << endl;
	}
};

class Parrot : public Pet
{
public:
	Parrot() : Pet() {}
	Parrot(string name, string type, string voice) : Pet(name, type, voice) {}

	void Sound() const override
	{
		cout << voice << endl;
	}
	void Show() const override
	{
		cout << "Name : " << name << endl;
	}
	void Type() const override
	{
		cout << "Type : " << type << endl;
	}
};

int main()
{
	Dog myDog("Patron", "Jack Russell Terrier", "Woof woof!");
	Cat myCat("Tigra", "Tabby redhead", "Meow meow!");
	Parrot myParrot("Blu", "Ara blue", "Squawk squawk!");

	cout << "Dog Info:" << endl;
	myDog.Show();
	myDog.Sound();
	myDog.Type();

	cout << "\nCat Info:" << endl;
	myCat.Show();
	myCat.Sound();
	myCat.Type();

	cout << "\nParrot Info:" << endl;
	myParrot.Show();
	myParrot.Sound();
	myParrot.Type();
}