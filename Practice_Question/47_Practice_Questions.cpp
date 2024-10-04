#include <iostream>
using namespace std;

class a {
protected:
    int s;
public:
    a() : s(0) {
        cout << "\nBase Constructor\n";
    }
    virtual ~a() {
        cout << "\nBase Destructor\n";
    }
    virtual void show() = 0;
};

class b : public a {
public:
    b() {
        cout << "\nDerived Constructor B\n";
        s = 42;  // Example value for demonstration
    }
    ~b() {
        cout << "\nDerived Destructor B\n";
    }
    void show() override {
        cout << "Derived B: " << s << endl;
    }
};

class c : public a {
public:
    c() {
        cout << "\nDerived Constructor C\n";
        s = 84;  // Example value for demonstration
    }
    ~c() {
        cout << "\nDerived Destructor C\n";
    }
    void show() override {
        cout << "Derived C: " << s << endl;
    }
};

class d : public a {
public:
    d() {
        cout << "\nDerived Constructor D\n";
        s = 126;  // Example value for demonstration
    }
    ~d() {
        cout << "\nDerived Destructor D\n";
    }
    void show() override {
        cout << "Derived D: " << s << endl;
    }
};

// Base class for diamond problem
class base {
public:
    base() {
        cout << "\nBase Class Constructor\n";
    }
    virtual ~base() {
        cout << "\nBase Class Destructor\n";
    }
};

// Derived classes for diamond problem
class derived1 : virtual public base {
public:
    derived1() {
        cout << "\nDerived1 Constructor\n";
    }
    ~derived1() {
        cout << "\nDerived1 Destructor\n";
    }
};

class derived2 : virtual public base {
public:
    derived2() {
        cout << "\nDerived2 Constructor\n";
    }
    ~derived2() {
        cout << "\nDerived2 Destructor\n";
    }
};

// Diamond problem resolution
class finalDerived : public derived1, public derived2 {
public:
    finalDerived() {
        cout << "\nFinalDerived Constructor\n";
    }
    ~finalDerived() {
        cout << "\nFinalDerived Destructor\n";
    }
};

// Function to demonstrate polymorphic behavior
void demonstratePolymorphism(a* objArray[], int size) {
    for (int i = 0; i < size; ++i) {
        objArray[i]->show();
    }
}

int main() {
    a** objArray = nullptr;
    try {
        // Allocate array of base class pointers
        objArray = new a*[10];
        for (int i = 0; i < 10; ++i) {
            // Alternate between different derived class objects
            if (i % 3 == 0) {
                objArray[i] = new b();
            } else if (i % 3 == 1) {
                objArray[i] = new c();
            } else {
                objArray[i] = new d();
            }
        }

        // Demonstrate polymorphic behavior
        demonstratePolymorphism(objArray, 10);
    } catch (const std::bad_alloc& e) {
        cout << "Memory allocation failed: " << e.what() << endl;
        // Clean up already allocated objects
        for (int i = 0; i < 10 && objArray && objArray[i]; ++i) {
            delete objArray[i];
        }
        delete[] objArray;
        return 1;
    }

    // Clean up
    for (int i = 0; i < 10; ++i) {
        delete objArray[i];
    }
    delete[] objArray;

    // Demonstrate using base class pointer to point to derived class object
    a* base;
    b derive;
    base = &derive;
    base->show();

    // Demonstrate diamond problem
    cout << "\nCreating finalDerived instance...\n";
    finalDerived fd;
    cout << "\nfinalDerived instance created.\n";

    return 0;
}


// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------



// a) Initialize row to 2 and col to 3.
// b) Allocate memory for the 2D array.
// c) Initialize each index with 1.
// Write an overloaded constructor to allocate memory based on input row and col.
// Implement a public function inputData for matrix.
// Create a dynamic array of matrices of size 4.
// Assign memory at the 0 index with the default constructor.
// Assign memory at the 1st index with the overloaded constructor of the same size.
// Write a function for addMatrix in the class which adds matrix2 with this and returns the result matrix.
// Save the result matrix at the 3rd index.
// Call the copy constructor to copy matrix[3] = matrix[2].
// Free memory by calling the destructor.
// Display proper messages for the constructor, copy constructor, and destructor calls.
// Utilize the this pointer within the class methods.

// #include <iostream>
// using namespace std;

// class Matrix
// {
//     int** matrix;
//     int row, col;
//     public:
//         Matrix(int r = 2,int c= 3) : row(r),col(c)
//         {
//             int matrix = new int*[row];
//             for (int i = 0; i < row; i++)
//             {
//                 int matrix[i]  = new int[col];
//             }  
//             for (int i = 0; i < row; i++)
//             {
//                 for (int j = 0; j < col; j++)
//                 {
//                     matrix[i][j]=1;
//                 }
                
//             }
             

//         }
//         ~Matrix()
//         {
//             delete[] matrix;
//             for (int i = 0; i < 2; i++)
//             {
//                 delete[] matrix[i];
//             }
            
