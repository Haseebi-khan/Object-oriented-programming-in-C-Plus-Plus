#include <iostream>
#include <string>
#include <sstream>

using namespace std;
sad
int main() {
    string from = "12 04 2024";
    string to = "12 05 2024";

    // Creating stringstream objects
    stringstream fromStream(from);
    stringstream toStream(to);

    int day1, month1, year1, day2, month2, year2;

    // Extracting day, month, and year from 'from' date string
    fromStream >> day1 >> month1 >> year1;

    // Extracting day, month, and year from 'to' date string
    toStream >> day2 >> month2 >> year2;

    // Printing the extracted date components
    cout << "From Date Components: " << day1 << "/" << month1 << "/" << year1 << endl;
    cout << "To Date Components: " << day2 << "/" << month2 << "/" << year2 << endl;

    return 0;
}
