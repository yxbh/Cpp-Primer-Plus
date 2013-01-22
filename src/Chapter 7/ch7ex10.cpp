#include <iostream>
#include <string>
using namespace std;

static double calculate(double, double, double (*func_pt)(double, double));
inline static double sum(double, double);
inline static double product(double x, double y) {return x*y;} 
inline static double max(double x, double y) { return (x > y)? x:y;}
inline static bool enter(void) { cout << "Enter pair of numbers <q to quit>: "; return true;}

typedef double (*func_pt[3])(double, double);
func_pt fp_arr = {sum, product, max};

void ch7ex10()
{
	double x,y;
	bool true_const = true;
	while (true_const){
		while (enter() && (cin >> x >> y)) {
			for (int i = 0; i < 3; ++i){
				cout << calculate(x, y, fp_arr[i]) << " ";
			}
			cout << endl;
		}

		// check for correct quit command. if not back to the loop
		if (!cin) {
			cin.clear();
			string buf;
			cin >> buf;
			if (buf != "q")
				cout << "Invalid input..." << endl;
			else 
				break;
		}
	}
}

static double calculate(double x, double y, double (*func_pt)(double, double))
{
	return func_pt(x, y);
}


// might not be the best example for an inline function since it will be passed as a function pointer.
inline static double sum(double x, double y)
{
	return x+y;
}