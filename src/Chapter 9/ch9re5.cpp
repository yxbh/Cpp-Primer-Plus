#include <iostream>
using std::cout;
using std::endl;

namespace {
	template<typename T>
	T average(T, T);
}

void ch9re5(void)
{
	int a = 12, b = 7;
	double c = 12.56, d = 43.2;
	cout << average(a,b) << endl;
	cout << average(c,d) << endl;
}

namespace {
	template<typename T>
	T average(T x, T y)
	{
		return (T)(x + y)/2;
	}
}