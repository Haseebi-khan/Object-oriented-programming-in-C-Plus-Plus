#include <iostream>
#include <cstring>
using namespace std;

//                      DONE

class Example //    Shallow Copy
{
private:
    int x;

public:
    Example(int x)
    {
        this->x = x;
    }
    Example(const Example &e)
    {
        this->x = e.x + 2;
    }
    void print()
    {
        cout << "X : " << x << endl;
    }
};

class Line //        Deep Copy
{
private:
    int *ptr;
    int *copyptr;

public:
    Line();
    ~Line();
    Line(const Line &obj);
    void setData(int num);
    void display();
};
Line::Line()
{
    ptr = new int;
    copyptr = new int;
    *ptr = 0;
    *copyptr = 0;
}
Line::~Line()
{
    delete ptr;
    delete copyptr;
}
Line::Line(const Line &obj)
{
    ptr = new int;
    copyptr = new int;
    *ptr = *(obj.ptr);
    *copyptr = *(obj.ptr);
}
void Line::setData(int num)
{
    if (ptr != nullptr)
    {
        *ptr = num;
    }
}
void Line::display()
{
    if (ptr != nullptr && copyptr != nullptr)
    {
        cout << *ptr << " ... " << *copyptr << endl;
    }
    else
    {
        cout << "Pointers are Null";
    }
}

class String
{
private:
    char *ch_string;
    int size;

public:
    String();
    String(const char *str);
    ~String() { delete[] ch_string; }
    String(const String *obj);
    void display()
    {
        int i = 0;
        while (ch_string[i] != '\0')
        {
            cout << ch_string[i];
            i++;
        }
        cout << "\n";
    }
};

String::String()
{
    size = 1;
    ch_string = new char[size + 1];
    strcpy(ch_string, "");
}

String::String(const char *str)
{
    size = strlen(str);
    ch_string = new char[size + 1];
    strcpy(ch_string, str);
}

String::String(const String *obj)
{
    size = obj->size;
    ch_string = new char[size + 1];
    strcpy(ch_string, obj->ch_string);
}

class student
{
    char name[50];
    int rno;
    double fee;

public:
    student(int, string n, double);
    student(const student &t) // copy constructor
    {
        rno = t.rno;
        strcpy(name, t.name);
        fee = t.fee;
    }
    void display();
};

student::student(int no, string n, double f)
{
    rno = no;
    int size = n.length();
    for (int i = 0; i < size + 1; i++)
    {
        name[i] = n[i];
    }

    fee = f;
}

void student::display()
{
    cout << endl
         << rno << "\t" << name << "\t" << fee;
}

class Point
{
private:
    int x, y;

public:
    Point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }

    Point(const Point &p1)
    {
        x = p1.x;
        y = p1.y;
    }

    int getX() { return x; }
    int getY() { return y; }
};

int main()
{
    cout << "First Class.\n\n";
    Example a(20);
    Example a2(a);
    a.print();
    a2.print();
    cout << "\nSecond Class.\n\n";
    Line b;
    b.setData(10);
    Line b2(b);
    b.display();
    b2.display();

    cout << "Thrid Class.\n\n";
    String strobj("StringObjectTasting");
    String strobj2(&strobj);
    String strobj3;
    strobj.display();
    strobj2.display();
    strobj3.display();

    cout << "fourth Class.\n";

    student s(1001, "Manjeet", 10000);
    s.display();

    student manjeet(s);
    manjeet.display();

    cout << "\n\nFifth Class.\n\n";
    Point p1(10, 15);
    Point p2 = p1;

    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
    cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();

    cout << endl;
    return 0;
}