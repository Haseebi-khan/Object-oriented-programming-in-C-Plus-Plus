// C++ Program to implement
// template Array class
#include <iostream>
using namespace std;

template <typename T> class Array {
private:
    T* ptr;
    int size;

public:
    Array(T arr[], int s);
    void print();
};

template <typename T> Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <typename T> void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}

int main()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);
    a.print();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template < class value> void fun(value a[], value size)
{
    for (int i = 0; i < size -1 ; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                value temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        
    }
    
}

int main() 
{
    double arr[5] = {3.45,3.223,2.222,11,2};
    int size = 5;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    fun<double>(arr,5);
    cout << "\nssssssssssssssssssssssssssssssssss\n";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

template <typename E>
class employee
{
    E *name;
    E age;

public:
    employee(E n, E a)
    {
        name = new E;
        *name = n;
        age = a;
    }
    ~employee()
    {
        delete name;
    }
    void print()
    {
        cout << "Name: " << *name << endl;
        cout << "Age: " << age << endl;
    }
};

int main()
{
    employee<string> p1("Hasebb", "22");
    p1.print();
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

template <typename N,typename A> class employee
{
    N *name;
    A age;

public:
    employee(N n, A a)
    {
        name = new N;
        *name = n;
        age = a;
    }
    ~employee()
    {
        delete name;
    }
    void print()
    {
        cout << "Name: " << *name << endl;
        cout << "Age: " << age << endl;
    }
};

int main()
{
    employee <string,int> p1("Hasebb", 22);
    p1.print();
    return 0;
}
