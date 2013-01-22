#include "Move.h"
#include <iostream>
using std::cout;
using std::endl;

Move::Move(double a, double b)	// sets x, y to a, b
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
}

// this function adds x of m to x of invoking ob ject to get new x,
// adds y of m to y of invoking object to get new y, creates a new
// move object initialized to new x, y values and returns it
Move Move::add(const Move & m) const
{
	return Move(this->get_x() + m.get_x(),
		this->get_y() + m.get_y());
}

const double Move::get_x(void) const
{
	return x;
}

const double Move::get_y(void) const
{
	return y;
}

void Move::reset(double a, double b) // resets  x, y to a, b
{
	x = a;
	y = b;
}
