#include <iostream>
#include <string>
#include <fstream>
#include "bh_lib.h"
using namespace bh_lib::console_util;
using namespace std;

// Tax rate
const long tax_1st = 5000;
const long tax_2nd = 10000;
const long tax_3rd = 20000;
const long tax_4th = 35000;
const double t1 = 0.00;
const double t2 = 0.1;
const double t3 = 0.15;
const double t4 = 0.20;

// PROTOTYPEs
double calculate_tax(double, int);

void ch6ex5()
{
	cout << " - Chapter 6 Exercise 5 - " << endl;
	double input = 0;
	cout << "Enter amount of tvarp: ";
	cin >> input;
	while( input >= 0 && cin){
		double tax = calculate_tax(input, 0);
		cout << "Tax = " << tax << "tvarps." << endl;
		cout << "Enter amount of tvarp: ";
		cin >> input;
	}

	// Check cin's state
	if (cin.fail() || cin.bad()){
		cin.clear();
		string mismatch;
		cin >> mismatch;
		cerr << "Failed" << endl;
		fstream fout;
		fout.open("error.log", ios::app);
		fout << "Type mismatch encounted:  " << mismatch << endl;
		fout.close();
		cerr << "Press enter to exit now..." << endl;
		pbe();
		exit(EXIT_FAILURE);
	} else if (input < 0) {
		cout << "Press Enter to exit..." << endl;
	}
}

/*
@param: double amount guaranteed to be >= 0 
@param: int tax_stage always called externally with 0;
*/
double calculate_tax(double amount, int tax_stage)
{
	if (tax_stage == 0) 
	{
		if (amount >= 0) {
			if (amount >= tax_1st) 
				return 0 + calculate_tax(amount - tax_1st, tax_stage+1);
			else
				return 0.0;
		} else {
			bh_unexpected_error("calculate_tax()");
			return -0.1;
		}
	}
	else if (tax_stage == 1)
	{
		if (amount >= tax_2nd) 
			return t2*tax_2nd + calculate_tax(amount - tax_2nd, tax_stage+1);
		else
			return amount*t2;
	}
	else if (tax_stage == 2)
	{
		if (amount >= tax_3rd) 
			return t3*tax_3rd + calculate_tax(amount - tax_3rd, tax_stage+1);
		else
			return amount*t3;
	}
	else if (tax_stage == 3)
	{

		return amount*t4;
	}
	else
	{
		bh_unexpected_error("calculate_tax()");
		return -0.1;
	}
}