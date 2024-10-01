#include <iostream>
using namespace std;

class FunctionAndSubsripting_Overload
{
    int a,b;
    static const int size = 10;
    int arry[size];
    
    public:
    FunctionAndSubsripting_Overload(int i = 10,int j = 12 ): a(i),b(j)
    {
        for (int i = 0; i < size; i++)
        {
            arry[i] = i + b;
        }
    }
    FunctionAndSubsripting_Overload &operator()(int i,int j,int k)
    {
        FunctionAndSubsripting_Overload F;
        F.a = a + b + i+j;
        F.b = k+b;
        return F;
    } 
    int &operator[](int i)
    {
        if (i > size)
        {
            cout << "out of range."<<endl;
            return arry[0];
        }
        return arry[i];
    }
    void dis()
    {
        cout << "--------------------------------------" <<endl;
        cout << "A: " << a<<endl;
        cout << "B: " << b<<endl;
        for (int  i = 0; i < size; i++)
        {
            cout << arry[i] << " "; 
        }
        cout << "--------------------------------------" <<endl;

        
    }

};

int main()
{
    FunctionAndSubsripting_Overload a;
    FunctionAndSubsripting_Overload b = a(3,2,4);
    cout << b[45] <<endl;
    cout << b[6] <<endl;
    b.dis();



    return 0;
}