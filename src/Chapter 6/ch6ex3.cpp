#include "../bh_util.h"
#include <iostream>
//#include "bh_lib.h"
using namespace bh_lib::console_util;
using namespace std;


// Prototypes
static void show_menu(void);
static bool valid_choice(char);

void ch6ex3(void)
{
	cout << " - Chapter 6 Exercise 3 - " << endl;
	show_menu();

	char input;
	cin >> input;
	int invalidCount = 0;
	while(!valid_choice(input, "cptg")){
		invalidCount++;
		if (invalidCount >= 4){
			cerr << "ERROR: invalid choice entered too many times! Exiting now..." << endl;
			pbe();
			exit(EXIT_FAILURE);
		}
		cout << "Plese enter a c, p, t, or g: ";
		cin >> input;
	}

	switch(input){
	case 'c':
		cout << "This is a carnivore" << endl;
		break;
	case 'p':
		cout << "Are you a pianist?" << endl;
		break;
	case 't':
		cout << "A maple is a tree." << endl;
		break;
	case 'g':
		cout << "Like a boss!" << endl;
		break;
	default:
		cerr << "ERROR" << endl;
		pbe();
		exit(EXIT_FAILURE);
		break;
	}
	

}

// printf menu
static void show_menu()
{
	cout << "please enter one of the following choices: " << endl;
	cout << "c) carnivore		p) pianist" << endl;
	cout << "t) tree			g) game" << endl;
}

