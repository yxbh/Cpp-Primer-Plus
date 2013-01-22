#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "bh_lib.h"
using namespace bh_lib::console_util;

struct donor {
	string name;
	double contribution;
};

void ch6ex9()
{
	cout << " - Chapter 6 Exercise 9 - " << endl << endl;

	cout << "Enter file name: ";
	string fname = "ch6ex9_input.txt";
	//cin >> fname;
	cout << "(skipped)" << endl << "load file: " << fname << endl; 
	ifstream fin(fname);

	int pcount;
	fin >> pcount;
	cout << "There are " << pcount << " donoar/s." << endl;

	donor * donors = new donor[pcount];
	for (int i = 0; i < pcount; i++){
		string buffer; // Cannot use getline() here because "fin >> pcount" leaves new line character in stream
		fin >> buffer;
		donors[i].name = buffer + " ";
		fin >> buffer;
		donors[i].name += buffer;
		fin >> donors[i].contribution;
	}

	cout << endl << "Donors who contributed $10,000 or more are: " << endl;
	int a = 0;
	for (int i = 0; i < pcount; i++){
		if (donors[i].contribution >= 10000) {
			a++;
			cout << donors[i].name << ":  $" << donors[i].contribution << endl;
		}
	}
	if (a == 0)
		cout << "None." << endl;

	cout << endl << "Other donors are: " << endl;
	int b = 0;
	for (int i = 0; i < pcount; i++){
		if (donors[i].contribution < 10000) {
			b++;
			cout << donors[i].name << ":  $" << donors[i].contribution << endl;
		}
	}
	if (b == 0)
		cout << "None." << endl;

	delete [] donors;

	cout << endl << "Press Enter to exit function..." << endl;
	pbe();
}