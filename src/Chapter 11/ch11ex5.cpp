#include <iostream>
#include "Stonewt.h"
using std::cout;
using std::endl;

void ch11ex5(void)
{
	Stonewt wt = Stonewt(123);
	cout << wt << endl;
	cout << wt.change_mode(Stonewt::mode::STONEP) << endl;
	cout << wt * 2 << endl;
	Stonewt wt2(999);
	Stonewt wt3 = wt2 + wt;
	cout << wt3 << endl;
	cout << wt3 + wt << endl;
}
