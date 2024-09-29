// #include <iostream>

// using namespace std;

// void library ::counter()
// {
//     cout << "How many Books you want to store: ";
//     count = 0;
//     cin >> a_count;
// }

// class library
// {
//     int a_count;
//     long serial[a_count];
//     int id[a_count];
//     int count;

// public:
//     string name[a_count];
//     void counter();
//     void read();

// }

// void library ::read()
// {
//     cout << "Enter the Name : ";
//     cin >> name[a_count];
//     cout << "Enter the Serial Number: ";
//     cin >> serial[a_count];
// }

// int main()
// {

//     return 0;
// }

#include <iostream>
using namespace std;

class CS_student
{
    const int size = 10;
    int id_no[size];
    string student_name[size];
    int count;

public:
    void counter()
    {
        count = 0;
    }
    void read();
    void display();
};

void CS_student::read()
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the name: ";
        getline(cin, student_name[count]);

        cout << "Enter the Roll no: ";
        cin >> id_no[count];
        cin.ignore();
        count++;
    }
}

void CS_student::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << "Name: " << student_name[i] << "\nRoll no: " << id_no[i] << endl;
    }
}

int main()
{
    CS_student s1;

    s1.read();
    s1.display();
    cout << endl;

    return 0;
}











//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
