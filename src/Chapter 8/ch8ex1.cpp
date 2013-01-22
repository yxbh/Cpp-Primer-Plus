#include <iostream>
#include <cstring>
#include <string>
using namespace std;
static void print_string(const char *, const int n = 0);

void ch8ex1(void)
{
	print_string("hello there", 12);
	print_string("hello there", 12);
	print_string("hello there", 12);
}

static void print_string(const char * str, const int n)
{
	static int call_count = 0;
	call_count++; //cout << "call_count: " << call_count << endl;
	cout << "This is the " << call_count << " call." << endl;
	int a = call_count;
	if (n == 0)
		cout << str << endl;
	else {
		while (a) {
			cout << str << endl;
			--a;
		}
	}
			
}