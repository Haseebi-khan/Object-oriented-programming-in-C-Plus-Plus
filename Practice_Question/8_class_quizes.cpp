#include <iostream>

using namespace std;

// /////////////////////////////////////////////////////////                 DONE

class course
{
    int x, y; 
    public:
    course(int xx)
    {
        x = ++xx;
    }
    void Display()
    {
        cout<< --x << " ";
    }
};
int main()
{
    course obj(20);
    obj.Display();
    int *p = (int*)&obj ;  // undefine beawear. due to on some compiler like "Online IDE" treated obj data well. But on otherhand compiler are not working like linux distro.  
    *p = 5;
    obj.Display();
    return 0; 
}