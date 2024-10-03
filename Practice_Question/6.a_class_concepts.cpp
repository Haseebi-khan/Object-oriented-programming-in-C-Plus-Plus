#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////DONE

class CS_student
{
    const static int size = 10;
    string student_name[size];
    int id_no[size];
    int count = 1;

public:
    CS_student()
    {
        for (int i = 0; i < size; i++)
        {
            id_no[i] = i + 1;
        }
    }
    void read();
    void display();
};

void CS_student::read()
{

    cout << "Enter the name: ";
    getline(cin, student_name[count - 1]);
    count++;
}

void CS_student::display()
{
    for (int i = 0; i < count - 1; i++)
    {
        cout << "Name: " << student_name[i] << " Roll no: " << id_no[i] << endl;
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
