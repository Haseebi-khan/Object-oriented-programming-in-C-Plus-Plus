#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>   // For time()
#include <cstdlib> // For rand() and srand()
#include <fstream>
#include <stdio.h>
#include <unistd.h>  // for usleep() function
#include <termios.h> // for struct termios and terminal control

// const int password = 1234;

// system("read -p 'Press Enter to continue...' var");
using namespace std;

string generateRandomString();

void gotoXY(int x, int y);
void textColor(int colorIndex);
void showCursor(bool showFlag);
void hideInputText(bool hideFlag);
void getHiddenInput(string &input);

bool isLeapYear(int year);
int daysInMonth(int year, int month);
long long dateToSerial(int year, int month, int day);
long long daysBetweenDates(int year1, int month1, int day1, int year2, int month2, int day2);
// bool admin_Validation(string username, string password);
bool admin_Verification();

void Starting_Page();
void exit_page();
// void Menu_page();
void box();

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }

    void printToFile(fstream &file)
    {
        if (!file.is_open())
        {
            cout << "Error!" << endl;
        }
        else
        {
            file << day << "/" << month << "/" << year << endl;
        }
    }

    bool isValidDay(int d)
    {
        return (d >= 1 && d <= 31);
    }

    bool isValidMonth(int m)
    {
        return (m >= 1 && m <= 12);
    }

    bool isValidYear(int y)
    {
        return (y >= 1000 && y <= 9999);
    }

    bool isValidDate(int d, int m, int y)
    {
        return (isValidDay(d) && isValidMonth(m) && isValidYear(y));
    }
};

class Room
{
public:
    char booking_Id[7];
    char type;
    char ac;
    int room_Number;
    bool status;
    long double t_Payment;
    int customer_index;
    int totalDays;
};

class Customer
{
public:
    string name;
    string address;
    char phone[12];
    Date from_Date;
    Date to_Date;
    double payment_Advance;
    Customer() : payment_Advance(0.0) {}
};

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

class Hotel
{
protected:
    static const int max_Rooms = 20;
    static const int rent_Double = 5000; // per day double seater
    static const int rent_Single = 3000; // per day single seater
    static const int AC = 200;           // per day single seater
    Room room[max_Rooms];
    Customer *customer;
    // Customer *new_Customer;

    fstream user_Data;

    static const char *admin_Name[3];
    static const char *admin_Password[3];

