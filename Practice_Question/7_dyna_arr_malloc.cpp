#include <iostream>
using namespace std;

////////////////////////////////////////////////////???                        DONE

int main()
{

    int *array = (int *)malloc(5 * sizeof(int));
    string *array2 = new string[5];

    // using malloc
    for (int i = 0; i < 5; i++)
    {
        array[i] = i + 1;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << endl;
    }

    free(array);

    // using new
    for (int i = 0; i < 5; i++)
    {
        array2[i] = "String " + to_string(i + 1);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << array2[i] << endl;
    }
    delete[] array2;
    // both methods are valid for allocating memory dynamically, but using new is generally considered the better practice in C++.
    // it automatically calls the constructor of the object type and automatically handles memory deallocation when the object goes out of scope,
    // making it simpler and safer to use.
    return 0;
}

// int main()
// {

//     int *li = (int *)malloc(3 * sizeof(int));

//     for (int i = 0; i < 3; i++)
//     {
//         li[i] = 1 + i;
//     }

//     for (int i = 0; i < 3; i++)
//     {
//         cout << li[i] << " ";
//     }
//     free(li);
//     cout <<endl;

//     return 0;
// }