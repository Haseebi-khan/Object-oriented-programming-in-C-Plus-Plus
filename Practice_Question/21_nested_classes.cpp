#include <iostream>
using namespace std;

class Outer
{
    int outerValue;

public:
    Outer(int outer_value, int nested_value)
        : outerValue(outer_value), nestedObject(nested_value) {}

    class Nested
    {
        int nestedValue;

    public:
        Nested(int value) : nestedValue(value) {}
        
        void display();
    } nestedObject;

    void display()
    {
        cout << "I am in Outer class: " << outerValue << endl;
    }
};

void Outer::Nested::display()
{
    cout << "I am in Nested class function: " << nestedValue << endl;
}

int main()
{
    Outer outerObject(1, 2);
    outerObject.display();
    outerObject.nestedObject.display();
    return 0;
}
