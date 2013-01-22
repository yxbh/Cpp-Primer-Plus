#include <iostream>
#include <string>
#include "bh_lib.h"
#include "chapters.h"
using namespace std;
using namespace bh_lib::console_util;

namespace {
	void welcome(void);
	void call_exit(void);
}

int main()
{
	welcome(); // Print welcome message

	

	//ch14ex1();
	//ch14ex2();
	//ch14ex3();
	ch14ex4();

	call_exit(); // exit msg and pause

	return 0;
}

namespace {
	void welcome()
	{
		cout << "################################################################" << endl;
		cout << "             C++ Primer Plus exercise solutions" << endl;
		cout << "                #Author: Ben Huang 2012-2013(c)" << endl;
		cout << "################################################################" << endl;
	}

	void call_exit(void)
	{
		cout << endl << "Press Enter to exit program..." << endl;
		pbe(); // wait for enter/s before exit
	}
}