#include <iostream>
#include <math.h>
#include "complex.h"

using namespace std;

Complex::Complex(double _r, double _phi)
{
	re = cos(_phi)*_r;
	im = sin(_phi)*_r;
}

Complex::Complex(double _r)
{
	re = _r;
	im = 0;
}

Complex::Complex()
{
	re = 0;
	im = 0;
}

double Complex::Re() const
{
	return re;
}

double Complex::Im() const
{
	return im;
}

double Complex::R() const
{
	return sqrt(re*re + im*im);
}

double Complex::Phi() const
{
	return atan(re / im);
}

ostream& operator<<(ostream &out, const Complex &ex)
{
	out << "(" << ex.re << ", " << ex.im << ")";
	return out;
}

istream& operator>>(istream &in, Complex &ex)
{
	in >> ex.re >> ex.im;
	double buf = ex.re;
	ex.re = ex.re*cos(ex.im);
	ex.im = buf*sin(ex.im);
	return in;
}

Complex Complex::operator+(Complex &ex)
{
	return Complex(re + ex.Re(), im + ex.Im());
}

Complex Complex::operator+=(Complex &ex)
{
	re += ex.Re();
	im += ex.Im();

	return *this;
}

Complex Complex::operator-(Complex &ex)
{
	return Complex(re - ex.Re(), im - ex.Im());
}

Complex Complex::operator-=(Complex &ex)
{
	re -= ex.Re();
	im -= ex.Im();

	return *this;
}

Complex Complex::operator*(Complex &ex)
{
	return Complex(re * ex.Re() - im * ex.Im(), re * ex.Im() + im * ex.Re());
}

Complex Complex::operator*=(Complex &ex)
{
	double _re = re;

	re = re * ex.Re() - im * ex.Im();
	im = _re * ex.Im() + im * ex.Re();

	return *this;
}

Complex Complex::operator/(Complex &ex)
{
	double r = ex.Re() * ex.Re() + ex.Im() * ex.Im();

	return Complex((re * ex.Re() + im * ex.Im()) / r, (im * ex.Re() - re * ex.Im()) / r);
}

Complex Complex::operator/=(Complex &ex)
{
	double _re = re;
	double r = ex.Re() * ex.Re() + ex.Im() * ex.Im();

	re = (re * ex.Re() + im * ex.Im()) / r;
	im = (im * ex.Re() - _re * ex.Im()) / r;

	return *this;
}
