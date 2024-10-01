// Problem 1:
// Suppose we want to design a banking application that tracks customer accounts.
// We need to create a class called "UserAccount" to represent each customer's account.
// Each account should have the following data members:
// • Account number
// • Account holder's name
// • Account balance
// • Account holder's bankname
// To ensure data encapsulation, make these all data members private. Implement or provide public getter and setter
// functions to allow other parts of the application to access and modify these data members. Print the user information
// using DetailUser function. Store the bank account information of at least five students.
#include <iostream>

using namespace std;

class UserAccount
{
private:
    string Account_holder_name;
    string Account_holders_bankname;
    double Account_balance;
    double Account_number;

public:
    void setter(string name, string bank_name, double acct_balance, double acct_number)
    {
        Account_holder_name = name;
        Account_holders_bankname = bank_name;
        Account_balance = acct_balance;
        Account_number = acct_number;
    }
    void getter()
    {

        cout << "Account holder name: " << Account_holder_name << endl;
        cout << "Account holders bankname: " << Account_holders_bankname << endl;
        cout << "Account balance: " << Account_balance << endl;
        cout << "Account number: " << Account_number << endl;
    }
};

int main()
{
    int size = 5;
    UserAccount users[size];
    string Account_holder_name;
    string Account_holders_bankname;
    double Account_balance;
    double Account_number = 9243;
    cout << "-----------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << "User :" << i + 1 << "\n";
        cout << "Enter Account holder name: ";
        getline(cin, Account_holder_name);
        cout << "Enter Account holders bankname: ";
        getline(cin, Account_holders_bankname);
        cout << "Enter Account balance: ";
        cin >> Account_balance;
        Account_number++;
        users[i].setter(Account_holder_name, Account_holders_bankname, Account_balance, Account_number);
        cout << "-----------------------\n";
        cin.ignore();
    }
    for (int i = 0; i < size; i++)
    {
        cout << "USER: " << i + 1 << endl;
        users[i].getter();
    }

    return 0;
}

== == == == == == == == == == == == == == == == == == == == == == == =

// Problem 2:
// Create a class called "Stock" to represent a stock. Each stock should have a ticker symbol, a company name, a current
// price, and a list of historical prices. Implement getter and setter functions for each data member. Add member functions
// to calculate the average price over a given time period, as well as to determine whether the stock is currently overvalued
// or undervalued.
#include <iostream>

                                                                         using namespace std;

class stock
{
private:
    string ticket_symbol,
        company_name;
    double current_price;
    double *historical_prices;
    int number_historical_prices;

public:
    stock(string ticketsymbol, string companyname, double currentprice, double *historicalprices, int size)
    {
        ticket_symbol = ticketsymbol;
        company_name = companyname;
        current_price = currentprice;
        number_historical_prices = size;
        historical_prices = new double[size];
        for (int i = 0; i < size; i++)
        {
            this->historical_prices[i] = historicalprices[i];
        }
    }

    ~stock()
    {
        delete[] historical_prices;
    }
    string get_ticket_symbol()
    {
        return ticket_symbol;
    }
    string get_company_name()
    {
        return company_name;
    }
    double get_current_price()
    {
        return current_price;
    }

    double get_Average()
    {
        if (number_historical_prices <= 0)
        {
            return current_price;
        }
        else
        {
            double sum = 0;
            for (int i = 0; i < number_historical_prices; i++)
            {
                sum += historical_prices[i];
            }
            return sum / number_historical_prices;
        }
    }
    void get_overvaled()
    {
        double sum = 0;
        for (int i = 0; i < number_historical_prices; i++)
        {
            sum += historical_prices[i];
        }
        double average = sum / number_historical_prices;
        if (current_price > average)
        {
            cout << "Not Overvalued." << endl;
        }
        else
        {
            cout << "Stock is currently overvalued." << endl;
        }
    }
};

int main()
{
    double historial_prices_list[] = {32, 75, 67, 83, 12};
    double size = sizeof(historial_prices_list) / sizeof(historial_prices_list[0]);

    stock tesla("TSLA", "Tesla, Inc.", 50, historial_prices_list, size);

    cout << "Ticket Symbol: " << tesla.get_ticket_symbol() << endl;
    cout << "Comapny name: " << tesla.get_company_name() << endl;
    cout << "Current Price: " << tesla.get_current_price() << endl;
    cout << "Averagr Price: " << tesla.get_Average() << endl;
    tesla.get_overvaled();
    return 0;
}

== == == == == == == == == == == == == =

// Problem 4:
// Create a class called "Employee" to represent an employee. Each employee should have a name, an ID, a
// salary, and a department. Implement getter and setter functions for each data member. Add member functions
// to give an employee a raise, as well as to print out a list of all employees in a given department.

#include <iostream>

                                           using namespace std;

class Employee
{
private:
    string name, dept;
    int id;
    double salary;

public:
    Employee(string names, string department, int ids, double salarys)
    {
        name = names;
        dept = department;
        id = ids;
        salary = salarys;
    }
    void setname(string n)
    {
        name = n;
    }
    void setdept(string d)
    {
        dept = d;
    }
    void setsalary(double s)
    {
        salary = s;
    }
    string getname()
    {
        return name;
    }

    string getDept()
    {
        return dept;
    }

    int getId()
    {
        return id;
    }

    double getSalary()
    {
        return salary;
    }

    void Raise(double amount)
    {
        salary += amount;
    }
};

