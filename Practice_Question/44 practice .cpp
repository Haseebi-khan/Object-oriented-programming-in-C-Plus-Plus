// prevent the copy constructor from being called when an object is passed into a function in C++

#include <iostream>
#include <string>

using namespace std;

class ClassName {
public:
    // Constructor
    ClassName(const string& name) : name(name) {}

    // Copy constructor
    ClassName(const ClassName& other) {
        cout << "Copy constructor invoked." << endl;
        name = other.name;
    }

    // Member function
    void printName() const {
        cout << "Name: " << name << endl;
    }

private:
    string name;
};

// Approach 1: Pass by reference
void passByReference(const ClassName& obj) {
    obj.printName();
}

// Approach 2: Pass by pointer
void passByPointer(const ClassName* ptr) {
    ptr->printName();
}

// Approach 3: Move semantics (C++11 or later)
void moveSemantics(ClassName&& obj) {
    obj.printName();
}

int main() {
    ClassName obj("Object");

    // Testing pass by reference
    cout << "Pass by reference:" << endl;
    passByReference(obj);

    // Testing pass by pointer
    cout << "\nPass by pointer:" << endl;
    passByPointer(&obj);

    // Testing move semantics
    cout << "\nMove semantics:" << endl;
    moveSemantics(std::move(obj));

    return 0;
}



// We must use initializer list in a constructor./////////////////
// There is a reference variable in class
// There is a constant variable in class
// There is an object of another class. And the other class doesn\'t have default constructor.




#include<iostream>
using namespace std;

int &fun()
{
    static int x = 10;
    return x;
}
int main()
{
    fun() = 30;
    cout << fun();
    return 0;
}
//   30

#include <iostream>
using namespace std; 
class A
{
    int id;
    static int count;
public:
    A() {
        count++;
        id = count;
        cout << "constructor for id " << id << endl;
    }
    ~A() {
        cout << "destructor for id " << id << endl;
    }
};
 
int A::count = 0;
 
int main() {
    A a[3];
    return 0;
}

// constructor for id 1
// constructor for id 2
// constructor for id 3
// destructor for id 3
// destructor for id 2
// destructor for id 1





// / A program with virtual destructor
#include <iostream>
 
using namespace std;
 
class base {
  public:
    base()     
    { cout << "Constructing base\n"; }
    virtual ~base()
    { cout << "Destructing base\n"; }     
};
 
class derived : public base {
  public:
    derived()     
    { cout << "Constructing derived\n"; }
    ~derived()
    { cout << "Destructing derived\n"; }
};
 
int main()
{
  derived *d = new derived();  
  base *b = d;
  delete b;
  getchar();
  return 0;
}
// Output
// Constructing base
// Constructing derived
// Destructing derived
// Destructing base


// If we declare new and [] new operators, then the objects cannot be created anywhere 
// (within the class and outside the class) See the following example.
//  We can not allocate an object of type Test using new.


#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Test {
private:
    void* operator new(size_t size) {}
    void* operator new[](size_t size) {}
};

int main()
{
    Test *obj = new Test;
    Test *arr = new Test[10];
    return 0;
}


// cout is an object of ostream class which is a compiler defined class. When we do "cout << obj" 
// where obj is an object of our class, the compiler first looks for an operator function in ostream, 
// then it looks for a global function. One way to overload insertion operator is to modify ostream class which may not be a good idea. 
// So we make a global method. Following is an example.


#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;
public:
    Complex(int r = 0, int i =0)
    {
        real = r;
        imag = i;
    }
    friend ostream & operator << (ostream &out, const Complex &c);
};

ostream & operator << (ostream &out, const Complex &c)
{
    out << c.real;
    out << "+i" << c.imag;
    return out;
}

int main()
{
    Complex c1(10, 15);
    cout << c1;
    return 0;
}

// A postfix ++ has a dummy parameter

#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

class Test {
    int x;
public:
    void* operator new(size_t size);
    void operator delete(void*);
    Test(int i) {
        x = i;
        cout << "Constructor called \n";
    }
    ~Test() { cout << "Destructor called \n"; }
};


void* Test::operator new(size_t size)
{
    void *storage = malloc(size);
    cout << "new called \n";
    return storage;
}

void Test::operator delete(void *p )
{
    cout<<"delete called \n";
    free(p);
}

int main()
{
    Test *m = new Test(5);
    delete m;
    return 0;
}





/* local variable is same as a member\'s name */
class Test
{
private:
   int x;
public:
   void setX (int x)
   {
       // The \'this\' pointer is used to retrieve the object\'s x
       // hidden by the local variable \'x\'
       this->x = x;
   }
   void print() { cout << "x = " << x << endl; }
};
And following example for second and third point.
#include
using namespace std;
 
class Test
{
private:
  int x;
  int y;
public:
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
  Test &setX(int a) { x = a; return *this; }
  Test &setY(int b) { y = b; return *this; }
  void print() { cout << "x = " << x << " y = " << y << endl; }
};
 
int main()
{
  Test obj1(5, 5);
 
  // Chained function calls.  All calls modify the same object
  // as the same object is returned by reference
  obj1.setX(10).setY(20);
 
  obj1.print();
  return 0;
}



#include<iostream>
using namespace std;

int fun(int x = 0, int y = 0, int z)
{  return (x + y + z); }

int main()
{
   cout << fun(10);
   return 0;
}



#include <iostream>
using namespace std;

int fun(int=0, int = 0);

int main()
{
  cout << fun(5);
  return 0;
}

int fun(int x, int y) { return (x+y); }



// Not good code as destructor is not virtual
#include<iostream>
using namespace std;

class Base  {
public:
    Base()    { cout << "Constructor: Base" << endl; }
    ~Base()   { cout << "Destructor : Base" << endl; }
};

class Derived: public Base {
public:
    Derived()   { cout << "Constructor: Derived" << endl; }
    ~Derived()   { cout << "Destructor : Derived" << endl; }
};

int main()  {
    Base *Var = new Derived();
    delete Var;
    return 0;
}

// Output on GCC:
// Constructor: Base
// Constructor: Derived
// Destructor : Base




