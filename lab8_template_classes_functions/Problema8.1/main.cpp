#include <iostream>
#include <cmath>

using namespace std;

// template pt comparare
template <typename T>
bool compare(const T &a, const T &b)
{
    return a < b;
}

class Complex
{
private:
    double real, imag;

public:
    // constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // operator overloading (pt. modul)
    double operator~() const
    {
        return sqrt(real * real + imag * imag);
    }

    // operator overloading (pt. comparatie in modul)
    bool operator<(const Complex &other) const
    {
        return ~(*this) < ~other;
    }

    // display method
    void display() const
    {
        cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
    }
};

int main()
{
    Complex c1(3, 4), c2(1, -2);
    float f1 = 5.5, f2 = 3.3;

    cout << "Comparing Complex Numbers: ";
    c1.display();
    c2.display();
    if (compare(c1, c2))
        cout << "c1 is smaller than c2 by module." << endl;
    else
        cout << "c1 is not smaller than c2 by module." << endl;

    cout << "Comparing Float Numbers: " << f1 << " and " << f2 << endl;
    if (compare(f1, f2))
        cout << f1 << " is smaller than " << f2 << endl;
    else
        cout << f1 << " is not smaller than " << f2 << endl;

    return 0;
}