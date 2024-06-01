#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Station
{
    int numberTrain;
    string time;
    string place;
public:
    Station()
    {
        numberTrain = 0;
        time = "No time";
        place = "No place";
    }

    Station(int num, string t, string p)
    {
        numberTrain = num;
        time = t;
        place = p;
    }

    void setNumberTrain(int num) 
    {
        numberTrain = num;
    }

    void setTime(string t) 
    {
        time = t;
    }

    void setPlace(string p) 
    {
        place = p;
    }

    int getNumberTrain()const 
    {
        return numberTrain;
    }

    string getTime()const 
    {
        return time;
    }

    string getPlace()const 
    {
        return place;
    }

    friend ostream& operator<<(ostream& os, const Station& station)
    {
        os << station.numberTrain << " " << station.time << " " << station.place;
        return os;
    }

    friend istream& operator>>(istream& is, Station& station)
    {
        is >> station.numberTrain >> station.time >> station.place;
        return is;
    }
};

void writeToFile(const vector<Station>& stations, const string& filename)
{
    ofstream file(filename, ios::trunc);
    if (!file)
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    for (const auto& station : stations)
    {
        file << station << endl;
    }
    file.close();
}

void readFromFile(vector<Station>& stations, const string& filename)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    Station station;
    while (file >> station)
    {
        stations.push_back(station);
    }
    file.close();
}

void editTrainTime(vector<Station>& stations, int trainNumber, const string& newTime)
{
    for (auto& station : stations)
    {
        if (station.getNumberTrain() == trainNumber)
        {
            station.setTime(newTime);
            cout << "Time updated successfully." << endl;
            return;
        }
    }
    cout << "Train not found." << endl;
}

void sortTrainsByDepartureTime(vector<Station>& stations)
{
    sort(stations.begin(), stations.end(), [](const Station& a, const Station& b) 
        {
        return a.getTime() < b.getTime();
        });
    cout << "Trains sorted by departure time." << endl;
}

void displayTrainsByDestination(const vector<Station>& stations, const string& destination)
{
    for (const auto& station : stations)
    {
        if (station.getPlace() == destination)
        {
            cout << "Number: " << station.getNumberTrain() << endl;
            cout << "Time: " << station.getTime() << endl;
            cout << "Place: " << station.getPlace() << endl;
            cout << "------------------------" << endl;
        }
    }
}

void menu(vector <Station>& stations)
{
    int choice;
    while (true) 
    {
        cout << "Menu: " << endl;
        cout << "1. Add train " << endl;
        cout << "2. Show all " << endl;
        cout << "3. Search by number of train" << endl;
        cout << "4. Edit train time by number" << endl;
        cout << "5. Sort trains by departure time" << endl;
        cout << "6. Show trains by destination" << endl;
        cout << "7. Save to file" << endl;
        cout << "8. Load from file" << endl;
        cout << "9. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int num;
            string time, place;

            cout << "Enter number of train: ";
            cin >> num;
            cout << "Enter time (HH:MM): ";
            cin >> time;
            cout << "Enter place: ";
            cin >> place;

            stations.emplace_back(num, time, place);
            break;
        }
        case 2:
        {
            cout << "All trains:" << endl;
            for (const auto& s : stations)
            {
                cout << "Number of train: " << s.getNumberTrain() << endl;
                cout << "Time: " << s.getTime() << endl;
                cout << "Place: " << s.getPlace() << endl;
                cout << "------------------------" << endl;
            }
            break;
        }
        case 3:
        {
            int trainNumber;
            cout << "Enter number of train: ";
            cin >> trainNumber;

            bool found = false;
            for (const auto& s : stations)
            {
                if (s.getNumberTrain() == trainNumber)
                {
                    cout << "Number: " << s.getNumberTrain() << endl;
                    cout << "Time: " << s.getTime() << endl;
                    cout << "Place: " << s.getPlace() << endl;
                    cout << "------------------------" << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "No train found." << endl;
            }
            break;
        }
        case 4:
        {
            int trainNumber;
            string newTime;

            cout << "Enter number of train: ";
            cin >> trainNumber;
            cout << "Enter new time (HH:MM): ";
            cin >> newTime;

            editTrainTime(stations, trainNumber, newTime);
            break;
        }
        case 5:
        {
            sortTrainsByDepartureTime(stations);
            break;
        }
        case 6: 
        {
            string destination;
            cout << "Enter destination: ";
            cin >> destination;

            displayTrainsByDestination(stations, destination);
            break;
        }
        case 7: 
        {
            writeToFile(stations, "trains.txt");
            break;
        }
        case 8:
        {
            readFromFile(stations, "trains.txt");
            break;
        }
        case 9:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main()
{
    vector<Station> stations;
    readFromFile(stations, "trains.txt");

    menu(stations);
}