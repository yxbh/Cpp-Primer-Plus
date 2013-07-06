#include <iostream>
#include <string>
#include "bh_util.h"
#include "chapters.h"
using namespace std;
using namespace bh_lib::console_util;

namespace 
{
	void welcome();
	void call_exit(void);
}

int main()
{
	::welcome(); // Print welcome message

	//ch17re7();
	//ch17ex1();
	//ch17ex2();
	//ch17ex3();
	//ch17ex4();
	//ch17ex5();
	//ch17ex6();
	ch17ex7();

	::call_exit(); // exit msg and pause

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