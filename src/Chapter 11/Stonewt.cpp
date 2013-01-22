#include <iostream>
#include <string>
using std::cout;
#include "Stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, mode mod)
{
	this->mod = mod;
	stone = int (lbs) / Lbs_per_stn;    // integer division
	pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, mode mod)
{
	this->mod = mod;
	stone = stn;
	pds_left = lbs;
	pounds =  stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt(mode mod)          // default constructor, wt = 0
{
	this->mod = mod;
	stone = int(pounds = int(pds_left = 0));
}

Stonewt & Stonewt::change_mode(mode mod)
{
	this->mod = mod;
	return *this;
}

Stonewt & Stonewt::operator=(const Stonewt & wt)
{
	this->stone = wt.stone;
	this->pds_left = wt.pds_left;
	this->pounds = wt.pounds;
	this->mod = wt.mod;
	return *this;
}

Stonewt Stonewt::operator+(const Stonewt & sw) const
{
	return Stonewt(this->pounds + sw.pounds);
}

Stonewt Stonewt::operator-(const Stonewt & sw) const
{
	return Stonewt(this->pounds - sw.pounds);
}

Stonewt operator*(const Stonewt & sw, const double x)
{
	return Stonewt(sw.pounds * x);
}

std::ostream & operator<<(std::ostream & os, const Stonewt & wt)
{
	switch(wt.mod)
	{
	case (Stonewt::mode::STONEP):
		os << wt.stone << " stones, " << wt.pds_left << " pounds";
		break;
	case (Stonewt::mode::POUND):
		os << wt.pounds << " pounds";
		break;
	}
	return os;
}