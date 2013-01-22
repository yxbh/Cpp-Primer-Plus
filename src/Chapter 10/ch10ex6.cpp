#include <iostream>
#include "Move.h"
using namespace std;

void ch10ex6(void)
{
	Move a1(12,32);
	a1.showmove();
	Move a2(32,12);
	Move a3 = a1.add(a2);
	a3.showmove();
	a2.showmove();
	a1.reset(1,0);
	a1.showmove();
}
