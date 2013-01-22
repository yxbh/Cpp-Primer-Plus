#include <iostream>
using namespace std;

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

static void func(const box &);
static void cal_vol(box &);

void ch8re4(void)
{
	box b = {"Ben", 12,32,43};
	cal_vol(b);
	func(b);
}

static void func(const box & b)
{
	cout << b.maker << endl;
	cout << b.height << endl;
	cout << b.width << endl;
	cout << b.length << endl;
	cout << b.volume << endl;
}

static void cal_vol(box & b)
{
	b.volume = b.height * b.width * b.length;
}