#include <iostream>
#include <cmath>
#include "header.h"

using namespace std;

int main()
{
    double a, b, c;

    cout << "Enter the coefficients for the quadratic equation (ax^2 + bx + c = 0):\n";
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;

    if (a == 0)
    {
        cout << "The value of 'a' cannot be zero. It must be a quadratic equation.\n";
    }
    else
    {
        QuadraticEquation equation(a, b, c);
        equation.solve();
    }

    return 0;
}