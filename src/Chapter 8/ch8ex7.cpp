// tempover.cpp --- template overloading
#include <iostream>

template <typename T>            // template A
static void ShowArray(T arr[], int n);

template <typename T>            // template B
static void ShowArray(T * arr[], int n);

template <typename T>
static T SumArray(T arr[], int n);

template <typename T>
static T SumArray(T * arr[], int n);

struct debts
{
    char name[50];
    double amount;
};


void ch8ex7(void)
{
	using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3]; 

// set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;
    
    cout << "Listing Mr. E's counts of things:\n";
// things is an array of int
    ShowArray(things, 6);  // uses template A
	cout << "Total: " << SumArray(things, 6) << endl;
    cout << "Listing Mr. E's debts:\n";
// pd is an array of pointers to double
    ShowArray(pd, 3);      // uses template B (more specialized)
	cout << "Total: " << SumArray(pd, 3) << endl;
}

template <typename T>
static void ShowArray(T arr[], int n)
{
    using namespace std;
    cout << "template A\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

template <typename T>
static void ShowArray(T * arr[], int n)
{
    using namespace std;
    cout << "template B\n";
    for (int i = 0; i < n; i++)
        cout << *arr[i] << ' ';
    cout << endl; 
}


template <typename T>
static T SumArray(T arr[], int n)
{
	using namespace std;
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

template <typename T>
static T SumArray(T * arr[], int n)
{
	using namespace std;
	T max = 0;
	for (int i = 0; i < n; i++)
        max += *arr[i];
	return max;
}