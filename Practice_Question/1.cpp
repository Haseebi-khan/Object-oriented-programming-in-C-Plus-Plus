#include <iostream>
#include <string>
using namespace std;

class empolyies 
{
    private:
        string private_name;
    public:
        void eemp (string name );
        void display()
        {
            cout << "PRAVTE Name: "<< private_name<<endl;
            cout << "Public Name: "<< public_name<<endl;
        }
        string public_name;
};

void empolyies :: eemp (string name )
{

    private_name = name;

}

int main()
{

    empolyies n1;

    cout << "Enter the private name: ";
    string privateName;
    cin >>privateName;
    n1.eemp(privateName);

    cout << "Enter the public name: ";
    cin >> n1.public_name;
    
    n1.display();   

    return 0;
}
