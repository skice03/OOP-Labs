#include <iostream>

using namespace std;

float first_order(float a, float b)
{
	try
	{
		if (!a)
			throw 0;
		return -b / a;
	}
	catch (int e)
	{
		cout << "The first coeficient can't be 0 in a first order equation" << endl;
		return 0;
	}
}

int main()
{
	float a, b;
	cin >> a >> b;
	cout << first_order(a, b);

	return 0;
}
