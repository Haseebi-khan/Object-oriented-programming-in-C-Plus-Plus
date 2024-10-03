#include <iostream>
using namespace std;

//                                                                             Done

class Empolyies
{
private:
    string private_name;

public:
    string public_name;
    void Emp(string name);
    void show_personalname()
    {
        cout << "Pravite Name: " << private_name << endl;
    }
    void display()
    {
        cout << "Gaming Name: " << public_name << endl;
        show_personalname();
    }
};

void Empolyies ::Emp(string name) { private_name = name; }

int main()
{

    Empolyies e1;
    cout << "Enter your Gaming name: ";
    string gameing_name, real_name;
    getline(cin, gameing_name);
    cout << "Enter your private name: ";
    getline(cin, real_name);

    e1.Emp(real_name);
    e1.public_name = gameing_name;

    e1.display();

    cout << endl;
    return 0;
}