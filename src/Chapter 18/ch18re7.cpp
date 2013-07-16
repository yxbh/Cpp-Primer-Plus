#include "chapter18_review.h"

static const int Size = 5;

template<typename T>
void sum(std::array<double, Size> a, T fp)
{
	for (auto pt : a)
		fp(pt);
}

//class Adder
//{
//private:
//	double tot;
//public:
//	Adder(double q = 0 ) : tot(q) {}
//	void operator()(const double w) {tot +=w;}
//	double tot_v(void) const {return tot;}
//};

void ch18re7(void)
{
	double total = 0.0;
	std::array<double, Size> temp_c = {32.1, 34.3, 37.8, 35.2, 34.7};
	sum(temp_c, [&total](double val){total+=val;});
	std::cout << "Total: " << total << '\n';
}
