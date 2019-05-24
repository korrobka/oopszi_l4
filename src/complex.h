#pragma once
#include <iostream>
using namespace std;

class Complex
{
private:
	double r;
	double phi;
public:
	Complex(double, double);
	Complex(double);
	Complex();

	double Re() const;
	double Im() const;
	double R() const;
	double Phi() const;

	friend std::ostream& operator<<(std::ostream &out, const Complex &ex);
	friend std::istream& operator>>(std::istream &in, Complex &ex);
	Complex operator+(Complex &expr);
	//Complex operator+=(Complex &expr);
	Complex operator-(Complex &expr);
	//Complex operator-=(Complex &expr);
	Complex operator*(Complex &expr);
	//Complex operator*=(Complex &expr);
	Complex operator/(Complex &expr);
	//Complex operator/=(Complex &expr);
};

Complex pow(double x, Complex pr);
Complex sin(Complex z);
Complex cos(Complex z);
Complex tg(Complex z);
Complex sh(Complex z);
Complex ch(Complex z);
Complex th(Complex z);

const double PI = 3.1415926535;
const double E = 2.7182818284;