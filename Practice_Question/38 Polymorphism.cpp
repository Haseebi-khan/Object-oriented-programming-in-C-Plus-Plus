#include <iostream>
using namespace std;

class Shape
{
protected:
    int width, height;

public:
    Shape(int a = 0, int b = 0)
    {
        width = a;
        height = b;
    }
    int virtual area()
    {
        cout << "Parent class area :" << width * height << endl;
        return width * height;
    }
};
class Rectangle : public virtual Shape
{
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {}

     int area() override
    {
        cout << "Rectangle class area :" << width * height << endl;
        return (width * height);
    }
};

class Triangle : public virtual Shape 
{
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {}

    int  area() override
    {
        cout << "Triangle class area :" << ( width * height ) / 2 << endl;
        return (width * height / 2);
    }
};

class Both: public Rectangle, public Triangle 
{
    int i;
public:
    Both(int a, int b,int i):Shape(a, b), Rectangle(a, b), Triangle(a, b) 
    {
        this->i = i;
    }
    int area() override
    {
        if (i == 0) 
        {
            return Rectangle::area();
        }
        else
        {
            return Triangle::area();
        }
        
    }
};

int main()
{
    Shape *shape;
    Both a(10,3, 1);
    shape = &a;
    a.area();
    Shape;

    return 0;
}