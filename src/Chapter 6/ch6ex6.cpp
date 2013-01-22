#include <iostream>
#include <string>
#include "bh_lib.h"
using namespace std;
using namespace bh_lib::console_util;

struct donor {
	string name;
	double contribution;
};

//vector<donor> donors();

void ch6ex6(void)
{
	cout << " - Chapter 6 Exercise 6 - " << endl << endl;

	int arrSize;
	cout << "Enter the number of contributor/s: ";
	cin >> arrSize;
	donor * donors = new donor[arrSize];
	for (int i = 0; i < arrSize; i++) {
		cout << "Enter name for donor " << i+1 << ": ";
		cin >> donors[i].name;
		cout << "Enter the amount of contribution: ";
		cin >> donors[i].contribution;
	}

	cout << endl << "Donors who contributed $10,000 or more are: " << endl;
	int a = 0;
	for (int i = 0; i < arrSize; i++){
		if (donors[i].contribution >= 10000) {
			a++;
			cout << donors[i].name << ":  $" << donors[i].contribution << endl;
		}
	}
	if (a == 0)
		cout << "None." << endl;

	cout << endl << "Other donors are: " << endl;
	int b = 0;
	for (int i = 0; i < arrSize; i++){
		if (donors[i].contribution < 10000) {
			b++;
			cout << donors[i].name << ":  $" << donors[i].contribution << endl;
		}
	}
	if (b == 0)
		cout << "None." << endl;

	delete [] donors;
	pbe();

}