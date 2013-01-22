#include <iostream>



struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

// cant seem to work out the specilisation stuff
static float larger(const box &, const box &);

static void cal_vol(box &);

template <typename T>
static T larger(const T &, const T &);

void ch8re8(void)
{
	box a = {"Kevin", 212,33,13};
	box b = {"Ben", 12,32,43};
	cal_vol(a);
	cal_vol(b);
	std::cout << larger(a,b);
}

template<typename T>
static T larger(const T & x, const T & y)
{
	return (x > y) ? x : y;
}

static float larger(const box & x, const box & y)
{
	return (x.volume > y.volume) ? x.volume : y.volume;
}

static void cal_vol(box & b)
{
	b.volume = b.height * b.width * b.length;
}