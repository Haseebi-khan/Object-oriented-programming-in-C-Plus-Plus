#include <iostream>
using namespace std;

class box
{
    double volumn=0;

public:
    double lenght, width, height;
    // member function
    double getdata(double lenght, double height, double width);
    void displaydata()
    {
        cout << "The volumn is: " << volumn << endl;
    }
};

double box ::getdata(double lenght1, double height1, double width1)
{
    return volumn = lenght * height * width;
}

int main()
{
    box b;
    double height , lenght, width;

    cout << "Enter the height: ";
    cin >> b.height;
    cout << "Enter the lenght: ";
    cin >> b.lenght;
    cout << "Enter the width: ";
    cin >> b.width;

    b.getdata(b.height, b.lenght, b.width);

    b.displaydata();

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>

using namespace std;
int i = 0;

class arry
{
        char arr[20];
    public:
        arry() {}
        arry(const char a[])
        {
            int i = 0;
            while (a[i] != '\0' && i < 19) {
                arr[i] = a[i];
                i++;
            }
            arr[i] = '\0';
            
        }
        void call(const char a[])
        {
            int i = 0;
            while (a[i] != '\0' && i < 19) {
                arr[i] = a[i];
                i++;
            }
            
            
        }
        void getname()
        {
            cout << arr <<endl;
        }
};


int main()
{
    arry i;
    cout << "Enter the name : ";
    char name[20];
    cin >> name;

    i.call(name);

    i.getname();
    


    
    return 0;
}