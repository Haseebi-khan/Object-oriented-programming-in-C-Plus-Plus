// #include <iostream>
// using namespace std;

// class Array
// {
// private:
//     int size;
//     int *data;
// public:
//     // Constructor
//     Array(): size(0), data(nullptr) {}
//     Array(int sz)
//     {
//         size = sz;
//         data = new int[sz];
//     }
//     // Copy Constructor for deep copy
//     Array(const Array &other)
//     {
//         size = other.size;
//         data = new int[other.size];
//         for (int i = 0; i < size; ++i)
//         {
//             data[i] = other.data[i];
//         }
//     }
//     // Destructor
//     ~Array()
//     {
//         delete[] data;
//     }
//     // Function to set value at index
//     void setValue(int index, int value)
//     {
//         if (index >= 0 && index < size)
//             data[index] = value;
//     }

//     // Function to print array
//     void print()
//     {
//         for (int i = 0; i < size; ++i)
//         {
//             cout << data[i] << " ";
//         }
//         cout << endl;
//     }
// };
// int main()
// {
//     // Create an Array object
//     Array arr1(5);
//     arr1.setValue(0, 1);
//     arr1.setValue(1, 2);
//     arr1.setValue(2, 3);
//     arr1.setValue(3, 4);
//     arr1.setValue(4, 5);
//     // Create a copy of arr1 using the copy constructor
//     Array arr2 = arr1;
//     // Modify arr2
//     arr2.setValue(0, 10);
//     // Print both arrays
//     cout << "Array 1: ";
//     arr1.print();
//     cout << "Array 2: ";
//     arr2.print();
//     return 0;
// }

// ===========================================================================================

// C++ Copy Constructor
// A Copy constructor is an overloaded constructor used to declare and initialize an object from another object.

// Copy Constructor is of two types:
// Default Copy constructor: The compiler defines the default copy constructor. If the user defines no copy constructor, compiler supplies its constructor.
// User Defined constructor: The programmer defines the user-defined constructor.
// C++ Copy Constructor
// Syntax Of User-defined Copy Constructor:
// Class_name(const class_name &old_object);
// Consider the following situation:

// class A
// {
//     A(A &x) //  copy constructor.
//    {
//        // copyconstructor.
//    }
// }
// In the above case, copy constructor can be called in the following ways:

// C++ Copy Constructor
// Let's see a simple example of the copy constructor.

// // program of the copy constructor.

// #include <iostream>
// using namespace std;
// class A
// {
// public:
//     int x;
//     A(int a) // parameterized constructor.
//     {
//         x = a;
//     }
//     A(A &i) // copy constructor
//     {
//         x = i.x;
//     }
// };
// int main()
// {
//     A a1(20); // Calling the parameterized constructor.
//     A a2(a1); //  Calling the copy constructor.
//     cout << a2.x;
//     return 0;
// }
// Output:

// 20
// When Copy Constructor is called
// Copy Constructor is called in the following scenarios:

// When we initialize the object with another existing object of the same class type. For example, Student s1 = s2, where Student is the class.
// When the object of the same class type is passed by value as an argument.
// When the function returns the object of the same class type by value.
// Two types of copies are produced by the constructor:
// Shallow copy
// Deep copy
// Shallow Copy
// The default copy constructor can only produce the shallow copy.
// A Shallow copy is defined as the process of creating the copy of an object by copying data of all the member variables as it is.
// Let's understand this through a simple example:

// #include <iostream>

// using namespace std;

// class Demo
// {
//     int a;
//     int b;
//     string *p;
//     public:
//     Demo() : a(0), b(0), p(nullptr)
//     {

//     }
//     void setdata(int x,int y,string z)
//     {
//         a=x;
//         b=y;
//         p = new string(z);
//     }
//     Demo(const Demo& v )
//     {
//         a = v.a;
//         b = v.b;
//         p = new string;
//         *p = *v.p;
//     }
//     void showdata()
//     {
//         std::cout << "value of a is : " <<a<< std::endl;
//         std::cout << "value of b is : " <<b<< std::endl;
//         std::cout << "value of *p is : " <<*p<< std::endl;
//     }
// };
// int main()
// {
//   Demo d1;
//   d1.setdata(4,5,"7");
//   Demo d2 = d1;
//   d2.showdata();
//     return 0;
// }
// Output:

// value of a is : 4
// value of b is : 5
// value of *p is : 7
// C++ Copy Constructor
// In the above case, a programmer has not defined any constructor, therefore,
// the statement Demo d2 = d1; calls the default constructor defined by the compiler.
// The default constructor creates the exact copy or shallow copy of the existing object.
// Thus, the pointer p of both the objects point to the same memory location. Therefore,
// when the memory of a field is freed, the memory of another field is also automatically freed as both the fields point to the same memory location.
//  This problem is solved by the user-defined constructor that creates the Deep copy.

