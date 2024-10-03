#include <iostream>
#include <string>

using namespace std;

//                                                  Done

class Library
{
    static const int a_count = 20;
    long serial[a_count];
    string id[a_count];
    int count = 0;

public:
    string name[a_count];
    void counter();
    void read();
    void display_all_books();
};

void Library::counter()
{
    cout << "How many books do you want to store (up to 20)? ";
    int type;
    cin >> type;

    if (type > a_count)
    {
        cout << "It's not possible to enter more than 20 books." << endl;
    }
    else if (type <= 0)
    {
        cout << "Invalid number of books." << endl;
    }
    else
    {
        for (int i = 0; i < type; i++)
        {
            read();
        }
    }
}

void Library::read()
{
    if (count < a_count)
    {
        cout << "Enter the name of the book: ";
        cin >> name[count];

        cout << "Enter the book ID: ";
        cin >> id[count];

        cout << "Enter the serial number: ";
        cin >> serial[count];

        count++;
    }
    else
    {
        cout << "Maximum limit of books reached." << endl;
    }
}

void Library::display_all_books()
{
    for (int i = 0; i < count; i++)
    {
        cout << "\nBook " << i + 1 << ":" << endl;
        cout << "Name: " << name[i] << endl;
        cout << "ID: " << id[i] << endl;
        cout << "Serial no: " << serial[i] << endl;
    }
}

int main()
{
    Library l1;
    l1.counter();
    l1.display_all_books();

    return 0;
}
