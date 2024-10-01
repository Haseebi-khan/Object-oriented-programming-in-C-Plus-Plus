// Problem 1:
//  You are tasked with developing a software for a restaurant chain that manages different types of employees, such as chefs, 
//  waiters/waitresses, and managers. Each employee type has specific roles and responsibilities. How would you utilize inheritance in C++ to represent these employee types? 
// Discuss how you would handle the shared characteristics and functionalities across these classes?


#include <iostream>
using namespace std;

class Employee
{
    protected:
        string name,association;
        int salary;
    public:
    Employee(string n, string asso, int sal): name(n), association(asso), salary(sal) 
    {
        cout << "Name: " << name <<endl;
        cout << "Association: " << association <<endl;
        cout << "Salary: " << salary <<endl; 
    }
};

class waiter : public Employee
{
    public:
        waiter(string n, string asso, int sal) : Employee(n,asso,sal) 
        {
            cout << "I would take order and serve food to Customer."<<endl;
        }
};

class chefs : public Employee
{
    public:
    chefs(string n, string asso, int sal) : Employee(n,asso,sal) 
    {
        cout << "I make food."<<endl;

    }
};

class manger : public Employee
{
    public:
    manger(string n, string asso, int sal) : Employee(n,asso,sal) 
    {
        cout << "I take care of chefs and waiter"<<endl;

    }
};

int main()
{
    cout << "-------WAITER---------"<<endl;
    waiter w("noman","gust waiter",344);

    cout << "-------Chefs---------"<<endl;
    chefs c("waqar","high expirance",232);

    cout << "-------Manger---------"<<endl;
    manger m("noman","all over",344);

    return 0;
}
// ==================================================================================================================================
// ==================================================================================================================================
// ==================================================================================================================================


#include <iostream>
using namespace std;

class Vehicles
{
	string name,model,colour,lenght_width;
	int max_speed,wheels;
	public:
Vehicles(string n,string m,string c,string l,int s,int w):name(n), model(m),colour(c),lenght_width(l),max_speed(s),wheels(w) {}
	void display()
	{
		cout << "Name: " << name <<endl;
		cout << "model: " << model <<endl;
		cout << "colour: " << colour <<endl;
		cout << "lenght_width: " << lenght_width <<endl;
		cout << "Max speed: " << max_speed <<endl;
		cout << "wheels: " << wheels <<endl;
	}

};

class Car : public Vehicles
{
	string engine;
	int hp;
	public:
	Car(string n,string m,string c,string l,int s,int w, string e,int h) : Vehicles( n, m, c, l, s, w), engine(e), hp(h) {}
	void display()
	{
		cout << "____CAR____"<<endl;
		Vehicles::display();
		cout << "Engine: " << engine <<endl;
		cout << "HP: " << hp <<endl;

	}
};

class Motorcycle : public Vehicles
{
	string engine;
	public:
	Motorcycle(string n,string m,string c,string l,int s,int w, string e) : Vehicles( n, m, c, l, s, w), engine(e) {}
	void display()
	{
				cout << "____Motorcycle____"<<endl;

		Vehicles::display();
		cout << "Engine: " << engine <<endl;
	}
};

class bicycle : public Vehicles
{
	string steel_type;
	public:
	bicycle(string n,string m,string c,string l,int s,int w, string e) : Vehicles( n, m, c, l, s, w), steel_type(e) {}
	void display()
	{
				cout << "____bicycle____"<<endl;

		Vehicles::display();
		cout << "Steel type: " << steel_type <<endl;
	}
};

int main()
{
	Car c("COROLLA","2024","Black","5'2' X 3' ",240,4,"B-45G",1700);
	c.display();
	Motorcycle m("Unique","2023","Red","3'' ",320,2,"V-33nn");
	m.display();
	bicycle b("Roger","2024","White","3",80,2,"Almunaum");
	b.display();


	return 0;
}



// =========================================================================================================================
// =========================================================================================================================
// =========================================================================================================================
// =========================================================================================================================


#include <iostream>
using namespace std;

class Sport_car
{
protected:
    string engine;
    int wheels;
};

class Electric_car
{
protected:
    string engine;
    int wheels;
};

