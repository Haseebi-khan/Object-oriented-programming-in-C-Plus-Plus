// #include <iostream>

// using namespace std;

// void greatest(int *x, int *y, int *z)
// {
//     if (*x > *y && *x > *z)
//     {
//         cout << "largest value is: " << *x << endl;
//     }
//     else if (*y > *x && *y > *z)
//     {
//         cout << "largest value is: " << *y << endl;
//     }
//     else if (*z > *y && *z > *y)
//     {
//         cout << "largest value is: " << *z << endl;
//     }
// }

// void greatests(int *x, int size)
// {
//     int max = x[0];

//     for (int i = 0; i < size; i++)
//     {
//         if (x[i] < max)
//         {
//             max = x[i];
//         }
//     }

//     cout << "Maximum no is: " << max;
// };

// int main()
// {
//     int x[5] = {
//         2, 6, 5, 3, 4};

//     int *p = x;

//     // greatest(p,q,r);

//     greatest(p, 5);

//     return 0;
// }

///////////////////////////////////////
#include <iostream>

using namespace std;

double factorial(int *x)
{
    double fact = 1;
    if (*x == 0)
    {
        return 1;
    }
    else
    {
        for (int i = *x; i > 1; i--)
        {
            fact *= i;
        }
        return fact;
    }
}


void reverse(int* num){
    int last = *num % 10;

    int seclast = (*num / 10 ) % 10;

    int sec = (*num / 100) % 10;

    int one = (*num / 1000); 

    *num = 888;

    cout << one << sec << seclast << last << endl;
}

int main()
{
    // cout << "Enter the value: ";
    // int f;
    // cin >> f;
    // int *ptr = &f;

    // cout << factorial(ptr);

    int num = 9331;
    int* ptr=&num;

    reverse(ptr);
    cout << "sadsaddddddddddddddddd   " << num; 


    // while (num != 0)
    // {
    //     int digit = num % 10;
    //     reverse = reverse * 10 + digit;
    //     num = num / 10;
    // }

    




    return 0;
}

//=======================================================================================


// #include <iostream>
// using namespace std;
// int main() {

//     int a = 5, b = 10, c = 15;
//     int *arr[] = {&a, &b, &c};
//     cout << *arr[1];
    
//     return 0;
// }