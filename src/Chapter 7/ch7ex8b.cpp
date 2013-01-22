#include <iostream>

using namespace std;

const int Seasons = 4;

const char * const Snames[Seasons] =
{"Spring", "Summer", "Fall", "Winter"};

struct expenses_arr {
	double arr[Seasons];
};

static void fill(expenses_arr);
static void show(const expenses_arr);

void ch7ex8b()
{
	expenses_arr expenses = {};
	fill(expenses);
	show(expenses);
}

static void fill(expenses_arr pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << "Enter " << Snames[i] << " expenses: ";
		std::cin >> pa.arr[i];
	}
}

static void show(const expenses_arr da)
{
	double total = 0.0;
	std::cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << Snames[i] << ": $" << da.arr[i] << '\n';
		total += da.arr[i];
	}
	std::cout << "Total: $" << total << '\n';
}
