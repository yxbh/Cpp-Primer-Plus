#include <iostream>

using namespace std;

static void song(const char * name = "O, My Papa", int times = 1);


void ch8re2(void)
{
	song();
}

static void song(const char * name, int times)
{
	while (times)
	{
		cout << name << endl;
		--times;
	}
}