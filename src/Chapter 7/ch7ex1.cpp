#include <iostream>

using namespace std;

static double harmonic_mean(int, int);

void ch7ex1()
{
	int x, y;
	cout << "Enter 2 values: ";
	while(cin >> x >> y)
	{
		if (x == 0 || y == 0) 
			break;
		
		cout << "The harmonic mean of the two values is " << harmonic_mean(x, y) << endl;

		cout << "Enter 2 values: ";
	}

	if (!cin)
		cin.clear();
}

static double harmonic_mean(int x, int y)
{
	return 2.0*x*y/(x+y);
}