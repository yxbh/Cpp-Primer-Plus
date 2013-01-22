#include <iostream>

using namespace std;

const int Seasons = 4;

const char * const Snames[Seasons] =
{"Spring", "Summer", "Fall", "Winter"};

static void fill(double []);
static void show(double []);

void ch7ex8a()
{
	double expenses[Seasons];
	fill(expenses);
	show(expenses);
}

static void fill(double pa[])
{
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << "Enter " << Snames[i] << " expenses: ";
		std::cin >> pa[i];
	}
}

static void show(double da[])
{
	double total = 0.0;
	std::cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << Snames[i] << ": $" << da[i] << '\n';
		total += da[i];
	}
	std::cout << "Total: $" << total << '\n';
}
