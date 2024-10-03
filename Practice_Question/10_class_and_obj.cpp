#include <iostream>
using namespace std;

//////////////////                                               DONE

class Box
{
private:
    double volume;

public:
    double getData(double lenght, double height, double width);
    void dataCalculation(int dataOfBox);
    void displayData();
};

double Box::getData(double lenght, double height, double width)
{
    double Value = lenght * height * width;
    return Value;
}

void Box::dataCalculation(int Value) 
{ 
    volume = Value; 
}

void Box::displayData() 
{
    cout << "The Volume is: " << volume << endl; 
}

int main()
{
    Box b1;
    double lenght, height, width;
    cout << "Enter Height: ";
    cin >> height;
    cout << "Enter Lenght: ";
    cin >> lenght;
    cout << "Enter Width: ";
    cin >> width;

    b1.dataCalculation(b1.getData(height, lenght, width));

    b1.displayData();

    return 0;
}