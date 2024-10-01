#include <iostream>
using namespace std;

class A
{
    int a;
    int b;

public:
    A() {}
    A(int c, int d) : a(c), b(d) {}
    void display()
    {
        cout << "A " << a << endl;
        cout << "B " << b << endl;
    }
    A operator+(const A &obj)
    {
        A a;
        a.a = this->a + obj.a;
        a.b = this->b + 2;
        return a;
    }
    A operator-(const A &obj)
    {
        A a;
        a.a = this->a - obj.a;
        a.b = this->b - 2;
        return a;
    }
    bool operator<(const A &obj)
    {
        if (this->a < obj.a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    A obj1(34, 56), obj2(23, 56);
    A obj3;
    if (obj1 < obj2)
    {
        obj3 = obj1 + obj2;
        cout << "Obj1 is less than Obj2" << endl;
    }
    else
    {
        cout << "Obj1 is greater than Obj2" << endl;
        obj3 = obj1 - obj2;
    }
    cout << "==================================" << endl;
    obj1.display();

    cout << "==================================" << endl;
    obj2.display();

    cout << "==================================" << endl;
    obj3.display();

    return 0;
}