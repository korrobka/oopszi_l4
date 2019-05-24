#include <iostream>
#include <math.h>
#include "complex.h"

using namespace std;

Complex::Complex(double _r, double _phi)
{
	r = _r;
	phi = _phi;
}

Complex::Complex(double _r)
{
	r = _r;
	phi = 0;
}

Complex::Complex()
{
	r = 0;
	phi = 0;
}

double Complex::R() const
{
	return r;
}

double Complex::Phi() const
{
	return phi;
}

double Complex::Re() const
{
	return cos(phi)*r;
}

double Complex::Im() const
{
	return sin(phi)*r;
}

ostream& operator<<(ostream &out, const Complex &ex)
{
	out << ex.r << "e^(" << ex.phi << "i)";
	return out;
}

istream& operator>>(istream &in, Complex &ex)
{
	in >> ex.r >> ex.phi;
	return in;
}

Complex Complex::operator+(Complex &ex)
{
	double sum_re = Re() + ex.Re();
	double sum_im = Im() + ex.Im();

	return Complex(sqrt(sum_re*sum_re+sum_im*sum_im), atan2(sum_im,sum_re));
}

//Complex Complex::operator+(double &ex) {
//	return Complex(r + ex, phi);
//}

Complex Complex::operator-(Complex &ex)
{
	double sub_re = Re() - ex.Re();
	double sub_im = Im() - ex.Im();

	return Complex(sqrt(sub_re*sub_re + sub_im*sub_im), atan2(sub_im, sub_re));
}

Complex Complex::operator*(Complex &ex)
{
	double mul_re = Re() * ex.Re() - Im() * ex.Im();
	double mul_im = Im() * ex.Re() - Re() * ex.Im();

	return Complex(sqrt(mul_re*mul_re + mul_im*mul_im), atan2(mul_im, mul_re));
}

Complex Complex::operator/(Complex &ex)
{
	double div_re = (Re() * ex.Re() - Im() * ex.Im())/(ex.Re()*ex.Re()-ex.Im()*ex.Im());
	double div_im = (Im() * ex.Re() - Re() * ex.Im())/(ex.Re()*ex.Re() - ex.Im()*ex.Im());

	return Complex(sqrt(div_re*div_re + div_im*div_im), atan2(div_im, div_re));
}

Complex pow(double x, Complex pr){
	double pow_re = pow(x, pr.Re())*cos(pr.Im());
	double pow_im = pow(x, pr.Re())*sin(pr.Im());

	return Complex(sqrt(pow_re*pow_re + pow_im*pow_im), atan2(pow_im, pow_re));
}

Complex sin(Complex z) {
	Complex e1(sqrt(z.Re()*z.Re() + z.Im()*z.Im()), atan2(z.Re(), -z.Im()));
	Complex e2(sqrt(z.Re()*z.Re() + z.Im()*z.Im()), atan2(-z.Re(), z.Im()));
	return (pow(E,e1)-pow(E, e2)) / Complex(2,PI/2);
}

Complex cos(Complex z) {
	return Complex(1) - sin(z)*sin(z);
}

Complex tg(Complex z) {
	return sin(z) / cos(z);
}

Complex sh(Complex z) {
	Complex e1(sqrt(z.Re()*z.Re() + z.Im()*z.Im()), atan2(z.Im(), z.Re()));
	Complex e2(sqrt(z.Re()*z.Re() + z.Im()*z.Im()), atan2(-z.Im(), -z.Re()));
	return (pow(E, e1) - pow(E, e2)) / Complex(2, 0);
}

Complex ch(Complex z) {
	Complex e1(sqrt(z.Re()*z.Re() + z.Im()*z.Im()), atan2(z.Im(), z.Re()));
	Complex e2(sqrt(z.Re()*z.Re() + z.Im()*z.Im()), atan2(-z.Im(), -z.Re()));
	return (pow(E, e1) + pow(E, e2)) / Complex(2, 0);
}

Complex th(Complex z) {
	return sh(z) / ch(z);
}