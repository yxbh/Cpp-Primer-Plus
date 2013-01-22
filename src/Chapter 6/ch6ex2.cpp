#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <array>

using namespace std;

void quit();


void ch6ex2()
{
	cout << " - Chapter 6 Exercise 2 - " << endl;
	cout << "Ready\n";
	
	array<double, 20> donation = {};

	double input;
	int dcount = 0; // donation count

	while ((dcount < 5) && (cin >> input)) // TODO change this back to 20
	{
		dcount++;
		cerr << dcount << endl;
		donation[dcount-1] = input;
	}

	// Check cin's state
	if (cin.fail() || cin.bad()){
		cin.clear();
		string mismatch;
		cin >> mismatch;
		cerr << "Failed" << endl;
		fstream fout("error.log");
		fout << "Type mismatch encounted:  " << mismatch << endl;
		fout.close();
		cerr << "Exiting now..." << endl;
		quit();
		exit(EXIT_FAILURE);
	}

	double sum = 0;
	for (int i = 0; i < 20; i++){
		sum += donation[i];
	}
	cout << "The sum is $" << sum << endl;
	cout << "Average is $" << sum/20 << endl;
	int davg = 0;
	for (int i = 0; i < 20; i++){
		if (donation[i] > sum/20)
			davg++;
	}
	cout << davg << " donations are higher than the average!" << endl;


	quit();
}

void quit()
{
	cerr << "Press enter\\s to exit" << endl;
	cin.get();
	cin.get();
}

