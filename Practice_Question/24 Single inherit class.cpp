#include <iostream>
using namespace std;

class Employee
{
protected:
    string employee_registeration_number;
    string employee_name;
    string destination;

public:
    Employee()
    {
        cout << "Enter Employee reg: 1 \n";
        employee_registeration_number = "01";
        cout << "Enter the Employee Name: ALI\n";
        employee_name = "ALI";
        cout << "Enter Destination: Association\n";
        destination = "Association";
    }
};

class Salary : protected Employee
{
protected:
    int sum = 0;

public:
    int human_resource_Allowance;
    int basic_salary;
    int profitable_fund;

    Salary()
    {
        cout << "Enter the Human resource Allowance: 23\n";
        human_resource_Allowance = 20;
        cout << "Enter Basic salary: 20\n";
        basic_salary = 20;
        cout << "Enter Profitable fund: 20\n";
        profitable_fund = 20;
        sum = human_resource_Allowance + basic_salary + profitable_fund;
    }
    void getter_salary()
    {
        cout << "Name : " << employee_name << endl;
        cout << "The total salary is : " << human_resource_Allowance + basic_salary + profitable_fund << endl;
    }
};

class checking_details : protected Salary
{
public:
    checking_details()
    {
        cout << "Name : " << employee_name << endl;
        cout << "total sal : " << sum << endl;
    }
    void getter_salary()
    {
        cout << "Name : " << employee_name << endl;
        cout << "The total salary is : " << human_resource_Allowance + basic_salary + profitable_fund << endl;
    }
};
int main()
{
    checking_details sal;
    sal.getter_salary();

    return 0;
}

//============================================================================//============================================================================
//============================================================================//============================================================================

#include <iostream>
using namespace std;

class A
{
    int x;

public:
    void set_x(int c)
    {
        x = c;
    }
    void get_x()
    {
        cout << x << endl;
    }
};

class B : public A
{
public:
};

int main()
{
    B b;
    b.set_x(10);
    b.get_x();
    return 0;
}

//============================================================================//============================================================================
//============================================================================//============================================================================

#include <iostream>
#include <string>
using namespace std;
class A
{
    int a, b;
    float d;

public:
    void change(int i)
    {
        a = i;
    }
    void value_of_a()
    {
        cout << a;
    }
};

class B : private A
{
};

int main(int argc, char const *argv[])
{
    B b;
    cout << sizeof(B);
    return 0;
}

//============================================================================//============================================================================
//============================================================================//============================================================================

#include <iostream>
#include <string>
using namespace std;
class A
{
    float d;

public:
    int a;
    void change(int i)
    {
        a = i;
    }
    void value_of_a()
    {
        cout << a;
    }
};

class B : public A
{
    int a = 15;

public:
    void print()
    {
        cout << a;
    }
};

int main(int argc, char const *argv[])
{
    B b;
    b.change(10);
    b.print();
    b.value_of_a();

    return 0;
}
//============================================================================//============================================================================
//============================================================================//============================================================================
#include <iostream>
#include <string>
using namespace std;
class A
{
    float d;

public:
    A()
    {
        cout << "Constructor of class A\n";
    }
};

class B : public A
{
    int a = 15;

public:
    B()
    {
        cout << "Constructor of class B\n";
    }
};

int main(int argc, char const *argv[])
{
    B b;
    return 0;
}

//============================================================================//============================================================================
//============================================================================//============================================================================

#include <iostream>
#include <string>
using namespace std;

class A
{
    float d;

public:
    virtual void func()
    {
        cout << "Hello this is class A\n";
    }
};

class B : public A
{
    int a = 15;

public:
    void func()
    {
        cout << "Hello this is class B\n";
    }
};

int main(int argc, char const *argv[])
{
    A *a = new B(); // Create an object of class B and assign its address to pointer a
    a->func();      // Calls the overridden function func() of class B

    delete a; // Delete the allocated object to prevent memory leaks
    return 0;
}

//============================================================================//============================================================================
//============================================================================//============================================================================

#include <iostream>

class Base
{
public:
    virtual void ShowMessage()
    {
        std::cout << "Base class message\n";
    }
};

class Derived : public Base
{
private:
    std::string myValue;

public:
    explicit Derived(const std::string &value)
        : myValue(value)
    {
    }

    virtual void ShowMessage()
    {
        std::cout << "Derived class message " << myValue << "\n";
    }
};

int main()
{
    Base *obj = new Derived("Test message");
    obj->ShowMessage();
    delete obj;
}


//===========================================================================================================================
//===========================================================================================================================


#include <iostream>
using namespace std;

class Base
{
    protected:
        int m_value;

    public:
        Base(int value): m_value {value} {}
        const char *getName() const { return "Base"; }
};

class Derived : public Base
{
    public:
        Derived(int value) : Base{value} {}
        const char *getName() const { return "Derived"; }
};

int main()
{
    Derived d{5};
    Base &b{d};
    cout << b.getName() << '\n';
    cout << d.getName() << endl;
    return 0;
}
