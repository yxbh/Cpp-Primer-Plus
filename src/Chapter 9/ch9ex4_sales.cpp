#include "ch9ex4.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

namespace SALES
{
	void setSales(Sales & s, const double ar[], int n)
	{
		cout << "function descrition makes no sense... so is this sentence..." << endl;
		cout << &s << "  " << ar << "  " << &n << endl;
	}

	void setSales(Sales & s)
	{
		cout << "Enter the sales numbers for the " << QUARTERS << " quarters." << endl;
		cin >> s.sales[0] >> s.sales[1] >> s.sales[2] >> s.sales[3]; cin.get();
		double max = 0;
		for (int i = 0; i < QUARTERS; i++)
		{
			if (s.sales[i] > max)
				max = s.sales[i];
			s.max = max;
		}
		double min = max;
		for (int i = 0; i < QUARTERS; i++)
		{
			if (s.sales[i] < max)
				min = s.sales[i];
		}
		s.min = min;
		double sum = 0;
		for (int i = 0; i < QUARTERS; i++)
			sum += s.sales[i];
		s.average = sum / QUARTERS;
	}

	void showSales(const Sales & s)
	{
		cout << "sales:" << endl;
		for (int i = 0; i < QUARTERS; i++)
			cout << s.sales[i] << "  ";
		cout << endl;
		cout << "avg: " << s.average << endl;
		cout << "max: " << s.max << endl;
		cout << "min: " << s.min << endl;
	}
}