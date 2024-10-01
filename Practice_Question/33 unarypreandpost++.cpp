#include <iostream>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;

public:
    Time()
    {
        hours = 0;
        minutes = 0;
    }
    Time(int h, int m)
    {
        hours = h;
        minutes = m;
    }

    void displayTime()
    {
        cout << "H: " << hours << " M:" << minutes << endl;
    }

    // overloaded prefix ++ operator
    Time operator++()
    {
        ++minutes;
        if (minutes >= 60)
        {
            ++hours;
            minutes -= 60;
        }
        return Time(hours, minutes);
    }

    // overloaded postfix ++ operator
    Time operator++(int)
    {

        // save the orignal value
        Time T(hours, minutes);

        ++minutes;

        if (minutes >= 60)
        {
            ++hours;
            minutes -= 60;
        }

        // return old original value
        return T;
    }
};

int main()
{
    Time T1(11, 59), T2(10, 58);

    ++T1;
    T1.displayTime();
    ++T1;
    T1.displayTime();
    cout << "===================================================" << endl;
    T2.displayTime();
    T2++;
    T2.displayTime();
    T2.operator++(1);
    T2++;
    T2.displayTime();
    return 0;
}