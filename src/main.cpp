#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

using namespace std;

Complex y(Complex z);

int main() {
	Complex a(5, PI / 3);
	Complex b = 1;
	Complex c;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << endl;

	c = a + b;
	cout << "a+b = " << c << endl;
	c = a * b;
	cout << "a*b = " << c << endl;
	c = a / b;
	cout << "a/b = " << c << endl;

	cout << "enter r and phi" << endl;
	cin >> c;
	cout << "c = " << c << endl;
	c = y(c);
	cout << "y(c) = i-c*sin(2c) = " << c << endl;
	
	system("pause");
}

Complex y(Complex z) {
	return Complex(1, PI / 2) - z*sin(Complex(2, 0)*z);
}