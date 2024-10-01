#include <iostream>
using namespace std;

class Shape
{
protected:
    int width, height;

public:
    Shape(int a = 0, int b = 0) : width(a), height(b) {
        cout << "sdfsdfsd";
    }
    virtual int area() = 0; // Making this a pure virtual function
};

class Rectangle : public virtual Shape
{
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {}

    int area() override
    {
        cout << "Rectangle class area: " << width * height << endl;
        return width * height;
    }
};

class Triangle : public virtual Shape
{
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {}

    int area() override
    {
        cout << "Triangle class area: " << (width * height) / 2 << endl;
        return (width * height) / 2;
    }
};

class Both : public Rectangle, public Triangle
{
private:
    int shapeType; // 0 for Rectangle, 1 for Triangle

public:
    Both(int a, int b, int i) : Shape(a, b), Rectangle(a, b), Triangle(a, b), shapeType(i) {}

    int area() override
    {
        if (shapeType == 0)
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
    Shape* shape;
    Both a(10, 3, 0); // Initialize Both with width 10, height 3, and shapeType 0 (Rectangle)
    shape = &a;
    shape->area(); // Calls Both's area method which calls Rectangle's area

    Both b(10, 3, 1); // Initialize Both with width 10, height 3, and shapeType 1 (Triangle)
    shape = &b;
    shape->area(); // Calls Both's area method which calls Triangle's area

    return 0;
}
