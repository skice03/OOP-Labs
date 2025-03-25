#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

// clasa de baza pt. equation
class Equation
{
public:
    virtual void solve() = 0;         // virtual method pt. rezolvare
    virtual void display() const = 0; // virtual method pt. afisare
    virtual ~Equation() {}
};

// ecuatie de gradul 1: ax + b = 0
class FirstDegreeEquation : public Equation
{
private:
    double a, b;

public:
    FirstDegreeEquation(double coefA, double coefB) : a(coefA), b(coefB) {}

    void solve() override
    {
        if (a == 0)
        {
            throw runtime_error("No solution exists: a = 0 in ax + b = 0.");
        }
        cout << "Solution: x = " << -b / a << endl;
    }

    void display() const override
    {
        cout << a << "x + " << b << " = 0" << endl;
    }
};

// ecuatie de gradul 2: ax^2 + bx + c = 0
class SecondDegreeEquation : public Equation
{
private:
    double a, b, c;

public:
    SecondDegreeEquation(double coefA, double coefB, double coefC) : a(coefA), b(coefB), c(coefC) {}

    void solve() override
    {
        if (a == 0)
        {
            throw runtime_error("Not a second-degree equation: a = 0.");
        }

        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
        {
            throw runtime_error("No real solutions: Discriminant < 0.");
        }
        else if (discriminant == 0)
        {
            cout << "Solution: x = " << -b / (2 * a) << endl;
        }
        else
        {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Solutions: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
    }

    void display() const override
    {
        cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    }
};

int main()
{
    vector<Equation *> equations;

    // se adauga ecuatii simple in vectorul care de stocare
    equations.push_back(new FirstDegreeEquation(2, -4));     // 2x - 4 = 0
    equations.push_back(new SecondDegreeEquation(1, -3, 2)); // x^2 - 3x + 2 = 0
    equations.push_back(new SecondDegreeEquation(1, 2, 5));  // x^2 + 2x + 5 = 0 (nu are solutii reale)
    equations.push_back(new FirstDegreeEquation(0, 4));      // ecuatie invalida de gradul 1

    for (auto eq : equations)
    {
        try
        {
            eq->display();
            eq->solve();
        }
        catch (const runtime_error &e)
        {
            cout << "Error: " << e.what() << endl;
        }
        cout << "-----------------------------" << endl;
    }

    // se elibereaza memoria
    for (auto eq : equations)
    {
        delete eq;
    }

    return 0;
}