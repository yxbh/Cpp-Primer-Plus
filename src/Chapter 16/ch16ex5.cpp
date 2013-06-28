#include "chapter16_exercises.h"

template<typename T>
static int reduce(T ar[], int n);

void ch16ex5(void)
{
	long ar[] = {32, 12, 123, 54, 123, 12};
	std::cout << std::endl << reduce(ar, 6) << std::endl;

	std::string st[] = {"hello", "bob", "ben", "ben", "hello"};
	std::cout << std::endl << reduce(st, 5) << std::endl;
}

template<typename T>
int reduce(T ar[], int n)
{

	std::sort(ar, ar+n);
	auto ptr = std::unique(ar, ar+n);
	std::copy(ar, ptr, std::ostream_iterator<T>(std::cout, " "));
	return ptr-ar;
}
