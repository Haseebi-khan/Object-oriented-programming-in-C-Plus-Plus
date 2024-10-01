#include <iostream>
using namespace std;

class Distance
{
    int inches;
    int feet;
    public:
    Distance (int f = 0, int i = 0): feet(f),inches(i) {}
    void dis()
    {
        cout << "feet: " << feet << endl;
        cout << "inches: " << inches << endl;
    }
    Distance operator -() 
    {
        feet = -feet;
        inches = --inches;
        return Distance(feet,inches);
    }

};

int main()
{
    Distance D1(34,2), D2(33,44); 
    D1.dis();

    -D1;
    D1.dis();
    cout << "-----------------------"<<endl;
    
    D2.dis();
    -D2;
    D2.dis();


    return 0;
}