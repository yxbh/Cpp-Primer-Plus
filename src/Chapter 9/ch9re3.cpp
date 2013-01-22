#include <iostream>

void ch9re(void)
{
	double x;
	std::cout << "Enter value: ";
	while (! (std::cin >> x) )
	{
		std::cout << "Bad input. Please enter a number: ";
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	std::cout << "value = " << x << std::endl;
	return;
}