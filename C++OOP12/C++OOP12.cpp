#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

//************************TASK1************************

class Equation
{
public:
	virtual void solve() = 0;
};

class LinearEquation : public Equation 
{
private:
    double a, b;

public:
    LinearEquation(double a_val, double b_val) : a(a_val), b(b_val) {}

    void solve() override 
    {
        if (a == 0) 
        {
            if (b == 0)
                cout << "The equation has infinitely many solutions" << endl;
            else
                cout << "The equation has no solution" << endl;
        }
        else 
        {
            double x = -b / a;
            cout << "Solution: x = " << x << endl;
        }
    }
};

class QuadraticEquation : public Equation
{
private:
    double a, b, c;

public:
    QuadraticEquation(double a_val, double b_val, double c_val) : a(a_val), b(b_val), c(c_val) {}

    void solve() override
    {
        if (a == 0) 
        {
            LinearEquation linear(b, c);
            linear.solve();
        }
        else 
        {
            double discriminant = b * b - 4 * a * c;

            if (discriminant > 0) 
            {
                double x1 = (-b + sqrt(discriminant)) / (2 * a);
                double x2 = (-b - sqrt(discriminant)) / (2 * a);
                cout << "Solutions: x1 = " << x1 << ", x2 = " << x2 << endl;
            }
            else if (discriminant == 0) 
            {
                double x = -b / (2 * a);
                cout << "The equation has one real solution x = " << x << endl;
            }
            else 
            {
                cout << "The equation has no real solutions" << endl;
            }
        }
    }
};

//************************TASK2************************

class Shape
{
public:
    virtual void Show() const = 0;
    virtual void Save(ofstream& file) const = 0;
    virtual void Load(ifstream& file) = 0;
    virtual ~Shape() {}
};

class Square : public Shape
{
private:
    int topLeftX, topLeftY;
    int sideLength;
public:
    Square(int x, int y, int length) : topLeftX(x), topLeftY(y), sideLength(length) {}

    void Show() const override 
    {
        cout << "Square: Top Left Corner (" << topLeftX << ", " << topLeftY << "), Side Length: " << sideLength << endl;
    }

    void Save(ofstream& file) const override 
    {
        file << "Square " << topLeftX << " " << topLeftY << " " << sideLength << endl;
    }

    void Load(ifstream& file) override
    {
        file >> topLeftX >> topLeftY >> sideLength;
    }
};

void SaveShapes(const vector<Shape*>& shapes, const string& filename) 
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        for (auto shape : shapes)
        {
            shape->Save(outFile);
        }
        outFile.close();
    }
    else 
    {
        cerr << "Unable to open file " << filename << " for writing." << endl;
    }
}


void LoadShapes(vector<Shape*>& shapes, const string& filename)
{
    ifstream inFile(filename);
    if (inFile.is_open()) 
    {
        string type;
        while (inFile >> type) 
        {
            if (type == "Square")
            {
                int x, y, length;
                inFile >> x >> y >> length;
                shapes.push_back(new Square(x, y, length)); 
            }
        }
        inFile.close();
    }
    else 
    {
        cerr << "Unable to open file " << filename << " for reading." << endl;
    }
}

int main()
{
    //Task 1

    /*QuadraticEquation equation1(1, -3, 2);
    equation1.solve();

    QuadraticEquation equation2(1, -2, 5);
    equation2.solve();

    LinearEquation equation3(0, 0);
    equation3.solve();

    LinearEquation equation4(0, 5);
    equation4.solve();*/

    // Task 2

    vector<Shape*> shapes;
    shapes.push_back(new Square(5, 7, 5));

    SaveShapes(shapes, "shapes.txt");

    LoadShapes(shapes, "shapes.txt");

    for (auto shape : shapes)
    {
        shape->Show();
    }

    for (auto shape : shapes) 
    {
        delete shape;
    }
    shapes.clear();

}