class Vehical : public Sport_car, public Electric_car
{
    string name;
    string model;
    string color;

public:
    Vehical() {}
    Vehical(string n, string m, string c, string se, int sw, string ee, int ew) : name(n), model(m), color(c)
    {
        Electric_car::engine = ee;
        Electric_car::wheels = ew;
        Sport_car ::engine = se;
        Sport_car ::wheels = sw;
        // engine = se;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Sport Car Engine: " << Sport_car::engine << endl;
        cout << "Sport Car Wheels: " << Sport_car::wheels << endl;
        cout << "Electric Car Engine: " << Electric_car::engine << endl;
        cout << "Electric Car Wheels: " << Electric_car::wheels << endl;
    }
};

int main()
{

    Vehical V;
    V = Vehical("lexus", "2025", "Black", "B-3e78", 4, "E-11Hp", 4);
    V.display();

    return 0;
}

// ==================================================================================================================================================================================================================================================
// ==================================================================================================================================================================================================================================================
// ==================================================================================================================================================================================================================================================
// ==================================================================================================================================================================================================================================================
// ==================================================================================================================================================================================================================================================
// ==================================================================================================================================================================================================================================================
// ==================================================================================================================================================================================================================================================







#include <iostream>
using namespace std;

class Hospital_employee
{
protected:
    string name;
    string association;
    int salary;
    int id;

public:
    Hospital_employee(string n, string asso, int sal, int ids) : name(n), association(asso), salary(sal), id(ids) {}
};

class Doctor : virtual public Hospital_employee
{
protected:
    string department;
    string skill;

public:
    Doctor(string n, string asso, int sal, int id, string dept, string skll) : Hospital_employee(n, asso, sal, id), department(dept), skill(skll) {}
    void display()
    {
        cout << "Doctor: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Association: " << association << endl;
        cout << "Salary: " << salary << endl;
        cout << "department: " << department << endl;
        cout << "skill: " << skill << endl;
    }
};

class Nurse : virtual public Hospital_employee
{
protected:
    string gender;

public:
    Nurse(string n, string asso, int sal, int id, string gen) : Hospital_employee(n, asso, sal, id), gender(gen) {}
    void display()
    {
        cout << "Nurse: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Association: " << association << endl;
        cout << "Salary: " << salary << endl;
        cout << "gender: " << gender << endl;
    }
};

class Technician : virtual public Hospital_employee
{
protected:
    string lab_name;

public:
    Technician(string n, string asso, int sal, int id, string lab) : Hospital_employee(n, asso, sal, id), lab_name(lab) {}
    void display()
    {
        cout << "Technician: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Association: " << association << endl;
        cout << "Salary: " << salary << endl;
        cout << "lab_name: " << lab_name << endl;
    }
};

class Management
{
public:
    Management()
    {
        cout << "Hospital Management System" << endl;
        cout << "Enter the operation:" << endl;
        cout << "1 Doctor" << endl;
        cout << "2 Nurse" << endl;
        cout << "3 Technician" << endl;

        int s;
        cin >> s;
        switch (s)
        {
        case 1:
        {

            Doctor doc("Haseeb", "Development", 34444, 34, "urrologist", "Surgen");
            doc.display();
            cout << "======================================" << endl;
            break;
        }
        case 2:
        {
            Nurse nurse("Siri", "Emergency", 5444, 4, "Female");
            nurse.display();
            cout << "======================================" << endl;

            break;
        }
        case 3:
        {
            Technician tech("Waqar", "X-ray", 3433, 32, "Civil Lab");

            tech.display();
            cout << "======================================" << endl;

            break;
        }
        default:
            cout << "Invalid" << endl;
            break;
        }
    }
};

int main()
{
    Management management;
    return 0;
}



//=======================================================================================================================================
//=======================================================================================================================================
//=======================================================================================================================================
//=======================================================================================================================================




#include <iostream>
using namespace std;

class Employee
{
protected:
    string name;
    int ID;
    string department;
    double salary;

public:
    Employee(string n, int ID, string d, double sal) : name(n), ID(ID), department(d), salary(sal) {}
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "department: " << department << endl;
        cout << "salary: " << salary << endl;
    }
};

