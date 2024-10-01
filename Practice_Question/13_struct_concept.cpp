#include <iostream>

using namespace std;

struct marks{
    double roll_no;
    char name[10];
    double chem,phy,math;
};

double percentage(struct marks a)
{
    double per = ((a.chem + a.phy + a.math)/300) * 100;

    return per;
};


int main()
{
    marks s[5];

    for (int i = 0; i < 5; i++)
    {
        s[i].roll_no = i + 1;
        cout << "Student "<< i + 1 <<endl;
        cout << "Enter Name: ";
        cin >> s[i].name;
        s[i].chem = i * 2 + 22;
        s[i].math = i +39;
        s[i].phy = 66-4+i;
    }

    double pers[5];

    for (int i = 0; i < 5; i++)
    {
        pers[i] = percentage(s[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "student " << i + 1 <<endl;
        cout << pers[i] << endl; 
    }
    
    return 0;
}