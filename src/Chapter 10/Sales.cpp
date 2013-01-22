#include "Sales.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

namespace SALES
{
	Sales::Sales(void)
	{
		cout << "Enter the sales numbers for the " << QUARTERS << " quarter" << endl;
		cin >> sales[0] >> sales[1] >> sales[2] >> sales[3]; cin.get();
		double max = 0;
		for (int i = 0; i < QUARTERS; i++)
		{
			if (sales[i] > max)
				max = sales[i];
			max = max;
		}
		double min = max;
		for (int i = 0; i < QUARTERS; i++)
		{
			if (sales[i] < max)
				min = sales[i];
		}
		min = min;
		double sum = 0;
		for (int i = 0; i < QUARTERS; i++)
			sum += sales[i];
		average = sum / QUARTERS;
	}

	Sales::Sales(const double ar[], int n)
	{
		cout << "function descrition makes no sense... so is this sentence..." << endl;
		cout << this << "  " << ar << "  " << &n << endl;
	}

	void Sales::showSales(void) const
	{
		cout << "sales:" << endl;
		for (int i = 0; i < QUARTERS; i++)
			cout << sales[i] << "  ";
		cout << endl;
		cout << "avg: " << average << endl;
		cout << "max: " << max << endl;
		cout << "min: " << min << endl;
	}

}