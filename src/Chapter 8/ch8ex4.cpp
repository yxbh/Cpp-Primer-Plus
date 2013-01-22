#if defined(_WIN32) || defined (_WIN64)
#define _CRT_SECURE_NO_WARNINGS   // VC++ specific: removes flag/warning for strcpy()
#endif
#include <iostream>
#include <cstring>	// for strlen(), strcpy()
using namespace std;

namespace {
	struct stringy {
		char * str;		// points to string
		int ct;			// length of string (not count '\0')
	};

	// prototypes for set(), show(), and show() go here
	void set(stringy &, const char *);
	void show(const stringy &, int n = 1);
	void show(const char *, int n = 1);
	void destruct(stringy &);
}

void ch8ex4(void)
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);	// first argument is a reference,
	// allocates space to hold copy of testing,
	// sets str member of beany to point to the
	// new block, copies testing to new block,
	// and sets ct member of beany
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	destruct(beany);
}

namespace {
	void set(stringy & str, const char * str_t)
	{
		str.ct = strlen(str_t);
		char * temp = new char[str.ct+1];
		strcpy(temp, str_t);
		str.str = temp;
	}

	void show(const stringy & str, int n)
	{
		while (n)
		{
			cout << str.str << endl;
			--n;
		}
	}

	void show(const char * str, int n)
	{
		while (n)
		{
			cout << str << endl;
			--n;
		}
	}

	void destruct(stringy & a)
	{
		delete [] a.str;
		a.str = NULL;
	}
}