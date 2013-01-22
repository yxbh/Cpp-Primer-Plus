// Stonewt_book1.cpp -- Stonewt_book class methods + conversion functions
#include <iostream>
using std::cout;
#include "Stonewt1.h"

// construct Stonewt_book object from double value
Stonewt_book::Stonewt_book(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonewt_book object from stone, double values
Stonewt_book::Stonewt_book(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn +lbs;
}

Stonewt_book::Stonewt_book()          // default constructor, wt = 0
{
    stone = int(pounds = int(pds_left = 0));
}

Stonewt_book::~Stonewt_book()         // destructor
{
}

// show weight in stones
void Stonewt_book::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt_book::show_lbs() const
{
    cout << pounds << " pounds\n";
}

// overload operator *
Stonewt_book Stonewt_book::operator*(const double & x) const
{
	return Stonewt_book(pounds * x);
}

// 2nd overload operator * for lefthand operand
Stonewt_book operator*(const double & x, const Stonewt_book & st)
{
	return st * x;
}

// conversion functions
Stonewt_book::operator int() const
{

    return int (pounds + 0.5);

}

Stonewt_book::operator double()const
{
    return pounds; 
}
