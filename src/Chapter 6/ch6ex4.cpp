#include <iostream>
#include <array>
#include "chapter6_exercises.h"
#include "bh_lib.h"
using namespace std;
using namespace bh_lib::console_util;

const int strsize = 255;

// prototype
static void show_menu(void);

struct bop {
	char fullname[strsize];	// real name
	char title[strsize];	// job title
	char bopname[strsize];	// secret BOP name
	int preference;			// 0 = fullname, 1 = title, 2 = bopname
};


void ch6ex4()
{
	cout << " - Chapter 6 Exercise 4 - " << endl;
	show_menu();

	array<bop, 5> bop_list = {{
		{"Wimp Macho","no body","lol",0},
		{"Raki Rhodes","Junior programmer","lol2",1},
		{"Celia Laiter","no body","MIPS",2},
		{"Hoppy Hipman","analyst Trainee","lol",1},
		{"Pat Hand","no body","LOOPY",2}
	}};

	char input;
	cout << "Enter your choice: ";
	cin >> input;
	while(valid_choice(input, "abcdq") && input != 'q'){
		if (input == 'a') // display by name
		{			
			for (int i = 0; (unsigned)i < bop_list.size(); i++)
				cout << bop_list[i].fullname << endl;
		} 
		else if (input == 'b') // display by title
		{	
			for (int i = 0; (unsigned)i < bop_list.size(); i++)
				cout << bop_list[i].title << endl;
		}
		else if (input == 'c') // display by bopname
		{	
			for (int i = 0; (unsigned)i < bop_list.size(); i++)
				cout << bop_list[i].bopname << endl;
		} 
		else // display by preference
		{	
			for (int i = 0; (unsigned)i < bop_list.size(); i++){
				switch(bop_list[i].preference){
				case 0:
					cout << bop_list[i].fullname << endl;
					break;
				case 1:
					cout << bop_list[i].title << endl;
					break;
				case 2:
					cout << bop_list[i].bopname << endl;
					break;
				default:
					cerr << "ERROR: invalid preference" << endl;
					break;
				}
			}
		}

		// Ask for entry again
		cout << "Enter your choice: ";
		cin >> input;
	}

	// post check
	if (input == 'q'){
		cout << "Press Enter to exit." << endl;
		return;
	} else if (!valid_choice(input, "abcdq")){
		cout << "ERROR: bad input! " << endl;
		return;
	} else {
		cerr << "ERROR: Unknown error!..." << endl;
		cerr << "call exit now... "<< endl;
		exit(EXIT_FAILURE);
	}

}

static void show_menu()
{
	cout << "a. display by name     b. display by title" << endl;
	cout << "c. display by bopname  d. display by preference" << endl;
	cout << "q. quit" << endl;

}