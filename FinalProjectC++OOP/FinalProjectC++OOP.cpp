#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>


using namespace std;

class Student 
{
private:
    string name;
    int id;
    int age;
    string major;

public:
    Student(const string& name, int id, int age, const string& major) : name(name), id(id), age(age), major(major) {}

    string getName() const { return name; }
    int getId() const { return id; }
    int getAge() const { return age; }
    string getMajor() const { return major; }

    void setName(const string& name) { this->name = name; }
    void setId(int id) { this->id = id; }
    void setAge(int age) { this->age = age; }
    void setMajor(const string& major) { this->major = major; }

    void print() const 
    {
        cout << "Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Age: " << age << endl;
        cout << "Major: " << major << endl;
    }
};

class StudentDatabase
{
private:
    vector<Student> students;
    set<string> uniqueMajors;

public:

    void addStudent(const Student& student)
    {
        students.push_back(student);
        uniqueMajors.insert(student.getMajor());
    }

    void removeStudent(int id)
    {
        auto it = find_if(students.begin(), students.end(), [id](const Student& s) { return s.getId() == id; });
        if (it != students.end())
        {
            students.erase(it);
            cout << "Student with ID " << id << " has been successfully removed." << endl;
        }
        else
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    bool findStudentById(int id, Student& foundStudent) const
    {
        for (const auto& student : students)
        {
            if (student.getId() == id)
            {
                foundStudent = student;
                return true;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
        return false;
    }

    void listStudents() const
    {
        for (const auto& student : students)
        {
            student.print();
        }
    }

    void saveToFile(const string& filename) const
    {
        ofstream file(filename);
        if (file.is_open())
        {
            for (const auto& student : students)
            {
                file << student.getId() << "," << student.getName() << "," << student.getAge() << "," << student.getMajor() << endl;
            }
            file.close();
        }
        else
        {
            cerr << "Unable to open file " << filename << endl;
        }
    }

    void loadFromFile(const string& filename)
    {
        ifstream file(filename);
        if (file.is_open())
        {
            int id, age;
            string name, major;
            while (file >> id)
            {
                file.ignore();
                getline(file, name, ',');
                file >> age;
                file.ignore();
                getline(file, major);
                addStudent(Student(name, id, age, major));
            }
            file.close();
        }
        else
        {
            cerr << "Unable to open file " << filename << endl;
        }
    }

    void updateStudent(int id, const Student& newData)
    {
        auto it = find_if(students.begin(), students.end(), [id](const Student& s) { return s.getId() == id; });
        if (it != students.end())
        {
            it->setName(newData.getName());
            it->setAge(newData.getAge());
            it->setMajor(newData.getMajor());
        }
    }


    void filterByMajor(const string& major) const
    {
        for (const auto& student : students)
        {
            if (student.getMajor() == major)
            {
                student.print();
            }
        }
    }

    void listUniqueMajors() const
    {
        for (const auto& major : uniqueMajors)
        {
            cout << major << endl;
        }
    }

    void menu() 
    {
        StudentDatabase db;

        int choice;

        while (true)
        {
            cout << "========================================" << endl;
            cout << "             MAIN MENU                 |" << endl;
            cout << "========================================" << endl;
            cout << "1. Add student                         | " << endl;
            cout << "2. Remove student                      | " << endl;
            cout << "3. Search student by ID                | " << endl;
            cout << "4. List all students                   | " << endl;
            cout << "5. Save data to file                   | " << endl;
            cout << "6. Load data from file                 | " << endl;
            cout << "7. Update student data                 |" << endl;
            cout << "8. Filter students by major            | " << endl;
            cout << "9. Exit                                | " << endl;
            cout << "========================================" << endl;
            cout << "Enter option: ";
            cin >> choice;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice)
            {
            case 1:
            {
                string name, major;
                int id, age;
                cout << "Enter student name: ";
                getline(cin, name);
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student age: ";
                cin >> age;
                cout << "Enter student major: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, major);
                db.addStudent(Student(name, id, age, major));
                break;
            }
            case 2:
            {
                int id;
                cout << "Enter student ID: ";
                cin >> id;
                db.removeStudent(id);
                break;
            }
            case 3:
            {
                int id;
                cout << "Enter student ID: ";
                cin >> id;
                Student foundStudent("", -1, -1, "");
                if (db.findStudentById(id, foundStudent))
                {
                    foundStudent.print();
                }
                break;
            }
            case 4:
                db.listStudents();
                break;
            case 5:
            {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                db.saveToFile(filename);
                break;
            }
            case 6:
            {
                string filename;
                cout << "Enter filename: ";
                cin >> filename;
                db.loadFromFile(filename);
                break;
            }
            case 7:
            {
                int id;
                cout << "Enter student ID: ";
                cin >> id;
                string name, major;
                int age;
                cout << "Enter new student name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, name);
                cout << "Enter new student age: ";
                cin >> age;
                cout << "Enter new student major: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, major);
                Student newData(name, id, age, major);
                db.updateStudent(id, newData);
                break;
            }
            case 8:
            {
                string major;
                cout << "Enter major: ";
                cin >> major;
                db.filterByMajor(major);
                break;
            }
            case 9:
                return;
            default:
                cout << "Invalid choice" << endl;
            }
        }
    }
};

int main()
{
    StudentDatabase sdt;
    sdt.menu();
}

