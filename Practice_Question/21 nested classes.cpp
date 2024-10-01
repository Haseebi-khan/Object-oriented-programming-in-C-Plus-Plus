
#include <iostream>

using namespace std;

class one
{
    int xvalue;
public:
    one(int outer_value, int inner_value) : xvalue(outer_value), obj1(inner_value) {}
    class nestedone
    {
        int ivalue;
    public:
        nestedone(int value): ivalue(value) {} 
        void function();
    } obj1;
};

void one::nestedone::function()
{
    cout << "I am in nestedone function\n";
    cout << ivalue <<endl;
}
int main(void)
{
    one obj(1, 2);
    obj.obj1.function();
    return 0;
}