int main()
{
    Employee employees[4] = {
        Employee("haseeb", "cs", 133, 600),
        Employee("faheem", "cs", 45, 675),
        Employee("haseeb", "bba", 34, 345),
        Employee("haseeb", "bba", 23, 234)};

    employees[0].Raise(543);

    cout << "After raise:" << endl;
    cout << "Name: " << employees[0].getName() << ", salary: " << employees[0].getSalary() << endl;

    cout << "Employees in department 'cs':" << endl;
    for (int i = 0; i < 4; ++i)
    {
        if (employees[i].getDept() == "cs")
        {
            cout << "Name: " << employees[i].getName() << ", ID: " << employees[i].getId() << ", Salary: " << employees[i].getSalary() << endl;
        }
    }

    return 0;
}

== == == == == == == == == == == == == == =
#include <iostream>

                                              using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    int getMonth() const { return month; }
    void setMonth(int m) { month = m; }

    int getDay() const { return day; }
    void setDay(int d) { day = d; }

    int getYear() const { return year; }
    void setYear(int y) { year = y; }

    int daysBetween(const Date &otherDate) const
    {
        int daysSelf = year * 365 + day;
        for (int m = 1; m < month; ++m)
        {
            daysSelf += daysInMonth(m, year);
        }
        int daysOther = otherDate.getYear() * 365 + otherDate.getDay();
        for (int m = 1; m < otherDate.getMonth(); ++m)
        {
            daysOther += daysInMonth(m, otherDate.getYear());
        }
        return abs(daysSelf - daysOther);
    }

    static bool isLeapYear(int year)
    {
        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                    return true;
                else
                    return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }

private:
    int daysInMonth(int month, int year) const
    {
        if (month == 2)
        {
            if (isLeapYear(year))
                return 29;
            else
                return 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            return 30;
        }
        else
        {
            return 31;
        }
    }
};

int main()
{
    Date date1(4, 15, 2024);
    Date date2(4, 10, 2024);

    cout << "Days between date1 and date2: " << date1.daysBetween(date2) << endl;
    cout << "Is 2024 a leap year? " << Date::isLeapYear(2024) << endl;

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
// Question No. 02:
// Define a class to represent a Bank account. Include the following members. Data members:-
// • Name of the depositor
// • Account number.
// • Type of account.
// • Balance amount in the account.
// Provide a default constructor, a parameterized constructor and a copy constructor to this class.
// Also provide Member Functions: -
// 1. To deposit an amount.
// 2. To withdraw the amount after checking for minimum balance.
// 3. To display all the details of an account holder.
// Illustrate all the constructors as well as all the methods by defining objects. In the main function,
// dynamically allocate an array of Bank Account objects. Your program should ask the user about
// the size of the array and then allocate the array dynamically. Then, your program should ask the
// user to enter the values of all attributes (Name of the depositor Account number, Type of
// account, Balance amount in the account) for each Bank Account. After that, your program should
// display the total number of Bank Account details as well as the details of each object on screen
// (by calling the display function for each Bank Account Object).

#include <iostream>
#include <cstring>

using namespace std;
class Bank_account
{
    string Name_of_the_depositor;
    char Account_number[16];
    char Type_of_account[12];
    long double Balance_amount_in_the_account;

public:
    Bank_account()
    {
        Balance_amount_in_the_account = 0;
    }
    Bank_account(const string n,const char acc_num[],const char type[],const double balance) : Name_of_the_depositor(n)
    {

        Balance_amount_in_the_account = balance;
        strncpy(Account_number, acc_num, sizeof(Account_number));
        Account_number[sizeof(Account_number) - 1] = '\0';

        strncpy(Type_of_account, type, sizeof(Type_of_account));
        Type_of_account[sizeof(Type_of_account) - 1] = '\0';
    }

    Bank_account(const Bank_account &obj)
    {
        Name_of_the_depositor = obj.Name_of_the_depositor;

        strncpy(Account_number, obj.Account_number, sizeof(Account_number));
        Account_number[sizeof(Account_number) - 1] = '\0';

        strncpy(Type_of_account, obj.Type_of_account, sizeof(Type_of_account));
        Type_of_account[sizeof(Type_of_account) - 1] = '\0';

        Balance_amount_in_the_account = obj.Balance_amount_in_the_account;
    }

    void Deposit()
    {
        cout << "Enter the Amount you want to deposite: ";
        double deposite;
        cin >> deposite;
        Balance_amount_in_the_account += deposite;
    }
    void Withdraw()
    {
        if (Balance_amount_in_the_account == 0)
        {
            cout << "Insufficent balance." << endl;
        }
        else
        {
            cout << "Enter the Withdraw Amount ";
            double amount;
            cin >> amount;
            if (amount > Balance_amount_in_the_account)
            {
                cout << "Insufficent balance." << endl;
            }
            else
            {

                Balance_amount_in_the_account -= amount;
                cout << "Withdrawal succesfully. Remaining balance is: " << Balance_amount_in_the_account << endl;
            }
        }
    }
    void display()
    {
        cout << "Name of the depositor: " << Name_of_the_depositor << endl;
        cout << "Account number: " << Account_number << endl;
        cout << "Type of account: " << Type_of_account << endl;
        cout << "Balance amount in the account: " << Balance_amount_in_the_account << endl;
    }
};

int main()
{
    cout << "Enter the acount no: ";
    int size;
    cin >> size;

    Bank_account* cust = new Bank_account[size];

    for (int i = 0; i < size; i++)
    {
        char Type_of_account[12];
        char Account_number[16];
        string name;
        double balan;
        cout << "Enter the Name: ";
        cin.ignore();
        getline(cin,name);
        cout << "Enter the account no:";
        cin >> Account_number;
        cout << "Enter the account Type: ";
        cin >> Type_of_account;
        cout << "Enter the balace: ";
        cin >> balan;

        // also possible throiugh samart pointer = unique pointer 
        cust[i] = Bank_account(name, Account_number, Type_of_account, balan );
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cust[i].display();
    }
    

    delete[] cust;



    return 0;
}