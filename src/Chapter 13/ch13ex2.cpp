#include "Cd2.h"
#include <iostream>
using std::cout;
using std::endl;
static void Bravo(const Cd2 & disk);
#if defined(DEBUG) | defined(_DEBUG)
#pragma warning (disable : 4505)
#pragma warning (disable : 4189) 
#endif

void ch13ex2(void)
{
	Cd2 c1("Beatles", "Capitol", 14, 35.5);
	ClassicCd2 c2 = ClassicCd2("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd2 *pCd2 = &c1;

	cout << endl << "Using object directly:\n";
	c1.Report();	// use Cd2 method
	c2.Report();	// use ClassicCd2 method

	cout << endl << "Using type Cd2 * pointer to objects:\n";
	pCd2->Report();	// use Cd2 method for Cd2 object
	pCd2 = &c2;
	pCd2->Report();	// use ClassicCd2 method for ClassicCd2 object;

	cout << endl << "calling a function with a Cd2 reference argument:" << endl;
	Bravo(c1);
	Bravo(c2);

	cout << endl << "testing assigment: " << endl;
	ClassicCd2 copy;
	copy = c2;
	copy.Report();
}

static void Bravo(const Cd2 & disk)
{
	disk.Report();
}
