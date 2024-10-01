#include <iostream>

using namespace std;

class base1
{
public:
    void p()
    {
        cout << "111111 " << endl;
    }
};

class base2
{
public:
    void p()
    {
        cout << "222222 " << endl;
    }
};
class base3 : public base1, public base2
{
    int x;

public:
    // void p()
    // {
    //    base2::p();
    //    base1::p();
    // }

public:
};

int main()
{

    base3 d;
    d.base1::p();

    return 0;
}
