#include "Complex.h"
#include <iostream>
using std::cout;

Complex::Complex()
{
	r = 0.0f;
	i = 0.0f;
}

Complex::Complex(const double r, const double i)
{
	this->r = r;
	this->i = i;
}

Complex::~Complex(){}

std::istream & operator>>(std::istream & is, Complex & c)
{
	cout << "real: ";
	double r;
	is >> r;
	c.r = r;
	cout << "imaginary: ";
	double i;
	is >> i;
	c.i = i;
	return is;
}