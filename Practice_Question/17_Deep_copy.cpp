// Problem Statement 1:
// Implement a copy constructor for a class that represents a customer.
// The Customer class has two member variables: "name", which is a dynamically allocated string, and "address",
// which is a statically allocated char array.
// Test your implementation by creating two instances of the Customer class and
// using the copy constructor to create a deep copy of one of them.
#include <iostream>

using namespace std;

class Customer
{
    string *name;
    char address[10];

public:

    Customer()
    {
        name = new string;
    }

    Customer(const Customer &newobj)
    {
        name = new string(*newobj.name);
        // *name = *newobj.name;
        for (int i = 0; i < 10; i++)
        {
            address[i] = newobj.address[i];
        }
    }

    void setter(string n, char a[])
    {
        *name = n;
        for (int i = 0; i < 10; ++i)
        {
            address[i] = a[i];
        }
    }

    void getter(void)
    {
        cout << "Name: " << *name << endl;
        cout << "Address: " << address << endl;
    }

    ~Customer()
    {
        delete name;
    }
};

int main()
{
    Customer c;

    string name;

    char address[10];

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your address: ";
    cin >> address;

    c.setter(name, address);

    Customer c2 = c;

    c.getter();
    cout << "\n";
    c2.getter();

    return 0;
}