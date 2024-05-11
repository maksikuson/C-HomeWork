#include <iostream>
using namespace std;

struct Node 
{
    int value;      
    Node* next;     
    Node* prev;     
    Node(int value, Node* next, Node* prev) : value{ value }, next{ next }, prev{ prev } {}
};

// Клас List для представлення двунаправленого списку
class List
{
    Node* head; // Вказівник на голову списку
    Node* tail; // Вказівник на хвіст списку

public:
    // Конструктор за замовчуванням
    List() : head(nullptr), tail(nullptr) {}

    // Конструктор зі списком значень
    List(const initializer_list<int>& values) : head(nullptr), tail(nullptr)
    {
        for (int val : values)
        {
            AddToTail(val);
        }
    }

    // Виведення всього списку
    void PrintAll() const
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    //  Додавання елемента на початок списку
    void AddToHead(int value)
    {
        Node* newNode = new Node(value, head, nullptr);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
        }
    }

    // Додавання елемента в кінець списку
    void AddToTail(int value)
    {
        Node* newNode = new Node(value, nullptr, tail);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Видалення вузла з вказаним значенням зі списку
    void DeleteByValue(int value)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->value == value)
            {
                if (current == head)
                {
                    head = current->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                    delete current;
                    return;
                }
                else if (current == tail)
                {
                    tail = current->prev;
                    tail->next = nullptr;
                    delete current;
                    return;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    return;
                }
            }
            current = current->next;
        }
        cout << "Value not found!" << endl;
    }

    // Видалення всіх дублікатів у списку
    void RemoveDuplicates()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* runner = current->next;
            while (runner != nullptr)
            {
                if (runner->value == current->value)
                {
                    Node* temp = runner;
                    runner->prev->next = runner->next;
                    if (runner->next != nullptr)
                        runner->next->prev = runner->prev;
                    runner = runner->next;
                    delete temp;
                }
                else
                {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    // Пошук максимального значення у списку
    int FindMax()const 
    {
        int maxVal = head->value;
        Node* current = head->next;
        while (current != nullptr) 
        {
            if (current->value > maxVal) 
            {
                maxVal = current->value;
            }
            current = current->next;
        }
        return maxVal;
    }

    // Пошук мінімального значення у списку
    int FindMin() const 
    {
        int minVal = head->value;
        Node* current = head->next;
        while (current != nullptr) 
        {
            if (current->value < minVal) 
            {
                minVal = current->value;
            }
            current = current->next;
        }
        return minVal;
    }

    // Оператор доступу за індексом для отримання значення вузла за певним індексом
    int operator[](int index)const
    {
        if (index < 0)
        {
            cout << "Index must be non-negative!" << endl;
            return -1;
        }

        Node* current = head;
        int count = 0;
        while (current != nullptr)
        {
            if (count == index)
            {
                return current->value;
            }
            current = current->next;
            count++;
        }

        cout << "Index out of range!" << endl;
        return -1;
    }

    // Перевірка на пустоту списку
    bool IsEmpty() const
    {
        return head == nullptr;
    }

    // Деструктор який видаляє всі вузли списку
    ~List()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main()
{
    List list1;

    // Додавання значень до списку
    list1.AddToHead(104);
    list1.AddToHead(123);
    list1.AddToHead(231);
    list1.AddToHead(11);

    list1.AddToTail(111);
    list1.AddToTail(112);
    list1.AddToTail(113);
    list1.AddToTail(114);
    list1.AddToTail(112);
    list1.PrintAll();

    // Видалення вузла з певним значенням зі списку
    list1.DeleteByValue(111);
    list1.PrintAll();
    list1.DeleteByValue(1);
    list1.PrintAll();

    // Видалення всіх дублікатів у списку
    list1.RemoveDuplicates();
    list1.PrintAll();

    // Виведення максимального та мінімального значень у списку
    cout << list1.FindMax() << endl;
    cout << list1.FindMin() << endl;

    // Виведення значення вузла за певним індексом
    list1[2];
    list1.PrintAll();
}