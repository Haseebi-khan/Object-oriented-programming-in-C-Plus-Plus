#include <iostream>
#include <string>

using namespace std;

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

class binary
{
private:
    string good;

public:
    void read(void)
    {
        cout << "Enter the binary string: ";
        getline(cin, good);
    }
    void display(void)
    {
        cout << good;
    }
    bool chk_bina(void);
    void incorrect(void);
    void one_compliement();
};

void binary ::one_compliement()
{
    for (int i = 0; i < good.length(); i++)
    {
        if (good[i] == '1')
        {
            good[i] = '0';
        }
        else
        {
            good[i] = '1';
        }
    }
}

void binary ::incorrect(void)
{
    cout << "Incorrect binary: " << good << endl;
}

bool binary ::chk_bina(void)
{
    bool found = false;

    for (int i = 0; i < good.length(); i++)
    {
        if (good[i] != '0' && good[i] != '1')
        {
            found = true;
            break;
        }
    }
    return found;
}

int main()
{
    binary b;
    b.read();

    cout << endl;

    if (b.chk_bina() == true)
    {
        b.incorrect();
    }
    else
    {
        b.display();
        cout << endl;
        b.one_compliement();
        b.display();
    }

    return 0;
}