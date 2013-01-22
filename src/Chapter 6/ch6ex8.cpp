#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void ch6ex8()
{
	cout << " - Chapter 6 Exercise 8 - " << endl << endl;

	cout << "Enter file name: ";
	string fname;
	cin >> fname;
	ifstream fin(fname);

	char ch;
	int ch_count = 0;
	cout << endl << "File: " << endl;
	while (!fin.eof()){
		fin.get(ch);
		ch_count++;
		cout << ch;
	}

	cout << endl << "eof reached. There are " << ch_count << " character\\s" << endl;
	cout << "Exiting now..." << endl;
	cout << "Press Enter to exit..." << endl;
	return;

}