    static int num_Of_Customers;
    static int room_Filled;

public:
    virtual void manageRooms(int) = 0;
    // virtual void Login() = 0;
    virtual void search() = 0; // i have to remove it and use subscript overloading concept
    friend bool admin_Verification();
    virtual void Menu_page() = 0;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Room *operator[](int roomNumber)
    {
        if (roomNumber > 0 && roomNumber <= max_Rooms)
        {
            return &room[roomNumber - 1];
        }
        return nullptr;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Hotel()
    {
        for (int i = 0; i < max_Rooms; ++i)
        {
            room[i].room_Number = i + 1;
            room[i].status = false;
        }
        num_Of_Customers++;
        room_Filled++;
        customer = new Customer[num_Of_Customers];
    }
    ~Hotel()
    {
        delete[] customer;
    }

    void display()
    {

        for (int i = 4; i < 27; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(i, 2);
            cout << "+";
        }
        for (int i = 2; i < 72; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(3, i);
            cout << "+";
        }
        for (int i = 4; i < 27; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(i, 71);
            cout << "+";
        }

        gotoXY(5, 25); // Position cursor below the box, adjust as needed
        textColor(3);  // Set text color to White (colorIndex 7)

        cout << "## ROOM INFORMATION ##" << endl;

        textColor(2); // Set text color to yellow (colorIndex 2)

        for (int i = 2; i < 72; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(7, i);
            cout << "+";
        }
        for (int i = 2; i < 72; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(26, i);
            cout << "+";
        }
        ///////////////////////////////////////////////////////////////////////////////////////////////////

        textColor(4); // Set text color to White (colorIndex 7)
        gotoXY(9, 0);

        cout << "\t   R    S         R    S         R     S          R    S    " << endl;
        cout << "\t  -------------------------------------------------------" << endl;
        textColor(2); // Set text color to White (colorIndex 7)

        cout << "\t_________" << endl;

        for (int i = 0; i < 5; i++)
        {

            cout << "\t|| " << room[i].room_Number << " || " << room[i].status << " ||   || " << room[i + 5].room_Number << " || " << room[i + 5].status << " ||  "
                                                                                                                                                            " || "
                 << room[i + 10].room_Number << " || " << room[i + 10].status << " ||  "
                                                                                 " || "
                 << room[i + 15].room_Number << " || " << room[i + 15].status << " ||  " << endl;
            cout << "\t_________" << endl;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
    }

    void setroom(int roomNo, long long totalDays)
    {
        system("clear");
        display();
        textColor(3);

        cout << "\n\t\t\t   INSERT ROOM INFO" << endl;
        textColor(4);
        gotoXY(27, 0);

        cout << "\t\t\tEnter room type (S/D): ";
        // cin >> room[roomNo - 1].type;
        room[roomNo - 1].type = 's';
        if (room[roomNo - 1].type == 'D' || room[roomNo - 1].type == 'D')
        {
            room[roomNo - 1].t_Payment += rent_Double;
        }
        else
        {
            room[roomNo - 1].t_Payment += rent_Single;
        }

        cout << "\t\t\tIs the room AC (Y/N): ";
        // cin >> room[roomNo - 1].ac;
        room[roomNo - 1].ac = 'y';

        if (room[roomNo - 1].ac == 'Y' || room[roomNo - 1].ac == 'y')
        {
            room[roomNo - 1].t_Payment += AC;
        }
        room[roomNo - 1].status = true;

        room[roomNo - 1].t_Payment *= totalDays;
    }

    void addCustomer()
    {
        display();
        fstream Customer_Detail;
        Customer_Detail.open("Customer_Detail.txt", ios::in | ios::app);
        if (!Customer_Detail.is_open())
        {
            cout << "Error!" << endl;
        }

        Customer_Detail.close();

        textColor(3);
        cout << "\n\t\t\tEnter the Room No: ";
        int roomNo;
        cin >> roomNo;
        if (roomNo < 1 || roomNo > max_Rooms)
        {

            cout << "\t\t\tInvalid room input. Try again :" << endl;
            // cout << "\t\t\t";
            system("read -p '\t\t\tPress Enter to continue...' var");
            // cin.ignore();

        } //
        //                                                        buffer error

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if (room[roomNo - 1].status)
        {
            cout << "\t\t\tRoom not available." << endl;
            cout << "\t\t\t";
            system("read -p '\t\t\tPress Enter to continue...' var");
        }
        else
        {
            textColor(4);
            gotoXY(27, 0);

            room[roomNo - 1].t_Payment = 0;

            cin.ignore();
            room[roomNo - 1].customer_index = num_Of_Customers - 1;
            cout << "\t\t\tEnter your Name: ";
            // getline(cin, customer[num_Of_Customers - 1].name);
            customer[num_Of_Customers - 1].name = "jjjjjjj";
            cout << "\t\t\tEnter your Address: ";
            // getline(cin, customer[num_Of_Customers - 1].address);
            customer[num_Of_Customers - 1].address = "sssss";

            cout << "\t\t\tEnter Phone no: ";
            cin >> customer[num_Of_Customers - 1].phone;
            cin.ignore();
            int DD = 12, MM = 12, YYYY = 2024;

            // do
            // {
            //     cout << "\t\t\tEnter From Date : (DD MM YYYY): ";
            //     cin >> DD >> MM >> YYYY;

            //     // Validate the input
            //     if (!customer[num_Of_Customers - 1].from_Date.isValidDate(DD, MM, YYYY))
            //     {
            //         cout << "Invalid date entered. Please enter again." << endl;
            //     }
            // } while (!customer[num_Of_Customers - 1].from_Date.isValidDate(DD, MM, YYYY));

            // If input is valid, set the date
            customer[num_Of_Customers - 1].from_Date.setDay(DD);
            customer[num_Of_Customers - 1].from_Date.setMonth(MM);
            customer[num_Of_Customers - 1].from_Date.setYear(YYYY);
            int DD1 = 16, MM1 = 12, YYYY1 = 2024;
            // do
            // {
            //     cout << "\t\t\tTO: (DD MM YYYY): ";
            //     cin >> DD1 >> MM1 >> YYYY1;

            //     // Validate the input
            //     if (!customer[num_Of_Customers - 1].to_Date.isValidDate(DD, MM, YYYY))
            //     {
            //         cout << "Invalid date entered. Please enter again." << endl;
            //     }
            // } while (!customer[num_Of_Customers - 1].to_Date.isValidDate(DD, MM, YYYY));
            customer[num_Of_Customers - 1].to_Date.setDay(DD1);
            customer[num_Of_Customers - 1].to_Date.setMonth(MM1);
            customer[num_Of_Customers - 1].to_Date.setYear(YYYY1);

            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            string temp = generateRandomString();

            for (int i = 0; temp[i] != '\0' && i < 7; i++)
            {
                room[roomNo - 1].booking_Id[i] = temp[i];
            }
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            int totalDays = daysBetweenDates(YYYY, MM, DD, YYYY1, MM1, DD1);

            room[roomNo - 1].totalDays = static_cast<int>(totalDays);

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            setroom(roomNo, totalDays);

            cout << "\t\t\tTotal Amount :" << room[roomNo - 1].t_Payment << endl;

            cout << "\t\t\tEnter Advance Payment :";
            cin >> customer[num_Of_Customers - 1].payment_Advance;

            if (customer[num_Of_Customers - 1].payment_Advance == 0)
            {
                cout << "\t\t\tAdvance Payment must be above $0. Returning to menu..." << endl;
                cancelLastBooking(roomNo, num_Of_Customers);
                return;
            }

            while (customer[num_Of_Customers - 1].payment_Advance < 2000)
            {
                cout << "\t\t\tAdvance Payment must be above $1999" << endl;
                cout << "\t\t\tEnter Advance Payment :";
                cin >> customer[num_Of_Customers - 1].payment_Advance;

                if (customer[num_Of_Customers - 1].payment_Advance == 0)
                {
                    cout << "\t\t\tAdvance Payment must be above $0. Returning to menu..." << endl;
                    textColor(5);
                    cancelLastBooking(roomNo, num_Of_Customers);
                    return;
                }
            }
            room[roomNo - 1].t_Payment -= customer[num_Of_Customers - 1].payment_Advance;
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////////////////////////////////////////////////
            // Writing Customer details into Customer_Detail file
            Customer_Detail.open("Customer_Detail.txt", ios::out | ios::app);

            if (!Customer_Detail.is_open())
            {
                cout << "Error!" << endl;
            }

            Customer_Detail << "------------------------------" << endl;
            Customer_Detail << "Booking ID: " << room[roomNo - 1].booking_Id << endl;
            Customer_Detail << "Room No: " << roomNo << endl;
            Customer_Detail << "Name: " << customer[num_Of_Customers - 1].name << endl;
            Customer_Detail << "Address: " << customer[num_Of_Customers - 1].address << endl;
            Customer_Detail << "Phone no: " << customer[num_Of_Customers - 1].phone << endl;
            Customer_Detail << "From Date : ";
            customer[num_Of_Customers - 1].from_Date.printToFile(Customer_Detail);
            Customer_Detail << "To Date : ";
            customer[num_Of_Customers - 1].to_Date.printToFile(Customer_Detail);
            Customer_Detail << "Room type (S/D): " << room[roomNo - 1].type << endl;
            Customer_Detail << "Room AC (Y/N): " << room[roomNo - 1].ac << endl;
            Customer_Detail << "Room Booked for:  " << room[roomNo - 1].totalDays << " Days" << endl;
            Customer_Detail << "Total Amount : " << room[roomNo - 1].t_Payment << endl;
            Customer_Detail << "Advance Payment: " << customer[num_Of_Customers - 1].payment_Advance << endl;
            Customer_Detail << "------------------------------" << endl;

            // void close();
            Customer_Detail.close();

            /////////////////////////////////////////////////////////////////////////////////////
            /////////////////////////////////////////////////////////////////////////////////////

            Customer *newcustomer = new Customer[num_Of_Customers + 1];
            for (int i = 0; i < num_Of_Customers; i++)
            {
                newcustomer[i] = customer[i];
            }

            delete[] customer;

            customer = newcustomer;

            num_Of_Customers++;
            room_Filled++;

            gotoXY(24, 0);
            textColor(3);
            cout << "\t\t\t   Booking ID: " << room[roomNo - 1].booking_Id << endl;
            gotoXY(31, 0);
            cout << "\t\t\t   Booking Successful!" << endl;

            system("read -p '\t\t\tPress Enter to continue...' var");
        }
    }

    /////////////////////////////////////////////////////
    void cancelLastBooking(int i, int j)
    {

        room[i - 1].booking_Id[0] = '\0';
        room[i - 1].type = '\0';
        room[i - 1].ac = '\0';
        room[i - 1].totalDays = 0;
        room[i - 1].totalDays = 0;
        room[i - 1].t_Payment = 0;
        room[i - 1].customer_index = 0;
        room[i - 1].status = false;
        room[i - 1].totalDays = 0;
        customer[j - 1].name.clear();
        customer[j - 1].address.clear();
        customer[j - 1].phone[0] = '\0';
        customer[j - 1].to_Date.setDay(0);
        customer[j - 1].to_Date.setMonth(0);
        customer[j - 1].to_Date.setYear(0);
        customer[j - 1].from_Date.setDay(0);
        customer[j - 1].from_Date.setMonth(0);
        customer[j - 1].from_Date.setYear(0);
        customer[j - 1].payment_Advance = 0;
    }

    bool isValidEmail(const string &email)
    {
        bool atFound = false,
             dotFound = false;

        int atPos = -1,
            dotPos = -1;

        for (int i = 0; i < email.length(); i++)
        {
            if (email[i] == '@')
            {
                if (atFound)
                {
                    return false; 
                }
                atFound = true;
                atPos = i;
            }
        }
        for (int i = atPos; i < email.length(); i++)
        {
            if (email[i] == '.')
            {
                dotFound = true;
                dotPos = i;
            }
        }

        return atFound && dotFound && atPos < dotPos;
    }

    bool isDigit(char c)
    {
        return c >= '0' && c <= '9';
    }

    bool isValidPhoneNumber(const string &phoneNumber)
    {
        if (phoneNumber.length() == 0 || phoneNumber.length() > 11)
        {
            return false;
        }
        for (int i = 0; i < phoneNumber.length(); i++)
        {
            if (phoneNumber[i] >= 0 && phoneNumber[i] != '+' && phoneNumber[i] <= 9)
            {
                return false;
            }
        }
        return true;
    }

    bool isEmpty(const string &str)
    {
        return str.length() == 0;
    }

    bool unique_User(string user_Name)
    {
        cin.ignore();
        user_Data.open("user_Data.txt", ios::in);
        if (!user_Data.is_open())
        {
            cout << "Error in opening file.";
        }
        bool found = false;
        string line,

            comp_line = "Username: ";
        comp_line += user_Name;

        int no_of_lines_in_file = 0;

        while (getline(user_Data, line))
        {
            no_of_lines_in_file++;
        }
        // cout << no_of_lines_in_file <<endl;

        user_Data.clear();
        user_Data.seekg(0, ios::beg);

        for (int i = 0; i < no_of_lines_in_file; i++)
        {
            getline(user_Data, line);

            if (line == comp_line)
            {
                found = true;
                break;
            }
        }

        user_Data.close();

        return found;
    }

    bool users_Password_Validation(string user_Name, string pass)
    {
        user_Data.open("user_Data.txt", ios::in);
        if (!user_Data.is_open())
        {
            cout << "Error in opening file.";
        }
        bool user_Found = false;
        bool userpass_Found = false;
        string line,
            password = "Password: ",
            comp_line = "Username: ";
        password += pass;
        comp_line += user_Name;

        int no_of_lines_in_file = 0;

        while (getline(user_Data, line))
        {
            no_of_lines_in_file++;
        }
        // cout << no_of_lines_in_file <<endl;

        int user_name_indux = -1;

        user_Data.clear();
        user_Data.seekg(0, ios::beg);

        for (int i = 0; i < no_of_lines_in_file; i++)
        {
            getline(user_Data, line);

            if (line == comp_line)
            {
                user_Found = true;
                user_name_indux = i;
                break;
            }
        }
        for (int i = user_name_indux; i < no_of_lines_in_file; i++)
        {
            getline(user_Data, line);
            if (line == password)
            {
                userpass_Found = true;
                break;
            }
            break;
        }

        user_Data.close();
        // system("read -p 'Press Enter to continue...' var");

        return user_Found && userpass_Found;
    }
};

int Hotel::num_Of_Customers = 1;
int Hotel::room_Filled = 0;
const char *Hotel::admin_Name[3] = {"Haseeb Khan", "Rafy", "admin"};
const char *Hotel::admin_Password[3] = {"123", "345", "admin"};

class Staff : virtual public Hotel
{
protected:
    void Menu_page() override
    {

        for (int i = 4; i < 18; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(i, 2);
            cout << "+";
        }
        for (int i = 2; i < 72; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(3, i);
            cout << "+";
        }
        for (int i = 4; i < 18; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(i, 71);
            cout << "+";
        }

        gotoXY(5, 23); // Position cursor below the box, adjust as needed
        textColor(3);  // Set text color to White (colorIndex 7)
        cout << "## HOTEL MANAGEMENT SYSTEM ##" << endl;
        textColor(2); // Set text color to yellow (colorIndex 2)

        for (int i = 2; i < 72; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(7, i);
            cout << "+";
        }
        textColor(4);
        gotoXY(8, 23); // Position cursor below the box, adjust as needed
        cout << "\n";
        cout << "\n\t\t\t   1. Check-In Room";
        cout << "\n\t\t\t   2. Check-Out Room";
        cout << "\n\t\t\t   3. Search Customer";
        cout << "\n\t\t\t   4. Guest Summary Report";
        cout << "\n\t\t\t   5. Log Out" << endl;
        for (int i = 2; i < 72; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(18, i);
            cout << "+";
        }

        cout << endl;
    }

    void get_Summary_report()
    {
        ifstream Customer_Detail("Customer_Detail.txt");
        if (!Customer_Detail.is_open())
        {
            cout << "Error!" << endl;
        }

        Customer_Detail.clear();  // Clear any error flags
        Customer_Detail.seekg(0); // Reset the Customer_Detail position to the beginning
        string line;
        while (getline(Customer_Detail, line))
        {
            cout << line << endl;
        }

        // Shift the Search to the right side of the terminal.
        textColor(1);
        gotoXY(3, 32);

        cout << "Search: ";
        string search;
        cin >> search;

        string nameAndId = "Booking ID: " + search;
        int count = 0;

        Customer_Detail.clear();  // Clear any error flags
        Customer_Detail.seekg(0); // Reset the Customer_Detail position to the beginning

        bool found = false;
        while (getline(Customer_Detail, line))
        {
            if (line == nameAndId)
            {
                gotoXY(4, 32);
                found = true;
                cout << line << endl;
                count = 5;
                // Print the next 8 lines assuming they contain relevant booking information
                for (int i = 0; i < 11; ++i)
                {

                    gotoXY(count, 32);
                    count++;
                    getline(Customer_Detail, line);
                    cout << line << endl;
                }
                break;
            }
        }

        if (!found)
        {
            cout << "No booking found with the ID: " << search << endl;
        }
        system("read -p '\t\t               Press Enter to continue...' var");

        Customer_Detail.close();
    }

    void checkOut()
    {
        display();
        textColor(3);
        cout << "\n\t\t\tEnter the Booking ID: ";
        string temp_id;
        cin >> temp_id;

        int cust_index = -1;
        int room_index = -1;
        for (int i = 0; i < max_Rooms; ++i)
        {
            if (temp_id == room[i].booking_Id)
            {
                cust_index = room[i].customer_index;
                room_index = i;
                break;
            }
        }

        if (room_index == -1)
        {
            cout << "\t\t\tBooking ID not found." << endl;
            return;
        }
        else
        {
            textColor(4);
            gotoXY(27, 0);
            cout << "\t\t\tCustomer Name: " << customer[cust_index].name << endl;
            cout << "\t\t\tEnter the number of days stayed: ";
            int actual_days_stayed;
            cin >> actual_days_stayed;

            int overtime_expense = 0;
            if (actual_days_stayed > room[room_index].totalDays)
            {
                if (room[room_index].type == 'S' || room[room_index].type == 's')
                {
                    overtime_expense += rent_Single * (actual_days_stayed - room[room_index].totalDays);
                }
                else
                {
                    overtime_expense += rent_Double * (actual_days_stayed - room[room_index].totalDays);
                }
            }

            room[room_index].t_Payment += overtime_expense;
            // cout << "\t\t\tTotal Payment: " << room[room_index].t_Payment << endl;

            while (room[room_index].t_Payment > 0)
            {
                cout << "\t\t\tTotal Payment: " << room[room_index].t_Payment << endl;
                cout << "\t\t\tEnter remaining payment: ";
                int remaining_payment;
                cin >> remaining_payment;
                room[room_index].t_Payment -= remaining_payment;
                if (room[room_index].t_Payment < 0)
                {
                    cout << "\t\t\tExcess payment detected. Refund: " << -room[room_index].t_Payment << endl;
                    room[room_index].t_Payment = 0;
                }
            }

            room[room_index].status = false;
            room[room_index].t_Payment = 0;
            room[room_index].customer_index = -1;
            customer[cust_index].payment_Advance = 0;
            textColor(3);
            cout << "\t\t\tCheckout completed successfully." << endl;
            textColor(4);
            system("read -p '\t\t\tPress Enter to continue...' var");
        }
    }
    void search() override
    {

        box();
        textColor(3);  // Set text color to White (colorIndex 7)
        gotoXY(5, 32); // Position cursor below the box, adjust as needed

        cout << "## SEARCH ##" << endl;
        textColor(4);
        gotoXY(9, 19);

        cout << "Enter Custommer Room No: ";

        int Room_no;
        cin.ignore();
        cin>>Room_no;

        system("clear");
        box();
        textColor(3);  // Set text color to White (colorIndex 7)
        gotoXY(5, 32); // Position cursor below the box, adjust as needed

        cout << "## SEARCH ##" << endl;
        textColor(4);
        gotoXY(9, 19);

        bool found = false;

        textColor(2);

        Room *foundRoom = (*this)[Room_no];
        if (foundRoom != nullptr)
        {
            int customerIndex = foundRoom->customer_index;
            if (customerIndex >= 0 && customerIndex < num_Of_Customers)
            {
                Customer *foundCustomer = &customer[customerIndex];
                gotoXY(10, 4);
                textColor(4);
                cout << "\t\tCustomer Name: " << foundCustomer->name << endl;

                cout << "\t\tRoom ID: " << foundRoom->booking_Id << endl;
                cout << "\t\tAddress: " << foundCustomer->address << endl;
                cout << "\t\tPhone Number: " << foundCustomer->phone << endl;
                cout << "\t\tCheckin Date: ";
                foundCustomer->from_Date.displayDate();
                cout << "\t\tCheckout Date: ";
                foundCustomer->to_Date.displayDate();
                cout << endl;
                cout << endl;
                cout << endl;
                system("read -p '\t\t\tPress Enter to continue...' var");
            }
            else
            {
                gotoXY(12, 25); // Position cursor for input
                textColor(3);
                cout << "Room Is Ready For Booking." << endl;
                system("read -p '\t\t\tPress Enter to continue...' var");
            }
        }
        else
        {
            gotoXY(12, 25); // Position cursor for input
                textColor(3);
            cout << "Room not found." << endl;
            system("read -p '\t\t\tPress Enter to continue...' var");
        }
    }

    void manageRooms(int a) override
    {
        int option;
        do
        {
            system("clear");
            Staff::Menu_page();
            cout << "\t\t\tEnter Option: ";
            cin >> option;
            system("clear");

            switch (option)
            {
            case 1:
                addCustomer();
                break;
            case 2:
                Staff::checkOut();
                break;
            case 3:
                Staff::search();
                break;
            case 4:
                // Guest summary implementation
                Staff::get_Summary_report();
                break;
            case 5:
                break;
            default:
                cout << "\nPlease Enter correct option";
                break;
            }

        } while (option != 5);
    }

    /////////////////////////////////////////////////////

    /////          things are remaining in the cancelbooking just intitalize each value to empty string
};

class Cust : virtual public Hotel
{
protected:
    void Menu_page() override
    {

        for (int i = 4; i < 18; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(i, 2);
            cout << "+";
        }
        for (int i = 2; i < 72; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(3, i);
            cout << "+";
        }
        for (int i = 4; i < 18; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(i, 71);
            cout << "+";
        }

        gotoXY(5, 23); // Position cursor below the box, adjust as needed
        textColor(3);  // Set text color to White (colorIndex 7)
        cout << "## HOTEL MANAGEMENT SYSTEM ##" << endl;
        textColor(2); // Set text color to yellow (colorIndex 2)

        for (int i = 2; i < 72; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(7, i);
            cout << "+";
        }
        textColor(4);
        gotoXY(9, 23); // Position cursor below the box, adjust as needed
        cout << "\n";
        cout << "\n\t\t\t   1. Check-In Room.";
        cout << "\n\t\t\t   2. Check Booking.";
        cout << "\n\t\t\t   3. Log Out" << endl;

        for (int i = 2; i < 72; i++)
        {
            textColor(2); // Set text color to Blue (colorIndex 4)
            gotoXY(18, i);
            cout << "+";
        }

        cout << endl;
    }

    void search() override // pure virtual function
    {
        box();
        textColor(3);  // Set text color to White (colorIndex 7)
        gotoXY(5, 32); // Position cursor below the box, adjust as needed

        cout << "## SEARCH ##" << endl;
        textColor(4);
        gotoXY(9, 19);

        cout << "Enter Your 6 Digit Booking ID.\n";

        gotoXY(10, 33);
        textColor(3);
        string id;
        cin.ignore();
        getline(cin, id);
        bool found = false;

        for (int i = 0; i < max_Rooms; i++)
        {
            if (id == room[i].booking_Id && id != "")
            {
                textColor(4);
                gotoXY(11, 0);
                cout << "\t\t\tName: " << customer[room[i].customer_index].name << endl;
                cout << "\t\t\tRoom no: " << room[i].room_Number << endl;
                cout << "\t\t\tAddress: " << customer[room[i].customer_index].address << endl;
                cout << "\t\t\tPhone no: " << customer[room[i].customer_index].phone << endl;
                //               i have to show the from date and to date
                cout << "\t\t\tCheckin Date: ";
                customer[room[i].customer_index].from_Date.displayDate();
                cout << "\t\t\tCheckout Date: ";
                customer[room[i].customer_index].to_Date.displayDate();

                cout << endl;
                cout << endl;
                found = true;
                system("read -p '\t\t     Press Enter to continue...' var");
                break;
            }
        }
        if (!found)
        {
            textColor(1);

            cout << "\t\t\tNo Booking is confirmed." << endl;
            system("read -p '\t\t\tPress Enter to continue...' var");
            // system("pause");
        }
    }

    void manageRooms(int a) override
    {
        int option;
        do
        {
            system("clear");
            Cust::Menu_page();
            cout << "\t\t\tEnter Option: ";
            cin >> option;
            system("clear");

            switch (option)
            {
            case 1:
                addCustomer();
                break;
            case 2:
                Cust::search();
                break;
            case 3:
                system("clear");
                box();
                gotoXY(5, 23); // Position cursor below the box, adjust as needed
                textColor(3);  // Set text color to White (colorIndex 7)

                cout << "## HOTEL MANAGEMENT SYSTEM ##" << endl;
                gotoXY(19, 25); // Position cursor for input
                textColor(3);
                cout << " Log out successfully " << endl;
                system("read -p '\t\t\tPress Enter to continue ....");

                // go to the middle of the page
                // and print Log Out Successfully

                break;
            default:
                gotoXY(15, 25); // Position cursor below the box, adjust as needed
                cout << "Please Enter correct option";
                usleep(200000);
                break;
            }

            gotoXY(19, 25); // Position cursor for input
            textColor(3);

        } while (option != 3);
    }
};

class Management : public Staff, public Cust
{
private:
    void Menu_page() override
    {

        // Clear the screen
        // system("clear");
        box();
        gotoXY(5, 29); // Position cursor below the box, adjust as needed
        textColor(3);  // Set text color to White (colorIndex 7)

        cout << "## HOME PAGE ##" << endl;

        textColor(4);

        gotoXY(9, 25); // Position cursor below the box, adjust as needed
        cout << "1. Login As Admin\n";

        gotoXY(10, 25); // Position cursor below the box, adjust as needed
        cout << "2. Login As Geust\n";

        gotoXY(11, 25); // Position cursor below the box, adjust as needed
        cout << "3. Create Account\n";

        gotoXY(12, 25); // Position cursor below the box, adjust as needed
        cout << "4. Exit\n";

        // i must have to add creating account
        gotoXY(14, 25); // Position cursor below the box, adjust as needed
        // cout << endl;
    }
    void create_Account()
    {
        box();
        gotoXY(5, 27); // Position cursor below the box, adjust as needed
        textColor(3);  // Set text color to White (colorIndex 7)

        cout << "## Create Account ##" << endl;

        string username, password, confirmPassword, email, firstName, lastName,
            phoneNumber, address, city, zipCode, country, gender;

        textColor(4); // Set text color to White (colorIndex 7)
        gotoXY(9, 7); // Position cursor for input
        cout << "Enter Username: ";
        textColor(3); // Set text color to White (colorIndex 7)
        cin >> username;

        if (username.length() == 0)
        {
            gotoXY(19, 25); // Position cursor for input
            textColor(1);   // Set text color to White (colorIndex 7)
            cout << "Username cannot be empty." << endl;
            system("read -p '\t\t\tPlease Try Again...' var");

            return;
        }
        else if (unique_User(username))
        {
            gotoXY(19, 25); // Position cursor for input
            textColor(1);   // Set text color to White (colorIndex 7)
            cout << "Use another User name." << endl;
            system("read -p '\t\t\tPlease Try Again...' var");

            return;
        }

        textColor(4);  // Set text color to White (colorIndex 7)
        gotoXY(9, 42); // Position cursor for input
        cout << "Enter Email: ";
        textColor(3); // Set text color to White (colorIndex 7)
        cin >> email;
        if (!isValidEmail(email))
        {
            gotoXY(19, 25); // Position cursor for input
            textColor(1);   // Set text color to White (colorIndex 7)
            cout << "Invalid email format." << endl;
            system("read -p '\t\t\tPlease Try Again...' var");

            return;
        }

        textColor(4);  // Set text color to White (colorIndex 7)
        gotoXY(10, 7); // Position cursor for input
        cout << "Enter First Name: ";
        textColor(3); // Set text color to White (colorIndex 7)
        cin >> firstName;
        if (isEmpty(firstName))
        {
            gotoXY(19, 25); // Position cursor for input
            textColor(1);   // Set text color to White (colorIndex 7)
            cout << "First Name cannot be empty." << endl;
            system("read -p '\t\t\tPlease Try Again...' var");

            return;
        }

        textColor(4);   // Set text color to White (colorIndex 7)
        gotoXY(10, 42); // Position cursor for input
        cout << "Enter Last Name: ";
        textColor(3); // Set text color to White (colorIndex 7)
        cin >> lastName;
        if (isEmpty(lastName))
        {
            gotoXY(19, 25); // Position cursor for input
            textColor(1);   // Set text color to White (colorIndex 7)
            cout << "Last Name cannot be empty." << endl;
            system("read -p '\t\t\tPlease Try Again...' var");

            return;
        }

        textColor(4);  // Set text color to White (colorIndex 7)
        gotoXY(11, 7); // Position cursor for input
        cout << "Enter Phone Number: ";
        textColor(3); // Set text color to White (colorIndex 7)
        cin >> phoneNumber;
        if (!isValidPhoneNumber(phoneNumber))
        {
            gotoXY(19, 25); // Position cursor for input
            textColor(1);   // Set text color to White (colorIndex 7)
            cout << "Invalid phone number format." << endl;
            system("read -p '\t\t\tPlease Try Again...' var");

            return;
        }

        textColor(4);   // Set text color to White (colorIndex 7)
        gotoXY(11, 42); // Position cursor for input
        cout << "Enter Address: ";
        textColor(3); // Set text color to White (colorIndex 7)
        cin >> address;
        if (isEmpty(address))
        {
            gotoXY(19, 25); // Position cursor for input
            textColor(1);   // Set text color to White (colorIndex 7)
            cout << "Address cannot be empty." << endl;
            system("read -p '\t\t\tPlease Try Again...' var");

            return;
        }

        textColor(4);  // Set text color to White (colorIndex 7)
        gotoXY(12, 7); // Position cursor for input
        cout << "Enter City: ";
        textColor(3); // Set text color to White (colorIndex 7)
        cin >> city;
        if (isEmpty(city))
        {
            gotoXY(19, 25); // Position cursor for input
            textColor(1);   // Set text color to White (colorIndex 7)
            cout << "City cannot be empty." << endl;
            system("read -p '\t\t\tPlease Try Again...' var");

            return;
        }

        // textColor(4);   // Set text color to White (colorIndex 7)
        // gotoXY(13, 42); // Position cursor for input
        // cout << "Enter State: ";
        // textColor(3); // Set text color to White (colorIndex 7)
        // cin >> state;

        textColor(4);   // Set text color to White (colorIndex 7)
        gotoXY(12, 42); // Position cursor for input
        cout << "Enter Country: ";
        textColor(3); // Set text color to White (colorIndex 7)
        cin >> country;
        if (isEmpty(country))
        {
            gotoXY(19, 25); // Position cursor for input
            textColor(1);   // Set text color to White (colorIndex 7)
            cout << "Country cannot be empty." << endl;
            system("read -p '\t\t\tPlease Try Again...' var");

            return;
        }

        textColor(4);  // Set text color to White (colorIndex 7)
        gotoXY(13, 7); // Position cursor for input
        cout << "Enter Zip Code: ";
        textColor(3); // Set text color to White (colorIndex 7)
        cin >> zipCode;

        // textColor(4);  // Set text color to White (colorIndex 7)
        // gotoXY(15, 6); // Position cursor for input
        // cout << "Enter Date of Birth: ";
        // textColor(3); // Set text color to White (colorIndex 7)
        // cin >> dateOfBirth;

        textColor(4);   // Set text color to White (colorIndex 7)
        gotoXY(13, 42); // Position cursor for input
        cout << "Enter Gender(M/F): ";
        textColor(3); // Set text color to White (colorIndex 7)
        cin >> gender;
        if (isEmpty(gender))
        {
            gotoXY(19, 25); // Position cursor for input
            textColor(1);   // Set text color to White (colorIndex 7)
            cout << "Gender cannot be empty." << endl;
            system("read -p '\t\t\tPlease Try Again...' var");

            return;
        }

        textColor(4);  // Set text color to White (colorIndex 7)
        gotoXY(15, 8); // Position cursor for input
        cout << "Enter Password: ";
        textColor(3); // Set text color to White (colorIndex 7)
        cin.ignore();
        getHiddenInput(password);
        if (password.length() == 0)
        {
            gotoXY(19, 25); // Position cursor for input
            textColor(1);   // Set text color to White (colorIndex 7)
            cout << "Password cannot be empty." << endl;
            system("read -p '\t\t\tPlease Try Again...' var");

            return;
        }

        textColor(4);   // Set text color to White (colorIndex 7)
        gotoXY(15, 40); // Position cursor for input

        cout << "Enter Confirm Password: ";
        textColor(3); // Set text color to White (colorIndex 7)

        // cin.ignore();
        getHiddenInput(confirmPassword);

        bool created = false;
        if (confirmPassword != password)
        {
            gotoXY(19, 25); // Position cursor for input
            textColor(1);   // Set text color to White (colorIndex 7)
            cout << "Passwords do not match." << endl;
            system("read -p '\t\t\tPlease Try Again...' var");

            return;
        }
        else
        {
            ofstream user_Data("user_Data.txt", ios::app);

            if (!user_Data.is_open())
            {
                cout << "Unable to open file";
            }

            user_Data << "-----------------------------------------------------------------------------" << endl;

            user_Data << "Username: " << username << endl;
            user_Data << "Password: " << password << endl;
            user_Data << "Email: " << email << endl;
            user_Data << "First Name: " << firstName << endl;
            user_Data << "Last Name: " << lastName << endl;
            user_Data << "Phone Number: " << phoneNumber << endl;
            user_Data << "Address: " << address << endl;
            user_Data << "City: " << city << endl;
            user_Data << "Zip Code: " << zipCode << endl;
            user_Data << "Country: " << country << endl;
            user_Data << "Gender: " << gender << endl;

            user_Data << "-----------------------------------------------------------------------------" << endl;

            user_Data.close();
            created = true;
        }

        if (created)
        {

            textColor(3);   // Set text color to White (colorIndex 7)
            gotoXY(19, 25); // Position cursor for input

            cout << "Processing ";
            textColor(3);   // Set text color to White (colorIndex 7)
            gotoXY(19, 36); // Position cursor for input
            cout << ".";

            // usleep(2000000);
            gotoXY(19, 37); // Position cursor for input
            cout << ".";

            // usleep(1000000);
            gotoXY(19, 38); // Position cursor for input
            cout << ".";

            // usleep(1000000);
            gotoXY(19, 39); // Position cursor for input
            cout << "." << endl;

            system("read -p '\t\t\tPress Enter to continue...' var");
            system("clear");
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            box();
            gotoXY(5, 27); // Position cursor below the box, adjust as needed
            textColor(3);  // Set text color to White (colorIndex 7)

            cout << "## Create Account ##" << endl;

            textColor(4); // Set text color to White (colorIndex 7)
            gotoXY(9, 7); // Position cursor for input
            cout << "Username: ";
            textColor(3); // Set text color to White (colorIndex 7)
            cout << username;

            textColor(4);  // Set text color to White (colorIndex 7)
            gotoXY(9, 42); // Position cursor for input
            cout << "Email: ";
            textColor(3); // Set text color to White (colorIndex 7)
            cout << email;

            textColor(4);  // Set text color to White (colorIndex 7)
            gotoXY(10, 7); // Position cursor for input
            cout << "First Name: ";
            textColor(3); // Set text color to White (colorIndex 7)
            cout << firstName;

            textColor(4);   // Set text color to White (colorIndex 7)
            gotoXY(10, 42); // Position cursor for input
            cout << "Last Name: ";
            textColor(3); // Set text color to White (colorIndex 7)
            cout << lastName;

            textColor(4);  // Set text color to White (colorIndex 7)
            gotoXY(11, 7); // Position cursor for input
            cout << "Phone Number: ";
            textColor(3); // Set text color to White (colorIndex 7)
            cout << phoneNumber;

            textColor(4);   // Set text color to White (colorIndex 7)
            gotoXY(11, 42); // Position cursor for input
            cout << "Address: ";
            textColor(3); // Set text color to White (colorIndex 7)
            cout << address;

            textColor(4);  // Set text color to White (colorIndex 7)
            gotoXY(12, 7); // Position cursor for input
            cout << "City: ";
            textColor(3); // Set text color to White (colorIndex 7)
            cout << city;

            // gotoXY(12, 42); // Position cursor for input
            // cout << "State: ";
            // cout << state;

            textColor(4);   // Set text color to White (colorIndex 7)
            gotoXY(12, 42); // Position cursor for input
            cout << "Country: ";
            textColor(3); // Set text color to White (colorIndex 7)
            cout << country;

            textColor(4);  // Set text color to White (colorIndex 7)
            gotoXY(13, 7); // Position cursor for input
            cout << "Zip Code: ";
            textColor(3); // Set text color to White (colorIndex 7)
            cout << zipCode;

            // gotoXY(14, 6); // Position cursor for input
            // cout << "Date of Birth: ";
            // cout << dateOfBirth;

            textColor(4);   // Set text color to White (colorIndex 7)
            gotoXY(13, 42); // Position cursor for input
            cout << "Gender: ";
            textColor(3); // Set text color to White (colorIndex 7)
            cout << gender;

            textColor(4);         // Set text color to White (colorIndex 7)
            gotoXY(15, 25);       // Position cursor for input
            cout << "Password: "; //  print it in the end
            textColor(3);         // Set text color to White (colorIndex 7)
            cout << password;

            gotoXY(19, 25); // Position cursor for input
            textColor(3);   // Set text color to White (colorIndex 7)
            cout << "Successfully Account Created" << endl;
        }
        system("read -p '\t\t\tPress Enter to continue...' var");
    }
    void Login(int option)
    {
        system("clear");
        box();

        gotoXY(5, 27); // Position cursor below the box, adjust as needed
        textColor(3);  // Set text color to White (colorIndex 7)

        cout << "## LogIn Account  ##" << endl;

        string username, password;

        textColor(4);   // Set text color to White (colorIndex 7)
        gotoXY(10, 25); // Position cursor for input
        cout << "Enter Username: ";
        cin >> username;
        cin.ignore();

        textColor(4);   // Set text color to White (colorIndex 7)
        gotoXY(12, 25); // Position cursor for input

        cout << "Enter Password: ";

        getHiddenInput(password);

        if (users_Password_Validation(username, password))
        {
            textColor(3);   // Set text color to White (colorIndex 7)
            gotoXY(14, 25); // Position cursor for input
            cout << "Login Successfully." << endl;
            system("read -p '\t\t\tPress Enter to continue...' var");

            Cust::manageRooms(option);
        }
        else
        {
            textColor(3);   // Set text color to White (colorIndex 7)
            gotoXY(14, 25); // Position cursor for input
            cout << "Invaild User Name and Password" << endl;
            system("read -p '\t\t\tPlease Try Again Later.' var");
        }
    }

public:
    void manageRooms(int a) override
    {
        int option;
        do
        {
            system("clear");
            Management::Menu_page();
            cout << "Enter Option: ";
            cin >> option;
            // system("clear");

            switch (option)
            {
            case 1:
                // As Staff
                if (admin_Verification())
                {
                    textColor(3);   // Set text color to White (colorIndex 7)
                    gotoXY(14, 25); // Position cursor for input
                    cout << "Login Successfully." << endl;
                    system("read -p '\t\t\tPress Enter to continue...' var");

                    Staff::manageRooms(option);
                }
                else
                {
                    textColor(3);   // Set text color to White (colorIndex 7)
                    gotoXY(14, 25); // Position cursor for input
                    cout << "Invaild User Name and Password" << endl;
                    system("read -p '\t\t\tPlease Try Again Latter.' var");
                }

                break;
            case 2:
                //   as Custommer
                Login(option);
                break;
            case 3:
                system("clear");
                create_Account();
                break;
            case 4:
                system("clear");
                exit_page();
                break;

            default:

                gotoXY(15, 25); // Position cursor below the box, adjust as needed
                cout << "Please Enter correct option";
                usleep(200000);
                break;
            }

        } while (option != 4);
    }
    void search() override {};
};

//                                                              MAIN
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Starting_Page();

    Hotel *h;
    Management m;
    h = &m;
    // system("read -p '\t\t\tPress Enter to continue...' var");
    h->manageRooms(1);

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void Hotel::checkOut ()
// {

// }

/// i must have to change the generateRandomString function

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int year, int month)
{
    if (month == 2)
    {
        return isLeapYear(year) ? 29 : 28;
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

long long dateToSerial(int year, int month, int day)
{
    long long serial = 0;
    for (int y = 1900; y < year; ++y)
    {
        serial += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; ++m)
    {
        serial += daysInMonth(year, m);
    }
    serial += day - 1;
    return serial;
}

long long daysBetweenDates(int year1, int month1, int day1, int year2, int month2, int day2)
{
    long long serial1 = dateToSerial(year1, month1, day1);
    long long serial2 = dateToSerial(year2, month2, day2);
    return serial2 - serial1;
}

void Starting_Page()
{
    textColor(3);
    string runTimeMessage = "PRESS ANY KEY TO RUN HOTEL MANAGEMENT SYSTEM";

    // Calculate padding to center the runtime message
    int paddingOfRunTime = (72 - runTimeMessage.length()) / 2;

    // Print runtime message with padding
    cout << setw(paddingOfRunTime + runTimeMessage.length()) << runTimeMessage << endl;

    for (int i = 4; i < 20; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(i, 2);
        cout << "+";
    }
    for (int i = 2; i < 72; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(3, i);
        cout << "+";
    }
    for (int i = 4; i < 20; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(i, 71);
        cout << "+";
    }
    textColor(4); // Set text color to Blue (colorIndex 4)

    gotoXY(11, 26); // Position cursor below the box, adjust as needed
    cout << "HOTEL MANAGEMENT SYSTEM" << endl;
    for (int i = 4; i < 20; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(i, 71);
        cout << "+";
    }
    for (int i = 2; i < 72; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(20, i);
        cout << "+";
    }
    cout << endl;

    // Position cursor for the prompt

    // Show cursor before prompting
    showCursor(true);
    system("read -p ' Press Enter to continue...' var");

    // Prompt message

    // Optionally, hide cursor again after prompt
    // showCursor(false);
    system("clear");
    gotoXY(0, 0); // Position cursor below the box, adjust as needed
    textColor(4345);
}

void exit_page()
{
    for (int i = 4; i < 20; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(i, 2);
        cout << "+";
        gotoXY(i, 3);
        cout << "+";
    }

    for (int i = 2; i < 72; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(3, i);
        cout << "+";
        gotoXY(4, i);
        cout << "+";
    }
    for (int i = 4; i < 20; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(i, 71);
        cout << "+";
        gotoXY(i, 70);
        cout << "+";
    }

    textColor(3);   // Set text color to Blue (colorIndex 4)
    gotoXY(11, 35); // Position cursor below the box, adjust as needed
    cout << "EXIT" << endl;
    gotoXY(13, 24); // Position cursor below the box, adjust as needed
    cout << "ThankYou!ForUsingSoftware";
    for (int i = 2; i < 72; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(19, i);
        cout << "+";
        gotoXY(20, i);
        cout << "+";
    }
    cout << endl;
    // Show cursor before prompting
    showCursor(true);
    system("read -p ' Press Enter to continue...' var");
    system("clear");
    gotoXY(0, 0); // Position cursor below the box, adjust as needed
    textColor(4345);
}

void gotoXY(int x, int y)
{
    cout << "\033[" << x << ";" << y << "H";
}

void textColor(int colorIndex)
{
    // ANSI escape codes for text color
    switch (colorIndex)
    {
    case 0: // Black
        cout << "\033[30m";
        break;
    case 1: // Red
        cout << "\033[31m";
        break;
    case 2: // Green
        cout << "\033[32m";
        break;
    case 3: // Yellow
        cout << "\033[33m";
        break;
    case 4: // Blue
        cout << "\033[34m";
        break;
    case 5: // Magenta
        cout << "\033[35m";
        break;
    case 6: // Cyan
        cout << "\033[36m";
        break;
    case 7: // White
        cout << "\033[37m";
        break;
    default:
        // Default to white if colorIndex is out of range
        cout << "\033[37m";
        break;
    }
}

void showCursor(bool showFlag)
{
    if (showFlag)
    {
        cout << "\033[?25h"; // Show cursor
    }
    else
    {
        cout << "\033[?25l"; // Hide cursor
    }
}

void box()
{

    for (int i = 4; i < 18; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(i, 2);
        cout << "+";
    }
    for (int i = 2; i < 72; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(3, i);
        cout << "+";
    }
    for (int i = 4; i < 18; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(i, 71);
        cout << "+";
    }

    gotoXY(5, 23); // Position cursor below the box, adjust as needed
    textColor(3);  // Set text color to White (colorIndex 7)

    // cout << "## HOTEL MANAGEMENT SYSTEM ##" << endl;

    textColor(2); // Set text color to yellow (colorIndex 2)

    for (int i = 2; i < 72; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(7, i);
        cout << "+";
    }
    textColor(4);
    gotoXY(8, 23); // Position cursor below the box, adjust as needed
    // cout << "\n";
    // cout << "\n\t\t\t   1. Check-In Room";
    // cout << "\n\t\t\t   2. Check-Out Room";
    // cout << "\n\t\t\t   3. Available Rooms";
    // cout << "\n\t\t\t   4. Search Customer";
    // cout << "\n\t\t\t   5. Guest Summary Report";
    // cout << "\n\t\t\t   6. Exit" << endl;
    for (int i = 2; i < 72; i++)
    {
        textColor(2); // Set text color to Blue (colorIndex 4)
        gotoXY(18, i);
        cout << "+";
    }

    cout << endl;
}

void hideInputText(bool hideFlag)
{
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty); // Get current terminal settings

    if (hideFlag)
    {
        tty.c_lflag &= ~ECHO;   // Turn off echoing of input characters
        tty.c_lflag &= ~ICANON; // Turn off canonical mode
    }
    else
    {
        tty.c_lflag |= ECHO;   // Turn on echoing (default behavior)
        tty.c_lflag |= ICANON; // Turn on canonical mode
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &tty); // Apply new terminal settings
}

void getHiddenInput(string &input)
{
    hideInputText(true); // Turn off echoing and canonical mode

    char ch;
    while ((ch = getchar()) != '\n') // Read characters until Enter is pressed
    {
        if (ch == 127)
        { // Handle backspace
            if (!input.empty())
            {
                input.pop_back();
                cout << "\b \b"; // Erase the last asterisk
            }
        }
        else
        {
            input.push_back(ch);
            cout << '*'; // Print asterisk for each character
        }
    }

    hideInputText(false); // Restore terminal settings
    cout << endl;
}

string generateRandomString()
{
    const int length = 6;
    const string characters = "012345678987576432123456ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string randomString;

    // Seed the random number generator with current time
    srand(time(0));

    for (int i = 0; i < length; ++i)
    {
        // Generate a random index within the range of characters
        int randomIndex = rand() % characters.size();
        randomString += characters[randomIndex];
    }

    return randomString;
}

bool admin_Verification()
{
    system("clear");
    box();

    gotoXY(5, 27); // Position cursor below the box, adjust as needed
    textColor(3);  // Set text color to White (colorIndex 7)

    cout << "## LogIn Account  ##" << endl;

    string username, password;

    textColor(4);   // Set text color to White (colorIndex 7)
    gotoXY(10, 25); // Position cursor for input
    cout << "Enter Username: ";
    cin >> username;
    cin.ignore();

    textColor(4);   // Set text color to White (colorIndex 7)
    gotoXY(12, 25); // Position cursor for input

    cout << "Enter Password: ";

    getHiddenInput(password);

    for (int i = 0; i < 3; ++i)
    {
        if (username == Hotel::admin_Name[i] && password == Hotel::admin_Password[i])
        {
            return true;
        }
    }
    return false;
}
