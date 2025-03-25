#include <iostream>
#include <math.h>

using namespace std;

typedef struct nrcomp
{
	float a;
	float b;
} NrComplex;

float absolute_value(float n)
{
	return (n > 0) ? n : -n;
}

float absolute_value(NrComplex n)
{
	return sqrt(n.a * n.a + n.b * n.b);
}

int main()
{
	NrComplex n;
	n.a = -4;
	n.b = 3;
	float f = -5;
	cout << absolute_value(f) << endl
		 << absolute_value(n);
	return 0;
}
