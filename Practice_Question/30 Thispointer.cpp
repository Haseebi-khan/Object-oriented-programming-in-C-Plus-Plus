
#include <iostream>
using namespace std;

class Test
{
private:
    int x;
    int y;

public:
    Test(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    Test &setX(int a)
    {
        x = a;
        return *this;
    }
    Test &setY(int b)
    {
        y = b;
        return *this;
    }
    void print() { cout << "x = " << x << " y = " << y << endl; }
};

int main()
{
    Test obj1(5, 5);

    // Chained function calls. All calls modify the same object
    // as the same object is returned by reference
    obj1.print();


    obj1.setX(4).setY(20);

    obj1.setX(20);

    obj1.print();
    return 0;
}
  //////////////////////////////////////////////////////////////////////
  #include <iostream>
using namespace std;

// this pointer

class X
{
    int p;
    int x;

public:
    X() {}
    X(int d) : p(d), x(0) {}

    X& setpx(int d,int g)
    {
        this->p = d;
        this->x = g;
        return *this;
    }

    void ps()
    {
        cout << p << "  " << x << endl;
    }
};

int main()
{
    X a;
    a.ps();
    a = X(5);
    a.ps();
    a.setpx(30,2).ps();

    return 0;
}