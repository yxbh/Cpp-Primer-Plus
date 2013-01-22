#include <iostream>

using namespace std;

struct box
{
	char maker[40];
	double height;
	double width;
	double length;
	double volume;
};

// PROTOTYPE
static void print_box_info(box);
static void calculate_volume(box *);

void ch7ex3()
{
	box myBox = {"Bob", 3.30, 3, 4.03, 3};

	print_box_info(myBox);
	calculate_volume(&myBox);
	print_box_info(myBox);

}

static void print_box_info(box b)
{
	cout << "Box information: " << endl;
	cout << "  Maker: " << b.maker << endl;
	cout << "  Height: " << b.height << endl;
	cout << "  Width: " << b.width << endl;
	cout << "  Length: " << b.length << endl;
	cout << "  Volume: " << b.volume << endl << endl;
}

static void calculate_volume(box * b)
{
	b->volume = b->height * b->width * b->width;
}