//         }

// };

// int main()
// {
    
//     Matrix a;

    
//     return 0;
// }

// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================




#include <iostream>
using namespace std;

class BankAccount
{
    int accountNumber;
    double balance;
    string pin;

public:
    BankAccount() {}
    BankAccount(int account_Number, double bal, string PIN) : accountNumber(account_Number), balance(bal), pin(PIN) {}

    int getAccountNumber()
    {
        return accountNumber;
    }
    double getBalance()
    {
        return balance;
    }
    string getPin()
    {
        return pin;
    }

    void setBalance(double newBalance)
    {
        balance = newBalance;
    }
    void setPin(string newPin)
    {
        pin = newPin;
    }

    void withdraw(double amount, string enteredPin)
    {
        if (enteredPin == pin)
        {
            if (amount > 0 && amount <= balance) 
            {
                balance -= amount; 
                cout << "Withdrawal successful. New balance: " << balance << endl;
            }
            else
            {
                cout << "Insufficient balance." << endl;
            }
        }
        else
        {
            cout << "Incorrect PIN. Withdrawal failed." << endl;
        }
    }
};

int main()
{
    BankAccount a(123456, 1000.0, "1234");

    cout << "Account Number: " << a.getAccountNumber() << endl;
    cout << "Current Balance: " << a.getBalance() << endl;
    cout << "PIN: " << a.getPin() << endl;

    cout << "Withdrawing $500 with correct PIN..." << endl;
    a.withdraw(500, "1234");

    cout << "Withdrawing $1500 with incorrect PIN..." << endl;
    a.withdraw(1500, "4321");

    return 0;
}





// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================
// =====================================================================================================================



#include <iostream>

using namespace std;

class Bank
{
private:
    double balance;
    double interestRate;
    double interest;
    int transaction;

public:
    Bank() : balance(0), interestRate(4.5), interest(0), transaction(0) {}
    Bank(double bal, double interest) : balance(bal), interestRate(interest), interest(0), transaction(0) {}

    Bank &setInterestRate(double intrate)
    {
        interestRate = intrate;
        return *this;
    }
    Bank &makeDeposit(double deposite)
    {
        balance += deposite;
        calcInterest();
        inCount();
        return *this;
    }
    Bank &withdraw(double witdraw)
    {
        if (balance > witdraw)
        {
            inCount();
            balance -= witdraw;
        }
        else
        {
            cout << "Insufficent balance." << endl;
        }
        return *this;
    }
    Bank &calcInterest()
    {
        interest = (balance * (4.5 / 100));
        return *this;
    }
    void inCount() { ++transaction; }
    double getCount() { return transaction; }
    double getInterestRate() { return interestRate; }
    double getInterest() { return interest; }
    double getTransactions() { return transaction; }
    double getBalance() const { return balance; }
    void display()
    {
        cout << "Banlance: " << getBalance() << endl;
        cout << "Interest Rate: " << getInterestRate() << endl;
        cout << "Interest : " << getInterest() << endl;
        cout << "Transactions: " << getTransactions() << endl;
    }
};

int main()
{
    Bank a;
    a.makeDeposit(4345).calcInterest().withdraw(45).display();

    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    string name;

public:
    Animal(string name) : name(name) {}

    void sound()
    {
        cout << "Name: " << name << endl;
        cout << "Animals." << endl;
    }
};

class Cat : public Animal
{
public:
    Cat(string name) : Animal(name) {}

    void sound()
    {
        cout << "Name: " << name << endl;

        cout << "Meow" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string name) : Animal(name) {}

    void sound()
    {

        cout << "Name: " << name << endl;
        cout << "Woof" << endl;
    }
};

class TigerFamily : public Animal
{
public:
    TigerFamily(string name) : Animal(name) {}
};

class Deer : public Animal
{
public:
    Deer(string name) : Animal(name) {}

    void sound()
    {
        cout << "Name: " << name << endl;

        cout << "Bleat" << endl;
    }
};

class Tiger : public TigerFamily
{
public:
    Tiger(string name) : TigerFamily(name) {}

    void sound()
    {
        cout << "Name: " << name << endl;

        cout << "Roar" << endl;
    }
};

class Lion : public TigerFamily
{
public:
    Lion(string name) : TigerFamily(name) {}

    void sound()
    {
        cout << "Name: " << name << endl;
        cout << "Roar" << endl;
    }
};

int main()
{
    Cat cat("Cat");
    cat.sound();

    Dog dog("Dog");
    dog.sound();

    Deer deer("Deer");
    deer.sound();

    Tiger tiger("Tiger");
    tiger.sound();

    Lion lion("Lion");
    lion.sound();

    return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
class LFC
{
public:
    int x;
};
int main()
{
    LFC *p = new LFC();

    (*p).x = 5;

    cout << (*p).x << " " << p->x << " ";

    p->x = 10;

    cout << (*p).x << " " << p->x;

    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



