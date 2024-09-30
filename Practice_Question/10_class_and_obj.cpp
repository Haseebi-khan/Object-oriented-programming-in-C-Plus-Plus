#include <iostream>
using namespace std;

class box
{
    double volumn;

public:
    double lenght, width, height;
    // member function
    double getdata(double lenght, double height, double width);
    void setdata(double i);
    void displaydata()
    {
        cout << "The volumn is: " << volumn << endl;
    }
};

double box ::getdata(double lenght, double height, double width){
    
    double cal;
    return cal = lenght * height * width;

}

void box ::setdata(double i){
    volumn = i;
}

int main()
{
    box b;

    cout << "Enter the height: ";
    cin >> b.height;
    cout << "Enter the lenght: "; 
    cin >> b.lenght;
    cout << "Enter the width: ";
    cin >> b.width;

    b.getdata(b.height, b.lenght, b.width);

    b.setdata(b.getdata(b.height, b.lenght, b.width));

    b.displaydata();





    return 0;
}