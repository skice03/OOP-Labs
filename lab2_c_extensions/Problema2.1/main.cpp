#include <iostream>
#include <string>

using namespace std;

float rectangle_area(float a, float b)
{
	return a * b;
}

float area(float (*foo)(float, float), string a, string b = "Square")
{
	float num1, num2;
	// posibil exception daca stof nu da convert la stringuri
	try
	{
		num1 = stof(a);
	}
	catch (const std::invalid_argument &e)
	{
		cout << "Invalid argument: " << e.what() << std::endl;
		return 0;
	}
	catch (const std::out_of_range &e)
	{
		cout << "Out of range: " << e.what() << std::endl;
		return 0;
	}

	if (b == "Square")
		return foo(num1, num1);

	try
	{
		num2 = stof(b);
	}
	catch (const std::invalid_argument &e)
	{
		cout << "Invalid argument: " << e.what() << std::endl;
		return 0;
	}
	catch (const std::out_of_range &e)
	{
		cout << "Out of range: " << e.what() << std::endl;
		return 0;
	}

	return foo(num1, num2);
}

int main()
{
	cout << area(*rectangle_area, "10", "25") << endl
		 << area(*rectangle_area, "10") << endl
		 << area(*rectangle_area, "zece10", "cinci5");
	return 0;
}
