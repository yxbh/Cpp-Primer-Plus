#include "Cow.h"
#include <iostream>

void ch12ex1(void)
{
	Cow c;
	c.ShowCow();
	Cow a("Bob", "Guitar", 222);
	a.ShowCow();
	c = Cow("Bob", "Guitar", 222);
	c.ShowCow();
}