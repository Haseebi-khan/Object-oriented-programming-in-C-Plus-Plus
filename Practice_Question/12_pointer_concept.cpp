#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//////////////////////////      Done

string greatestIndex(int *numptr)
{
    string highIndexValue;
    if (numptr[0] > numptr[1] && numptr[0] > numptr[2])
    {
        highIndexValue = "First Index Value is highest. ";
    }
    else if (numptr[1] > numptr[0] && numptr[1] > numptr[2])
    {
        highIndexValue = "2nd Index Value is highest. ";
    }
    else if (numptr[2] > numptr[1] && numptr[2] > numptr[0])
    {
        highIndexValue = "3rd Index Value is highest. ";
    }

    return highIndexValue;
}

double hightestValue(int *numptr, int size)
{
    int max = numptr[0];

    for (int i = 0; i < size; i++)
    {
        if (numptr[i] > max)
        {
            max = numptr[i];
        }
    }
    return max;
};

void reverse(int &num)
{
    int last = num % 10;

    int seclast = (num / 10) % 10;

    int sec = (num / 100) % 10;

    int one = (num / 1000);

    cout << last << seclast << sec <<  one << endl;
}

int main()
{
    srand(time(0));

    int numArry[3];

    for (int i = 0; i < 3; i++)
    {
        numArry[i] = rand() % 10000 + 1;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << numArry[i] << " ";
    }
    cout << endl;

    int *numptr = numArry;

    int(*wholeBlockOfArray)[3] = &numArry; // how to use it.

    string highestIndex = greatestIndex(numptr);
    int highestValue = hightestValue(numptr, 3);

    cout << highestIndex << endl;
    cout << "Heighest Value is: " << highestValue << endl;

    cout << "WholeBlockOfArray: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << (*wholeBlockOfArray)[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Reversed Number: ";
    reverse(highestValue);

    int *arr[] = {&numArry[0], &numArry[1], &numArry[2]};
    cout << *arr[0] << " " << *arr[1] << " " << *arr[2] << endl;

    cout << endl;
    return 0;
}
