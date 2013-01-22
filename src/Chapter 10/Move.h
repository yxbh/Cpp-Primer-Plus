#ifndef _MOVE_H_
#define _MOVE_H_

class Move
{
private:
	double  x;
	double  y;
public:
	Move(double a = 0, double b = 0);	// sets x, y to a, b
	void showmove() const;				// shows current x, y values

	// this function adds x of m to x of invoking object to get new x,
	// adds y of m to y of invoking object to get new y, creates a new
	// move object initialized to new x, y values and returns it
	Move add(const Move & m) const;

	const double get_x(void) const;
	const double get_y(void) const;
	
	void reset(double a = 0, double b = 0); // resets  x, y to a, b
};


#endif

