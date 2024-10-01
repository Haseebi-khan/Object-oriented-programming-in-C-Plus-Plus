#include <iostream>
using namespace std;
// Create a class Employee with the following attributes and member functions:
// • Employee registeration number
// • Employee name
// • Destination
// • Human resource Allowance
// • Basic salary
// • Profitable fund
// • Get function to take input of Registeration number, name and destination.
// Inherit(public) a class Salary from employee . Salary should contain the following
// member functions:
// • Get function to take input of human resource allowance, basic salary and
// profitable fund.

class Employee
{
protected:
    string employee_registeration_number;
    string employee_name;
    string destination;

    // func
    // we can also use getline but for now use name without spaces
    Employee()
    {
        cout << "Enter Employee reg: ";
        cin >> employee_registeration_number;
        cout << "Enter the Employee Name: ";
        cin >> employee_name;
        cout << "Enter Destination: ";
        cin >> destination;
    }
};

class Salary : protected Employee
{
public:
    int human_resource_Allowance;
    int basic_salary;
    int profitable_fund;
    Salary()
    {
        cout << "Enter the Human resource Allowance:";
        cin >> human_resource_Allowance;
        cout << "Enter Basic salary:";
        cin >> basic_salary;
        cout << "Enter Profitable fund:";
        cin >> profitable_fund;
    }
    void getter_salary()
    {
        cout << "The total salary is : " << human_resource_Allowance + basic_salary + profitable_fund << endl;
    }
};

int main()
{
    Salary sal;
    sal.getter_salary();

    return 0;
}
