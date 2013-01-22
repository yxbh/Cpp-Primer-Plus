#ifndef _WINE2_H_
#define _WINE2_H_
#include <string>
using std::string;
#include <valarray>
using std::valarray;
#include <utility>
using std::pair;

class Wine2 : private string
{
private:
	string label;
	int num_yr;
	pair<valarray<int>, valarray<int>> info;
public:
	//================================================
	// constructors and destructors
	//================================================

	// default constructor 
	Wine2();
	// initialize label to l, number of years to y,
	// vintage years to yr[], bottles to bot[]
	Wine2(const char * l, int y, const int yr[], const int bot[]);
	// initialize label to l, number of years to y,
	// create array of objects of length y
	Wine2(const char * l, int y);
	// destructor
	~Wine2() {}

	//================================================
	// methods
	//================================================
	
	// given num_yr, prompt user to enter years and bottles
	void GetBottles(void);
	// return label name
	const string & Label(void) const
	{
		return (const string &)*this;
	}
	// returns int, the total number of bottles
	const int sum(void) const
	{
		return info.second.sum();
	}
	// print Wine2 details
	void Show(void) const;
};



#endif

