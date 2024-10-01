#include <iostream>
using namespace std;

class Person
{
    protected:
        string name;
        int age;
    public:
        Person(string n = "", int a = 0) : name(n), age(a) {}
        virtual void displayDetails()
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

int main()
{
    Person* p;

    Person p1("haseeb", 20);
    p1.displayDetails();

    p = &p1;
    p->displayDetails();

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// Derive two classes, Student and Teacher, from Person. Add a private member variable studentId in the Student class
// and teacherId in the Teacher class. Implement the displayDetails() function in each derived class to display the
// additional information along with the name and age.
#include <iostream>
using namespace std;

class Person 
{
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}

    virtual void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person 
{
private:
    int studentId;

public:
    Student(string n = "", int a = 0, int id = 0) : Person(n, a), studentId(id) {}

    void displayDetails()
     {
        Person::displayDetails();
        cout << "Student ID: " << studentId << endl;
    }
};

class Teacher : public Person
 {
private:
    int teacherId;

public:
    Teacher(string n = "", int a = 0, int id = 0) : Person(n, a), teacherId(id) {}

    void displayDetails() 
    {
        Person::displayDetails();
        cout << "Teacher ID: " << teacherId << endl;
    }
};

int main() 
{
    Person* p;

    Student s("Haseeb", 20, 10009);
    Teacher t("Ahmed", 45, 1232);

    p = &s;
    p->displayDetails();
    cout << "--------------------------------------------------\n";

    p = &t;
    p->displayDetails();

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////



// Derive two classes, Student and Teacher, from Person. Add a private member variable studentId in the Student class
// and teacherId in the Teacher class. Implement the displayDetails() function in each derived class to display the
// additional information along with the name and age.

#include <iostream>
using namespace std;

class Person 
{
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}

    virtual void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person 
{
private:
    int studentId;

public:
    Student(string n = "", int a = 0, int id = 0) : Person(n, a), studentId(id) {}

    void displayDetails()
     {
        Person::displayDetails();
        cout << "Student ID: " << studentId << endl;
    }
};

class Teacher : public Person
 {
private:
    int teacherId;

public:
    Teacher(string n = "", int a = 0, int id = 0) : Person(n, a), teacherId(id) {}

    void displayDetails() 
    {
        Person::displayDetails();
        cout << "Teacher ID: " << teacherId << endl;
    }
};

int main() 
{

    Student s("Haseeb", 20, 10009);
    Teacher t("Ahmed", 45, 1232);

    s.displayDetails();

    cout << "--------------------------------------------------\n";
    
    t.displayDetails();

    return 0;
}


////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double calculateArea() const = 0;
    virtual void resize(double len, double wid) {}
    virtual void resize(double r) {}
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l = 0, double w = 0) : length(l), width(w) {}
    void resize(double len, double wid ) {
        length = len;
        width = wid;
    }

    double calculateArea() const
    {
        return length * width;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r = 0) : radius(r) {}
    void resize(double r) {
        radius = r;
    }

    double calculateArea() const 
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    Rectangle rect(5, 3);
    Circle circ(7);

    Shape* shape;

    shape = &rect;
    
    cout << "Rectangle Area: " << shape->calculateArea() << endl;
    rect.resize(6, 5);

    cout << "Resize Rectangle Area: " << shape->calculateArea() << endl;

    cout << "------------------------------" << endl;

    shape = &circ;
    cout << "Circle Area: " << shape->calculateArea() << endl;
    circ.resize(6);
    cout << "Resize Circle Area: " << shape->calculateArea() << endl;

    return 0;
}




