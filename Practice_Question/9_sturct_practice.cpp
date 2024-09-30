#include <iostream>
using namespace std;

typedef struct sajsdhkjasd {
    int age[2];
}p1;


int main()
{
    p1 b[10];
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            b[i].age[j] = i + j;
        }
    }
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << b[i].age[j] << " ";
        }
        cout <<endl;
    }

    
    return 0;
}