#include <iostream>
#include <math.h>
#include "complex.h"

using namespace std;

Complex y(Complex);

int main()
{
	Complex ex1(10, -5);
	Complex ex2 = 3;
	Complex ex3;

	cout << "ex1 = " << ex1 << endl;
	cout << "ex2 = " << ex2 << endl;
	cout << "ex3 = " << ex3 << endl;
	cout << endl;

	ex3 = ex1 + ex2;
	ex1 /= ex3;
	ex2 *= ex3;

	cout << "ex3 = ex1 + ex2 = " << ex3 << endl;
	cout << "ex1 = ex1 / ex3 = " << ex1 << endl;
	cout << "ex2 = ex2 * ex3 = " << ex2 << endl;
	cout << endl;

	cout << "enter re and im" << endl;
	cin >> ex3;
	cout << "ex3 = " << ex3 << endl;

	system("pause");
}

Complex y(Complex z)
{
	Complex i(1, 3.14);
	return i;// -z*sin(Complex(2) * z);
}
