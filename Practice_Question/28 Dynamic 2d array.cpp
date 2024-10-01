#include <iostream>
using namespace std;

int *GetFactorsArray(int n)
{
    int *factor = new int[n];
    int count = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            factor[count++] = i;
        }
    }

    factor[count] = -1;
    return factor;
}

void print(int **factorArray, int input)
{
    cout << "Following are the factors of numbers entered:" << endl;
    for (int i = 0; i < input; i++)
    {
        cout << "Factors of " << factorArray[i][0] << " are: ";
        for (int j = 1; factorArray[i][j] != -1; j++)
        {
            cout << factorArray[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int inputs;
    cout << "Enter no of inputs you want to take: ";
    cin >> inputs;
    int **factor = new int *[inputs];

    for (int i = 0; i < inputs; i++)
    {
        int n;
        cout << "Enter a number between 6 and 100: ";
        cin >> n;

        while (n < 6 || n > 100)
        {
            cout << "Wrong input. Please re-enter the number between 6 and 100: ";
            cin >> n;
        }

        factor[i] = GetFactorsArray(n);
        factor[i][0] = n;
        if (n == 1)
        {
            break;
        }
    }

    print(factor, inputs);

    for (int i = 0; i < inputs; i++)
    {
        delete[] factor[i];
    }
    delete[] factor;

    return 0;
}




/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

// Question No. 01:
// Factor calculator is a program which asks user how many inputs he wants to take and then asks user to
// enter n numbers such that, Numbers entered should be greater than 6 and less than 100. If the number
// does not fall in this range, program should alert user to re-enter the number. If the entered number is 1, the
// program should stop taking input and return the factors of all the entered numbers. Create factors array for
// each number in above allocated 2D array and store that number on 1st index of factors array and the
// factors on the further indexes. Your program should also de-allocate acquired dynamic memory at the end
// of the life cycle. Do not consume extra memory.

// Int** GetFactorsArray(...) // This function takes count of elements and values of elements from user.
// Returns a dynamic 2-D Array of Factors of the elements(numbers) entered.
// Void Print(.......); Displays 2-D array in proper format.
// Void main()
// {
// // Design main as per your requirements.
// }

// Sample Output:
// Enter no of inputs you want to take: 2
// Enter Number between 6 and 100: 12
// Enter Number between 6 and 100: 5
// Wrong input. Please re-enter the number
// Enter Number between 6 and 100:10
// ...
// Following are the factors of numbers entered:
// Factors of 12 are 1,2,3,4,6,12
// Factors of 10 are 1, 2,5,10

// Question No. 01:
#include <iostream>
using namespace std;

int *GetFactorsArray(int n)
{
    int *factor = new int[n];
    int count = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            factor[count++] = i;
            
        }
    }

    factor[count] = -1;
    // return factor column
    return factor;
};

void print(int **factorArray, int input)
{
    for (int i = 0; i < input; i++)
    {
        cout << "Factor for " << factorArray[i][0] << " are : ";
        // finite loop sentimaental value;
        for (int j = 1; factorArray[i][j] !=-1; j++)
        {
            cout << factorArray[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // int m = 3, n = 4, c = 0;

    // for (int i = 0; i < m; i++)
    // {
    //     factor[i] = new int[n];
    // }
    int inputs;
    cout << "Enter no of inputs you want to take:";
    cin >> inputs;
    int **factor;
    factor = new int *[inputs];

    for (int i = 0; i < inputs; i++)
    {
        int n;
        cout << "Enter n numbers: ";
        cin >> n;
        while (n < 6 || n > 100)
        {
            cout << "Wrong input. Please re-enter the number: ";
            cin >> n;
        }

        if (n == 1)
        {
            break;
        }

        factor[i] = GetFactorsArray(n);
        factor[i][0] = n;

        // factor[i] = GetFactorsArray(n);
    }

    // for (int i = 0; i < inputs; ++i)
    // {
    //     for (int j = 0; j < factor[i][0]; ++j)
    //     {
    //         cout << factor[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    print(factor, inputs);

    for (int i = 0; i < inputs; i++)
    {
        delete[] factor[i];
    }
    delete[] factor;

    return 0;
}
