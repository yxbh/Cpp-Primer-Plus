#ifndef _STONEWT_H_
#define _STONEWT_H_
#include <iostream>

class Stonewt
{
public:
	// weight mode (how the obj is interpreted)
	enum class mode {STONEP, POUND};	
private:
	enum {Lbs_per_stn = 14};			// pounds per stone
	int stone;							// whole stones
	double pds_left;					// fractional pounds
	double pounds;						// entire weight in pounds
	mode mod;							// current weight mode
public:
	// default constructor, default mode = pound
	Stonewt(mode mod = mode::POUND);
	// construct from double pounds
	Stonewt(double lbs, mode mod = mode::POUND);   
	// construct from stone, lbs
	Stonewt(int stn, double lbs, mode mod = mode::STONEP);
	~Stonewt() {}
	Stonewt & change_mode(mode mod);
	// operator overload
	Stonewt & operator=(const Stonewt & wt);
	Stonewt operator+(const Stonewt & sw) const;
	Stonewt operator-(const Stonewt & sw) const;
	friend Stonewt operator*(const Stonewt & sw, const double x);
	friend Stonewt operator*(const double x, const Stonewt & sw)
	{return sw * x;}
	friend std::ostream & operator<<(std::ostream &, const Stonewt &);
	// overload >   automatically inline
	bool operator>(const Stonewt & sw) const
	{return this->pounds > sw.pounds;}
	// overload <
	bool operator<(const Stonewt & sw) const
	{return this->pounds < sw.pounds;}
	// overload >=
	bool operator>=(const Stonewt & sw) const
	{return this->pounds >= sw.pounds;}
	// overload <=
	bool operator<=(const Stonewt & sw) const
	{return this->pounds <= sw.pounds;}
	// overload ==
	bool operator==(const Stonewt & wt) const
	{return this->pounds == wt.pounds;}
	// overload !=
	bool operator!=(const Stonewt & wt) const
	{return this->pounds != wt.pounds;}
};	

#endif

