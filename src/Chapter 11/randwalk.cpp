// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <fstream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vect.h"

int randwalk()
{
    using namespace std;
    using VECTOR::Vector;
	typedef unsigned int uint;
    srand((uint)time(0));     // seed random-number generator
    double direction, target, dstep;
    Vector step, result(0.0, 0.0);
    unsigned long steps = 0;
	ofstream fout("ch11ex1_output.txt");
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;

		// out to file
		fout << "Target Distance: " << target  << ", Step Size: " << dstep << endl;

        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;

			// out to file
			cout << steps - 1 << ": " << result << endl; // debug ////
			fout << steps - 1 << ": " << result << endl;
        }
        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval()/steps << endl;

		// out to file too
		fout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        fout << result << endl;
        result.polar_mode();
        fout << " or\n" << result << endl;
        fout << "Average outward distance per step = "
            << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);

        cout << "Enter target distance (q to quit): ";
		    }
    cout << "Bye!\n";

	fout.close();

    return 0; 
}
