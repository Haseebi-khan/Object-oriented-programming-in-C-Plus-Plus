#include <iostream>
using namespace std;

int main()
{
    int* arr = new int[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = 10+i;
    }
    cin >> arr[6];
    // int* arr = new int[5];
    cout << arr[6]<<endl;
    




    return 0;
}