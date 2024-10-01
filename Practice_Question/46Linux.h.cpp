#include <iostream>
#include <termios.h> // for struct termios and terminal control
#include <unistd.h> // for usleep() function

using namespace std;


void gotoXY(int x, int y) {
    cout << "\033[" << x << ";" << y << "H";
}

void showCursor(bool showFlag) {
    if (showFlag) {
        cout << "\033[?25h"; // Show cursor
    } else {
        cout << "\033[?25l"; // Hide cursor
    }
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

void hideInputText(bool hideFlag) {
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty); // Get current terminal settings
    
    if (hideFlag) {
        tty.c_lflag &= ~ECHO; // Turn off echoing of input characters
    } else {
        tty.c_lflag |= ECHO; // Turn on echoing (default behavior)
    }
    
    tcsetattr(STDIN_FILENO, TCSANOW, &tty); // Apply new terminal settings
}

int main() {
    cout << "This is some text." << endl;
    textColor(5);
    gotoXY(10, 5); // Move cursor to position (10, 5)
    showCursor(false);
    cout << "Cursor moved!" << endl;
    showCursor(true);

    gotoXY(15, 5); // Move cursor to position (10, 5)
    cout << "good ";
    gotoXY(3, 5); // Move cursor to position (10, 5)
cout << "sdsadsad" <<endl;
    gotoXY(17, 6); // Move cursor to position (10, 5)
    cout << "sasdsad\n";


    // Sleep for a few seconds to see the result
    usleep(10000000); // usleep is in microseconds (2000000 microseconds = 2 seconds)

    return 0;
}
