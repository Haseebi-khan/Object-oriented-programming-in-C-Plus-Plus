#include <iostream>
using namespace std;

/////                                                   DONE

const int student_size = 5;
const int teach_size = 5;
const int manag_size = 5;

struct Teacher
{
    string teach_name[teach_size];
    int teach_id[teach_size];
    long salary[teach_size];
    string email[teach_size];
};
struct Mangement
{
    string mang_name[manag_size];
    int mang_id[manag_size];
    long salary[manag_size];
};
struct Student
{
    string std_name[student_size];
    int id[student_size];
};

class Person_info
{
private:
    Teacher teacher;
    Mangement mangement;
    Student student;

public:
    Person_info() { cout << " DATA ENTRY " << endl; }
    ~Person_info() {}

    void dataEntry()
    {
        cout << "Are you Sudent or Teacher or Mangement ?" << endl;
        string type;
        cin >> type;
        if (type == "Student")
        {
            cout << "Dont use space in your name" << endl;

            cout << "Enter your name: ";
            cin >> student.std_name[0];
            cout << "Enter your id: ";
            cin >> student.id[0];
        }
        else if (type == "Teacher")
        {
            cout << "Dont use space in your name" << endl;
            cout << "Enter your name: ";
            cin >> teacher.teach_name[0];
            cout << "Enter your id: ";
            cin >> teacher.teach_id[0];
            cout << "Enter your salary: ";
            cin >> teacher.salary[0];
            cout << "Enter your email: ";
            cin >> teacher.email[0];
        }
        else if (type == "Mangement")
        {
            cout << "Dont use space in your name" << endl;
            cout << "Enter your name: ";
            cin >> mangement.mang_name[0];
            cout << "Enter your id: ";
            cin >> mangement.mang_id[0];
            cout << "Enter your salary: ";
            cin >> mangement.salary[0];
        }
    }

    void display()
    {
        cout << "Are you Sudent or Teacher or Mangement ?" << endl;

        string type;
        cin >> type;
        if (type == "Student")
        {
            cout << "Enter your ID: ";
            int id;
            cin >> id;
            for (int i = 0; i < student_size; i++)
            {
                if (id == student.id[i])
                {
                    cout << "Student name: " << student.std_name[i] << endl;
                    cout << "Student id: " << student.id[i] << endl;
                    break;
                }
            }
        }
        else if (type == "Teacher")
        {
            cout << "Enter your ID: ";

            int id;
            cin >> id;
            for (int i = 0; i < teach_size; i++)
            {
                if (id == teacher.teach_id[i])
                {
                    cout << "Teacher name: " << teacher.teach_name[i] << endl;
                    cout << "Teacher id: " << teacher.teach_id[i] << endl;
                    cout << "Teacher salary: " << teacher.salary[i] << endl;
                    cout << "Teacher email: " << teacher.email[i] << endl;
                }
            }
        }
        else if (type == "Mangement")
        {
            cout << "Enter your ID: ";

            int id;
            cin >> id;
            for (int i = 0; i < manag_size; i++)
            {
                if (id == mangement.mang_id[i])
                {
                    cout << "Mangement name: " << mangement.mang_name[i] << endl;
                    cout << "Mangement id: " << mangement.mang_id[i] << endl;
                    cout << "Mangement salary: " << mangement.salary[i] << endl;
                }
            }
        }
    }
};

int main()
{
    Person_info person;
    int type;
    do
    {
        cout << "For data entry press 1 and Checking press 2";
        cin >> type;
        if (type == 1)
        {
            person.dataEntry();
        }
        else if (type == 2)
        {
            person.display();
        }

    } while (type != 0);

    return 0;
}