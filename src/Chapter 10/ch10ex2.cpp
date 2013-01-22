#include "Person.h"

void ch10ex2(void)
{
	Person one;
	Person two("Smythecraft");
	Person three("Dimiwiddy", "Sam");
	one.Show();
	one.FormalShow();
	two.Show();
	two.FormalShow();
	three.Show();
	three.FormalShow();
}