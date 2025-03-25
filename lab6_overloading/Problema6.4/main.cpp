#include <iostream>

using namespace std;

class Time
{
private:
    int hours, minutes, seconds;

public:
    // constructor
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    // operator overloading (pt. adunare)
    Time operator+(const Time &other) const
    {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds +
                           other.hours * 3600 + other.minutes * 60 + other.seconds;

        return Time(totalSeconds / 3600, (totalSeconds % 3600) / 60, totalSeconds % 60);
    }

    // operator overloading (pt. scadere)
    Time operator-(const Time &other) const
    {
        int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        int diff = abs(totalSeconds1 - totalSeconds2);

        return Time(diff / 3600, (diff % 3600) / 60, diff % 60);
    }

    // operator overloading (pt. egalitate)
    bool operator==(const Time &other) const
    {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    // operator overloading (pt. negatie)
    bool operator!=(const Time &other) const
    {
        return !(*this == other);
    }

    // display method
    void display() const
    {
        cout << hours << "h " << minutes << "m " << seconds << "s" << endl;
    }
};

int main()
{
    Time t1(1, 30, 45), t2(2, 15, 30);

    Time sum = t1 + t2;
    cout << "Sum of times: ";
    sum.display();

    Time diff = t1 - t2;
    cout << "Difference of times: ";
    diff.display();

    if (t1 == t2)
    {
        cout << "Times are equal." << endl;
    }
    else
    {
        cout << "Times are not equal." << endl;
    }

    return 0;
}