#include <iostream>
using namespace std;

class person
{
    string name;
    int age;
    public:
    friend ostream& operator << (ostream &output,const person &p )
    {
        output << "name: "<< p.name << ", Age: " << p.age <<endl;
        return output;
    }
    friend istream& operator >> (istream &input, person &p)
    {
        cout << "Enter your name :";
        input >> p.name;
        cout << "Enter your age :";
        input >> p.age;
        return input;
    }
};

int main()
{
    person p1;

    cin >> p1;
    cout << p1;
    


    return 0;
}