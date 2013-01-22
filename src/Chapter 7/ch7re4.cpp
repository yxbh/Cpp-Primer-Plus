#include <iostream>

using namespace std;

static void func(int*, int*, int);

void ch7re4()
{
	std::cout << " - Chapter 7 Review 4 - " << std::endl << std::endl;

	int arr[] = {12,32,32,34,1122,32,42};

	cout << "Before calling func()..." << endl;
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";

	func(arr, arr+7, 12);

	cout << endl << "After the call..." << endl;
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
}

static void func(int *begin, int *end, int val)
{
	for (; begin != end; begin++)
		*begin = val;
}