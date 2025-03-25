#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
private:
    double real, imag;

public:
    // constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // operator overloading (pt. val abs in modul)
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

    cout << "ComplexNumber1: ";
    c1.display();
    cout << "ComplexNumber2: ";
    c2.display();

    if (c1 < c2)
    {
        cout << "ComplexNumber1 is smaller than ComplexNumber2 based on module." << endl;
    }
    else
    {
        cout << "ComplexNumber1 is not smaller than ComplexNumber2 based on module." << endl;
    }

    return 0;
}