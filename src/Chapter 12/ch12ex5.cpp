#include "queue.h"
#include "chapter12_exercises.h"
using namespace ch12;
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::endl;
using std::cout;

void ch12ex5(void)
{
	string input;
	cout << "quit?";
	while(cin >> input && input != "q")
	{
		bank();
		cout << "quit?";
	}
	cin.get();
}