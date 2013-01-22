#ifndef _WINE_H_
#define _WINE_H_
#include <string>
using std::string;
#include <valarray>
using std::valarray;
#include <utility>
using std::pair;

class Wine
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
	Wine();
	// initialize label to l, number of years to y,
	// vintage years to yr[], bottles to bot[]
	Wine(const char * l, int y, const int yr[], const int bot[]);
	// initialize label to l, number of years to y,
	// create array of objects of length y
	Wine(const char * l, int y);
	// destructor
	~Wine() {}

	//================================================
	// methods
	//================================================
	
	// given num_yr, prompt user to enter years and bottles
	void GetBottles(void);
	// return label name
	const string & Label(void) const
	{
		return label;
	}
	// return the total number of bottles
	const int sum(void) const
	{
		return info.second.sum();
	}
	// print Wine details
	void Show(void) const;
};



#endif

