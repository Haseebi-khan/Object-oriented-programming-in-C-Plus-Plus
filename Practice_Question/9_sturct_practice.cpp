#include <iostream>
using namespace std;

typedef struct AgePair {
    int ages[2];
} AgePair;

int main()
{
    AgePair people[10];  
    
    for (int person = 0; person < 10; person++)
    {
        for (int ageIndex = 0; ageIndex < 2; ageIndex++)
        {
            people[person].ages[ageIndex] = person + ageIndex;
        }
    }
    
    for (int person = 0; person < 10; person++)
    {
        for (int ageIndex = 0; ageIndex < 2; ageIndex++)
        {
            cout << people[person].ages[ageIndex] << " ";
        }
        cout << endl;
    }

    return 0;
}
