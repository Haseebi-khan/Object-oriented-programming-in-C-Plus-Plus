#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
};

class Room {
public:
    string id;
};

class hotel {
public:
    Person p;
    Room r;
    int age;
    virtual void add_person() = 0;
    virtual void dis() = 0;
    virtual ~hotel() {}  // Virtual destructor for proper cleanup
};

class staff : public virtual hotel {
public:
    void add_person() override {
        cout << "Staff CLASS" << endl;

        cout << "Enter your name: ";
        cin >> p.name;
        cout << "Enter your Id: ";
        cin >> r.id;
    }
    void dis() override {
        cout << "Staff CLASS" << endl;
        cout << "Your Name is: " << p.name << endl;
        cout << "Your ID is: " << r.id << endl;
    }
};

class Cust : public virtual hotel {
public:
    Cust()
    {
        age = 0;
    }
    void add_person() override {
        cout << "Enter your name: ";
        cin >> p.name;
        cout << "Enter your Age: ";
        cin >> age;
        cout << "Enter your Id: ";
        cin >> r.id;
    }
    void dis() override {
        cout << "Cust CLASS" << endl;
        cout << "Your Name is: " << p.name << endl;
        if (age == 0)
        cout << "Your Age is: " << age << endl;
        cout << "Your ID is: " << r.id << endl;
    }
};

class management : public staff, public Cust {
public:
    void add_person() override {
        // Decide which add_person to use, here using Cust's version
        Cust::add_person();
    }

    void dis() override {
        // Decide which dis to use, here using Cust's version
        staff::dis();
    }
};

int main() {
    management m;
    hotel* h = &m;  // Pointer to base class

    h->add_person();  // Polymorphic call
    h->dis();         // Polymorphic call

    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////??????????///////////////////////////????////////////////////

// #include <iostream>
// #include <string>

// using namespace std;

// class Person {
// public:
//     string name;
// };

// class Room {
// public:
//     string id;
// };

// class hotel {
// public:
//     Person p;
//     Room* r;  // Pointer to Room object
//     int age;

//     hotel() : r(new Room) {}  // Allocate memory for Room in the constructor

//     virtual void add_person() = 0;
//     virtual void dis() = 0;

//     virtual ~hotel() {  // Virtual destructor for proper cleanup
//         delete r;  // Deallocate memory for Room
//     }
// };

// class staff : public virtual hotel {
// public:
//     void add_person() override {
//         cout << "Staff CLASS" << endl;

//         cout << "Enter your name: ";
//         cin >> p.name;
//         cout << "Enter your Id: ";
//         cin >> r->id;
//     }

//     void dis() override {
//         cout << "Staff CLASS" << endl;
//         cout << "Your Name is: " << p.name << endl;
//         cout << "Your ID is: " << r->id << endl;
//     }
// };

// class Cust : public virtual hotel {
// public:
//     Cust() {
//         age = 0;
//     }

//     void add_person() override {
//         cout << "Enter your name: ";
//         cin >> p.name;
//         cout << "Enter your Age: ";
//         cin >> age;
//         cout << "Enter your Id: ";
//         cin >> r->id;
//     }

//     void dis() override {
//         cout << "Cust CLASS" << endl;
//         cout << "Your Name is: " << p.name << endl;
//         if (age != 0) {
//             cout << "Your Age is: " << age << endl;
//         }
//         cout << "Your ID is: " << r->id << endl;
//     }
// };

// class management : public staff, public Cust {
// public:
//     void add_person() override {
//         // Decide which add_person to use, here using Cust's version
//         Cust::add_person();
//     }

//     void dis() override {
//         // Decide which dis to use, here using Cust's version
//         Cust::dis();
//     }
// };

// int main() {
//     management m;
//     hotel* h = &m;  // Pointer to base class

//     h->add_person();  // Polymorphic call
//     h->dis();         // Polymorphic call

//     return 0;
// }
