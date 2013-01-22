#include <iostream>
#include <string>
using namespace std;

struct CandyBar {
	char * brand_name;
	double weight;
	int calore;
};

static void fill_info(CandyBar & cb, char * const bn = "Millennium Munch", const double w = 2.85, const int c = 350);
static void display(const CandyBar &);

void ch8ex2(void)
{
	CandyBar cb;
	fill_info(cb);
	display(cb);
}

static void fill_info(CandyBar & cb, char * const bn, const double w, const int c)
{
	cb.brand_name = bn;
	cb.weight = w;
	cb.calore = c;
}

static void display(const CandyBar & cb)
{
	cout << cb.brand_name << endl;
	cout << cb.weight << endl;
	cout << cb.calore << endl;
}