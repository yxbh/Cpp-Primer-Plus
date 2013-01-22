#include "List.h"
#include <iostream>
using namespace std;

void ch10ex8(void)
{
	List l = List();
	cout << l.isEmpty() << endl;	
	l.add(123);
	l.add(254);
	l.add(540);
	l.show();
	cout << l.isEmpty() << endl;
	
}