// Deep copy
// Deep copy dynamically allocates the memory for the copy and then copies the actual value,
// both the source and copy have distinct memory locations. In this way, both the source and copy are distinct and will not share the same memory location.
// Deep copy requires us to write the user-defined constructor.

// Let's understand this through a simple example.

// #include <iostream>
// using namespace std;
// class Demo
// {
//     public:
//     int a;
//     int b;
//     int *p;

//     Demo()
//     {
//         p=new int;
//     }
//     Demo(Demo &d)
//     {
//         a = d.a;
//         b = d.b;
//         p = new int;
//         *p = (*d.p);
//     }
//     void setdata(int x,int y,int z)
//     {
//         a=x;
//         b=y;
//         *p=z;
//     }
//     void showdata()
//     {
//         std::cout << "value of a is : " <<a<< std::endl;
//         std::cout << "value of b is : " <<b<< std::endl;
//         std::cout << "value of *p is : " <<*p<< std::endl;
//     }
// };
// int main()
// {
//   Demo d1;
//   d1.setdata(4,5,7);
//   Demo d2 = d1;
//   d2.showdata();
//   return 0;
// }
// Output:

// value of a is : 4
// value of b is : 5
// value of *p is : 7

// C++ Copy Constructor
// In the above case, a programmer has defined its own constructor,
// therefore the statement Demo d2 = d1; calls the copy constructor defined by the user.
// It creates the exact copy of the value types data and the object pointed by the pointer p.
// Deep copy does not create the copy of a reference type variable.

// // C++ program to demonstrate
// // the working of copy elision
// #include <iostream>
// #include <string.h>
// using namespace std;

// class GFG
// {
//     int size;
//     char *s;

// public:
//     GFG() : size(0), s(nullptr) {}
//     // constructor
//     GFG(const int siz, char *str)
//     {
//         this->size = siz;
//         s = new char[size + 1];
//         strcpy(s, str);
//     }
//     // destructor

//     ~GFG()
//     {
//         delete[] s;
//     }
//     // deep copy constructor
//     GFG(const GFG &a)
//     {
//         cout << "called deep copy constructor\n";
//         size = a.size;
//         s = new char[size + 1];
//         strcpy(s, a.s);
//     }
//     // printing
//     void print()
//     {
//         cout << " GFG: " << size << endl;
//         cout << "String : " << s << endl;
//     }
//     void setvalue(const char *i)
//     {
//         delete[] s;
//         s = new char[size + 1];
//         strcpy(s, i);
//     }
// };

// int main()
// {
//     GFG G;
//     G.print();

//     GFG Q = G;
//     GFG w(Q);

//     cout << &G << endl;
//     cout << &Q << endl;
//     cout << &w << endl;
//     Q.setvalue("kjhkhkj");
//     w.setvalue("qqqqqqq");

//     G.print();
//     Q.print();
//     w.print();

//     return 0;
// }

// #include <iostream>

// using namespace std;

// class Line
// {
// private:
//     int *ptr;
//     int *copyptr;

// public:
//     Line()
//     {
//         ptr = new int;
//         copyptr = new int;
//     }
//     Line(int len)
//     {
//         cout << "Normal constructor allocating ptr" << endl;
//         ptr = new int;
//         copyptr = new int(len);
//         *ptr = len;
//     }
//     Line(int len,int copyp)
//     {
//         cout << "Normal constructor allocating ptr" << endl;
//         ptr = new int;
//         copyptr = new int(copyp);
//         *ptr = len;
//     }
//     ~Line()
//     {
//         cout << "Freeing memory!" << endl;
//         delete ptr;
//         delete copyptr;
//     }

//     Line(const Line &obj)
//     {
//         cout << "Copy constructor allocating ptr." << endl;
//         copyptr = new int(*obj.ptr);
//         ptr = new int(*obj.ptr);
//     }
//     int getLength(void)
//     {
//         return *ptr;
//     }
//     int getcopyiedlen(void)
//     {
//         return *copyptr;
//     }
//     void display()
//     {
//         cout << "Length of line : " << getLength() << endl;

//         cout << "Copied ptr is: " << getcopyiedlen() << endl;
//     }
// };

// int main()
// {
//     Line line(66);

//     Line line2 = line;
//     cout << " ---------------------------------------" << endl;
//     line2.display();
//     cout << " ---------------------------------------" << endl;

//     Line line3(44,33);
//     line3.display();
//     line = line3;
//     line.display();

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int d = 78;

//     int* ptr = &d;
//     int* a;
//     cout << a <<endl;
//     cout << *a <<endl;
//     cout << "ID = &d: " << &d <<endl;
//     cout << "ID = *(&d): " << *(&d) <<endl;
//     cout << "ID = *ptr " << *ptr <<endl;
//     cout << "ID = *(ptr)" << *(ptr) <<endl;
//     return 0;
// }