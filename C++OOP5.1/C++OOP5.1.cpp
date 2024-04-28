#include <iostream>
using namespace std;

template <typename T>
class Array
{
private:
    T* data;
    int size;
    int capacity;
    int grow;

public:
    Array(int grow = 1)
        : data(nullptr), size(0), capacity(0), grow(grow) {}

    ~Array()
    {
        delete[] data;
    }

    int GetSize() const
    {
        return size;
    }

    void SetSize(int newSize, int growSize = 1)
    {
        if (newSize > capacity)
        {
            int newCapacity = ((newSize - capacity + growSize - 1) / growSize) * growSize + capacity;
            T* newData = new T[newCapacity];
            for (int i = 0; i < size; ++i)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
            grow = growSize;
        }
        size = newSize;
    }

    int GetUpperBound() const
    {
        return size - 1;
    }

    bool IsEmpty() const
    {
        return size == 0;
    }

    void FreeExtra()
    {
        if (size < capacity)
        {
            T* newData = new T[size];
            for (int i = 0; i < size; ++i)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = size;
        }
    }

    void RemoveAll()
    {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    T GetAt(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    void SetAt(int index, const T& value)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range");
        }
        data[index] = value;
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    void Add(const T& value)
    {
        if (size >= capacity)
        {
            SetSize(size + 1, grow);
        }
        else {
            ++size;
        }
        data[size - 1] = value;
    }

    void Append(const Array& other)
    {
        SetSize(size + other.size);
        for (int i = 0; i < other.size; i++)
        {
            data[size - other.size + i] = other.data[i];
        }
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            grow = other.grow;
            data = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    T* GetData() const
    {
        return data;
    }

    void InsertAt(int index, const T& value)
    {
        if (index < 0 || index > size)
        {
            throw out_of_range("Index out of range");
        }
        SetSize(size + 1);
        for (int i = size - 1; i > index; i--)
        {
            data[i] = data[i - 1];
        }
        data[index] = value;
    }

    void RemoveAt(int index, int count = 1)
    {
        if (index < 0 || index >= size || count <= 0 || index + count > size)
        {
            throw out_of_range("Invalid index or count");
        }
        for (int i = index; i < size - count; i++)
        {
            data[i] = data[i + count];
        }
        size -= count;
    }
};

int main()
{
    Array<int> arr(2);

    arr.Add(10);
    arr.Add(20);
    arr.Add(30);

    cout << "Array size: " << arr.GetSize() << endl;
    cout << "Element at index 1: " << arr.GetAt(1) << endl;
    arr.SetAt(1, 25);
    cout << "Element at index 1 after update: " << arr[1] << endl;
    arr.RemoveAt(0);
    cout << "After removing the element at index 0, array size: " << arr.GetSize() << endl;
}