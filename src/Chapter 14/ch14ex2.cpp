#include "Wine2.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void ch14ex2(void)
{
	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	Wine2 holding(lab, yrs); // store label, years, give arrays yrs elements
	holding.GetBottles();	// solicit input for year, bottle count
	holding.Show();			// display object contents

	const int YRS = 3;
	int y[YRS] = {1993, 1995, 1998};
	int b[YRS] = {48, 60, 72};
	// create bew object, initialize using data in arrays y and b
	Wine2 more("Gushing Grape red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label() // use Label() method
		<< ": " << more.sum() << endl;			 // use sum() method
	cout << "Bye\n";

	cin.get(); // flush cin
}