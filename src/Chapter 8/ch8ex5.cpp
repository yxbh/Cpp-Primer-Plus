#include <iostream>
using namespace std;

template<typename T>
static T max5(const T[5]);

void ch8ex5(void)
{
	int int_arr[5] = {12, 32, 1, 543, 132};
	cout << max5(int_arr) << endl;
}

template<typename T>
static T max5(const T arr[5])
{
	T max = arr[0];
	for (int i = 0; i < 5; i++) {
		if ( arr[i] > max) 
			max = arr[i];
	}
	return max;
}
