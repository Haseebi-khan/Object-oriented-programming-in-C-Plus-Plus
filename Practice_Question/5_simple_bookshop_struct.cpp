#include <iostream>

using namespace std;


/////////////////////////////////////////////////////??DONE


struct book
{
    string name;
    double price;
    long pages;
};

void read(book a[], int i)
{
    cout << "the book " << (i + 1) << endl;
    cout << "Enter book name: ";
    cin.ignore();
    getline(cin, a[i].name);
    cout << "Enter book price: ";
    cin >> a[i].price;
    cout << "Enter book pages: ";
    cin >> a[i].pages;
}

int main()
{
    book a[3];

    for (int i = 0; i < 3; i++)
    {
        read(a, i);
    }

    cout << "===========================================\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "The book " << i + 1 << " name is: " << a[i].name << endl;
        cout << "Price is: " << a[i].price << endl;
        cout << "Total pages is: " << a[i].pages << endl;
    }

    return 0;
}