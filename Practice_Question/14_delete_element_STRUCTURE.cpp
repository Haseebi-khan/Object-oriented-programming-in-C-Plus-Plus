#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct N
{
    string f_name,
        middle,
        l_name;
    long long number;
};

typedef struct NameNumberAddressesCompanyAgeProfession
{
    N nameAndNumber;
    string profession,
        address;
    long age;

} Personinfo;

int main()
{

    int size = 0;

    Personinfo *persons = new Personinfo[size];

    string back;
    do
    {
        Personinfo person;

        cout << "Enter First Name: ";
        getline(cin, person.nameAndNumber.f_name);
        cout << "Enter Middle Name: ";
        getline(cin, person.nameAndNumber.middle);
        cout << "Enter Last Name: ";
        getline(cin, person.nameAndNumber.l_name);
        cout << "Enter Number: ";
        cin >> person.nameAndNumber.number;
        cin.ignore();
        cout << "Address: ";
        getline(cin, person.address);
        cout << "Profession: ";
        getline(cin, person.profession);

        cout << "Age: ";
        cin >> person.age;
        while (person.age <= 18 || person.age >= 130)
        {
            cout << "Enter age b/w 18 to 130: ";
            cin >> person.age;
        }

        Personinfo *new_persons = new Personinfo[size + 1];

        for (int i = 0; i < size; i++)
        {
            new_persons[i] = persons[i];
        }

        delete[] persons;

        persons = new_persons;

        persons[size++] = person;

        cout << "\tName \tNumber\n";
        cout << "\t" << person.nameAndNumber.f_name << " " << person.nameAndNumber.l_name
             << "\t" << person.nameAndNumber.number << endl;

        cout << "\tContact have been saved.\n";
        cout << "\tIf you want to go back then press 'x' else press any key: ";

        cin >> back;
        cin.ignore();

    } while (back != "x");

    for (int i = 0; i < size; ++i)
    {
        cout << "\t" << persons[i].nameAndNumber.f_name << " " << persons[i].nameAndNumber.l_name
             << "\t" << persons[i].nameAndNumber.number << endl;
    }

    delete[] persons;

    return 0;
}