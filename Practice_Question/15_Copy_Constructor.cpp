// #include <iostream>

// using namespace std;

// class Example
// {
// private:
//     int x;

// public:
//     Example(int a)
//     {
//         x = a;
//     }

//     Example(const Example &e)
//     {
//         x = (e.x) * x + 1;
//     }

//     void print()
//     {
//         cout << "x= " << x << endl;
//         ;
//     }
// };

// int main()
// {

//     Example p(5);
//     Example p1(p); // Example p1(p);
//     cout << "Shallow Copy."<<endl;

//     p.print();
//     p1.print();

//     return 0;
// }

// // ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>

// using namespace std;

// class Line
// {
// private:
//     int *ptr;
//     int *copyptr;

// public:
//     Line(int len)
//     {
//         cout << "Normal constructor allocating ptr" << endl;

//         ptr = new int;
//         *ptr = len;
//     }
//     ~Line();
//     Line(const Line &obj);
//     int getcopyiedlen(void);
//     int getLength(void);
//     void display(const Line &obj);

//     void set()
//     {
//         ptr = new int;
//         *ptr = 10;
//     }
// };

// Line::Line(const Line &obj)
// {
//     cout << "Copy constructor allocating ptr." << endl;
//     copyptr = new int;
//     *ptr = *obj.ptr;
//     *copyptr = *obj.ptr;
// }

// Line::~Line(void)
// {
//     cout << "Freeing memory!" << endl;
//     delete ptr;
//     delete copyptr;
// }

// int Line::getLength(void)
// {
//     return *ptr;
// }

// int Line::getcopyiedlen(void)
// {
//     return *copyptr;
// }

// void display(Line obj)
// {
//     cout << "Length of line : " << obj.getLength() << endl;

//     cout << "Copied ptr is: " << obj.getcopyiedlen() << endl;
// }

// int main()
// {
//     Line line(66);
//     Line s = line;

//     line.set();

//     cout << "=================================" << endl;

//     display(line);

//     cout << "=================================" << endl;

//     display(s);

//     cout << "=================================" << endl;

//     return 0;
// }

// #include <iostream>

// using namespace std;

// class Line
// {
// private:
//     int *ptr;

// public:
//     Line()
//     {
//         ptr = new int;
//         *ptr = 0;
//     }
//     ~Line();               // destructor
//     Line(int len);         // simple constructor
//     Line(const Line &obj); // copy constructor
//     int getLength(void);
//     void display();

// };

// // Member functions definitions including constructor
// Line::Line(int len)
// {
//     cout << "Normal constructor allocating ptr" << endl;

//     // allocate memory for the pointer;
//     ptr = new int;
//     *ptr = len;
// }

// Line::Line(const Line &obj)
// {
//     cout << "Copy constructor allocating ptr." << endl;
//     ptr = new int;
//     *ptr = *obj.ptr; // copy the value
// }

// Line::~Line(void)
// {
//     cout << "Freeing memory!" << endl;
//     delete ptr;
// }

// int Line::getLength(void)
// {
//     return *ptr;
// }

// void Line::display()
// {
//     cout << "Length of line : " << *ptr << endl;
// }

// void display(Line obj)
// {
//     cout << "Length of line : " << obj.getLength() << endl;
// }

// // Main function for the program
// int main()
// {
//     Line line(10);

//     display(line);

//     line.display();

//     return 0;
// }

// // =====================

// // Example – Class Where a Copy Constructor is Required
// // Following is a complete C++ program to demonstrate the use of the Copy constructor.
// // In the following String class, we must write a copy constructor.

// // Example:

// // // C++ program to demonstrate the
// // // Working of Copy constructor
// #include <cstring>
// #include <iostream>
// using namespace std;

// class String {
// private:
//     char* s;
//     int size;

// public:
//     String(const char* str = NULL); // constructor
//     ~String() { delete[] s; } // destructor
//     String(const String&); // copy constructor
//     void print()
//     {
//         cout << s << endl;
//     } // Function to print string
//     void change(const char*); // Function to change
// };

// String::String(const char* str)
// {
//     size = strlen(str);
//     s = new char[size + 1];
//     strcpy(s, str);
// }

// void String::change(const char* str)
// {
//     delete[] s;  // can we overwrite.
//     size = strlen(str);

//     s = new char[size + 1];
//     strcpy(s, str);
// }

// String::String(const String& old_str)
// {
//     size = old_str.size;
//     s = new char[size + 1];
//     strcpy(s, old_str.s);
// }

// int main()
// {
//     String str1("GeeksQuiz");
//     String str2 = str1;

//     str1.print(); // what is printed ?
//     str2.print();

//     str2.change("GeeksforGeeks");

//     str1.print(); // what is printed now ?
//     str2.print();
//     return 0;
// }
// // Output
// // GeeksQuiz
// // GeeksQuiz
// // GeeksQuiz
// // GeeksforGeeks

// // ======================
// #include <iostream>

// using namespace std;

// class Line
// {
// private:
// 	int *ptr;
// 	int *copyptr;

// public:
// 	Line(int len)
// 	{
// 		cout << "Normal constructor allocating ptr" << endl;
// 		ptr = new int;
// 		*ptr = len;
// 		copyptr = new int; // Allocate memory for copyptr
// 		*copyptr = 0;
// 	}
// 	~Line()
// 	{
// 		cout << "Freeing memory!" << endl;
// 		delete ptr;
// 		delete copyptr;
// 	}
// 	Line(const Line &obj)
// 	{
// 		cout << "Copy constructor allocating ptr." << endl;
// 		ptr = new int;
// 		*ptr = *obj.ptr;
// 		copyptr = new int;		 // Allocate memory for copyptr
// 		*copyptr = *obj.copyptr; // Copy the value
// 	}
// 	int getcopyiedlen(void)
// 	{
// 		return *copyptr;
// 	}
// 	int getLength(void)
// 	{
// 		return *ptr;
// 	}

