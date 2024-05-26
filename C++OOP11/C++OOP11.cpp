#include <iostream>
#include <cstring>
using namespace std;

class Pet 
{
protected:
    string name;
public:
    Pet(string petName) : name(petName) {}

    void display() const 
    {
        cout << "Pet Name: " << name << endl;
    }
};

class Dog : public Pet
{
    string owner;
public:
    Dog(string dogName, string ownerName) : Pet(dogName), owner(ownerName) {}

    void display() const 
    {
        cout << "Dog Name: " << name << endl;
        cout << "Dog's Owner: " << owner << endl;
    }
};

class Cat : public Pet 
{
    string ownerC;
public:
    Cat(string catName, string ownerCatName) : Pet(catName), ownerC(ownerCatName) {}

    void display() const 
    {
        cout << "Cat Name: " << name << endl;
        cout << "Cat's Owner: " << ownerC << endl;
    }
};

class Parrot : public Pet
{
    string ownerP;
public:
    Parrot(string parrotName, string ownerPname) : Pet(parrotName), ownerP(ownerPname) {}

    void display() const 
    {
        cout << "Parrot Name: " << name << endl;
        cout << "Parrot's Owner: " << ownerP << endl;
    }
};

class String
{
protected:
    char* str;
    size_t length;
public:
    String() : str(new char[1] {'\0'}), length(0) {}

    String(const char* str) 
    {
        length = strlen(str);
        this->str = new char[length + 1];
        strcpy_s(this->str, length + 1, str);
    }

    String(const String& other) : length(other.length)
    {
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }

    String& operator=(const String& other) 
    {
        if (this != &other)
        {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy_s(str, length + 1, other.str);
        }
        return *this;
    }

    size_t getLength() const 
    {
        return length;
    }

    void clear() 
    {
        delete[] str;
        str = new char[1] {'\0'};
        length = 0;
    }

    ~String() 
    {
        delete[] str;
    }

    String operator+(const String& other) const
    {
        size_t newLength = length + other.length;
        char* newStr = new char[newLength + 1];
        strcpy_s(newStr, newLength + 1, str);
        strcat_s(newStr, newLength + 1, other.str);

        String result(newStr);
        delete[] newStr;

        return result;
    }

    bool operator==(const String& other) const 
    {
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const String& other) const 
    {
        return !(*this == other);
    }

    void show() const 
    {
        cout << "Length: " << length << endl;
        cout << "String: " << str << endl;
    }
};

class BinaryString : public String
{
public:
    BinaryString() : String("00000") {}

    BinaryString(const char* str) : String() 
    {
        bool isValid = true;
        for (size_t i = 0; i < strlen(str); ++i) 
        {
            if (str[i] != '0' && str[i] != '1')
            {
                isValid = false;
                break;
            }
        }
        if (isValid)
        {
            delete[] this->str;
            length = strlen(str);
            this->str = new char[length + 1];
            strcpy_s(this->str, length + 1, str);
        }
        else
        {
            this->str = new char[1] {'\0'};
            length = 0;
        }
    }

    void negate() 
    {
        for (size_t i = 0; i < length; ++i)
        {
            str[i] = (str[i] == '0') ? '1' : '0';
        }

        for (int i = length - 1; i >= 0; --i) 
        {
            if (str[i] == '0')
            {
                str[i] = '1';
                break;
            }
            else 
            {
                str[i] = '0';
            }
        }
    }

    int toInteger() const 
    {
        int result = 0;
        for (size_t i = 0; i < length; ++i)
        {
            result = (result << 1) + (str[i] - '0');
        }
        return result;
    }

    void show() const
    {
        cout << "Binary String: " << str << endl;
    }
};

void displayPets() 
{
    Pet p1("My Pet");
    p1.display();

    Dog d1("Patron", "Maksik");
    d1.display();

    Cat c1("Tigra", "Maxim");
    c1.display();

    Parrot per1("Blu", "Maksimiliano");
    per1.display();
}

void stringOperations() 
{
    String st1("Hello my world");
    cout << "Length: " << st1.getLength() << endl;
    st1.show();
    st1.clear();
    st1.show();

    String S1("Hello,");
    String S2(" Teacher");
    String S3 = S1 + S2;
    S3.show();

    String s1("Hello");
    String s2("Hello");
    String s3("World");

    if (s1 == s2)
    {
        cout << "s1 and s2 are equal" << endl;
    }
    else 
    {
        cout << "s1 and s2 are not equal" << endl;
    }

    if (s1 == s3)
    {
        cout << "s1 and s3 are equal" << endl;
    }
    else 
    {
        cout << "s1 and s3 are not equal" << endl;
    }
}

void binaryStringOperations()
{
    BinaryString bs1("101010");
    bs1.show();
    cout << "Integer value: " << bs1.toInteger() << endl;

    BinaryString bs2("1010201");
    bs2.show();
}

int main()
{
    displayPets();
    cout << "*****************************" << endl;
    stringOperations();
    cout << "*****************************" << endl;
    binaryStringOperations();
}