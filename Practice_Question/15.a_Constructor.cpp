// #include <iostream>
// using namespace std;

// class PublicConstructor {
// public:
//     // Public constructor
//     PublicConstructor() {
//         cout << "Public constructor called" << endl;
//     }
// };

// class ProtectedConstructor {
// protected:
//     // Protected constructor
//     ProtectedConstructor() {
//         cout << "Protected constructor called" << endl;
//     }
// };

// class PrivateConstructor {
// private:
//     // Private constructor
//     PrivateConstructor() {
//         cout << "Private constructor called" << endl;
//     }

// public:
//     // Public static method to create instances of the class
//     static PrivateConstructor* createInstance() {
//         return new PrivateConstructor();
//     }
// };

// int main() {
//     // Creating object using public constructor
//     PublicConstructor obj1;

//     // Creating object using protected constructor (will cause a compilation error)
//     // ProtectedConstructor obj2;

//     // Creating object using private constructor (will cause a compilation error)
//     // PrivateConstructor obj3;

//     // Creating object using public static method of PrivateConstructor
//     PrivateConstructor* obj4 = PrivateConstructor::createInstance();

//     delete obj4;

//     return 0;
// }




// #include <iostream>

// using namespace std;

// class X
// {
//     int x, y;
//     public:
//     X(){}
//     X(const X& p)
//     {
//         x = p.x;
//         y = p.y;
//     }
//     int xx()
//     {
//         return x;
//     }
//    int yy()
//     {
//         return y;
//     }
// };

// int main()
// {
//     X a;
//     X b = a;

//     cout << a.xx() << " " << a.yy() <<endl;
//     cout << b.xx() << " " << b.yy() <<endl;

//     return 0;
// }

// #include <iostream>
// #include <string.h>

// using namespace std;

// class String
// {
//     char *str;
//     public:
//     String(const char* y)
//     {
//         str = new char[strlen(y)+1];
//         strcpy(str,y);

//     }
//     String(const String& obj)
//     {
//         str = new char[strlen(obj.str)+1];
//         strcpy(str,obj.str);
//     }
//     ~String()
//     {
//         delete[] str;
//     }

//     const char* get() const
//     {
//         return str;
//     }

// };

// int main()

// {
//     String s1("sfdsd");
//     String s2 = s1;

//     cout << s1.get() <<" ";
//     cout << s2.get();

//     return 0;
// }
