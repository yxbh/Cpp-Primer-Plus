#include "chapter16_exercises.h"

static int reduce(long ar[], int n);

void ch16ex4(void)
{
	long ar[] = {32, 12, 123, 54, 123, 12};

	std::cout << std::endl << reduce(ar, 6) << std::endl;
}

int reduce(long ar[], int n)
{

	std::sort(ar, ar+n);
	auto ptr = std::unique(ar, ar+n);
	std::copy(ar, ptr, std::ostream_iterator<long>(std::cout, " "));
	return ptr-ar;
}
