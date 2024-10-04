// Question:
#include <iostream>
using namespace std;

//////                                                      DONE

// You are required to write a C++ program to manage the academic records of 5 students,
// specifically calculating their percentages based on their marks in three subjects: Chemistry, Physics, and Mathematics.
// The program should perform the following tasks:

// Define a Structure:
// Create a structure marks to store the following information for each student:
// Roll Number (double)
// Name (char[10])
// Marks in Chemistry (double)
// Marks in Physics (double)
// Marks in Mathematics (double)
// Create a Percentage Calculation Function:
struct Marks
{
    double roll_no;
    char name[10];
    double chem_marks;
    double phy_marks;
    double math_marks;
    double percentage;

    Marks() {}
    Marks(double r, const char n[], double c, double p, double m)
    {
        roll_no = r;
        int i = 0;
        while (n[i] != '\0' && i < 9)
        {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
        chem_marks = c;
        phy_marks = p;
        math_marks = m;
    }
    // Write a function percentage that takes a marks structure as an argument and returns the percentage of the total marks for a student. The percentage should be calculated as the sum of Chemistry, Physics, and Mathematics marks divided by 300, then multiplied by 100.
    double Percentage()
    {
        return (chem_marks + phy_marks + math_marks) / 300 * 100;
    }
};
// Program Logic:
// In the main function:
// Create an array of 5 marks structures to store the data of 5 students.
// Prompt the user to input the name of each student and automatically assign their roll number.
// Use a predefined formula to assign the marks in Chemistry, Physics, and Mathematics for each student.
// Use the percentage function to calculate the percentage for each student and store it.
// Display each student's name, roll number, and calculated percentage.
int main()
{
    Marks students[2];
    for (int i = 0; i < 2; i++)
    {
        students[i].roll_no = i + 1;
    }

    for (int i = 0; i < 2; i++)
    {
        cout << "Student no: " << i + 1 << endl;
        cout << "Enter Name: ";
        cin >> students[i].name;
        cout << "Enter Math marks: ";
        cin >> students[i].math_marks;
        cout << "Enter Chemistry marks: ";
        cin >> students[i].chem_marks;
        cout << "Enter Physics marks: ";
        cin >> students[i].phy_marks;
        students[i].percentage = students[i].Percentage();
    }
    for (int i = 0; i < 2; i++)
    {
        cout << "Student Roll no: " << students[i].roll_no << endl;
        cout << "Student Name: " << students[i].name << endl;
        cout << "Percentage Student got : " << students[i].percentage << endl;
        cout << "----------------------------------" << endl;
    }

    return 0;
}

// Requirements:

// Use a structure to store and manage student details.
// Use a function to calculate the percentage of marks based on the marks stored in the structure.
// Provide meaningful prompts to the user for entering information, and display the results in a clear and organized manner.