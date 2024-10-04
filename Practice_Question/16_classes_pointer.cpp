#include <iostream>

using namespace std;

class Line
{

public:
    int getLength(void);
    Line(int len);         // simple constructor
    Line(const Line &obj); // copy constructor
    int getcopyiedlen(void);
    ~Line(); // destructor

private:
    int *ptr;
    int *copyptr;
};

// Member functions definitions including constructor
Line::Line(int len)
{
    cout << "Normal constructor allocating ptr" << endl;

    // allocate memory for the pointer;
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "Copy constructor allocating ptr." << endl;
    copyptr = new int;
    *copyptr = *obj.ptr; // copy the value
}

Line::~Line(void)
{
    cout << "Freeing memory!" << endl;
    delete ptr;
    delete copyptr; // Don't forget to deallocate the memory for copyptr
}

int Line::getLength(void)
{
    return *ptr;
}

int Line::getcopyiedlen(void)
{
    return *copyptr;
}

void display(Line obj)
{
    cout << "Length of line : " << obj.getLength() << endl;

    cout << "Copied ptr is: " << obj.getcopyiedlen() << endl;
}

// Main function for the program
int main()
{
    Line line(10);

    cout << "================================="<<endl;

    display(line);

    cout << "================================="<<endl;


    return 0;
}
