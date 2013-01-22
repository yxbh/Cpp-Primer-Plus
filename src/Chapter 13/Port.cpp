#include "Port.h"
#include <cstring>
#pragma warning (disable : 4996)

//================================================
// Port class Constructor
//================================================
Port::Port(const char* br, const char * st, int b)
{
	brand = new char[strlen(br)+1];
	strcpy(brand, br);
	strncpy(style, st, 20);
	bottles = b;
}

//================================================
// Port class copy constructor
//================================================
Port::Port(const Port & p)	// copy constructor
{
	delete [] brand;
	brand = new char[strlen(p.brand)+1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

//================================================
// Port class overload op=
//================================================
Port & Port::operator=(const Port & p)
{
	if (this == &p)
		return *this;
	delete [] brand;
	brand = new char[strlen(p.brand)+1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

//================================================
// Port class overload op-=
//================================================
Port & Port::operator+=(int b)			// adds b to bottles
{
	bottles += b;
	return *this;
}

//================================================
// Port class overload op+=
//================================================
Port & Port::operator-=(int b)			// subtracts b from bottles, if available
{
	bottles -= b;\
	return *this;
}

//================================================
// Port class cout class members
//================================================
void Port::Show() const
{
	cout << "Brand: " << brand << endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}

//================================================
// Port class overload opt<<
//================================================
ostream & operator<<(ostream & os, const Port & p)
{
	return os << p.brand << ", " << p.style << ", " << p.bottles;
}

//================================================
// VintagePort class default constructor
//================================================
VintagePort::VintagePort()
	: Port(nullptr, '\0', 0)
{
	nickname = nullptr;
	year = 0;
}

//================================================
// VintagePort class contrusctor
//================================================
VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
	: Port(br, "vintage", b)
{
	nickname = new char[strlen(nn)+1];
	strcpy(nickname, nn);
	year = y;
}

//================================================
// VintagePort class copy constructor
//================================================
VintagePort::VintagePort(const VintagePort & vp)
	: Port(vp)
{
	delete [] nickname;
	nickname = new char[strlen(vp.nickname)+1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

//================================================
// VintagePort class overload op=
//================================================
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	Port::operator=(vp);
	delete [] nickname;
	nickname = new char[strlen(vp.nickname)+1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}

//================================================
// VintagePort class overload op<<	
//================================================
ostream & operator<<(ostream & os, const VintagePort & vp)
{
	return os << (const Port &) vp << ", " << vp.nickname << ", " << vp.year;
}

//================================================
// VintagePort Show() method
//================================================
void VintagePort::Show() const
{
	Port::Show();
	cout << "Nickname: " << nickname << endl;
	cout << "Year: " << year << endl;
}

