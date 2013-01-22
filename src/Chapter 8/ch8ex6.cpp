#include <iostream>
using namespace std;

template<typename T>
static const T maxn(const T[], int n);

typedef char * STR; // take note, with out the typedef, the following template specilisation wont work!!!
template <> static const STR maxn<STR>(const STR[], int n);

void ch8ex6(void)
{
	int int_arr[6] = {32, 12, 32, 1, 543, 132};
	cout << maxn(int_arr, 6) << endl;

	double double_arr[4] = {32.43, 123.5, 2.34, 32.4};
	cout << maxn(double_arr, 4) << endl;

	STR str_arr[5] = {"Hello world", "no way man!", "hey there!", "omg!", "oh no..."};
	cout << maxn(str_arr, 5) << endl;
}


template<typename T>
static const T maxn(const T arr[], int n)
{
	T max = arr[0];
	for (int i = 0; i < n; i++) {
		if ( arr[i] > max) 
			max = arr[i];
	}
	return max;
}

template <> static const STR maxn<STR>(const STR str_arr[], int n)
{
	STR temp = str_arr[0];
	unsigned temp_len = strlen(str_arr[0]);
	for (int i = 0; i < n; i++){
		unsigned a;
		a = strlen(str_arr[i]);
		if (a > temp_len) {
			temp_len = a;
			temp = str_arr[i];
		}
	}
	return temp;
}
