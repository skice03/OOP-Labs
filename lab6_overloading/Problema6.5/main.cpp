#include <iostream>
#include <vector>

using namespace std;

class Polynomial
{
private:
    vector<int> coeffs; // coeficienti

public:
    // constructor
    Polynomial(vector<int> c) : coeffs(c) {}

    // operator overloading
    Polynomial operator+(const Polynomial &other) const
    {
        vector<int> result(max(coeffs.size(), other.coeffs.size()), 0);

        for (size_t i = 0; i < coeffs.size(); i++)
            result[i] += coeffs[i];

        for (size_t i = 0; i < other.coeffs.size(); i++)
            result[i] += other.coeffs[i];

        return Polynomial(result);
    }

    // display method
    void display() const
    {
        for (size_t i = 0; i < coeffs.size(); i++)
        {
            if (coeffs[i] != 0)
            {
                cout << coeffs[i] << "x^" << i;
                if (i < coeffs.size() - 1)
                    cout << " + ";
            }
        }
        cout << endl;
    }
};

int main()
{
    Polynomial p1({1, 2, 3}); // 1 + 2x + 3x^2
    Polynomial p2({3, 4});    // 3 + 4x

    Polynomial sum = p1 + p2;
    cout << "Sum of polynomials: ";
    sum.display();

    return 0;
}