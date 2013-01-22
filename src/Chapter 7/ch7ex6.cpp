#include <iostream>

using namespace std;

static int Fill_array(double [], int);
static void Show_array(const double [], int);
static void Reverse_array(double [], int);

void ch7ex6()
{
	std::cout << " - Chapter 7 Exercise 6 - " << std::endl << std::endl;

	cout << "Make array: arr" << endl;
	const int size = 7;
	int input_count;
	double arr[size];
	cout << "Fill array..." << endl;
	input_count = Fill_array(arr, size);
	cout << "Show array..." << endl;
	Show_array(arr, input_count);
	cout << "Reverse array..." << endl;
	Reverse_array(arr, input_count);
	cout << "Show array..." << endl;
	Show_array(arr, input_count);

	cout << endl << "exiting..." << endl;

}

static int Fill_array(double arr[], int size)
{
	double input;
	int index = 0;
	cout << "Enter a double number <d to finish>:";
	while (index < size && cin >> input) {
		arr[index] = input;
		index++;

		if (index < size)
			cout << "Enter another double: ";
	}

	return index;
}

static void Show_array(const double arr[], int size)
{
	for (int i= 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// ignore 1st and last element in the arr
static void Reverse_array(double arr[], int size)
{
	int i = 1;
	while (i < (size-1-i)) {
		double temp = arr[i];
		arr[i] = arr[size-1-i];
		arr[size-1-i] = temp;
		i++;
	}
}