// 	void set(int len)
// 	{
// 		delete ptr;
// 		delete copyptr;
// 		ptr = new int;
// 		*ptr = len;
// 		*copyptr = len;

// 	}
// 	void display()
// 	{
// 		cout << "Length of line : " << *ptr  << endl;
// 		cout << "Copied ptr is: " << *copyptr << endl;
// 	}
// };

// int main()
// {
// 	Line line(66);
// 	Line s = line;

// 	s.set(45);

// 	cout << "=================================" << endl;

// 	line.display();

// 	cout << "=================================" << endl;

// 	s.display();

// 	cout << "=================================" << endl;

// 	return 0;
// }

// // //////////

// // Copy Constructor in C++
// // Last Updated : 30 Jan, 2024
// // Pre-requisite: Constructor in C++

// // A copy constructor is a member function that initializes an object using another object of the same class. In simple terms, a constructor which creates an object by initializing it with an object of the same class, which has been created previously is known as a copy constructor.

// // Copy constructor is used to initialize the members of a newly created object by copying the members of an already existing object.

// // Copy constructor takes a reference to an object of the same class as an argument.

// // Sample(Sample &t)
// // {
// //     id=t.id;
// // }
// // The process of initializing members of an object through a copy constructor is known as copy initialization.

// // It is also called member-wise initialization because the copy constructor initializes one object with the existing object, both belonging to the same class on a member by member copy basis.

// // The copy constructor can be defined explicitly by the programmer. If the programmer does not define the copy constructor, the compiler does it for us.

// // Example:

// // Syntax of Copy Constructor with Example
// // Syntax of Copy Constructor

// #include <iostream>
// #include <string.h>
// using namespace std;
// class student {
//     int rno;
//     char name[50];
//     double fee;

// public:
//     student(int, char[], double);
//     student(student& t) // copy constructor
//     {
//         rno = t.rno;
//         strcpy(name, t.name);
//         fee = t.fee;
//     }
//     void display();
// };

// student::student(int no, char n[], double f)
// {
//     rno = no;
//     strcpy(name, n);
//     fee = f;
// }

// void student::display()
// {
//     cout << endl << rno << "\t" << name << "\t" << fee;
// }

// int main()
// {
//     student s(1001, "Manjeet", 10000);
//     s.display();

//     student manjeet(s); // copy constructor called
//     manjeet.display();

//     return 0;
// }
// // Output
// // 1001    Manjeet    10000
// // 1001    Manjeet    10000

// #include <iostream>
// #include <string.h>
// using namespace std;
// class student {
//     int rno;
//     char name[50];
//     double fee;

// public:
//     student(int, char[], double);
//     student(student& t) // copy constructor (member wise
//                         // initialization)
//     {
//         rno = t.rno;
//         strcpy(name, t.name);
//     }
//     void display();
//     void disp() { cout << endl << rno << "\t" << name; }
// };
// student::student(int no, char n[], double f)
// {
//     rno = no;
//     strcpy(name, n);
//     fee = f;
// }

// void student::display()
// {
//     cout << endl << rno << "\t" << name << "\t" << fee;
// }

// int main()
// {
//     student s(1001, "Manjeet", 10000);
//     s.display();

//     student manjeet(s); // copy constructor called
//     manjeet.disp();

//     return 0;
// }
// // Output
// 1001    Manjeet    10000
// 1001    Manjeet
// Characteristics of Copy Constructor
// 1. The copy constructor is used to initialize the members of a newly created object by copying the members of an already existing object.

// 2. Copy constructor takes a reference to an object of the same class as an argument. If you pass the object by value in the copy constructor, it would result in a recursive call to the copy constructor itself. This happens because passing by value involves making a copy, and making a copy involves calling the copy constructor, leading to an infinite loop. Using a reference avoids this recursion. So we use reference of Objects to avoid infinite calls.

// Sample(Sample &t)
// {
//        id=t.id;
// }
// 3. The process of initializing members of an object through a copy constructor is known as copy initialization.

// 4. It is also called member-wise initialization because the copy constructor initializes one object with the existing object, both belonging to the same class on a member-by-member copy basis.

// 5. The copy constructor can be defined explicitly by the programmer. If the programmer does not define the copy constructor, the compiler does it for us.

// Example:

// C++ program to demonstrate the working
// // of a COPY CONSTRUCTOR
// #include <iostream>
// using namespace std;

// class Point {
// private:
//     int x, y;

// public:
//     Point(int x1, int y1)
//     {
//         x = x1;
//         y = y1;
//     }

//     // Copy constructor
//     Point(const Point& p1)
//     {
//         x = p1.x;
//         y = p1.y;
//     }

//     int getX() { return x; }
//     int getY() { return y; }
// };

// int main()
// {
//     Point p1(10, 15); // Normal constructor is called here
//     Point p2 = p1; // Copy constructor is called here

//     // Let us access values assigned by constructors
//     cout << "p1.x = " << p1.getX()
//          << ", p1.y = " << p1.getY();
//     cout << "\np2.x = " << p2.getX()
//          << ", p2.y = " << p2.getY();
//     return 0;
// }