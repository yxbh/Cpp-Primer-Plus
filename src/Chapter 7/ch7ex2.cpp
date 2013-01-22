#include <iostream>

using namespace std;

static void print_results(const int *);
static double avg(const int *, int);

void ch7ex2()
{
	int input_count = 0;
	int input_buffer;

	int golf_scores[11];

	cout << "Enter scores. (enter a negative value or non-numeric input to stop)." << endl;
	//cout << "Enter golf score " << input_count+1 << ": ";
	while (cin && input_count < 10)
	{
		cout << "Enter golf score " << input_count+1 << ": ";
		cin >> input_buffer;
		golf_scores[input_count] = input_buffer;

		input_count++;


	}
	golf_scores[input_count] = '\0';

	// Clear cin state if input type mismatch
	if (!cin)
		cin.clear();

	// exit if number of input == 0
	if (input_count == 0) {
		cout << "No score entered. Exiting now..." << endl;
		return;
	}

	// print all scores in a line
	cout << endl << "All scores:" << endl;
	print_results(golf_scores);
	cout << "Average score is " << avg(golf_scores, input_count) << endl;

}

static void print_results(const int * scores_arr)
{
	while (*scores_arr) {
		cout << *scores_arr << " ";
		scores_arr++;
	}
	cout << endl;
}

static double avg(const int * scores_arr, int count)
{
	double avg = 0.0;
	while (*scores_arr){
		avg += (double)(*scores_arr);
		scores_arr++;
	}

	return avg/count;
}

