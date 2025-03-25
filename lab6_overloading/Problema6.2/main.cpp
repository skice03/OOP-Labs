#include <iostream>

using namespace std;

class Complex
{
private:
    double real, imag;

public:
    // constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // operator overloading (pt. adunare)
    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // display method
    void display() const
    {
        cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
    }
};

int main()
{
    Complex complexNumber1(3, 4), complexNumber2(1, -2);

    // suma nr. complexe
    Complex complexNumber3 = complexNumber1 + complexNumber2;

    cout << "ComplexNumber1: ";
    complexNumber1.display();
    cout << "ComplexNumber2: ";
    complexNumber2.display();
    cout << "ComplexNumber3 (Sum): ";
    complexNumber3.display();

    return 0;
}