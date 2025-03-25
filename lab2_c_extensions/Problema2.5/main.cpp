#include <iostream>

using namespace std;

#define subunitara 0
#define supraunitara 1
#define eroare 2

bool is_supra(double a, double b)
{
	return (a / b >= 1) ? true : false;
}

int operate(bool (*f)(double, double), int a, int b)
{

	try
	{
		if (!b)
			throw 0;

		if (f(double(a), double(b)))
			return supraunitara;
		return subunitara;
	}
	catch (int e)
	{
		return eroare;
	}
}

int operate(bool (*f)(double, double), double a, double b)
{

	try
	{
		if (!b)
			throw 0;
		if (f(a, b))
			return supraunitara;
		return subunitara;
	}
	catch (int e)
	{
		return eroare;
	}
}
int main()
{
	int a = 2, b = 4, f = 0;
	double c = 3.14, d = 2.12, g = 0;

	cout << operate(*is_supra, a, b) << endl
		 << operate(*is_supra, c, d) << endl
		 << operate(*is_supra, a, f) << endl
		 << operate(*is_supra, c, g);

	return 0;
}
