#include "Wine2.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//================================================
// Constructor
//================================================
Wine2::Wine2(void)
	: string("")
{
	num_yr = 0;
}

//================================================
// Constructor
//================================================
Wine2::Wine2(const char * l, int y, const int yr[], const int bot[])
	: string(l)
{
	num_yr = y;
	info.first.resize(y);
	info.second.resize(y);
	for (int i = 0; i < y; i++)
	{
		info.first[i] = yr[i];
		info.second[i] = bot[i];
	}
}

//================================================
// Constructor
//================================================
Wine2::Wine2(const char * l, int y)
{
	label = l;
	num_yr = y;
	info.first.resize(y);
	info.second.resize(y);
}

//================================================
// GetBottles method
//================================================
void Wine2::GetBottles(void)
{
	if (num_yr == 0)
	{
		cout << "Number of years is 0" << endl;
		return;
	}

	for (int i = 0; i < num_yr; i++)
	{
		cout << "Enter year: ";
		cin >> info.first[i];
		cout << "Enter number of bottle: ";
		cin >> info.second[i];
	}
}

//================================================
// print wine details
//================================================
void Wine2::Show(void) const
{
	cout << "Label: " << label << endl;
	cout << "Number of years: " << num_yr << endl;
	for (int i = 0; i < num_yr; i++)
	{
		cout.width(5);
		cout << " Year: " << info.first[i] << ": ";
		cout.width(3);
		cout << info.second[i] << endl;
	}
}