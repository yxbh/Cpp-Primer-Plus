#include "chapter18_review.h"

template<typename T>
void show2(double x, T fp)
{ std::cout << x << " -> " << fp(x) << '\n'; }

void ch18re6(void)
{
	show2(18.0, [](double x){return 1.8*x+32;});
}
