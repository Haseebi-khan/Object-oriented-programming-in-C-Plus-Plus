#include <iostream>
#include <string>

using namespace std;


///                                                    DONE

// class Empty {
//     int doos;
//     string sad;
//     long sadsa;
//     double dd;
//     float whole;
// };

// int main()
// {
//   cout << sizeof(Empty);
//   return 0;
// }
//////////////////////////////////////////////////////////////////////////////////////////////////////

// class Empty
// {
//     int c;
// };

// int main()
// {

//     Empty c;
//     cout << c.c;

//     return 0;
// }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Binary
{
private:
    string _string;

public:
    void dataEntry()
    {
        cout << "Enter the Binary String: ";
        getline(cin, _string);
    }
    void display() { cout << "The Binary String is: " << _string << endl; }
    bool check_binary()
    {
        bool found = false;
        for (int i = 0; i < _string.length(); i++)
        {
            if (_string[i] != '0' && _string[i] != '1')
            {
                found = true;
                break;
            }
        }
        return found;
    }
    void show_Error()
    {
        cout << "String is not a binary string: " << _string << endl;
    }
    void one_compliment()
    {
        string complimentString;
        complimentString = _string;
        for (int i = 0; i < _string.length(); i++)
        {
            if (complimentString[i] == '1')
            {
                complimentString[i] = '0';
            }
            else
            {
                complimentString[i] = '1';
            }
        }
        cout << "The One's Compliment is: " << complimentString << endl;
    }
};

int main()
{

    Binary _String;
    _String.dataEntry();
    if (_String.check_binary() == true)
    {
        _String.show_Error();
    }
    else
    {
        _String.display();
        _String.one_compliment();
    }

    return 0;
}