#include <iostream>
using namespace std;

class Copy
{
    int* a;
    public: 
        Copy() {}
        // Copy(const Copy& obj)
        // {
        //     a = obj.a;
        // }
        Copy(int i) 
        {
            *a = i;
        }
        // void operator= (const Copy &obj)
        // {
        //     a = obj.a;
        // } 
        Copy& operator= (const Copy &obj)
        {
            if (this != &obj) { // Prevent self-assignment
                a = obj.a;
            }
            return *this;
        } 
        void display()
        {
            cout << "A: " << *a <<endl;
        }

};

int main()
{
    Copy a;
    Copy b;
    b.operator=(a);
    b.display();

    return 0;
}