#include "chapter17_review.h"
#include <string>
#include <iostream>
#include <iomanip>

void ch17re7(void)
{
	std::string name;
	float wage;
	std::size_t hours_worked;
	std::cout << "Enter your name: ";
	getline(std::cin, name);
	std::cout << "Enter your hourly wage: ";
	std::cin >> wage; std::cin.get();
	std::cout << "Enter number of hours worked: ";
	std::cin >> hours_worked; std::cin.get();

	// first format
	std::cout << "First format:\n";
	std::cout.width(20);
	std::cout << std::right << name <<":" << " $";
	std::cout.width(7);
	std::cout << std::right << wage << ":";
	std::cout.width(5);
	std::cout << std::right << hours_worked << std::endl;

	// second format
	std::cout << "Second format:\n";
	std::cout.width(20);
	std::cout << std::left << name << " : $";
	std::cout.width(7);
	std::cout << wage << ":" << hours_worked << std::endl;
}
