#include "Cd.h"
#include <iostream>
using std::cout;
using std::endl;

static void Bravo(const Cd & disk);

void ch13ex1(void)
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	ClassicCd c2 = ClassicCd("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd *pCd = &c1;

	cout << endl << "Using object directly:\n";
	c1.Report();	// use Cd method
	c2.Report();	// use ClassicCd method

	cout << endl << "Using type Cd * pointer to objects:\n";
	pCd->Report();	// use Cd method for Cd object
	pCd = &c2;
	pCd->Report();	// use ClassicCd method for ClassicCd object;

	cout << endl << "calling a function with a Cd reference argument:" << endl;
	Bravo(c1);
	Bravo(c2);

	cout << endl << "testing assigment: " << endl;
	ClassicCd copy;
	copy = c2;
	copy.Report();
}

static void Bravo(const Cd & disk)
{
	disk.Report();
}
