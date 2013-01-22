#include <iostream>

using namespace std;

static double func(const int[], int);

void ch7re5()
{
	std::cout << " - Chapter 7 Review 5 - " << std::endl << std::endl;


	int arr[] = {12,32,32,34,1122,32,42};

	cout << "Array elements:" << endl;
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";

	cout << endl << "The largest element is: " << func(arr, 7) << endl;


}

static double func(const int arr[], int arrSize)
{
	double max = 0.0;
	for (int i = 0; i < arrSize; i++){
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}