class Proffessor: private Employee
{
    string course;
    string scale;
    public:
    Proffessor(string n, int ID, string d, double sal,string crse,string s) : Employee( n,  ID,  d, sal), course(crse),scale(s){}
    void display()
    {
        cout << "======Proffessor========"<<endl;
        Employee::display();
        cout << "Course: "<<course<<endl;
        cout << "Scale: "<<scale<<endl;
    }

};

class Saff_member: private Employee
{
    string block;
    public:
    Saff_member(string n, int ID, string d, double sal,string b) : Employee( n,  ID,  d, sal), block(b) {}
    void display()
    {
        cout << "======Saff_member========"<<endl;
        Employee::display();
        cout << "Block: "<<block<<endl;
    }

};
class Adminstration: private Employee
{
    string block;
    public:
    Adminstration(string n, int ID, string d, double sal,string b) : Employee( n,  ID,  d, sal), block(b) {}
    void display()
    {
        cout << "======Adminstration========"<<endl;
        Employee::display();
        cout << "Block: "<<block<<endl;
    }

};


int main()
{
    Proffessor p("noman",32,"BSCS",30000,"OOP","17 scale");
    p.display();
    cout << "---------=========---------------\n";

    Saff_member s("ijaz",23,"HMS",345,"Main Block");
    s.display();
    cout << "---------=========---------------\n";

    Adminstration a("Ali",2,"BSCS",4564,"Examination");
    a.display();
    cout << "---------=========---------------";


    return 0;
}


//============================================================================================================
//============================================================================================================
//============================================================================================================
//============================================================================================================



#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    string name;
    int age;

public:
    Animal(string n, int a)
        : name(n), age(a) {}

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
    }
};

class Lion : public Animal
{
private:
    string color;

public:
    Lion(string n, int a, string c) : Animal(n, a), color(c) {}

    void display()
    {
        cout << "Lion:" << endl;
        Animal::display();
        cout << "Color: " << color << endl;
        cout << "Roar" << endl;
    }
};

class Tiger : public Animal
{
private:
    string gender;

public:
    Tiger(string n, int a, string g) : Animal(n, a), gender(g) {}

    void display()
    {
        cout << "Tiger:" << endl;
        Animal::display();
        cout << "growl" << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Elephant : public Animal
{
private:
    int height;

public:
    Elephant(string n, int a, int h) : Animal(n, a), height(h) {}

    void display()
    {
        cout << "Elephant:" << endl;
        Animal::display();
        cout << "Height: " << height << endl;
    }
};

int main()
{
    Lion lion("babarshar", 20, "light brown");
    Tiger tiger("cheeta", 15, "male");
    Elephant elephant("eleplent", 70, 255);

    lion.display();

    cout << endl;

    tiger.display();

    cout << endl;

    elephant.display();

    return 0;
}



//====================================================================================================
//====================================================================================================
//====================================================================================================
//====================================================================================================


#include <iostream>
#include <string>

using namespace std;

class Account
{
protected:
    string accountNumber;
    double balance;
    double interestRate;

public:
    Account(string anum, double b, double intrate)
        : accountNumber(anum), balance(b), interestRate(intrate) {}

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }

    void calculateInterest()
    {
        balance += balance * (interestRate / 100.0);
    }

    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(string anum, double b, double intrate)
        : Account(anum, b, intrate) {}

    void withdraw(double amount)
    {
        if (amount <= balance)
        {

            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(string anum, double b, double intrate)
        : Account(anum, b, intrate) {}

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }
};

class FixedDepositAccount : public Account
{
public:
    FixedDepositAccount(string anum, double b, double intrate)
        : Account(anum, b, intrate) {}

    void withdraw(double amount)
    {
        cout << "Withdrawal is not allowed for fixed account" << endl;
    }
};

int main()
{
    SavingsAccount savings("345345", 14444, 1.5);
    CheckingAccount checking("987654", 5000, 1.0);
    FixedDepositAccount fixed("3334445444", 20000, 5.0);
    cout << "Saving account" << endl;
    savings.display();
    savings.withdraw(233);
    savings.display();

    cout << endl;
    cout << "Checking account" << endl;

    checking.display();
    checking.withdraw(3000);
    checking.display();

    cout << endl;
    cout << "Fixed account" << endl;

    fixed.display();
    fixed.withdraw(5000);
    fixed.display();

    return 0;
}
