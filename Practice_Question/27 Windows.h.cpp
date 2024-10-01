#include <iostream>
// #pragma once
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;

// Enumerator that contain constant values for ascii of enter key and backspace key

enum KEY
{
    KEY_BACK = 8,   // ascii for backspace key
    KEY_RET = 13,   // ascii for carriage return/Enter key
    KEY_ONE = 49,   // ascii for key '1'
    KEY_UP = 72,    // ascii for key up arrow key
    KEY_DOWN = 80,  // ascii for down arrow key
    KEY_LEFT = 75,  // ascii for down arrow key
    KEY_RIGHT = 77, // ascii for down arrow key
    KEY_ESC = 27    // ascii for down escape key
};

// Function for changing cursor postion in console window
void gotoXY(float x, float y)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition; // coord used to define coordinates for a variable
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

// Function for Text Coloring on Console Window
void textColor(int colorIndex)
{
    HANDLE textColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(textColor, colorIndex);
    return;
}

// Function for hiding console cursor
void showCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(out, &cursor);
    cursor.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursor);
    return;
}

// Function for Loading Window
void loadingConsole()
{
    showCursor(false);
    // Printing Loading on Console with actual animation effects
    cout << "\n\n\n\n\n  Loading...\n  Please Wait\n  ";
    // Sleep function used to delay clock timer of program(compiler)
    for (int counter = 1; counter <= 60; counter++)
    {
        cout << "\xcd";
    }
    gotoXY(6, 8);
    cout << "\n  ";
    for (int counter = 1; counter <= 60; counter++)
    {
        cout << "\xcd";
    }
    gotoXY(4, 7);
    Sleep(10);      //
    cout << "\n  "; // used to print a box
    textColor(368);
    for (int counter = 1; counter <= 59; counter++)
    {
        Sleep(10);
        cout << " ";
    }
    textColor(15);
}

// Function for Hiding Inputed Text
void hideInputText(bool showFlag)
{
    HANDLE cpin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = showFlag;
    GetConsoleMode(cpin, &mode);
    SetConsoleMode(cpin, mode & (~ENABLE_ECHO_INPUT));
}

// Main menu function initialization
void mainMenu(string title)
{
    showCursor(false);
    textColor(783);
    // used for clearing console window elements
    system("cls");
    // Printing Loading Interference
    // loadingConsole();
    // Sleep(550);
    // Used to clear screen buffer in console window
    system("cls");
    // Printing Interface for Main Menu
    for (int counter = 2; counter <= 15; counter++)
    { // 15
        gotoXY(3, counter);
        textColor(368);
        cout << " ";
    }
    for (int counter = 2; counter <= 15; counter++)
    {
        gotoXY(62, counter);
        textColor(368);
        cout << " ";
    }
    for (int counter = 4; counter <= 15; counter++)
    { // 13
        gotoXY(23, counter);
        textColor(368);
        cout << " ";
    }
    for (int counter = 4; counter <= 15; counter++)
    {
        gotoXY(48, counter);
        textColor(368);
        cout << " ";
    }
    gotoXY(0, 1);
    textColor(8);
    cout << "   ";
    for (int counter = 1; counter <= 27; counter++)
    {
        cout << "\xcd";
    }
    textColor(14);
    cout << " " << title << " ";
    textColor(8);
    for (int counter = 1; counter <= 27; counter++)
    {
        cout << "\xcd";
    }
    gotoXY(18, 3);
    cout << "     ";
    textColor(8);
    for (int counter = 1; counter <= 26; counter++)
    {
        cout << "\xcd";
    }
    cout << endl
         << "\t\t\t\t";
    textColor(11);
    cout << "Main Menu";
    textColor(15);
    cout << " " << endl;
    gotoXY(23.5, 5);
    textColor(8);
    for (int counter = 1; counter <= 26; counter++)
    {
        cout << "\xcd";
    }
    for (int counter = 3; counter <= 62; counter++)
    {
        gotoXY(counter, 16);
        textColor(8);
        cout << "\xcd";
    }
    textColor(15);
    // Hiding Cursor
    showCursor(false);
    // Making a Highliter Menu
    int set[] = {7, 7, 7, 7, 7}; // Default colors
    int counter = 2;
    char key;
    set[1] = 335; // setting color of counter 2nd output to this color on starting
    for (int infiniteCounter = 0;;)
    { // for infinite loop

        gotoXY(25, 6);
        textColor(set[0]);
        cout << "[1] Play             ";

        gotoXY(25, 8);
        textColor(set[1]);
        cout << "[2] Level            ";

        gotoXY(25, 10);
        textColor(set[2]);
        cout << "[3] High Score       ";

        gotoXY(25, 12);
        textColor(set[3]);
        cout << "[4] Credits          ";

        gotoXY(25, 14);
        textColor(set[4]);
        cout << "[5] Exit             ";

        key = _getch();

        // (2,3,   ,1,2)    (,3,4   , 2,3)	(4,5  3,4)
        if (key == KEY(KEY_UP) && (counter >= 2 && counter <= 3 || counter >= 3 && counter <= 4 || counter >= 4 && counter <= 5))
        { // for up key
            counter--;
        }

        //( 1,2,    ,2,3)    (,2,3   ,3,4)	(3,4   4,5)
        if (key == KEY(KEY_DOWN) && (counter >= 1 && counter <= 2 || counter >= 2 && counter <= 3 || counter >= 3 && counter <= 4))
        { // for down key
            counter++;
        }

        if (key == '\r')
        { // for Enter key
            if (counter == 1)
            {
                system("cls");
                textColor(783); // default black bg. with white text
                // used for clearing console window elements
                system("cls");
                // Printing Loading Interference
                loadingConsole();
                Sleep(10);
                system("cls");

                break; // used to stop iterating main menu screen again while screen buffer is cleared
            }
            if (counter == 2)
            {
                system("cls");
                textColor(783); // default black bg. with white text
                // used for clearing console window elements
                system("cls");
                // Printing Loading Interference
                loadingConsole();
                Sleep(10);
                system("cls");

                break; // used to stop iterating main menu screen again while screen buffer is cleared
            }
            if (counter == 3)
            {
                textColor(783); // default black bg. with white text
                system("cls");
                textColor(783); // default black bg. with white text

                break;
            }
            if (counter == 4)
            {
                textColor(15);
                system("cls");

                break;
            }
            if (counter == 5)
            {
                textColor(15);
                system("cls");
                exit(0);
                break;
            }
        }

        // setting to default colors
        set[0] = 7;
        set[1] = 7;
        set[2] = 7;
        set[3] = 7;
        set[4] = 7;

        // Changing colors on changing cursor position
        if (counter == 1)
        {
            set[0] = 335;
        }
        if (counter == 2)
        {
            set[1] = 335;
        }
        if (counter == 3)
        {
            set[2] = 335;
        }
        if (counter == 4)
        {
            set[3] = 335;
        }
        if (counter == 5)
        {
            set[4] = 335;
        }
    }
    cout << endl;
}

int main()
{

    string gameTitle = "Game";

    SetConsoleTitleA("Game");



    cout << endl;
    loadingConsole();
    Sleep(1000);
    system("cls");
    showCursor(true);
    /*cout << "Hello World\n";
    int j;
    cout << "Enter J: ";
    hideInputText(true);
    cin >> j;
    cout<< "\nValue of J is : " << j << endl;*/

    mainMenu(gameTitle);

    system("pause");
    return 0;
}
