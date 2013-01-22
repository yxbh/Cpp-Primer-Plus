#ifndef _COMPLEX_H_
#define _COMPLEX_H_
#include <iostream>

class Complex
{
private:
	double r;
	double i;
public:
	/* constructors & destructor */
	Complex();
	Complex(const double r, const double i);
	~Complex();
	/* operator overload */ 
	// overload +
	Complex operator+(const Complex & c) const
	{ return Complex(r+c.r, i+c.i); }
	// overload -
	Complex operator-(const Complex & c) const
	{ return Complex(r-c.r, i-c.i); }
	// overload *
	Complex operator*(const Complex & c) const
	{ return Complex(r*c.r-i*c.i, r*c.i+i*c.r); }
	// overload * with real number
	friend Complex operator*(int n, const Complex & c)
	{ return Complex(n*c.r, n*c.i); }
	friend Complex operator*(const Complex & c, int n)
	{ return n * c; }
	// overload <<
	friend std::ostream & operator<<(std::ostream & os, const Complex & c)
	{ return (os << "(" << c.r << ", " << c.i << "i)");}
	// overload >> 
	friend std::istream & operator>>(std::istream & is, Complex & c);
};



#endif

