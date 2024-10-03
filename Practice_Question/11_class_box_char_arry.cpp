// Question:

// Write a C++ program that defines a class StringArray to manage character arrays (strings) effectively. The program should meet the following requirements:

// Implement a default constructor and a parameterized constructor that accepts a string (character array) and stores it in a private member variable str.
// Define a method setString that takes a string as input and stores it in the class's internal array.
// Define a method printString that outputs the stored string to the console.

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

// In the main function, prompt the user to input a name (string), store it using the setString method, and then display the name using the printString method.
// Ensure that the class can handle strings up to 19 characters in length (excluding the null terminator).

#include <iostream>
using namespace std;

//                                                  DONE

class StringArray
{
    char str[20];

public:
    StringArray() {}
    StringArray(const char arr[])
    {
        int i = 0;
        while (arr[i] != '\0' && i < 20)
        {
            str[i] = arr[i];
            i++;
        }
        str[i] = '\0';
    }
    void setStr(const char* arr)
    {
        int i = 0;
        while (arr[i] != '\0' && i <20)
        {
            str[i] = arr[i];
            i++;
        }
        str[i] = '\0';
    }
    void displaySet()
    {
        cout << "The String is: " << str <<endl;
    }

};

int main()
{

    cout << "Enter First String (without spaces): ";
    char str[20];
    char str2[20];
    cin >> str;
    cout << "Enter 2nd String (without spaces): ";
    cin >> str2;

    StringArray _1;
    StringArray _2;

    _1.setStr(str);
    _2.setStr(str2);

    _1.displaySet();
    _2.displaySet();

    return 0;
}
