#include <iostream>
#include <string>

static long double probability(unsigned numbers, unsigned picks);

void ch7ex4()
{
	using namespace std;

	std::cout << " - Chapter 7 Exercise 4 - " << std::endl << std::endl;

	cout << "Enter the total number of choices on the game card and\n"
		"the number of picks allowed and then enter the total \n"
		"number of mega number:\n";
	bool true_const = true;
	while (true_const) 
	{
		int total, choices, total_mega;
		while ((cin >> total >> choices >> total_mega) && choices <= total)
		{
			cout << "You have one chance in ";
			cout << probability(total, choices) * probability(total_mega, 1);      // compute the odds
			cout << " of winning.\n";
			cout << "Next three numbers (q to quit): ";
		}

		if (!cin) {
			string str_buf;
			cin.clear();
			cin >> str_buf;
			if (str_buf != "q")
				cerr << "Invalid input..." << endl;
			else
				break;
		}
		cout << "Next three numbers (q to quit): ";
	}

	cout << "bye\n";
}

// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
static long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;  // here come some local variables
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p ; 
	return result;
}
