#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;


//Task 1


void addColumn(int**& matrix, int numRows, int& numCols, int colPosition, int defaultValue)
{
    int** newMatrix = new int* [numRows];
    for (int i = 0; i < numRows; i++)
    {
        newMatrix[i] = new int[numCols + 1];
    }
    if (newMatrix == nullptr)
    {
        cerr << "Failed to allocate memory." << endl;
        return;
    }
    for (int i = 0; i < numRows; i++)
    {
        int col = 0;
        for (col = 0; col < colPosition; col++)
        {
            newMatrix[i][col] = matrix[i][col];
        }
        newMatrix[i][col] = defaultValue;
        for (col = colPosition; col < numCols; col++)
        {
            newMatrix[i][col + 1] = matrix[i][col];
        }
    }
    for (int i = 0; i < numRows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = newMatrix;
    numCols++;
}


//Task 2


void deleteColumn(int**& matrix, int numRows, int numCols, int columnToDelete)
{
    if (columnToDelete < 0 || columnToDelete >= numCols)
    {
        cout << "Invalid column index!" << endl;
        return;
    }

    int** newMatrix = new int* [numRows];
    for (int i = 0; i < numRows; i++)
    {
        newMatrix[i] = new int[numCols - 1];
    }

    for (int i = 0; i < numRows; i++)
    {
        int colIndex = 0;
        for (int j = 0; j < numCols; j++)
        {
            if (j != columnToDelete)
            {
                newMatrix[i][colIndex] = matrix[i][j];
                colIndex++;
            }
        }
    }

    for (int i = 0; i < numRows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;

    matrix = newMatrix;
}


//Task 3


void cycleShift(int** matrix, int rows, int columns, int shiftCount, bool shiftRows, bool shiftRight) 
{
    if (shiftRows) {
        for (int i = 0; i < rows; i++) {
            int* tempRow = new int[columns](); 
            for (int j = 0; j < columns; j++) 
            {
                int newIndex = (shiftRight) ? (j + shiftCount) % columns : (j + columns - shiftCount) % columns;
                tempRow[newIndex] = matrix[i][j];
            }
            delete[] matrix[i];
            matrix[i] = tempRow;
        }
    }
    else 
    {
        for (int j = 0; j < columns; j++)
        {
            int* tempColumn = new int[rows]();
            for (int i = 0; i < rows; i++) 
            {
                int newIndex = (shiftRight) ? (i + shiftCount) % rows : (i + rows - shiftCount) % rows;
                tempColumn[newIndex] = matrix[i][j];
            }
            for (int i = 0; i < rows; i++)
            {
                matrix[i][j] = tempColumn[i];
            }
            delete[] tempColumn;
        }
    }
}
void printMatrix(int** matrix, int rows, int columns)
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


//Task 4


void transposeMatrix(int** matrix, int rows, int columns)
{
    int** transposedMatrix = new int* [columns];
    for (int i = 0; i < columns; ++i)
    {
        transposedMatrix[i] = new int[rows]();
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    cout << "Transposed matrix:" << endl;
    for (int i = 0; i < columns; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < columns; ++i)
    {
        delete[] transposedMatrix[i];
    }
    delete[] transposedMatrix;
}


//Task 5


const int MAX_CONTACTS = 100;

struct Contact {
    char name[50];
    char phone[15];
};

Contact contacts[MAX_CONTACTS];
int contactsCount = 0;

void addContact(const char* name, const char* phone) 
{
    if (contactsCount < MAX_CONTACTS) 
    {
        strcpy(contacts[contactsCount].name, name);
        strcpy(contacts[contactsCount].phone, phone);
        contactsCount++;
        cout << "Contact added successfully." << endl;
    }
    else 
    {
        cout << "Cannot add more contacts. Limit reached." << endl;
    }
}

void searchByName(const char* name) 
{
    bool found = false;
    for (int i = 0; i < contactsCount; i++) 
    {
        if (strcmp(contacts[i].name, name) == 0) 
        {
            cout << "Name: " << contacts[i].name << ", Phone: " << contacts[i].phone << endl;
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Contact not found." << endl;
    }
}

void searchByPhone(const char* phone) 
{
    bool found = false;
    for (int i = 0; i < contactsCount; i++) 
    {
        if (strcmp(contacts[i].phone, phone) == 0) 
        {
            cout << "Name: " << contacts[i].name << ", Phone: " << contacts[i].phone << endl;
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Contact not found." << endl;
    }
}


int main() 
{


    //Task 1


    /*int numRows = 3;
    int numCols = 2;
    int** matrix = new int* [numRows];
    for (int i = 0; i < numRows; i++)
    {
        matrix[i] = new int[numCols];
        for (int j = 0; j < numCols; j++)
        {
            matrix[i][j] = i * numCols + j + 1;
        }
    }

    cout << "Initial matrix:" << endl;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    addColumn(matrix, numRows, numCols, 1, 0);

    cout << "Matrix after adding column:" << endl;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < numRows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;*/


    //Task 2


   /* int numRows = 3;
    int numCols = 3;
    int** matrix = new int* [numRows];
    for (int i = 0; i < numRows; i++)
    {
        matrix[i] = new int[numCols];
    }

    int value = 1;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            matrix[i][j] = value++;
        }
    }

    int columnToDelete = 1;
    cout << "Original matrix:" << endl;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    deleteColumn(matrix, numRows, numCols, columnToDelete);

    cout << "Matrix after deleting column " << columnToDelete << ":" << endl;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols - 1; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < numRows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = nullptr;*/


    //Task 3


   /* int rows, columns;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) 
    {
        matrix[i] = new int[columns]();
    }

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j) 
        {
            cin >> matrix[i][j];
        }
    }

    int shiftCount;
    cout << "Enter number of shifts: ";
    cin >> shiftCount;

    bool shiftRows, shiftRight;
    cout << "Shift rows? (1 for yes, 0 for no): ";
    cin >> shiftRows;
    cout << "Shift to the right? (1 for yes, 0 for no): ";
    cin >> shiftRight;

    cycleShift(matrix, rows, columns, shiftCount, shiftRows, shiftRight);

    cout << "Matrix after cyclic shift:" << endl;
    printMatrix(matrix, rows, columns);

    for (int i = 0; i < rows; ++i) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;*/

 
   //Task 4


   /* int rows, columns;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[columns];
        for (int j = 0; j < columns; ++j) 
        {
            matrix[i][j] = 0;
        }
    }
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    transposeMatrix(matrix, rows, columns);

    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;*/


   //Task 5


    char choice;
    do {
        cout << "Menu:\n";
        cout << "1. Add contact\n";
        cout << "2. Search by name\n";
        cout << "3. Search by phone\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case '1': 
        {
                char name[50], phone[15];
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone: ";
                cin >> phone;
                addContact(name, phone);
                break;
            }
            case '2': 
            {
                char name[50];
                cout << "Enter the name you want to search : ";
                cin >> name;
                searchByName(name);
                break;
            }
            case '3': 
            {
                char phone[15];
                cout << "Enter the phone you want to search : ";
                cin >> phone;
                searchByPhone(phone);
                break;
            }
            case '4': 
            {
                cout << "Exiting program.";
                break;
            }
            default:
                cout << "ERROR";
        }
    } while (choice != '4');
}
