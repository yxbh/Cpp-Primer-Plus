#include <iostream>

using namespace std;

static double * Fill_array(double [], int);
static void Show_array(const double [], const double * const);
static void Reverse_array(double [], double *);


void ch7ex7()
{
	std::cout << " - Chapter 7 Exercise 7 - " << std::endl << std::endl;

	cout << "Make array: arr" << endl;
	const int size = 7;
	double * arr_end, arr[size];
	cout << "Fill array..." << endl;
	arr_end = Fill_array(arr, size);
	cout << "Show array..." << endl;
	Show_array(arr, arr_end);
	cout << "Reverse array..." << endl;
	Reverse_array(arr, arr_end);
	cout << "Show array..." << endl;
	Show_array(arr, arr_end);

	cout << endl << "exiting..." << endl;

}

static double * Fill_array(double arr[], int size)
{
	double input, * pos = arr;
	cout << "Enter a double number <d to finish>:";
	while ((pos-arr) < size && cin >> input) {
		(*pos) = input;
		pos++;

		if ((pos-arr) < size)
			cout << "Enter another double: ";
	}

	return pos;
}

static void Show_array(const double arr[], const double * const arr_end)
{
	while (arr != arr_end){
		cout << *arr << " ";
		arr++;
	}
	cout << endl;
}

// ignore 1st and last element in the arr
static void Reverse_array(double arr[], double * arr_end)
{
	arr++; // ignoring 1st element
	while (arr < arr_end) {
		double temp = *arr;   // temp place holder
		*arr = *(arr_end-2); 
		*(arr_end-2) = temp;
		arr++; arr_end--;
	}
}