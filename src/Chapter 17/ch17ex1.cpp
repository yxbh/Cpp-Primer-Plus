#include "chapter17_exercises.h"
#include <iostream>

void ch17ex1(void)
{
	unsigned int count = 0;
	while ( std::cin.get() != '$')
		++count;

	std::cin.putback('$').get();

	std::cout << count << std::endl;

}
