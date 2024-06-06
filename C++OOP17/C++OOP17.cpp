#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Car 
{
private:
    string name;
    int year;
    int engineCapacity;
    double price;

public:
    Car() : name("no name"), year(0), engineCapacity(0), price(0.0) {}
    Car(string nameC, int yearC, int engineCapacityC, double priceC) : name(nameC), year(yearC), engineCapacity(engineCapacityC), price(priceC) {}

    string getName() const { return name; }
    int getYear() const { return year; }
    int getEngineCapacity() const { return engineCapacity; }
    double getPrice() const { return price; }

    void setName(const string& nameC) { name = nameC; }
    void setYear(int yearC) { year = yearC; }
    void setEngineCapacity(int engineCapacityC) { engineCapacity = engineCapacityC; }
    void setPrice(double priceC) { price = priceC; }
};

class CarDealership 
{
private:
    vector<Car> cars;

public:
    void addCar(const Car& car) 
    {
        cars.push_back(car);
    }

    bool removeCar(const string& name) 
    {
        auto it = find_if(cars.begin(), cars.end(),
            [&name](const Car& car) { return car.getName() == name; });

        if (it != cars.end()) 
        {
            cars.erase(it);
            return true;
        }
        return false;
    }

    void displayCar(const Car& car) const
    {
        cout << "Name: " << car.getName() << endl;
        cout << "Year: " << car.getYear() << endl;
        cout << "Engine capacity: " << car.getEngineCapacity() << endl;
        cout << "Price: " << car.getPrice() << endl;
        cout << "-------------------------" << endl;
    }

    void displayCars() const 
    {
        for (const Car& car : cars)
        {
            displayCar(car);
        }
    }

    void sortCarsByName() 
    {
        sort(cars.begin(), cars.end(),
            [](const Car& a, const Car& b) { return a.getName() < b.getName(); });
    }

    void sortCarsByYear()
    {
        sort(cars.begin(), cars.end(),
            [](const Car& a, const Car& b) { return a.getYear() < b.getYear(); });
    }

    void sortCarsByEngineCapacity()
    {
        sort(cars.begin(), cars.end(),
            [](const Car& a, const Car& b) { return a.getEngineCapacity() < b.getEngineCapacity(); });
    }

    void sortCarsByPrice()
    {
        sort(cars.begin(), cars.end(),
            [](const Car& a, const Car& b) { return a.getPrice() < b.getPrice(); });
    }

    vector<Car> searchCarsByName(const string& name) const
    {
        vector<Car> results;
        string lowerName = toLower(name);
        copy_if(cars.begin(), cars.end(), back_inserter(results),
            [this, &lowerName](const Car& car) { return toLower(car.getName()) == lowerName; });
        return results;
    }

    vector<Car> searchCarsByYear(int year) const
    {
        vector<Car> results;
        copy_if(cars.begin(), cars.end(), back_inserter(results),
            [&year](const Car& car) { return car.getYear() == year; });
        return results;
    }

    vector<Car> searchCarsByEngineCapacity(int engineCapacity) const
    {
        vector<Car> results;
        copy_if(cars.begin(), cars.end(), back_inserter(results),
            [&engineCapacity](const Car& car) { return car.getEngineCapacity() == engineCapacity; });
        return results;
    }

    vector<Car> searchCarsByPrice(double price) const 
    {
        vector<Car> results;
        copy_if(cars.begin(), cars.end(), back_inserter(results),
            [&price](const Car& car) { return car.getPrice() == price; });
        return results;
    }

    string toLower(const string& str) const 
    {
        string lowerStr = str;
        transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    }
};

void addSampleCars(CarDealership& dealership)
{
    Car car1("Toyota", 2015, 2000, 15000.0);
    Car car2("Honda", 2018, 2500, 20000.0);
    Car car3("Ford", 2020, 3000, 25000.0);

    dealership.addCar(car1);
    dealership.addCar(car2);
    dealership.addCar(car3);
}

void displaySearchResults(const vector<Car>& results)
{
    for (const Car& car : results)
    {
        cout << "Name: " << car.getName() << endl;
        cout << "Year: " << car.getYear() << endl;
        cout << "Engine capacity: " << car.getEngineCapacity() << endl;
        cout << "Price: " << car.getPrice() << endl;
        cout << "-------------------------" << endl;
    }
}

int main()
{
    CarDealership dealership;

    addSampleCars(dealership);

    cout << "All cars:" << endl;
    dealership.displayCars();

    cout << "Cars sorted by year:" << endl;
    dealership.sortCarsByYear();
    dealership.displayCars();

    cout << "Search results for cars with price 20000.0:" << endl;
    vector<Car> results = dealership.searchCarsByPrice(20000.0);
    displaySearchResults(results);

    bool removed = dealership.removeCar("Ford");
    cout << "Car removed: " << (removed ? "true" : "false") << endl;

    cout << "All cars after removal:" << endl;
    dealership.displayCars();
}